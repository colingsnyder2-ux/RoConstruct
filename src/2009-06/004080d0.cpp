// from server: 100% by EspClaude
// roc 2009-06 004080d0  unit: VCApp::?$CComAggObject  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004080d0
//
// 004080d0  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004080d4  85c9                 test ecx, ecx
// 004080d6  7508                 jne 0x4080e0
// 004080d8  b803400080           mov eax, 0x80004003
// 004080dd  c20c00               ret 0xc
// 004080e0  8b442408             mov eax, dword ptr [esp + 8]
// 004080e4  56                   push esi
// 004080e5  33f6                 xor esi, esi
// 004080e7  c70100000000         mov dword ptr [ecx], 0
// 004080ed  3930                 cmp dword ptr [eax], esi
// 004080ef  752b                 jne 0x40811c
// 004080f1  397004               cmp dword ptr [eax + 4], esi
// 004080f4  7526                 jne 0x40811c
// 004080f6  817808c0000000       cmp dword ptr [eax + 8], 0xc0
// 004080fd  751d                 jne 0x40811c
// 004080ff  81780c00000046       cmp dword ptr [eax + 0xc], 0x46000000
// 00408106  7514                 jne 0x40811c
// 00408108  8b442408             mov eax, dword ptr [esp + 8]
// 0040810c  8901                 mov dword ptr [ecx], eax
// 0040810e  8b08                 mov ecx, dword ptr [eax]
// 00408110  8b5104               mov edx, dword ptr [ecx + 4]
// 00408113  50                   push eax
// 00408114  ffd2                 call edx
// 00408116  8bc6                 mov eax, esi
// 00408118  5e                   pop esi
// 00408119  c20c00               ret 0xc
// 0040811c  51                   push ecx
// 0040811d  50                   push eax
// 0040811e  8b442410             mov eax, dword ptr [esp + 0x10]
// 00408122  68a0cd8a00           push 0x8acda0
// 00408127  83c008               add eax, 8
// 0040812a  50                   push eax
// 0040812b  e8f0ddffff           call 0x405f20
// 00408130  8bf0                 mov esi, eax
// 00408132  5e                   pop esi
// 00408133  c20c00               ret 0xc
// copied from an identical function in another client (function ?QueryInterface@ns_ROCX000011@@YGJPAUInterface@1@ABUIID@1@PAPAX@Z)

namespace ns_ROCX000011 {
struct IID {
    unsigned long words[4];
};

struct Interface;

struct VTable {
    long (__stdcall *QueryInterface)(Interface *, const IID &, void **);
    unsigned long (__stdcall *AddRef)(Interface *);
};

struct Interface {
    VTable *vtable;
};

extern const unsigned char interfaceMap[];
extern "C" long __stdcall InternalQueryInterface(
    void *, const void *, const IID &, void **);

long __stdcall QueryInterface(Interface *object, const IID &iid, void **output)
{
    if (!output)
        return (long)0x80004003UL;

    *output = 0;
    long result = 0;

    if (iid.words[0] == 0 &&
        iid.words[1] == 0 &&
        iid.words[2] == 0x000000C0UL &&
        iid.words[3] == 0x46000000UL)
    {
        *output = object;
        object->vtable->AddRef(object);
    }
    else
    {
        result = InternalQueryInterface(
            reinterpret_cast<unsigned char *>(object) + 8,
            interfaceMap, iid, output);
    }

    return result;
}
}
