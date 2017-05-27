#include <iostream>
#include<cstring>
using namespace std;
class Node{
private:
    char *_word;
    Node *_pointer;
public:
    Node(){
        _pointer=NULL;
    }
    void setWord(char *word){
        _word=word;
    }
    
    char* getWord(){
        return _word;
    }
    
    void setPointer(Node *pointer){
        _pointer=pointer;
    }
    
    Node* getPointer(){
        return _pointer;
    }
};

int main(){
    int memoryWords;
    Node *memoryHead=NULL;
    
    int searchWords;
    Node *searchHead=NULL;
    
    Node *add;
    Node *front;
    char *word;
    
    cout<<"please input the number of words"<<endl;
    cin>>memoryWords;
    
    front=memoryHead;
    for(int i=0;i<memoryWords;i++){
        add=new Node;
        word=new char[20];
        
        cin>>word;
        add->setWord(word);
        
        if(memoryHead==NULL){
            memoryHead=add;
            front=memoryHead;
        }
        else{
            front->setPointer(add);
            front=front->getPointer();
        }
        add=new Node;
    }
        
    
    
    cout<<"please input search number of words"<<endl;
    cin>>searchWords;
    
    front=searchHead;
    for(int i=0;i<searchWords;i++){
        add=new Node;
        word=new char[20];
        
        cin>>word;
        add->setWord(word);
        
        if(searchHead==NULL){
            searchHead=add;
            front=searchHead;
        }
        else{
            front->setPointer(add);
            front=front->getPointer();
        }
        add=new Node;
    }
    
    cout<<"---------------"<<endl;
    
    Node *search;
    Node *memory;
    Node *insert;
    bool memory_bool;
    search=searchHead;
    while(search!=NULL){
        memory=memoryHead;
        memory_bool=false;
        
        while(memory!=NULL){
            if(strcmp(search->getWord(), memory->getWord())==0){
                memory_bool=true;
            }
            memory=memory->getPointer();
        }
        
        if(memory_bool==false){
            cout<<"no"<<endl;
            
            add=new Node;
            add->setWord(search->getWord());
            insert=memoryHead;
            
            while(insert->getPointer()!=NULL){
                insert=insert->getPointer();
            }
            insert->setPointer(add);
        }
        else{
            cout<<"yes"<<endl;
        }
        search=search->getPointer();
    }
}
