//
//  XMLParser.cpp
//  xmlParser
//
//  Created by John Mullin on 11/12/15.
//  Copyright (c) 2015 Mullin Media. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string.h>

#include "../../rapidxml-1.13/rapidxml.hpp"

#include "XMLParser.h"
#include "Stopwatch.h"
#include "Stemmer.h"
#include "DocObject.h"
#include "StopWordRemover.h"
#include "stemmedWords.h"
#include "RefWord.h"


using namespace std;

XMLParser::XMLParser(){
    
    cout << "in XMLParser" << endl ;
    
    ifstream myfile("wikidump.xml");
    
    rapidxml::xml_document<> doc; //create parser instance
    
    cout << endl <<"READING FILE INTO A STRING" << endl;
    Stopwatch<> sw0;
    string buffer2((istreambuf_iterator<char>(myfile)), (istreambuf_iterator<char>()));     //read file into a string
    sw0.stop();
    cout << " reading to a stream took: " << sw0.elapsed()/1000000 << " seconds" << endl;
    
    
    
    
    cout << endl <<"PARSING" << endl;
    Stopwatch<> sw;
    doc.parse<0>(&buffer2[0]); //parse file into DOM tree
    sw.stop();
    cout << " parsing took: " << sw.elapsed()/1000000 << " seconds" << endl;
    
    
    
    
    cout << endl <<"STEMMING" << endl;
    string word = "running";
    Porter2Stemmer::stem(word);
    cout << "running -> " << word << endl;
    
    string a = "runner";
    string b = "running";
    string c = "run";
    
    StemmedWords list;
    
    if (list.isStemmedWord(a)!=true){
        Porter2Stemmer::stem(a);
        list.insert(a);
    }
    
    if (list.isStemmedWord(b)!=true){
        Porter2Stemmer::stem(b);
        list.insert(b);
    }
    
    if (list.isStemmedWord(c)!=true){
        Porter2Stemmer::stem(c);
        list.insert(c);
    }
    list.print();
    
    
    
    
    
    
    cout << endl << "STOPWORDS" << endl;
    Stopwatch<> sw3;
    StopWordRemover remover;
    sw3.stop();
    cout << "StopWordSet fill took: " << sw3.elapsed()/1000000 << " seconds" << endl;
    
    string tester = "the";
    if (remover.isStopWord(tester)){
        cout << "found a stop word" << endl;
    }
    else {
        cout << "not a stop word" << endl;
    }
    
    
    //STEMMER
    //don't stem every word.
    //build a stemmed list as you go on
    
    //if in stemmed list, move to next
    //if not in stemmed list, then stem
        //add to stemmedList
   
    //REMOVE STOP WORDS
    //check every word if it is a stop word
    //if it is, delete it
    //else, do nothing
    
    cout << endl << "TRAVERSE" << endl;
    StopWordRemover stopWordRemover;
    char* start;
    char* endWord;
    char* pageBeginning;
    
    rapidxml::xml_node<>*curNode = doc.first_node()->first_node("page");//goes to first <page> marking
    rapidxml::xml_node<>* titleNode;
    
    char* pageStart;
    bool stopWord;
    int page = 1;
    int stemEnd;
    char* buffer;
    bool hasWord = false;
    int length;
    DocObject *myDoc = new DocObject();
    RefWord refword;
    
    pair<int,int> addMe (1,2);
    pair<int, int> addMe2 = make_pair (2,3);
    
    refword.addRecord(addMe);
    refword.addRecord(addMe2);
    
    refword.print();
    
    Stopwatch<> sw4;
    while(curNode != nullptr)   //for every document
    {
        titleNode = curNode->first_node("title");
        start = titleNode->next_sibling("revision")->first_node("text")->value();//takes iterator to first text in page
        pageStart = start;
        pageBeginning = start;
        endWord = strchr(start, ' ');//gets first word
        
        while(endWord != nullptr)
        {
            string inputWord(start, endWord);//creates string to be indexed
            
            prepWord(inputWord);//preps the word to be indexed
            
            start = endWord+1;//moves the char pointer to the start of the next word
            
            endWord = strchr(start,' ');//gets the ending of the word
            //------------------------------------------Stemmer-----------------------------------------------------
            Porter2Stemmer::stem(word);
            
            
            
            //-----------------------------------------StopWords---------------------------------------------------------
            
            //buffer = const_cast<char*>(inputWord.c_str());//casts as non-const to pass in
            
            //length = strlen(buffer)-1;//sets to length minus 1 to be pointing to the last char
            
            //inputWord = inputWord.substr(0, stemEnd);//creates a new truncated (stemmed) string
            
            
//            if(stopWord == false)
//            {
//                hasWord = AVLIndex->search(page, inputWord, AVLIndex->getRoot());//checks to see if word is already in index
//                if(hasWord == false)
//                {
//                    AVLIndex->setRoot(AVLIndex->insert(inputWord, page, AVLIndex->getRoot()));
//                }
//            }
        }
        
        curNode = curNode->next_sibling("page");
        
    }
    sw4.stop();
    cout << endl <<  "Traversing DOM tree took: " << sw4.elapsed()/1000000 << " seconds" << endl;

    
    
    
    
    
    
    
    
    
    //set root node
    
    
    //test xml_document
    
    //cout << "Name of my first node is: " << doc.first_node()->name() << "\n";

}

void XMLParser::prepWord(string& word){
    //remove non alphanumeric chars
    //force to lowercas
    
    word.erase(std::remove_if(word.begin(), word.end(), std::not1(std::ptr_fun(::isalnum))), word.end());//removes non alphanumeric chars
    transform(word.begin(), word.end(), word.begin(), ::tolower);//forces to lowercase
}