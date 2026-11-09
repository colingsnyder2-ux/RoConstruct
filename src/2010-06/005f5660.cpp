// from server: 49% by colin
struct S {
    void f(int* p);
};

extern float g_val;

extern "C" void __cdecl sub_5dda30(float* a, float* b);

void S::f(int* p) {
    float v = g_val;
    float a = v;
    float b = v;
    sub_5dda30(&a, &b);
    float r = a;
    p[0] = *(int*)&r;
    p[1] = *(int*)&r;
}
