#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string>moves_vector;
vector<string>files_vector;
vector<string>fen_vector;


vector<int>x_v;
vector<int>y_v;

int Counter;
string Turn;
string fen;


void clearArray(){
    files_vector.clear();
    x_v.clear();
    y_v.clear();
}
string Changer(int row,int col){

    char row_ = (char)('a'+(row));
    string square = "";
    square+=row_;
    square+=to_string(col+1);
    return square;
}
vector<string> Print(int x,int y){
    vector<string>finalle;
    for(int i=0; i<x_v.size() ; i++){
        string str = Changer(x_v.at(i),y_v.at(i));
        string square = Changer(x,y);
        square+=str;
        finalle.push_back(square);
    }

    x_v.clear();
    y_v.clear();
    sort(finalle.begin(),finalle.end());
    return finalle;
}
bool ValidPr(int curr_x_move,int curr_y_move){
    bool valid = false;
    if(curr_x_move<=6 && curr_x_move>=0){
        if(curr_y_move <= 6 && curr_y_move >= 0 ){
            if(Turn == "b"){
                if(files_vector.at(6-curr_y_move)[curr_x_move] =='0'){   
                    valid = true;
                }
            }
            else if(Turn == "w"){
                if(files_vector.at(6-curr_y_move)[curr_x_move] =='0'){
                    valid = true;  
                }
            }
        }
    }
    return valid;
}
bool ValidP(int curr_x_move,int curr_y_move){
    bool valid = false;
    if(curr_x_move<=6 && curr_x_move>=0){
        if(curr_y_move <= 6 && curr_y_move >= 0 ){
            if(Turn == "b"){
                if(isupper(files_vector.at(6-curr_y_move)[curr_x_move]) || files_vector.at(6-curr_y_move)[curr_x_move] =='0'){    
                    valid = true;
                }
            }
            else if(Turn == "w"){
                if(islower(files_vector.at(6-curr_y_move)[curr_x_move]) || files_vector.at(6-curr_y_move)[curr_x_move] =='0'){
                    valid = true;
                }
            }
        }
    }
    return valid;
}
bool ValidG(int curr_x_move,int curr_y_move){
        bool valid = false;
        if(curr_x_move<=6 && curr_x_move>=0){
            if(curr_y_move <= 6 && curr_y_move >= 0 ){
                if(Turn == "b"){
                    if(files_vector.at(6-curr_y_move)[curr_x_move] =='0'){    
                        valid = true;
                    }
                }
                else if(Turn == "w"){
                    if(files_vector.at(6-curr_y_move)[curr_x_move] =='0'){
                        valid = true;  
                    }
                }
            }
        }
        return valid;
    }
bool ValidZ(int curr_x_move,int curr_y_move){
            bool valid = false;
            if(curr_x_move<=6 && curr_x_move>=0){
                if(curr_y_move <= 6 && curr_y_move >= 0 ){
                    if(Turn == "b"){
                        if(isupper(files_vector.at(6-curr_y_move)[curr_x_move]) || files_vector.at(6-curr_y_move)[curr_x_move] =='0'){  
                            valid = true; 
                        }
                    }
                    else if(Turn == "w"){
                        if(islower(files_vector.at(6-curr_y_move)[curr_x_move]) || files_vector.at(6-curr_y_move)[curr_x_move] =='0'){
                            valid = true;  
                        }
                    }
                }
            }
            return valid;
        
        }
bool Valid(int curr_x_move,int curr_y_move){
            bool valid = false;
            if(curr_x_move<5 && curr_x_move>1){
                if((curr_y_move<=2 && curr_y_move>=0) || (curr_y_move<=6 && curr_y_move>=4) ){
                    if(Turn == "b"){
                        if(isupper(files_vector.at(6-curr_y_move)[curr_x_move]) || files_vector.at(6-curr_y_move)[curr_x_move] =='0'){
                            valid = true;  
                        }
                    }
                    else if(Turn == "w"){
                        if(islower(files_vector.at(6-curr_y_move)[curr_x_move]) || files_vector.at(6-curr_y_move)[curr_x_move] =='0'){
                            valid = true;  
                        }
                    }
                }
            }
            return valid;
        }
void State(string position){
     //for rows
    string file7 = "";
    string file6 = "";
    string file5 = "";
    string file4 = "";
    string file3 = "";
    string file2 = "";
    string file1 = "";
    string split = "";   //helps to split a string

    int index = 0;  //help with indexes

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
            }else{
                if(isdigit(x)){
                    int s = x-'0';
                    for(int j=0;j<s;j++){
                        split += "0";
                    }
                }else{
                    split += x;
                }
                file1 = split;    // 1st rank
            }
        }

        files_vector.push_back(file7);
        files_vector.push_back(file6);
        files_vector.push_back(file5);
        files_vector.push_back(file4);
        files_vector.push_back(file3);
        files_vector.push_back(file2);
        files_vector.push_back(file1);
}
void King(int x,int y){
    int curr_x = x+1;
    if(Valid(curr_x,y)){
        x_v.push_back(curr_x);
        y_v.push_back(y);
    }
    curr_x = x-1;
    if(Valid(curr_x,y)){
        x_v.push_back(curr_x);
        y_v.push_back(y);;
    }
    int curr_y = y-1;
    if(Valid(x,curr_y)){
        x_v.push_back(x);
        y_v.push_back(curr_y);
    }
    curr_y = y+1;
    if(Valid(x,curr_y)){
        x_v.push_back(x);
        y_v.push_back(curr_y);
    }
     curr_y = y-1;
     curr_x = x+1;
    if(Valid(curr_x,curr_y)){
        x_v.push_back(curr_x);
        y_v.push_back(curr_y);
    }
     curr_y = y+1;
     curr_x = x+1;
    if(Valid(curr_x,curr_y)){
        x_v.push_back(curr_x);
        y_v.push_back(curr_y);
    }
     curr_y = y-1;
     curr_x = x-1;
    if(Valid(curr_x,curr_y)){
        x_v.push_back(curr_x);
        y_v.push_back(curr_y);
    }
     curr_y = y+1;
     curr_x = x-1;
    if(Valid(curr_x,curr_y)){
        x_v.push_back(curr_x);
        y_v.push_back(curr_y);
    }

    if(Turn == "b"){
        for(int i=0;i<7;i++){
            string file = files_vector.at(i);
            int c = file.find('L');
            if(c!=-1){

                int k_opp_x = c;
                int k_opp_y = i;

                if(x == k_opp_x){
                    int p = 0;
                    for(int j = (6-y)+1;j<k_opp_y;j++){
                        if(files_vector.at(j)[x] != '0'){
                            p++;
                        }
                    }
                    if(p==0){
                        x_v.push_back(k_opp_x);
                        y_v.push_back(6-k_opp_y);              
                    }
                }
                else if((x==4 && k_opp_x==2) && (y==4 && (6-k_opp_y)==2) && (files_vector.at(3)[3] == '0')){
                    x_v.push_back(k_opp_x);
                    y_v.push_back(6-k_opp_y);
                }
                else if((x==2 && k_opp_x==4) && (y==4 &&(6-k_opp_y)==2) && (files_vector.at(3)[3] == '0')){
                    x_v.push_back(k_opp_x);
                    y_v.push_back(6-k_opp_y);
                }
            }
        }
    }

    else if(Turn=="w"){
        for(int i=0;i<7;i++){
            string file = files_vector.at(i);
            int c = file.find('l');
            if(c!=-1){
                int k_opp_x = c;
                int k_opp_y = i;
                if(x == k_opp_x){
                    int p = 0;
                    for(int j = k_opp_y+1;j <6-y;j++){
                        if(files_vector.at(j)[x] != '0'){
                            p++;
                        }
                    }
                    if(p==0){
                        x_v.push_back(k_opp_x);
                        y_v.push_back(6-k_opp_y);                 
                    }
                }
                else if((x==2 &&k_opp_x==4) && (y==2 && 6-k_opp_y==4) && (files_vector.at(3)[3] == '0')){
                    x_v.push_back(k_opp_x);
                    y_v.push_back(6-k_opp_y);
                }
                else if((x==4 && k_opp_x==2) && (y==2 && 6-k_opp_y==4) && (files_vector.at(3)[3] == '0')){
                    x_v.push_back(k_opp_x);
                    y_v.push_back(6-k_opp_y);
                }
            }
        }
    }
}
void Zebra(int x,int y){
    int curr_y = y+2;
    int curr_x = x+1;
    if(ValidZ(curr_x,curr_y)){
        x_v.push_back(curr_x);
        y_v.push_back(curr_y);
    }

    curr_y = y-2;
    curr_x = x+1;
    if(ValidZ(curr_x,curr_y)){
        x_v.push_back(curr_x);
        y_v.push_back(curr_y);
    }

    curr_y = y+2;
    curr_x = x-1;
    if(ValidZ(curr_x,curr_y)){
        x_v.push_back(curr_x);
        y_v.push_back(curr_y);
    }
    curr_y = y-2;
    curr_x = x-1;
    if(ValidZ(curr_x,curr_y)){
        x_v.push_back(curr_x);
        y_v.push_back(curr_y);
    }

    curr_y = y+1;
    curr_x = x+2;
    if(ValidZ(curr_x,curr_y)){
        x_v.push_back(curr_x);
        y_v.push_back(curr_y);
    }

    curr_y = y+1;
    curr_x = x-2;
    if(ValidZ(curr_x,curr_y)){
        x_v.push_back(curr_x);
        y_v.push_back(curr_y);
    }

    curr_y = y-1;
    curr_x = x-2;
    if(ValidZ(curr_x,curr_y)){
        x_v.push_back(curr_x);
        y_v.push_back(curr_y);
    }

    curr_y = y-1;
    curr_x = x+2;
    if(ValidZ(curr_x,curr_y)){
        x_v.push_back(curr_x);
        y_v.push_back(curr_y);
    }
}
void Geraffe(int x,int y){
    
            int curr_y = y+1;
            if(ValidG(x,curr_y)){
                x_v.push_back(x);
                y_v.push_back(curr_y);
            }
            int curr_x = x+1;
            if(ValidG(curr_x,y)){
                x_v.push_back(curr_x);
                y_v.push_back(y);  
            }
            if(ValidG(curr_x,curr_y)){
                x_v.push_back(curr_x);
                y_v.push_back(curr_y);
            }
            
            curr_y = y-1;
            if(ValidG(x,curr_y)){
                x_v.push_back(x);
                y_v.push_back(curr_y);
            }
            curr_x = x-1;
            if(ValidG(curr_x,y)){
                x_v.push_back(curr_x);
                y_v.push_back(y);
            }
            if(ValidG(curr_x,curr_y)){
                x_v.push_back(curr_x);
                y_v.push_back(curr_y);
            }

            curr_y = y+1;
            curr_x = x-1;
            if(ValidG(curr_x,curr_y)){
                x_v.push_back(curr_x);
                y_v.push_back(curr_y);
            }

            curr_y = y-1;
            curr_x = x+1;
            if(ValidG(curr_x,curr_y)){
                x_v.push_back(curr_x);
                y_v.push_back(curr_y);
            }

            curr_y =y+2;
            if(ValidZ(x,curr_y)){
                x_v.push_back(x);
                y_v.push_back(curr_y);
            }

            curr_x = x+2;
            if(ValidZ(curr_x,y)){
                x_v.push_back(curr_x);
                y_v.push_back(y);
            }
            if(ValidZ(curr_x,curr_y)){
                x_v.push_back(curr_x);
                y_v.push_back(curr_y);
            }

            curr_x = x-2;
            if(ValidZ(curr_x,y)){
                x_v.push_back(curr_x);
                y_v.push_back(y);
            }
            curr_y = y-2;
            if(ValidZ(x,curr_y)){
                x_v.push_back(x);
                y_v.push_back(curr_y);
            }
            if(ValidZ(curr_x,curr_y)){
                x_v.push_back(curr_x);
                y_v.push_back(curr_y);
            }

            curr_x = x+2;
            curr_y = y-2;
            if(ValidZ(curr_x,curr_y)){
                x_v.push_back(curr_x);
                y_v.push_back(curr_y);
            }
            curr_x = x-2;
            curr_y = y+2;
            if(ValidZ(curr_x,curr_y)){
                x_v.push_back(curr_x);
                y_v.push_back(curr_y);
            }
}
void Pawn(int x,int y){
    if(Turn == "w"){
        if(y>3){
            int curr_y = y-1;
            int possible = 0;
            if(ValidPr(x,curr_y)){
                possible++;
                x_v.push_back(x);
                y_v.push_back(curr_y);
            }

            curr_y = y-2;
            if(ValidPr(x,curr_y) && possible == 1){
                x_v.push_back(x);
                y_v.push_back(curr_y);
            }
        }
        int curr_y = y+1;
        if(ValidP(x,curr_y)){
            x_v.push_back(x);
            y_v.push_back(curr_y);
        }
        int curr_x = x+1;
        if(ValidP(curr_x,curr_y)){
            x_v.push_back(curr_x);
            y_v.push_back(curr_y);
        }
        curr_x = x-1;
        if(ValidP(curr_x,curr_y)){
            x_v.push_back(curr_x);
            y_v.push_back(curr_y);
        }
    }

    else if(Turn == "b"){
        if(y<3){
            int curr_y = y+1;
            int possible = 0;
            if(ValidPr(x,curr_y)){
                possible++;
                x_v.push_back(x);
                y_v.push_back(curr_y);
            }

            curr_y = y+2;
            if(ValidPr(x,curr_y) && possible == 1){
                x_v.push_back(x);
                y_v.push_back(curr_y);
            }
        }
        int curr_y = y-1;
        if(ValidP(x,curr_y)){
            x_v.push_back(x);
            y_v.push_back(curr_y);
        }
        int curr_x = x+1;
        if(ValidP(curr_x,curr_y)){
            x_v.push_back(curr_x);
            y_v.push_back(curr_y);
        }
        curr_x = x-1;
        if(ValidP(curr_x,curr_y)){
            x_v.push_back(curr_x);
            y_v.push_back(curr_y);
        }
    }
}
void Superpawn(int x,int y){
    if(Turn == "w"){
     
        int curr_y = y+1;
        if(ValidP(x,curr_y)){
            x_v.push_back(x);
            y_v.push_back(curr_y);
        }
        int curr_x = x+1;
        if(ValidP(curr_x,curr_y)){
            x_v.push_back(curr_x);
            y_v.push_back(curr_y);
        }
        if(ValidP(curr_x,y)){
            x_v.push_back(curr_x);
            y_v.push_back(y);
        }
        curr_x = x-1;
        if(ValidP(curr_x,curr_y)){
            x_v.push_back(curr_x);
            y_v.push_back(curr_y);
        }
        if(ValidP(curr_x,y)){
            x_v.push_back(curr_x);
            y_v.push_back(y);
        }
    }

    else if(Turn == "b"){

        int curr_y = y-1;
        if(ValidP(x,curr_y)){
            x_v.push_back(x);
            y_v.push_back(curr_y);
        }
        int curr_x = x+1;
        if(ValidP(curr_x,curr_y)){
            x_v.push_back(curr_x);
            y_v.push_back(curr_y);
        }
        if(ValidP(curr_x,y)){
            x_v.push_back(curr_x);
            y_v.push_back(y);
        }
        curr_x = x-1;
        if(ValidP(curr_x,curr_y)){
            x_v.push_back(curr_x);
            y_v.push_back(curr_y);
        }
        if(ValidP(curr_x,y)){
            x_v.push_back(curr_x);
            y_v.push_back(y);;
        }
    }

    if(Turn == "w"){
        int curr_y = y-1;
        int possible_y = 0;
        if(ValidPr(x,curr_y)){
            possible_y++;
            x_v.push_back(x);
            y_v.push_back(curr_y);
        }
        
        int curr_x = x-1;
        int possible_x_l = 0;
        if(ValidPr(curr_x,curr_y)){
            possible_x_l++;
            x_v.push_back(curr_x);
            y_v.push_back(curr_y);
        }
    
        curr_x = x+1;
        int possible_x_r = 0;
        if(ValidPr(curr_x,curr_y)){
            possible_x_r++;
            x_v.push_back(curr_x);
            y_v.push_back(curr_y);
        }

        curr_y = y-2;
        if(ValidPr(x,curr_y) && possible_y == 1){
            x_v.push_back(x);
            y_v.push_back(curr_y);
        }
        
        curr_x = x-2;
        if(ValidPr(curr_x,curr_y) && possible_x_l == 1){
            x_v.push_back(curr_x);
            y_v.push_back(curr_y);
        }
        curr_x = x+2;
        if(ValidPr(curr_x,curr_y) && possible_x_r == 1){
            x_v.push_back(curr_x);
            y_v.push_back(curr_y);
        }
    }

    else if(Turn == "b"){
        
        int curr_y = y+1;
        int possible_y = 0;
        if(ValidPr(x,curr_y)){
            possible_y++;
            x_v.push_back(x);
            y_v.push_back(curr_y);
        }
        
        int curr_x = x-1;
        int possible_x_l = 0;
        if(ValidPr(curr_x,curr_y)){
            possible_x_l++;
            x_v.push_back(curr_x);
            y_v.push_back(curr_y);
        }
       
        curr_x = x+1;
        int possible_x_r = 0;
        if(ValidPr(curr_x,curr_y)){
            possible_x_r++;
            x_v.push_back(curr_x);
            y_v.push_back(curr_y);
        }
        
        curr_y = y+2;
        if(ValidPr(x,curr_y) && possible_y == 1){
            x_v.push_back(x);
            y_v.push_back(curr_y);
        }
       
        curr_x = x-2;
        if(ValidPr(curr_x,curr_y) && possible_x_l == 1){
            x_v.push_back(curr_x);
            y_v.push_back(curr_y);
        }
       
        curr_x = x+2;
        if(ValidPr(curr_x,curr_y) && possible_x_r == 1){
            x_v.push_back(curr_x);
            y_v.push_back(curr_y);
        }
    }
}
void Game(){
    
    vector<string> output;
    for(int j=0;j<7;j++){
        if(Turn == "b"){
            string file = files_vector.at(j);
            for(int i=0;i<file.size();i++){
                  if(file[i] == 'p'){
                    vector<string> fetch;
                    // King(i,6-j);
                    // Zebra(i,6-j);
                    // Geraffe(i,6-j);
                    Pawn(i,6-j);
                    // Superpawn(i,6-j);
                    fetch = Print(i,6-j);
                    
                    for(string str:fetch){
                        output.push_back(str);
                    }
                }
            }        
        }
        else if (Turn == "w"){
            string file = files_vector.at(j);
            for (int i=0;i<file.size();i++){
                if(file[i] == 'P'){
                    vector<string> fetch;
                    // King(i,6-j);
                    // Zebra(i,6-j);
                    // Geraffe(i,6-j);
                    Pawn(i,6-j);
                    // Superpawn(i,6-j);
                    fetch = Print(i,6-j);
                    
                    for(string str:fetch){
                        output.push_back(str);
                    }
                }
            }
        }
    }

    sort(output.begin(),output.end());
    for(int i=0;i<output.size();i++){
        cout<<output.at(i);

        if(i<output.size()-1){
            cout<<" ";
        }
    }
}

void Piece_in_River_before(vector<int>& P_in_river){
    for(int i=0;i<7;i++){
        if(Turn=="w"){
            if(isupper(files_vector.at(3)[i])){
                P_in_river.push_back(i);
            }
        }
        else if(Turn == "b"){
            if(islower(files_vector.at(3)[i])){
                P_in_river.push_back(i);
            }
        }
    }
}
void Side_to_play(){
    if(Turn=="b"){
        Turn = "w";
    }
    else{
        Turn = "b";
    }
}
void Move_counter(){
    if(Turn=="b"){
        Counter++;
    }
}

string To_fen(){
    string fen = "";
    for(int i=0;i<7;i++){
        string file = files_vector.at(i);
        int k = 0;
        for(int j=0;j<7;j++){
            if(file[j]=='0'){
                k++;
            }
            else if(isalpha(file[j])){
                if(k!=0){
                    fen+=to_string(k);
                    k=0;
                }
                fen += file[j];
            }
            if(j+1>6){
                if(k!=0){
                    fen+=to_string(k);
                    k=0;
                }
            }
            if(j==6 && i!=6){
                fen+="/";
            }
        }
    }
    return fen;
}

void From_To(int x1,int y1,int x2,int y2){

    char from = files_vector.at(y1)[x1];
    //super pawn stuff for black
    if(Turn == "b"){
        if(y1 == 5 && files_vector.at(y1)[x1]=='p' && y2 == 6){
            from = 's';
        }
    }
    //super pawn stuff for white
    if(Turn == "w"){
        if(y1 == 1 && files_vector.at(y1)[x1]=='P' && y2 == 0){
            from = 'S';
        }
    }
    files_vector.at(y2)[x2] = from;
    files_vector.at(y1)[x1] = '0';
}

string State(){
    string state = "Continue";
    if(Turn == "w"){
        bool black = true;
        for(int i=0;i<3;i++){
            string file = files_vector.at(i);
            int c = file.find('l');
            if(c!=-1){
                return state;
            }
            else{
                black = false;
            }
        }
        if(!black){
            return  "White wins";
        }
    }
    else if(Turn == "b"){
        bool white = true;
        for(int i=4;i<7;i++){
            string file = files_vector.at(i);
            int c = file.find('L');
            if(c!=-1){
                return state;
            }
            else{
                white = false;
            }

        }
        if(!white){
            return  "Black wins";
        }
    }
    return state;
}
void Move(string move){
    vector<int> P_in_river_before; //for coordinate of piece in river
    vector<char> P; //piece in the river
    //from
    int x_from = int(move[0]) -97;
    int y_from = move[1]-'0';
    y_from = 7-y_from ;
    //to
    int x_to = int(move[2]) -97;
    int y_to = move[3]-'0';
    y_to = 7- y_to;
    //pieces in the river in coordinate
    Piece_in_River_before(P_in_river_before);
    //store the piece
    for(int i=0;i<P_in_river_before.size();i++){
        P.push_back(files_vector.at(3)[P_in_river_before.at(i)]);
    }
    //move the piece from_to :/
    From_To(x_from,y_from,x_to,y_to);
    /*remove piece in river
        2 cases: 
        1.moved
        2.haven't moved
    good luck :/ */
    for(int i=0;i<P_in_river_before.size();i++){
        string file = files_vector.at(3);
        //still here,haven't moved (x,y) 1 case 
        if(P.at(i) == file[P_in_river_before.at(i)]){
            files_vector.at(3)[P_in_river_before.at(i)] = '0';
        }
        //moved but same still on the river(3,y) 2nd case
        else if(y_to - y_from == 0 ){
            files_vector.at(3)[x_to] = '0';
        }
    }
    //other stuff
    Move_counter();
    string state = State();
    Side_to_play();
    fen =  To_fen();
    cout<<fen<<" "<<Turn<<" "<<Counter<<endl;
    cout<<state;
    
}

int Bvalue(string fen){
    int score = 0;
    for(int i=0;i<fen.size();i++){
        if(fen[i] == 'p'){
            score += 100;
        }
        else if(fen[i] == 'z'){
            score += 300;
        }
        else if(fen[i] == 's'){
            score += 350;
        }
        else if(fen[i] == 'g'){
            score += 400;
        }
    }
    return score;
}

int Wvalue(string fen){
    int score = 0;
    for(int i=0;i<fen.size();i++){
        if(fen[i] == 'P'){
            score += 100;
        }
        else if(fen[i] == 'Z'){
            score += 300;
        }
        else if(fen[i] == 'S'){
            score += 350;
        }
        else if(fen[i] == 'G'){
            score += 400;
        }
    }
    return score;
}

int Point1(string fen){
    int blackking = fen.find('l');
    int whiteking = fen.find('L');

    if(blackking !=-1 && whiteking!=-1){
        for(int i=0;i<fen.length();i++){
            if(fen[i] =='z' || fen[i] =='s' ||
             fen[i] =='g'||fen[i] =='p' ||
              fen[i] =='Z' || fen[i] =='S' ||
               fen[i] =='G'|| fen[i] =='P'){
                return 1; 
            }
        }
        return 0; //no available
    }
    return -1;//one of the lion is not there
}


int Evaluate(string fen,string turn){

    int score = 0;
    int points = Point1(fen);
    //point 1 //draw
    if(points == 0){
        return score;
    }
    //one the lion  is not there
    else if(points == -1){
        int blackking = fen.find('l');
        int whiteking = fen.find('L');
        // point 2
        if(blackking == -1){
            score =  10000;
            return score;
        }
        // point 3
        else if(whiteking == -1){
            score =  -10000;
            return score;
        }
    }
        //point 4
        else if(points == 1 ){
        int wscore = Wvalue(fen);
        int bscore = Bvalue(fen);
        score = wscore - bscore;
        return score;
        }
}

vector<string> generateMoves(vector<string>files,string turn){
    vector<string> output;
    for(int j=0;j<7;j++){
        if(turn == "b"){
            // j represents a row
            string file = files.at(j);
            for (int i=0;i<file.size();i++){
                vector<string> fetch;
                if(file[i] == 'l'){
                   King(i,6-j);
                   fetch = Print(i,6-j);
                }if(file[i] == 'g'){
                    Geraffe(i,6-j);
                    fetch = Print(i,6-j);
                }if(file[i] == 'z'){
                    Zebra(i,6-j);
                    fetch = Print(i,6-j);
                }if(file[i] == 's'){
                    Superpawn(i,6-j);
                    fetch = Print(i,6-j);
                }if(file[i] == 'p'){
                    Pawn(i,6-j);
                    fetch = Print(i,6-j);
                }
                for(string str:fetch){
                    output.push_back(str);
                }
            }
        }else if (turn == "w"){
            string file = files.at(j);
            //this loops only once,got it
            for (int i=0;i<file.size();i++){
                vector<string> fetch;
                if(file[i] == 'L'){
                   King(i,6-j);
                   fetch = Print(i,6-j); 
                }if(file[i] == 'G'){
                    Geraffe(i,6-j);
                    fetch = Print(i,6-j);
                }if(file[i] == 'Z'){
                    Zebra(i,6-j);
                    fetch = Print(i,6-j);  
                }if(file[i] == 'S'){
                    Superpawn(i,6-j);
                    fetch = Print(i,6-j); 
                }if(file[i] == 'P'){
                    Pawn(i,6-j);
                    fetch = Print(i,6-j);
                }        
                for(string str:fetch){
                    output.push_back(str);
                }
            }
        }
    }

    sort(output.begin(),output.end());
    return output;
}
int Mobility(vector<string>files,string turn){
    string realturn = turn;
    turn = "w";
    vector<string> moves = generateMoves(files,turn);
    int wscore = moves.size();
    // cout<<wscore<<endl;
    turn = "b";
    moves = generateMoves(files,turn);
    int bscore = moves.size();
    // cout<<bscore<<endl;
    turn = realturn;

    int finalscore = wscore - bscore;
    return finalscore;
}

int WhiteAttack(vector<string>files,string turn){
    int attackscore = 0;
    vector<string> moves = generateMoves(files,turn);
    for(int i=0;i<moves.size();i++){
        string curr_move = moves.at(i); //current move
        
        int x_to = int(curr_move[2]) -97;   //move to be x
        int y_to = curr_move[3]-'0';
        y_to = 7- y_to;//move to be y

        if(islower(files.at(y_to)[x_to])){
            attackscore = attackscore+1;
            if(files.at(y_to)[x_to] == 'l' ){
                attackscore = attackscore+10;
            }        
        }
    }
    return attackscore;
}

int BlackAttack(vector<string>files,string turn){
    int attackscore = 0;
    vector<string> moves = generateMoves(files,turn);
    for(int i=0;i<moves.size();i++){
        string curr_move = moves.at(i); //current move
        
        int x_to = int(curr_move[2]) -97;   //move to be x
        int y_to = curr_move[3]-'0';
        y_to = 7- y_to;//move to be y

        if(isupper(files.at(y_to)[x_to])){
            attackscore = attackscore+1;
            if(files.at(y_to)[x_to] == 'L' ){
                attackscore = attackscore+10;
            }              
        }
    }
    return attackscore;
}

int Attack(vector<string>files,string turn){
    int attackscore = 0;
    if(turn == "w"){
        int whitescore = WhiteAttack(files,turn);
        turn="b"; //assume its black to play
        int blackscore = BlackAttack(files,turn);
        attackscore = whitescore - blackscore;
        turn ="w"; //return the turn to the owner :/
    }
    else if(turn == "b"){
        int blackscore = BlackAttack(files,turn);
        turn="w"; //assume its black to white
        int whitescore = WhiteAttack(files,turn);
        attackscore = whitescore - blackscore;
        turn="b"; //return the turn to the owner :/
    }
    return attackscore;
}

int ScoreEvaluation(string fen,string turn){
    if(Evaluate(fen,turn) == 0){
        return 0;
    }
    else{
        int finalscore = Evaluate(fen,turn);
        if(turn == "b"){
            finalscore = finalscore*-1;
            // cout<<finalscore;
            return finalscore;
        }
        return finalscore;
    }
}


void Score(vector<string>files,string turn,string fen){

    if(Evaluate(fen,turn) == 0){
        if(Point1(fen) == 0){
            cout<< 0;
            return;
        }
    }
    // else{
        int finalscore = 0;
        int material = Evaluate(fen,turn);
        if(Point1(fen) == -1){
            finalscore =  Evaluate(fen,turn);
        }
        else{
            int mobility = Mobility(files,turn);
            int attack = Attack(files,turn);
            finalscore = material + mobility + attack;
        }
        // cout<<material<<"..."<<mobility<<"..."<<attack<<endl;
        if(turn == "b"){
            finalscore = finalscore*-1;
            cout<<finalscore;
            // MyFile<<finalscore<<endl;
            return;
        }
        cout<<finalscore;
        // MyFile<<finalscore<<endl;
    // }
}

void CallScore(string fen){
    Score(files_vector,Turn,fen);
}

int main(){
    string position = "";   
    string turn = "";   
    string m_number = "";   
    string split = "";   
    string fen = "";   
    string move = "";

    int index = 0;  

    int N;
    cin>>N;
    cin.ignore();
    for(int i=0;i<N;i++){
        // if(i%2!=0){
        //     string move;
        //     getline(cin,move);
        //     moves_vector.push_back(move);
        // }
        // else{
            string fen;
            getline(cin,fen);
            fen_vector.push_back(fen);
        // }
    }

    for(int i=0;i<N;i++){

        fen  = fen_vector.at(i); 
        // move = moves_vector.at(i);
        for(auto x:fen){
            if(x == ' '){
    
                if(index == 0){
                
                    position = split;
                    index++;
                    split = "";
                }
                else if(index == 1){
                
                    turn = split;
                    index++;
                    split = "";
                }
            }else{
                split += x;
                m_number = split;   
            }
        }

        
        split = ""; 
        index = 0 ;
        State(position);
        Turn = turn;
        Counter = stoi(m_number);     
        
        split = "";
        index = 0 ;
        // Game();
        // Move(move);
        CallScore(fen);
        

        clearArray();
        split = "";   
        
        if(i<N-1){
            cout<<endl;
        }
    }
        
    return 0;
}

