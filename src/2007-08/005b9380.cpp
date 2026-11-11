// from server: 100% by EspClaude
// from server: 81% by EspClaude
// roc 2007-08 005b9380  unit: RBX::VFaceInstance::?$EnumPropDescriptor  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005b9380
//
// 005b9380  83ec0c               sub esp, 0xc
// 005b9383  56                   push esi
// 005b9384  8bf1                 mov esi, ecx
// 005b9386  8b06                 mov eax, dword ptr [esi]
// 005b9388  8b80d8010000         mov eax, dword ptr [eax + 0x1d8]
// 005b938e  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b9391  8b848894000000       mov eax, dword ptr [eax + ecx*4 + 0x94]
// 005b9398  85c0                 test eax, eax
// 005b939a  753a                 jne 0x5b93d6
// 005b939c  b801000000           mov eax, 1
// 005b93a1  8405bc5e8c00         test byte ptr [0x8c5ebc], al
// 005b93a7  7528                 jne 0x5b93d1
// 005b93a9  d905f0547b00         fld dword ptr [0x7b54f0]
// 005b93af  0905bc5e8c00         or dword ptr [0x8c5ebc], eax
// 005b93b5  d91db45e8c00         fstp dword ptr [0x8c5eb4]
// 005b93bb  c705b05e8c0000000000 mov dword ptr [0x8c5eb0], 0
// 005b93c5  d9059c7e7900         fld dword ptr [0x797e9c]
// 005b93cb  d91db85e8c00         fstp dword ptr [0x8c5eb8]
// 005b93d1  b8b05e8c00           mov eax, 0x8c5eb0
// 005b93d6  8b08                 mov ecx, dword ptr [eax]
// 005b93d8  d9442414             fld dword ptr [esp + 0x14]
// 005b93dc  894c2404             mov dword ptr [esp + 4], ecx
// 005b93e0  8b5004               mov edx, dword ptr [eax + 4]
// 005b93e3  89542408             mov dword ptr [esp + 8], edx
// 005b93e7  d8542408             fcom dword ptr [esp + 8]
// 005b93eb  8b4008               mov eax, dword ptr [eax + 8]
// 005b93ee  8944240c             mov dword ptr [esp + 0xc], eax
// 005b93f2  dfe0                 fnstsw ax
// 005b93f4  f6c444               test ah, 0x44
// 005b93f7  7b46                 jnp 0x5b943f
// 005b93f9  8b5604               mov edx, dword ptr [esi + 4]
// 005b93fc  d95c2408             fstp dword ptr [esp + 8]
// 005b9400  8b06                 mov eax, dword ptr [esi]
// 005b9402  8d4c2404             lea ecx, [esp + 4]
// 005b9406  51                   push ecx
// 005b9407  8b88d8010000         mov ecx, dword ptr [eax + 0x1d8]
// 005b940d  52                   push edx
// 005b940e  e81db6ffff           call 0x5b4a30
// 005b9413  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b9416  51                   push ecx
// 005b9417  8b0e                 mov ecx, dword ptr [esi]
// 005b9419  e882aafbff           call 0x573ea0
// 005b941e  8b5604               mov edx, dword ptr [esi + 4]
// 005b9421  8b0e                 mov ecx, dword ptr [esi]
// 005b9423  52                   push edx
// 005b9424  e867a4fbff           call 0x573890
// 005b9429  8bc8                 mov ecx, eax
// 005b942b  e870d7ffff           call 0x5b6ba0
// 005b9430  8b0e                 mov ecx, dword ptr [esi]
// 005b9432  50                   push eax
// 005b9433  e8d8b2e8ff           call 0x444710
// 005b9438  5e                   pop esi
// 005b9439  83c40c               add esp, 0xc
// 005b943c  c20400               ret 4
// 005b943f  ddd8                 fstp st(0)
// 005b9441  5e                   pop esi
// 005b9442  83c40c               add esp, 0xc
// 005b9445  c20400               ret 4

// from server: 100% by colin
// roc 2008-06 005f14f0  unit: RBX::FaceInstance  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f14f0
//
// 005f14f0  83ec0c               sub esp, 0xc
// 005f14f3  56                   push esi
// 005f14f4  8bf1                 mov esi, ecx
// 005f14f6  8b06                 mov eax, dword ptr [esi]
// 005f14f8  8b4e04               mov ecx, dword ptr [esi + 4]
// 005f14fb  0528020000           add eax, 0x228
// 005f1500  8b8488d0000000       mov eax, dword ptr [eax + ecx*4 + 0xd0]
// 005f1507  85c0                 test eax, eax
// 005f1509  753a                 jne 0x5f1545
// 005f150b  b801000000           mov eax, 1
// 005f1510  8405d0ab9700         test byte ptr [0x97abd0], al
// 005f1516  7528                 jne 0x5f1540
// 005f1518  d905dc828200         fld dword ptr [0x8282dc]
// 005f151e  0905d0ab9700         or dword ptr [0x97abd0], eax
// 005f1524  d91dc8ab9700         fstp dword ptr [0x97abc8]
// 005f152a  c705c4ab970000000000 mov dword ptr [0x97abc4], 0
// 005f1534  d905ac9b8100         fld dword ptr [0x819bac]
// 005f153a  d91dccab9700         fstp dword ptr [0x97abcc]
// 005f1540  b8c4ab9700           mov eax, 0x97abc4
// 005f1545  8b08                 mov ecx, dword ptr [eax]
// 005f1547  d9442414             fld dword ptr [esp + 0x14]
// 005f154b  894c2404             mov dword ptr [esp + 4], ecx
// 005f154f  8b5004               mov edx, dword ptr [eax + 4]
// 005f1552  89542408             mov dword ptr [esp + 8], edx
// 005f1556  d8542408             fcom dword ptr [esp + 8]
// 005f155a  8b4008               mov eax, dword ptr [eax + 8]
// 005f155d  8944240c             mov dword ptr [esp + 0xc], eax
// 005f1561  dfe0                 fnstsw ax
// 005f1563  f6c444               test ah, 0x44
// 005f1566  7b46                 jnp 0x5f15ae
// 005f1568  8b5604               mov edx, dword ptr [esi + 4]
// 005f156b  d95c2408             fstp dword ptr [esp + 8]
// 005f156f  8d4c2404             lea ecx, [esp + 4]
// 005f1573  51                   push ecx
// 005f1574  8b0e                 mov ecx, dword ptr [esi]
// 005f1576  52                   push edx
// 005f1577  81c128020000         add ecx, 0x228
// 005f157d  e8ee61ffff           call 0x5e7770
// 005f1582  8b4604               mov eax, dword ptr [esi + 4]
// 005f1585  8b0e                 mov ecx, dword ptr [esi]
// 005f1587  50                   push eax
// 005f1588  e83382faff           call 0x5997c0
// 005f158d  8b4e04               mov ecx, dword ptr [esi + 4]
// 005f1590  51                   push ecx
// 005f1591  8b0e                 mov ecx, dword ptr [esi]
// 005f1593  e84878faff           call 0x598de0
// 005f1598  8bc8                 mov ecx, eax
// 005f159a  e851b5ffff           call 0x5ecaf0
// 005f159f  8b0e                 mov ecx, dword ptr [esi]
// 005f15a1  50                   push eax
// 005f15a2  e859c5e1ff           call 0x40db00
// 005f15a7  5e                   pop esi
// 005f15a8  83c40c               add esp, 0xc
// 005f15ab  c20400               ret 4
// 005f15ae  ddd8                 fstp st(0)
// 005f15b0  5e                   pop esi
// 005f15b1  83c40c               add esp, 0xc
// 005f15b4  c20400               ret 4

// from server: 97% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
//

extern float defaultFirst;
extern float defaultSecond;

struct Value {
    int kind;
    float first;
    float second;
    Value();
};

inline Value::Value()
    : kind(0), first(defaultFirst), second(defaultSecond)
{
}

struct Values {
    char padding[0x94];
    Value* entries[1];
    const Value& get(int) const;
    void set(int, const Value*);
};

inline const Value& Values::get(int index) const
{
    if (entries[index])
        return *entries[index];
    static Value empty;
    return empty;
}

struct Property { void* descriptor(); };
struct PartInstance {
    char padding[0x1d8];
    Values* values;
    void setShouldRender(int);
    Property* f(int);
    void notify(void*);
};

struct FaceInstance {
    PartInstance* part;
    int face;
    void setSecond(float);
};

void FaceInstance::setSecond(float second)
{
    Values* values = part->values;
    const Value& ref = values->get(face);
    Value value = ref;
    if (value.first != second) {
        value.first = second;
        part->values->set(face, &value);
        part->setShouldRender(face);
        part->notify(part->f(face)->descriptor());
    }
}
