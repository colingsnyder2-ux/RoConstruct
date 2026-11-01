// from server: 100% by auto
// roc 2009-12 0053c0b0  unit: RBX::Network::Replicator::PingItem  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0053c0b0
//
// 0053c0b0  f644240401           test byte ptr [esp + 4], 1
// 0053c0b5  56                   push esi
// 0053c0b6  8bf1                 mov esi, ecx
// 0053c0b8  7409                 je 0x53c0c3
// 0053c0ba  56                   push esi
// 0053c0bb  e89a772b00           call 0x7f385a
// 0053c0c0  83c404               add esp, 4
// 0053c0c3  8bc6                 mov eax, esi
// 0053c0c5  5e                   pop esi
// 0053c0c6  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\ctlppg.cpp (function ??_GAFX_DDPDATA@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlppg.cpp
