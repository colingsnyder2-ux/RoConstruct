// from server: 100% by Xemicl
// from server: 95% by Intel
// roc 2012-06 004b59b0  unit: VCWorkspace::?$CComObject  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004b59b0
//
// 004b59b0  56                   push esi
// 004b59b1  8bf1                 mov esi, ecx
// 004b59b3  837e4000             cmp dword ptr [esi + 0x40], 0
// 004b59b7  7418                 je 0x4b59d1
// 004b59b9  8b4644               mov eax, dword ptr [esi + 0x44]
// 004b59bc  50                   push eax
// 004b59bd  ff151051b200         call dword ptr [0xb25110]
// 004b59c3  c7464000000000       mov dword ptr [esi + 0x40], 0
// 004b59ca  c7464400000000       mov dword ptr [esi + 0x44], 0
// 004b59d1  8b463c               mov eax, dword ptr [esi + 0x3c]
// 004b59d4  85c0                 test eax, eax
// 004b59d6  740f                 je 0x4b59e7
// 004b59d8  8b08                 mov ecx, dword ptr [eax]
// 004b59da  8b5108               mov edx, dword ptr [ecx + 8]
// 004b59dd  50                   push eax
// 004b59de  ffd2                 call edx
// 004b59e0  c7463c00000000       mov dword ptr [esi + 0x3c], 0
// 004b59e7  5e                   pop esi
// 004b59e8  c3                   ret 

extern "C" __declspec(dllimport) void __stdcall CoTaskMemFree(void *pv);

struct VCWorkspace_CComObject
{
    void ReleaseResources();
};

void VCWorkspace_CComObject::ReleaseResources()
{
    if (*reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 0x40) != 0)
    {
        void *ptr = *reinterpret_cast<void **>(reinterpret_cast<char *>(this) + 0x44);
        CoTaskMemFree(ptr);
        *reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 0x40) = 0;
        *reinterpret_cast<void **>(reinterpret_cast<char *>(this) + 0x44) = 0;
    }

    void *obj = *reinterpret_cast<void **>(reinterpret_cast<char *>(this) + 0x3C);
    if (obj != 0)
    {
        void *vtable = *reinterpret_cast<void **>(obj);
        void (__stdcall *release)(void *) = *reinterpret_cast<void (__stdcall **)(void *)>(reinterpret_cast<char *>(vtable) + 8);
        release(obj);
        *reinterpret_cast<void **>(reinterpret_cast<char *>(this) + 0x3C) = 0;
    }
}
