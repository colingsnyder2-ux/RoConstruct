// from server: 100% by colin
#include <intrin.h>
// from server: 85% by colin
// Make this compile to the exact bytes below, then: roc check 2008-06 0045ecc0
//

// from server: 84% by king_originala
// Make this compile to the exact bytes below, then: roc check 2008-06 0045ecc0
//

struct Part0 {
    virtual void slot0();
    char padding[12];
};

struct Part10 {
    virtual void slot10();
};

struct Part14 {
    virtual void slot14();
    char padding[8];
};

struct Part20 {
    virtual void slot20();
};

struct Part24 {
    virtual void slot24();
    char padding[28];
};

struct Part44 {
    virtual void slot44();
    char padding[28];
};

struct Part64 {
    virtual void slot64();
    char padding[28];
};

struct Part84 {
    virtual void slot84();
    char padding[28];
};

struct Parta4 {
    virtual void slota4();
    char padding[28];
};

struct Partc4 {
    virtual void slotc4();
    char padding[104];
};

struct Base : Part0, Part10, Part14, Part20, Part24, Part44, Part64, Part84, Parta4, Partc4 {
    Base();
};

struct S : Base {
    double value;
    unsigned char text[28];
    S();
};

extern void __cdecl func_005ec170(void *);
extern bool __cdecl func_0060a2f0();

typedef void (__cdecl *Fn)(void *);

struct List1 {
    void *a1;
    List1(void *a) : a1(a) {}
};

struct Pair {
    Fn function;
    List1 list;
    Pair(Fn f, const List1 &l) : function(f), list(l) {}
};

inline Pair bind(Fn f, void *a)
{
    return Pair(f, List1(a));
}

inline void *__cdecl operator new(unsigned int, void *p)
{
    return p;
}

extern const char targetTable[];

struct FunctionBase {
    unsigned long state;
    unsigned long padding;
    union { char buffer[8]; } functor;
    FunctionBase() : state(0) {}
};

struct Function : FunctionBase {
    __forceinline Function(Pair f) : FunctionBase()
    {
        assign(f);
    }
    __forceinline void assign(const Pair& f)
    {
        if (!reinterpret_cast<bool (__cdecl *)(Pair *)>(&func_0060a2f0)(const_cast<Pair*>(&f))) {
            new (&functor) Pair(f);
            state = (unsigned long)targetTable;
        } else {
            state = 0;
        }
    }
};

struct Item : S {
    Function target;
    Item(void *);
};

Item::Item(void *argument) : target(bind(&func_005ec170, argument))
{
}
