//
//  main.cpp
//  CS 4080 Project1
//
//  Created by Ahmed Elsayed on 6/4/20.
//  Copyright © 2020 Ahmed Elsayed. All rights reserved.
//

#include <iostream>
#include <ctime>
using namespace std;
using namespace std::chrono;
#include <iostream>
#define size 10
static float a [size][size] ;
static float b[size][size] ;
static float c [size][size] ;
  
void fillMatrix() {

  srand((unsigned)time(NULL));
       for (int i = 0; i < size; i++) {
           for (int j = 0; j < size; j++) {
               a[i][j] = rand();
               b[i][j] = rand();
             
               
           }

       }



   }


void  add  () {
    auto start = high_resolution_clock::now();
     
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }

    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);         cout << "Time taken to complete this operation is : " << duration.count()<< " microseconds."<< endl;
}


void subtract() {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            c[i][j] = a[i][j] - b[i][j];
        }

    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);         cout << "Time taken to complete this operation is : " << duration.count()<<" microseconds."<<  endl;
}
    void  multiplication() {
        auto start = high_resolution_clock::now();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int x = 0; x < size; x++) {
                    c[i][j] += a[i][x] * b[x][j];

                }

            }

        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);         cout << "Time taken to complete this operation is : " << duration.count()<< " microseconds."<< endl;
       
    }

void initiateArrays(){
    for (int i = 0; i < size; i++) {
                 for (int j = 0; j < size; j++) {
                     a[i][j] = 0;
                     b[i][j] = 0;
                     c[i][j] = 0;
                   
                     
                 }

             }
}

void print(){
    for (int i = 0 ; i < size ; i ++){
        cout<< endl;
        cout << "-------------------------------------------------------------"<<endl;
        for (int j = 0; j < size; j++) {
            cout << c[i][j] << "||" ;
        
        }
        
    }
    cout<< endl;
     cout << "-------------------------------------------------------------"<<endl;
}
void driver(){
    bool boolValue = true;
    char answerForLoop;
    int options;
    while (boolValue) {
        cout << "HELLO !. Please Follow The Instructions Carefully" << endl;
        cout<< "The size of 2D array is pre set to 100" << endl;
        
       
        initiateArrays();
        fillMatrix();
        cout << "Two 2D Arrays have been created with same size. "<< endl;
        cout << "Please Choose From The Following Menu." << endl;
        cout << "Multiplication: Enter 1" << endl;
        cout << "Subtraction: Enter 2" << endl;
        cout << "Addition: Enter 3" << endl;
        cin >> options;
        switch (options) {
            case 1:
                cout << "You Chose Multiplication"<< endl;
                multiplication();
                
                break;
            case 2:
                cout << "You Chose Subtraction"<< endl;
                subtract();
            break;
            case 3:
                cout << "You Chose Addition"<< endl;
                add();
                break;
            default:
                cout << "Please Choose A Correct Option. The Program Will Exit Now." << endl;
                exit(3);
                break;
        }
        cout << "Output is : " << endl;
        print();
        cout<< "////////////  END   ////////////////" << endl;
        cout <<"Would You Like To Try Another Operation? Please Enter y/n" <<endl;
        cin >> answerForLoop;
        switch (answerForLoop) {
            case 'y':
                boolValue = true;
                break;
            case 'n':
                cout << "Thank You & Have A Good Day!" << endl;
                boolValue = false;
                break;;
                
            default:
                cout << "You Choose Wrong Option. The Program Will Exit. Please Try Again Later" << endl;
                boolValue = false;
                exit(3);
                break;
        }
        
    }
    
}


int main(int argc, const char * argv[]) {

//    int a = rand();
//    int b = rand();
//    std::cout<< a << std::endl;
//    std::cout<< b << std::endl;
    
    driver();
//    add();
    
   
}


    

//    static void createTwoMatrix(int size) {
//        a = new float[size][size];
//        b = new float[size][size];
//        c = new float[size][size];
//    }
//
    
//
//
//    static float[][] add(float[][] a, float[][] b) {
//        for (int i = 0; i < a.length; i++) {
//            for (int j = 0; j < a.length; j++) {
//                c[i][j] = a[i][j] + b[i][j];
//            }
//
//        }
//        return c;
//    }
//
//    static float[][] subtract(float[][] a, float[][] b) {
//        for (int i = 0; i < a.length; i++) {
//            for (int j = 0; j < a.length; j++) {
//
//                c[i][j] = a[i][j] - b[i][j];
//            }
//
//        }
//        return c;
//    }
//
//    static float[][] multiplication(float[][] a, float[][] b) {
//
//        for (int i = 0; i < a.length; i++) {
//            for (int j = 0; j < a.length; j++) {
//                for (int x = 0; x < a.length; x++) {
//                    c[i][j] += a[i][x] * b[x][j];
//
//                }
//
//            }
//
//        }
//        return c;
//    }

