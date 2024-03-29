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
#include <algorithm>

class DocIndexTable{
private:
    int docID;
    std::vector<std::pair<std::string, int>> docRecords; //word, term frequency
    std::vector<std::string> checkList;
    
public:
    DocIndexTable(){
        docID = -1;
     
    };
    
    int getDocRecordssSize(){
        return docRecords.size();
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
    
    
    bool isWordRecord(std::string& reference){  //check if word is in the records vector
        for(int i = 0; i < docRecords.size(); i++){
            if (docRecords[i].first == reference){
                return true;
                break;
            }
        }
        return false;
    };
    
    
    void updateRecord(std::string& reference){//either adds a term to the records vector or counters its frequency
        int check = 0;
        
        for(int i = 0; i < docRecords.size(); i++){

            if (docRecords[i].first == reference){
                docRecords[i].second++;
                break;
                check++;
            }
        }
        if(check== 0)
            addRecord(reference, 1);
    };
    
    
    void print(){//print set
        for(int i = 0; i < docRecords.size(); i++)
        {
            std::cout << docRecords[i].first << ", " << docRecords[i].second << std::endl;
        }
    };
    

    
    
  
};

#endif /* defined(__xmlParser__DocIndexTable__) */
