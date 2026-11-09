// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_selectionctorstring16d652bca095ce61.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
extern const unsigned table_82ed28[];
extern const unsigned table_82ed34[];
extern const unsigned table_82ed44[];
extern const unsigned table_82ed54[];
extern const unsigned table_82ed64[];
extern const unsigned table_82ed74[];
extern const unsigned table_82ed84[];
extern const unsigned table_82ed94[];
extern const unsigned table_82eda4[];
extern const unsigned table_82edac[];
extern const unsigned table_82edb4[];
extern const unsigned table_82edc4[];
// from server: 85% by king_originala
typedef unsigned int Word;

void* __cdecl operator new(unsigned int);

struct String;
extern void (__thiscall *stringConstruct)(String*,const char*);
extern void (__thiscall *stringDestroy)(String*);
struct String { unsigned storage[7];
 String(const char* text) { stringConstruct(this,text); }
 ~String() { stringDestroy(this); }
};
struct Base {
    char storage[0x130];
    Base();
    ~Base();
    void setValue(const String&);
};

struct Part {
    char storage[0x20];
    Part();
    ~Part();
};

namespace RBX { class Instance; }
typedef std::vector<boost::shared_ptr<RBX::Instance> > List;

struct Holder {
    char storage[8];
    Holder(const List&);
    ~Holder();
};

struct S : Base {
    Part part;
    Word table150;
    Holder holder;
    List list;

    S();
    void initializeTables();
};

__forceinline void S::initializeTables()
{
    *reinterpret_cast<Word*>(reinterpret_cast<char*>(this) + 0x000) = reinterpret_cast<Word>(table_82edc4);
    *reinterpret_cast<Word*>(reinterpret_cast<char*>(this) + 0x010) = reinterpret_cast<Word>(table_82edb4);
    *reinterpret_cast<Word*>(reinterpret_cast<char*>(this) + 0x014) = reinterpret_cast<Word>(table_82edac);
    *reinterpret_cast<Word*>(reinterpret_cast<char*>(this) + 0x020) = reinterpret_cast<Word>(table_82eda4);
    *reinterpret_cast<Word*>(reinterpret_cast<char*>(this) + 0x024) = reinterpret_cast<Word>(table_82ed94);
    *reinterpret_cast<Word*>(reinterpret_cast<char*>(this) + 0x044) = reinterpret_cast<Word>(table_82ed84);
    *reinterpret_cast<Word*>(reinterpret_cast<char*>(this) + 0x064) = reinterpret_cast<Word>(table_82ed74);
    *reinterpret_cast<Word*>(reinterpret_cast<char*>(this) + 0x084) = reinterpret_cast<Word>(table_82ed64);
    *reinterpret_cast<Word*>(reinterpret_cast<char*>(this) + 0x0a4) = reinterpret_cast<Word>(table_82ed54);
    *reinterpret_cast<Word*>(reinterpret_cast<char*>(this) + 0x0c4) = reinterpret_cast<Word>(table_82ed44);
    *reinterpret_cast<Word*>(&part) = reinterpret_cast<Word>(table_82ed34);
    table150 = reinterpret_cast<Word>(table_82ed28);
}

S::S()
    : Base(), part(), holder((initializeTables(), List())), list()
{
    setValue(String("Selection"));
}
