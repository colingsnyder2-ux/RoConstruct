// from server: 100% by EspClaude
// from server: 81% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_5e226d55ea09768e.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <string>
#include <memory>
struct String { char storage[28]; __declspec(dllimport) ~String(); __declspec(dllimport) const char* c_str() const; };
struct OwnerBase {
    void* proxy;
    OwnerBase();
    ~OwnerBase();
};
struct Owner : OwnerBase {
    unsigned int reserved[2];
    unsigned int first;
    unsigned int last;
    unsigned int end;
    Owner();
    ~Owner();
};

typedef std::auto_ptr<Owner> Holder;

struct Runner {
    Holder run(int, const char*, const char*, Owner*);
};

struct Model {
    Runner* runner();
};

typedef boost::shared_ptr<Model> Result;
struct Returned : Result {};

struct Lock {
    unsigned char storage[12];
    Lock(Result);
    ~Lock();
};

struct Source {
    void copy(Result*);
};

struct S {
    unsigned char padding[0x94];
    Source* source;
    Returned f();
    int execute(String);
};

inline OwnerBase::OwnerBase()
{
    void** p = new void*(this);
    proxy = p;
}

void lengthError();
inline void checkCapacity(unsigned int count)
{
    if (count > 0x3fffffff)
        lengthError();
}

inline Owner::Owner()
{
    checkCapacity(0);
    first = 0;
    last = 0;
    end = 0;
}


int S::execute(String text)
{
    Lock lock(f());
    Owner owner;
    try {
        f()->runner()->run(1, text.c_str(), "Doc script", &owner);
        return 1;
    }
    catch (...) {
        return 0;
    }
}

