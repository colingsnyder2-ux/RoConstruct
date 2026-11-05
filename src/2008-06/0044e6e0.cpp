// from server: 100% by king_originala
typedef void (__thiscall *DestroyFunction)(void *);
extern DestroyFunction destroyElement;
void __cdecl operator delete(void *);

struct Element {
    unsigned char data[8];
    unsigned char value[4];
};

struct S {
    unsigned char padding[12];
    Element *first;
    Element *last;
    Element *limit;

    void clear();
};

void S::clear()
{
    if (first) {
        Element *p = first;
        Element *end = last;
        for (; p != end; ++p)
            destroyElement(p->value);
        operator delete(first);
    }
    first = 0;
    last = 0;
    limit = 0;
}
