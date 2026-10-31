// from server: 89% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005d3990  unit: RBX::VSpawnLocation::?$BoundPropGetSet  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d3990
//
// 005d3990  8b442404             mov eax, dword ptr [esp + 4]
// 005d3994  56                   push esi
// 005d3995  57                   push edi
// 005d3996  8bf1                 mov esi, ecx
// 005d3998  85c0                 test eax, eax
// 005d399a  7405                 je 0x5d39a1
// 005d399c  8d78ec               lea edi, [eax - 0x14]
// 005d399f  eb02                 jmp 0x5d39a3
// 005d39a1  33ff                 xor edi, edi
// 005d39a3  8b460c               mov eax, dword ptr [esi + 0xc]
// 005d39a6  8b8f34010000         mov ecx, dword ptr [edi + 0x134]
// 005d39ac  8b1408               mov edx, dword ptr [eax + ecx]
// 005d39af  035608               add edx, dword ptr [esi + 8]
// 005d39b2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005d39b6  8a09                 mov cl, byte ptr [ecx]
// 005d39b8  388c3a34010000       cmp byte ptr [edx + edi + 0x134], cl
// 005d39bf  8d843a34010000       lea eax, [edx + edi + 0x134]
// 005d39c6  7430                 je 0x5d39f8
// 005d39c8  8808                 mov byte ptr [eax], cl
// 005d39ca  8b4610               mov eax, dword ptr [esi + 0x10]
// 005d39cd  85c0                 test eax, eax
// 005d39cf  741c                 je 0x5d39ed
// 005d39d1  8b5604               mov edx, dword ptr [esi + 4]
// 005d39d4  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005d39d7  52                   push edx
// 005d39d8  8b9734010000         mov edx, dword ptr [edi + 0x134]
// 005d39de  8b0c11               mov ecx, dword ptr [ecx + edx]
// 005d39e1  034e14               add ecx, dword ptr [esi + 0x14]
// 005d39e4  8d8c3934010000       lea ecx, [ecx + edi + 0x134]
// 005d39eb  ffd0                 call eax
// 005d39ed  8b5604               mov edx, dword ptr [esi + 4]
// 005d39f0  52                   push edx
// 005d39f1  8bcf                 mov ecx, edi
// 005d39f3  e808a1e3ff           call 0x40db00
// 005d39f8  5f                   pop edi
// 005d39f9  5e                   pop esi
// 005d39fa  c20800               ret 8

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

    void f(void*, const bool*);
};

void S::f(void* p, const bool* value)
{
    char* base = p ? (char*)p - 20 : 0;
    int table = *(int*)(base + 0x134);
    int offset = *(int*)(table + valueIndex);
    offset += valueOffset;
    bool* destination = (bool*)(base + 0x134 + offset);

    if (*destination != *value)
    {
        *destination = *value;
        if (callback)
        {
            int callbackTable = *(int*)(base + 0x134);
            int adjustment = *(int*)(callbackTable + callbackIndex);
            adjustment += callbackOffset;
            callback(base + 0x134 + adjustment, property);
        }
        ((Object*)base)->notify(property);
    }
}
