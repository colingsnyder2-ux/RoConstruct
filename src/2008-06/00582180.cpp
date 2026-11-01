// from server: 100% by king_originala
extern "C" void (__cdecl* invalid_parameter_noinfo)();

struct Container {
    void* owner;
    unsigned char padding[8];
    unsigned* first;
    unsigned* last;
};

struct Object {
    unsigned char padding[0x154];
    Container* container;
};

struct Access {
    Object* get(int);
};

struct Predicate {
    bool (__cdecl* function)(unsigned, void*);
    void* argument;
};

bool __cdecl predicate(unsigned, void*);
unsigned* __cdecl find_match(unsigned*, unsigned*, Predicate);

struct S {
    unsigned char padding[0x14];
    Access access;
    unsigned char reserved[0x0f];
    void* context;

    bool f();
};

bool S::f()
{
    unsigned* volatile iteratorStorage[3];
    struct Saved {
        unsigned* end;
        void* owner;
    } saved;

    Container* c = access.get(1)->container;
    saved.end = c->last;
    if (c->first > saved.end)
        invalid_parameter_noinfo();

    saved.owner = c->owner;
    void* argument = context;

    c = access.get(1)->container;
    unsigned* end = c->last;
    if (c->first > end)
        invalid_parameter_noinfo();

    c = access.get(1)->container;
    unsigned* begin = c->first;
    if (begin > c->last)
        invalid_parameter_noinfo();

    void* owner = c->owner;
    Predicate test = { predicate, argument };
    iteratorStorage[2] = begin;
    unsigned* result = find_match(begin, end, test);

    if (!owner || owner != saved.owner)
        invalid_parameter_noinfo();

    return result != saved.end;
}
