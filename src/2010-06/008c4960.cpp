// from server: 100% by atomic.potato
struct ViewRbxGfx_InitModule
{
    void *field0;
    char pad[4];
    void *field8;
    void *fieldC;
    void ViewRbxGfxFactory(int a, int b);
};

extern "C" bool __cdecl func_006f7750(void *p);

void ViewRbxGfx_InitModule::ViewRbxGfxFactory(int a, int b)
{
    int local[2];
    local[0] = a;
    local[1] = b;

    if (!func_006f7750(local))
    {
        void *p = (char *)this + 8;
        if (p)
        {
            *(int *)p = local[0];
            *(int *)((char *)p + 4) = local[1];
        }
        *(int *)this = 0x00bfa38c;
        return;
    }

    *(int *)this = 0;
}
