/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/

#include <map> 
#include <vector> 
#include <utility> // for using pairs 
using namespace std;

void search(const vector< pair<int, double> > &nums, const map<int, vector<int> > &numCorpus, map<int, vector<double> > &IDF) {

    bool flag = false;
    vector<double> vecIDF;

    for (const auto& key : numCorpus) {
        for(const auto& num : nums) {
            for(const auto& value : key.second) {
                if(value == num.first) {
                    flag = true;
                    break;
                }
            }
            if (flag == true) {
                vecIDF.push_back(num.second);
            }
            else {
                vecIDF.push_back(0);
            }
            flag = false;
        }
        IDF.insert({key.first, vecIDF});
        vecIDF.clear();
    }
    
}