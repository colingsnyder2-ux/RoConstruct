// from server: 96% by colin
// roc 2007-08 006319e0  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006319e0

struct CXTPCommandBars
{
};

void __cdecl Construct(int a, int b)
{
    struct Local
    {
        void* p;
        int a;
        int b;
        int c;
    } local;

    local.p = (void*)0x7c4ec0;
    local.a = a;
    local.b = b;
    local.c = 0;

    extern void __stdcall Helper(void*, void*);
    Helper(&local, (void*)0x869bec);
}
