#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

void returnArr(vector<int> input){
    for(int num : input){
        cout << num << " " ;
    }
    cout << endl;
}
int main(){
    vector<int> number1, number2;

    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error: Could not open input file." << endl;
        return 1; // Exit with an error code
    }


    int tracker = 0;
    int tracker2 = 0;
    int finalTracker = 0;
    bool increasing;

    string line;
    while(getline(inputFile, line)){
        istringstream iss(line);
        vector<int> values;
        int num;

        while(iss >> num){
            values.push_back(num);
        }
        if(values[0] < values[1]){
            increasing = true;
        }
        else{
            increasing = false;
        }
        bool removal = false;
        for(int i = 0; i < values.size()-1; i++){
            //testing for whether there is a random increase after the decrease or vice versa.  Ex.) 1 20 18 17 16 15removing 18 would make this true but we would also have to change to increasing
            if(!increasing && values[2] > values[1] && !removal){
                values.erase(values.begin()+(0));
                //returnArr(values);
                removal = true;
                i--;
            }
            else if(increasing && values[2] < values[1] && !removal){
                values.erase(values.begin()+(0));
                //returnArr(values);
                removal = true;
                i--;
            }

            if(abs(values[i+1] - values[i] ) > 3){
                    //Ex.) 17 16 14 58 13 12
                    //index[0 1  2  3  4  5]
                    //Ex.) 12 13 14 58 15 16
                    //index[0 1  2  3  4  5]
                    if(removal){
                        tracker++;
                        break;
                    }
                    if(i+2 < values.size()){
                        if(!increasing && values[i+2] < values[i] && abs(values[i+2] - values[i] ) <= 3){
                            values.erase(values.begin()+(i+1));
                            //returnArr(values);
                            removal = true;
                            i--;
                        }
                        else if(increasing && values[i+2] > values[i] && abs(values[i+2] - values[i] ) <= 3){
                            values.erase(values.begin()+(i+1));
                            //returnArr(values);
                            removal = true;
                            i--;
                        }
                    }
                    else{
                        values.erase(values.begin()+(i+1));
                        removal = true;
                        i--;
                    }
            }
            if(increasing && values[i+1] < values[i]){
                    if(removal){
                        tracker++;
                        break;
                    }
                    values.erase(values.begin()+(i+1));
                    //returnArr(values);
                    i--;

            }
            if(!increasing && values[i+1] > values[i]){
                    if(removal){
                        tracker++;
                        break;
                    }
                    values.erase(values.begin()+(i+1));
                    //returnArr(values);
                    i--;

            }
            if(values[i+1] == values[i]){
                    if(removal){
                        tracker++;
                        break;
                    }
                    values.erase(values.begin()+(i+1));
                    //returnArr(values);
                    i--;
            }

            if(i == values.size()-2){
                finalTracker++;
                returnArr(values);
            }
        }
        tracker2++;
    }
    cout << finalTracker << endl;
    tracker = tracker2 - tracker;
    //cout << tracker << endl;

    }
