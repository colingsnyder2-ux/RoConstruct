// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005d3920  unit: RBX::VSpawnLocation::?$BoundPropGetSet  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d3920
//
// 005d3920  8b442404             mov eax, dword ptr [esp + 4]
// 005d3924  56                   push esi
// 005d3925  57                   push edi
// 005d3926  8bf1                 mov esi, ecx
// 005d3928  85c0                 test eax, eax
// 005d392a  7405                 je 0x5d3931
// 005d392c  8d78ec               lea edi, [eax - 0x14]
// 005d392f  eb02                 jmp 0x5d3933
// 005d3931  33ff                 xor edi, edi
// 005d3933  8b460c               mov eax, dword ptr [esi + 0xc]
// 005d3936  8b8f34010000         mov ecx, dword ptr [edi + 0x90]
// 005d393c  8b1408               mov edx, dword ptr [eax + ecx]
// 005d393f  035608               add edx, dword ptr [esi + 8]
// 005d3942  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005d3946  8b09                 mov ecx, dword ptr [ecx]
// 005d3948  398c3a34010000       cmp dword ptr [edx + edi + 0x90], ecx
// 005d394f  8d843a34010000       lea eax, [edx + edi + 0x90]
// 005d3956  7430                 je 0x5d3988
// 005d3958  8908                 mov dword ptr [eax], ecx
// 005d395a  8b4610               mov eax, dword ptr [esi + 0x10]
// 005d395d  85c0                 test eax, eax
// 005d395f  741c                 je 0x5d397d
// 005d3961  8b5604               mov edx, dword ptr [esi + 4]
// 005d3964  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005d3967  52                   push edx
// 005d3968  8b9734010000         mov edx, dword ptr [edi + 0x90]
// 005d396e  8b0c11               mov ecx, dword ptr [ecx + edx]
// 005d3971  034e14               add ecx, dword ptr [esi + 0x14]
// 005d3974  8d8c3934010000       lea ecx, [ecx + edi + 0x90]
// 005d397b  ffd0                 call eax
// 005d397d  8b5604               mov edx, dword ptr [esi + 4]
// 005d3980  52                   push edx
// 005d3981  8bcf                 mov ecx, edi
// 005d3983  e878a1e3ff           call 0x40db00
// 005d3988  5f                   pop edi
// 005d3989  5e                   pop esi
// 005d398a  c20800               ret 8

struct Object
{
    void notify(void*);
};

typedef void (__thiscall *Callback)(void*, void*);

struct S
{
    int reserved;
    void* property;
    int valueOffset;
    int valueIndex;
    Callback callback;
    int callbackOffset;
    int callbackIndex;

    void f(void*, const int*);
};

void S::f(void* p, const int* value)
{
    char* base = p ? (char*)p - 24 : 0;
    int table = *(int*)(base + 0x90);
    int offset = *(int*)(table + valueIndex);
    offset += valueOffset;
    int* destination = (int*)(base + 0x90 + offset);

    if (*destination != *value)
    {
        *destination = *value;
        if (callback)
        {
            int callbackTable = *(int*)(base + 0x90);
            int adjustment = *(int*)(callbackTable + callbackIndex);
            adjustment += callbackOffset;
            callback(base + 0x90 + adjustment, property);
        }
        ((Object*)base)->notify(property);
    }
}
