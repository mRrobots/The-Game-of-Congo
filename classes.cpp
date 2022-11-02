#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Point{
    private:
        Point *Parent;
    public:
        
        vector<Point*> points;
        int x;
        int y;
        // Point(){}
        Point(int x_point,int y_point,Point *parent){
            // Point *parent = new Point(x,y);
            this->x = x_point;
            this->y = y_point;
            this->Parent = parent;
            // this->parent = parent;
        }

        void Insert(){
            for(int i=0;i<3;i++){
                Point *point = new Point(i,i+1,this);
                points.push_back(point);
            }
        }

        void Print(){
            for(int i=0; i<points.size() ; i++){
                Point *c_point = points.at(i);
                cout<<c_point->x<<endl;
                cout<<c_point->Parent<<endl;
            }
        }

        void MoveRight(){
            Point *right = new Point(Parent->x+1,Parent->y,this);
            cout<<"Moved right"<<endl;
            points.push_back(right);
        }

        void printParent(){
            cout<<"Hello"<<endl;
            cout<<Parent->x<<endl;
        }    
};

// class Hey:public Point{
//     public:
//         void call(){
//             // Print();
//         }
// };

int main(){
    Point p = Point(10,10,NULL);
    // Point point(10,10,p);
    // point.Insert();
    p.MoveRight();
    p.Print();
    cout<<"Hey"<<endl;
    // point.printParent(); 

    return 0;
    // cout<<"Hello"<<endl;
}