#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



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

        void Print(){
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
            for(int i=0;i<finalle.size();i++){
                cout<<finalle.at(i);
                //some nice printing
                if(i<finalle.size()-1){
                    cout<<" ";
                }
            }
        }

        //evalute if move is valid
        bool Valid(int curr_x_move,int curr_y_move){
            bool valid = false;
            //king bound for ranks
            if(curr_x_move<5 && curr_x_move>1){
                //king bound for files
                if((curr_y_move<=2 && curr_y_move>=0) || (curr_y_move<=6 && curr_y_move>=4) ){
                    if(turn == "b"){
                        if(isupper(Files.at(6-curr_y_move)[curr_x_move]) || Files.at(6-curr_y_move)[curr_x_move] =='0'){
                            // cout<<Files.at(6-curr_y_move)[curr_x_move]<<"x:"<<curr_x_move<<"y:"<<curr_y_move<<endl;    
                            valid = true;   //yep valid
                        }
                    }
                    //works in reverse idk why? even now, see it later
                        //finally got it, it works with ranks not files
                    else if(turn == "w"){
                        if(islower(Files.at(6-curr_y_move)[curr_x_move]) || Files.at(6-curr_y_move)[curr_x_move] =='0'){
                            // cout<<Files.at(6-curr_y_move)[curr_x_move]<<endl;
                            // cout<<"debug"<<Files.at(6)[3]<<endl;
                            valid = true;   //yebo yes
                        }
                    }
                }
            }
            return valid;
        }

        //queen type of like move
            //1 straight line
            //2 diagonal ?,didn't test this one
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

        //move right
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
        void Move(){
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
};

class Congo{
    public:
        string FEN;         //posiotions
        string Turn = "";   //represent a players turn
        string M_number = "";   //represent a number of moves
        vector<string>File;

        Congo(string fen,string turn,string m_number,vector<string>file){
            this->FEN = fen;
            this->Turn = turn;
            this->M_number = m_number;
            this->File = file;
        }

        void PrintFile(){
            for(int i=0;i<7;i++){
                for(int j=0;j<7;j++){
                    cout<<File.at(i)[j]<<"_";
                }
                cout<<endl;
            }
        }

        void GameRule(){
            for(int j=0;j<7;j++){
                if(Turn == "b"){
                    // j represents a row
                    string file = File.at(j);
                    int c = file.find('l');
                    //c represents a col
                    if(c!=-1){

                        Point p = Point(c,6-j,NULL,File,Turn);
                        p.Move();
                        //cout<<"original x:"<<c<<" y:"<<6-j<<endl;
                        p.Print();
                    }
                    else{
                        //Black Lion not here
                    }        
                }
                else if (Turn == "w"){
                    string file = File.at(j);
                    int c = file.find('L');
                    if(c!=-1){
    
                        Point p = Point(c,6-j,NULL,File,Turn);
                        p.Move();
                        //cout<<"original x:"<<c<<" y:"<<6-j<<endl;
                        p.Print();
                    }
                    else{
                        // White Lion not here
                    }
                }
            }
        }
};

vector<string>ranks_vector;
vector<string>files_vector;
vector<string>fen_vector;

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

void newadd(){
    //searchin files
    for(int i=0;i<7;i++){
        //searching for ranks
        for(int j=0;j<7;j++){
            //search by ranks
            char row = (char)('a'+i);
            int col = 7 - j;
            if(files_vector.at(j)[i] == 'P'){
            string square = "";
            square += row;
            square += to_string(col);
            Wpawn.push_back(square);
            }else if(files_vector.at(j)[i] == 'S'){
                string square = "";
                square += row;
                square += to_string(col);
                Wsuperpawn.push_back(square);
            }else if(files_vector.at(j)[i] == 'G'){
                string square = "";
                square += row;
                square += to_string(col);
                Wgirafe.push_back(square);
            }else if(files_vector.at(j)[i] == 'M'){
                string square = "";
                square += row;
                square += to_string(col);
                Wmonkey.push_back(square);
            }else if(files_vector.at(j)[i] == 'E'){
                string square = "";
                square += row;
                square += to_string(col);
                Welephant.push_back(square);
            }else if(files_vector.at(j)[i] == 'L'){
                string square = "";
                square += row;
                square += to_string(col);
                Wlion.push_back(square);
            }else if(files_vector.at(j)[i] == 'C'){
                string square = "";
                square += row;
                square += to_string(col);
                Wcrocodile.push_back(square);
            }else if(files_vector.at(j)[i] == 'Z'){
                string square = "";
                square += row;
                square += to_string(col);
                Wzebra.push_back(square);
            }else if(files_vector.at(j)[i] == 'p'){
                string square = "";
                square += row;
                square += to_string(col);
                Bpawn.push_back(square);
            }else if(files_vector.at(j)[i] == 's'){
                string square = "";
                square += row;
                square += to_string(col);
                Bsuperpawn.push_back(square);
            }else if(files_vector.at(j)[i] == 'g'){
                string square = "";
                square += row;
                square += to_string(col);
                Bgirafe.push_back(square);
            }else if(files_vector.at(j)[i] == 'm'){
                string square = "";
                square += row;
                square += to_string(col);
                Bmonkey.push_back(square);
            }else if(files_vector.at(j)[i] == 'e'){
                string square = "";
                square += row;
                square += to_string(col);
                Belephant.push_back(square);
            }else if(files_vector.at(j)[i] == 'l'){
                string square = "";
                square += row;
                square += to_string(col);
                Blion.push_back(square);
            }else if(files_vector.at(j)[i] == 'c'){
                string square = "";
                square += row;
                square += to_string(col);
                Bcrocodile.push_back(square);
            }else if(files_vector.at(j)[i] == 'z'){
                string square = "";
                square += row;
                square += to_string(col);
                Bzebra.push_back(square);
            }
        }
    }
    /*Complexity Analsis :
            // Time c is :O(n*n) nested loops,for row and cols
            // Space c is :O(n*n) loop,adding the char loop everyrtime i loop /: not sure
        */
}
void print(){
    cout<<"white pawn:";
    sort(Wpawn.begin(), Wpawn.end());
    for(int j=0;j<Wpawn.size();j++){
        cout<<" "<<Wpawn.at(j);
    }cout<<endl;
    cout<<"black pawn:";
    sort(Bpawn.begin(), Bpawn.end());
    for(int j=0;j<Bpawn.size();j++){
        cout<<" "<<Bpawn.at(j);
    }cout<<endl;
    cout<<"white superpawn:";
    sort(Wsuperpawn.begin(), Wsuperpawn.end());
    for(int j=0;j<Wsuperpawn.size();j++){
        cout<<" "<<Wsuperpawn.at(j);
    }cout<<endl;
    cout<<"black superpawn:";
    sort(Bsuperpawn.begin(), Bsuperpawn.end());
    for(int j=0;j<Bsuperpawn.size();j++){
        cout<<" "<<Bsuperpawn.at(j);
    }cout<<endl;
    cout<<"white giraffe:";
    sort(Wgirafe.begin(), Wgirafe.end());
    for(int j=0;j<Wgirafe.size();j++){
        cout<<" "<<Wgirafe.at(j);
    }cout<<endl;
    cout<<"black giraffe:";
    sort(Bgirafe.begin(), Bgirafe.end());
    for(int j=0;j<Bgirafe.size();j++){
        cout<<" "<<Bgirafe.at(j);
    }cout<<endl;
    cout<<"white monkey:";
    sort(Wmonkey.begin(), Wmonkey.end());
    for(int j=0;j<Wmonkey.size();j++){
        cout<<" "<<Wmonkey.at(j);
    }cout<<endl;
    cout<<"black monkey:";
    sort(Bmonkey.begin(), Bmonkey.end());
    for(int j=0;j<Bmonkey.size();j++){
        cout<<" "<<Bmonkey.at(j);
    }cout<<endl;
    cout<<"white elephant:";
    sort(Welephant.begin(), Welephant.end());
    for(int j=0;j<Welephant.size();j++){
        cout<<" "<<Welephant.at(j);
    }cout<<endl;
    cout<<"black elephant:";
    sort(Belephant.begin(), Belephant.end());
    for(int j=0;j<Belephant.size();j++){
        cout<<" "<<Belephant.at(j);
    }cout<<endl;
    cout<<"white lion:";
    sort(Wlion.begin(), Wlion.end());
    for(int j=0;j<Wlion.size();j++){
        cout<<" "<<Wlion.at(j);
    }cout<<endl;
    cout<<"black lion:";
    sort(Blion.begin(), Blion.end());
    for(int j=0;j<Blion.size();j++){
        cout<<" "<<Blion.at(j);
    }cout<<endl;
    cout<<"white crocodile:";
    sort(Wcrocodile.begin(), Wcrocodile.end());
    for(int j=0;j<Wcrocodile.size();j++){
        cout<<" "<<Wcrocodile.at(j);
    }cout<<endl;
     cout<<"black crocodile:";
     sort(Bcrocodile.begin(), Bcrocodile.end());
    for(int j=0;j<Bcrocodile.size();j++){
        cout<<" "<<Bcrocodile.at(j);
    }cout<<endl;
     cout<<"white zebra:";
     sort(Wzebra.begin(), Wzebra.end());
    for(int j=0;j<Wzebra.size();j++){
        cout<<" "<<Wzebra.at(j);
    }cout<<endl;
     cout<<"black zebra:";
     sort(Bzebra.begin(), Bzebra.end());
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

    files_vector.clear();
}


int main(){
    string position = "";   //represent a position
    string turn = "";   //represent a players turn
    string m_number = "";   //represent a number of moves
    string split = "";   //helps to split a string
    string fen = "";    //for current FEN

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
        string fen;
        getline(cin,fen);
        fen_vector.push_back(fen);
    }

    for(int i=0;i<N;i++){
        // index = 0;
        fen  = fen_vector.at(i);  //current fen

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

        // cout<<"Number of run:"<<i<<endl;
        // cout<<"File1:"<<file1<<endl;
        // cout<<"File7:"<<file7<<endl;

        files_vector.push_back(file7);
        files_vector.push_back(file6);
        files_vector.push_back(file5);
        files_vector.push_back(file4);
        files_vector.push_back(file3);
        files_vector.push_back(file2);
        files_vector.push_back(file1);

        Congo congo = Congo(fen,turn,m_number,files_vector);
        // congo.PrintFile();
        // cout<<"file:"<<6<<" "<<files_vector.at(2)<<endl;
        // cout <<files_vector.at(1)[3]<<endl;
        congo.GameRule();
        
        // int s = file7.find('L');
        // cout<<s<<endl;


        /*for(int j=0;j<7;j++){
            // cout<<"file:"<<i<<" "<<files_vector.at(i)<<endl;
            for(int k=0;k<7;k++){
                // cout<<files_vector.at(j)[k]<<"_";
            }
            cout<<endl;
        }*/

        // newadd();

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

