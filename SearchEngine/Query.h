//
//  Query.h
//  MiniGoogle
//
//  Created by Gabriel I Leyva Merino on 11/10/15.
//  Copyright © 2015 Gabriel Leyva Merino. All rights reserved.
//

#ifndef Query_h
#define Query_h
#include "DocObject.h"
#include "XMLParser.h"

#include <vector>
#include <string>
#include <iostream>
#include <sstream>


class Query{
    
private:
    string searchKey;
    vector<string> searchWords;
    
public:
    
    Query(string key){
        
        searchKey = key;
        
    }
    
    void startQuery(){
        
        splitSearchKey();
        
        if (searchWords[0].compare("AND") == 0){
            
            AND();
            
        } else if(searchWords[0].compare("OR") == 0){
            
            OR();
            
        } else {
            
            cerr << " Invalid Prefix Boolean Entered " << endl;
        }
        
    }
    
    void splitSearchKey()
    {
       
  
        stringstream ss(searchKey);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> vstrings(begin, end);
        //std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
        searchWords = vstrings;
      
    }
    
    void AND(){
        
        cout << "AND Called" << endl;
        
        XMLParser *parser = new XMLParser();
        parser->parseThroughIndex(searchWords);
        
        
        bool notIsCalled = false;
        for (int i = 0; i < searchWords.size(); i++){
            
            if (searchWords[i].compare("NOT") == 0){
                
                notIsCalled = true;
                break;
             
            }
            
            
        }
        
        if(notIsCalled == true){
            
            NOT();
            
        } else {
            
            //search articles that contain all search keys
        }
        
        
    }
    
    void OR(){
        
        cout << "OR Called" << endl;
        XMLParser *parser = new XMLParser();
        parser->parseThroughIndex(searchWords);
        
        bool notIsCalled = false;
        for (int i = 0; i < searchWords.size(); i++){
            
            if (searchWords[i].compare("NOT") == 0){
                
                notIsCalled = true;
                break;
                
            }
            
            
        }
        
        if(notIsCalled == true){
            
            NOT();
            
        } else {
            
            //search for the articles that contain one or more of the search keys
            //searchFunction 
        }
        
        
    }

    void NOT(){
        
        cout << "NOT Called" << endl;
        
    }
    
    string  getSearchKey(){
      
      return searchKey;
        
    }
    
    void printSearchWords(){
        
        for (int i = 0; i < searchWords.size(); i++){
            
            cout  << searchWords[i] << endl;
            
            }
        
        
    }
    
    //SEARCH
    
};

#endif /* Query_h */
