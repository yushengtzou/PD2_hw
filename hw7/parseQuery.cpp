/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

void parseQuery(char* &query, unordered_map<int, vector<string> > &q) { 
    // 宣告一個ifstream型別的物件infile
    ifstream infile;
    // 開啟當前目錄下名為corpus的檔案
    infile.open(query);
    if (!infile) {
        cerr << "error: unable to open the input file: " << query << endl;
    }

    string line, field;
    int key = 1;

    // 將檔案中的資料存入vector<Employee> employees
    while (getline(infile, line)) {
        istringstream ss(line); // 將ss綁定至讀取行
        vector<string> fields;
        // 將每一行的單字取出
        while (getline(ss, field, ' ')) { 
            transform(field.begin(), field.end(), field.begin(), ::tolower);
            fields.push_back(field);
        }
        q.insert({key, fields});
        key++;
    }
    
    infile.close();    
    // for (auto it = q.begin(); it != q.end(); ++it) {
    //     cout << "Key: " << it->first << ", Value: ";
    //     for (const auto& str : it->second) {
    //         cout << str << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "Read query.txt success" << endl;
}

