// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_reflectedvectorstring_33341b0adb218553.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
extern void (__thiscall *stringConstruct)(void*, const char*);
extern void (__thiscall *stringDestroy)(void*);

struct String {
    unsigned char storage[28];
    String(const char* text) { stringConstruct(this,text); }
    ~String() { stringDestroy(this); }
};

struct Base {
    unsigned char storage[0x134];
    Base();
    ~Base();
    void setName(const String&);
};

struct Control {
    void* pointer;
    Control();
    ~Control();
};

__forceinline Control::Control() : pointer(0) {}

struct Shared {
    void* object;
    Control control;
    Shared(int);
    ~Shared();
};

__forceinline Shared::Shared(int) : object(0), control() {}

struct Proxy {
    Proxy** pointer;
    unsigned int reserved[2];
    Proxy();
    ~Proxy();
};

__forceinline Proxy::Proxy() {
    Proxy** p = static_cast<Proxy**>(operator new(4));
    if (p)
        *p = this;
    else
        p = 0;
    pointer = p;
}

struct Container {
    Proxy proxy;
    void* first;
    void* last;
    void* end;
    Container();
    ~Container();
};

__forceinline Container::Container()
    : proxy(), first(0), last(0), end(0) {}

struct ClearBackpack : Base {
    Shared shared;
    std::vector<void*> container;
    int initializeTables();
    ClearBackpack();
};

__forceinline int ClearBackpack::initializeTables() {
    *reinterpret_cast<unsigned int*>(storage + 0x00) = 0x830944;
    *reinterpret_cast<unsigned int*>(storage + 0x10) = 0x830934;
    *reinterpret_cast<unsigned int*>(storage + 0x14) = 0x83092c;
    *reinterpret_cast<unsigned int*>(storage + 0x20) = 0x830924;
    *reinterpret_cast<unsigned int*>(storage + 0x24) = 0x830914;
    *reinterpret_cast<unsigned int*>(storage + 0x44) = 0x830904;
    *reinterpret_cast<unsigned int*>(storage + 0x64) = 0x8308f4;
    *reinterpret_cast<unsigned int*>(storage + 0x84) = 0x8308e4;
    *reinterpret_cast<unsigned int*>(storage + 0xa4) = 0x8308d4;
    *reinterpret_cast<unsigned int*>(storage + 0xc4) = 0x8308c4;
    *reinterpret_cast<unsigned int*>(storage + 0x130) = 0x8308bc;
    return 0;
}

ClearBackpack::ClearBackpack()
    : Base(), shared(initializeTables()), container() {
    setName(String("FilteredSelection"));
}
