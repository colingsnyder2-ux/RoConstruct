// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Time {
public:
    double sec;
    static Time now();
    bool operator<(const Time& o) const { return sec < o.sec; }
    bool operator>(const Time& o) const { return sec > o.sec; }
    bool operator>=(const Time& o) const { return sec >= o.sec; }
    bool operator<=(const Time& o) const { return sec <= o.sec; }
};
class ExeObj {
    char pad[0xe0];
    Time lastTime;
public:
    bool expired();
};
bool ExeObj::expired() { return Time::now() > lastTime; }
}
