#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){
    const int ENTER='\0';
    const int SPACE=' ';
    
    //[0]=lightX,[1]=lightY,[2]=cityX,[3]=cityY,[4]=distance;
    int position[5];
    char input[50];
    string series;
    int size=0;
    
    for(int j=0;j<10;j++){
        series="";
        size=0;
        
        cout<<"please input coordinate"<<endl;
        cin.getline(input, 50);
        
        for(int i=0;i<50;i++){
            if(input[i]==ENTER){
                position[size++]=atoi(series.c_str());
                series="";
                break;
            }
            else if(input[i]==SPACE){
                position[size++]=atoi(series.c_str());
                series="";
            }
            else{
                series+=input[i];
            }
        }
        
        if(abs(position[2]-position[0])+abs(position[3]-position[1])>position[4]){
            cout<<"alive"<<endl;
        }else{
            cout<<"die"<<endl;
        }
    }
}
