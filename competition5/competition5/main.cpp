#include <iostream>
#include<cstring>
using namespace std;

class Node{
private:
    int _number_a;
    int _number_b;
    char _char_operator;
    int _number_sum;
    Node *_pointer;
public:
    
    Node(){
        _pointer=NULL;
    }
    
    void setNumberA(int number_a){
        _number_a=number_a;
    }
    
    int getNumberA(){
        return _number_a;
    }
    
    void setNumberB(int number_b){
        _number_b=number_b;
    }
    
    int getNumberB(){
        return _number_b;
    }
    
    void calOperator(){
        if(_number_a>_number_b)
            _char_operator='>';
        else if(_number_a==_number_b)
            _char_operator='=';
        else if(_number_a<_number_b)
            _char_operator='<';
    }
    
    char getOperator(){
        return _char_operator;
    }
    
    void calNumberSum(){
        _number_sum=_number_a+_number_b;
    }
    
    int getNumberSum(){
        return _number_sum;
    }
    
    void setPointer(Node *pointer){
        _pointer=pointer;
    }
    
    Node* getPointer(){
        return _pointer;
    }
};

int main(){
    const int SPACE=' ';
    const int ENTER='\0';
    const int EXIT='0';
    Node *head=NULL;
    Node *add;
    Node *front,*rear;
    int count;
    char input[50];
    string series="";
    cout<<"please input number of group"<<endl;
    cin >> count;
    cin.get();
    for(int i=0;i<count;i++){
        cout<<"please input two number"<<endl;
        cin.getline(input, 50);
        
        if(input[0]==EXIT){
            break;
        }
        else{
            add=new Node;
            
            
            for(int j=0;j<50;j++){
                if(input[j]==ENTER){
                    add->setNumberB(atoi(series.c_str()));
                    add->calOperator();
                    add->calNumberSum();
                    front=head;
                    if(head==NULL){
                        add->setPointer(head);
                        head=add;
                    }else{
                        while(front!=NULL && front->getNumberSum()>add->getNumberSum()){
                            rear=front;
                            front=front->getPointer();
                        }
                        if(front==head){
                            add->setPointer(head);
                            head=add;
                        }else{
                            add->setPointer(rear->getPointer());
                            rear->setPointer(add);
                        }
                    }
                    
                    series="";
                    break;
                }else if(input[j]!=SPACE){
                    series+=input[j];
                }else if(input[j]==SPACE){
                    add->setNumberA(atoi(series.c_str()));
                    series="";
                }
            }
        }
    }
    
    
    
    front=head;
    while(front!=NULL){
        cout<<front->getOperator()<<front->getNumberSum()<<endl;
        front=front->getPointer();
    }
}
