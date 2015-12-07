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

class DocObject {//used for referencing a document's data when returning listings
    
private:
    
    string title;
    string username;
    string date;
    int ranking;
    
public:
    
    DocObject(string t, string u, string d, int r){ //stores all pertinent document information
        
        title = t;
        username = u;
        date = d;
        ranking = r;
        
    }
    
    DocObject(){
        
    }
    
    //setters
    void setTitle(string t){
        
        title = t;
    }
    
    void setUsername(string u){
        
        username = u;
    }
    
    void setDate( string d){
        
        date = d;
    }
    
    //getters
    
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
