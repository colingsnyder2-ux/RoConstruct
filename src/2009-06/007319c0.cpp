// from server: 100% by auto
// roc 2009-06 007319c0  unit: CXTPCommandBar  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007319c0
//
// 007319c0  83ec2c               sub esp, 0x2c
// 007319c3  6a2c                 push 0x2c
// 007319c5  8d442404             lea eax, [esp + 4]
// 007319c9  6a00                 push 0
// 007319cb  50                   push eax
// 007319cc  e8a382feff           call 0x719c74
// 007319d1  8b542444             mov edx, dword ptr [esp + 0x44]
// 007319d5  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007319d9  83c40c               add esp, 0xc
// 007319dc  6a00                 push 0
// 007319de  6a00                 push 0
// 007319e0  89542410             mov dword ptr [esp + 0x10], edx
// 007319e4  8d54243c             lea edx, [esp + 0x3c]
// 007319e8  52                   push edx
// 007319e9  894c2410             mov dword ptr [esp + 0x10], ecx
// 007319ed  b801000000           mov eax, 1
// 007319f2  6689442418           mov word ptr [esp + 0x18], ax
// 007319f7  b920000000           mov ecx, 0x20
// 007319fc  6a00                 push 0
// 007319fe  8d442410             lea eax, [esp + 0x10]
// 00731a02  66894c241e           mov word ptr [esp + 0x1e], cx
// 00731a07  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00731a0b  50                   push eax
// 00731a0c  51                   push ecx
// 00731a0d  c744241828000000     mov dword ptr [esp + 0x18], 0x28
// 00731a15  c744242800000000     mov dword ptr [esp + 0x28], 0
// 00731a1d  ff155ce18900         call dword ptr [0x89e15c]
// 00731a23  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00731a27  85c9                 test ecx, ecx
// 00731a29  7406                 je 0x731a31
// 00731a2b  8b542434             mov edx, dword ptr [esp + 0x34]
// 00731a2f  8911                 mov dword ptr [ecx], edx
// 00731a31  83c42c               add esp, 0x2c
// 00731a34  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?Create32BPPDIBSection@CXTPImageManager@@SAPAUHBITMAP__@@PAUHDC__@@HHPAPAE@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
