// from server: 100% by auto
// roc 2011-06 008f37e0  unit: CXTCaptionPopupWnd  size: 195 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f37e0
//
// 008f37e0  83ec30               sub esp, 0x30
// 008f37e3  53                   push ebx
// 008f37e4  55                   push ebp
// 008f37e5  56                   push esi
// 008f37e6  8bf1                 mov esi, ecx
// 008f37e8  57                   push edi
// 008f37e9  56                   push esi
// 008f37ea  8d4c2424             lea ecx, [esp + 0x24]
// 008f37ee  e89d95f6ff           call 0x85cd90
// 008f37f3  6afe                 push -2
// 008f37f5  6afe                 push -2
// 008f37f7  8d442428             lea eax, [esp + 0x28]
// 008f37fb  50                   push eax
// 008f37fc  ff15e41ba400         call dword ptr [0xa41be4]
// 008f3802  8b442424             mov eax, dword ptr [esp + 0x24]
// 008f3806  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 008f380a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008f380e  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 008f3812  8bf8                 mov edi, eax
// 008f3814  83c013               add eax, 0x13
// 008f3817  6a01                 push 1
// 008f3819  89542440             mov dword ptr [esp + 0x40], edx
// 008f381d  894c243c             mov dword ptr [esp + 0x3c], ecx
// 008f3821  2bd0                 sub edx, eax
// 008f3823  52                   push edx
// 008f3824  2bcb                 sub ecx, ebx
// 008f3826  51                   push ecx
// 008f3827  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 008f382a  50                   push eax
// 008f382b  53                   push ebx
// 008f382c  89442438             mov dword ptr [esp + 0x38], eax
// 008f3830  e8fb6bf1ff           call 0x80a430
// 008f3835  8b542438             mov edx, dword ptr [esp + 0x38]
// 008f3839  8d6f13               lea ebp, [edi + 0x13]
// 008f383c  6a01                 push 1
// 008f383e  8bcd                 mov ecx, ebp
// 008f3840  2bcf                 sub ecx, edi
// 008f3842  51                   push ecx
// 008f3843  2bd3                 sub edx, ebx
// 008f3845  52                   push edx
// 008f3846  57                   push edi
// 008f3847  53                   push ebx
// 008f3848  8d4e60               lea ecx, [esi + 0x60]
// 008f384b  e8e06bf1ff           call 0x80a430
// 008f3850  8b442438             mov eax, dword ptr [esp + 0x38]
// 008f3854  6afe                 push -2
// 008f3856  6afe                 push -2
// 008f3858  8d4c2418             lea ecx, [esp + 0x18]
// 008f385c  51                   push ecx
// 008f385d  895c241c             mov dword ptr [esp + 0x1c], ebx
// 008f3861  897c2420             mov dword ptr [esp + 0x20], edi
// 008f3865  89442424             mov dword ptr [esp + 0x24], eax
// 008f3869  896c2428             mov dword ptr [esp + 0x28], ebp
// 008f386d  ff15e41ba400         call dword ptr [0xa41be4]
// 008f3873  8b442418             mov eax, dword ptr [esp + 0x18]
// 008f3877  8b542414             mov edx, dword ptr [esp + 0x14]
// 008f387b  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 008f387f  8d48f0               lea ecx, [eax - 0x10]
// 008f3882  6a01                 push 1
// 008f3884  2bfa                 sub edi, edx
// 008f3886  57                   push edi
// 008f3887  2bc1                 sub eax, ecx
// 008f3889  50                   push eax
// 008f388a  52                   push edx
// 008f388b  894c2420             mov dword ptr [esp + 0x20], ecx
// 008f388f  51                   push ecx
// 008f3890  8d8ef0010000         lea ecx, [esi + 0x1f0]
// 008f3896  e8956bf1ff           call 0x80a430
// 008f389b  5f                   pop edi
// 008f389c  5e                   pop esi
// 008f389d  5d                   pop ebp
// 008f389e  5b                   pop ebx
// 008f389f  83c430               add esp, 0x30
// 008f38a2  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionPopupWnd.cpp (function ?RecalcLayout@CXTCaptionPopupWnd@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionPopupWnd.cpp
