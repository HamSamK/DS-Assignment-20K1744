#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
using namespace std;
int main()
{
    int elements;
    srand(time(0));
    for(elements=0; elements<500; elements++)
        cout<<rand()<<endl;
    cout<<endl;
    
    ofstream PTR("500 Elements.txt");
    for(elements=0; elements<500; elements++)
        PTR << rand() <<endl;
	
	PTR.close();
    return 0;
}
