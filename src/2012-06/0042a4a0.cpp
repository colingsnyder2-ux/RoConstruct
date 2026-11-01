// from server: 100% by auto
// roc 2012-06 0042a4a0  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0042a4a0
//
// 0042a4a0  0fb7442404           movzx eax, word ptr [esp + 4]
// 0042a4a5  56                   push esi
// 0042a4a6  50                   push eax
// 0042a4a7  6a04                 push 4
// 0042a4a9  50                   push eax
// 0042a4aa  8bf1                 mov esi, ecx
// 0042a4ac  e8ab855500           call 0x982a5c
// 0042a4b1  50                   push eax
// 0042a4b2  ff15d43ab200         call dword ptr [0xb23ad4]
// 0042a4b8  50                   push eax
// 0042a4b9  8bce                 mov ecx, esi
// 0042a4bb  e896855500           call 0x982a56
// 0042a4c0  5e                   pop esi
// 0042a4c1  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCommandBars.cpp (function ?LoadMenuA@CMenu@@QAEHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCommandBars.cpp
