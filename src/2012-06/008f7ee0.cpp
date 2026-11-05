// from server: 80% by atomic.potato
extern "C" double __fastcall func_008f7dd0(double);

struct VAnimationTrack_EventDesc
{
    char pad[0xa8];
    double field_a8;
    double field_b0;
    double field_b8;
    double field_c0;

    void func_008f7ee0(float a, float b, float c);
};

void VAnimationTrack_EventDesc::func_008f7ee0(float a, float b, float c)
{
    field_a8 = a;
    field_b0 = func_008f7dd0(a);
    field_b8 = a + c;
    field_c0 = b;
}
