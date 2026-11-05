// from server: 46% by colin
// roc 2007-08 0064b4af  unit: CXTPImageManagerIcon  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0064b4af
//
// 0064b4af  33db                 xor ebx, ebx
// 0064b4b1  885dfc               mov byte ptr [ebp - 4], bl
// 0064b4b4  e86bcf0e00           call 0x738424
// 0064b4b9  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 0064b4bc  3bc3                 cmp eax, ebx
// 0064b4be  740a                 je 0x64b4ca
// 0064b4c0  50                   push eax
// 0064b4c1  ff15c4e67700         call dword ptr [0x77e6c4]
// 0064b4c7  83c404               add esp, 4
// 0064b4ca  8b45e4               mov eax, dword ptr [ebp - 0x1c]
// 0064b4cd  3bc3                 cmp eax, ebx
// 0064b4cf  740a                 je 0x64b4db
// 0064b4d1  50                   push eax
// 0064b4d2  ff15c4e67700         call dword ptr [0x77e6c4]
// 0064b4d8  83c404               add esp, 4
// 0064b4db  8d4dc0               lea ecx, [ebp - 0x40]
// 0064b4de  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0064b4e5  e8f2ce0e00           call 0x7383dc
// 0064b4ea  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 0064b4ed  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0064b4f0  64890d00000000       mov dword ptr fs:[0], ecx
// 0064b4f7  59                   pop ecx
// 0064b4f8  5f                   pop edi
// 0064b4f9  5e                   pop esi
// 0064b4fa  5b                   pop ebx
// 0064b4fb  8be5                 mov esp, ebp
// 0064b4fd  5d                   pop ebp
// 0064b4fe  c3                   ret 

extern "C" void __cdecl free(void*);

extern "C" void __cdecl sub_738424();
extern "C" void __cdecl sub_7383DC();

struct CXTPImageManagerIcon
{
    void Cleanup();
};

void CXTPImageManagerIcon::Cleanup()
{
    void* p1;
    void* p2;

    sub_738424();

    p1 = *(void**)((char*)this - 0x18);
    if (p1 != 0)
    {
        free(p1);
    }

    p2 = *(void**)((char*)this - 0x1c);
    if (p2 != 0)
    {
        free(p2);
    }

    sub_7383DC();
}
