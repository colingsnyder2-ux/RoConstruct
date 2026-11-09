// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0056e3a0  unit: G3D::VVector2int16::?$TypedPropertyDescriptor  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056e3a0
//
// 0056e3a0  83ec08               sub esp, 8
// 0056e3a3  53                   push ebx
// 0056e3a4  56                   push esi
// 0056e3a5  8b742418             mov esi, dword ptr [esp + 0x18]
// 0056e3a9  8bd9                 mov ebx, ecx
// 0056e3ab  8bce                 mov ecx, esi
// 0056e3ad  e85ee40000           call 0x57c810
// 0056e3b2  84c0                 test al, al
// 0056e3b4  7563                 jne 0x56e419
// 0056e3b6  a134539700           mov eax, dword ptr [0x975334]
// 0056e3bb  57                   push edi
// 0056e3bc  50                   push eax
// 0056e3bd  8bce                 mov ecx, esi
// 0056e3bf  e86cde0000           call 0x57c230
// 0056e3c4  8b0d80539700         mov ecx, dword ptr [0x975380]
// 0056e3ca  51                   push ecx
// 0056e3cb  8bce                 mov ecx, esi
// 0056e3cd  8bf8                 mov edi, eax
// 0056e3cf  e85cde0000           call 0x57c230
// 0056e3d4  8d54240c             lea edx, [esp + 0xc]
// 0056e3d8  52                   push edx
// 0056e3d9  8d4f10               lea ecx, [edi + 0x10]
// 0056e3dc  8bf0                 mov esi, eax
// 0056e3de  e80de10000           call 0x57c4f0
// 0056e3e3  8d442410             lea eax, [esp + 0x10]
// 0056e3e7  50                   push eax
// 0056e3e8  8d4e10               lea ecx, [esi + 0x10]
// 0056e3eb  e800e10000           call 0x57c4f0
// 0056e3f0  668b542410           mov dx, word ptr [esp + 0x10]
// 0056e3f5  668b4c240c           mov cx, word ptr [esp + 0xc]
// 0056e3fa  668954241e           mov word ptr [esp + 0x1e], dx
// 0056e3ff  66894c241c           mov word ptr [esp + 0x1c], cx
// 0056e404  8b4b18               mov ecx, dword ptr [ebx + 0x18]
// 0056e407  8b01                 mov eax, dword ptr [ecx]
// 0056e409  8b400c               mov eax, dword ptr [eax + 0xc]
// 0056e40c  8d54241c             lea edx, [esp + 0x1c]
// 0056e410  52                   push edx
// 0056e411  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0056e415  52                   push edx
// 0056e416  ffd0                 call eax
// 0056e418  5f                   pop edi
// 0056e419  5e                   pop esi
// 0056e41a  5b                   pop ebx
// 0056e41b  83c408               add esp, 8
// 0056e41e  c20c00               ret 0xc

struct Vector2 {
    short x;
    short y;
};

struct Value {
    bool get(int*);
};

struct Element {
    unsigned char padding[16];
    Value value;

    bool isNull();
    Element* find(void*);
};

extern void* xKey;
extern void* yKey;

struct Accessor;

struct AccessorTable {
    void* reserved[3];
    void (__thiscall* set)(Accessor*, void*, const Vector2&);
};

struct Accessor {
    AccessorTable* table;
};

struct Descriptor {
    unsigned char padding[24];
    Accessor* accessor;

    void read(void*, Element*, void*);
};

void Descriptor::read(void* object, Element* element, void*)
{
    if (!element->isNull()) {
        Element* xElement = element->find(xKey);
        Element* yElement = element->find(yKey);
        int x;
        int y;
        xElement->value.get(&x);
        yElement->value.get(&y);
        Vector2 result;
        result.x = (short)x;
        result.y = (short)y;
        accessor->table->set(accessor, object, result);
    }
}
