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


int main(int argc, char *argv[]){
    ifstream fin; // create filestream object
    fin.open(argv[argc-1]);
    wc res = calc(fin); 
    //cout << (strcmp(argv[1], "-c"));
    //cout << res.lines << endl;
    string ss;
    if(argc > 2){
        for(int i=1; i < argc; i++){
            ss = argv[i];
            if(ss=="-l")
                cout << res.lines << " ";
            else if(ss=="-c" || ss=="-m")
                cout << res.chars << " ";
            else if(ss=="-w")
                cout << res.words << " ";
        }
    }
    else if(argc > 1){
       cout << res.toString() << " " << argv[argc-1]; 
    }
    else{
        cout << "Please specify your file name";
    }

    fin.close();
    return 0;
}