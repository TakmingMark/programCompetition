#include <iostream>
#include<cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    const int SPACE=' ';
    const int ENTER='\0';
    char *input;
    string content="";
    string series;
    string *str_array=new string[10];
    int count;
    
    while(true){
        input=new char[50];
        series="";
        cin.getline(input, 50);
        cout<<"input:"<<input<<endl;
        count=0;
        for(int i=0;i<50;i++){
            if(input[i]==ENTER){
                *(str_array+count)=series.c_str();
                series="";
                count++;
                break;
            }
            else if(input[i]!=SPACE ){
                series=series+input[i];
            }
            else if(input[i]==SPACE){
                *(str_array+count)=series.c_str();
                series="";
                count++;
            }
        }
        
        
        
        for(int i=0;i<count;){
            int number;
            if((*(str_array+i)).compare("insert")==0){
                i++;
                if((*(str_array+i)).compare("left")==0){
                    i++;
                    content=*(str_array+i)+content;
                    i++;
                }
                else if((*(str_array+i)).compare("right")==0){
                    i++;
                    content=content+*(str_array+i);
                    i++;
                }
                else if((number=atoi((*(str_array+i)).c_str()))!=0){
                    i++;
                    if(number==1){
                        content=*(str_array+i)+content;
                    }
                    else{
                        content=content.substr(0,number-1)+*(str_array+i)+content.substr(number-1,content.length()-1);
                    }

                    i++;
                }
            }
            else if((*(str_array+i)).compare("delete")==0){
                i++;
                if((*(str_array+i)).compare("left")==0){
                    i++;
                    content=content.substr(1,content.length()-1);
                    i++;
                }
                else if((*(str_array+i)).compare("right")==0){
                    i++;
                    content=content.substr(0,content.length()-1);
                    i++;
                }
                else if((number=atoi((*(str_array+i)).c_str()))!=0){
                    if(number==1){
                         content=content.substr(1,content.length()-1);
                    }
                    else{
                        content=content.substr(0,number-1)+content.substr(number,content.length()-1);
                    }
                    
                    i++;
                }
            }
            else{
                cout<<"input error,please input again"<<endl;
                break;
            }
            cout<<"count:"<<count<<endl;
            cout<<"i:"<<i<<endl;
            cout<<content<<endl;
        }
    }
}
