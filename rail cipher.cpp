// C++ program to illustrate Rail Fence Cipher

#include<iostream>
#include<string>
using namespace std;
void encrypt(){
    
    cout<<"Enter string to encrypt: ";
    string str;
    cin>>str; //take string from user
    cout<<"Enter the key of encryption: ";
    int key;
    cin>>key; //take key from user
    char table[key][str.size()]; 
    
    //initializing table    
    for(int r=0;r<=key;r++)
        for(int c=0;c<=str.size();c++)
            table[r][c]=5;
            
    //sequence of encryption
    int dir = 1 , r=0 , c=0 ;
    for(int i=0;i<=str.size();i++){
        table[r][i] = str[i];
        if(r == key-1)
            dir= -1 ; 
        if(r==0)
            dir= 1;
        r += dir;    
    }
    
    //printing encrypted string
    for(r=0;r<=key;r++)
        for(c=0;c<=str.size();c++)
            if (table[r][c]!=5) 
            cout<<table[r][c];
    
}


void decrypt(){
    cout<<"Enter string to decipher: ";
    string dcpt; //take string form user to decrypt
    cin>>dcpt;
    cout<<"enter key of decryption: ";
    int key;
    cin>>key; //take key of decryption form user
    char list[key][dcpt.size()];
    
    //initializing the table 
   for (int r=0;r<key;r++){
        for(int c=0;c<dcpt.size();c++){
            list[r][c] = 0 ;
        }
   }
    
    //filling the ''encyption''' sequence with stars 
    int c=0,r=0,dir=1;
    for(c=0;c<dcpt.size();c++){
        list[r][c] = '*';
        if(r == key-1)
            dir= -1;
        if (r==0)
            dir=1;
        r+=dir;
    }
    
    //reolacing stars with string characters
    int i = 0; 
    for(int row=0;row<key;row++){
        for(int col=0;col<dcpt.size();col++)
            if(list[row][col]=='*'){
                list[row][col]=dcpt[i++];
            }
    }
    
    //read the table with the encryption sequence
    string encrypted="";
    for(int col=0,row=0;col<dcpt.size();col++){
        encrypted+=list[row][col] ;
        if (row == key-1)
            dir=-1;
        if (row == 0)
            dir=1;
        row+=dir;
            
    }    
    cout<<encrypted;
    
            
    
            
        
     
    
}







int main()
{
    cout<<"press 1 to encrypt: "<<endl<<"press 2 to decipher: "<<endl<<"press any other button to exit: "<<endl;
    int opr;
    cin>>opr;
    
    switch(opr){
        case 1:encrypt();
        break;
        case 2:decrypt();
        break;
        default:
        break;
    }
}






