//
//  Stopwatch.h
//  xmlParser
//
//  Created by John Mullin on 11/27/15.
//  Copyright (c) 2015 Mullin Media. All rights reserved.
//

#ifndef __xmlParser__Stopwatch__
#define __xmlParser__Stopwatch__

#include <stdio.h>

#include "Stopwatch.h"
#include <chrono>
#include <iostream>

template<typename TimeT = std::chrono::microseconds,
typename ClockT=std::chrono::high_resolution_clock,
typename DurationT=double>

class Stopwatch
{
private:
    std::chrono::time_point<ClockT> _start, _end;
public:
    Stopwatch() { start(); }
    void start() { _start = _end = ClockT::now(); }
    DurationT stop() { _end = ClockT::now(); return elapsed();}
    DurationT elapsed() {
        auto delta = std::chrono::duration_cast<TimeT>(_end-_start);
        return delta.count();
    }
};

#endif /* defined(__xmlParser__Stopwatch__) */
