// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_servicemaps_c19cbf574de4de42.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <vector>
// from server: 93% by king_originala
extern void* __cdecl G_006a0920(unsigned int);

struct Tag
{
    Tag();
};

__forceinline Tag::Tag()
{
}

struct Base
{
    unsigned int storage[11];
    Base(const char*, const void*);
    virtual ~Base();
};

typedef std::map<int,int> Map;

typedef std::vector<void*> Vector;

struct S : Base
{
    Map map1;
    Map map2;
    Vector vector1;
    Vector vector2;
    Vector vector3;
    Vector vector4;
    Vector vector5;

    S();
    virtual ~S();
    void G_0064d530(int, const char*);
};

S::S()
    : Base("EnviromentalPhysicsThrottle",
           reinterpret_cast<const void*>(0x9452a0)),
      map1(),
      map2(),
      vector1(),
      vector2(),
      vector3(),
      vector4(),
      vector5()
{
    G_0064d530(0, "DefaultAuto");
    G_0064d530(1, "Disabled");
    G_0064d530(2, "Random");
    G_0064d530(3, "Always");
}
