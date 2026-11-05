// from server: 77% by atomic.potato
extern "C" double __fastcall func_008F7DD0(float);

struct VAnimationTrack
{
    char pad_0000[0xa8];
    double field_0xa8;
    double field_0xb0;
    double field_0xb8;
    double field_0xc0;

    void func_008F7EA0(float a, float b);
};

void VAnimationTrack::func_008F7EA0(float a, float b)
{
    field_0xa8 = a;
    field_0xb0 = func_008F7DD0(a);
    field_0xb8 = a + b;
    field_0xc0 = 0.0;
}
