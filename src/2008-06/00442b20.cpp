// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_propgridcontainers_fdf37cf8a5e473bb.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <vector>
void* __cdecl operator new(unsigned int);

struct Base
{
    Base();
    virtual ~Base();

    char reserved04[0x5c];
    int value60;
    char reserved64[0x124];
};

struct __declspec(novtable) Interface
{
    virtual void interfaceFunction() = 0;
};

struct Resource
{
    Resource();
    ~Resource();
    char data[12];
};

typedef std::vector<void*> Owner;
typedef std::map<void*,void*> Map;
typedef Map OtherMap;
typedef Map FinalMap;
struct CPropGrid : Base, Interface
{
    CPropGrid();
    virtual ~CPropGrid();
    virtual void interfaceFunction();

    Resource resource;
    int value198;
    Owner owner;
    Map map1;
    Map map2;
    bool flag1;
    bool flag2;
    OtherMap map3;
    FinalMap map4;
};

CPropGrid::CPropGrid()
    : value198(0),
      map1(),
      map2(),
      flag1(false),
      flag2(false),
      map3(),
      map4()
{
    value60 = 0;
}