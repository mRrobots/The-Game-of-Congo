#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

class Board{
private:
    vector<vector<string>> board;
    vector<string> opts = {"p","s","g","m","e","l","c","z"};
    string turn = "";
    int gameNum = 0;//never initialized
    vector<vector<string>> convMap = {
            {"a7", "b7", "c7", "d7", "e7", "f7", "g7"},
            {"a6", "b6", "c6", "d6", "e6", "f6", "g6"},
            {"a5", "b5", "c5", "d5", "e5", "f5", "g5"},
            {"a4", "b4", "c4", "d4", "e4", "f4", "g4"},
            {"a3", "b3", "c3", "d3", "e3", "f3", "g3"},
            {"a2", "b2", "c2", "d2", "e2", "f2", "g2"},
            {"a1", "b1", "c1", "d1", "e1", "f1", "g1"}
    };
    string gamestate = "";
    vector<string> stateCapture;

public:

    Board(){
        vector<string> init = {"gmelecz/ppppppp/7/7/7/PPPPPPP/GMELECZ", "w", "0"};
        setState(init);
    }

    vector<string> split(string str, char del){
        string temp = "";
        vector<string> data;

        for(int i=0; i<(int)str.size(); i++){
            if(str[i] != del){
                temp += str[i];
            }
            else{
                data.push_back(temp);
                temp = "";
            }
        }
        data.push_back(temp);
        return data;
    }

    vector<string> sorter(vector<string> str){
        string temp;
        for(int i = 0; i < str.size(); i++){
            for (int j = i+ 1; j < str.size(); j++){
                if(str[i] > str[j]){
                    temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;
                }
            }
        }
        return str;
    }

    void setState(vector<string> inp){
        string state = inp[0];
        string t = inp[1];
        gameNum = stoi(inp[2]);
        playerTurn(t);
        board.clear();
        vector<string> dat = split(state, '/');
        for(int i = 0; i < 7; i++){
            vector<string> curr;
            string str = "";
            for (int j = 0; j < dat[i].size(); j++){
                str += dat[i][j];
                curr.push_back(str);
                str = "";
            }
            board.push_back(curr);
        }
        filler();
        gamestate = printState();
        stateCapture = inp;
    }

    bool isPresent(vector<string> data, string word){
        for (string el : data){
            if(el == word){
                return true;
            }
        }
        return false;
    }

    bool isBlack(string pos){
        int row = pos[0] - '0';
        int col = pos[1] - '0';
        return isPresent(opts,board[row][col]);
    }

    bool sameColor(string pos1, string pos2){
        if(isBlack(pos1) == isBlack(pos2)){
            return true;
        }
        return false;
    }

    void filler(){
        vector<vector<string>> clone;
        for(int i = 0; i < 7; i ++){
            vector<string> curr;
            for (int j = 0 ; j < board[i].size(); j++){
                curr.push_back(board[i][j]);
            }
            clone.push_back(curr);
        }
        board.clear();
        for(int i = 0; i < 7; i++){
            vector<string> curr;
            for(int j = 0; j < clone[i].size(); j++){
                string num = "";
                string word = clone[i][j];
                transform(word.begin(), word.end(), word.begin(), :: tolower);
                if(isPresent(opts, word)){
                    num += clone[i][j];
                    curr.push_back(num);
                }else{
                    int count = stoi(clone[i][j]);
                    for(int p = 0; p < count; p++){
                        curr.push_back(" ");
                    }
                }
            }
            board.push_back(curr);
        }
    }

    void print(){
        vector<string> bases = {
                "white pawn :",
                "black pawn :",
                "white superpawn :",
                "black superpawn :",
                "white giraffe :",
                "black giraffe :",
                "white monkey :",
                "black monkey :",
                "white elephant :",
                "black elephant :",
                "white lion :",
                "black lion :",
                "white crocodile :",
                "black crocodile :",
                "white zebra :",
                "black zebra :"};
        vector<string> letters = {" a", " b", " c", " d", " e", " f", " g"};//bumps into it first
        vector<vector<string>> pieces;

        for(int i = 0; i < bases.size(); i++){
            vector<string> temp;
            pieces.push_back(temp);
        }
        int row = 7;
        for(int i = 0; i < 7; i++){
            string r = to_string(row);
            for(int j = 0; j < 7; j++){
                string check = board[i][j];
                string add = letters[j]+r;
                if (check ==  "P"){
                    pieces[0].push_back(add);
                }
                else if (check ==  "p"){
                    pieces[1].push_back(add);
                }
                else if (check ==  "S"){
                    pieces[2].push_back(add);
                }
                else if (check == "s"){
                    pieces[3].push_back(add);
                }
                else if (check == "G"){
                    pieces[4].push_back(add);
                }
                else if (check == "g"){
                    pieces[5].push_back(add);
                }
                else if (check == "M"){
                    pieces[6].push_back(add);
                }
                else if (check == "m"){
                    pieces[7].push_back(add);
                }
                else if (check == "E"){
                    pieces[8].push_back(add);
                }
                else if (check == "e"){
                    pieces[9].push_back(add);
                }
                else if (check == "L"){
                    pieces[10].push_back(add);
                }
                else if (check == "l"){
                    pieces[11].push_back(add);
                }
                else if (check == "C"){
                    pieces[12].push_back(add);
                }
                else if (check == "c"){
                    pieces[13].push_back(add);
                }
                else if (check == "Z"){
                    pieces[14].push_back(add);
                }
                else if (check == "z"){
                    pieces[15].push_back(add);
                }
            }
            row -= 1;
        }


        for(int i = 0; i < pieces.size(); i++){
            cout<<bases[i];
            vector<string> curr = sorter(pieces[i]);
            //sort(curr.begin(), curr.end());
            for(int j = 0; j < pieces[i].size(); j++){
                cout<<curr[j];
            }
            if(i != pieces.size()-1){
                cout<<endl;
            }
        }

        cout<<"side to play : "<<turn<<endl;

    }

    void playerTurn(string t){
        if (t == "b"){
            turn = "black";
        }else{
            turn = "white";
        }
    }

    void shader(int flick) {
        if(flick == 1){
            for (int row = 0; row < 7; row++) {
                board[row][5] = "*";
                board[row][1] = "*";
                board[3][row] = "*";
            }
        }else{
            setState(stateCapture);

        }
    }

    string locator(string curr) {
        string answer = "";
        for (int i = 6; i >= 0; i--) {
            for (int j = 6; j >= 0; j--) {
                if (board[i][j] == curr) {
                    return to_string(i) + to_string(j);
                }
            }
        }
        return answer;
    }

    string converter(string raw, int dir){
        string answer = "";
        if(dir == 0){//word map to num map
            for (int i = 0; i < 7; i++){
                for(int j = 0; j < 7; j++){
                    if(convMap[i][j] == raw){
                        string row = to_string(i);
                        string col = to_string(j);
                        return row+col;
                    }
                }
            }
        }
        else if(dir == 1){//num map to word map
            int row = raw[0] - '0';
            int col = raw[1] - '0';
            return convMap[row][col];
        }
        return answer;
    }

    vector<string> availOptions(string pos){
        vector<string>answer;
        string cords = converter(pos, 0);//num coords
//        string cords = pos;
        int row = cords[0] -'0';
        int col = cords[1] -'0';
        string val = board[row][col];
        string clone = val;
        transform(clone.begin(), clone.end(), clone.begin(), :: tolower);
        bool race = isBlack(cords);

        if(clone == "l"){
            shader(1);
            if(row > 0 and row != 4) {
                for (int i = -1; i < 2; i++) {
                    string curr = board[row - 1][col + i];
                    string currCords = to_string(row - 1) + to_string(col + i);
                    if(col+i > 1 and col+i < 5) {
                        if (curr == " " or (curr != "*" and !sameColor(cords, currCords))) {
                            answer.push_back(currCords);
                        }
                    }
                }
            }

            if(row < 6 and row != 2 ){
                for(int i = -1; i < 2; i++){
                    string curr = board[row+1][col+i];
                    string currCords = to_string(row+1)+to_string(col+i);
                    if(col+i > 1 and col+i < 5) {
                        if (curr == " " or (curr != "*" and !sameColor(cords, currCords))) {
                            answer.push_back(currCords);
                        }
                    }
                }
            }
            string currCords = to_string(row)+to_string(col-1);
            if(board[row][col-1] == " " or (board[row][col-1] != "*" and !sameColor(cords, currCords))){
                answer.push_back(to_string(row)+to_string(col-1));
            }
            currCords = to_string(row)+to_string(col+1);
            if(board[row][col+1] == " " or (board[row][col+1] != "*" and !sameColor(cords, currCords))){
                answer.push_back(to_string(row)+to_string(col+1));
            }


            bool isClear = true;
            shader(0);

            if(locator("L")[1] -'0' == locator("l")[1] -'0'){
                string cordZ = locator("L");//num coords
                int rowS = cordZ[0] -'0';
                string cordz = locator("l");//num coords
                int rows = cordz[0] -'0';

                for(int t = min(rowS, rows)+1 ; t < max(rowS, rows); t++){
                    if(board[t][col] != " "/* and t != 3*/){
                        isClear = false;
                    }
                }
                if(isClear){
                    if(clone.compare(val)){
                        //write a for loop to check if thre is something along the path
                        //just a simple checker if its blank using locator("l")[1] -'0'
                        answer.push_back(locator("l"));
                    }else {
                        answer.push_back(locator("L"));
                    }
                }


            }
            else if(locator("L")[0] -'0' == 4 and locator("l")[0] -'0' == 2 and ((locator("l")[1] - '0') - (locator("L")[1] - '0') == 2)){
                if(board[3][3] == " "){
                    if(clone.compare(val)){
                        //write a for loop to check if thre is something along the path
                        //just a simple checker if its blank using locator("l")[1] -'0'
                        answer.push_back(locator("l"));
                    }else {
                        answer.push_back(locator("L"));
                    }
                }
            }
//            shader(0);
        }
        else if(clone == "z"){
            vector<int> moves = {2,-2,1,-1};
            for(int transRow : moves){
                for(int transCol : moves){
                    if(abs(transCol) + abs(transRow) == 3) {
                        int r = row + transRow;
                        int c = col + transCol;
                        string currCords = to_string(r) + to_string(c);
                        if (r >= 0 and r <= 6 and c >= 0 and c <= 6) {
                            if (board[r][c] == " " or !sameColor(cords, currCords)) {
                                if (!isPresent(answer, currCords)) {
                                    answer.push_back(currCords);
                                }
                            }
                        }
                    }
                }
            }
        }
        else if(clone == "e"){
            for(int i = -2; i < 3; i++){
                int r = row + i;
                int c = col + i;
                if(i != 0 and c < 7 and c >= 0){
                    string currCords = to_string(row) + to_string(c);
                    if(board[row][c] == " " or !sameColor(cords, currCords)){
                        answer.push_back(currCords);
                    }
                }
                if (i != 0 and r < 7 and r >= 0){
                    string currCords = to_string(r) + to_string(col);
                    if(board[r][col] == " " or !sameColor(cords, currCords)){
                        answer.push_back(currCords);
                    }
                }
            }
        }
        else if(clone == "p"){
            //after crossing the river you should be able to move backwards straight with 1 or 2 steps
            //this last move is not a jump so it can get blocked.
            if(val == clone){//black
                if(row != 6){
                    int r = row + 1;
                    for(int i = -1; i < 2; i++){
                        if(col + i >= 0 and col + i < 7){
                            string currCords = to_string(r)+to_string(col+i);
                            if (board[r][col+i] == " " or !sameColor(cords, currCords)){
                                answer.push_back(currCords);
                            }
                        }
                    }
                }
                if(row > 3){
                    int curr = -1;
                    do{
                        int r = row + curr;
                        string currCords = to_string(r)+to_string(col);
                        if(board[r][col] == " "){
                            answer.push_back(currCords);
                        }else{
                            break;
                        }
                        curr -= 1;
                        if(curr == -3){
                            break;
                        }
                    }while(board[row + curr][col] == " " and curr > -3);

                }
            }else{//white
                if(row != 0){
                    int r = row - 1;
                    for(int i = -1; i < 2; i++){
                        if(col + i >= 0 and col + i < 7){
                            string currCords = to_string(r)+to_string(col+i);
                            if (board[r][col+i] == " " or !sameColor(cords, currCords)){
                                answer.push_back(currCords);
                            }
                        }
                    }
                }
                if(row < 3){
                    int curr = 1;
                    do{
                        int r = row + curr;
                        string currCords = to_string(r)+to_string(col);
                        if(board[r][col] == " "){
                            answer.push_back(currCords);
                        }else{
                            break;
                        }
                        curr += 1;
                        if(curr == 3){
                            break;
                        }
                    }while(board[row + curr][col] == " " and curr < 3);
                }
            }


        }
        else if(clone == "g"){
            for(int i = -2; i < 3; i++){
                if(row +i < 7 and row + i >= 0){
                    string currCords = to_string(row+i) + to_string(col);
                    if(board[row + i][col] == " " or (abs(i) == 2 and !sameColor(cords, currCords))){
                        answer.push_back(to_string(row+i)+to_string(col));
                    }
                }
                if(col +i < 7 and col + i >= 0) {
                    string currCords = to_string(row) + to_string(col+i);
                    if (board[row][col + i] == " " or (abs(i) == 2 and !sameColor(cords, currCords))) {
                        answer.push_back(to_string(row) + to_string(col + i));
                    }
                }
                if(row +i < 7 and row + i >= 0 and col +i < 7 and col + i >= 0) {
                    string currCords = to_string(row+i) + to_string(col+i);
                    if (board[row + i][col + i] == " " or (abs(i) == 2 and !sameColor(cords, currCords))) {
                        answer.push_back(to_string(row + i) + to_string(col + i));
                    }
                }
                if(row +i < 7 and row + i >= 0 and col -i < 7 and col - i >= 0) {
                    string currCords = to_string(row+i) + to_string(col-i);
                    if (board[row + i][col - i] == " " or (abs(i) == 2 and !sameColor(cords, currCords))) {
                        answer.push_back(to_string(row + i) + to_string(col - i));
                    }
                }

            }
        }
        else if(clone == "s"){
            if(val == clone){//black
                for(int i = -1; i > -3 and row + i >= 0 and col + i >= 0; i--){
                    string currCords = to_string(row+i)+to_string(col+i);
                    if (board[row+i][col+i] == " "){
                        answer.push_back(currCords);
                    }else{
                        break;
                    }
                }
                for(int i = -1; i > -3 and row + i >= 0 and col - i <= 6; i--){
                    string currCords1 = to_string(row+i)+to_string(col-i);
                    if (board[row+i][col-i] == " "){
                        answer.push_back(currCords1);
                    }else{
                        break;
                    }
                }

                if(row != 6){
                    int r = row + 1;
                    for(int i = -1; i < 2; i++){
                        if(col + i >= 0 and col + i < 7){
                            string currCords = to_string(r)+to_string(col+i);
                            if (board[r][col+i] == " " or !sameColor(cords, currCords)){
                                answer.push_back(currCords);
                            }
                        }
                    }
                    int curr = -1;
                    do{
                        int rule = row + curr;
                        if(rule == -1){
                            break;
                        }
                        string currCords = to_string(rule)+to_string(col);
                        if(board[rule][col] == " "){
                            answer.push_back(currCords);
                        }else{
                            break;
                        }
                        curr -= 1;
                        if(curr == -3 or row + curr < 0){
                            break;
                        }
                    }while(board[row + curr][col] == " " and curr > -3);
                }
            }
            else{//white
                for(int i = 1; i < 3 and row + i <= 6 and col + i <= 6; i++){
                    string currCords = to_string(row+i)+to_string(col+i);
                    if (board[row+i][col+i] == " "){
                        answer.push_back(currCords);
                    }else{
                        break;
                    }
                }
                for(int i = 1; i < 3 and row + i <= 6 and col - i >= 0; i++){
                    string currCords1 = to_string(row+i)+to_string(col-i);
                    if (board[row+i][col-i] == " "){
                        answer.push_back(currCords1);
                    }else{
                        break;
                    }
                }

                if(row != 0){
                    int r = row - 1;
                    for(int i = -1; i < 2; i++){
                        if(col + i >= 0 and col + i < 7){
                            string currCords = to_string(r)+to_string(col+i);
                            if (board[r][col+i] == " " or !sameColor(cords, currCords)){
                                answer.push_back(currCords);
                            }
                        }
                    }
                    int curr = 1;
                    do{
                        int rule = row + curr;
                        if(rule == 7){
                            break;
                        }
                        string currCords = to_string(rule)+to_string(col);
                        if(board[rule][col] == " "){
                            answer.push_back(currCords);
                        }else{
                            break;
                        }
                        curr += 1;
                        if(curr == 3 or row + curr > 6){
                            break;
                        }
                    }while(board[row + curr][col] == " " and curr < 3);
                }




            }
            if(col != 0){
                string currCords = to_string(row)+to_string(col-1);
                if (board[row][col-1] == " " or !sameColor(cords, currCords)){
                    answer.push_back(currCords);
                }
            }
            if(col != 6){
                string currCords = to_string(row)+to_string(col+1);
                if (board[row][col+1] == " " or !sameColor(cords, currCords)){
                    answer.push_back(currCords);
                }
            }
        }

        return answer;
    }

    string printState() {
        string answer = "";
        for(int i = 0; i < 7; i++){
            int count = 0;
            for(int j = 0; j < 7; j++){
                if(board[i][j] == " " or board[i][j] == ""){
                    count+=1;
                    if(j == 6){
                        answer += to_string(count);
                        count = 0;
                    }
                }else{
                    if(count > 0){
                        answer += to_string(count);
                        count = 0;
                    }
                    answer += board[i][j];
                }
            }
            if(i != 6){
                answer += "/";
            }
        }
        return answer;
    }

    void makeMove(string move) {
        string ini = "";
        string fin = "";
        ini = ini + move[0]+move[1];
        fin = fin + move[2]+move[3];
        ini = converter(ini,0);
        fin = converter(fin,0);
        int row1 = ini[0] - '0';
        int col1 = ini[1] - '0';
        int row2 = fin[0] - '0';
        int col2 = fin[1] - '0';
        if(isPresent(availOptions(ini), fin) and (!sameColor(ini, fin) or
                                                  boxValue(row2, col2) == " ")){
            string temp = board[row1][col1];
            board[row2][col2] = board[row1][col1];
            board[row1][col1] = " ";
            for(int i = 0; i < 7; i++){
                //string curr = board[3][i];
                if(sameColor(fin, to_string(3)+ to_string(i))){
                    board[3][i] = " ";
                }
                if(row1 != 3 and row2 == 3){
                    board[row2][col2] = temp;
                }
            }
            if(temp == "p" and row2 == 6){
                board[row2][col2] == "s";
            }else if(temp == "P" and row2 == 0){
                board[row2][col2] == "S";
            }
            if(isBlackTurn()){
                gameNum += 1;
                gamestate = printState() + " w " + to_string(gameNum);
            }else{
                gamestate = printState() + " b " + to_string(gameNum);
            }

        }else{
            if(isBlackTurn()){
                gamestate = printState() + " b " + to_string(gameNum);
            }else{
                gamestate = printState() + " w " + to_string(gameNum);
            }
        }
    }

    bool piecePresent(string piece){
        for(int i = 0 ; i < 7; i++){
            for(int j = 0 ; j < 7; j++){
                if(board[i][j] == piece){
                    return true;
                }
            }
        }
        return false;
    }

    int evalFun(){
        int answer = 0;
        int ele = 200;
        int paw = 100;
        int zeb = 300;

        for(int i = 0; i < 7; i ++){
            for(int j = 0 ; j < 7; j++){
                string clone = board[i][j];
                transform(clone.begin(), clone.end(), clone.begin(), :: tolower);
                if(clone == "p"){
                    if(isPresent(opts, board[i][j])){
                        answer -= paw;
                    }else{
                        answer+= paw;
                    }
                }else if(clone == "e"){
                    if(isPresent(opts, board[i][j])){
                        answer -= ele;
                    }else{
                        answer+= ele;
                    }
                }else if(clone == "z"){
                    if(isPresent(opts, board[i][j])){
                        answer -= zeb;
                    }else{
                        answer+= zeb;
                    }
                }
            }
        }
        if(turn == "black"){
            return answer * -1;
        }else {
            return answer;
        }
    }

    bool isValidMove(string piece, string move){
        vector<string>options = availOptions(piece);
        return isPresent(options, move);
    }

    bool isGameOver(){
        bool black = false;//isAlive
        bool white = false;//isAlive
        for (int i = 0 ; i < 7; i++){
            for (int j = 0 ; j < 7; j++){
                if(board[i][j] == "l"){
                    black = true;
                }
                if(board[i][j] == "L"){
                    white = true;
                }
                if(black and white){
                    return false;
                }

            }
        }
        return true;
    }

    string boxValue(int i, int j){
        return board[i][j];
    }

    vector<string> allMoves(){
        vector<string> answer;
        if(isBlackTurn()){
            for(int i = 0; i < 7; i++){
                for(int j = 0 ; j < 7; j++){
                    if(isPresent(opts, board[i][j])){
                        string c = converter(to_string(i)+to_string(j), 1);
                        vector<string> curr = availOptions(c);
                        for(string el : curr){
                            string d = converter(el, 1);
                            if(c != d){
                                answer.push_back(c+d);
                            }
                        }
                    }
                }
            }
        }else{
            for(int i = 0; i < 7; i++){
                for(int j = 0 ; j < 7; j++){
                    if(!isPresent(opts, board[i][j]) and board[i][j] != " " and board[i][j] != ""){
                        string c = converter(to_string(i)+to_string(j), 1);
                        vector<string> curr = availOptions(c);
                        for(string el : curr){
                            string d = converter(el, 1);
                            if(c != d){
                                answer.push_back(c+d);
                            }
                        }
                    }
                }
            }

        }
        return answer;
    }//returns them combined, the current move and the next move

    string gameState(){
        return gamestate;
    }

    bool isBlackTurn(){
        if(turn == "black"){
            return true;
        }else{
            return false;
        }
    }

    vector<string> nextState(){
        vector<string> answer;
        answer.push_back(gamestate);
        if(isBlackTurn()){
            answer.push_back("w");
            answer.push_back(to_string(gameNum+1));
        }else{
            answer.push_back("b");
            answer.push_back(to_string(gameNum));
        }
        return answer;
    }

    vector<string> gameStateVec(){
        vector<string> answer;
        answer.push_back(gamestate);
        if(isBlackTurn()){
            answer.push_back("b");
        }else{
            answer.push_back("w");
        }
        answer.push_back(to_string(gameNum));
        return answer;
    }
//
    vector<string> massLocator(string piece){
        vector<string> answer;
        for (int i = 6; i >= 0; i--) {
            for (int j = 6; j >= 0; j--) {
                if (board[i][j] == piece) {
                    answer.push_back(to_string(i) + to_string(j));
                }
            }
        }
        vector<string> temp;
        for(string el : answer){
            temp.push_back(converter(el, 1));
        }
        answer.clear();
        for(string el : sorter(temp)){
            answer.push_back(converter(el, 0));
        }

        return answer;
    }

    void massPrinter(){
        int N = 0;
        cin>>N;
        vector<vector<string>> inputs;
        string inp = "";
        for (int j = 0; j <N;j++){
            vector<string>curr;
            for(int i = 0; i < 3;i++){
                cin>>inp;
                curr.push_back(inp);
            }
            inputs.push_back(curr);
        }
        string black = "l";//when there are multiple verions of the piece
        string white = "L";
        for (int i  = 0; i < N; i ++){
            Board board;
            board.setState(inputs[i]);
            if(board.isBlackTurn()){
                for (string key : board.massLocator(black)){
                    vector<string>curr;
                    for(string el : board.availOptions(board.converter(key, 1))){
                        curr.push_back(board.converter(el, 1));
                    }

                    for (string el : board.sorter(curr)){
                        if(el.compare(board.converter(key, 1)) != 0){
                            cout<<board.converter(key, 1)<<el<<" ";
                        }
                    }
                }

                cout<<endl;
            }else{
                for (string key : board.massLocator(white)){
                    vector<string>curr;
                    for(string el : board.availOptions(board.converter(key, 1))){
                        curr.push_back(board.converter(el, 1));
                    }

                    for (string el : board.sorter(curr)){
                        if(el.compare(board.converter(key, 1)) != 0){
                            cout<<board.converter(key, 1)<<el<<" ";
                        }
                    }
                }
                cout<<endl;

//            for(string el : board.availOptions(board.converter(board.locator(white), 1))){
//                curr.push_back(board.converter(el, 1));
//            }
//            for (string el : board.sorter(curr)){
//                if(el.compare(board.converter(board.locator(white), 1)) != 0){
//                    cout<<board.converter(board.locator(white), 1)<<el<<" ";
//                }
//            }
//            cout<<endl;
            }
        }

    }

    string gameDone(){
        if(!piecePresent("L")){
            return "Black wins";
        }else if(!piecePresent("l")){
            return "White wins";
        }else{
            return "Continue";
        }
    }

    void massMover(){
        ifstream theFileOut("out.txt");//this is to compare the outputs with the things the code is outputting
        ifstream theFileIn("in.txt");//this is to compare the outputs with the things the code is outputting
        ofstream theFile("output.txt");

        int N = 0;
        cin >> N;
        vector<vector<string>> inputs;
        vector<string> moves;
        string inp = "";
        for (int j = 0; j < N; j++) {//TODO edge cases not catered for in point 3
            //TODO invalid moves not catered for
            vector<string> curr;
            for (int i = 0; i < 3; i++) {
                cin >> inp;
                curr.push_back(inp);
            }
            string move;
            cin >> move;
            moves.push_back(move);
            inputs.push_back(curr);
        }




        for (int i  = 0; i < N; i ++){
            Board board;
            board.setState(inputs[i]);
            board.makeMove(moves[i]);
            cout<<board.gameState()<<endl;
            cout<<board.gameDone()<<endl;

        }

        // string word1;
        // vector<vector<string>> database;
        // vector<string>curr;
        // int count = 0;
        // while(getline(theFileOut, word1)){
        //     count+=1;
        //     curr.push_back(word1);
        //     if(count == 2){
        //         count = 0;
        //         database.push_back(curr);
        //         curr.clear();
        //     }
        // }

//    for (int i  = 0; i < N; i ++){
//        Board board;
//        board.setState(inputs[i]);
//        board.makeMove(moves[i]);
//        if(database[i][0] != board.gameState() or database[i][1] != board.gameDone() ){
//             cout<<endl;
//             cout<<board.gameState()<<endl;
//             cout<<database[i][0]<<" <- supposed to be"<<endl;
//             cout<<endl;
//             cout<<inputs[i][0]<<" <- initial"<<endl;

//             cout<<board.gameDone()<<" is supposed to be "<<database[i][1]<<endl;
//             cout<<"u at "<<i<<endl;
//             break;
//        }
//    }



    }

};

class Game{
private:
    Board board;

public:
    vector<string> state;
    Game(vector<string> state){
        board.setState(state);
        this->state = state;
    }
    void Print(){
        for(int i=0;i<state.size();i++){
            cout<<state.at(i);
        }
    }

    int rawScore(){
        int answer = 0;
        for(char el : board.gameState()){
            string curr = "";
            curr = curr + el;
            string clone = curr;
            transform(clone.begin(), clone.end(), clone.begin(), :: tolower);
            if(clone == "p"){
                if(clone == curr){
                    answer -= 100;
                }else{
                    answer += 100;
                }
            }else if(clone  == "z"){
                if(clone == curr){
                    answer -= 300;
                }else{
                    answer += 300;
                }
            }else if (clone == "s"){
                if(clone == curr){
                    answer -= 350;
                }else{
                    answer += 350;
                }
            }else if(clone == "g"){
                if(clone == curr){
                    answer -= 400;
                }else{
                    answer += 400;
                }
            }
        }
        if(!board.piecePresent("l") and !board.piecePresent("L")){
            answer  = 0;
        }else if(board.gameDone() == "White wins"){
            answer  = 10000;
        }else if(board.gameDone() =="Black wins"){
            answer  = -10000;
        }
        if(board.isBlackTurn()){
            return answer *-1;
        }else{
            return answer;
        }
    }

    void Min(){
        // vector<string>state  = ;
        int m = minimax(state,2);
        cout<<m<<endl;
    }

    int minimax(vector<string> currentState, int depth){
        //make it take a vetor
        Board curr;
        //vector<string> cont = {currentState, "b", "0"};
        curr.setState(currentState);
        if (curr.isGameOver() or depth <= 0){
            return curr.evalFun();
        }
        
        int Cval = -10000000;
        vector<string> moves = curr.allMoves();//strings contain ini and fin
        cout<<moves.at(1)<<endl;
        for(string move : moves){
            vector<string> c = curr.gameStateVec();
            cout<<c.at(0);
            Board b;
            b.setState(c);
            b.makeMove(move);
            vector<string> nextState = b.nextState();
            cout<<nextState.size()<<endl;
//                curr.makeMove(move);
//                string nextState = curr.gameState();
            int eval = -minimax(nextState, depth-1);
            Cval = max(eval, Cval);
        }
        //cout<<Cval<<endl;
        return Cval;

    }
};

int main() {
    //TODO check if move is valid
    //TODO reduce number of times the board is drawn to increase performance

    //*****Possible Culprits*****
    //eval funtion value not updating
    //incorrect function values
    //isgame over funtion funtionality

    // int N = 0;
    // cin >> N;
    // vector<vector<string>> inputs;
    // string inp = "";
    // for (int j = 0; j < N; j++) {//TODO edge cases not catered for in point 3
    //     //TODO invalid moves not catered for
    //     vector<string> curr;
    //     for (int i = 0; i < 3; i++) {
    //         cin >> inp;
    //         curr.push_back(inp);
    //     }
    //     string move;
    //     inputs.push_back(curr);
    // }
    // for (int i  = 0; i < N; i ++){
    //     Game game(inputs[i]);
    //     cout<<game.rawScore()<<endl;
    //     //cout<<game.minimax(inputs[i], 2)<<endl;
    // }



//    ifstream theFileOut("out (copy).txt");//this is to compare the outputs with the things the code is outputting
//    ofstream theFile("output.txt");

    int N = 0;
    cin >> N;
    vector<vector<string>> inputs;
    vector<string> moves;
    string inp = "";
    for (int j = 0; j < N; j++) {//TODO edge cases not catered for in point 3
        //TODO invalid moves not catered for
        vector<string> curr;
        for (int i = 0; i < 3; i++) {
            cin >> inp;
            curr.push_back(inp);
        }
        inputs.push_back(curr);
    }

    string word1;
    vector<string> database;//
    // while(getline(theFileOut, word1)){
    //     database.push_back(word1);
    // }
    // cout<<endl;
    // cout<<endl;

    for (int i  = 0; i < N; i ++){
        Game game(inputs[i]);
        // cout<<game.rawScore()<<endl;
        // game.Print();
        game.Min();

        // if(database[i] != to_string(game.rawScore())){
        //     cout<<game.rawScore()<<endl;
        //     cout<<database[i]<<" <- supposed to be"<<endl;
        //     cout<<endl;
        //     cout<<inputs[i][0]<<" <- initial"<<endl;
        //     cout<<"u at "<<i<<endl;
        //     break;
        // }
    }






    return 0;
}
