// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_aa1722ad196cb510.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <boost/shared_ptr.hpp>

struct Listener1 { char storage[36]; };
struct Listener2 { char storage[36]; };
struct Signal { char storage[32]; void disconnect(Listener1*); void connect(Listener1&); };
struct Signal2 { char storage[32]; void disconnect(Listener2*); void connect(Listener2&); };
struct Instance { char padding[100]; Signal first; Signal2 second; };

boost::shared_ptr<Instance> __cdecl acquire(void*);

struct Service { void reset(); };
struct Window {
    virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void s8();virtual void s9();
    virtual void s10();virtual void s11();virtual void s12();virtual void s13();virtual void s14();virtual void s15();virtual void s16();virtual void s17();virtual void s18();virtual void s19();
    virtual void s20();virtual void s21();virtual void s22();virtual void s23();virtual void s24();virtual void s25();virtual void s26();virtual void s27();virtual void s28();virtual void s29();
    virtual void s30();virtual void s31();virtual void s32();virtual void s33();virtual void s34();virtual void s35();virtual void s36();virtual void s37();virtual void s38();virtual void s39();
    virtual void s40();virtual void s41();virtual void s42();virtual void s43();virtual void s44();virtual void s45();virtual void s46();virtual void s47();virtual void s48();virtual void s49();
    virtual void s50();virtual void s51();virtual void s52();virtual void s53();virtual void s54();virtual void s55();virtual void s56();virtual void s57();virtual void s58();virtual void s59();
    virtual void s60();virtual void s61();virtual void s62();virtual void s63();virtual void s64();virtual void s65();virtual void s66();virtual void s67();virtual void s68();virtual void s69();
    virtual void s70();virtual void s71();virtual void s72();virtual void s73();virtual void s74();virtual void s75();virtual void s76();virtual void s77();virtual void s78();virtual void s79();
    virtual void s80();virtual void s81();virtual void s82();virtual void s83();virtual void s84();virtual void s85();virtual void s86();virtual void s87();
    virtual void refresh();
    char padding[228];
    Service* service;
};

struct FlagGuard {
    unsigned char* flag; unsigned char previous;
    FlagGuard(unsigned char& v) : flag(&v), previous(v) { v = 1; }
    ~FlagGuard() { *flag = previous; }
};

struct ExplorerTable { void* slots[101]; Window* (__thiscall* getWindow)(void*); };
struct ExplorerBase { ExplorerTable* table; char padding[884]; };

struct Explorer : ExplorerBase, Listener1, Listener2
{
    boost::shared_ptr<Instance> instance;
    unsigned char changing;
    Window* getWindow() { return table->getWindow(this); }
    void setInstance(void*);
};

inline void disconnect1(const boost::shared_ptr<Instance>& i, Listener1* l) { if (i) i->first.disconnect(l); }
inline void disconnect2(const boost::shared_ptr<Instance>& i, Listener2* l) { if (i) i->second.disconnect(l); }
inline void connect1(Instance* i, Listener1& l) { if (i) i->first.connect(l); }
inline void connect2(Instance* i, Listener2& l) { if (i) i->second.connect(l); }
void Explorer::setInstance(void* argument)
{
    FlagGuard guard(changing);
    disconnect1(instance, this);
    disconnect2(instance, this);
    getWindow()->service->reset();
    instance = acquire(argument);
    connect1(instance.get(), *this);
    connect2(instance.get(), *this);
    Window* window = getWindow();
    window->refresh();
}
