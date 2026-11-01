// from server: 100% by auto
// roc 2009-06 0077ab00  unit: CXTPTabClientWnd::CSingleWorkspace  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077ab00
//
// 0077ab00  53                   push ebx
// 0077ab01  55                   push ebp
// 0077ab02  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0077ab06  56                   push esi
// 0077ab07  8b7504               mov esi, dword ptr [ebp + 4]
// 0077ab0a  8bd9                 mov ebx, ecx
// 0077ab0c  81fe01020000         cmp esi, 0x201
// 0077ab12  7420                 je 0x77ab34
// 0077ab14  81fe04020000         cmp esi, 0x204
// 0077ab1a  7418                 je 0x77ab34
// 0077ab1c  81fe07020000         cmp esi, 0x207
// 0077ab22  7410                 je 0x77ab34
// 0077ab24  81fe03020000         cmp esi, 0x203
// 0077ab2a  7408                 je 0x77ab34
// 0077ab2c  81fe06020000         cmp esi, 0x206
// 0077ab32  752a                 jne 0x77ab5e
// 0077ab34  57                   push edi
// 0077ab35  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 0077ab38  e8e9e1f9ff           call 0x718d26
// 0077ab3d  8b4020               mov eax, dword ptr [eax + 0x20]
// 0077ab40  57                   push edi
// 0077ab41  56                   push esi
// 0077ab42  6868280000           push 0x2868
// 0077ab47  50                   push eax
// 0077ab48  ff1590ee8900         call dword ptr [0x89ee90]
// 0077ab4e  5f                   pop edi
// 0077ab4f  85c0                 test eax, eax
// 0077ab51  740b                 je 0x77ab5e
// 0077ab53  5e                   pop esi
// 0077ab54  5d                   pop ebp
// 0077ab55  b801000000           mov eax, 1
// 0077ab5a  5b                   pop ebx
// 0077ab5b  c20400               ret 4
// 0077ab5e  55                   push ebp
// 0077ab5f  8bcb                 mov ecx, ebx
// 0077ab61  e8d2e4f9ff           call 0x719038
// 0077ab66  5e                   pop esi
// 0077ab67  5d                   pop ebp
// 0077ab68  5b                   pop ebx
// 0077ab69  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?PreTranslateMessage@CSingleWorkspace@CXTPTabClientWnd@@MAEHPAUtagMSG@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
