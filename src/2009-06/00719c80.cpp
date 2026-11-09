// from server: 86% by EspClaude
// from server: 100% by colin
// roc 2008-06 006a1598  unit: std::bad_alloc  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006a1598
//
// 006a1598  6a10                 push 0x10
// 006a159a  68c00a9000           push 0x900ac0
// 006a159f  e8180a0000           call 0x6a1fbc
// 006a15a4  33c0                 xor eax, eax
// 006a15a6  8945e0               mov dword ptr [ebp - 0x20], eax
// 006a15a9  8945fc               mov dword ptr [ebp - 4], eax
// 006a15ac  8945e4               mov dword ptr [ebp - 0x1c], eax
// 006a15af  8b45e4               mov eax, dword ptr [ebp - 0x1c]
// 006a15b2  3b4510               cmp eax, dword ptr [ebp + 0x10]
// 006a15b5  7d13                 jge 0x6a15ca
// 006a15b7  8b7508               mov esi, dword ptr [ebp + 8]
// 006a15ba  8bce                 mov ecx, esi
// 006a15bc  ff5514               call dword ptr [ebp + 0x14]
// 006a15bf  03750c               add esi, dword ptr [ebp + 0xc]
// 006a15c2  897508               mov dword ptr [ebp + 8], esi
// 006a15c5  ff45e4               inc dword ptr [ebp - 0x1c]
// 006a15c8  ebe5                 jmp 0x6a15af
// 006a15ca  c745e001000000       mov dword ptr [ebp - 0x20], 1
// 006a15d1  c745fcfeffffff       mov dword ptr [ebp - 4], 0xfffffffe
// 006a15d8  e808000000           call 0x6a15e5
// 006a15dd  e81f0a0000           call 0x6a2001
// 006a15e2  c21400               ret 0x14

// from server: 86% by EspClaude
// from server: 78% by colin
// roc-flags: /O2 /GS /MD
// roc 2008-06 006a1598  unit: std::bad_alloc  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006a1598
//
// 006a1598  6a10                 push 0x10
// 006a159a  68c00a9000           push 0x900ac0
// 006a159f  e8180a0000           call 0x6a1fbc
// 006a15a4  33c0                 xor eax, eax
// 006a15a6  8945e0               mov dword ptr [ebp - 0x20], eax
// 006a15a9  8945fc               mov dword ptr [ebp - 4], eax
// 006a15ac  8945e4               mov dword ptr [ebp - 0x1c], eax
// 006a15af  8b45e4               mov eax, dword ptr [ebp - 0x1c]
// 006a15b2  3b4510               cmp eax, dword ptr [ebp + 0x10]
// 006a15b5  7d13                 jge 0x6a15ca
// 006a15b7  8b7508               mov esi, dword ptr [ebp + 8]
// 006a15ba  8bce                 mov ecx, esi
// 006a15bc  ff5514               call dword ptr [ebp + 0x14]
// 006a15bf  03750c               add esi, dword ptr [ebp + 0xc]
// 006a15c2  897508               mov dword ptr [ebp + 8], esi
// 006a15c5  ff45e4               inc dword ptr [ebp - 0x1c]
// 006a15c8  ebe5                 jmp 0x6a15af
// 006a15ca  c745e001000000       mov dword ptr [ebp - 0x20], 1
// 006a15d1  c745fcfeffffff       mov dword ptr [ebp - 4], 0xfffffffe
// 006a15d8  e808000000           call 0x6a15e5
// 006a15dd  e81f0a0000           call 0x6a2001
// 006a15e2  c21400               ret 0x14

typedef void (__thiscall *ElementFunction)(void *);

extern "C" void __stdcall array_unwind(
    void *, unsigned int, int, ElementFunction);

#pragma optimize("s", on)

extern "C" void __stdcall vector_constructor(
    void *ptr,
    unsigned int size,
    int count,
    ElementFunction constructor,
    ElementFunction destructor)
{
    int success = 0;
    int i;

    __try {
        for (i = 0; i < count; ++i) {
            constructor(ptr);
            ptr = (char *)ptr + size;
        }
        success = 1;
    }
    __finally {
        if (!success)
            array_unwind(ptr, size, i, destructor);
    }
}
