// from server: 100% by EspClaude
// from server: 100% by EspClaude
// roc 2008-06 004a5a70  unit: RBX::VHint::?$FactoryProduct::Creator  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a5a70
//
// 004a5a70  6aff                 push -1
// 004a5a72  68b9fe7c00           push 0x7cfeb9
// 004a5a77  64a100000000         mov eax, dword ptr fs:[0]
// 004a5a7d  50                   push eax
// 004a5a7e  64892500000000       mov dword ptr fs:[0], esp
// 004a5a85  83ec44               sub esp, 0x44
// 004a5a88  56                   push esi
// 004a5a89  57                   push edi
// 004a5a8a  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 004a5a8e  8b37                 mov esi, dword ptr [edi]
// 004a5a90  c744245c00000000     mov dword ptr [esp + 0x5c], 0
// 004a5a98  8b4618               mov eax, dword ptr [esi + 0x18]
// 004a5a9b  8b402c               mov eax, dword ptr [eax + 0x2c]
// 004a5a9e  6a01                 push 1
// 004a5aa0  40                   inc eax
// 004a5aa1  50                   push eax
// 004a5aa2  8d4c2464             lea ecx, [esp + 0x64]
// 004a5aa6  51                   push ecx
// 004a5aa7  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 004a5aab  e860f7ffff           call 0x4a5210
// 004a5ab0  84c0                 test al, al
// 004a5ab2  7534                 jne 0x4a5ae8
// 004a5ab4  68343c8200           push 0x823c34
// 004a5ab9  8d4c240c             lea ecx, [esp + 0xc]
// 004a5abd  ff1558248000         call dword ptr [0x802458]
// 004a5ac3  8d542408             lea edx, [esp + 8]
// 004a5ac7  52                   push edx
// 004a5ac8  8d4c2428             lea ecx, [esp + 0x28]
// 004a5acc  c744245800000000     mov dword ptr [esp + 0x58], 0
// 004a5ad4  e87742f6ff           call 0x409d50
// 004a5ad9  68c81b8d00           push 0x8d1bc8
// 004a5ade  8d442428             lea eax, [esp + 0x28]
// 004a5ae2  50                   push eax
// 004a5ae3  e8a4ba1f00           call 0x6a158c
// 004a5ae8  8b4704               mov eax, dword ptr [edi + 4]
// 004a5aeb  85c0                 test eax, eax
// 004a5aed  740f                 je 0x4a5afe
// 004a5aef  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 004a5af3  8b16                 mov edx, dword ptr [esi]
// 004a5af5  8b5234               mov edx, dword ptr [edx + 0x34]
// 004a5af8  51                   push ecx
// 004a5af9  50                   push eax
// 004a5afa  8bce                 mov ecx, esi
// 004a5afc  ffd2                 call edx
// 004a5afe  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004a5b02  5f                   pop edi
// 004a5b03  5e                   pop esi
// 004a5b04  64890d00000000       mov dword ptr fs:[0], ecx
// 004a5b0b  83c450               add esp, 0x50
// 004a5b0e  c3                   ret 

// from server: 90% by king_originala
// roc 2008-06 004a5a70  unit: RBX::VHint::?$FactoryProduct::Creator  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a5a70
//
// 004a5a70  6aff                 push -1
// 004a5a72  68b9fe7c00           push 0x7cfeb9
// 004a5a77  64a100000000         mov eax, dword ptr fs:[0]
// 004a5a7d  50                   push eax
// 004a5a7e  64892500000000       mov dword ptr fs:[0], esp
// 004a5a85  83ec44               sub esp, 0x44
// 004a5a88  56                   push esi
// 004a5a89  57                   push edi
// 004a5a8a  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 004a5a8e  8b37                 mov esi, dword ptr [edi]
// 004a5a90  c744245c00000000     mov dword ptr [esp + 0x5c], 0
// 004a5a98  8b4618               mov eax, dword ptr [esi + 0x18]
// 004a5a9b  8b402c               mov eax, dword ptr [eax + 0x2c]
// 004a5a9e  6a01                 push 1
// 004a5aa0  40                   inc eax
// 004a5aa1  50                   push eax
// 004a5aa2  8d4c2464             lea ecx, [esp + 0x64]
// 004a5aa6  51                   push ecx
// 004a5aa7  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 004a5aab  e860f7ffff           call 0x4a5210
// 004a5ab0  84c0                 test al, al
// 004a5ab2  7534                 jne 0x4a5ae8
// 004a5ab4  68343c8200           push 0x823c34
// 004a5ab9  8d4c240c             lea ecx, [esp + 0xc]
// 004a5abd  ff1558248000         call dword ptr [0x802458]
// 004a5ac3  8d542408             lea edx, [esp + 8]
// 004a5ac7  52                   push edx
// 004a5ac8  8d4c2428             lea ecx, [esp + 0x28]
// 004a5acc  c744245800000000     mov dword ptr [esp + 0x58], 0
// 004a5ad4  e87742f6ff           call 0x409d50
// 004a5ad9  68c81b8d00           push 0x8d1bc8
// 004a5ade  8d442428             lea eax, [esp + 0x28]
// 004a5ae2  50                   push eax
// 004a5ae3  e8a4ba1f00           call 0x6a158c
// 004a5ae8  8b4704               mov eax, dword ptr [edi + 4]
// 004a5aeb  85c0                 test eax, eax
// 004a5aed  740f                 je 0x4a5afe
// 004a5aef  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 004a5af3  8b16                 mov edx, dword ptr [esi]
// 004a5af5  8b5234               mov edx, dword ptr [edx + 0x34]
// 004a5af8  51                   push ecx
// 004a5af9  50                   push eax
// 004a5afa  8bce                 mov ecx, esi
// 004a5afc  ffd2                 call edx
// 004a5afe  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004a5b02  5f                   pop edi
// 004a5b03  5e                   pop esi
// 004a5b04  64890d00000000       mov dword ptr fs:[0], ecx
// 004a5b0b  83c450               add esp, 0x50
// 004a5b0e  c3                   ret 

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <stdexcept>
struct Stream {
    bool read(int*, int, int);
};
inline bool readValue(Stream* s, int* v, int n, int b) { return s->read(v, n, b); }

struct Property;

struct PropertyTable {
    void* entries[13];
    void (__thiscall* set)(Property*, void*, int);
};

struct EnumInfo {
    unsigned char reserved[48];
    int count;
};

struct Property {
    PropertyTable* table;
    unsigned char reserved[20];
    EnumInfo* info;
};

struct Descriptor {
    Property* property;
    void* object;
};

void deserializeEnum(Descriptor* descriptor, Stream* stream)
{
    Property* property = descriptor->property;
    int value = 0;

    if (!readValue(stream, &value, property->info->count + 1, 1)) {
        std::string message("deserializeEnum failed");
        throw std::runtime_error(message);
    }

    if (descriptor->object)
        property->table->set(property, descriptor->object, value);
}
