// from server: 52% by atomic.potato
struct S {
    char pad[0x1c];
    int field1c;
    void method(int);
};

extern "C" void __stdcall sub_676890(int*, int);
extern "C" void __stdcall sub_699900(int*, int*, float*);

extern float g_float_a4c938;

void S::method(int arg) {
    int local;
    sub_676890(&local, arg);
    float f = g_float_a4c938;
    sub_699900(&field1c, &local, &f);
}
