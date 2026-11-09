// from server: 100% by king_originala
struct Object;

struct Link {
    unsigned long reserved;
    Link* parent;
};

struct Header {
    unsigned long reserved0;
    unsigned long reserved1;
    unsigned long order;
    char padding[0x280 - 12];
};

struct Object : Header, Link {
};

struct Prefix {
    unsigned long reserved0;
    Object* object;
    unsigned long reserved1;
};

struct Item {
    bool f(Object* first, Object* second, unsigned long unused);
};

struct Owner : Prefix, Item {
};

extern void __cdecl previous(Link**);
extern void __cdecl next(Link**);

bool Item::f(Object* first, Object* second, unsigned long unused)
{
    Object* parent =
        static_cast<Object*>(static_cast<Owner*>(this)->object->parent);
    Link* link;

    if (second != parent) {
        link = static_cast<Link*>(second);
        previous(&link);
        if (first->order < static_cast<Object*>(link)->order)
            return false;
    }

    link = static_cast<Link*>(second);
    next(&link);
    Object* object = static_cast<Object*>(link);

    return object == static_cast<Owner*>(this)->object ||
        object->order >= first->order;
}
