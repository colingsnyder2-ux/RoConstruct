// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Time {
    double sec;
public:
    static Time now();
    bool operator<(const Time& o) const { return sec < o.sec; }
};
class ExeObj {
    char pad[0xe0];
    Time lastTime;
public:
    void touch();
    bool expired();
};
void ExeObj::touch() { lastTime = Time::now(); }
bool ExeObj::expired() { return lastTime < Time::now(); }
}
