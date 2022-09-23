#include <iostream>
using namespace std;

int main(){

    string position = "";   //represent a position
    string turn = "";   //represent a players turn
    string m_number = "";   //represent a number of moves

    //taaking input
    int N;
    cin>>N;
    cin.ignore();
    for(int i=0;i<N;i++){
        string fen;
        // getline(cin,fen);
        fen = "2l4/7/4z2/4c2/PP2EP1/3L2p/7 b 23";
        string split = "";   //helps to split a string
        int index = 0;  //(0,1,2) - (position,turn,number)
        for(auto x:fen){
            if(x == ' '){
                // found space
                if(index == 0){
                    // first index for postion
                    position = split;
                    index++;
                    split = "";
                }
                else if(index == 1){
                    // first index for tune
                    turn = split;
                    index++;
                    split = "";
                }
            }
            else{
                split += x;
                m_number = split;    // last for number of moves
            }
        }
        
        //done assigning
    }

    //Complexity Analsis :
        // Time c is :O(n) looping the whole input
        // Space c is :O(n) loop,adding the char loop everyrtime i loop
    
    cout<<"Position "<<position<<endl;
    cout<<"Turn "<<turn<<endl;
    cout<<"Moves "<<m_number<<endl;

    string file7 = "";
    string file6 = "";
    string file5 = "";
    string file4 = "";
    string file3 = "";
    string file2 = "";
    string file1 = "";

    //done
    return 0;
}