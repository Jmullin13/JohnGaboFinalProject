//
//  AVLTreeIndex.h
//  xmlParser
//
//  Created by John Mullin on 11/19/15.
//  Copyright (c) 2015 Mullin Media. All rights reserved.
//

#ifndef __xmlParser__AVLTreeIndex__
#define __xmlParser__AVLTreeIndex__

#include <stdio.h>
#include "RefWord.h"


#include <iostream>
using namespace std;


template <typename Comparable>
class AvlTree
{
    friend class IndexHandler;
public:
    AvlTree( ) : root( NULL )
    { }
    AvlTree( const AvlTree & rhs ) : root( NULL )
    {
        *this = rhs;
    }
    
    ~AvlTree( )
    {
        makeEmpty( );
    }
    
    
    
    //finds the smalledt object
    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
       
            return findMin( root )->element;
    }
    
 //finds the greatest object
    const Comparable & findMax( ) const
    {
        
        if( isEmpty( ) )
           
            return findMax( root )->element;
    }
    
    
    bool contains( const Comparable & x ) const
    {
        return contains( x, root );
    }
    
//checks to see if it is empty
    bool isEmpty( ) const
    {
        return root == NULL;
    }
    
//printd the tree in order
    void printTree( ) const
    {
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        else
            printTree( root );
    }
    
//makes tree empty
    void makeEmpty( )
    {
        makeEmpty( root );
    }
    

    void insert( RefWord & x )
    {
        insert( x, root );
    }

//AVL Node struct
    struct AvlNode
    {
        RefWord *element;
        AvlNode   *left;
        AvlNode   *right;
        int       height;
        
        AvlNode(  RefWord & theElement, AvlNode *lt,
                AvlNode *rt, int h = 0 )
        : element( &theElement ), left( lt ), right( rt ), height( h ) { }
    };
    

    AvlNode *root;
    
    //inserts a node
    void insert( RefWord & x, AvlNode * & t )
    {
        if( t == NULL )
            t = new AvlNode( x, NULL, NULL );
        else if( x.getWord() < t->element->getWord() )
        {
            insert( x, t->left );
            if( height( t->left ) - height( t->right ) == 2 )
                if( x.getWord() < t->left->element->getWord() )
                    rotateWithLeftChild( t );
                else
                    doubleWithLeftChild( t );
        }
        else if( t->element->getWord() < x.getWord() )
        {
            insert( x , t->right );
            if( height( t->right ) - height( t->left ) == 2 )
                if( t->right->element->getWord() < x.getWord())
                    rotateWithRightChild( t );
                else
                    doubleWithRightChild( t );
            
        }
        else
            ;  // Duplicate; do nothing
        t->height = max( height( t->left ), height( t->right ) ) + 1;
    }

    AvlNode * findMin( AvlNode *t ) const
    {
        if( t == NULL )
            return NULL;
        if( t->left == NULL )
            return t;
        return findMin( t->left );
    }
    
    //checks to see if tree contains object
    bool contains( const Comparable & x, AvlNode *t ) const
    {
        if( t == NULL )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }
    
    AvlNode * findMax( AvlNode *t ) const
    {
        if( t != NULL )
            while( t->right != NULL )
                t = t->right;
        return t;
    }
    


    void makeEmpty( AvlNode * & t )
    {
        if( t != NULL )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = NULL;
    }
    
    //print tree
    void printTree( AvlNode *t ) const
    {
        if( t != NULL )
        {
            printTree( t->left );
            cout << t->element->getWord() << endl;
            printTree( t->right );
        }
    }


    int height( AvlNode *t ) const
    {
        return t == NULL ? -1 : t->height;
    }
    
    int max( int lhs, int rhs ) const
    {
        return lhs > rhs ? lhs : rhs;
    }
    
    //rotates right child
    void rotateWithRightChild( AvlNode * & k1 )
    {
        AvlNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
        k2->height = max( height( k2->right ), k1->height ) + 1;
        k1 = k2;
    }
    

    void rotateWithLeftChild( AvlNode * & k2 )
    {
        AvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
        k1->height = max( height( k1->left ), k2->height ) + 1;
        k2 = k1;
    }

    
    //double rotate with left child
    void doubleWithLeftChild( AvlNode * & k3 )
    {
        rotateWithRightChild( k3->left );
        rotateWithLeftChild( k3 );
    }
    
    
    void doubleWithRightChild( AvlNode * & k1 )
    {
        rotateWithLeftChild( k1->right );
        rotateWithRightChild( k1 );
    }
    
    
    
public:
    
    //searches for an element
    bool search (string& searchWord, AvlNode *k)//standard AVL search
    {
        if(k == nullptr)
        {
            return false;
        }
        if(searchWord < k->element->getWord())
        {
            search(searchWord, k->left);
        }
        else if(searchWord > k->element->getWord())
        {
            search(searchWord, k->right);
        }
        else if(searchWord == k-> element -> getWord())
        {
  
            return true;
        }
        return false;
    }
    
    
    //getsTheRoot
    AvlNode * getRoot(){
        
        return root;
    }
    
    
    
    //traverses through the tree
    void traverseTree(){
        
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        
        else
            getLeaf( root );
        
        
    }
    //gets a leaf
    void getLeaf(AvlNode *t){
        
        if( t != NULL ){
            
            getLeaf( t->left );
            
            string tmp = t->element->getWord();
        
            cout << t->element->getWord() << endl;
            
            getLeaf( t->right );
        }
    }
    
    
    //writes to the index file
    void getLeafPRINT(AvlNode *t){
        
        
        if( t != NULL )
        {
            
            
            ofstream outputFile;
            outputFile.open("InvertedIndex.xml", std::ios_base::app);
    
            getLeafPRINT( t->left );
            
            string tmp = t->element->getWord();
            std::vector<std::pair<int, int>> wordRecords = t->element->getRecord();
       
            outputFile << "<word>" << endl;
            outputFile << "   <name> " << t->element->getWord() << " </name>" << endl;
            
            outputFile << "      <record>" << endl;
            for (int i = 0; i < wordRecords.size(); i++){
                outputFile << "         <docID>" << wordRecords[i].first << "</docID>" << endl;
                outputFile << "         <termFreq>" << wordRecords[i].second <<   "</termFreq>" << endl;
            }
            
            outputFile << "      </record>" << endl;
            outputFile << "</word>" << endl;
            
            
            getLeafPRINT( t->right );
            outputFile.close();
        }
      
    }
    
    //prints to the index file
    void printTreeToFile(){
        
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        
        else
            getLeafPRINT( root );
        
        
    }
    
    
};


#endif /* defined(__xmlParser__AVLTreeIndex__) */