// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection {
class FunctionDescriptor
{
public:
    enum Security { None = 0, Plugin = 1 };
};
template<class Class, class Signature, int N>
class BoundFuncDesc
{
    char data[0x50];
public:
    BoundFuncDesc(Signature (Class::*function), const char* name, const char* arg1name, double arg1default, FunctionDescriptor::Security security);
    ~BoundFuncDesc();
};
}
class Instance { public: virtual ~Instance(); };
class Listener { public: virtual ~Listener(); };
class Stats : public Instance, public Listener
{
public:
    int getTimes(double window);
};
static Reflection::BoundFuncDesc<Stats, int(double), 1> func_getTimes(&Stats::getTimes, "GetTimes", "window", 0.0, Reflection::FunctionDescriptor::Plugin);
}
