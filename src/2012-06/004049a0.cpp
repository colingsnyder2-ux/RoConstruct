// from server: 100% by auto
// roc 2012-06 004049a0  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004049a0
//
// 004049a0  b800100000           mov eax, 0x1000
// 004049a5  e836e95700           call 0x9832e0
// 004049aa  56                   push esi
// 004049ab  57                   push edi
// 004049ac  8bbc240c100000       mov edi, dword ptr [esp + 0x100c]
// 004049b3  803f3d               cmp byte ptr [edi], 0x3d
// 004049b6  8bf1                 mov esi, ecx
// 004049b8  752d                 jne 0x4049e7
// 004049ba  57                   push edi
// 004049bb  e820feffff           call 0x4047e0
// 004049c0  85c0                 test eax, eax
// 004049c2  7c25                 jl 0x4049e9
// 004049c4  8bce                 mov ecx, esi
// 004049c6  e8b5fdffff           call 0x404780
// 004049cb  8d442408             lea eax, [esp + 8]
// 004049cf  50                   push eax
// 004049d0  8bce                 mov ecx, esi
// 004049d2  e809feffff           call 0x4047e0
// 004049d7  85c0                 test eax, eax
// 004049d9  7c0e                 jl 0x4049e9
// 004049db  57                   push edi
// 004049dc  8bce                 mov ecx, esi
// 004049de  e8fdfdffff           call 0x4047e0
// 004049e3  85c0                 test eax, eax
// 004049e5  7c02                 jl 0x4049e9
// 004049e7  33c0                 xor eax, eax
// 004049e9  5f                   pop edi
// 004049ea  5e                   pop esi
// 004049eb  81c400100000         add esp, 0x1000
// 004049f1  c20400               ret 4
// library atl-8.0/atl.cpp (function ?SkipAssignment@CRegParser@ATL@@IAEJPAD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
