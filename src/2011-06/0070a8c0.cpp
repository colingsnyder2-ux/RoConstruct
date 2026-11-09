// from server: 64% by atomic.potato
struct Vec3 { float x; float y; float z; };

struct Inner {
    char pad0[4];
    Vec3 v;
};

struct Outer {
    char pad0[4];
    Inner* p;
};

extern "C" float* __stdcall sub_4191e0(void*);
extern "C" float* __stdcall sub_5c5430(void*);

struct S {
    void sub_70a7e0(float, float, float);
    void f(Outer* o);
};

void S::f(Outer* o)
{
    float a = *sub_4191e0((char*)o->p + 8);
    float b = *sub_4191e0((char*)o->p + 4);
    float c = *sub_5c5430(o->p);
    sub_70a7e0(c, b, a);
}
