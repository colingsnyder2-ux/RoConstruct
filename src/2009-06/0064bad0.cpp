// from server: 74% by EspClaude
// from server: 100% by colin
// roc 2008-06 005be610  unit: RBX::Soundscape::SoundService  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005be610
//
// 005be610  55                   push ebp
// 005be611  8bec                 mov ebp, esp
// 005be613  6aff                 push -1
// 005be615  68003f7d00           push 0x7d3f00
// 005be61a  64a100000000         mov eax, dword ptr fs:[0]
// 005be620  50                   push eax
// 005be621  64892500000000       mov dword ptr fs:[0], esp
// 005be628  51                   push ecx
// 005be629  8b4508               mov eax, dword ptr [ebp + 8]
// 005be62c  8b4814               mov ecx, dword ptr [eax + 0x14]
// 005be62f  53                   push ebx
// 005be630  56                   push esi
// 005be631  57                   push edi
// 005be632  8965f0               mov dword ptr [ebp - 0x10], esp
// 005be635  85c9                 test ecx, ecx
// 005be637  742e                 je 0x5be667
// 005be639  50                   push eax
// 005be63a  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005be641  e8fafbffff           call 0x5be240
// 005be646  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005be649  8901                 mov dword ptr [ecx], eax
// 005be64b  83c404               add esp, 4
// 005be64e  b001                 mov al, 1
// 005be650  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005be653  64890d00000000       mov dword ptr fs:[0], ecx
// 005be65a  5f                   pop edi
// 005be65b  5e                   pop esi
// 005be65c  5b                   pop ebx
// 005be65d  8be5                 mov esp, ebp
// 005be65f  5d                   pop ebp
// 005be660  c3                   ret 

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