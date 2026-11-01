// from server: 100% by king_originala
struct Base {
    char storage[28];
    Base(int);
    ~Base();
};

struct S : Base {
    char cursor[28];
    S(int);
};

extern unsigned long primaryTable[];
extern unsigned long secondaryTable[];

typedef void* (__thiscall *StringConstructor)(void*, const char*);
extern StringConstructor constructString;

S::S(int a1) : Base(a1)
{
    constructString(
        (*(unsigned long**)((char*)this + 0) = primaryTable,
         *(unsigned long**)((char*)this + 4) = secondaryTable,
         cursor),
        "ArrowCursor");
}
