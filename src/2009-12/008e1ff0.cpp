// from server: 100% by auto
// roc 2009-12 008e1ff0  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e1ff0
//
// 008e1ff0  8bc1                 mov eax, ecx
// 008e1ff2  33c9                 xor ecx, ecx
// 008e1ff4  89480c               mov dword ptr [eax + 0xc], ecx
// 008e1ff7  894810               mov dword ptr [eax + 0x10], ecx
// 008e1ffa  894808               mov dword ptr [eax + 8], ecx
// 008e1ffd  894804               mov dword ptr [eax + 4], ecx
// 008e2000  894814               mov dword ptr [eax + 0x14], ecx
// 008e2003  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008e2007  c7004cbea000         mov dword ptr [eax], 0xa0be4c
// 008e200d  894818               mov dword ptr [eax + 0x18], ecx
// 008e2010  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ??0CObList@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
