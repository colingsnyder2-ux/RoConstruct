// from server: 32% by colin
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl func_004384b0(void*);

struct CStandardOutputView
{
    void* construct();
};

void* CStandardOutputView::construct()
{
    void* p = malloc(0x12c);
    if (p != 0)
    {
        func_004384b0(p);
    }
    return p;
}
