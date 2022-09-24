#include <iostream>
#include <vector>
using namespace std;



vector<string> Wpawn;
vector<string> Wsuperpawn;
vector<string> Wgirafe;
vector<string> Wmonkey;
vector<string> Welephant;
vector<string> Wlion;
vector<string> Wcrocodile;
vector<string> Wzebra;

vector<string> Bpawn;
vector<string> Bsuperpawn;
vector<string> Bgirafe;
vector<string> Bmonkey;
vector<string> Belephant;
vector<string> Blion;
vector<string> Bcrocodile;
vector<string> Bzebra;
void addtovector(string input,int col){
    // int player = 0;
    for(int i=0;i<7;i++){
        char row = (char)('a'+i);
        if(input[i] == 'P'){
            string square = "";
            square += row;
            square += to_string(col);
            Wpawn.push_back(square);
        }
        else if(input[i] == 'S'){
            string square = "";
            square += row;
            square += to_string(col);
            Wsuperpawn.push_back(square);
        }else if(input[i] == 'G'){
            string square = "";
            square += row;
            square += to_string(col);
            Wsuperpawn.push_back(square);
        }else if(input[i] == 'M'){
            string square = "";
            square += row;
            square += to_string(col);
            Wmonkey.push_back(square);
        }else if(input[i] == 'E'){
            string square = "";
            square += row;
            square += to_string(col);
            Welephant.push_back(square);
        }else if(input[i] == 'L'){
            string square = "";
            square += row;
            square += to_string(col);
            Wlion.push_back(square);
        }else if(input[i] == 'C'){
            string square = "";
            square += row;
            square += to_string(col);
            Wcrocodile.push_back(square);
        }else if(input[i] == 'Z'){
            string square = "";
            square += row;
            square += to_string(col);
            Wzebra.push_back(square);
        }else if(input[i] == 'p'){
            string square = "";
            square += row;
            square += to_string(col);
            Bpawn.push_back(square);
        }else if(input[i] == 's'){
            string square = "";
            square += row;
            square += to_string(col);
            Bsuperpawn.push_back(square);
        }else if(input[i] == 'g'){
            string square = "";
            square += row;
            square += to_string(col);
            Bsuperpawn.push_back(square);
        }else if(input[i] == 'm'){
            string square = "";
            square += row;
            square += to_string(col);
            Bmonkey.push_back(square);
        }else if(input[i] == 'e'){
            string square = "";
            square += row;
            square += to_string(col);
            Belephant.push_back(square);
        }else if(input[i] == 'l'){
            string square = "";
            square += row;
            square += to_string(col);
            Blion.push_back(square);
        }else if(input[i] == 'c'){
            string square = "";
            square += row;
            square += to_string(col);
            Bcrocodile.push_back(square);
        }else if(input[i] == 'z'){
            string square = "";
            square += row;
            square += to_string(col);
            Bzebra.push_back(square);
        }
    }
}
void print(){
    cout<<"white pawn:";
    for(int j=0;j<Wpawn.size();j++){
        cout<<" "<<Wpawn.at(j);
    }cout<<endl;
    cout<<"black pawn:";
    for(int j=0;j<Bpawn.size();j++){
        cout<<" "<<Bpawn.at(j);
    }cout<<endl;
    cout<<"white superpawn:";
    for(int j=0;j<Wsuperpawn.size();j++){
        cout<<" "<<Wsuperpawn.at(j);
    }cout<<endl;
    cout<<"black superpawn:";
    for(int j=0;j<Bsuperpawn.size();j++){
        cout<<" "<<Bsuperpawn.at(j);
    }cout<<endl;
    cout<<"white giraffe:";
    for(int j=0;j<Wgirafe.size();j++){
        cout<<" "<<Wgirafe.at(j);
    }cout<<endl;
    cout<<"black giraffe:";
    for(int j=0;j<Bgirafe.size();j++){
        cout<<" "<<Bgirafe.at(j);
    }cout<<endl;
    cout<<"white monkey:";
    for(int j=0;j<Wmonkey.size();j++){
        cout<<" "<<Wmonkey.at(j);
    }cout<<endl;
    cout<<"black monkey:";
    for(int j=0;j<Bmonkey.size();j++){
        cout<<" "<<Bmonkey.at(j);
    }cout<<endl;
    cout<<"white elephant:";
    for(int j=0;j<Welephant.size();j++){
        cout<<" "<<Welephant.at(j);
    }cout<<endl;
    cout<<"black elephant:";
    for(int j=0;j<Belephant.size();j++){
        cout<<" "<<Belephant.at(j);
    }cout<<endl;
    cout<<"white lion:";
    for(int j=0;j<Wlion.size();j++){
        cout<<" "<<Wlion.at(j);
    }cout<<endl;
    cout<<"black lion:";
    for(int j=0;j<Blion.size();j++){
            cout<<" "<<Blion.at(j);
    }cout<<endl;
    cout<<"white crocodile:";
    for(int j=0;j<Wcrocodile.size();j++){
        cout<<" "<<Wcrocodile.at(j);
    }cout<<endl;
     cout<<"black crocodile:";
    for(int j=0;j<Bcrocodile.size();j++){
        cout<<" "<<Bcrocodile.at(j);
    }cout<<endl;
     cout<<"white zebra:";
    for(int j=0;j<Wzebra.size();j++){
        cout<<" "<<Wzebra.at(j);
    }cout<<endl;
     cout<<"black zebra:";
    for(int j=0;j<Bzebra.size();j++){
        cout<<" "<<Bzebra.at(j);
    }cout<<endl;
}
void clearArray(){
    Wpawn.clear();
    Wsuperpawn.clear();
    Wgirafe.clear();
    Wmonkey.clear();
    Welephant.clear();
    Wlion.clear();
    Wcrocodile.clear();
    Wzebra.clear();

    Bpawn.clear();
    Bsuperpawn.clear();
    Bgirafe.clear();
    Bmonkey.clear();
    Belephant.clear();
    Blion.clear();
    Bcrocodile.clear();
    Bzebra.clear();
}
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
        getline(cin,fen);
        // fen = "2l4/7/4z2/4c2/PP2EP1/3L2p/7 b 23";
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
        
        split = "";
        index = 0 ;

        // cout<<"Position "<<position<<endl;
        // cout<<"Turn "<<turn<<endl;
        // cout<<"Moves "<<m_number<<endl;

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

                if(isdigit(x)){
                    int s = x-'0';
                    // cout<<"number: "<<s<<endl;
                    for(int j=0;j<s;j++){
                        split += "0";
                    }
                }
                else{
                    split += x;
                }
                
                file1 = split;    // 1st rank
            }
        }
        
        /*Complexity Analsis :
            // Time c is :O(n) looping the whole input
            // Space c is :O(n) loop,adding the char loop everyrtime i loop
        */

        addtovector(file7,7);
        addtovector(file6,6);
        addtovector(file5,5);
        addtovector(file4,4);
        addtovector(file3,3);
        addtovector(file2,2);
        addtovector(file1,1);
        print();
        if(turn == "b"){
            cout<<"side to play: black"<<endl;
        }
        else{
            cout<<"side to play: white"<<endl;
        }
        clearArray();
    }
    return 0;
}

