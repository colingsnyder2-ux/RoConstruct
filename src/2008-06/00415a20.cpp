// from server: 100% by colin
// from server: 81% by king_originala
// roc 2008-06 00415a20  unit: CopyVerb  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00415a20
//
// 00415a20  56                   push esi
// 00415a21  57                   push edi
// 00415a22  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00415a26  8bf1                 mov esi, ecx
// 00415a28  85ff                 test edi, edi
// 00415a2a  7459                 je 0x415a85
// 00415a2c  8d44240c             lea eax, [esp + 0xc]
// 00415a30  50                   push eax
// 00415a31  57                   push edi
// 00415a32  ff1520298000         call dword ptr [0x802920]
// 00415a38  85c0                 test eax, eax
// 00415a3a  7c27                 jl 0x415a63
// 00415a3c  837c240c00           cmp dword ptr [esp + 0xc], 0
// 00415a41  7420                 je 0x415a63
// 00415a43  56                   push esi
// 00415a44  57                   push edi
// 00415a45  e896ffffff           call 0x4159e0
// 00415a4a  8b542414             mov edx, dword ptr [esp + 0x14]
// 00415a4e  83c408               add esp, 8
// 00415a51  b900200000           mov ecx, 0x2000
// 00415a56  66090e               or word ptr [esi], cx
// 00415a59  5f                   pop edi
// 00415a5a  895608               mov dword ptr [esi + 8], edx
// 00415a5d  8bc6                 mov eax, esi
// 00415a5f  5e                   pop esi
// 00415a60  c20400               ret 4
// 00415a63  b90a000000           mov ecx, 0xa
// 00415a68  66890e               mov word ptr [esi], cx
// 00415a6b  894608               mov dword ptr [esi + 8], eax
// 00415a6e  3d0e000780           cmp eax, 0x8007000e
// 00415a73  7506                 jne 0x415a7b
// 00415a75  50                   push eax
// 00415a76  e885b5feff           call 0x401000
// 00415a7b  6857000780           push 0x80070057
// 00415a80  e87bb5feff           call 0x401000
// 00415a85  33d2                 xor edx, edx
// 00415a87  5f                   pop edi
// 00415a88  668916               mov word ptr [esi], dx
// 00415a8b  8bc6                 mov eax, esi
// 00415a8d  5e                   pop esi
// 00415a8e  c20400               ret 4

#include <intrin.h>
typedef long HRESULT;

struct S;
extern "C" HRESULT (__stdcall *SafeArrayCopy)(void*, void**);
extern void __cdecl G_func_004159e0(void*, S*);
namespace ATL {
    void __stdcall AtlThrowImpl(HRESULT);
}

struct S {
    unsigned short type;
    unsigned short reserved[3];
    union {
        void* array;
        HRESULT error;
    };
    S& assign(void* source);
};

S& S::assign(void* source)
{
    void* original = source;
    _ReadWriteBarrier();
    if (original) {
        HRESULT hr = SafeArrayCopy(original, &source);
        if (hr >= 0 && source) {
            G_func_004159e0(original, this);
            type |= 0x2000;
            array = source;
            return *this;
        }
        type = 10;
        error = hr;
        if (hr == (HRESULT)0x8007000E)
            ATL::AtlThrowImpl(hr);
        ATL::AtlThrowImpl((HRESULT)0x80070057);
    }
    type = 0;
    return *this;
}
