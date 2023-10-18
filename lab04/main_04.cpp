#include <iostream>
#include <vector>
#include "PointSet.h"
#include <iomanip>

using namespace std;

int main() {

    /*
    int n = 4;
    PointSet ps(n);
    cout << "Max distance: " << ps.maxDistance() << endl;
    cout << "Min distance: " << ps.minDistance() << endl;
    cout << "Number of distances: " << ps.numDistances() << endl;
    ps.sortPointsX();
    ps.printPoints();
    cout<<endl;

    ps.sortPointsY();
    ps.printPoints();
    cout<<endl;

    ps.sortDistances();
    ps.printDistances();
    cout<<endl;

    cout << "Number of distinct distances: " << ps.numDistinctDistances() << endl;
    */
    int n = 2;
    cout<<"Pontok\tMinTav\t MaxTav\t #tavolsagok\t#kulonbozotavolsagok"<<endl;
    cout<< fixed;
    for( int i= 0; i<12; ++i ){
        PointSet pSet( n );
        cout<<setw(6)<<n<<" ";
        cout<<setw(8)<<setprecision(2)<<pSet.minDistance()<<" ";
        cout<<setw(8)<<setprecision(2)<<pSet.maxDistance()<<" ";
        cout<<setw(10) << pSet.numDistances()<<" ";
        cout<<setw(16) << pSet.numDistinctDistances()<<endl;
        n = n << 1;
    }

}