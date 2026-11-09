// from server: 100% by king_originala
struct Object;

struct Link {
    Object* first;
    Object* second;
    Object* third;
};

struct Object {
    char padding[0x280];
    Link link;
    void release();
};

struct Prefix {
    unsigned long reserved0;
    Object* object;
    unsigned long reserved1;
};

struct Item {
    unsigned long reserved;
    void f(Object* value);
};

struct Owner : Prefix, Item {
};

extern void __cdecl update(Link*, Link*, Object**, Object**);

void Item::f(Object* value)
{
    Object* third = static_cast<Owner*>(this)->object;
    Object* second = static_cast<Owner*>(this)->object;
    Link* first = &static_cast<Owner*>(this)->object->link;
    Link* incoming = value ? &value->link : 0;

    update(incoming, first, &second->link.second, &third->link.third);
    value->release();
}
