// from server: 100% by colin
struct seg_00770000
{
    void sub_0077a640();
};

extern "C" void __cdecl sub_0062fc62(void*);

void seg_00770000::sub_0077a640()
{
    void* p = *(void**)0x8a2828;
    *(int*)0x8a2820 = 0x7acf48;
    if (p)
    {
        sub_0062fc62(p);
    }
    *(int*)0x8a2828 = 0;
    *(int*)0x8a282c = 0;
    *(int*)0x8a2830 = 0;
}
