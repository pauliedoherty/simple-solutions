

//

//  main.cpp

//  helloworld

//

//  Created by Paul Doherty on 22/11/2018.

//  Copyright © 2018 Paul Doherty. All rights reserved.

//


#include<iostream>
#include<limits>
#include<ios>
#include<string>
#include<sstream>
#include<cstring>
using namespace std;
typedef long long int ll;
void findPairs(ll size);
int main()

{

    ll t=0;
    ll size;
    bool done = false;
    //first input T, number of test cases
    while(!done){
        cout << "Input number of Test cases please:\n";
        cin >> t;
        if(t >= 1 && t <= 100){
            done = true;
        }
    }

    while(t--){
        //Second input declares size of array
        cout << "Enter number of elements to test \n";
        cin >> size;
        findPairs(size);

    }
    cin.get();
    return 0;
}

//TODO update function to return array of matching pairs

void findPairs(ll size){
    ll sum, target, i, j, k;
    bool sumFound = false;

    string str, word;
    ll* A = new ll[size];

    cout << "Enter elements to test\n";
    cin.ignore(256,'\n');
    getline(cin, str);

    istringstream s(str);
     k = 0;
    while(s >> word){
        A[k] = atol(word.c_str());
        k++;
    }

    cout << "Enter target to test: \n";
    cin >> target;

    i = 0;
    j = size-1;
    while(i <= j){
        sum = A[i]+A[j];
        if(sum == target){
            cout << A[i] << " " << A[j] << " " << target << endl;
            i++;
            j--;
            sumFound = true;
            continue;
        }else if(sum < target){
            i++;
            continue;
        }else if(sum > target){
            j--;
            continue;
        }
    }

    delete[] A;
    if(!sumFound){
        cout << "-1" << endl;
    }
};
