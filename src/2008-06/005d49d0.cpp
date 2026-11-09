// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_d02dc6c2a37b661d.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct String {
    char storage[28];
    String(const char*);
    ~String();
};

extern void (__thiscall* stringConstruct)(String*, const char*);
extern void (__thiscall* stringDestroy)(String*);

typedef boost::shared_ptr<void> Shared;

struct Node {
    Node* find(const String&);
};

Shared __cdecl acquire(void*);

struct S {
    char padding[0x104];
    Node* node;
    void* f();
};

__forceinline String::String(const char* text)
{
    stringConstruct(this, text);
}

__forceinline String::~String()
{
    stringDestroy(this);
}

void* S::f()
{
    Shared result;
    Node* p = node;
    if (p) {
        String name("Right Arm");
        Node* found = node->find(name);
        result = acquire(found ? reinterpret_cast<char*>(found) + 0xe4 : 0);
    }
    return result.get();
}

