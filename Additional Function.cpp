#include<bits/stdc++.h>
#include"RE.cpp"
using namespace std;
class IFunction{
    Reguler_Expression re;
    smatch match;
public:
    //File read
    vector<string> ReadFile(){
        fstream File;
        File.open("text.txt");
        vector<string> CodeFile;
        if(File.is_open()) {
            string str;
            while(getline(File, str)) {
                CodeFile.push_back(str);
            }
        } else {
            cout <<"File isn't open\n";
        }
        return CodeFile;
    }

    vector<pair<string, int>> RemoveSpaceAndComment(vector<string> lines){
         vector<pair<string, int>> CodeWithoutSpaceAndComment;
         for(int i = 0;i<lines.size();i++){
            string withoutSpace ="";
            if(regex_search(lines[i], match, re.removeFrontSpaceOrTabe())){
                withoutSpace = match.suffix().str();
            }
            if(regex_search(withoutSpace, match, re.removeEndSpaceOrTabe())){
                withoutSpace = match.prefix().str();
            }
            if(regex_search(withoutSpace, match, re.removeAllSingleLineComment())){
                withoutSpace = match.prefix().str();
            }
            if(!withoutSpace.empty()){
                CodeWithoutSpaceAndComment.push_back({withoutSpace, i+1});
            }
         }
         return CodeWithoutSpaceAndComment;
    }

    bool IsHeaderExists(vector<pair<string, int>> Codes){
        for(auto item: Codes){
            if(item.first[0] == '#') {
                string suffisAfterHeader = "";
                if(regex_search(item.first, match, re.isHeaderFile())) {
                    suffisAfterHeader = match.suffix().str();
                    if(suffisAfterHeader.empty()) {

                    } else {
                        cerr << "header file " << item.first << " is not correct in line number " << item.second << '\n';
                        return false;
                    }
                } else {
                    cerr << "header file " << item.first << " is not correct in line number " << item.second << '\n';
                    return false;
                }
            }
        }
        return true;
    }
    bool IsMainFunctionExists(vector<pair<string ,int>> Codes){
        for(auto item : Codes) {
            if(regex_search(item.first, match, re.isMainFile())) {
                return true;
            }
        }
        cout<<"Main function isn't correct ";
        return false;
    }
};
