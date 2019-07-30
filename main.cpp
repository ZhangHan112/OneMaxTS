#include "OneMaxTS.h"

int main(int argc,char *argv[]){
    int Iteration = atoi(argv[1]);
    int Dimension = atoi(argv[2]);
    int Run = atoi(argv[3]);
    int TabuLength = atoi(argv[4]);

    OneMaxTS ts(Iteration,Dimension,Run,TabuLength);
    ts.TabuSearch();
    
    
    return 0;
}