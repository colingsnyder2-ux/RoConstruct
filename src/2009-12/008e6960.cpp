// from server: 100% by auto
// roc 2009-12 008e6960  unit: CXTCaptionPopupWnd  size: 195 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e6960
//
// 008e6960  83ec30               sub esp, 0x30
// 008e6963  53                   push ebx
// 008e6964  55                   push ebp
// 008e6965  56                   push esi
// 008e6966  8bf1                 mov esi, ecx
// 008e6968  57                   push edi
// 008e6969  56                   push esi
// 008e696a  8d4c2424             lea ecx, [esp + 0x24]
// 008e696e  e85d49f6ff           call 0x84b2d0
// 008e6973  6afe                 push -2
// 008e6975  6afe                 push -2
// 008e6977  8d442428             lea eax, [esp + 0x28]
// 008e697b  50                   push eax
// 008e697c  ff1558ca9800         call dword ptr [0x98ca58]
// 008e6982  8b442424             mov eax, dword ptr [esp + 0x24]
// 008e6986  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 008e698a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008e698e  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 008e6992  8bf8                 mov edi, eax
// 008e6994  83c013               add eax, 0x13
// 008e6997  6a01                 push 1
// 008e6999  89542440             mov dword ptr [esp + 0x40], edx
// 008e699d  894c243c             mov dword ptr [esp + 0x3c], ecx
// 008e69a1  2bd0                 sub edx, eax
// 008e69a3  52                   push edx
// 008e69a4  2bcb                 sub ecx, ebx
// 008e69a6  51                   push ecx
// 008e69a7  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 008e69aa  50                   push eax
// 008e69ab  53                   push ebx
// 008e69ac  89442438             mov dword ptr [esp + 0x38], eax
// 008e69b0  e87dd2f0ff           call 0x7f3c32
// 008e69b5  8b542438             mov edx, dword ptr [esp + 0x38]
// 008e69b9  8d6f13               lea ebp, [edi + 0x13]
// 008e69bc  6a01                 push 1
// 008e69be  8bcd                 mov ecx, ebp
// 008e69c0  2bcf                 sub ecx, edi
// 008e69c2  51                   push ecx
// 008e69c3  2bd3                 sub edx, ebx
// 008e69c5  52                   push edx
// 008e69c6  57                   push edi
// 008e69c7  53                   push ebx
// 008e69c8  8d4e60               lea ecx, [esi + 0x60]
// 008e69cb  e862d2f0ff           call 0x7f3c32
// 008e69d0  8b442438             mov eax, dword ptr [esp + 0x38]
// 008e69d4  6afe                 push -2
// 008e69d6  6afe                 push -2
// 008e69d8  8d4c2418             lea ecx, [esp + 0x18]
// 008e69dc  51                   push ecx
// 008e69dd  895c241c             mov dword ptr [esp + 0x1c], ebx
// 008e69e1  897c2420             mov dword ptr [esp + 0x20], edi
// 008e69e5  89442424             mov dword ptr [esp + 0x24], eax
// 008e69e9  896c2428             mov dword ptr [esp + 0x28], ebp
// 008e69ed  ff1558ca9800         call dword ptr [0x98ca58]
// 008e69f3  8b442418             mov eax, dword ptr [esp + 0x18]
// 008e69f7  8b542414             mov edx, dword ptr [esp + 0x14]
// 008e69fb  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 008e69ff  8d48f0               lea ecx, [eax - 0x10]
// 008e6a02  6a01                 push 1
// 008e6a04  2bfa                 sub edi, edx
// 008e6a06  57                   push edi
// 008e6a07  2bc1                 sub eax, ecx
// 008e6a09  50                   push eax
// 008e6a0a  52                   push edx
// 008e6a0b  894c2420             mov dword ptr [esp + 0x20], ecx
// 008e6a0f  51                   push ecx
// 008e6a10  8d8ef0010000         lea ecx, [esi + 0x1f0]
// 008e6a16  e817d2f0ff           call 0x7f3c32
// 008e6a1b  5f                   pop edi
// 008e6a1c  5e                   pop esi
// 008e6a1d  5d                   pop ebp
// 008e6a1e  5b                   pop ebx
// 008e6a1f  83c430               add esp, 0x30
// 008e6a22  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionPopupWnd.cpp (function ?RecalcLayout@CXTCaptionPopupWnd@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionPopupWnd.cpp
