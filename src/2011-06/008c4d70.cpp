// from server: 100% by auto
// roc 2011-06 008c4d70  unit: CXTPDockingPaneTabbedContainer  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008c4d70
//
// 008c4d70  56                   push esi
// 008c4d71  57                   push edi
// 008c4d72  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008c4d76  8bf1                 mov esi, ecx
// 008c4d78  85ff                 test edi, edi
// 008c4d7a  7446                 je 0x8c4dc2
// 008c4d7c  8b442410             mov eax, dword ptr [esp + 0x10]
// 008c4d80  894668               mov dword ptr [esi + 0x68], eax
// 008c4d83  8b4f24               mov ecx, dword ptr [edi + 0x24]
// 008c4d86  894e58               mov dword ptr [esi + 0x58], ecx
// 008c4d89  8b5728               mov edx, dword ptr [edi + 0x28]
// 008c4d8c  89565c               mov dword ptr [esi + 0x5c], edx
// 008c4d8f  8b473c               mov eax, dword ptr [edi + 0x3c]
// 008c4d92  894670               mov dword ptr [esi + 0x70], eax
// 008c4d95  8b4f40               mov ecx, dword ptr [edi + 0x40]
// 008c4d98  894e74               mov dword ptr [esi + 0x74], ecx
// 008c4d9b  8b5744               mov edx, dword ptr [edi + 0x44]
// 008c4d9e  895678               mov dword ptr [esi + 0x78], edx
// 008c4da1  8b4748               mov eax, dword ptr [edi + 0x48]
// 008c4da4  6a01                 push 1
// 008c4da6  57                   push edi
// 008c4da7  8bce                 mov ecx, esi
// 008c4da9  89467c               mov dword ptr [esi + 0x7c], eax
// 008c4dac  e8cff7ffff           call 0x8c4580
// 008c4db1  8b16                 mov edx, dword ptr [esi]
// 008c4db3  8b8244010000         mov eax, dword ptr [edx + 0x144]
// 008c4db9  6a01                 push 1
// 008c4dbb  6a01                 push 1
// 008c4dbd  57                   push edi
// 008c4dbe  8bce                 mov ecx, esi
// 008c4dc0  ffd0                 call eax
// 008c4dc2  5f                   pop edi
// 008c4dc3  5e                   pop esi
// 008c4dc4  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?Init@CXTPDockingPaneTabbedContainer@@IAEXPAVCXTPDockingPane@@PAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
