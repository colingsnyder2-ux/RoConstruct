// from server: 35% by atomic.potato
struct S_007d7ca0 {
    void f(float, float, float);
};

extern "C" void call_007d7b30(S_007d7ca0*, float*);

void S_007d7ca0::f(float a, float b, float c)
{
    float v[3];
    v[0] = a;
    v[1] = b;
    v[2] = c;
    call_007d7b30(this + 1, v);
}
