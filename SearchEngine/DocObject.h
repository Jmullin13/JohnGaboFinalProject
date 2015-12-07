//
//  DocObject.h
//  MiniGoogle
//
//  Created by Gabriel I Leyva Merino on 11/10/15.
//  Copyright © 2015 Gabriel Leyva Merino. All rights reserved.
//

#ifndef DocObject_h
#define DocObject_h
#include <string>

using namespace std;

class DocObject {
    
private:
    
    string title;
    string username;
    string date;
    int ranking;
    
public:
    
    DocObject(string t, string u, string d, int r){
        
        title = t;
        username = u;
        date = d;
        ranking = r;
        
    }
    
    DocObject(){
        
        
    }
    
    void setTitle(string t){
        
        title = t;
    }
    
    void setUsername(string u){
        
        username = u;
    }
    
    void setDate( string d){
        
        date = d;
    }
    
    string getTitle(){
        
        return title;
        
    }
    
    string getUsername(){
        
        return username;
        
    }
    
    
    string getDate(){
        
        return date;
        
    }
    
    
    
    int getRanking(){
        
        return ranking;
        
    }
    
};

#endif /* DocObject_h */
