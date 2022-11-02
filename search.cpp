#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

ofstream MyFile("filename.txt");
class Point{
    private:
        Point *Parent;  //for later cool stuff
    public:
        vector<string>Files;    //files vector
        vector<Point*> points;  //coordinate(x,y)
        int x;
        int y;
        string turn;    //white or black to play
        Point(int x_point,int y_point,Point *parent,vector<string>files,string turn){
            //maybe inheritence was cooler but yeah for next time :/,lot of arg for my constr now
            this->x = x_point;
            this->y = y_point;
            this->Parent = parent;
            this->Files = files;
            this->turn = turn;
        }

        //help to change number to col-row(c7d6)
        string Changer(int row,int col){

            char row_ = (char)('a'+(row));
            string square = "";
            square+=row_;
            square+=to_string(col+1);
            return square;
        }

        vector<string> Print(){
            //for final output
            vector<string>finalle;

            for(int i=0; i<points.size() ; i++){
                Point *c_point = points.at(i);
                //possible square
                string str = Changer(c_point->x,c_point->y);
                string square = Changer(x,y);
                //complete move
                square+=str;
                finalle.push_back(square);
            }

            //printing it nicely
            sort(finalle.begin(),finalle.end());
            return finalle;
        }

        //evalute if move is valid
        bool Valid(int curr_x_move,int curr_y_move){
            bool valid = false;
            if(curr_x_move<5 && curr_x_move>1){
                if((curr_y_move<=2 && curr_y_move>=0) || (curr_y_move<=6 && curr_y_move>=4) ){
                    if(turn == "b"){
                        if(isupper(Files.at(6-curr_y_move)[curr_x_move]) || Files.at(6-curr_y_move)[curr_x_move] =='0'){   
                            valid = true; 
                        }
                    }
                    else if(turn == "w"){
                        if(islower(Files.at(6-curr_y_move)[curr_x_move]) || Files.at(6-curr_y_move)[curr_x_move] =='0'){
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
                    if(turn == "b"){
                        if(isupper(Files.at(6-curr_y_move)[curr_x_move]) || Files.at(6-curr_y_move)[curr_x_move] =='0'){    
                            valid = true;
                        }
                    }
                    else if(turn == "w"){
                        if(islower(Files.at(6-curr_y_move)[curr_x_move]) || Files.at(6-curr_y_move)[curr_x_move] =='0'){
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
                    if(turn == "b"){
                        if(Files.at(6-curr_y_move)[curr_x_move] =='0'){    
                            valid = true;
                        }
                    }
                    else if(turn == "w"){
                        if(Files.at(6-curr_y_move)[curr_x_move] =='0'){
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
                    if(turn == "b"){
                        if(isupper(Files.at(6-curr_y_move)[curr_x_move]) || Files.at(6-curr_y_move)[curr_x_move] =='0'){    
                            valid = true;
                        }
                    }
                    else if(turn == "w"){
                        if(islower(Files.at(6-curr_y_move)[curr_x_move]) || Files.at(6-curr_y_move)[curr_x_move] =='0'){
                            valid = true;
                        }
                    }
                }
            }
            return valid;
        }

        bool ValidPr(int curr_x_move,int curr_y_move){
            bool valid = false;
            if(curr_x_move<=6 && curr_x_move>=0){
                if(curr_y_move <= 6 && curr_y_move >= 0 ){
                    if(turn == "b"){
                        if(Files.at(6-curr_y_move)[curr_x_move] =='0'){   
                            valid = true;
                        }
                    }
                    else if(turn == "w"){
                        if(Files.at(6-curr_y_move)[curr_x_move] =='0'){
                            valid = true;  
                        }
                    }
                }
            }
            return valid;
        
        }
        void SpecialMove(){
            if(turn == "b"){
                for(int i=0;i<7;i++){

                    //who's turn?find oppenent's king
                    string file = Files.at(i);
                    int c = file.find('L');
                    if(c!=-1){

                        //its x and y value
                        int k_opp_x = c;
                        int k_opp_y = i;

                        // cout<<"WKing"<<Files.at(k_opp_y)[k_opp_x]<<endl;
                        // cout<<"x:"<<k_opp_x<< "y:"<<k_opp_y<<endl;

                        // cout<<"BKing"<<Files.at(6-y)[x]<<endl;
                        // cout<<"x:"<<x<< "y:"<<6-y<<endl;

                        //check if they on same rank
                        if(x == k_opp_x){
                            int p = 0;
                            for(int j = (6-y)+1;j<k_opp_y;j++){
                                if(Files.at(j)[x] != '0'){
                                    p++;
                                }
                                // cout<<Files.at(j)[x]<<endl;
                            }
                            // cout<<p<<endl;
                            if(p==0){
                                //we can capture it, NOICE
                                Point *special = new Point(k_opp_x,6-k_opp_y,this,Files,turn);
                                points.push_back(special);                
                            }
                        }

                        // Diagonal capture right //black takes
                        else if((x==4 && k_opp_x==2) && (y==4 && (6-k_opp_y)==2) && (Files.at(3)[3] == '0')){
                            Point *r_diagonal = new Point(k_opp_x,6-k_opp_y,this,Files,turn);
                            points.push_back(r_diagonal);
                        }
                        //Diagonal capture left,//black takes 
                        else if((x==2 && k_opp_x==4) && (y==4 &&(6-k_opp_y)==2) && (Files.at(3)[3] == '0')){
                            Point *r_diagonal = new Point(k_opp_x,6-k_opp_y,this,Files,turn);
                            points.push_back(r_diagonal);
                        }
                    }
                }
            }

            //same thing
            else if(turn=="w"){
                for(int i=0;i<7;i++){
                    string file = Files.at(i);
                    //find black king
                    int c = file.find('l');
                    if(c!=-1){
                        int k_opp_x = c;
                        int k_opp_y = i;


                        // cout<<"BKing"<<Files.at(k_opp_y)[k_opp_x]<<endl;
                        // cout<<"x:"<<k_opp_x<< "y:"<<k_opp_y<<endl;

                        // cout<<"WKing"<<Files.at(6-y)[x]<<endl;
                        // cout<<"x:"<<x<< "y:"<<6-y<<endl;

                        //same line
                            //x and y are fine(up to left) but x-opp works in revers(down to left)
                            //fied it
                        if(x == k_opp_x){
                            int p = 0;
                            for(int j = k_opp_y+1;j <6-y;j++){
                                if(Files.at(j)[x] != '0'){
                                    p++;
                                }
                                // cout<<Files.at(j)[x]<<endl;
                            }
                            // cout<<p<<endl;
                            if(p==0){
                                Point *special = new Point(k_opp_x,6-k_opp_y,this,Files,turn);
                                points.push_back(special);                
                            }
                        }

                        //not sure
                        else if((x==2 &&k_opp_x==4) && (y==2 && 6-k_opp_y==4) && (Files.at(3)[3] == '0')){
                            Point *r_diagonal = new Point(k_opp_x,6-k_opp_y,this,Files,turn);
                            points.push_back(r_diagonal);
                        }

                        //Diagonal capture left,//white takes
                        else if((x==4 && k_opp_x==2) && (y==2 && 6-k_opp_y==4) && (Files.at(3)[3] == '0')){
                            Point *r_diagonal = new Point(k_opp_x,6-k_opp_y,this,Files,turn);
                            points.push_back(r_diagonal);
                        }
                    }
                }
            }
        }
        //King move
        void right(){
            int curr_x = x+1;
            if(Valid(curr_x,y)){
                Point *right = new Point(curr_x,this->y,this,Files,turn);
                points.push_back(right);
            }
        };
        void Left(){
            int curr_x = x-1;
            if(Valid(curr_x,y)){
                Point *left = new Point(curr_x,this->y,this,Files,turn);
                points.push_back(left);
            }
        };
        void Up(){
            int curr_y = y-1;
            if(Valid(x,curr_y)){
                Point *up = new Point(this->x,curr_y,this,Files,turn);
                points.push_back(up);
            }
        };
        void down(){
            int curr_y = y+1;
            if(Valid(x,curr_y)){
                Point *down = new Point(this->x,curr_y,this,Files,turn);
                points.push_back(down);
            }
        };
        void rightup(){
            int curr_y = y-1;
            int curr_x = x+1;
            if(Valid(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }
        };
        void rightdown(){
            int curr_y = y+1;
            int curr_x = x+1;
            if(Valid(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }
        };
        void leftup(){
            int curr_y = y-1;
            int curr_x = x-1;
            if(Valid(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }
        };
        void lefttdown(){
            int curr_y = y+1;
            int curr_x = x-1;
            if(Valid(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }
        };
        //zebra
        void Zebra(){
            int curr_y = y+2;
            int curr_x = x+1;
            if(ValidZ(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }

            curr_y = y-2;
            curr_x = x+1;
            if(ValidZ(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }

            curr_y = y+2;
            curr_x = x-1;
            if(ValidZ(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }
            curr_y = y-2;
            curr_x = x-1;
            if(ValidZ(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }

            curr_y = y+1;
            curr_x = x+2;
            if(ValidZ(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }

            curr_y = y+1;
            curr_x = x-2;
            if(ValidZ(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }

            curr_y = y-1;
            curr_x = x-2;
            if(ValidZ(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }

            curr_y = y-1;
            curr_x = x+2;
            if(ValidZ(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }
        }
        //Geraffe
        void onestep(){

            int curr_y = y+1;
            if(ValidG(x,curr_y)){
                Point *down = new Point(x,curr_y,this,Files,turn);
                points.push_back(down);
            }
            int curr_x = x+1;
            if(ValidG(curr_x,y)){
                Point *down = new Point(curr_x,y,this,Files,turn);
                points.push_back(down);
            }
            if(ValidG(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }
            
            curr_y = y-1;
            if(ValidG(x,curr_y)){
                Point *down = new Point(x,curr_y,this,Files,turn);
                points.push_back(down);
            }
            curr_x = x-1;
            if(ValidG(curr_x,y)){
                Point *down = new Point(curr_x,y,this,Files,turn);
                points.push_back(down);
            }
            if(ValidG(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }

            curr_y = y+1;
            curr_x = x-1;
            if(ValidG(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }

            curr_y = y-1;
            curr_x = x+1;
            if(ValidG(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }
        }
        void Twostep(){
            int curr_y =y+2;
            if(ValidZ(x,curr_y)){
                Point *down = new Point(x,curr_y,this,Files,turn);
                points.push_back(down);
            }

            int curr_x = x+2;
            if(ValidZ(curr_x,y)){
                Point *down = new Point(curr_x,y,this,Files,turn);
                points.push_back(down);
            }
            if(ValidZ(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }

            curr_x = x-2;
            if(ValidZ(curr_x,y)){
                Point *down = new Point(curr_x,y,this,Files,turn);
                points.push_back(down);
            }
            curr_y = y-2;
            if(ValidZ(x,curr_y)){
                Point *down = new Point(x,curr_y,this,Files,turn);
                points.push_back(down);
            }
            if(ValidZ(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }

            curr_x = x+2;
            curr_y = y-2;
            if(ValidZ(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }
            curr_x = x-2;
            curr_y = y+2;
            if(ValidZ(curr_x,curr_y)){
                Point *down = new Point(curr_x,curr_y,this,Files,turn);
                points.push_back(down);
            }
        }
        //SuperPawn move before river
        void SBriver(){
            if(turn == "w"){
                //go up
                int curr_y = y+1;
                //check validity
                if(ValidP(x,curr_y)){
                    Point *down = new Point(x,curr_y,this,Files,turn);
                    points.push_back(down);
                }
                //go up right
                int curr_x = x+1;
                //check validity
                if(ValidP(curr_x,curr_y)){
                    Point *down = new Point(curr_x,curr_y,this,Files,turn);
                    points.push_back(down);
                }
                //go right only
                if(ValidP(curr_x,y)){
                    Point *down = new Point(curr_x,y,this,Files,turn);
                    points.push_back(down);
                }
                //go up left
                curr_x = x-1;
                //check validity
                if(ValidP(curr_x,curr_y)){
                    Point *down = new Point(curr_x,curr_y,this,Files,turn);
                    points.push_back(down);
                }
                //go left only
                if(ValidP(curr_x,y)){
                    Point *down = new Point(curr_x,y,this,Files,turn);
                    points.push_back(down);
                }
            }

            else if(turn == "b"){
                //go down
                int curr_y = y-1;
                if(ValidP(x,curr_y)){
                    Point *down = new Point(x,curr_y,this,Files,turn);
                    points.push_back(down);
                }
                //go right down
                int curr_x = x+1;
                if(ValidP(curr_x,curr_y)){
                    Point *down = new Point(curr_x,curr_y,this,Files,turn);
                    points.push_back(down);
                }
                //just down
                if(ValidP(curr_x,y)){
                    Point *down = new Point(curr_x,y,this,Files,turn);
                    points.push_back(down);
                }
                //go down left down
                curr_x = x-1;
                //check validity
                if(ValidP(curr_x,curr_y)){
                    Point *down = new Point(curr_x,curr_y,this,Files,turn);
                    points.push_back(down);
                }
                //just left
                if(ValidP(curr_x,y)){
                    Point *down = new Point(curr_x,y,this,Files,turn);
                    points.push_back(down);
                }
            }
        }
        //SuperPawn move before river
        void SAriver(){
            if(turn == "w"){
                // if(y>3){
                    //retreate one square straight
                    int curr_y = y-1;
                    int possible_y = 0;
                    if(ValidPr(x,curr_y)){
                        possible_y++;
                        Point *down = new Point(x,curr_y,this,Files,turn);
                        points.push_back(down);
                    }
                    //retreate one square diagonal left
                    int curr_x = x-1;
                    int possible_x_l = 0;
                    if(ValidPr(curr_x,curr_y)){
                        possible_x_l++;
                        Point *down = new Point(curr_x,curr_y,this,Files,turn);
                        points.push_back(down);
                    }
                    //retreate one square diagonal rigt
                    curr_x = x+1;
                    int possible_x_r = 0;
                    if(ValidPr(curr_x,curr_y)){
                        possible_x_r++;
                        Point *down = new Point(curr_x,curr_y,this,Files,turn);
                        points.push_back(down);
                    }
                    //retreate two square back
                    curr_y = y-2;
                    if(ValidPr(x,curr_y) && possible_y == 1){
                        Point *down = new Point(x,curr_y,this,Files,turn);
                        points.push_back(down);
                    }
                    //retreate two square diagonal left
                    curr_x = x-2;
                    if(ValidPr(curr_x,curr_y) && possible_x_l == 1){
                        Point *down = new Point(curr_x,curr_y,this,Files,turn);
                        points.push_back(down);
                    }
                    //retreate two square diagonal rigth
                    curr_x = x+2;
                    if(ValidPr(curr_x,curr_y) && possible_x_r == 1){
                        Point *down = new Point(curr_x,curr_y,this,Files,turn);
                        points.push_back(down);
                    }
                // }
            }

            else if(turn == "b"){
                // if(y<3){
                    int curr_y = y+1;
                    int possible_y = 0;
                    if(ValidPr(x,curr_y)){
                        possible_y++;
                        Point *down = new Point(x,curr_y,this,Files,turn);
                        points.push_back(down);
                    }
                    //retreate one square diagonal left
                    int curr_x = x-1;
                    int possible_x_l = 0;
                    if(ValidPr(curr_x,curr_y)){
                        possible_x_l++;
                        Point *down = new Point(curr_x,curr_y,this,Files,turn);
                        points.push_back(down);
                    }
                    //retreate one square diagonal rigt
                    curr_x = x+1;
                    int possible_x_r = 0;
                    if(ValidPr(curr_x,curr_y)){
                        possible_x_r++;
                        Point *down = new Point(curr_x,curr_y,this,Files,turn);
                        points.push_back(down);
                    }
                    //retreate two square back
                    curr_y = y+2;
                    if(ValidPr(x,curr_y) && possible_y == 1){
                        Point *down = new Point(x,curr_y,this,Files,turn);
                        points.push_back(down);
                    }
                    //retreate two square diagonal left
                    curr_x = x-2;
                    if(ValidPr(curr_x,curr_y) && possible_x_l == 1){
                        Point *down = new Point(curr_x,curr_y,this,Files,turn);
                        points.push_back(down);
                    }
                    //retreate two square diagonal rigth
                    curr_x = x+2;
                    if(ValidPr(curr_x,curr_y) && possible_x_r == 1){
                        Point *down = new Point(curr_x,curr_y,this,Files,turn);
                        points.push_back(down);
                    }
                // }
            }
        }
        //pawn move before river
        void Briver(){
            if(turn == "w"){
                int curr_y = y+1;
                //check validity
                if(ValidP(x,curr_y)){
                    Point *down = new Point(x,curr_y,this,Files,turn);
                    points.push_back(down);
                }
                int curr_x = x+1;
                //check validity
                if(ValidP(curr_x,curr_y)){
                    Point *down = new Point(curr_x,curr_y,this,Files,turn);
                    points.push_back(down);
                }
                curr_x = x-1;
                //check validity
                if(ValidP(curr_x,curr_y)){
                    Point *down = new Point(curr_x,curr_y,this,Files,turn);
                    points.push_back(down);
                }
            }

            else if(turn == "b"){
                int curr_y = y-1;
                //check validity
                if(ValidP(x,curr_y)){
                    Point *down = new Point(x,curr_y,this,Files,turn);
                    points.push_back(down);
                }
                int curr_x = x+1;
                //check validity
                if(ValidP(curr_x,curr_y)){
                    Point *down = new Point(curr_x,curr_y,this,Files,turn);
                    points.push_back(down);
                }
                curr_x = x-1;
                //check validity
                if(ValidP(curr_x,curr_y)){
                    Point *down = new Point(curr_x,curr_y,this,Files,turn);
                    points.push_back(down);
                }
            }
        }
        //pawn move after river
        void Ariver(){
            if(turn == "w"){
                if(y>3){
                    int curr_y = y-1;
                    int possible = 0;
                    if(ValidPr(x,curr_y)){
                        possible++;
                        Point *down = new Point(x,curr_y,this,Files,turn);
                        points.push_back(down);
                    }

                    curr_y = y-2;
                    if(ValidPr(x,curr_y) && possible == 1){
                        Point *down = new Point(x,curr_y,this,Files,turn);
                        points.push_back(down);
                    }
                }
            }

            else if(turn == "b"){
                if(y<3){
                    int curr_y = y+1;
                    int possible = 0;
                    if(ValidPr(x,curr_y)){
                        possible++;
                        Point *down = new Point(x,curr_y,this,Files,turn);
                        points.push_back(down);
                    }

                    curr_y = y+2;
                    if(ValidPr(x,curr_y) && possible == 1){
                        Point *down = new Point(x,curr_y,this,Files,turn);
                        points.push_back(down);
                    }
                }
            }
        }

        void PMove(){
            Briver();
            Ariver();
        }
        void SPMove(){
            SBriver();
            SAriver();
        }
        void GMove(){
            onestep();
            Twostep();
        }
        void ZMove(){
            Zebra();
        }
        void KMove(){
            right();
            Left();
            Up();
            down();
            lefttdown();
            leftup();
            rightdown();
            rightup();
            SpecialMove();
        }

        void AllMoves(){
            PMove();
            SPMove();
            GMove();
            ZMove();
            KMove();
        }
};
class Congo{
    private:
       vector<string>Parent_File;
       string Parent_FEN;
    public:

        string FEN;         //posiotions
        string Turn = "";   //represent a players turn
        int M_number;   //represent a number of moves
        bool Gamestate;
        string Move = "";   //move to be played
        vector<string>File; //represent a board


        Congo(string fen,string turn,int m_number,bool game,vector<string>file ,string move){
            this->FEN = fen;
            this->Turn = turn;
            this->M_number = m_number;
            this->File = file;
            this->Move = move;
            this->Gamestate = game;
            this->Parent_File = file;
            this->Parent_FEN = fen;
        }

        void PrintMove(vector<string>output){
            for(int i=0;i<output.size();i++){
                cout<<output.at(i);
                //some nice printing
                if(i<output.size()-1){
                    cout<<" ";
                }
            }
            cout<<"/..........//"<<endl;
        }
        void Play(){
            // PrintFile(File);
            int v = MinMax(this->FEN,this->File,this->Turn,this->M_number,2);
            cout<<v;
            MyFile<<v<<endl;;
            // cout<<endl;
            // PrintFile(File);
            // cout<<endl;
            // PrintFile();
        }
        
        int MinMax(string curr_state,vector<string>files,string turn,int c,int depth){
            // MyFile<<curr_state<<":"<<ScoreEvaluation(curr_state)<<endl;
            if(isGameOver(curr_state) || depth <= 0){
                return ScoreEvaluation(curr_state,turn);
            }
            int value = -10000000;
            vector<string> moves = generateMoves(files,turn);
            // PrintMove(moves);
            for(int i = 0;i < moves.size(); i++){
                string move = moves.at(i); 
                // MyFile<<curr_state<<".."<<Evaluate(curr_state,turn)<<".."<<move<<".."<<value<<endl;
                vector<string> board = Execute(files,move,curr_state,turn);
                string new_turn = Side_to_play(turn);
                string next_state = To_fen(board,c,new_turn);
                // MyFile<<".."<<next_state<<".."<<Evaluate(next_state,turn)<<endl;
                // MyFile<<new_turn<<endl;
                int eval = -MinMax(next_state,board,new_turn,c,depth-1);
                value = max(value,eval);
                // MyFile <<eval<<"..."<<value<<"...:"<<ScoreEvaluation(next_state,turn)<<endl;
            }
            return value;
        }
        //Print Board
        void PrintFile(vector<string>file){
            for(int i=0;i<7;i++){
                for(int j=0;j<7;j++){
                    cout<<file.at(i)[j]<<" ";
                }
                cout<<endl;
            }
        }

        bool isGameOver(string fen){
            // cout<<fen<<endl;
            int blackking = fen.find('l');
            int whiteking = fen.find('L');

            if(blackking == -1 || whiteking == -1){
                return true;
            }
            return false;
        }

        // void game(){
        //     if(isGameOver(FEN)){
        //         cout<<"Game over";
        //     }
        //     cout<<"We still playing";
        // }

        int Bvalue(string fen){
            int score = 0;
            for(int i=0;i<fen.size();i++){
                if(fen[i] == 'p'){
                    score += 100;
                }else if(fen[i] == 'z'){
                    score += 300;
                }else if(fen[i] == 's'){
                    score += 350;
                }else if(fen[i] == 'g'){
                    score += 400;
                }
            }
            return score;
        }

        int Wvalue(string fen){
            int score = 0;
            for(int i=0;i<FEN.size();i++){
                if(fen[i] == 'P'){
                    score += 100;
                }else if(fen[i] == 'Z'){
                    score += 300;
                }else if(fen[i] == 'S'){
                    score += 350;
                }else if(fen[i] == 'G'){
                    score += 400;
                }
            }
            return score;
        }

        int Point1(string fen){
            
            int blackking = fen.find('l');
            int whiteking = fen.find('L');

            if(blackking !=-1 && whiteking!=-1){
                //lions are available
                for(int i=0;i<fen.length();i++){
                    if(fen[i] =='z' || fen[i] =='s' || fen[i] =='g'|| fen[i] =='p' 
                    || fen[i] =='Z' || fen[i] =='S' || fen[i] =='G'|| fen[i] =='P'){
                        return 1; //some pieces are available
                    }
                }
                return 0; //no available
            }
            return -1;//one of the lion is not there
        }

        int Evaluate(string fen,string turn){

            int score = 0;
            int points = Point1(fen);
            //point 1
            if(points == 0){
                return score;
            }
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
            int wscore = Wvalue(fen);
            int bscore = Bvalue(fen);
            score = wscore - bscore;
            return score;
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

        void Score(string turn){
            string fen  = this->FEN;
            if(Evaluate(fen,turn) == 0){
                cout<< 0;
            }
            else{
                int finalscore = Evaluate(fen,turn);
                if(turn == "b"){
                    finalscore = finalscore*-1;
                    cout<<finalscore;
                    return;
                }
                cout<<finalscore;
            }
        }

        vector<string> Execute(vector<string>curr_file,string move,string state,string turn){
            vector<int> P_in_river_before;
            vector<char> P;
            //state to work with
            // vector<string>curr_file = this->File;
            int counter = this->M_number;
            // string player = this->turn;
            //from
            int x_from = int(move[0]) -97;
            int y_from = move[1]-'0';
            y_from = 7-y_from ;
            //to
            int x_to = int(move[2]) -97;
            int y_to = move[3]-'0';
            y_to = 7- y_to;
            //pieces in the river in coordinate
            Piece_in_River_before(P_in_river_before,curr_file,turn);
            //store the piece
            for(int i=0;i<P_in_river_before.size();i++){
                P.push_back(curr_file.at(3)[P_in_river_before.at(i)]);
            }
            //move the piece from_to :/
            From_To(x_from,y_from,x_to,y_to,curr_file,turn);
            /*remove piece in river
             2 cases: 
                1.moved
                2.haven't moved
             good luck :/ 
            */
            for(int i=0;i<P_in_river_before.size();i++){
                string file = File.at(3);
                //still here,haven't moved (x,y) 1 case 
                if(P.at(i) == file[P_in_river_before.at(i)]){
                    curr_file.at(3)[P_in_river_before.at(i)] = '0';
                }
                //moved but same still on the river(3,y) 2nd case
                else if(y_to - y_from == 0 ){
                    curr_file.at(3)[x_to] = '0';
                }
            }
            //other stuff
            Move_counter(counter,turn);
            // string state = State();
            turn = Side_to_play(turn);
            state =  To_fen(curr_file,counter,turn);
            return curr_file;
            // PrintFile();
        }

        string State(){
            string state = "Continue";
            if(Turn == "w"){
                bool black = true;
                for(int i=0;i<3;i++){
                    string file = File.at(i);
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
                    string file = File.at(i);
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

        void Piece_in_River_before(vector<int>& P_in_river,vector<string>&curr_file,string turn){
            //store the coordiante
            for(int i=0;i<7;i++){
                if(turn=="w"){
                    if(isupper(curr_file.at(3)[i])){
                        P_in_river.push_back(i);
                    }
                }
                else if(turn == "b"){
                    if(islower(curr_file.at(3)[i])){
                        P_in_river.push_back(i);
                    }
                }
            }
        }

        string Side_to_play(string player){
            if(player=="b"){
                player = "w";
            }
            else{
                player = "b";
            }
            return player;
        }

        void Move_counter(int &counter,string player){
            if(player == "b"){
                counter++;
            }
        }

       void From_To(int x1,int y1,int x2,int y2,vector<string>&curr_file,string turn){

            char from = curr_file.at(y1)[x1];
            //super pawn stuff for black
            if(turn == "b"){
                if(y1 == 5 && curr_file.at(y1)[x1]=='p' && y2 == 6){
                    from = 's';
                }
            }
            //super pawn stuff for white
            if(turn == "w"){
                if(y1 == 1 && curr_file.at(y1)[x1]=='P' && y2 == 0){
                    from = 'S';
                }
            }
            curr_file.at(y2)[x2] = from;
            curr_file.at(y1)[x1] = '0';
        }

        string To_fen(vector<string>&curr_file,int counter,string player){
            string fen = "";
            for(int i=0;i<7;i++){
                string file = curr_file.at(i);
                int k = 0;
                for(int j=0;j<7;j++){
                    if(file[j]=='0'){
                        k++;
                    }else if(isalpha(file[j])){
                        if(k!=0){
                            fen+=to_string(k);
                            k=0;
                        }
                        fen += file[j];
                    }if(j+1>6){
                        if(k!=0){
                            fen+=to_string(k);
                            k=0;
                        }
                    }if(j==6 && i!=6){
                        fen+="/";
                    }
                }
            }
            fen+=" ";
            fen+=player;
            fen+=" ";
            fen+= to_string(counter);
            return fen;
        }
        // Possible moves
        vector<string> generateMoves(vector<string>files,string turn){
            vector<string> output;
            for(int j=0;j<7;j++){
                if(turn == "b"){
                    // j represents a row
                    string file = files.at(j);
                    for (int i=0;i<file.size();i++){
                        vector<string> fetch;
                        Point *p;
                        if(file[i] == 'l'){
                            p = new Point(i,6-j,NULL,files,turn);
                            p->KMove();   
                            fetch = p->Print();  
                        }if(file[i] == 'g'){
                            p = new Point(i,6-j,NULL,files,turn);
                            p->GMove();   
                            fetch = p->Print();  
                        }if(file[i] == 'z'){
                            p = new  Point(i,6-j,NULL,files,turn);
                            p->ZMove();   
                            fetch = p->Print();  
                        }if(file[i] == 's'){
                            p = new Point(i,6-j,NULL,files,turn);
                            p->SPMove();   
                            fetch = p->Print();  
                        }if(file[i] == 'p'){
                            p = new Point(i,6-j,NULL,files,turn);
                            p->PMove();   
                            fetch = p->Print();  
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
                        Point *p;
                        if(file[i] == 'L'){
                            p = new Point(i,6-j,NULL,files,turn);
                            p->KMove();   
                            fetch = p->Print();  
                        }if(file[i] == 'G'){
                            p = new Point(i,6-j,NULL,files,turn);
                            p->GMove();   
                            fetch = p->Print();  
                        }if(file[i] == 'Z'){
                            p = new  Point(i,6-j,NULL,files,turn);
                            p->ZMove();   
                            fetch = p->Print();  
                        }if(file[i] == 'S'){
                            p = new Point(i,6-j,NULL,files,turn);
                            p->SPMove();   
                            fetch = p->Print();  
                        }if(file[i] == 'P'){
                            p = new Point(i,6-j,NULL,files,turn);
                            p->PMove();   
                            fetch = p->Print();  
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
};

vector<string>files_vector;
vector<string>fen_vector;
vector<string>moves_vector;

void clearArray(){
    files_vector.clear();
    // moves_vector.clear();
}

int main(){
    string position = "";   //represent a position
    string turn = "";   //represent a players turn
    string m_number = "";   //represent a number of moves
    string split = "";   //helps to split a string
    string fen = "";    //for current FEN
    string move = "";

    int index = 0;  //help with indexes

     //for rows
    string file7 = "";
    string file6 = "";
    string file5 = "";
    string file4 = "";
    string file3 = "";
    string file2 = "";
    string file1 = "";

    //taking input
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
        fen  = fen_vector.at(i);  //current fen
        move =""; /*moves_vector.at(i);  //current  move*/

        /*spliting input to
        1 posiotion <position of pieces> 
        2 turn <side to move> 
        3 m_number <move number>
        */
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
            }else{
                split += x;
                m_number = split;    // last for number of moves
            }
        }

        /*Complexity Analsis :
            // Time c is :O(n) looping the whole input
            // Space c is :O(n) loop,adding the char loop everyrtime i loop
        */
        
        //erase stuff and split again
        split = ""; 
        index = 0 ;

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
        
        /*Complexity Analsis :
            // Time c is :O(n) looping the whole input
            // Space c is :O(n) loop,adding the char loop everyrtime i loop
        */
        split = "";
        index = 0 ;

        files_vector.push_back(file7);
        files_vector.push_back(file6);
        files_vector.push_back(file5);
        files_vector.push_back(file4);
        files_vector.push_back(file3);
        files_vector.push_back(file2);
        files_vector.push_back(file1);

        int m_number_int =stoi(m_number);
        Congo congo = Congo(fen,turn,m_number_int,false,files_vector,move);
        // congo.PrintFile();
        // congo.generateMoves();
        // congo.Execute();
        // congo.Score();
        // cout<<endl;
        congo.Play();
        // congo.game();
        
        clearArray();

        file7 = "";
        file6 = "";
        file5 = "";
        file4 = "";
        file3 = "";
        file2 = "";
        file1 = "";

        position = "";   //represent a position
        turn = "";   //represent a players turn
        m_number = "";   //represent a number of moves
        split = "";   //helps to split a string
        fen = "";    //for current FEN

        index = 0;  //help with indexes
        
        if(i<N-1){
            cout<<endl;
        }
    }
        
    return 0;
}

