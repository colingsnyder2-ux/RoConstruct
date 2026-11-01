// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace RBX {
class Time {
public:
    double sec;
    Time() : sec(0) {}
    explicit Time(double s) : sec(s) {}
    static Time now();
    Time operator+(double d) const { return Time(sec + d); }
};
class Item2009 {
public:
	std::string name;
	Time expire;
	Item2009(const char* n);
};
Item2009::Item2009(const char* n) : name(n), expire(Time::now() + 300.0) {}
}
