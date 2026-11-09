// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 87% by colin
// roc 2008-06 005f15c0  unit: RBX::FaceInstance  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f15c0
//
// 005f15c0  83ec0c               sub esp, 0xc
// 005f15c3  56                   push esi
// 005f15c4  8bf1                 mov esi, ecx
// 005f15c6  8b06                 mov eax, dword ptr [esi]
// 005f15c8  8b4e04               mov ecx, dword ptr [esi + 4]
// 005f15cb  0528020000           add eax, 0x228
// 005f15d0  8b8488d0000000       mov eax, dword ptr [eax + ecx*4 + 0xd0]
// 005f15d7  85c0                 test eax, eax
// 005f15d9  753a                 jne 0x5f1615
// 005f15db  b801000000           mov eax, 1
// 005f15e0  8405d0ab9700         test byte ptr [0x97abd0], al
// 005f15e6  7528                 jne 0x5f1610
// 005f15e8  d905dc828200         fld dword ptr [0x8282dc]
// 005f15ee  0905d0ab9700         or dword ptr [0x97abd0], eax
// 005f15f4  d91dc8ab9700         fstp dword ptr [0x97abc8]
// 005f15fa  c705c4ab970000000000 mov dword ptr [0x97abc4], 0
// 005f1604  d905ac9b8100         fld dword ptr [0x819bac]
// 005f160a  d91dccab9700         fstp dword ptr [0x97abcc]
// 005f1610  b8c4ab9700           mov eax, 0x97abc4
// 005f1615  8b08                 mov ecx, dword ptr [eax]
// 005f1617  d9442414             fld dword ptr [esp + 0x14]
// 005f161b  894c2404             mov dword ptr [esp + 4], ecx
// 005f161f  8b5004               mov edx, dword ptr [eax + 4]
// 005f1622  89542408             mov dword ptr [esp + 8], edx
// 005f1626  8b4008               mov eax, dword ptr [eax + 8]
// 005f1629  8944240c             mov dword ptr [esp + 0xc], eax
// 005f162d  d854240c             fcom dword ptr [esp + 0xc]
// 005f1631  dfe0                 fnstsw ax
// 005f1633  f6c444               test ah, 0x44
// 005f1636  7b46                 jnp 0x5f167e
// 005f1638  8b5604               mov edx, dword ptr [esi + 4]
// 005f163b  d95c240c             fstp dword ptr [esp + 0xc]
// 005f163f  8d4c2404             lea ecx, [esp + 4]
// 005f1643  51                   push ecx
// 005f1644  8b0e                 mov ecx, dword ptr [esi]
// 005f1646  52                   push edx
// 005f1647  81c128020000         add ecx, 0x228
// 005f164d  e81e61ffff           call 0x5e7770
// 005f1652  8b4604               mov eax, dword ptr [esi + 4]
// 005f1655  8b0e                 mov ecx, dword ptr [esi]
// 005f1657  50                   push eax
// 005f1658  e86381faff           call 0x5997c0
// 005f165d  8b4e04               mov ecx, dword ptr [esi + 4]
// 005f1660  51                   push ecx
// 005f1661  8b0e                 mov ecx, dword ptr [esi]
// 005f1663  e87877faff           call 0x598de0
// 005f1668  8bc8                 mov ecx, eax
// 005f166a  e8e1b4ffff           call 0x5ecb50
// 005f166f  8b0e                 mov ecx, dword ptr [esi]
// 005f1671  50                   push eax
// 005f1672  e889c4e1ff           call 0x40db00
// 005f1677  5e                   pop esi
// 005f1678  83c40c               add esp, 0xc
// 005f167b  c20400               ret 4
// 005f167e  ddd8                 fstp st(0)
// 005f1680  5e                   pop esi
// 005f1681  83c40c               add esp, 0xc
// 005f1684  c20400               ret 4

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
    if (value.second != second) {
        value.second = second;
        part->values.set(face, &value);
        part->setShouldRender(face);
        part->notify(part->f(face)->descriptor());
    }
}
