// from server: 100% by auto
// roc 2009-12 00808b40  unit: CXTPCommandBar  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00808b40
//
// 00808b40  83ec2c               sub esp, 0x2c
// 00808b43  6a2c                 push 0x2c
// 00808b45  8d442404             lea eax, [esp + 4]
// 00808b49  6a00                 push 0
// 00808b4b  50                   push eax
// 00808b4c  e853bffeff           call 0x7f4aa4
// 00808b51  8b542444             mov edx, dword ptr [esp + 0x44]
// 00808b55  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00808b59  83c40c               add esp, 0xc
// 00808b5c  6a00                 push 0
// 00808b5e  6a00                 push 0
// 00808b60  89542410             mov dword ptr [esp + 0x10], edx
// 00808b64  8d54243c             lea edx, [esp + 0x3c]
// 00808b68  52                   push edx
// 00808b69  894c2410             mov dword ptr [esp + 0x10], ecx
// 00808b6d  b801000000           mov eax, 1
// 00808b72  6689442418           mov word ptr [esp + 0x18], ax
// 00808b77  b920000000           mov ecx, 0x20
// 00808b7c  6a00                 push 0
// 00808b7e  8d442410             lea eax, [esp + 0x10]
// 00808b82  66894c241e           mov word ptr [esp + 0x1e], cx
// 00808b87  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00808b8b  50                   push eax
// 00808b8c  51                   push ecx
// 00808b8d  c744241828000000     mov dword ptr [esp + 0x18], 0x28
// 00808b95  c744242800000000     mov dword ptr [esp + 0x28], 0
// 00808b9d  ff1560b19800         call dword ptr [0x98b160]
// 00808ba3  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00808ba7  85c9                 test ecx, ecx
// 00808ba9  7406                 je 0x808bb1
// 00808bab  8b542434             mov edx, dword ptr [esp + 0x34]
// 00808baf  8911                 mov dword ptr [ecx], edx
// 00808bb1  83c42c               add esp, 0x2c
// 00808bb4  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?Create32BPPDIBSection@CXTPImageManager@@SAPAUHBITMAP__@@PAUHDC__@@HHPAPAE@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
