// from server: 100% by king_originala
extern "C" void* __cdecl initialType();
extern "C" void* __cdecl firstType();
extern "C" void* __cdecl secondType();
extern "C" void* __cdecl convertValue(void*, int);

struct Value {
    void* type;
    void assign(void*, void*, void*);
};

struct S {
    char padding0[0x14];
    Value value;
    char padding1[0x2c];
    char first[8];
    char second[8];

    void f(void*, void*);
};

void S::f(void* a, void* b)
{
    value.type = initialType();
    value.assign(convertValue(a, -1), firstType(), first);
    value.assign(convertValue(b, -1), secondType(), second);
}
