#include <iostream>
using namespace std;

int main(){

    string position = "";   //represent a position
    string turn = "";   //represent a players turn
    string m_number = "";   //represent a number of moves

    string split = "";   //helps to split a string

    //taking input
    int N;
    cin>>N;
    cin.ignore();
    for(int i=0;i<N;i++){
        string fen;
        // getline(cin,fen);
        fen = "2l4/7/4z2/4c2/PP2EP1/3L2p/7 b 23";
        int index = 0;  //help with indexes
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

        /*Complexity Analsis :
            // Time c is :O(n) looping the whole input
            // Space c is :O(n) loop,adding the char loop everyrtime i loop
        */
        //done assigning
        
        split = "";
        index = 0 ;

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

        for(auto x:position){
            if(x == '/'){
                // found rank
                if(index == 0){
                    // first index for 7th rank
                    file7 = split;
                    index++;
                    split = "";
                }else if(index == 1){
                    // second index for 6th rank
                    file6 = split;
                    index++;
                    split = "";
                }else if(index == 2){
                    // second index for 5th rank
                    file5 = split;
                    index++;
                    split = "";
                }else if(index == 3){
                    // second index for 4th rank
                    file4 = split;
                    index++;
                    split = "";
                }else if(index == 4){
                    // second index for 3th rank
                    file3 = split;
                    index++;
                    split = "";
                }else if(index == 5){
                    // second index for 2nd rank
                    file2 = split;
                    index++;
                    split = "";
                }
            }
            else{
                split += x;
                file1 = split;    // 1st rank
            }
        }

        cout<<"File7: "<<file7<<endl;
        cout<<"File6: "<<file6<<endl;
        cout<<"File5: "<<file5<<endl;
        cout<<"File4: "<<file4<<endl;
        cout<<"File3: "<<file3<<endl;
        cout<<"File2: "<<file2<<endl;
        cout<<"File1: "<<file1<<endl;
    }
    return 0;
}