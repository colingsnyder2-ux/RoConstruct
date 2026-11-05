// from server: 75% by atomic.potato
struct VAnimationTrack
{
    char pad[0xb8];
    double field_b8;
    double field_c0;
    double field_c8;
    double field_d0;

    double sub_00740ba0();
    void func_00740cb0(float a, float b, float c);
};

void VAnimationTrack::func_00740cb0(float a, float b, float c)
{
    field_b8 = a;
    field_c0 = sub_00740ba0();
    field_c8 = a + c;
    field_d0 = b;
}
