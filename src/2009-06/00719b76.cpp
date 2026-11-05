// from server: 86% by EspClaude
// from server: 100% by colin
// roc 2008-06 006a165b  unit: std::bad_alloc  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006a165b
//
// 006a165b  6a0c                 push 0xc
// 006a165d  68000b9000           push 0x900b00
// 006a1662  e855090000           call 0x6a1fbc
// 006a1667  8365e400             and dword ptr [ebp - 0x1c], 0
// 006a166b  8b750c               mov esi, dword ptr [ebp + 0xc]
// 006a166e  8bc6                 mov eax, esi
// 006a1670  0faf4510             imul eax, dword ptr [ebp + 0x10]
// 006a1674  014508               add dword ptr [ebp + 8], eax
// 006a1677  8365fc00             and dword ptr [ebp - 4], 0
// 006a167b  ff4d10               dec dword ptr [ebp + 0x10]
// 006a167e  780b                 js 0x6a168b
// 006a1680  297508               sub dword ptr [ebp + 8], esi
// 006a1683  8b4d08               mov ecx, dword ptr [ebp + 8]
// 006a1686  ff5514               call dword ptr [ebp + 0x14]
// 006a1689  ebf0                 jmp 0x6a167b
// 006a168b  c745e401000000       mov dword ptr [ebp - 0x1c], 1
// 006a1692  c745fcfeffffff       mov dword ptr [ebp - 4], 0xfffffffe
// 006a1699  e808000000           call 0x6a16a6
// 006a169e  e85e090000           call 0x6a2001
// 006a16a3  c21000               ret 0x10

// from server: 86% by EspClaude
// roc-flags: /O2 /GS /EHsc /MD
// from server: 80% by king_originala
// roc 2008-06 006a165b  unit: std::bad_alloc  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006a165b
//
// 006a165b  6a0c                 push 0xc
// 006a165d  68000b9000           push 0x900b00
// 006a1662  e855090000           call 0x6a1fbc
// 006a1667  8365e400             and dword ptr [ebp - 0x1c], 0
// 006a166b  8b750c               mov esi, dword ptr [ebp + 0xc]
// 006a166e  8bc6                 mov eax, esi
// 006a1670  0faf4510             imul eax, dword ptr [ebp + 0x10]
// 006a1674  014508               add dword ptr [ebp + 8], eax
// 006a1677  8365fc00             and dword ptr [ebp - 4], 0
// 006a167b  ff4d10               dec dword ptr [ebp + 0x10]
// 006a167e  780b                 js 0x6a168b
// 006a1680  297508               sub dword ptr [ebp + 8], esi
// 006a1683  8b4d08               mov ecx, dword ptr [ebp + 8]
// 006a1686  ff5514               call dword ptr [ebp + 0x14]
// 006a1689  ebf0                 jmp 0x6a167b
// 006a168b  c745e401000000       mov dword ptr [ebp - 0x1c], 1
// 006a1692  c745fcfeffffff       mov dword ptr [ebp - 4], 0xfffffffe
// 006a1699  e808000000           call 0x6a16a6
// 006a169e  e85e090000           call 0x6a2001
// 006a16a3  c21000               ret 0x10

typedef void (__thiscall *Destructor)(void *);

extern "C" void __stdcall array_unwind(
    void *ptr, unsigned int size, int count, Destructor destructor);

#pragma optimize("s", on)

void __stdcall vector_destructor(
    void *ptr, unsigned int size, int count, Destructor destructor)
{
    int success = 0;
    ptr = (char *)ptr + size * count;

    __try {
        while (--count >= 0) {
            ptr = (char *)ptr - size;
            destructor(ptr);
        }
        success = 1;
    }
    __finally {
        if (!success)
            array_unwind(ptr, size, count, destructor);
    }
}
