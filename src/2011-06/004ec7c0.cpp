// from server: 100% by Yeetserama
// roc 2011-06 004ec7c0  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004ec7c0
//
// 004ec7c0  56                   push esi
// 004ec7c1  8bf1                 mov esi, ecx
// 004ec7c3  8b4608               mov eax, dword ptr [esi + 8]
// 004ec7c6  8d4801               lea ecx, [eax + 1]
// 004ec7c9  3b0e                 cmp ecx, dword ptr [esi]
// 004ec7cb  7606                 jbe 0x4ec7d3
// 004ec7cd  32c0                 xor al, al
// 004ec7cf  5e                   pop esi
// 004ec7d0  c20400               ret 4
// 004ec7d3  8bc8                 mov ecx, eax
// 004ec7d5  83e107               and ecx, 7
// 004ec7d8  ba80000000           mov edx, 0x80
// 004ec7dd  d3fa                 sar edx, cl
// 004ec7df  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004ec7e2  c1e803               shr eax, 3
// 004ec7e5  841408               test byte ptr [eax + ecx], dl
// 004ec7e8  8b442408             mov eax, dword ptr [esp + 8]
// 004ec7ec  0f95c2               setne dl
// 004ec7ef  8810                 mov byte ptr [eax], dl
// 004ec7f1  b801000000           mov eax, 1
// 004ec7f6  014608               add dword ptr [esi + 8], eax
// 004ec7f9  5e                   pop esi
// 004ec7fa  c20400               ret 4
// copied from an identical function in another client (function ??$Read@_N@BitStream@RakNet@@QAE_NAA_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 FullyConnectedMesh2.cpp