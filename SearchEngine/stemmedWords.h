//
//  stemmedWords.h
//  xmlParser
//
//  Created by John Mullin on 12/3/15.
//  Copyright (c) 2015 Mullin Media. All rights reserved.
//

#ifndef __xmlParser__stemmedWords__
#define __xmlParser__stemmedWords__

#include <stdio.h>
#include <set>

class StemmedWords{
    
private:
    std::set<std::string> stemmedList;
public:
    StemmedWords();
    void insert(std::string&);
    bool isStemmedWord(std::string&);
    void print();
    
};

#endif /* defined(__xmlParser__stemmedWords__) */
