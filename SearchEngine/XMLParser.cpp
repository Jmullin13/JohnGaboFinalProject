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

#include "rapidxml.hpp"

#include "XMLParser.h"
#include "Stopwatch.h"
#include "Stemmer.h"
#include "DocObject.h"
#include "StopWordRemover.h"
#include "stemmedWords.h"
#include "RefWord.h"
#include "AVLTreeIndex.h"
#include "DocIndexTable.h"
#include <stdlib.h>
#include "Dictionary.h"


using namespace std;

XMLParser::XMLParser(){
    
}

void XMLParser::prepWord(string& word){
    word.erase(std::remove_if(word.begin(), word.end(), std::not1(std::ptr_fun(::isalnum))), word.end());//removes non alphanumeric chars
    transform(word.begin(), word.end(), word.begin(), ::tolower);//forces to lowercase
}

AvlTree<RefWord>* XMLParser::parse(){
    
    cout << "Welcome to XMLParser" << endl ;
    ifstream myfile("wikidump100.xml");
    rapidxml::xml_document<> doc; //create parser instance

    string buffer2((istreambuf_iterator<char>(myfile)), (istreambuf_iterator<char>()));     //read file into a string

    
    
    cout << endl <<"PARSING" << endl;
    Stopwatch<> sw;
    doc.parse<0>(&buffer2[0]); //parse file into DOM tree
    sw.stop();
    cout << " parsing took: " << sw.elapsed()/1000000 << " seconds" << endl;
    
    StopWordRemover stopWordRemover;
    
    cout << endl << "PARSE" << endl;//-------------------------------------------------------------------------------------------------
    char* start;
    char* endWord;
    char* pageBeginning;
    char* pageStart;
    char* pageID;
    
    rapidxml::xml_node<>*curNode = doc.first_node()->first_node("page");//goes to first <page> marking
    rapidxml::xml_node<>* titleNode;
    
    AvlTree<RefWord>* mytree = new AvlTree<RefWord>();
    StemmedWords stemmedWords;
    
    Stopwatch<> sw4;
    cout << "Parsing..." << endl;
    while(curNode != nullptr)   //for every document
    {
        titleNode = curNode->first_node("title");
        start = titleNode->next_sibling("revision")->first_node("text")->value();//takes iterator to first text in page
        pageID =curNode->first_node("id")->value();
        
        int intPageID = atoi (pageID);
        pageStart = start;
        pageBeginning = start;
        endWord = strchr(start, ' ');//gets first word
        
        while(endWord != nullptr)
        {
            string inputWord(start, endWord);//finds the word for indexing
            
            prepWord(inputWord);//removes unnecesary characters
           
            start = endWord+1;//moves through to next word
            
            endWord = strchr(start,' ');//gets the ending of the word
            
            Porter2Stemmer::stem(inputWord);//stem the word
           
            DocIndexTable docIndexTable;   //maps an index for each document
            
            docIndexTable.updateRecord(inputWord);  //records word repeats
            
            //docIndexTable.print();
            
            RefWord *refWord = new RefWord();  //create word Node to store
            
            refWord->setWord(inputWord);        //add term to word Node
            refWord->addRecord(intPageID, 2);      //fill with exemplarary records
            refWord->addRecord(3, 5);
            
            if(stopWordRemover.isStopWord(inputWord) != true){  //move over stop words
                bool isInTree = mytree->search(inputWord, mytree->getRoot());   //check to make sure it is not in tree
                if (!isInTree) {
                    mytree->insert(*refWord);  //add node to AVL tree
                }
            }
        }
        
        mytree->printTreeToFile();  //copy to persistent data
        curNode = curNode->next_sibling("page");    //move to next page
    }
    
    mytree->printTree();    //show the data is being stored
    
    sw4.stop();
    cout << endl <<  "Traversing DOM tree took: " << sw4.elapsed()/1000000 << " seconds" << endl;
    return mytree;//return tree to IndexHandler
    
}

RefWord XMLParser::parseIndex(string searchQuery){  //parse the inverted index file we created using the User's Search Query to find Documents
    cout << "Welcome to XMLParser" << endl ;
    ifstream myfile("InvertedIndex.xml");
    rapidxml::xml_document<> doc; //create parser instance
    string buffer2((istreambuf_iterator<char>(myfile)), (istreambuf_iterator<char>()));     //read file into a string

    doc.parse<0>(&buffer2[0]); //parse file into DOM tree
    
    StopWordRemover stopWordRemover;
    
    char* start;
    char* endWord;
    char* word;
    char* docID;
    char* termFreq;
    
    rapidxml::xml_node<>*curNode = doc.first_node()->first_node("page");//goes to first <page> marking
    rapidxml::xml_node<>* titleNode;
    
    RefWord refWord;
    
    Stopwatch<> sw4;
    while(curNode != nullptr)   //for every document
    {
        endWord = strchr(start, ' ');//gets first word
        titleNode = curNode->first_node("name");    //goes to name tag
        word =curNode->first_node("name")->value(); //saves the name value as the word
        std::string stringWord(word);   //cast for passing
        refWord.setWord(stringWord);    //save term
        
        while(curNode != nullptr) {
            docID = titleNode->next_sibling("record")->first_node("docId")->value();
            termFreq =titleNode->next_sibling("record")->first_node("termFreq")->value();
            curNode = curNode->next_sibling("word");
       
        int frequency = atoi (termFreq);    //find each document and frequency record
        int document = atoi (docID);
        refWord.addRecord(document, frequency); //save to node
        }
    
    }
    return refWord; //return node to be compared with others for final results listing
    
}

