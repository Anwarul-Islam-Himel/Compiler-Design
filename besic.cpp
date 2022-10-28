#include<bits/stdc++.h>
using namespace std;

vector<string> Contains;
vector<string> Headers;
vector<string> Keyword;
queue<string> Token;
bool Main = false;

void Push();

bool Compile(){
    int i,j;
    bool x = true;
    string temp;
    while(!Token.empty()){
        temp = Token.front();
        Token.pop();
        if(temp[0] == '#'){
            temp = Token.front();
            Token.pop();
            for(i=0;i<Contains.size();i++){
                x = true;
                if(temp.compare(Contains[i]) != 0)
                    x = false;
                if(x)
                    break;
            }
            if(x){
                temp = Token.front();
                Token.pop();
                for(i=0;i<Headers.size();i++){
                    x = true;
                    if(temp.compare(Headers[i]) != 0)
                        x = false;
                    if(x)
                        break;
                }
            }
            if(!x){
                cout<<"No such file or directory";
                return false;
            }
            return true;
        }
        if(temp == "int" || temp == "void"){
            temp = Token.front();
            Token.pop();
            if(temp.compare("main(){") == 0){
                Main = true;
            }
            if(!Main)
                cout<<"undefined reference ";
            return Main;
        }
        if(temp.compare(Contains[2]) == 0){
            temp = Token.front();
            Token.pop();
            if(temp.compare("0;") == 0)
                return true;
            cout<<"undefined reference ";
            return false;
        }
        if(temp.compare("}")==0)
            return true;
        cout<<"undefined reference ";
        return false;
    }
}

int main(){
    Push();
    int lineNumber = 0;
    ifstream myfile;
    myfile.open("text.txt");
    string myline,t;
    bool flag;
    if(myfile.is_open()){
       while(getline(myfile,myline)){
           lineNumber++;
           stringstream X(myline);
           while(getline(X,t,' ')){
                if(t[0] != ' '){
                    Token.push(t);
                }
           }
           flag = Compile();
           if(!flag){
               return 0;
           }
       }
       cout<<"Build finished";
       myfile.close();
    }else{
        cout<<"File isn't open";
    }
    return 0;
}

void Push(){
    Contains.push_back("define");
    Contains.push_back("include");
    Contains.push_back("return");

    Headers.push_back("<stdio.h>");
    Headers.push_back("<math.h>");

    Keyword.push_back("void");
    Keyword.push_back("int");
}

