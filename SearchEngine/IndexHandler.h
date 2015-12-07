//
//  IndexHandler.h
//  xmlParser
//
//  Created by John Mullin on 11/19/15.
//  Copyright (c) 2015 Mullin Media. All rights reserved.
//

#ifndef __xmlParser__IndexHandler__
#define __xmlParser__IndexHandler__

#include <stdio.h>
#include <fstream>
#include <iostream>
#include "AVLTreeIndex.h"
#include "XMLParser.h"
#include "RefWord.h"
#include <string>

using namespace std;

class IndexHandler {
    
private:
    AvlTree<RefWord>* fullTree;

    
public:
    
    IndexHandler(){
        XMLParser xmlParser;
        fullTree = xmlParser.parse();
    };
    
    void loadIndex(){
        printTreeToFile();
    };
    
    void getLeafPRINT(AvlTree<RefWord>::AvlNode *t){
        
        if( t != NULL )
        {
            
            ofstream outputFile;
            outputFile.open("InvertedIndex.xml", std::ios_base::app);
            
            getLeafPRINT( t->left );
            
            string tmp = t->element->getWord();
            std::vector<std::pair<int, int>> wordRecords = t->element->getRecord();
            
            outputFile << "<word>" << endl;
            outputFile << "<name> " << t->element->getWord() << " </name>" << endl;
            
            outputFile << "<record>" << endl;
            for (int i = 0; i < wordRecords.size(); i++){
                outputFile << "<docID>" << wordRecords[i].first << "</docID>" << endl;
                outputFile << "<termFreq>" << wordRecords[i].second <<   "</termFreq>" << endl;
            }
            
            outputFile << "</record>" << endl;
            outputFile << "</word>" << endl;
            
            
            getLeafPRINT( t->right );
            outputFile.close();
        }
        
    };
    
    void printTreeToFile(){
        
        if( fullTree->isEmpty( ) )
            cout << "Empty tree" << endl;
        
        else
            getLeafPRINT( fullTree->getRoot() );
        cout << "Printing to  file" << endl;
        
    };

    void clearIndex(){
        fstream indexFile("InvertedIndex.txt");
        indexFile.open("file", std::fstream::out | std::fstream::trunc);
        indexFile.close();
    };
    
    void readIndex(){
        XMLParser xmlParser;
        //xmlParser.parseIndex(std::string searchQuery);
    };
    
    
    
};


#endif /* defined(__xmlParser__IndexHandler__) */


