/*  鄒雨笙 F64081070 程式設計二 第5次作業 2023/5/15

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

void setResults(map<int, map<int, vector<bool> > > &results, map<int, vector<int> > &processedResults) {

    for (auto it : results) {
        vector<int> resultsList;
        for (auto it_map : it.second) {
            // cout << "Processing query " << it->first << ", corpus " << it_map->first << ", first result " << (it_map->second).at(0) << "\n";

            bool flag = true;
            for (auto value : it_map.second) {
                if ( value == false ) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                resultsList.push_back(it_map.first);
            }

        }
        processedResults.insert({it.first, resultsList});
    }
}
