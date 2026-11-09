// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc 2008-06 0064ce40  (agentH rewrite)

#include <set>

struct Object {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void apply(int);
};

struct S {
    char padding0[16];
    std::set<Object*> objects;
    void f(int);
};

void S::f(int argument)
{
    for (std::set<Object*>::iterator it = objects.begin(); it != objects.end(); ++it)
        (*it)->apply(argument);
}
