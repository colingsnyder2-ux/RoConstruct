// from server: 100% by EspClaude
// roc 2009-06 0065b6b0  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0065b6b0
//
// 0065b6b0  56                   push esi
// 0065b6b1  8bf1                 mov esi, ecx
// 0065b6b3  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0065b6b7  57                   push edi
// 0065b6b8  8b3e                 mov edi, dword ptr [esi]
// 0065b6ba  e8d13cdeff           call 0x43f390
// 0065b6bf  8b573c               mov edx, dword ptr [edi + 0x3c]
// 0065b6c2  50                   push eax
// 0065b6c3  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065b6c7  50                   push eax
// 0065b6c8  8bce                 mov ecx, esi
// 0065b6ca  ffd2                 call edx
// 0065b6cc  5f                   pop edi
// 0065b6cd  5e                   pop esi
// 0065b6ce  c20800               ret 8
// copied from an identical function in another client (function ?apply@Descriptor@ns_ROCX00003d@@QAEXPAXPAUValue@2@@Z)

namespace ns_ROCX00003d {
struct Value {
    int convert();
};

struct Descriptor;

typedef void (__thiscall *Setter)(Descriptor*, void*, int);

struct DispatchTable {
    void* padding[15];
    Setter set;
};

struct Descriptor {
    DispatchTable* table;
    void apply(void*, Value*);
};

void Descriptor::apply(void* object, Value* value)
{
    DispatchTable* dispatch = table;
    int converted = value->convert();
    dispatch->set(this, object, converted);
}
}
