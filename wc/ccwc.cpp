#include <iostream>
#include <fstream>

using namespace std;


int bytes_num(ifstream &in){
    /*return the no. of bytes in the file*/
    /*char size = 1 byte*/
    char c;
    int bytes_cnt=0;
    
    while(!in.eof()){
        in.get(c);
        ++bytes_cnt;
    }
    return bytes_cnt;
}


int main(int argc, char *argv[]){
    ifstream InFile; // create filestream object
    InFile.open(argv[argc-1], ios::binary);
    
    cout << argv[argc-1] << '\n';
    if(argc > 1){
        cout << bytes_num(InFile);
    }
    else{

    }

    InFile.close();
    return 0;
}