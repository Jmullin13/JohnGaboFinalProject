//
//  XMLParser.h
//  xmlParser
//
//  Created by John Mullin on 11/12/15.
//  Copyright (c) 2015 Mullin Media. All rights reserved.
//



#ifndef __xmlParser__XMLParser__
#define __xmlParser__XMLParser__

#include <stdio.h>
#include <string>
#include "AVLTreeIndex.h"
#include "RefWord.h"


class XMLParser{
private:
    
public:
    XMLParser();
    void prepWord(std::string&);
    AvlTree<RefWord>* parse();
    RefWord parseIndex(string searchQuery);
 
    void parseAllFiles(int option);
};

 
#endif /* defined(__xmlParser__XMLParser__) */


