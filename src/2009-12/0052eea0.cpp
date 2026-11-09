// from server: 100% by auto
// roc 2009-12 0052eea0  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0052eea0
//
// 0052eea0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0052eea4  57                   push edi
// 0052eea5  8bf9                 mov edi, ecx
// 0052eea7  33c0                 xor eax, eax
// 0052eea9  d1ef                 shr edi, 1
// 0052eeab  741c                 je 0x52eec9
// 0052eead  53                   push ebx
// 0052eeae  56                   push esi
// 0052eeaf  8b742410             mov esi, dword ptr [esp + 0x10]
// 0052eeb3  8d4c0eff             lea ecx, [esi + ecx - 1]
// 0052eeb7  8a19                 mov bl, byte ptr [ecx]
// 0052eeb9  8a1430               mov dl, byte ptr [eax + esi]
// 0052eebc  881c30               mov byte ptr [eax + esi], bl
// 0052eebf  8811                 mov byte ptr [ecx], dl
// 0052eec1  40                   inc eax
// 0052eec2  49                   dec ecx
// 0052eec3  3bc7                 cmp eax, edi
// 0052eec5  72f0                 jb 0x52eeb7
// 0052eec7  5e                   pop esi
// 0052eec8  5b                   pop ebx
// 0052eec9  5f                   pop edi
// 0052eeca  c3                   ret 
// library raknet-4.081/BitStream.cpp (function ?ReverseBytesInPlace@BitStream@RakNet@@SAXPAEI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp
