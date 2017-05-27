#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Node{
private:
    int *_int_array;
    int _count;
    int _m;
    Node *_pointer;
public:
    
    void setInt_array(int *int_array){
        _int_array=int_array;
    }
    
    int* getInt_array(){
        return _int_array;
    }
    
    void setCount(int count){
        _count=count;
    }
    
    int getCount(){
        return _count;
    }
    
    void setM(int m){
        _m=m;
    }
    
    int getM(){
        return _m;
    }
    
    void setPointer(Node *pointer){
        _pointer=pointer;
    }
    
    Node* getPointer(){
        return _pointer;
    }
    
    void testPrint(){
        cout<<"count:"<<_count<<endl;
        cout <<"_m"<<_m<<endl;

        for(int i=0;i<_count;i++){
            cout<<*(_int_array+i)<<endl;
        }
    }
    
    void sortArray(){
        for(int i=0;i<_count;i++){
            for(int j=i+1;j<_count;j++){
                if(*(_int_array+j)<*(_int_array+i)){
                    int change=*(_int_array+j);
                    *(_int_array+j)=*(_int_array+i);
                    *(_int_array+i)=change;
                }
            }
        }
    }
    
    void print(){
        for(int i=0;i<_count-_m+1;i++){
            for(int j=i+_m-1;j<_count;j++){
                for(int k=0;k<_m-1;k++){
                    cout<<*(_int_array+i+k)<<" ";
                }
                 cout<<*(_int_array+j)<<endl;
            }
        }
         cout<<"----------------"<<endl;
    }
    
};
int main(int argc, const char * argv[]) {
    Node *head=NULL;
    Node *front=NULL;
    Node *add=new Node;
    const int SPACE=' ';
    const int ENTER='\0';
    const int EXIT='0';
    
    while(true){
        char input[1000];
        int *int_array=new int[1000];
        string series;
        int count=0;
        int m=0;
        cout<<"please input number array:"<<endl;
        
        cin.getline(input, 1000);
        
        if(input[0]==EXIT)
            break;
        
        for(int i=2;i<1000;i++){
            
            if(input[i]==ENTER){
                m=atoi(series.c_str());
                break;
            }
            else if(input[i]!=SPACE ){
                series=series+input[i];
            }
            else if(input[i]==SPACE){
                *(int_array+count)=atoi(series.c_str());
                series="";
                count++;
            }
        }
        
        add->setInt_array(int_array);
        add->setCount(count);
        add->setM(m);
        add->setPointer(NULL);
        
        if(head==NULL){
            head=add;
            front=head;
        }
        else{
            front->setPointer(add);
            front=front->getPointer();
        }
        add=new Node;
    }
    
    front=head;
    while(front!=NULL){
        front->sortArray();
        front->print();
        front=front->getPointer();
    }
    return 0;
}
