// from server: 56% by colin
struct Sub1 {
    char pad[0x104];
    int* begin;
    int* end;
};

struct Sub2 {
    char pad[0xf8];
    int* begin;
    int* end;
};

struct Inner {
    char pad[0x14];
    int field14;
};

struct Outer {
    char pad[0x14];
    Inner inner;
    char pad2[8];
    void* ptr20;
};

struct Target {
    char pad[0x14];
    Inner inner;
    char pad2[8];
    void* ptr20;
    bool method();
};

extern "C" Sub1* __fastcall func_562300(Inner* self, int, int);
extern "C" Sub2* __fastcall func_5618e0(void* self);

bool Target::method()
{
    Sub1* s1 = func_562300(&this->inner, 1, 0);
    int* b = s1->begin;
    if (b == 0)
        return false;
    int* e = s1->end;
    if ((e - b) >> 3 == 0)
        return false;
    void* p = this->ptr20;
    Sub2* s2;
    if (p != 0)
        s2 = func_5618e0(p);
    else
        s2 = 0;
    int* b2 = s2->begin;
    if (b2 == 0)
        return false;
    int* e2 = s2->end;
    if (((e2 - b2) >> 2) != 1)
        return false;
    return true;
}
