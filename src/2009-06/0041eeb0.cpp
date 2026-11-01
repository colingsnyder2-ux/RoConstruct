// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
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
    int a, b, c, d;
    Content() : a(0), b(0), c(0), d(0) {}
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
