// from server: 100% by auto
// roc 2010-06 007bcce0  unit: CXTPCommandBar  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bcce0
//
// 007bcce0  83ec2c               sub esp, 0x2c
// 007bcce3  6a2c                 push 0x2c
// 007bcce5  8d442404             lea eax, [esp + 4]
// 007bcce9  6a00                 push 0
// 007bcceb  50                   push eax
// 007bccec  e8f3befeff           call 0x7a8be4
// 007bccf1  8b542444             mov edx, dword ptr [esp + 0x44]
// 007bccf5  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007bccf9  83c40c               add esp, 0xc
// 007bccfc  6a00                 push 0
// 007bccfe  6a00                 push 0
// 007bcd00  89542410             mov dword ptr [esp + 0x10], edx
// 007bcd04  8d54243c             lea edx, [esp + 0x3c]
// 007bcd08  52                   push edx
// 007bcd09  894c2410             mov dword ptr [esp + 0x10], ecx
// 007bcd0d  b801000000           mov eax, 1
// 007bcd12  6689442418           mov word ptr [esp + 0x18], ax
// 007bcd17  b920000000           mov ecx, 0x20
// 007bcd1c  6a00                 push 0
// 007bcd1e  8d442410             lea eax, [esp + 0x10]
// 007bcd22  66894c241e           mov word ptr [esp + 0x1e], cx
// 007bcd27  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007bcd2b  50                   push eax
// 007bcd2c  51                   push ecx
// 007bcd2d  c744241828000000     mov dword ptr [esp + 0x18], 0x28
// 007bcd35  c744242800000000     mov dword ptr [esp + 0x28], 0
// 007bcd3d  ff15b0a09e00         call dword ptr [0x9ea0b0]
// 007bcd43  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 007bcd47  85c9                 test ecx, ecx
// 007bcd49  7406                 je 0x7bcd51
// 007bcd4b  8b542434             mov edx, dword ptr [esp + 0x34]
// 007bcd4f  8911                 mov dword ptr [ecx], edx
// 007bcd51  83c42c               add esp, 0x2c
// 007bcd54  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?Create32BPPDIBSection@CXTPImageManager@@SAPAUHBITMAP__@@PAUHDC__@@HHPAPAE@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
