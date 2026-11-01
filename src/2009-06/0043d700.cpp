// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <map>
#include <vector>
void* __cdecl operator new(unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern long g_trackCount;

struct Base
{
    Base();
    virtual ~Base();

    char reserved04[0x5c];
    int value60;
    char reserved64[0x124];
};

struct sp_counted_base;
struct SharedCount
{
    sp_counted_base* pi_;
    SharedCount() : pi_(0) {}
    ~SharedCount();
};
struct SharedPtr
{
    void* px;
    SharedCount pn;
    SharedPtr() : px(0), pn() {}
};

struct Handle
{
    void* h;
    Handle() : h(0) {}
    ~Handle();
};

struct WeakBase
{
    void* px;
    sp_counted_base* pn;
    WeakBase() { InterlockedIncrement(&g_trackCount); px = 0; pn = 0; }
    ~WeakBase();
};

struct WeakDerived : WeakBase
{
    ~WeakDerived();
};

typedef std::vector<void*> Owner;
typedef std::map<void*,void*> Map;
typedef std::map<int,void*> OtherMap;
typedef std::map<void*,int> FinalMap;
typedef std::map<int,int> LastMap;
struct CPropGrid : Base
{
    CPropGrid();
    virtual ~CPropGrid();

    SharedPtr shared;
    int a, b, c;
    Handle handle;
    int value1a0;
    Owner owner;
    Map map1;
    Map map2;
    OtherMap map3;
    bool flag1;
    FinalMap map4;
    LastMap map5;
    WeakDerived weak;
};

CPropGrid::CPropGrid()
    : a(0), b(0), c(0),
      value1a0(0),
      map1(),
      map2(),
      map3(),
      flag1(false),
      map4(),
      map5()
{
    value60 = 0;
}
