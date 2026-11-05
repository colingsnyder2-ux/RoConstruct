// from server: 100% by auto
// roc 2011-06 008f34c0  unit: CXTCaptionPopupWnd  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f34c0
//
// 008f34c0  83ec28               sub esp, 0x28
// 008f34c3  56                   push esi
// 008f34c4  e8536ef1ff           call 0x80a31c
// 008f34c9  8b7008               mov esi, dword ptr [eax + 8]
// 008f34cc  8d442404             lea eax, [esp + 4]
// 008f34d0  50                   push eax
// 008f34d1  6838a9ad00           push 0xada938
// 008f34d6  56                   push esi
// 008f34d7  ff15201aa400         call dword ptr [0xa41a20]
// 008f34dd  85c0                 test eax, eax
// 008f34df  756d                 jne 0x8f354e
// 008f34e1  8b0da01ca400         mov ecx, dword ptr [0xa41ca0]
// 008f34e7  57                   push edi
// 008f34e8  33ff                 xor edi, edi
// 008f34ea  c744240803000000     mov dword ptr [esp + 8], 3
// 008f34f2  894c240c             mov dword ptr [esp + 0xc], ecx
// 008f34f6  897c2410             mov dword ptr [esp + 0x10], edi
// 008f34fa  897c2414             mov dword ptr [esp + 0x14], edi
// 008f34fe  89742418             mov dword ptr [esp + 0x18], esi
// 008f3502  897c241c             mov dword ptr [esp + 0x1c], edi
// 008f3506  e8116ef1ff           call 0x80a31c
// 008f350b  68007f0000           push 0x7f00
// 008f3510  57                   push edi
// 008f3511  ff15081aa400         call dword ptr [0xa41a08]
// 008f3517  6a0f                 push 0xf
// 008f3519  89442424             mov dword ptr [esp + 0x24], eax
// 008f351d  ff15701aa400         call dword ptr [0xa41a70]
// 008f3523  8d542408             lea edx, [esp + 8]
// 008f3527  52                   push edx
// 008f3528  89442428             mov dword ptr [esp + 0x28], eax
// 008f352c  897c242c             mov dword ptr [esp + 0x2c], edi
// 008f3530  c744243038a9ad00     mov dword ptr [esp + 0x30], 0xada938
// 008f3538  e823940d00           call 0x9cc960
// 008f353d  5f                   pop edi
// 008f353e  85c0                 test eax, eax
// 008f3540  750c                 jne 0x8f354e
// 008f3542  e8e5910d00           call 0x9cc72c
// 008f3547  33c0                 xor eax, eax
// 008f3549  5e                   pop esi
// 008f354a  83c428               add esp, 0x28
// 008f354d  c3                   ret 
// 008f354e  b801000000           mov eax, 1
// 008f3553  5e                   pop esi
// 008f3554  83c428               add esp, 0x28
// 008f3557  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionPopupWnd.cpp (function ?RegisterWindowClass@CXTCaptionPopupWnd@@IAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionPopupWnd.cpp
