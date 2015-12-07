/*
  StopWordRemover.cpp
  xmlParser

  Created by John Mullin on 11/12/15.
  Copyright (c) 2015 Mullin Media. All rights reserved.
*/

#include "StopWordRemover.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

StopWordRemover::StopWordRemover(){
    fillSet();
}

void StopWordRemover::fillSet(){
    ifstream fileReader;
    fileReader.open("stopWords.txt");
    
    string temp;
    ifstream myfile ("stopWords.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,temp) ){
            stopWordsSet.insert(temp);
        }
        myfile.close();
    }

}

bool StopWordRemover::isStopWord(string& word){
    
    if(stopWordsSet.find(word) == stopWordsSet.end()){
        return false;
    }
    else{
        return true;
    }
}



//STL::UnorderedMap     or         STL::unordered_set    (HASH TABLE)
    //stl hash table
        //key = nullptr; (not important)
        //value = stop word
    //for every word: is this a key (stop word) or not?
    //O(1) complexity


