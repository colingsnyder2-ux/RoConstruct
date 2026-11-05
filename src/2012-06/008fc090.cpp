// from server: 88% by atomic.potato
extern "C" float __stdcall sub_8f82a0(float, float, float);
extern "C" void __stdcall sub_8fbb70(int, int);

struct S {
    void f(float, float, float);
};

void S::f(float a, float b, float c) {
    float r = sub_8f82a0(c, b, a);
    sub_8fbb70((int)this, *(int*)&r);
}
