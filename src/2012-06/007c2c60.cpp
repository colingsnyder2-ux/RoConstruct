// from server: 70% by atomic.potato
extern "C" bool __fastcall sub_751850(void *);

struct S
{
    void *field_84;
    bool f();
};

bool S::f()
{
    extern unsigned char g_00e31abe;
    if (g_00e31abe)
        return true;
    return sub_751850((char *)field_84 + *(unsigned int *)field_84 + 0x84);
}
