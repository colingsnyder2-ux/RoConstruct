// from server: 100% by atomic.potato
extern "C" void __cdecl ViewRbxGfxFactory_Fallback(int, void *, int);

struct ViewRbxGfx_InitModule
{
};

void __cdecl ViewRbxGfxFactory(int a, void *p, int type)
{
    if (type != 4)
    {
        ViewRbxGfxFactory_Fallback(a, p, type);
        return;
    }

    *(int *)p = 0x00bfa2b8;
    ((unsigned char *)p)[4] = 0;
    ((unsigned char *)p)[5] = 0;
}
