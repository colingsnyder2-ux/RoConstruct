// from server: 100% by king_originala
extern "C" void (__cdecl * const invalid_parameter_noinfo)();

struct Entry {
    void* value;
    void* owner;
};

struct Container {
    char padding[12];
    Entry* begin;
    Entry* end;
};

struct S {
    char padding[0x108];
    Container* items;

    void select(void* value);
    bool f(unsigned int index);
};

bool S::f(unsigned int index)
{
    Container* p = items;
    unsigned int count = p ? static_cast<unsigned int>(p->end - p->begin) : 0;
    if (index <= count) {
        unsigned int position = index - 1;
        if (position >= static_cast<unsigned int>(p->end - p->begin))
            invalid_parameter_noinfo();
        select(p->begin[position].value);
        return true;
    }
    return false;
}
