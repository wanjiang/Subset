/*
 * Program: Subsets Problem
 * Description: Find subset that has at least two different elements between each other
 * Developed by: Wanjiang Qian
 * Professor: Dr. Seo
 * Date: 05 March 2015
 */
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <bitset>
#include <stdint.h>
#include <vector>
using namespace std;
// Count numbers of 1 in binary number
int bitCount(uint64_t c);
// Cout format
const int INT64 = 64;
const int INT32 = 32;
const int INT16 = 16;
const int INT8 = 8;

int main(int argc, char**argv){
	// totle element number of the set
	int total = -1;
	while(total!=0){
		cout<<"Enter totle element number of the set, from 1 to 64. Enter 0 to exit.\n";
		cin>>total;
		// total posible subset
		uint64_t t = pow(2,total);
		// save these subsets result
		vector<uint64_t> result;
		// in the safe rang, from 1 to 64
		if(total>0&&total<64){
			cout<<"Subset Result:\n";
			for(uint64_t index=0;index<t;index++){
				// size of result
				int size_temp = result.size();
				// flag for validate subset
				bool isValidate = true;
				for(int vindex=size_temp-1;vindex>=0;vindex--){
					uint64_t temp = result.at(vindex);
					// decide if the new subset is eligible
					if(bitCount((temp^index)&index)<2){
						isValidate = false;
						break;
					}
				}
				// print result one by one in special format
				if(isValidate){
					result.push_back(index);
					if(total>32){
						std::bitset<INT64> y(index);
						cout<<y<<"\n";
					}else if(total>16){
						std::bitset<INT32> y(index);
						cout<<y<<"\n";
					}else if(total>8){
						std::bitset<INT16> y(index);
						cout<<y<<"\n";
					}else{
						std::bitset<INT8> y(index);
						cout<<y<<"\n";
					}
				}
			}
			// print total number of subsets
			cout<<"Finished!\nOriginal set:{";
			for(int index=1;index<=total;index++){
				cout<<index;
				if(index!=total)
					cout<<",";
			}
			cout<<"}\nTotal number of subsets is:"<<result.size()<<"\n\n";
		}else{
			cout<<"OUT OF RANG!\n";
		}
	}
	return 0;
}

/*
 * Count the number of 1 in binary
 */
int bitCount(uint64_t c){
	int result = 0;
    while(c){
        result++;
        c &=c-1;
    }
    return result;
}