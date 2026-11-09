// from server: 79% by atomic.potato
extern "C" double sub_00740ba0(double);

struct VAnimationTrack_EventDesc_00740c70 {
    char pad_0000[0xb8];
    double field_00b8;
    double field_00c0;
    double field_00c8;
    double field_00d0;
    void func_00740c70(float a, float b);
};

void VAnimationTrack_EventDesc_00740c70::func_00740c70(float a, float b)
{
    field_00b8 = a;
    field_00c0 = sub_00740ba0(a);
    field_00c8 = a + b;
    field_00d0 = 0.0;
}
