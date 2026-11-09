// from server: 66% by colin
struct seg_00860000
{
    void m();
};

void seg_00860000::m()
{
    void (*p)() = (void (*)())0xE424E900;
    p();
}
