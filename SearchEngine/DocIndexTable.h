//
//  DocIndexTable.h
//  xmlParser
//
//  Created by John Mullin on 12/5/15.
//  Copyright (c) 2015 Mullin Media. All rights reserved.
//

#ifndef __xmlParser__DocIndexTable__
#define __xmlParser__DocIndexTable__

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

class DocIndexTable{
private:
    int docID;
    std::vector<std::pair<std::string, int>> docRecords; //word, term frequency
    
public:
    DocIndexTable(){
        docID = -1;

    };
    
    void setDocID(int newDocID){
        docID = newDocID; 
    };
    
    std::vector<std::pair<std::string, int>> getRecords(){
        return docRecords;
    };
    
    void addRecord(std::string& inputString, int inputInt){
        
        std::pair<std::string, int> addRecord = std::make_pair (inputString, inputInt);
        
        docRecords.push_back(addRecord);
    };
    
    
    bool isWordRecord(std::string& reference){
        for(int i = 0; i < docRecords.size(); i++){
            if (docRecords[i].first == reference){
                return true;
                break;
            }
        }
        return false;
    };
    
    int updateRecord(std::string& reference){
        for(int i = 0; i < docRecords.size(); i++){
            if (docRecords[i].first == reference){
                docRecords[i].second++;
                break;
            }
        }
        return -1;
    };
    
    
    void print(){
        for(int i = 0; i < docRecords.size(); i++)
        {
            std::cout << docRecords[i].first << ", " << docRecords[i].second << std::endl;
        }
    };
    
    

    
    
    
  
};

#endif /* defined(__xmlParser__DocIndexTable__) */
