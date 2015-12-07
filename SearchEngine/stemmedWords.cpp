//
//  stemmedWords.cpp
//  xmlParser
//
//  Created by John Mullin on 12/3/15.
//  Copyright (c) 2015 Mullin Media. All rights reserved.
//

#include "stemmedWords.h"
#include <string>
#include <iostream>

using namespace std;



StemmedWords::StemmedWords(){
    set<string> stemmedList;
}

void StemmedWords::insert(std::string& word){
    stemmedList.insert(word);
}

bool StemmedWords::isStemmedWord(std::string& word){
    if(stemmedList.find(word) == stemmedList.end()){
        return false;
    }
    else{
        return true;
    }
}

void StemmedWords::print(){
    set<string>::iterator iter;
    cout << "Stemmed List:" << endl;
    cout << "set size: " << stemmedList.size() << endl;
    int i= 0;
    cout << "set contains: " << endl;
    for(iter=stemmedList.begin(); iter!=stemmedList.end(); ++iter){
        cout << i << " ";
        cout << (*iter) << endl;
        i +=1;
    }
    
}
