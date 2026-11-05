// from server: 81% by atomic.potato
struct VAnimationTrack_EventDesc
{
    char pad[0xc0];
    double field_c0;
    double field_c8;
    double field_d0;
    double field_d8;
    void sub_006fe000(float a, float b);
};

extern "C" double __fastcall sub_006fdf30(double);

void VAnimationTrack_EventDesc::sub_006fe000(float a, float b)
{
    field_c0 = a;
    field_c8 = sub_006fdf30(a);
    field_d0 = a + b;
    field_d8 = 0.0;
}
