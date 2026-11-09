// from server: 100% by auto
// roc 2010-06 00867920  unit: CXTPDockingPaneTabbedContainer  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00867920
//
// 00867920  56                   push esi
// 00867921  57                   push edi
// 00867922  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00867926  8bf1                 mov esi, ecx
// 00867928  85ff                 test edi, edi
// 0086792a  7446                 je 0x867972
// 0086792c  8b442410             mov eax, dword ptr [esp + 0x10]
// 00867930  894668               mov dword ptr [esi + 0x68], eax
// 00867933  8b4f24               mov ecx, dword ptr [edi + 0x24]
// 00867936  894e58               mov dword ptr [esi + 0x58], ecx
// 00867939  8b5728               mov edx, dword ptr [edi + 0x28]
// 0086793c  89565c               mov dword ptr [esi + 0x5c], edx
// 0086793f  8b473c               mov eax, dword ptr [edi + 0x3c]
// 00867942  894670               mov dword ptr [esi + 0x70], eax
// 00867945  8b4f40               mov ecx, dword ptr [edi + 0x40]
// 00867948  894e74               mov dword ptr [esi + 0x74], ecx
// 0086794b  8b5744               mov edx, dword ptr [edi + 0x44]
// 0086794e  895678               mov dword ptr [esi + 0x78], edx
// 00867951  8b4748               mov eax, dword ptr [edi + 0x48]
// 00867954  6a01                 push 1
// 00867956  57                   push edi
// 00867957  8bce                 mov ecx, esi
// 00867959  89467c               mov dword ptr [esi + 0x7c], eax
// 0086795c  e8cff7ffff           call 0x867130
// 00867961  8b16                 mov edx, dword ptr [esi]
// 00867963  8b8244010000         mov eax, dword ptr [edx + 0x144]
// 00867969  6a01                 push 1
// 0086796b  6a01                 push 1
// 0086796d  57                   push edi
// 0086796e  8bce                 mov ecx, esi
// 00867970  ffd0                 call eax
// 00867972  5f                   pop edi
// 00867973  5e                   pop esi
// 00867974  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?Init@CXTPDockingPaneTabbedContainer@@IAEXPAVCXTPDockingPane@@PAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
