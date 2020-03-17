#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std ;

string toupper_for_str(string x){
    string y = x ;
    for(int i = 0;i < x.size();i++){
        y[i] = toupper(x[i]);
    }
    return y ;
}

int main(){
    string asd ;
    string qwe ;
    string textline ;
    ifstream source ;
    vector <string> nam ;
    vector <float> score ;
    vector <string> grade ;
    string grade_1 ;
    source.open("name_score.txt") ;
    while(getline(source,textline)){
        char format[] = "%[^:]: %f %f %f" ;
        char name[100] ;
        float a , b , c ;
        sscanf(textline.c_str(),format,name,&a,&b,&c) ;
        /*cout << name << endl ;
        cout << a << " " << b << " " << c << endl ;*/
        if(a+b+c >= 80) grade_1 = "A" ;
            else if(a+b+c >= 70) grade_1 = "B" ;
                else if(a+b+c >= 60) grade_1 = "C" ;
                    else if(a+b+c >=50) grade_1 ="D" ;
                        else grade_1 = "F" ;
        nam.push_back(name) ;
        score.push_back(a+b+c) ;
        grade.push_back(grade_1) ;

    }

    for(int i=0; ; i++){
        cout << "Please input your command :" ;
        getline(cin,asd) ;
        asd = toupper_for_str(asd);
        if(asd == "EXIT") break ;
            else if(asd.substr(0,6) == "GRADE " ){
                for(int j=0;j<26;j++){
                    if(asd.substr(6,1) == grade[j] ){
                        cout << nam[j] << endl ;
                    }
                    if(asd.substr(6,1) != "A" & asd.substr(6,1) != "B" & asd.substr(6,1) != "C" & asd.substr(6,1) != "D" & asd.substr(6,1) != "F" ){
                       cout << "Cannot Found." << endl ;
                      break ;
                    }
                   
                }
            }
            else if(asd.substr(0,5) == "NAME "){
                for(int k=0;k<26;k++){
                    qwe = toupper_for_str(nam[k]);
                    if(asd.substr(5,asd.size()-5) == qwe){
                        cout << nam[k] <<"'s "<< "grade = " << grade[k] << endl;
                        break ;
                    }
                    if(k == 25 ) cout << "Cannot found." << endl ;
                }
            }
                else cout << "Invalid command" << endl;
        cout << "---------------------------------------------" << endl ;
    }


    return 0 ;
}