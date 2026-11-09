// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_selectionmap_b7ec641d3790ea4e.cpp

// Candidate translation unit (score above; library headers required).
#include <map>

struct Primary {
    virtual ~Primary();
    char padding[0x50];
};

struct Secondary {
    virtual ~Secondary();
    char padding[0x3c];
};

struct Base : Primary, Secondary {
    Base();
    virtual ~Base();
};

typedef std::map<void*, void*> Map;

struct Member {
    int storage[2];
    Member();
    ~Member();
};

struct Content {
    int storage[3];
    Content();
    ~Content();
};

struct S : Base {
    int value;
    Map tree;
    bool flag;
    Member member;
    Content content;

    S();
    virtual ~S();
};

S::S()
    : Base(),
      value(0),
      tree(),
      flag(false),
      member(),
      content()
{
}