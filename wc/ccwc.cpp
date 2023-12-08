#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

struct wc{
    int chars=0;
    int lines=0;
    int words=0;
    int bytes=0;

    string toString(){
        return ("    "+ to_string(lines) +" "+ to_string(words) +" "+ to_string(chars));
    }
};

wc calc(ifstream &fin){
    /*return the no. of bytes in the file*/
    /*char size = 1 byte*/
    wc res;
    char c;
    bool state=false; // false means empty space, true means a word char
    while(fin.get(c)){
        ++res.chars;
        if(c=='\n'){
            res.lines++;
        }
        if(c == ' ' || c == '\t' || c == '\n' || c == '\r'){
            state=false;
        }
        else{
            if(!state)
                res.words++;
            state=true;
        }
    }
    return res;
}

wc calc(istream &cin){
    /*return the no. of bytes in the file*/
    /*char size = 1 byte*/
    wc res;
    char c;
    bool state=false; // false means empty space, true means a word char
    while(cin.get(c)){
        ++res.chars;
        if(c=='\n'){
            res.lines++;
        }
        if(c == ' ' || c == '\t' || c == '\n' || c == '\r'){
            state=false;
        }
        else{
            if(!state)
                res.words++;
            state=true;
        }
    }
    return res;
}

bool is_param(string s){
    if(s=="-c" || s=="-m" || s=="-l" || s=="-w")
        return true;
    return false;
}


int main(int argc, char *argv[]){
    ifstream fin; // create filestream object
    string filename = argv[argc-1];
    wc res;
    //
    bool no_file = is_param(filename);
    if(no_file){
        res = calc(cin);
        filename = "";
    }
    else{
        fin.open(filename);
        res = calc(fin);
    }
    string ss;
    for(int i=1; i < argc; i++){
        ss = argv[i];
        if(ss=="-l")
            cout << res.lines << " ";
        else if(ss=="-c" || ss=="-m")
            cout << res.chars << " ";
        else if(ss=="-w")
            cout << res.words << " ";
    }
    //
    if((argc==1 && no_file) || (argc==2 && !no_file)){
       cout << res.toString() << " " << filename; 
    }

    fin.close();
    return 0;
}