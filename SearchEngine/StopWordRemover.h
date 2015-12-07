//
//  StopWordRemover.h
//  xmlParser
//
//  Created by John Mullin on 11/12/15.
//  Copyright (c) 2015 Mullin Media. All rights reserved.
//

#ifndef __xmlParser__StopWordRemover__
#define __xmlParser__StopWordRemover__

#include <stdio.h>
#include <set>

class StopWordRemover{
private:
    std::set<std::string> stopWordsSet;
public:
    StopWordRemover();
    bool isStopWord(std::string& word);
    void fillSet();
};


#endif /* defined(__xmlParser__StopWordRemover__) */
