#include "OneMaxTS.h"

OneMaxTS::OneMaxTS(int Iteration, int Dimension, int Run, int TabuLength){
    iter = Iteration;
    dim = Dimension;
    run = Run;
    tabuL = TabuLength;
    fit1=0;
    fit2=0;
    Best=0;

    alternation = vector<int> (dim,0);
    neighbor = vector<int> (dim,0);
    tabuList = vector<int> (tabuL,-1);
    srand(time(NULL));
}

void OneMaxTS::TabuSearch(){
    string s = "output0.dat";
    for(int r=0;r<run;r++){
        initialize();
        if(r<10)
            s.replace(6,1,to_string(r+1));
        else
            s.replace(6,2,to_string(r+1));
        ofstream file(s);

        Best = Fitness(alternation);
        for(int i=0;i<iter;i++){
            neighbor = Transition(alternation);
            fit1 = Fitness(alternation);
            fit2 = Fitness(neighbor);
            Determination();

            //cout << "Best: " << Best << endl;
            // if(Best==dim){
            //     cout << i << " iterations" <<endl;
            //     break;
            // }
            file << (i+1) << " " << Best << endl;
        }
        file.close();
    }

}

void OneMaxTS::initialize(){
    for(int i=0;i<dim;i++)
        alternation[i] = rand()%2;
}

vector<int> OneMaxTS::Transition(vector<int> arr){
    int pos;

    while(true){
        pos = rand()%dim;
        if( IsTabu(pos)==true )
            continue;
        else{
            if(arr[pos]==1) arr[pos] = 0;
            else arr[pos] = 1;
            InsertTabu(pos);
            break;
        }
    }
    return arr;
}

int OneMaxTS::Fitness(vector<int> arr){
    int cnt=0;
    for(int i=0;i<dim;i++)
        if(arr[i]==1)
            cnt++;
    return cnt;
}

void OneMaxTS::Determination(){
    if( fit1<fit2 ){
        alternation = neighbor;
        Best = fit2;
    }
}

bool OneMaxTS::IsTabu(int element){
    bool temp=false;
    for(int i=0;i<tabuL;i++)
            if(tabuList[i]==element)
                temp = true;
             
    return temp;

}

void OneMaxTS::InsertTabu(int element){
    int update = 0;
    for(int i=0;i<tabuL;i++){
        if(tabuList[i]==-1){
            tabuList[i] = element;
            update = 1; 
            break;
        }   
    }
    if(update==0){
        tabuList.erase(tabuList.begin());
        tabuList.push_back(element);
    }
}

void OneMaxTS::DelTabu(int element){
    int found=0;
    for(int i=0;i<tabuL;i++){
        if(tabuList[i]==element){
            found = 1;
            tabuList.erase(tabuList.begin()+i);
            tabuList.push_back(-1);
            break;
        }   
    }
    if(!found)
        cout << "Not found element!" << endl;
}

void OneMaxTS::printInfo(){
    
}
