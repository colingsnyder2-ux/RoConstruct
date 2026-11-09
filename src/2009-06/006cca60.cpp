// from server: 100% by tester
struct S_func_005fe120 {
    float* f();
};

float* S_func_005fe120::f()
{
    static unsigned int init = 0;
    static float a;
    static float b;
    static float c;
    if (!(init & 1)) {
        init |= 1;
        a = 1.0f;
        b = *(float*)0x7aa8b4;
        c = a;
    }
    return &a;
}
