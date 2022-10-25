#include<bits/stdc++.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<math.h>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<sstream>
#include<string.h>
#include<deque>
using namespace std;
#include"person.h"
using namespace std;

class doctor:public person
{
public:
    string id,degree,college,spacialist;
};

doctor dr[100];
int number_of_doctor=0;      //gobal declaretion of total_doctor as we need everytime



void show_doctor_list()           //presenting the doctor list in console
{
    read_doctor();           //read the txt file first
    int i =0;
    cout<<"Doctor List : \n";
    cout<<"-------------\n";
    while(i<number_of_doctor)
    {
//please check this line   ↓   this colon should be in line **********
        cout<<"ID          : "<<dr[i].id<<endl;
        cout<<"Name        : "<<dr[i].name<<endl;
        cout<<"Degree      : "<<dr[i].degree<<endl;
        cout<<"College     : "<<dr[i].college<<endl;
        cout<<"Mobile NO.  : "<<dr[i].mobile_no<<endl;
        i++;
        cout<<"\n"<<endl;
    }
}
 


void add_doctor()        //adding new doctor.
{
    read_doctor();       //reading previous list for rewriting
    doctor new_doctor;    //variable for new doctor
    cout<<"\n\nADDING NEW DOCTOR DETAILS\n";
    cout<<"------------------------\n";         
//  this line please   ↓         //taking all of the details below
    cout<<"ID             : ";
    getline(cin,new_doctor.id);
    cout<<"Doctor Name    : ";
    getline(cin,new_doctor.name);
    cout<<"Doctor Degree  : ";
    getline(cin,new_doctor.degree);
    cout<<"Doctor College : ";
    getline(cin,new_doctor.college);
    cout<<"Mobile No.     : ";
    getline(cin,new_doctor.mobile_no);
 
    ofstream doo("text/doctor.txt");           //opening file in write mode to rewrite every doctor
    int i =0;
    dr[number_of_doctor].id = new_doctor.id;             //setting new_doctor data in array varible 
    dr[number_of_doctor].name = new_doctor.name;
    dr[number_of_doctor].degree = new_doctor.degree;
    dr[number_of_doctor].college = new_doctor.college;
    dr[number_of_doctor].mobile_no = new_doctor.mobile_no;
    number_of_doctor++;              //total doctor number increase by one
    while(i<number_of_doctor)        //rewriting doctor data again in txt file.   ** BE AWARE WITH THE VAUE OF i
    {
        doo<<dr[i].id<<endl;
        doo<<dr[i].name<<endl;
        doo<<dr[i].degree<<endl;
        doo<<dr[i].college<<endl;
        doo<<dr[i].mobile_no<<endl;
        i++;
        doo<<"\n";
    }
    doo.close();         //close file after writing is done
 
}




int main()
{
    show_doctor_list();
    add_doctor();
    show_doctor_list();
}
