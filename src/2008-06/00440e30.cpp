// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
extern "C" void* __cdecl runtime_cast(void*, int, const void*, const void*, int);

extern char descriptorBase;
extern char descriptor0;
extern char descriptor1;
extern char descriptor2;
extern char descriptor3;
extern char descriptor4;
extern char descriptor5;
extern char descriptor6;
extern char descriptor7;
extern char descriptor9;
extern char descriptor10;

struct Grid;
struct Owner {
    bool check(void*);
};

struct Property {
    typedef bool (__thiscall *Query)(Property*);
    void** table;
    char padding[8];
    Owner* owner;
    unsigned char flags;
};
extern Property specialProperty;

struct Editor0 {
    char storage[0x144];
    Editor0(void*, Grid*);
};
struct Editor1 {
    char storage[0x130];
    Editor1(void*, Grid*);
};
struct Editor2 {
    char storage[0x130];
    Editor2(void*, Grid*);
};
struct Editor3 {
    char storage[0x13c];
    Editor3(void*, Grid*);
};
struct Editor4 {
    char storage[0x13c];
    Editor4(void*, Grid*);
};
struct Editor5 {
    char storage[0x13c];
    Editor5(void*, Grid*);
};
struct Editor6 {
    char storage[0x138];
    Editor6(void*, Grid*);
};
struct Editor7 {
    char storage[0x134];
    Editor7(void*, Grid*);
};
struct Editor8 {
    char storage[0x130];
    Editor8(void*, Grid*);
};
struct Editor9 {
    char storage[0x130];
    Editor9(void*, Grid*);
};
struct Editor10 {
    char storage[0x130];
    Editor10(void*, Grid*);
};
struct Editor11 {
    char storage[0x130];
    Editor11(void*, Grid*);
};

struct Grid {
    void add0(Editor0*);
    void add3(Editor3*);
    void add3(Editor4*);
    void add6(Editor6*);
    void addOther(Editor1*);
    void addOther(Editor2*);
    void addOther(Editor5*);
    void addOther(Editor7*);
    void addOther(Editor8*);
    void addOther(Editor9*);
    void addOther(Editor10*);
    void addOther(Editor11*);
    void f(void*, Property*);
};

void Grid::f(void* object, Property* property)
{
    if (property->owner->check(object))
        return;
    if (!(property->flags & 1))
        return;

    void* typed = runtime_cast(property, 0, &descriptorBase, &descriptor0, 0);
    if (typed) {
        add0(new Editor0(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor1, 0);
    if (typed) {
        addOther(new Editor1(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor2, 0);
    if (typed) {
        addOther(new Editor2(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor3, 0);
    if (typed) {
        add3(new Editor3(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor4, 0);
    if (typed) {
        add3(new Editor4(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor5, 0);
    if (typed) {
        addOther(new Editor5(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor6, 0);
    if (typed) {
        add6(new Editor6(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor7, 0);
    if (typed) {
        addOther(new Editor7(typed, this));
        return;
    }

    if (property == &specialProperty) {
        addOther(new Editor8(property, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor9, 0);
    if (typed) {
        addOther(new Editor9(typed, this));
        return;
    }

    typed = runtime_cast(property, 0, &descriptorBase, &descriptor10, 0);
    if (typed) {
        addOther(new Editor10(typed, this));
        return;
    }

    if (((Property::Query)property->table[6])(property))
        addOther(new Editor11(property, this));
}
