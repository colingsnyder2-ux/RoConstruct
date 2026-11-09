// from server: 100% by auto
// roc 2010-06 00809ab0  unit: CXTPTabClientWnd::CSingleWorkspace  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00809ab0
//
// 00809ab0  53                   push ebx
// 00809ab1  55                   push ebp
// 00809ab2  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00809ab6  56                   push esi
// 00809ab7  8b7504               mov esi, dword ptr [ebp + 4]
// 00809aba  8bd9                 mov ebx, ecx
// 00809abc  81fe01020000         cmp esi, 0x201
// 00809ac2  7420                 je 0x809ae4
// 00809ac4  81fe04020000         cmp esi, 0x204
// 00809aca  7418                 je 0x809ae4
// 00809acc  81fe07020000         cmp esi, 0x207
// 00809ad2  7410                 je 0x809ae4
// 00809ad4  81fe03020000         cmp esi, 0x203
// 00809ada  7408                 je 0x809ae4
// 00809adc  81fe06020000         cmp esi, 0x206
// 00809ae2  752a                 jne 0x809b0e
// 00809ae4  57                   push edi
// 00809ae5  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 00809ae8  e8a1e1f9ff           call 0x7a7c8e
// 00809aed  8b4020               mov eax, dword ptr [eax + 0x20]
// 00809af0  57                   push edi
// 00809af1  56                   push esi
// 00809af2  6868280000           push 0x2868
// 00809af7  50                   push eax
// 00809af8  ff1554ba9e00         call dword ptr [0x9eba54]
// 00809afe  5f                   pop edi
// 00809aff  85c0                 test eax, eax
// 00809b01  740b                 je 0x809b0e
// 00809b03  5e                   pop esi
// 00809b04  5d                   pop ebp
// 00809b05  b801000000           mov eax, 1
// 00809b0a  5b                   pop ebx
// 00809b0b  c20400               ret 4
// 00809b0e  55                   push ebp
// 00809b0f  8bcb                 mov ecx, ebx
// 00809b11  e88ae4f9ff           call 0x7a7fa0
// 00809b16  5e                   pop esi
// 00809b17  5d                   pop ebp
// 00809b18  5b                   pop ebx
// 00809b19  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?PreTranslateMessage@CSingleWorkspace@CXTPTabClientWnd@@MAEHPAUtagMSG@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
