// from server: 100% by auto
// roc 2007-03 005f9c70  unit: seg_005f0000  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f9c70
//
// 005f9c70  53                   push ebx
// 005f9c71  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005f9c75  55                   push ebp
// 005f9c76  8b2b                 mov ebp, dword ptr [ebx]
// 005f9c78  57                   push edi
// 005f9c79  8bf8                 mov edi, eax
// 005f9c7b  8b4608               mov eax, dword ptr [esi + 8]
// 005f9c7e  8928                 mov dword ptr [eax], ebp
// 005f9c80  8b6b04               mov ebp, dword ptr [ebx + 4]
// 005f9c83  896804               mov dword ptr [eax + 4], ebp
// 005f9c86  8b5b08               mov ebx, dword ptr [ebx + 8]
// 005f9c89  895808               mov dword ptr [eax + 8], ebx
// 005f9c8c  8b1f                 mov ebx, dword ptr [edi]
// 005f9c8e  8b4608               mov eax, dword ptr [esi + 8]
// 005f9c91  895810               mov dword ptr [eax + 0x10], ebx
// 005f9c94  8b5f04               mov ebx, dword ptr [edi + 4]
// 005f9c97  895814               mov dword ptr [eax + 0x14], ebx
// 005f9c9a  8b7f08               mov edi, dword ptr [edi + 8]
// 005f9c9d  897818               mov dword ptr [eax + 0x18], edi
// 005f9ca0  8b3a                 mov edi, dword ptr [edx]
// 005f9ca2  83c010               add eax, 0x10
// 005f9ca5  8b4608               mov eax, dword ptr [esi + 8]
// 005f9ca8  897820               mov dword ptr [eax + 0x20], edi
// 005f9cab  8b7a04               mov edi, dword ptr [edx + 4]
// 005f9cae  897824               mov dword ptr [eax + 0x24], edi
// 005f9cb1  8b5208               mov edx, dword ptr [edx + 8]
// 005f9cb4  83c020               add eax, 0x20
// 005f9cb7  895008               mov dword ptr [eax + 8], edx
// 005f9cba  8b4608               mov eax, dword ptr [esi + 8]
// 005f9cbd  8b11                 mov edx, dword ptr [ecx]
// 005f9cbf  83c030               add eax, 0x30
// 005f9cc2  8910                 mov dword ptr [eax], edx
// 005f9cc4  8b5104               mov edx, dword ptr [ecx + 4]
// 005f9cc7  895004               mov dword ptr [eax + 4], edx
// 005f9cca  8b4908               mov ecx, dword ptr [ecx + 8]
// 005f9ccd  894808               mov dword ptr [eax + 8], ecx
// 005f9cd0  8b561c               mov edx, dword ptr [esi + 0x1c]
// 005f9cd3  2b5608               sub edx, dword ptr [esi + 8]
// 005f9cd6  5f                   pop edi
// 005f9cd7  83fa40               cmp edx, 0x40
// 005f9cda  5d                   pop ebp
// 005f9cdb  5b                   pop ebx
// 005f9cdc  7f0b                 jg 0x5f9ce9
// 005f9cde  6a04                 push 4
// 005f9ce0  56                   push esi
// 005f9ce1  e80a60fcff           call 0x5bfcf0
// 005f9ce6  83c408               add esp, 8
// 005f9ce9  83460840             add dword ptr [esi + 8], 0x40
// 005f9ced  8b4608               mov eax, dword ptr [esi + 8]
// 005f9cf0  6a00                 push 0
// 005f9cf2  83c0c0               add eax, -0x40
// 005f9cf5  50                   push eax
// 005f9cf6  56                   push esi
// 005f9cf7  e8b467fcff           call 0x5c04b0
// 005f9cfc  83c40c               add esp, 0xc
// 005f9cff  c3                   ret 
// library lua-5.1.1/lvm.c (function _callTM)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lvm.c
