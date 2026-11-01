// from server: 100% by auto
// roc 2009-12 0054fdb0  unit: RBX::Network::IdSerializer  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0054fdb0
//
// 0054fdb0  833de007b80000       cmp dword ptr [0xb807e0], 0
// 0054fdb7  7e2f                 jle 0x54fde8
// 0054fdb9  832de007b80001       sub dword ptr [0xb807e0], 1
// 0054fdc0  7526                 jne 0x54fde8
// 0054fdc2  8b0ddc07b800         mov ecx, dword ptr [0xb807dc]
// 0054fdc8  56                   push esi
// 0054fdc9  8bf1                 mov esi, ecx
// 0054fdcb  85c9                 test ecx, ecx
// 0054fdcd  740e                 je 0x54fddd
// 0054fdcf  e8acfeffff           call 0x54fc80
// 0054fdd4  56                   push esi
// 0054fdd5  e8803a2a00           call 0x7f385a
// 0054fdda  83c404               add esp, 4
// 0054fddd  c705dc07b80000000000 mov dword ptr [0xb807dc], 0
// 0054fde7  5e                   pop esi
// 0054fde8  c3                   ret 
// library raknet-4.081/StringCompressor.cpp (function ?RemoveReference@StringCompressor@RakNet@@SAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 StringCompressor.cpp
