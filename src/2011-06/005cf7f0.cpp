// from server: 84% by atomic.potato
struct Elem {
    int value;
};

struct Container {
    char pad0[0x68];
    Elem* begin;
    Elem* end;
};

struct GuiObject {
    char pad0[0x6c];
    Container* container;
    int lookup(int);
};

extern "C" Elem* __stdcall sub_5c2890(int);

int GuiObject::lookup(int idx) {
    Elem* e = sub_5c2890(idx);
    int v = e->value;
    if (v < 0)
        return 0;
    int count = (int)((container->end - container->begin));
    if ((unsigned)v >= (unsigned)count)
        return 0;
    return container->begin[v].value;
}
