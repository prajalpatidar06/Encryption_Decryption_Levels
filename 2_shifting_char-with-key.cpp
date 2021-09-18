// In these Process charecter is shifted by k position with respect to their original position

#include<iostream>
#include<string>
using namespace std;

int generate_key(string key){
    int res = 0;
    for(int i = 0 ; i < key.size() ; i++){
        res = (res^key[i])%'z';
    }
    return res;
}

string encrypt(string text , int _key){
    string res;
    for(int i = 0 ; i < text.size() ; i++){
        res += char(text[i]+_key);
    }
    return res;
}

string decrypt(string text , int _key){
    string res;
    for(int i = 0 ; i < text.size() ; i++){
        res += char(text[i]-_key);
    }
    return res;
}

int main(){
    string text;
    string key;
    int op;
    cout<<"Program to Encrypt and Decrypt Input string\n";
    cout<<"Input string and key : \n";
    cout<<"String = ";
    getline(cin,text);
    cout<<"Key = ";
    cin>>key;

    cout<<"Press : 1 (for Encryption) ,  2 (for Decryption) = ";
    cin>>op;
    string output = "Invalid Operation , Please try again...\n";
    int _key = generate_key(key);
    switch(op){
        case 1:
            output = encrypt(text , _key);
            break;
        case 2:
            output = decrypt(text , _key);
            break;
    }
    cout<<output<<"\n";
    return 0;
}
