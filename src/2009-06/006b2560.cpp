// from server: 100% by EspClaude
// from server: 99% by EspClaude
// roc 2009-06 006b2560  unit: RBX::BlockBlockContact  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b2560
//
// 006b2560  6aff                 push -1
// 006b2562  6848098600           push 0x860948
// 006b2567  64a100000000         mov eax, dword ptr fs:[0]
// 006b256d  50                   push eax
// 006b256e  64892500000000       mov dword ptr fs:[0], esp
// 006b2575  83ec0c               sub esp, 0xc
// 006b2578  33c0                 xor eax, eax
// 006b257a  56                   push esi
// 006b257b  8bf1                 mov esi, ecx
// 006b257d  89442408             mov dword ptr [esp + 8], eax
// 006b2581  8944240c             mov dword ptr [esp + 0xc], eax
// 006b2585  89442404             mov dword ptr [esp + 4], eax
// 006b2589  89442418             mov dword ptr [esp + 0x18], eax
// 006b258d  8d442404             lea eax, [esp + 4]
// 006b2591  50                   push eax
// 006b2592  8d4e08               lea ecx, [esi + 8]
// 006b2595  51                   push ecx
// 006b2596  e815160000           call 0x6b3bb0
// 006b259b  8b562c               mov edx, dword ptr [esi + 0x2c]
// 006b259e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006b25a2  8b742428             mov esi, dword ptr [esp + 0x28]
// 006b25a6  52                   push edx
// 006b25a7  50                   push eax
// 006b25a8  8d4c2414             lea ecx, [esp + 0x14]
// 006b25ac  51                   push ecx
// 006b25ad  56                   push esi
// 006b25ae  e8ed280000           call 0x6b4ea0
// 006b25b3  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 006b25b7  52                   push edx
// 006b25b8  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 006b25c0  e8cb8cebff           call 0x56b290
// 006b25c5  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006b25c9  83c41c               add esp, 0x1c
// 006b25cc  8bc6                 mov eax, esi
// 006b25ce  5e                   pop esi
// 006b25cf  64890d00000000       mov dword ptr fs:[0], ecx
// 006b25d6  83c418               add esp, 0x18
// 006b25d9  c20800               ret 8

// from server: 100% by king_originala
// roc 2008-06 0060e180  unit: RBX::BlockBlockContact  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060e180
//
// 0060e180  6aff                 push -1
// 0060e182  68a88d7d00           push 0x7d8da8
// 0060e187  64a100000000         mov eax, dword ptr fs:[0]
// 0060e18d  50                   push eax
// 0060e18e  64892500000000       mov dword ptr fs:[0], esp
// 0060e195  83ec0c               sub esp, 0xc
// 0060e198  33c0                 xor eax, eax
// 0060e19a  56                   push esi
// 0060e19b  8bf1                 mov esi, ecx
// 0060e19d  89442408             mov dword ptr [esp + 8], eax
// 0060e1a1  8944240c             mov dword ptr [esp + 0xc], eax
// 0060e1a5  89442404             mov dword ptr [esp + 4], eax
// 0060e1a9  89442418             mov dword ptr [esp + 0x18], eax
// 0060e1ad  8d442404             lea eax, [esp + 4]
// 0060e1b1  50                   push eax
// 0060e1b2  8d4e08               lea ecx, [esi + 8]
// 0060e1b5  51                   push ecx
// 0060e1b6  e875090000           call 0x60eb30
// 0060e1bb  8b5628               mov edx, dword ptr [esi + 0x28]
// 0060e1be  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0060e1c2  8b742428             mov esi, dword ptr [esp + 0x28]
// 0060e1c6  52                   push edx
// 0060e1c7  50                   push eax
// 0060e1c8  8d4c2414             lea ecx, [esp + 0x14]
// 0060e1cc  51                   push ecx
// 0060e1cd  56                   push esi
// 0060e1ce  e85d270000           call 0x610930
// 0060e1d3  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0060e1d7  52                   push edx
// 0060e1d8  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 0060e1e0  e83b9befff           call 0x507d20
// 0060e1e5  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0060e1e9  83c41c               add esp, 0x1c
// 0060e1ec  8bc6                 mov eax, esi
// 0060e1ee  5e                   pop esi
// 0060e1ef  64890d00000000       mov dword ptr fs:[0], ecx
// 0060e1f6  83c418               add esp, 0x18
// 0060e1f9  c20800               ret 8

extern void __cdecl alignedFree(void *);

struct Buffer {
    void *data;
    int size;
    int capacity;

    Buffer() : size(0), capacity(0) { data = 0; }
    ~Buffer() { alignedFree(data); }
};

extern void __cdecl prepare(void *, Buffer *);
extern void __cdecl construct(void *, Buffer *, int, int);

struct S {
    char padding[8];
    char storage[36];
    int value;

    void *f(void *, int);
};

void *S::f(void *result, int argument)
{
    Buffer buffer;
    prepare(storage, &buffer);
    construct(result, &buffer, argument, value);
    return result;
}
