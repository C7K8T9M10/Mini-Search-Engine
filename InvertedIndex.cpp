#include "stmr.h"
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include <string.h>
#include<string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <vector>

std::map<std::string,std::map<int,int>>invertedindex;

std::set<std::string> stopwordlist;

std::vector<std::string> filename;

void getstopword() {
    std::string file = "Mini Search Engine//stopword.txt";
    std::ifstream in(file);

    if (in) {
        std::string word;
        while (in >> word) {
            stopwordlist.insert(word);
        }
        in.close();
        std::cout << "Stop words have been loaded." << std::endl;
    } else {
        std::cerr << "Unable to open the file: " << file << std::endl;
    }
}

/*void stemmer(std::string s){
    char *p=(char*)s.data();
    s=s.substr(0,stem(p,0,s.size()-1)+1);
}*/

void readfiletitle(){
      std::string file = "Mini Search Engine//titles.txt";
    std::ifstream in(file);
    if (in) {
        std::string word;
        while (in >> word) {
            filename.push_back(word);
        }
        in.close();
        std::cout << "Titles have been loaded." << std::endl;
    } else {
        std::cerr << "Unable to open the file: " << file << std::endl;
    }
}

bool isstopword(std::string s){
    if(stopwordlist.empty()){
        getstopword();
    }
    if(stopwordlist.find(s)==stopwordlist.end()){
        return true;
    }
    return false;
}

void readfilecontent(){
    for(int i=0;i<filename.size();i++){
        std::string path="Mini Search Engine//FullShakespeare//";
        std::ifstream in(path+filename[i]);
        if(in){
        std::string word;
        while(in>>word) {
        transform(word.begin(),word.end(),word.begin(),::tolower);
          if(isstopword(word)==false)
          continue;
          if (invertedindex.find(word)==invertedindex.end()) {
    // 如果外层键不存在，则添加一个新的内层 map
    invertedindex[word]=std::map<int, int>();
        }
    invertedindex[word][i]++;
    }
        }else{
            std::cerr << "Unable to open the file: " << filename[i] << std::endl;
        }
       
}
}

void bulidindex(){

}

int main(){
    getstopword();
    readfiletitle();
    readfilecontent();
    std::cout<<invertedindex.size()<<std::endl;
    std::cout<<invertedindex["play"][0];
    for(int i=0;i<12;i++){
       i+=10;
    }
}