// from server: 100% by EspClaude
// roc 2009-06 00416290  unit: CopyVerb  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00416290
//
// 00416290  51                   push ecx
// 00416291  56                   push esi
// 00416292  8bf1                 mov esi, ecx
// 00416294  8b06                 mov eax, dword ptr [esi]
// 00416296  85c0                 test eax, eax
// 00416298  750a                 jne 0x4162a4
// 0041629a  6805400080           push 0x80004005
// 0041629f  e80cccfeff           call 0x402eb0
// 004162a4  8d4c2404             lea ecx, [esp + 4]
// 004162a8  51                   push ecx
// 004162a9  6a01                 push 1
// 004162ab  50                   push eax
// 004162ac  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004162b4  ff1524ea8900         call dword ptr [0x89ea24]
// 004162ba  85c0                 test eax, eax
// 004162bc  7d06                 jge 0x4162c4
// 004162be  50                   push eax
// 004162bf  e8eccbfeff           call 0x402eb0
// 004162c4  55                   push ebp
// 004162c5  8b6c2408             mov ebp, dword ptr [esp + 8]
// 004162c9  57                   push edi
// 004162ca  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004162ce  3bfd                 cmp edi, ebp
// 004162d0  7c3b                 jl 0x41630d
// 004162d2  8b06                 mov eax, dword ptr [esi]
// 004162d4  8d542414             lea edx, [esp + 0x14]
// 004162d8  52                   push edx
// 004162d9  6a01                 push 1
// 004162db  50                   push eax
// 004162dc  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004162e4  ff1520ea8900         call dword ptr [0x89ea20]
// 004162ea  85c0                 test eax, eax
// 004162ec  7d06                 jge 0x4162f4
// 004162ee  50                   push eax
// 004162ef  e8bccbfeff           call 0x402eb0
// 004162f4  3b7c2414             cmp edi, dword ptr [esp + 0x14]
// 004162f8  7f13                 jg 0x41630d
// 004162fa  8b0e                 mov ecx, dword ptr [esi]
// 004162fc  8bc7                 mov eax, edi
// 004162fe  2bc5                 sub eax, ebp
// 00416300  5f                   pop edi
// 00416301  c1e004               shl eax, 4
// 00416304  03410c               add eax, dword ptr [ecx + 0xc]
// 00416307  5d                   pop ebp
// 00416308  5e                   pop esi
// 00416309  59                   pop ecx
// 0041630a  c20400               ret 4
// 0041630d  6857000780           push 0x80070057
// 00416312  e899cbfeff           call 0x402eb0
// copied from an identical function in another client (function ?f@CopyVerb@ns_ROCX000001@@QAEPAUElement@2@J@Z)

namespace ns_ROCX000001 {
typedef long HRESULT;

struct Element {
    char data[16];
};

struct SafeArray {
    char padding[12];
    Element* data;
};

extern "C" HRESULT (__stdcall *SafeArrayGetLBound)(SafeArray*, unsigned int, long*);
extern "C" HRESULT (__stdcall *SafeArrayGetUBound)(SafeArray*, unsigned int, long*);

namespace ATL {
    __declspec(noreturn) void __stdcall AtlThrowImpl(HRESULT);
}

struct CopyVerb {
    SafeArray* array;
    Element* f(long index);
};

Element* CopyVerb::f(long index)
{
    if (!array)
        ATL::AtlThrowImpl((HRESULT)0x80004005);

    long lowerBound;
    {
        long lower = 0;
        HRESULT hr = SafeArrayGetLBound(array, 1, &lower);
        if (hr < 0)
            ATL::AtlThrowImpl(hr);
        lowerBound = lower;
    }

    if (index >= lowerBound) {
        long upper = 0;
        HRESULT hr = SafeArrayGetUBound(array, 1, &upper);
        if (hr < 0)
            ATL::AtlThrowImpl(hr);

        if (index <= upper)
            return array->data + (index - lowerBound);
    }

    ATL::AtlThrowImpl((HRESULT)0x80070057);
    return 0;
}
}
