// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Item {
    unsigned int first;
    unsigned int second;
};

struct Selection {
    char padding[12];
    Item* begin;
    Item* end;
};

struct Root {
    char padding[0x154];
    Selection* selection;
};

struct Handle {
    char padding[12];
    Root* get(int);
};

extern bool __cdecl predicate(void*);

struct Target {
    int check(bool (__cdecl*)(void*));
};

struct Provider {
    Target* get();
};

struct S {
    char padding[0x14];
    Handle handle;
    Provider* provider;
    bool f();
};

bool S::f()
{
    Selection* selection = handle.get(1)->selection;
    if (static_cast<unsigned int>(selection->end - selection->begin) <= 0)
        return false;

    Target* target = provider ? provider->get() : 0;
    return target->check(predicate) != 0;
}
