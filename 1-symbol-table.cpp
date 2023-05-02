#include <bits/stdc++.h>
using namespace std;

class symbol {
public:
    unordered_map<char,int> hashmap;
    
   
    void createTable(string temp){
        for(int i=0;i<temp.length();i++){
            
            hashmap[temp[i]] = 100 + (rand() % 2000);
        }
        cout<<"Table created"<<"\n";
    }
   
    void viewTable() {
        cout<<"Symbol Table"<<"\n";
        for(auto i : hashmap){
            string type = isalpha(i.first) ? "identifier" : "operator";
            cout<<"Symbol:"<<i.first<<"  Address:"<<i.second<<" Type:"<<type<<"\n";
        }
    }
   
    void removeSymbol(char n){
        if(hashmap.find(n) != hashmap.end()){
            hashmap.erase(n);
            cout<<"Symbol removed"<<"\n";
        }
        else{
            cout<<"Symbol does not exist"<<"\n";
        }
    }
   
    void enterSymbol(char n){
        if(hashmap.find(n) != hashmap.end()){
            cout<<"Symbol already exist"<<"\n";
        }
        else{
        
            hashmap[n] = 100 + (rand() % 2000);
            cout<<"Symbol inserted"<<"\n";
        }
    }
   
    void searchSymbol(char n){
        if(hashmap.find(n) != hashmap.end()){
            cout<<"Symbol"<<n<<"exists at address:"<<hashmap[n]<<"\n";
        }
        else{
            cout<<"Symbol does not exists"<<"\n";
        }
    }
   
};

int main() {
    bool flag=true;
    unordered_map<char,int> hashmap;
   
    symbol ob;
    char n;
    string temp;
    int x;
    while(flag){
        cout<<"\n1. Create table 2. Search symbol 3. Enter symbol 4. Remove symbol 5. View table 6. Exit"<<"\n";
        cout<<"Enter your choice:";
        cin>>x;
       
        switch(x){
            case 1:
            cout<<"Enter the expression:";
            cin>>temp;
            ob.createTable(temp);
            break;
           
            case 2:
            cout<<"Enter the symbol you want to search:";
            cin>>n;
            ob.searchSymbol(n);
           
            break;
           
            case 3:
            cout<<"Enter the symbol you want to add:";
            cin>>n;
            ob.enterSymbol(n);
            break;
           
            case 4:
            cout<<"Enter the symbol you want to remove:";
            cin>>n;
            ob.removeSymbol(n);
            break;
           
            case 5:
            ob.viewTable();
            break;
           
            case 6:
            flag = false;
            break;
        }
       
    }
   
     cout<<"program exited";

    return 0;
}

