// from server: 100% by Xemicl
// roc 2012-06 00732270  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00732270
//
// 00732270  56                   push esi
// 00732271  8bf1                 mov esi, ecx
// 00732273  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00732277  57                   push edi
// 00732278  8b3e                 mov edi, dword ptr [esi]
// 0073227a  e8d109ceff           call 0x412c50
// 0073227f  8b573c               mov edx, dword ptr [edi + 0x3c]
// 00732282  50                   push eax
// 00732283  8b442410             mov eax, dword ptr [esp + 0x10]
// 00732287  50                   push eax
// 00732288  8bce                 mov ecx, esi
// 0073228a  ffd2                 call edx
// 0073228c  5f                   pop edi
// 0073228d  5e                   pop esi
// 0073228e  c20800               ret 8
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