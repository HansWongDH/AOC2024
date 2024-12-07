#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

bool checkRule(vector<int> row, map<int, vector<int>> pattern) {
    for (vector<int>::iterator it = row.begin(); it != row.end(); it++) {
        map<int, vector<int>>::const_iterator search = pattern.find(*it);
        if (search != pattern.end()) {
           const vector<int>& rules =  search->second;
           for (size_t i = 0; i < rules.size(); ++i) {
                auto found_index = find(row.begin(), row.end(), rules[i]);
                
                if (found_index != row.end()) {
                    size_t index_in_row = distance(row.begin(), found_index);
                    if (index_in_row < distance(row.begin(), it)) {
                        return false;
                    }
                }
           }
        }
    }
    return true;
}
vector<int> sortRow(vector<int>& row, const map<int, vector<int>>& orderMap) {
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 0; i < row.size() - 1; ++i) {
            int page1 = row[i];
            int page2 = row[i + 1];
            
            // Check if page1 should come before page2 based on the orderMap
            if (orderMap.find(page1) != orderMap.end() && find(orderMap.at(page1).begin(), orderMap.at(page1).end(), page2) != orderMap.at(page1).end()) {
                // Swap pages if the order is violated
                swap(row[i], row[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
    return row;
}

map<int, vector<int>> getPattern() {
    map<int, vector<int>> dataMap;
    string line;
    ifstream pattern("day5pattern.txt");
    while (getline(pattern, line)) {
        stringstream ss(line);
        int key, value;

        char delimiter;
        ss >> key >> delimiter >> value;

        dataMap[key].push_back(value);
    }
    pattern.close();
    return dataMap;
}


int main() {
    map<int, vector<int>> dataMap = getPattern();
    ifstream input("day5.txt");
        vector<vector<int>> data;
        string line;
        map<int, set<int>> dependencyChains;
        // findDependencies(dataMap, dependencyChains);
        while (getline(input, line)) {
            vector<int> row;
            stringstream ss(line);
            string temp;
            
            while (getline(ss, temp, ',')) {
                row.push_back(stoi(temp));
            }
            if (!checkRule(row, dataMap)) {
                data.push_back(sortRow(row, dataMap));
            }
        }
        input.close();
        int sum = 0;
        for (vector<vector<int>>::iterator it =  data.begin(); it != data.end(); it++){
            vector<int> list = *it;
            sum += list[list.size() / 2];
        }
        cout << sum << endl;
}
