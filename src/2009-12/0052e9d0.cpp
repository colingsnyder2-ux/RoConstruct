// from server: 100% by auto
// roc 2009-12 0052e9d0  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0052e9d0
//
// 0052e9d0  56                   push esi
// 0052e9d1  8bf1                 mov esi, ecx
// 0052e9d3  8b4608               mov eax, dword ptr [esi + 8]
// 0052e9d6  8d4801               lea ecx, [eax + 1]
// 0052e9d9  3b0e                 cmp ecx, dword ptr [esi]
// 0052e9db  7606                 jbe 0x52e9e3
// 0052e9dd  32c0                 xor al, al
// 0052e9df  5e                   pop esi
// 0052e9e0  c20400               ret 4
// 0052e9e3  8bc8                 mov ecx, eax
// 0052e9e5  83e107               and ecx, 7
// 0052e9e8  ba80000000           mov edx, 0x80
// 0052e9ed  d3fa                 sar edx, cl
// 0052e9ef  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0052e9f2  c1e803               shr eax, 3
// 0052e9f5  841408               test byte ptr [eax + ecx], dl
// 0052e9f8  8b442408             mov eax, dword ptr [esp + 8]
// 0052e9fc  0f95c2               setne dl
// 0052e9ff  8810                 mov byte ptr [eax], dl
// 0052ea01  b801000000           mov eax, 1
// 0052ea06  014608               add dword ptr [esi + 8], eax
// 0052ea09  5e                   pop esi
// 0052ea0a  c20400               ret 4
// library raknet-4.081/BitStream.cpp (function ??$Read@_N@BitStream@RakNet@@QAE_NAA_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp
