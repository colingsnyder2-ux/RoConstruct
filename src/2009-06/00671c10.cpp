// from server: 88% by EspClaude
// from server: 100% by atomic.potato
// roc 2008-06 005d20d0  unit: RBX::VSpawnLocation::?$BoundPropGetSet  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d20d0
//
// 005d20d0  8b442404             mov eax, dword ptr [esp + 4]
// 005d20d4  85c0                 test eax, eax
// 005d20d6  7405                 je 0x5d20dd
// 005d20d8  83c0ec               add eax, -0x14
// 005d20db  eb02                 jmp 0x5d20df
// 005d20dd  33c0                 xor eax, eax
// 005d20df  8b9034010000         mov edx, dword ptr [eax + 0x134]
// 005d20e5  56                   push esi
// 005d20e6  8b710c               mov esi, dword ptr [ecx + 0xc]
// 005d20e9  8b1432               mov edx, dword ptr [edx + esi]
// 005d20ec  035108               add edx, dword ptr [ecx + 8]
// 005d20ef  5e                   pop esi
// 005d20f0  8b840234010000       mov eax, dword ptr [edx + eax + 0x134]
// 005d20f7  c20400               ret 4

struct S
{
    int f(int);
    int value8;
    int valueC;
};

int S::f(int p)
{
    int* base = (int*)p;
    if (base)
        base = (int*)((char*)base - 20);
    else
        base = 0;

    int index = *(int*)((char*)base + 0x134);
    int offset = *(int*)((char*)this + 0xC);
    int entry = *(int*)((char*)index + offset);
    entry += *(int*)((char*)this + 8);

    return *(int*)((char*)entry + (int)base + 0x134);
}
