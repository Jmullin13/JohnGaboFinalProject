//
//  main.cpp
//  xmlParser
//
//  Created by John Mullin on 11/11/15.
//  Copyright (c) 2015 Mullin Media. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "XMLParser.h"
#include "RefWord.h"
#include "IndexHandler.h"
#include "Query.h"

using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Hello" << endl;
    
    
    XMLParser *xmlParser = new XMLParser();

    bool programIsRunning = true;
    bool maintanceMode = false;
    bool interactiveMode = false;
    int option;
    int option2;
    int option3;
    
    
    while (programIsRunning == true){
        
        cout << "Mini Google" << endl;
        cout << "1) Maintance Mode" << endl;
        cout << "2) Interactive Mode" << endl;
        cout << "3) Exit Program" << endl;
        cout << "Enter the number next to the Mode you wish to use" << endl;
        cin >> option;
        cout  << "" << endl;
        
        
        if (option == 1 || option == 2 || option == 3){
            
            if (option == 1) {
                
                maintanceMode = true;
                
                while (maintanceMode == true) {
                    
                    //Maintance mode engaged
                    cout << "Maintance Mode" << endl;
                    cout << "1) Add Documents to the Index" << endl;
                    cout << "2) Clear the Index" << endl;
                    cout << "3) Return to Main Menu" << endl;
                    cout << "Enter the number next to the option you wish to use" << endl;
                    cin >> option2;
                    cout << "" << endl;
                    
                    if (option2 == 1 || option2 == 2 || option2 == 3){
                        
                        if(option2 == 1){
                            
                            cout << "Enter the path to the new file you wish to add" << endl;
                            string path;
                            cin >> path;
                            //getline(cin, path);
                            cout << "" << endl;
                            //add the file
                            ifstream myFile(path);
                            
                            //xmlParser->parseOneFile(path);
                            
                            
                            
                        } else if (option2 == 2){
                            
                            //clear the index
                            cout << "Indexed Cleared" << endl;
                            cout << "" << endl;
                            remove("XMLIndexFile.xml");
                            
                        } else if(option2 == 3){
                            
                            //returns to main menu
                            maintanceMode = false;
                        }
                        
                    } else {
                        
                        cout << "Invalid Option. please Eneter a valid number" << endl;
                        cout << "" << endl;
                        
                    }
                    
                }
                
                
            } else if (option == 2){
                
                interactiveMode = true;
                
                while(interactiveMode == true){
                    //Interactive mode engaged
                    cout << "Interactive Mode" << endl;
                    cout << "1) AVL Tree" << endl;
                    cout << "2) Hash Table" << endl;
                    cout << "3) Return to Main Menu" << endl;
                    cout << "Enter the number next to the option you wish to use" << endl;
                    cin >> option3;
                    cout << "" << endl;
                    
                    if (option3 == 3){
                        
                        interactiveMode = false;
                        
                    } else if( option3 == 1 || option3 == 2){
                        
                         IndexHandler indexHandler;

                        
                        cout << "Please enter a search query" << endl;
                        string input;
                        
                        cin.ignore( 256, '\n') ;
                        getline(cin, input);
                        
                        cout << "" << endl;
                        
                        Query *q = new Query(input);
                        q->startQuery();
                        q->printSearchWords();
                        
                    } else {
                        
                        cout << "Invalid Option. please Eneter a valid number" << endl;
                    }
                }
                
                
            } else if (option == 3){
                
                programIsRunning = false;
            }
            
            
        } else {
            
            cout << "Invalid Option. please Eneter a valid number" << endl;
            cout << "" << endl;
        }
        
    }
    

}



