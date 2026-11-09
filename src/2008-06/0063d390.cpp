// from server: 100% by EspClaude
// from server: 83% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_37f081dfa0d6ed2b.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <boost/signals/connection.hpp>
#include <string>
//

typedef std::string String;

struct Base {
    int data[250];
    Base(int);
    ~Base();
};

extern int table134[];
extern int table420[];
extern int table000[];
extern int table010[];
extern int table014[];
extern int table020[];
extern int table024[];
extern int table044[];
extern int table064[];
extern int table084[];
extern int table0a4[];
extern int table0c4[];
extern int table130[];
extern int table1a0[];
extern int table1c0[];
extern int table1cc[];
extern int virtualTable1[];
extern int virtualTable2[];
extern int virtualTable3[];
extern const char spawnName[];

struct X;
struct Conn0 { char e[4]; boost::shared_ptr<X> con; bool ctrl; Conn0(int) : con(), ctrl(false) {} };
struct Conn : Conn0 { bool released; Conn(int v) : Conn0(v), released(false) {} ~Conn(); };
struct S : Base {
    Conn connection;
    int unk;
    struct P { boost::shared_ptr<X> p1; bool b3; char pad3[3]; bool b4; char pad4[3]; P() : b3(false), b4(false) {} } p;
    double d;
    boost::shared_ptr<X> p2;
    char tail[0x18];

    S(int);
    int prepare(int);
    int initializeTables();
    void fixOffset(int index,int delta) {int offset=((int*)data[0x134/4])[index];*(int*)((char*)this+0x130+offset)=offset-delta;}
    void setName(const String&);
};

__forceinline int S::prepare(int initialize) {
    volatile int constructionState = 0;
    if (initialize) {
        data[0x134 / 4] = reinterpret_cast<int>(table134);
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x438) =
            reinterpret_cast<int>(table420);
    }
    return 0;
}

__forceinline int S::initializeTables() {
    int* table = reinterpret_cast<int*>(data[0x134 / 4]);

    data[0x000 / 4] = reinterpret_cast<int>(table000);
    data[0x010 / 4] = reinterpret_cast<int>(table010);
    data[0x014 / 4] = reinterpret_cast<int>(table014);
    data[0x020 / 4] = reinterpret_cast<int>(table020);
    data[0x024 / 4] = reinterpret_cast<int>(table024);
    data[0x044 / 4] = reinterpret_cast<int>(table044);
    data[0x064 / 4] = reinterpret_cast<int>(table064);
    data[0x084 / 4] = reinterpret_cast<int>(table084);
    data[0x0a4 / 4] = reinterpret_cast<int>(table0a4);
    data[0x0c4 / 4] = reinterpret_cast<int>(table0c4);
    data[0x130 / 4] = reinterpret_cast<int>(table130);
    data[0x1a0 / 4] = reinterpret_cast<int>(table1a0);
    data[0x1c0 / 4] = reinterpret_cast<int>(table1c0);
    data[0x1cc / 4] = reinterpret_cast<int>(table1cc);

    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x134 + table[1]) =
        reinterpret_cast<int>(virtualTable1);
    table = reinterpret_cast<int*>(data[0x134 / 4]);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x134 + table[2]) =
        reinterpret_cast<int>(virtualTable2);
    table = reinterpret_cast<int*>(data[0x134 / 4]);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x134 + table[3]) =
        reinterpret_cast<int>(virtualTable3);

    table=reinterpret_cast<int*>(data[0x134/4]);
    int offset=table[1];
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this)+0x130+offset)=offset-0x2f0;
    fixOffset(2,0x2f8);
    fixOffset(3,0x300);

    return 194;
}

S::S(int initialize)
    : Base(prepare(initialize)),
      connection(initializeTables()),
      p(),
      d(0)
{
    String name("Seat");
    setName(name);
}

