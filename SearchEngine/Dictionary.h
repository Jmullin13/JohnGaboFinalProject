//
//  Dictionary.h
//  MiniGoogle
//
//  Created by Gabriel I Leyva Merino on 11/10/15.
//  Copyright © 2015 Gabriel Leyva Merino. All rights reserved.
//

#include "AVLTreeIndex.h"
#include <string>
#include "RefWord.h"

#ifndef Dictionary_h
#define Dictionary_h

using namespace std;


//item that goes in the bucket. Will hold an AVL Tree
class DictionaryItem {
    
private:
    
    string key;
    AvlTree<RefWord> *value;
    
public:
    
    DictionaryItem(string k, AvlTree<RefWord> *v){
        
        key = k;
        value = v;
    }
    
    string getKey(){
        
        return key;
        
    }
    
    AvlTree<RefWord>* getValue(){
        
        return value;
    }
    
    
    
};


class Dictionary {
    
private:
    
    DictionaryItem ** map;
    int mapSize;
    
public:
    //creates the dictionary with a desired size
    Dictionary(int size) {
        
        mapSize = size;
        
        map = new DictionaryItem *[mapSize];
        
        for (int i = 0; i < mapSize; i++)
            map[i] = NULL;
    }
    
    
    //deletes the dictionary
    ~Dictionary() {
        for (int i = 0; i < mapSize; i++)
            if (map[i] != NULL)
                delete map[i];
        delete[] map;
    }
    
    
    //gets an item
    AvlTree<RefWord>* get(string key) {
        
     
        std::hash<std::string> hash_fn;
        std::size_t hash = key.length();
        
        //hashFunction(key);
        
       // cout << "In get Function" << endl;
        
        if (map[hash] == NULL)
            return NULL;
        
        while (map[hash] != NULL && map[hash]->getKey().compare(key) != 0)
            hash = (hash + 1) % mapSize;
        if (map[hash] == NULL)
            return NULL;
        else
            return map[hash]->getValue();
        
       
    }
    
    //adds an item
    void add(string key, AvlTree<RefWord> *value) {
        
        std::hash<std::string> hash_fn;
        std::size_t hash = key.length();
        
        while (map[hash] != NULL && map[hash]->getKey().compare(key) != 0)
            hash = (hash + 1) % mapSize;
        if (map[hash] != NULL)
            delete map[hash];
        map[hash] = new DictionaryItem(key, value);
    }
    


    
    
};

#endif /* Dictionary_h */
