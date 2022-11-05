#include<bits/stdc++.h>
using namespace std;

class Reguler_Expression{
public:
    regex removeFrontSpaceOrTabe() {
        return regex("^[ \t]*");
    }
    regex removeEndSpaceOrTabe() {
        return regex("[ \t]*$");
    }
    regex removeAllSingleLineComment() {
        return regex("[ \t]*//");
    }
    regex isHeaderFile() {
        return regex("#( )*include( )*(<)(stdio|string|math|time).h( )*>");
    }
    regex isMainFile() {
        return regex("^(int|void|char|double|float) +main( )*\\( *\\) *\\{$");
    }
};
