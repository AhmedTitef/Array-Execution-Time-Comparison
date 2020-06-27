//
//  main.cpp
//  CS 4080 Project 1 version 3
//
//  Created by Ahmed Elsayed on 6/9/20.
//  Copyright © 2020 Ahmed Elsayed. All rights reserved.
//

#include <iostream>
using namespace std;

using namespace std::chrono;

class Matrix{
//    #define size 6
private:
     float **a = new float*[size];
     float **b = new float*[size];
     float **c = new float*[size];
    
    
  
public:
    int size;
    void createA2DArray();
    void initiateArrays();
    void fillMatrix();
    void  add  ();
    void subtract();
    void  multiplication();
    void  print();
    void driver();


};

void Matrix:: createA2DArray(){
    for (int i = 0 ; i < size ; i++){
        a[i] = new float[size];
         b[i] = new float[size];
         c[i] = new float[size];
        
        
    }
}
void Matrix::initiateArrays(){
    for (int i = 0; i < size; i++) {
                 for (int j = 0; j < size; j++) {
                     a[i][j] = 0;
                     b[i][j] = 0;
                     c[i][j] = 0;
                   
                     
                 }

             }
}
void Matrix::fillMatrix(){
    for (int i = 0; i < size; i++) {
              for (int j = 0; j < size; j++) {
                  a[i][j] = rand();
                  b[i][j] = rand();
                
                  
              }

          }
}
void Matrix::add  () {
      auto start = high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }

    }
    auto stop = high_resolution_clock::now();
       auto duration = duration_cast<microseconds>(stop - start);         cout << "Time taken to complete this operation is : " << duration.count()<< " microseconds."<< endl;
}
void Matrix::subtract() {
     auto start = high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            c[i][j] = a[i][j] - b[i][j];
        }

    }
    auto stop = high_resolution_clock::now();
       auto duration = duration_cast<microseconds>(stop - start);         cout << "Time taken to complete this operation is : " << duration.count()<< " microseconds."<< endl;
}
void Matrix::multiplication() {
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

void Matrix::driver(){
    bool boolValue = true;
    char answerForLoop;
    int options;
    while (boolValue) {
        cout << "HELLO!. Please Follow The Instructions Carefully" << endl;
        cout<< "Please Specify The Size of The 2D Array. You Can Input 10 ,  or any integer value" << endl;
        cin >> size;
        createA2DArray();
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
                break;
                
            default:
                cout << "You Choose Wrong Option. The Program Will Exit. Please Try Again Later" << endl;
                boolValue = false;
                exit(3);
                break;
        }
        
    }
    
}

void Matrix::print(){
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







int main(int argc, const char * argv[]) {
    
    Matrix matrix;
    matrix.driver();
}


