// from server: 81% by EspClaude
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
// roc-cl: 21022
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
    char padding[0xd0];
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
    char padding[0x228];
    Values values;
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
    const Value& ref = part->values.get(face);
    Value value = ref;
    if (value.first != second) {
        value.first = second;
        part->values.set(face, &value);
        part->setShouldRender(face);
        part->notify(part->f(face)->descriptor());
    }
}
