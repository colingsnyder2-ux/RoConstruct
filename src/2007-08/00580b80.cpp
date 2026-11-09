// from server: 100% by EspClaude
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-cl: 50727
// from server: 100% by colin
// roc 2008-06 005be5a0  unit: RBX::Soundscape::SoundService  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005be5a0
//
// 005be5a0  55                   push ebp
// 005be5a1  8bec                 mov ebp, esp
// 005be5a3  6aff                 push -1
// 005be5a5  68f03e7d00           push 0x7d3ef0
// 005be5aa  64a100000000         mov eax, dword ptr fs:[0]
// 005be5b0  50                   push eax
// 005be5b1  64892500000000       mov dword ptr fs:[0], esp
// 005be5b8  51                   push ecx
// 005be5b9  8b4508               mov eax, dword ptr [ebp + 8]
// 005be5bc  8b4814               mov ecx, dword ptr [eax + 0x14]
// 005be5bf  53                   push ebx
// 005be5c0  56                   push esi
// 005be5c1  57                   push edi
// 005be5c2  8965f0               mov dword ptr [ebp - 0x10], esp
// 005be5c5  85c9                 test ecx, ecx
// 005be5c7  742e                 je 0x5be5f7
// 005be5c9  50                   push eax
// 005be5ca  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005be5d1  e84afbffff           call 0x5be120
// 005be5d6  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005be5d9  8901                 mov dword ptr [ecx], eax
// 005be5db  83c404               add esp, 4
// 005be5de  b001                 mov al, 1
// 005be5e0  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005be5e3  64890d00000000       mov dword ptr fs:[0], ecx
// 005be5ea  5f                   pop edi
// 005be5eb  5e                   pop esi
// 005be5ec  5b                   pop ebx
// 005be5ed  8be5                 mov esp, ebp
// 005be5ef  5d                   pop ebp
// 005be5f0  c3                   ret 

struct S
{
    unsigned char padding[20];
    void* volatile value;
};

extern int __cdecl process(S* object);

bool __cdecl getValue(S* object, int* result)
{
    void* v = object->value;
    if (v)
    {
        try
        {
            *result = process(object);
            return true;
        }
        catch (...)
        {
        }
    }
    return false;
}
