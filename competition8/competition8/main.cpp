#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){
    char *input=new char[10000000];
    int count;
    int sum=1;
    char character=NULL;
    string series;
    
    cout<<"please input number of characters"<<endl;
    cin>>count;
    
    cout<<"please input incantation"<<endl;
    cin>>input;

    for(int i=0;i<10;i++){
        character=input[0];
        for(int j=1;j<count;j++){
            
            if(character==input[j]){
                sum++;
            }
            else{
                series+=to_string(sum)+character;
                character=input[j];
                sum=1;
            }
        }
        
        series+=to_string(sum)+character;
        
        if(series.length()>=count){
            cout<<input<<endl;
        }
        else{
            cout<<series<<endl;
        }
    }
}
