// from server: 100% by auto
// roc 2010-06 0089a960  unit: CXTCaptionPopupWnd  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089a960
//
// 0089a960  83ec28               sub esp, 0x28
// 0089a963  56                   push esi
// 0089a964  e8f5d2f0ff           call 0x7a7c5e
// 0089a969  8b7008               mov esi, dword ptr [eax + 8]
// 0089a96c  8d442404             lea eax, [esp + 4]
// 0089a970  50                   push eax
// 0089a971  68100ea700           push 0xa70e10
// 0089a976  56                   push esi
// 0089a977  ff15f8ba9e00         call dword ptr [0x9ebaf8]
// 0089a97d  85c0                 test eax, eax
// 0089a97f  756d                 jne 0x89a9ee
// 0089a981  8b0d7cbb9e00         mov ecx, dword ptr [0x9ebb7c]
// 0089a987  57                   push edi
// 0089a988  33ff                 xor edi, edi
// 0089a98a  c744240803000000     mov dword ptr [esp + 8], 3
// 0089a992  894c240c             mov dword ptr [esp + 0xc], ecx
// 0089a996  897c2410             mov dword ptr [esp + 0x10], edi
// 0089a99a  897c2414             mov dword ptr [esp + 0x14], edi
// 0089a99e  89742418             mov dword ptr [esp + 0x18], esi
// 0089a9a2  897c241c             mov dword ptr [esp + 0x1c], edi
// 0089a9a6  e8b3d2f0ff           call 0x7a7c5e
// 0089a9ab  68007f0000           push 0x7f00
// 0089a9b0  57                   push edi
// 0089a9b1  ff15ccbb9e00         call dword ptr [0x9ebbcc]
// 0089a9b7  6a0f                 push 0xf
// 0089a9b9  89442424             mov dword ptr [esp + 0x24], eax
// 0089a9bd  ff1520ba9e00         call dword ptr [0x9eba20]
// 0089a9c3  8d542408             lea edx, [esp + 8]
// 0089a9c7  52                   push edx
// 0089a9c8  89442428             mov dword ptr [esp + 0x28], eax
// 0089a9cc  897c242c             mov dword ptr [esp + 0x2c], edi
// 0089a9d0  c7442430100ea700     mov dword ptr [esp + 0x30], 0xa70e10
// 0089a9d8  e8e7280e00           call 0x97d2c4
// 0089a9dd  5f                   pop edi
// 0089a9de  85c0                 test eax, eax
// 0089a9e0  750c                 jne 0x89a9ee
// 0089a9e2  e823250e00           call 0x97cf0a
// 0089a9e7  33c0                 xor eax, eax
// 0089a9e9  5e                   pop esi
// 0089a9ea  83c428               add esp, 0x28
// 0089a9ed  c3                   ret 
// 0089a9ee  b801000000           mov eax, 1
// 0089a9f3  5e                   pop esi
// 0089a9f4  83c428               add esp, 0x28
// 0089a9f7  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionPopupWnd.cpp (function ?RegisterWindowClass@CXTCaptionPopupWnd@@IAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionPopupWnd.cpp
