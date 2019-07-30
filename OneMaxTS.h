#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<ctime>
#include<fstream>
using namespace std;


class OneMaxTS{
public:
    int iter;
    int dim;
    int run;
    int tabuL;

    int fit1;
    int fit2;
    int Best;

    vector<int> alternation;
    vector<int> neighbor;
    vector<int> tabuList;


    OneMaxTS (int Iteration,int Dimension,int Run,int TabuLength);
    void TabuSearch();
    void initialize();
    vector<int> Transition(vector<int> arr);
    int Fitness(vector<int> arr);
    void Determination();
    bool IsTabu(int element);
    void InsertTabu(int element);
    void DelTabu(int element);
    void printInfo();
};