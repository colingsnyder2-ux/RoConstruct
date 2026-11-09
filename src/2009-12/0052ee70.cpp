// from server: 100% by auto
// roc 2009-12 0052ee70  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0052ee70
//
// 0052ee70  56                   push esi
// 0052ee71  8b742410             mov esi, dword ptr [esp + 0x10]
// 0052ee75  33c0                 xor eax, eax
// 0052ee77  85f6                 test esi, esi
// 0052ee79  7619                 jbe 0x52ee94
// 0052ee7b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0052ee7f  57                   push edi
// 0052ee80  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0052ee84  8d4c31ff             lea ecx, [ecx + esi - 1]
// 0052ee88  8a11                 mov dl, byte ptr [ecx]
// 0052ee8a  881438               mov byte ptr [eax + edi], dl
// 0052ee8d  40                   inc eax
// 0052ee8e  49                   dec ecx
// 0052ee8f  3bc6                 cmp eax, esi
// 0052ee91  72f5                 jb 0x52ee88
// 0052ee93  5f                   pop edi
// 0052ee94  5e                   pop esi
// 0052ee95  c3                   ret 
// library raknet-4.081/BitStream.cpp (function ?ReverseBytes@BitStream@RakNet@@SAXPAE0I@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp
