//
//  RefWord.h
//  xmlParser
//
//  Created by John Mullin on 12/3/15.
//  Copyright (c) 2015 Mullin Media. All rights reserved.
//

#ifndef __xmlParser__RefWord__
#define __xmlParser__RefWord__

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>


class RefWord{
private:
    std::string word;
    std::vector<std::pair<int, int>> records;
    
public:
    
    RefWord(){
        word = "empty";
    }
    
    std::string getWord(){
        return word;
    }
    
    std::vector<std::pair<int,int>> getRecord(){
        return records;
    }
    
    void sortRecords(){
        //sort records to include highest relevancy pairs first
    }
    
    void setWord(std::string& setword){
        word = setword;
    }
    
    void addRecord(int firstInt, int secondInt){ //
    
        std::pair<int, int> addPair = std::make_pair(firstInt, secondInt);
        
        records.push_back(addPair);
    }
    
    
    void addRecord(std::pair<int,int>& addPair ){
        
        
        records.push_back(addPair);
    }
    
    void print(){
        for(int i = 0; i < records.size(); i++)
        {
            std::cout << records[i].first << ", " << records[i].second << std::endl;
        }
    }
    
};



#endif /* defined(__xmlParser__RefWord__) */
