// from server: 100% by auto
// roc 2010-06 008448c0  unit: CXTPDockContext  size: 275 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008448c0
//
// 008448c0  83ec30               sub esp, 0x30
// 008448c3  53                   push ebx
// 008448c4  56                   push esi
// 008448c5  8bf1                 mov esi, ecx
// 008448c7  8b460c               mov eax, dword ptr [esi + 0xc]
// 008448ca  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 008448ce  8b5610               mov edx, dword ptr [esi + 0x10]
// 008448d1  57                   push edi
// 008448d2  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 008448d6  2bc8                 sub ecx, eax
// 008448d8  8b4608               mov eax, dword ptr [esi + 8]
// 008448db  2bfa                 sub edi, edx
// 008448dd  83f80a               cmp eax, 0xa
// 008448e0  740a                 je 0x8448ec
// 008448e2  83f80d               cmp eax, 0xd
// 008448e5  7405                 je 0x8448ec
// 008448e7  83f810               cmp eax, 0x10
// 008448ea  7503                 jne 0x8448ef
// 008448ec  014e40               add dword ptr [esi + 0x40], ecx
// 008448ef  83f80b               cmp eax, 0xb
// 008448f2  740a                 je 0x8448fe
// 008448f4  83f80e               cmp eax, 0xe
// 008448f7  7405                 je 0x8448fe
// 008448f9  83f811               cmp eax, 0x11
// 008448fc  7503                 jne 0x844901
// 008448fe  014e48               add dword ptr [esi + 0x48], ecx
// 00844901  83f80c               cmp eax, 0xc
// 00844904  740a                 je 0x844910
// 00844906  83f80e               cmp eax, 0xe
// 00844909  7405                 je 0x844910
// 0084490b  83f80d               cmp eax, 0xd
// 0084490e  7503                 jne 0x844913
// 00844910  017e44               add dword ptr [esi + 0x44], edi
// 00844913  83f80f               cmp eax, 0xf
// 00844916  740a                 je 0x844922
// 00844918  83f811               cmp eax, 0x11
// 0084491b  7405                 je 0x844922
// 0084491d  83f810               cmp eax, 0x10
// 00844920  7503                 jne 0x844925
// 00844922  017e4c               add dword ptr [esi + 0x4c], edi
// 00844925  8b4e04               mov ecx, dword ptr [esi + 4]
// 00844928  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0084492b  8d44240c             lea eax, [esp + 0xc]
// 0084492f  50                   push eax
// 00844930  52                   push edx
// 00844931  ff153cbc9e00         call dword ptr [0x9ebc3c]
// 00844937  8b4648               mov eax, dword ptr [esi + 0x48]
// 0084493a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0084493e  2b4640               sub eax, dword ptr [esi + 0x40]
// 00844941  8b564c               mov edx, dword ptr [esi + 0x4c]
// 00844944  2b4c240c             sub ecx, dword ptr [esp + 0xc]
// 00844948  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0084494c  2b5644               sub edx, dword ptr [esi + 0x44]
// 0084494f  2b5c2410             sub ebx, dword ptr [esp + 0x10]
// 00844953  8d7e40               lea edi, [esi + 0x40]
// 00844956  3bc8                 cmp ecx, eax
// 00844958  7504                 jne 0x84495e
// 0084495a  3bda                 cmp ebx, edx
// 0084495c  745e                 je 0x8449bc
// 0084495e  8b4604               mov eax, dword ptr [esi + 4]
// 00844961  50                   push eax
// 00844962  8d4c2420             lea ecx, [esp + 0x20]
// 00844966  51                   push ecx
// 00844967  e864bffaff           call 0x7f08d0
// 0084496c  8bc8                 mov ecx, eax
// 0084496e  e8fdbafaff           call 0x7f0470
// 00844973  57                   push edi
// 00844974  50                   push eax
// 00844975  8d542434             lea edx, [esp + 0x34]
// 00844979  52                   push edx
// 0084497a  ff15a4ba9e00         call dword ptr [0x9ebaa4]
// 00844980  85c0                 test eax, eax
// 00844982  7438                 je 0x8449bc
// 00844984  8b4608               mov eax, dword ptr [esi + 8]
// 00844987  8b0f                 mov ecx, dword ptr [edi]
// 00844989  8b5704               mov edx, dword ptr [edi + 4]
// 0084498c  50                   push eax
// 0084498d  83ec10               sub esp, 0x10
// 00844990  8bc4                 mov eax, esp
// 00844992  8908                 mov dword ptr [eax], ecx
// 00844994  8b4f08               mov ecx, dword ptr [edi + 8]
// 00844997  895004               mov dword ptr [eax + 4], edx
// 0084499a  8b570c               mov edx, dword ptr [edi + 0xc]
// 0084499d  894808               mov dword ptr [eax + 8], ecx
// 008449a0  8b4e04               mov ecx, dword ptr [esi + 4]
// 008449a3  89500c               mov dword ptr [eax + 0xc], edx
// 008449a6  e805c00500           call 0x8a09b0
// 008449ab  8b4e04               mov ecx, dword ptr [esi + 4]
// 008449ae  8b01                 mov eax, dword ptr [ecx]
// 008449b0  8b90ac010000         mov edx, dword ptr [eax + 0x1ac]
// 008449b6  6a01                 push 1
// 008449b8  6a00                 push 0
// 008449ba  ffd2                 call edx
// 008449bc  8b442440             mov eax, dword ptr [esp + 0x40]
// 008449c0  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 008449c4  5f                   pop edi
// 008449c5  89460c               mov dword ptr [esi + 0xc], eax
// 008449c8  894e10               mov dword ptr [esi + 0x10], ecx
// 008449cb  5e                   pop esi
// 008449cc  5b                   pop ebx
// 008449cd  83c430               add esp, 0x30
// 008449d0  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPDockContext.cpp (function ?Resize@CXTPDockContext@@IAEXVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPDockContext.cpp
