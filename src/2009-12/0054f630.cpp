// from server: 100% by auto
// roc 2009-12 0054f630  unit: RBX::Network::IdSerializer  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0054f630
//
// 0054f630  833dd807b80000       cmp dword ptr [0xb807d8], 0
// 0054f637  7e2f                 jle 0x54f668
// 0054f639  832dd807b80001       sub dword ptr [0xb807d8], 1
// 0054f640  7526                 jne 0x54f668
// 0054f642  8b0dd407b800         mov ecx, dword ptr [0xb807d4]
// 0054f648  56                   push esi
// 0054f649  8bf1                 mov esi, ecx
// 0054f64b  85c9                 test ecx, ecx
// 0054f64d  740e                 je 0x54f65d
// 0054f64f  e8fcfeffff           call 0x54f550
// 0054f654  56                   push esi
// 0054f655  e800422a00           call 0x7f385a
// 0054f65a  83c404               add esp, 4
// 0054f65d  c705d407b80000000000 mov dword ptr [0xb807d4], 0
// 0054f667  5e                   pop esi
// 0054f668  c3                   ret 
// library raknet-4.081/StringCompressor.cpp (function ?RemoveReference@StringCompressor@RakNet@@SAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 StringCompressor.cpp
