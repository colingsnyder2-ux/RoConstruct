// from server: 89% by Intel
struct VAnimationTrack_EventDesc
{
    void __cdecl func_008f7fb0(float arg1, float arg2);
};

void VAnimationTrack_EventDesc::func_008f7fb0(float arg1, float arg2)
{
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10) != 0)
    {
        int* vtable = *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 8);
        void (__thiscall *func)(int*, float, float) = reinterpret_cast<void (__thiscall*)(int*, float, float)>(vtable[0]);
        func(vtable, arg1, arg2);
    }
}
