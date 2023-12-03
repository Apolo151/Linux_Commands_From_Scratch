#include <iostream>
#include <fstream>

using namespace std;


int bytes_num(ifstream &fin){
    /*return the no. of bytes in the file*/
    /*char size = 1 byte*/
    char c;
    int bytes_cnt=0;
    
    while(fin.get(c)){
        ++bytes_cnt;
    }
    return bytes_cnt;
}


int main(int argc, char *argv[]){
    ifstream fin; // create filestream object
    cout << argc << endl;
    fin.open(argv[argc-1]);
    
    cout << argv[argc-1] << '\n';
    if(argc > 1){
        cout << bytes_num(fin);
    }
    else{

    }

    fin.close();
    return 0;
}