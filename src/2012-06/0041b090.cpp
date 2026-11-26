// from server: 100% by Xemicl
// roc 2012-06 0041b090  unit: CopyVerb  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0041b090
//
// 0041b090  51                   push ecx
// 0041b091  56                   push esi
// 0041b092  8bf1                 mov esi, ecx
// 0041b094  8b06                 mov eax, dword ptr [esi]
// 0041b096  85c0                 test eax, eax
// 0041b098  750a                 jne 0x41b0a4
// 0041b09a  6805400080           push 0x80004005
// 0041b09f  e80c91feff           call 0x4041b0
// 0041b0a4  8d4c2404             lea ecx, [esp + 4]
// 0041b0a8  51                   push ecx
// 0041b0a9  6a01                 push 1
// 0041b0ab  50                   push eax
// 0041b0ac  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0041b0b4  ff15302bb200         call dword ptr [0xb22b30]
// 0041b0ba  85c0                 test eax, eax
// 0041b0bc  7d06                 jge 0x41b0c4
// 0041b0be  50                   push eax
// 0041b0bf  e8ec90feff           call 0x4041b0
// 0041b0c4  55                   push ebp
// 0041b0c5  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0041b0c9  57                   push edi
// 0041b0ca  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0041b0ce  3bfd                 cmp edi, ebp
// 0041b0d0  7c3b                 jl 0x41b10d
// 0041b0d2  8b06                 mov eax, dword ptr [esi]
// 0041b0d4  8d542414             lea edx, [esp + 0x14]
// 0041b0d8  52                   push edx
// 0041b0d9  6a01                 push 1
// 0041b0db  50                   push eax
// 0041b0dc  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0041b0e4  ff15342bb200         call dword ptr [0xb22b34]
// 0041b0ea  85c0                 test eax, eax
// 0041b0ec  7d06                 jge 0x41b0f4
// 0041b0ee  50                   push eax
// 0041b0ef  e8bc90feff           call 0x4041b0
// 0041b0f4  3b7c2414             cmp edi, dword ptr [esp + 0x14]
// 0041b0f8  7f13                 jg 0x41b10d
// 0041b0fa  8b0e                 mov ecx, dword ptr [esi]
// 0041b0fc  8bc7                 mov eax, edi
// 0041b0fe  2bc5                 sub eax, ebp
// 0041b100  5f                   pop edi
// 0041b101  c1e004               shl eax, 4
// 0041b104  03410c               add eax, dword ptr [ecx + 0xc]
// 0041b107  5d                   pop ebp
// 0041b108  5e                   pop esi
// 0041b109  59                   pop ecx
// 0041b10a  c20400               ret 4
// 0041b10d  6857000780           push 0x80070057
// 0041b112  e89990feff           call 0x4041b0
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