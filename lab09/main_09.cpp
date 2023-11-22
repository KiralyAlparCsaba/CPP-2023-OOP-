#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <random>

using namespace std;



void feladatok1_3(){
    //1
    vector<string> fruits {"melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"};
    auto berry = std::find_if(fruits.begin(), fruits.end(), [](const string& fruit) {
        return fruit.find("nana") != string::npos;
    });
    cout << (berry - fruits.begin()) << endl;
    //2
    vector<int> numbers {2,2,2,4,6,6,8,8,8,10};
    auto even = std::all_of(numbers.begin(), numbers.end(), [](const int& num) {
        return (num & 1 )== 0;
    });
    cout << even << endl;
    //3
    vector<int> numbers2 {2,2,2,4,6,6,8,8,8,10};
    std::for_each(numbers2.begin(), numbers2.end(), [](int& num) {
        num = num*2;
    });
    std::for_each(numbers2.begin(), numbers2.end(), [](int& num) {
        cout << num << " ";
    });

}

void feladat4(){
    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };
    cout << count_if(months.begin(), months.end(), [](const string& month) {
        return month.length() == 5;
    }) << endl;


}
void feladat5(){
    vector<float> numbers3 {2,7,2.5,5,4.6,1.3,8,9.1,8,10};
    std::sort(numbers3.begin(), numbers3.end(),[]( float a, float b) {
        return a > b;
    });
    std::for_each(numbers3.begin(), numbers3.end(), [](float num) {
        cout << num << " ";
    });
    cout<<endl;

    greater<float> g;
    std::sort(numbers3.begin(), numbers3.end(),g);
    std::for_each(numbers3.begin(), numbers3.end(), [](float num) {
        cout << num << " ";
    });

}

void feladat6() {
        vector<pair<string, float>> months{
                {"January", 7.5},
                {"February", 8.5},
                {"March", 31.5},
                {"April", 30.5},
                {"May", 31.5},
                {"June", 30.5},
                {"July", 31.5},
                {"August", 31.5},
                {"September", 29.5},
                {"October", 26.5},
                {"November", 25.5},
                {"December", 4.5}
        };
        std::sort(months.begin(), months.end(),[](pair<string, float> a, pair<string, float> b) {
            return a.second < b.second;
        });
        std::for_each(months.begin(), months.end(), [](pair<string, float> month) {
            cout << month.first << " " << month.second << endl;
        });


    }

void feladat7(){
    vector<float> numbers4 {11.2,7,2.5,5,4.6,1.3,8,9.1,8,10};
    std::sort(numbers4.begin(), numbers4.end(),[]( float a, float b) {
        return abs(a) < abs(b);
    });
    std::for_each(numbers4.begin(), numbers4.end(), [](float num) {
        cout << num << " ";
    });
    cout<<endl;

}

void feladat8() {
    vector<pair<string, float>> months{
            {"January", 7.5},
            {"February", 8.5},
            {"March", 31.5},
            {"April", 30.5},
            {"May", 31.5},
            {"June", 30.5},
            {"July", 31.5},
            {"August", 31.5},
            {"September", 29.5},
            {"October", 26.5},
            {"November", 25.5},
            {"December", 4.5}
    };
    for_each(months.begin(), months.end(), [](pair<string, float>& month) {
        month.first[0] = tolower(month.first[0]);
    });
    std::for_each(months.begin(), months.end(), [](pair<string, float>& month) {
        cout << month.first << " " << month.second << endl;
    });

}
void feladat9() {
    mt19937 mt;
    string abc = "abcdefghijklmnopqrstuvwxyz";
    shuffle(abc.begin(), abc.end(), mt);
    cout << abc << endl;

}

int main() {
    //feladatok1_3();
    //feladat4();
    //feladat5();
    //feladat6();
    //feladat7();
    //feladat8();
    //feladat9();





}