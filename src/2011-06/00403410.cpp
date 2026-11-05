// from server: 100% by auto
// roc 2011-06 00403410  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00403410
//
// 00403410  8b442404             mov eax, dword ptr [esp + 4]
// 00403414  83f850               cmp eax, 0x50
// 00403417  7713                 ja 0x40342c
// 00403419  0fb68844344000       movzx ecx, byte ptr [eax + 0x403444]
// 00403420  ff248d34344000       jmp dword ptr [ecx*4 + 0x403434]
// 00403427  e9e46e4000           jmp 0x80a310
// 0040342c  e9d96e4000           jmp 0x80a30a
// 00403431  c3                   ret 
// 00403432  8bff                 mov edi, edi
// 00403434  313440               xor dword ptr [eax + eax*2], esi
// 00403437  0027                 add byte ptr [edi], ah
// 00403439  3440                 xor al, 0x40
// 0040343b  002c34               add byte ptr [esp + esi], ch
// 0040343e  40                   inc eax
// 0040343f  002c34               add byte ptr [esp + esi], ch
// 00403442  40                   inc eax
// 00403443  0000                 add byte ptr [eax], al
// 00403445  0303                 add eax, dword ptr [ebx]
// 00403447  0303                 add eax, dword ptr [ebx]
// 00403449  0303                 add eax, dword ptr [ebx]
// 0040344b  0303                 add eax, dword ptr [ebx]
// 0040344d  0303                 add eax, dword ptr [ebx]
// 0040344f  0301                 add eax, dword ptr [ecx]
// 00403451  0303                 add eax, dword ptr [ebx]
// 00403453  0303                 add eax, dword ptr [ebx]
// 00403455  0303                 add eax, dword ptr [ebx]
// 00403457  0303                 add eax, dword ptr [ebx]
// 00403459  0302                 add eax, dword ptr [edx]
// 0040345b  0303                 add eax, dword ptr [ebx]
// 0040345d  0303                 add eax, dword ptr [ebx]
// 0040345f  0303                 add eax, dword ptr [ebx]
// 00403461  0303                 add eax, dword ptr [ebx]
// 00403463  0303                 add eax, dword ptr [ebx]
// 00403465  0302                 add eax, dword ptr [edx]
// 00403467  0303                 add eax, dword ptr [ebx]
// 00403469  0303                 add eax, dword ptr [ebx]
// 0040346b  0303                 add eax, dword ptr [ebx]
// 0040346d  0303                 add eax, dword ptr [ebx]
// 0040346f  0303                 add eax, dword ptr [ebx]
// 00403471  0303                 add eax, dword ptr [ebx]
// 00403473  0303                 add eax, dword ptr [ebx]
// 00403475  0303                 add eax, dword ptr [ebx]
// 00403477  0303                 add eax, dword ptr [ebx]
// 00403479  0303                 add eax, dword ptr [ebx]
// 0040347b  0303                 add eax, dword ptr [ebx]
// 0040347d  0303                 add eax, dword ptr [ebx]
// 0040347f  0303                 add eax, dword ptr [ebx]
// 00403481  0303                 add eax, dword ptr [ebx]
// 00403483  0303                 add eax, dword ptr [ebx]
// 00403485  0303                 add eax, dword ptr [ebx]
// 00403487  0303                 add eax, dword ptr [ebx]
// 00403489  0303                 add eax, dword ptr [ebx]
// 0040348b  0303                 add eax, dword ptr [ebx]
// 0040348d  0303                 add eax, dword ptr [ebx]
// 0040348f  0303                 add eax, dword ptr [ebx]
// 00403491  0303                 add eax, dword ptr [ebx]
// 00403493  0300                 add eax, dword ptr [eax]
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ?AfxCrtErrorCheck@@YAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
