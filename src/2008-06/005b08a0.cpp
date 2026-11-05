// from server: 100% by king_originala
typedef void (__thiscall *StringCtor)(void*, const char*);
typedef void (__thiscall *StringDtor)(void*);

extern StringCtor stringCtor;
extern StringDtor stringDtor;
extern char instanceType;
extern char partType;

extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

struct String {
    char storage[28];
    String(const char* text) { stringCtor(this, text); }
    ~String() { stringDtor(this); }
};

struct S {
    void* find(const String&);
    void* f();
};

void* S::f()
{
    String name("Handle");
    return __RTDynamicCast(find(name), 0, &instanceType, &partType, 0);
}
