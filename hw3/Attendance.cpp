/*  鄒雨笙 F64081070 程式設計二 第3次作業 2023/4/11
    
*/
#include "Attendance.h"
#include "Record.h"

void Attendance::setRecord(int conWorkday, std::string &startDay, std::string &endDay) {
    Record record(conWorkday, startDay, endDay);
    conDayRecord.push_back(record);
}


