// from server: 100% by EspClaude
// roc 2009-06 004d6050  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004d6050
//
// 004d6050  51                   push ecx
// 004d6051  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004d6055  56                   push esi
// 004d6056  8bf1                 mov esi, ecx
// 004d6058  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 004d605b  8b01                 mov eax, dword ptr [ecx]
// 004d605d  8b4008               mov eax, dword ptr [eax + 8]
// 004d6060  57                   push edi
// 004d6061  52                   push edx
// 004d6062  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004d606a  ffd0                 call eax
// 004d606c  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004d6070  8d4c2414             lea ecx, [esp + 0x14]
// 004d6074  51                   push ecx
// 004d6075  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 004d6078  57                   push edi
// 004d6079  8944241c             mov dword ptr [esp + 0x1c], eax
// 004d607d  e8beac2300           call 0x710d40
// 004d6082  8bc7                 mov eax, edi
// 004d6084  5f                   pop edi
// 004d6085  5e                   pop esi
// 004d6086  59                   pop ecx
// 004d6087  c20800               ret 8
// copied from an identical function in another client (function ?convert@Descriptor@ns_ROCX000036@@QAEPAXPAXH@Z)

namespace ns_ROCX000036 {
struct Converter {
    void __thiscall convert(void* output, int* value);
};

struct Descriptor {
    char padding[0x1c];
    void* source;
    Converter* converter;

    void* convert(void* output, int value);
};

void* Descriptor::convert(void* output, int value)
{
    volatile int temporary = 0;
    int* table = *reinterpret_cast<int**>(source);
    value = reinterpret_cast<int (__thiscall*)(void*, int)>(table[2])(source, value);
    converter->convert(output, &value);
    return output;
}
}
