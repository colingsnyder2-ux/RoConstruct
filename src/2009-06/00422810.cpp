// from server: 100% by why2
extern "C" void* (__stdcall *GetProcessHeap)();
extern "C" int (__stdcall *HeapFree)(void*, unsigned long, void*);

void __cdecl func_00422810(void* p)
{
    HeapFree(GetProcessHeap(), 0, p);
}
