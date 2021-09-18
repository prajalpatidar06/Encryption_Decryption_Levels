#include<iostream>
using namespace std;

string _toBase64(string s){
    char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int index = 0 , no_of_bits = 0 , count = 0 , padding = 0 , val = 0 , temp;
    int i , j , k = 0;
    string result = "";

    for(i = 0 ; i < s.size() ; i += 3){
        val = 0 , count = 0 , no_of_bits = 0;
        for(j = i ; j < s.size() && j <= (i+2) ; j++){
            val = val << 8;
            val = val | s[j];
            count++;
        }
        no_of_bits = count*8;
        padding = no_of_bits % 3;

        while(no_of_bits != 0){
            if(no_of_bits >= 6){
                temp = no_of_bits - 6;
                index = (val >> temp) & 63;
                no_of_bits -= 6;
            }else{
                temp = 6 - no_of_bits;
                index = (val << temp) & 63;
                no_of_bits = 0;
            }
            result += char_set[index];
        }
    } 

    result.append(padding , '=');
    return result;
}

int main(){
    cout<<_toBase64("MENON");
    return 0;
}