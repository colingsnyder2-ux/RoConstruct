// from server: 100% by auto
// roc 2009-12 00855b80  unit: CXTPTabClientWnd::CSingleWorkspace  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00855b80
//
// 00855b80  53                   push ebx
// 00855b81  55                   push ebp
// 00855b82  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00855b86  56                   push esi
// 00855b87  8b7504               mov esi, dword ptr [ebp + 4]
// 00855b8a  8bd9                 mov ebx, ecx
// 00855b8c  81fe01020000         cmp esi, 0x201
// 00855b92  7420                 je 0x855bb4
// 00855b94  81fe04020000         cmp esi, 0x204
// 00855b9a  7418                 je 0x855bb4
// 00855b9c  81fe07020000         cmp esi, 0x207
// 00855ba2  7410                 je 0x855bb4
// 00855ba4  81fe03020000         cmp esi, 0x203
// 00855baa  7408                 je 0x855bb4
// 00855bac  81fe06020000         cmp esi, 0x206
// 00855bb2  752a                 jne 0x855bde
// 00855bb4  57                   push edi
// 00855bb5  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 00855bb8  e891dff9ff           call 0x7f3b4e
// 00855bbd  8b4020               mov eax, dword ptr [eax + 0x20]
// 00855bc0  57                   push edi
// 00855bc1  56                   push esi
// 00855bc2  6868280000           push 0x2868
// 00855bc7  50                   push eax
// 00855bc8  ff15c4cb9800         call dword ptr [0x98cbc4]
// 00855bce  5f                   pop edi
// 00855bcf  85c0                 test eax, eax
// 00855bd1  740b                 je 0x855bde
// 00855bd3  5e                   pop esi
// 00855bd4  5d                   pop ebp
// 00855bd5  b801000000           mov eax, 1
// 00855bda  5b                   pop ebx
// 00855bdb  c20400               ret 4
// 00855bde  55                   push ebp
// 00855bdf  8bcb                 mov ecx, ebx
// 00855be1  e87ae2f9ff           call 0x7f3e60
// 00855be6  5e                   pop esi
// 00855be7  5d                   pop ebp
// 00855be8  5b                   pop ebx
// 00855be9  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?PreTranslateMessage@CSingleWorkspace@CXTPTabClientWnd@@MAEHPAUtagMSG@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
