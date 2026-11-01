// from server: 100% by auto
// roc 2009-12 0054f5f0  unit: RBX::Network::IdSerializer  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0054f5f0
//
// 0054f5f0  a1d807b800           mov eax, dword ptr [0xb807d8]
// 0054f5f5  40                   inc eax
// 0054f5f6  a3d807b800           mov dword ptr [0xb807d8], eax
// 0054f5fb  83f801               cmp eax, 1
// 0054f5fe  7525                 jne 0x54f625
// 0054f600  6a0c                 push 0xc
// 0054f602  e859422a00           call 0x7f3860
// 0054f607  33c9                 xor ecx, ecx
// 0054f609  83c404               add esp, 4
// 0054f60c  3bc1                 cmp eax, ecx
// 0054f60e  740e                 je 0x54f61e
// 0054f610  894808               mov dword ptr [eax + 8], ecx
// 0054f613  8908                 mov dword ptr [eax], ecx
// 0054f615  894804               mov dword ptr [eax + 4], ecx
// 0054f618  a3d407b800           mov dword ptr [0xb807d4], eax
// 0054f61d  c3                   ret 
// 0054f61e  33c0                 xor eax, eax
// 0054f620  a3d407b800           mov dword ptr [0xb807d4], eax
// 0054f625  c3                   ret 
// library raknet-4.081/StringTable.cpp (function ?AddReference@StringTable@RakNet@@SAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 StringTable.cpp
