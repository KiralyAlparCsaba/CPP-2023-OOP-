#include <iostream>
#include "Point.h"

using namespace std;

int main(int argc, char** argv) {
        Point p1(2,3);
        cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
        Point p2(100, 200);
        cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
        Point * pp1 = new Point(300, 400);
        Point * pp2 = new Point(500, 1000);
        cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
        cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
        p1.print();
        cout<<"distance: "<<distance(p1,p2)<<endl;
        Point p3(1,1);
        Point p4(2,1);
        Point p5(1,0);
        Point p6(2,0);
        if(isSquare(p3,p4,p5,p6)==1){
            cout<<"square"<<endl;
        }
        else{
            cout<<"not square haha"<<endl;
        }
        testIsSquare("points.txt");

        cout<<"Give me a number:";
        int n;
        cin>>n;
        Point * pp = createArray(n);
        pp = createArray(n);
        printArray(pp,n);
        closestPoints(pp,n);
        farthestPoints(pp,n);






        delete pp1;
        delete pp2;
        return 0;



}
