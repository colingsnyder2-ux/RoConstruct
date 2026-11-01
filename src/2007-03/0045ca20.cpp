// from server: 100% by auto
// roc 2007-03 0045ca20  unit: seg_00450000  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0045ca20
//
// 0045ca20  83ec18               sub esp, 0x18
// 0045ca23  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0045ca27  8b5004               mov edx, dword ptr [eax + 4]
// 0045ca2a  56                   push esi
// 0045ca2b  8bf1                 mov esi, ecx
// 0045ca2d  8b08                 mov ecx, dword ptr [eax]
// 0045ca2f  8d44240c             lea eax, [esp + 0xc]
// 0045ca33  894c2404             mov dword ptr [esp + 4], ecx
// 0045ca37  50                   push eax
// 0045ca38  8d4c2408             lea ecx, [esp + 8]
// 0045ca3c  8954240c             mov dword ptr [esp + 0xc], edx
// 0045ca40  e88be6ffff           call 0x45b0d0
// 0045ca45  84c0                 test al, al
// 0045ca47  7420                 je 0x45ca69
// 0045ca49  8d4c240c             lea ecx, [esp + 0xc]
// 0045ca4d  56                   push esi
// 0045ca4e  51                   push ecx
// 0045ca4f  e8cce5ffff           call 0x45b020
// 0045ca54  83c408               add esp, 8
// 0045ca57  85c0                 test eax, eax
// 0045ca59  740e                 je 0x45ca69
// 0045ca5b  33c0                 xor eax, eax
// 0045ca5d  894608               mov dword ptr [esi + 8], eax
// 0045ca60  8bc6                 mov eax, esi
// 0045ca62  5e                   pop esi
// 0045ca63  83c418               add esp, 0x18
// 0045ca66  c20400               ret 4
// 0045ca69  b801000000           mov eax, 1
// 0045ca6e  894608               mov dword ptr [esi + 8], eax
// 0045ca71  8bc6                 mov eax, esi
// 0045ca73  5e                   pop esi
// 0045ca74  83c418               add esp, 0x18
// 0045ca77  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxshelllistctrl.cpp (function ??4COleDateTime@ATL@@QAEAAV01@AB_J@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxshelllistctrl.cpp
