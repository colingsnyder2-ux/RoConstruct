// roc 2012-06 00710bf0  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00710bf0
//
// 00710bf0  6aff                 push -1
// 00710bf2  68e8e8aa00           push 0xaae8e8
// 00710bf7  64a100000000         mov eax, dword ptr fs:[0]
// 00710bfd  50                   push eax
// 00710bfe  64892500000000       mov dword ptr fs:[0], esp
// 00710c05  51                   push ecx
// 00710c06  56                   push esi
// 00710c07  8bf1                 mov esi, ecx
// 00710c09  89742404             mov dword ptr [esp + 4], esi
// 00710c0d  8d4e18               lea ecx, [esi + 0x18]
// 00710c10  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00710c18  e883f6ffff           call 0x7102a0
// 00710c1d  8bce                 mov ecx, esi
// 00710c1f  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00710c27  e8a40ee6ff           call 0x571ad0
// 00710c2c  f644241801           test byte ptr [esp + 0x18], 1
// 00710c31  7409                 je 0x710c3c
// 00710c33  56                   push esi
// 00710c34  e8b779d1ff           call 0x4285f0
// 00710c39  83c404               add esp, 4
// 00710c3c  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00710c40  8bc6                 mov eax, esi
// 00710c42  5e                   pop esi
// 00710c43  64890d00000000       mov dword ptr fs:[0], ecx
// 00710c4a  83c410               add esp, 0x10
// 00710c4d  c20400               ret 4
// library raknet-4.081/RelayPlugin.cpp (function ??_GStrAndGuidAndRoom@RelayPlugin@RakNet@@QAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 RelayPlugin.cpp
