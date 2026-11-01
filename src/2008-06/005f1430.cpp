// from server: 100% by colin
// from server: 76% by king_originala
// roc 2008-06 005f1430  unit: RBX::FaceInstance  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f1430
//
// 005f1430  83ec0c               sub esp, 0xc
// 005f1433  56                   push esi
// 005f1434  8bf1                 mov esi, ecx
// 005f1436  8b06                 mov eax, dword ptr [esi]
// 005f1438  8b4e04               mov ecx, dword ptr [esi + 4]
// 005f143b  0528020000           add eax, 0x228
// 005f1440  8b8488d0000000       mov eax, dword ptr [eax + ecx*4 + 0xd0]
// 005f1447  85c0                 test eax, eax
// 005f1449  753a                 jne 0x5f1485
// 005f144b  b801000000           mov eax, 1
// 005f1450  8405d0ab9700         test byte ptr [0x97abd0], al
// 005f1456  7528                 jne 0x5f1480
// 005f1458  d905dc828200         fld dword ptr [0x8282dc]
// 005f145e  0905d0ab9700         or dword ptr [0x97abd0], eax
// 005f1464  d91dc8ab9700         fstp dword ptr [0x97abc8]
// 005f146a  c705c4ab970000000000 mov dword ptr [0x97abc4], 0
// 005f1474  d905ac9b8100         fld dword ptr [0x819bac]
// 005f147a  d91dccab9700         fstp dword ptr [0x97abcc]
// 005f1480  b8c4ab9700           mov eax, 0x97abc4
// 005f1485  8b08                 mov ecx, dword ptr [eax]
// 005f1487  894c2404             mov dword ptr [esp + 4], ecx
// 005f148b  8b5004               mov edx, dword ptr [eax + 4]
// 005f148e  89542408             mov dword ptr [esp + 8], edx
// 005f1492  8b4008               mov eax, dword ptr [eax + 8]
// 005f1495  8944240c             mov dword ptr [esp + 0xc], eax
// 005f1499  8b442414             mov eax, dword ptr [esp + 0x14]
// 005f149d  3bc1                 cmp eax, ecx
// 005f149f  743f                 je 0x5f14e0
// 005f14a1  8b5604               mov edx, dword ptr [esi + 4]
// 005f14a4  8d4c2404             lea ecx, [esp + 4]
// 005f14a8  51                   push ecx
// 005f14a9  8b0e                 mov ecx, dword ptr [esi]
// 005f14ab  52                   push edx
// 005f14ac  81c128020000         add ecx, 0x228
// 005f14b2  8944240c             mov dword ptr [esp + 0xc], eax
// 005f14b6  e8b562ffff           call 0x5e7770
// 005f14bb  8b4604               mov eax, dword ptr [esi + 4]
// 005f14be  8b0e                 mov ecx, dword ptr [esi]
// 005f14c0  50                   push eax
// 005f14c1  e8fa82faff           call 0x5997c0
// 005f14c6  8b4e04               mov ecx, dword ptr [esi + 4]
// 005f14c9  51                   push ecx
// 005f14ca  8b0e                 mov ecx, dword ptr [esi]
// 005f14cc  e80f79faff           call 0x598de0
// 005f14d1  8bc8                 mov ecx, eax
// 005f14d3  e8b8b5ffff           call 0x5eca90
// 005f14d8  8b0e                 mov ecx, dword ptr [esi]
// 005f14da  50                   push eax
// 005f14db  e820c6e1ff           call 0x40db00
// 005f14e0  5e                   pop esi
// 005f14e1  83c40c               add esp, 0xc
// 005f14e4  c20400               ret 4

#pragma float_control(precise, off)

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

struct Storage {
    char padding[0xd0];
    Value* values[6];
    const Value& get(int index) const;
    void set(int index, const Value& value);
};

inline const Value& Storage::get(int index) const
{
    if (values[index])
        return *values[index];
    static Value empty;
    return empty;
}

struct Item {
    void* descriptor();
};

struct PartInstance {
    char padding[0x228];
    Storage storage;
    void setShouldRender(int index);
    Item* item(int index);
    void notify(void* descriptor);
};

struct S {
    PartInstance* part;
    int index;
    void f(int kind);
};

void S::f(int kind)
{
    Value copy = part->storage.get(index);
    if (kind != copy.kind) {
        copy.kind = kind;
        part->storage.set(index, copy);
        part->setShouldRender(index);
        part->notify(part->item(index)->descriptor());
    }
}
