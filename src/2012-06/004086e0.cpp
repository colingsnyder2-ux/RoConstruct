// from server: 100% by Xemicl
// roc 2012-06 004086e0  unit: VCApp::?$CComAggObject  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004086e0
//
// 004086e0  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004086e4  85c9                 test ecx, ecx
// 004086e6  7508                 jne 0x4086f0
// 004086e8  b803400080           mov eax, 0x80004003
// 004086ed  c20c00               ret 0xc
// 004086f0  8b442408             mov eax, dword ptr [esp + 8]
// 004086f4  56                   push esi
// 004086f5  33f6                 xor esi, esi
// 004086f7  c70100000000         mov dword ptr [ecx], 0
// 004086fd  3930                 cmp dword ptr [eax], esi
// 004086ff  752b                 jne 0x40872c
// 00408701  397004               cmp dword ptr [eax + 4], esi
// 00408704  7526                 jne 0x40872c
// 00408706  817808c0000000       cmp dword ptr [eax + 8], 0xc0
// 0040870d  751d                 jne 0x40872c
// 0040870f  81780c00000046       cmp dword ptr [eax + 0xc], 0x46000000
// 00408716  7514                 jne 0x40872c
// 00408718  8b442408             mov eax, dword ptr [esp + 8]
// 0040871c  8901                 mov dword ptr [ecx], eax
// 0040871e  8b08                 mov ecx, dword ptr [eax]
// 00408720  8b5104               mov edx, dword ptr [ecx + 4]
// 00408723  50                   push eax
// 00408724  ffd2                 call edx
// 00408726  8bc6                 mov eax, esi
// 00408728  5e                   pop esi
// 00408729  c20c00               ret 0xc
// 0040872c  51                   push ecx
// 0040872d  50                   push eax
// 0040872e  8b442410             mov eax, dword ptr [esp + 0x10]
// 00408732  68d037b400           push 0xb437d0
// 00408737  83c008               add eax, 8
// 0040873a  50                   push eax
// 0040873b  e810eaffff           call 0x407150
// 00408740  8bf0                 mov esi, eax
// 00408742  5e                   pop esi
// 00408743  c20c00               ret 0xc
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