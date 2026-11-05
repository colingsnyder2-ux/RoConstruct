// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct ExeBaseA { virtual ~ExeBaseA(); };
struct ExeBaseB { virtual ~ExeBaseB(); };
class Stats : public ExeBaseA, public ExeBaseB {
public:
    int getValue() const;
};
namespace Reflection {
template<class C, class V>
class PropDescriptor {
public:
    enum Functionality { Standard = 7 };
    template<class Getter>
    PropDescriptor(const char* name, const char* category, Getter getter, int setter, Functionality f);
    ~PropDescriptor();
private:
    char data[0x50];
};
}
static Reflection::PropDescriptor<Stats, int> desc_ProcessorTime("ProcessorTime", "PerfCounters", &Stats::getValue, 0, Reflection::PropDescriptor<Stats, int>::Standard);
}
