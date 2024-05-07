#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool compareValues(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

int main()
{
    map<string,int> search;
    string s1;
    int offset, flag = 0;
    string line;
    string file_name,file_name_;
    
    int choi; char c;
    map<string, int> map;
    vector<string> selected_files;
    
    // Take input for search specifications
    while (true) {
        cout << "Do you want to enter a specification (y/n): ";
        cin >> c;
        if (c == 'y') {
            cout << "Enter the word to search: ";
            cin >> s1;
            // Convert to uppercase for case-insensitive search
            transform(s1.begin(), s1.end(), s1.begin(), [](unsigned char c){ return std::toupper(c); });
            search[s1] = 0;
        } else {
            break;
        }
    }
    
    // Search for the specified keywords in the files
    while (true) {
        cout << "Enter 1 to continue to enter applicant id and 0 to exit: ";
        cin >> choi;
        if (choi == 1) {
            cout << "Enter id: ";
            
            cin >> file_name;
            file_name_=file_name+".txt";
            ifstream Myfile(file_name_);
            int count = 0;
            if (Myfile.is_open()) {
                while (getline(Myfile, line)) {
                    // Convert to uppercase for case-insensitive search
                    transform(line.begin(), line.end(), line.begin(), [](unsigned char c){ return std::toupper(c); });
                    for (auto& pair : search) {
                        if ((offset = line.find(pair.first, 0)) != string::npos) {
                            pair.second++; 
                            count++;
                        }
                    }
                }
                // Check if all keywords were found in the file
                for (const auto& pair : search) {
                    if (pair.second == 0) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    selected_files.push_back(file_name);
                }
                Myfile.close();
                flag = 0;
                map[file_name] = count;
            } else {
                cout << "File opening error" << endl;
            }
        } else {
            break;
        }
    }
    
    // Sort the files based on the number of matched keywords
    vector<pair<string, int>> mapVector(map.begin(), map.end());
    sort(mapVector.begin(), mapVector.end(), compareValues);
    
    // Print the results
    for (const auto& p : mapVector) {
        auto result = find(selected_files.begin(), selected_files.end(), p.first);
        if (result != selected_files.end()) {
            cout << p.first << ": " << p.second <<"points"<< endl;
        }
    }
    
    // Print the best file for the job
    if (!mapVector.empty()) {
        cout << mapVector[0].first << " is best for the job" << endl;
    } else {
        cout << "No files matched the specifications" << endl;
    }
    
    return 0;
}
