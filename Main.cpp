#include<bits/stdc++.h>
#include"Additional Function.cpp"
using namespace std;
IFunction iFunction;
int main(){
    vector<string> CodeFile = iFunction.ReadFile();
    if(CodeFile.size() == 0)
       return 0;
    vector<pair<string, int>> CodeWithoutSpaceAndComment = iFunction.RemoveSpaceAndComment(CodeFile);
    bool isMatch;
    isMatch = iFunction.IsHeaderExists(CodeWithoutSpaceAndComment);
    if(!isMatch)
        return 0;
    isMatch = iFunction.IsMainFunctionExists(CodeWithoutSpaceAndComment);
    if(!isMatch)
        return 0;
    cout<<"Build finished";

}
