// from server: 100% by colin
extern "C" void __cdecl func_00427c40(int, void*);
extern "C" void __stdcall func_00429060(void*, void*, int, int, void*, void*);

void func_00429220(void* self, void* a, void* b)
{
    func_00427c40(1, a);
    func_00429060(self, a, 0, 0, (void*)0x7c4e6c, b);
}
