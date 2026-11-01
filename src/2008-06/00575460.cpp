// from server: 100% by king_originala
extern "C" void* __cdecl getType();
extern "C" void* __cdecl getOtherType();
extern "C" const char* __cdecl convert(const char*, int);

struct Value {
    void* type;
    char padding[40];
    void set(const char*, void*, void*);
};

struct S {
    char padding[20];
    Value value;
    char first[8];
    char second[8];
    char third[8];

    void f(const char*, const char*, const char*);
};

void S::f(const char* a, const char* b, const char* c)
{
    value.type = getType();
    value.set(convert(a, -1), getType(), first);
    value.set(convert(b, -1), getType(), second);
    value.set(convert(c, -1), getOtherType(), third);
}
