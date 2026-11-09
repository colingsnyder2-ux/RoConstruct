// from server: 100% by Intel
extern "C" void __stdcall func_00A951CE(int);
extern "C" void __cdecl func_00982114(void*);

struct CSelectionPropGrid
{
    static void __cdecl f(void* p);
};

void __cdecl CSelectionPropGrid::f(void* p)
{
    if (p)
    {
        func_00A951CE(*(int*)p);
        func_00982114(p);
    }
}
