#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Node{
private:
    int _number;
    int _number_sum;
    Node *_pointer;
public:
    
    Node(){
        _pointer=NULL;
    }
    
    void setNumber(int number){
        _number=number;
    }
    
    int getNumber(){
        return _number;
    }
    void setPointer(Node *pointer){
        _pointer=pointer;
    }
    
    Node* getPointer(){
        return _pointer;
    }
};


Node* combination(Node *head,int array[],int size){
    int m=size;
    Node *add;
    int sum=0;
    for(int n=1;n<m;n++){
        if(n==1){
            for(int i=0;i<m;i++){
                add=new Node;
                sum+=array[i];
                add->setNumber(sum);
                add->setPointer(head);
                head=add;
                sum=0;
            }
        }
        else{
            for(int i=0;i<(m-n)+1;i++){
                for(int j=(i+n)-1;j<m;j++){
                    for(int k=0;k<(n)-1;k++){
                        sum+=array[i+k];
                    }
                    add=new Node;
                    sum+=array[j];
                    add->setNumber(sum);
                    add->setPointer(head);
                    head=add;
                    sum=0;
                }
            }
        }
    }
    
    return head;
}

int main(){
    const int SPACE=' ';
    const int ENTER='\0';
    const int MAX=700000;
    
    Node *head=NULL;
    char input[50];
    string series="";
    int count;
    int size=0;
    int combinationMax=0;
    
    cout<<"please input count"<<endl;
    cin>>count;
    
    int array[count];

    cout<<"please input number array"<<endl;
    cin.get();
    cin.getline(input, 50);
    
    for(int i=0;i<50;i++){
        if(input[i]==ENTER){
            array[size++]=atoi(series.c_str());
            series="";
            break;
        }
        else if(input[i]==SPACE){
            array[size++]=atoi(series.c_str());
            series="";
        }
        else{
            series+=input[i];
        }
    }

    
    head=combination(head,array,count);
    
    Node *front=head;
    while(front!=NULL){
        if(combinationMax<front->getNumber() &&front->getNumber()<MAX)
            combinationMax=front->getNumber();
        front=front->getPointer();
    }
    
    cout<<"The power maximum is "<<combinationMax<<endl;
}
