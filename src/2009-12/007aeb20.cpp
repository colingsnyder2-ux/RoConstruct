// from server: 100% by atomic.potato
extern "C" void G1_func_007d8e50();

struct Humanoid
{
    int pad_0[6];
    int field_18;
    int field_1c;
    int field_20;
    Humanoid* f();
};

Humanoid* Humanoid::f()
{
    G1_func_007d8e50();
    field_18 = 0;
    field_1c = 0;
    field_20 = 0;
    *(int*)this = 0x9ede0c;
    return this;
}
