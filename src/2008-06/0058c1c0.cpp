// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_historydestructorvirtuale799b54806f11459.cpp

// Candidate translation unit (score above; library headers required).
#include <list>
#include <boost/signals/connection.hpp>
extern const unsigned table_831840[];
extern const unsigned table_831850[];
extern const unsigned table_831860[];
extern const unsigned table_831870[];
extern const unsigned table_831880[];
extern const unsigned table_831890[];
extern const unsigned table_8318a0[];
extern const unsigned table_8318a8[];
extern const unsigned table_8318b0[];
extern const unsigned table_8318bc[];
void __cdecl operator delete(void *);

struct B0 { virtual ~B0(); char pad[12]; };
struct B1 { virtual ~B1();  };
struct B2 { virtual ~B2(); char pad[8]; };
struct B3 { virtual ~B3();  };
struct B4 { virtual ~B4(); char pad[28]; };
struct B5 { virtual ~B5(); char pad[28]; };
struct B6 { virtual ~B6(); char pad[28]; };
struct B7 { virtual ~B7(); char pad[28]; };
struct B8 { virtual ~B8(); char pad[28]; };
struct B9 { virtual ~B9(); char pad[108]; };
struct Base : B0,B1,B2,B3,B4,B5,B6,B7,B8,B9 { virtual ~Base(); };

struct Owned {
    ~Owned();
};

typedef boost::signals::scoped_connection Ref;
struct List : std::list<Owned*> { char extra[0x30-sizeof(std::list<Owned*>)]; };

struct S : Base {
    Owned *owned;
    List list;
    Ref first;
    Ref second;
    Ref third;
    ~S();
};

S::~S()
{
    delete owned;
}
