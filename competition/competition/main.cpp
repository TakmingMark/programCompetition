#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    int customerBuyCandy;
    int customerTotalCandy;
    float rate;
    
    cout<<"customer buy the candy"<<endl;
    cin>>customerBuyCandy;
    
    cout<<"rate:"<<endl;
    cin >>rate;
    
    customerTotalCandy=customerBuyCandy;
    while((customerBuyCandy=customerBuyCandy * rate)>=1){
        customerTotalCandy+=customerBuyCandy;
    }
    cout<<customerTotalCandy;
    return 0;
}
