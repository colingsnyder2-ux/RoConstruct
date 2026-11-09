// from server: 100% by EspClaude
// from server: 93% by colin
// roc 2008-06 00578c20  unit: RBX::VDataModel::?$SignalDesc  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00578c20
//
// 00578c20  56                   push esi
// 00578c21  8bf1                 mov esi, ecx
// 00578c23  56                   push esi
// 00578c24  e8b7c3ffff           call 0x574fe0
// 00578c29  83c404               add esp, 4
// 00578c2c  83f804               cmp eax, 4
// 00578c2f  7728                 ja 0x578c59
// 00578c31  ff24858c8c5700       jmp dword ptr [eax*4 + 0x578c8c]
// 00578c38  57                   push edi
// 00578c39  e852eaffff           call 0x577690
// 00578c3e  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00578c42  8bf0                 mov esi, eax
// 00578c44  56                   push esi
// 00578c45  8bcf                 mov ecx, edi
// 00578c47  e844e3ffff           call 0x576f90
// 00578c4c  8a460c               mov al, byte ptr [esi + 0xc]
// 00578c4f  88470c               mov byte ptr [edi + 0xc], al
// 00578c52  8a4e0d               mov cl, byte ptr [esi + 0xd]
// 00578c55  884f0d               mov byte ptr [edi + 0xd], cl
// 00578c58  5f                   pop edi
// 00578c59  5e                   pop esi
// 00578c5a  c20400               ret 4
// 00578c5d  85f6                 test esi, esi
// 00578c5f  74f8                 je 0x578c59
// 00578c61  8bce                 mov ecx, esi
// 00578c63  e86899e9ff           call 0x4125d0
// 00578c68  85c0                 test eax, eax
// 00578c6a  74ed                 je 0x578c59
// 00578c6c  5e                   pop esi
// 00578c6d  8bc8                 mov ecx, eax
// 00578c6f  e95c09f2ff           jmp 0x4995d0
// 00578c74  56                   push esi
// 00578c75  e80620f2ff           call 0x49ac80
// 00578c7a  83c404               add esp, 4
// 00578c7d  85c0                 test eax, eax
// 00578c7f  74d8                 je 0x578c59
// 00578c81  5e                   pop esi
// 00578c82  8bc8                 mov ecx, eax
// 00578c84  e947a4f1ff           jmp 0x4930d0
// 00578c89  8d4900               lea ecx, [ecx]
// 00578c8c  5d                   pop ebp
// 00578c8d  8c5700               mov word ptr [edi], ss
// 00578c90  748c                 je 0x578c1e
// 00578c92  57                   push edi
// 00578c93  00748c57             add byte ptr [esp + ecx*4 + 0x57], dh
// 00578c97  0038                 add byte ptr [eax], bh
// 00578c99  8c5700               mov word ptr [edi], ss

// from server: 57% by colin
struct S
{
    char padding[12];
    char fieldC;
    char fieldD;

    int getType();
    void copy(S*);
    void* getPayload();
    void copyFrom(S* other);
};

extern "C" int __cdecl sub_574fe0(S*);
extern "C" S* __cdecl sub_577690();
extern "C" void* __cdecl sub_49ac80(S*);
struct PayloadA { void call(S* other); };
struct PayloadB { void call(S* other); };

void S::copyFrom(S* other)
{
    int t = sub_574fe0(this);
    if ((unsigned)t > 4)
        return;

    switch (t)
    {
    case 3:
    case 4:
        {
            S* tmp = sub_577690();
            S* dst = other;
            dst->copy(tmp);
            dst->fieldC = tmp->fieldC;
            dst->fieldD = tmp->fieldD;
        }
        return;
    case 0:
        {
            if (this == 0)
                return;
            void* p = getPayload();
            if (p == 0)
                return;
            return ((PayloadA*)p)->call(other);
        }
        return;
    case 1:
    case 2:
        {
            void* p = sub_49ac80(this);
            if (p == 0)
                return;
            return ((PayloadB*)p)->call(other);
        }
        return;
    default:
        return;
    }
}


