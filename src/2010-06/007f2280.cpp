// from server: 100% by auto
// roc 2010-06 007f2280  unit: CXTPCustomizeSheet  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f2280
//
// 007f2280  56                   push esi
// 007f2281  8b742408             mov esi, dword ptr [esp + 8]
// 007f2285  8b06                 mov eax, dword ptr [esi]
// 007f2287  8b5004               mov edx, dword ptr [eax + 4]
// 007f228a  57                   push edi
// 007f228b  8bf9                 mov edi, ecx
// 007f228d  6a00                 push 0
// 007f228f  8bce                 mov ecx, esi
// 007f2291  ffd2                 call edx
// 007f2293  8b87b8000000         mov eax, dword ptr [edi + 0xb8]
// 007f2299  8b7858               mov edi, dword ptr [eax + 0x58]
// 007f229c  85ff                 test edi, edi
// 007f229e  7424                 je 0x7f22c4
// 007f22a0  8b16                 mov edx, dword ptr [esi]
// 007f22a2  8b8798000000         mov eax, dword ptr [edi + 0x98]
// 007f22a8  8b5204               mov edx, dword ptr [edx + 4]
// 007f22ab  50                   push eax
// 007f22ac  8bce                 mov ecx, esi
// 007f22ae  ffd2                 call edx
// 007f22b0  8b06                 mov eax, dword ptr [esi]
// 007f22b2  8b10                 mov edx, dword ptr [eax]
// 007f22b4  33c9                 xor ecx, ecx
// 007f22b6  398f80000000         cmp dword ptr [edi + 0x80], ecx
// 007f22bc  0f95c1               setne cl
// 007f22bf  51                   push ecx
// 007f22c0  8bce                 mov ecx, esi
// 007f22c2  ffd2                 call edx
// 007f22c4  5f                   pop edi
// 007f22c5  5e                   pop esi
// 007f22c6  c20400               ret 4
// copied from an identical function in another client (function ?func@CXTPCustomizeSheet@ns_ROCX000006@ns_ROCX000061@@QAEXPAX@Z)

namespace ns_ROCX000006 {
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPNotifyConnection.cpp
}
