// from server: 100% by king_originala
extern "C" void __cdecl advance_link(char**);
extern "C" void __cdecl release_node(char*);

struct Iterator {
    char* node;
};

struct S {
    char padding[36];
    unsigned count;

    void erase_node(char*);
    Iterator f(Iterator);
};

struct Owner {
    char prefix[12];
    S part;
};

Iterator S::f(Iterator position)
{
    char* original = position.node;
    char* link = original ? original + 96 : 0;
    advance_link(&link);
    position.node = link ? link - 96 : 0;

    Owner* owner = this
        ? reinterpret_cast<Owner*>(reinterpret_cast<char*>(this) - 12)
        : 0;

    owner->part.erase_node(original);
    release_node(original);
    --owner->part.count;
    return position;
}
