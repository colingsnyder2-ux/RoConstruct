// from server: 100% by EspClaude
#include <list>
#include <algorithm>
struct Time {
    unsigned long low;
    unsigned long high;
    unsigned __int64 value() const { return low | ((unsigned __int64)high << 32); }
};
inline bool operator<(Time a, Time b) { return a.value() < b.value(); }
struct Entry {
    unsigned long tag;
    Time time;
    unsigned long padding[75];
    double alignment;
};
struct After {
    Time limit;
    bool operator()(Entry e) const { return limit < e.time; }
};
std::list<Entry>::iterator findBoundary(std::list<Entry>& l, Time limit)
{
    After a; a.limit = limit;
    return std::find_if(l.begin(), l.end(), a);
}
