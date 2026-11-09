// from server: 100% by colin
// roc 2007-08 0059c8d0  unit: RBX::UserInputBase  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0059c8d0
//
// 0059c8d0  d901                 fld dword ptr [ecx]
// 0059c8d2  56                   push esi
// 0059c8d3  8b742408             mov esi, dword ptr [esp + 8]
// 0059c8d7  d81e                 fcomp dword ptr [esi]
// 0059c8d9  dfe0                 fnstsw ax
// 0059c8db  f6c441               test ah, 0x41
// 0059c8de  8bc6                 mov eax, esi
// 0059c8e0  7402                 je 0x59c8e4
// 0059c8e2  8bc1                 mov eax, ecx
// 0059c8e4  d900                 fld dword ptr [eax]
// 0059c8e6  8d5104               lea edx, [ecx + 4]
// 0059c8e9  d919                 fstp dword ptr [ecx]
// 0059c8eb  57                   push edi
// 0059c8ec  d902                 fld dword ptr [edx]
// 0059c8ee  8d7e04               lea edi, [esi + 4]
// 0059c8f1  d81f                 fcomp dword ptr [edi]
// 0059c8f3  dfe0                 fnstsw ax
// 0059c8f5  f6c441               test ah, 0x41
// 0059c8f8  7402                 je 0x59c8fc
// 0059c8fa  8bfa                 mov edi, edx
// 0059c8fc  d907                 fld dword ptr [edi]
// 0059c8fe  8d7e08               lea edi, [esi + 8]
// 0059c901  d91a                 fstp dword ptr [edx]
// 0059c903  8d5108               lea edx, [ecx + 8]
// 0059c906  d907                 fld dword ptr [edi]
// 0059c908  d81a                 fcomp dword ptr [edx]
// 0059c90a  dfe0                 fnstsw ax
// 0059c90c  f6c441               test ah, 0x41
// 0059c90f  7402                 je 0x59c913
// 0059c911  8bfa                 mov edi, edx
// 0059c913  d907                 fld dword ptr [edi]
// 0059c915  5f                   pop edi
// 0059c916  d91a                 fstp dword ptr [edx]
// 0059c918  d9460c               fld dword ptr [esi + 0xc]
// 0059c91b  d8590c               fcomp dword ptr [ecx + 0xc]
// 0059c91e  dfe0                 fnstsw ax
// 0059c920  f6c441               test ah, 0x41
// 0059c923  750a                 jne 0x59c92f
// 0059c925  d9460c               fld dword ptr [esi + 0xc]
// 0059c928  5e                   pop esi
// 0059c929  d9590c               fstp dword ptr [ecx + 0xc]
// 0059c92c  c20400               ret 4
// 0059c92f  d9410c               fld dword ptr [ecx + 0xc]
// 0059c932  5e                   pop esi
// 0059c933  d9590c               fstp dword ptr [ecx + 0xc]
// 0059c936  c20400               ret 4
// copied from an identical function in another client (function ?f@DxUserInput@@QAEXABU1@@Z)

// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
inline const float& minimum(const float& a, const float& b)
{
    return b < a ? b : a;
}

inline const float& maximum(const float& a, const float& b)
{
    return a < b ? b : a;
}

struct DxUserInput
{
    float x0;
    float y0;
    float x1;
    float y1;

    void f(const DxUserInput& other);
};

void DxUserInput::f(const DxUserInput& other)
{
    x0 = minimum(x0, other.x0);
    y0 = minimum(y0, other.y0);
    x1 = maximum(x1, other.x1);
    y1 = maximum(y1, other.y1);
}