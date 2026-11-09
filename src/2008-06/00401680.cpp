// from server: 100% by auto
// roc 2008-06 00401680  unit: CAboutRobloxDialog  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401680
//
// 00401680  8b442404             mov eax, dword ptr [esp + 4]
// 00401684  83f850               cmp eax, 0x50
// 00401687  7713                 ja 0x40169c
// 00401689  0fb688b4164000       movzx ecx, byte ptr [eax + 0x4016b4]
// 00401690  ff248da4164000       jmp dword ptr [ecx*4 + 0x4016a4]
// 00401697  e9eaef2900           jmp 0x6a0686
// 0040169c  e9a3f22900           jmp 0x6a0944
// 004016a1  c3                   ret 
// 004016a2  8bff                 mov edi, edi
// 004016a4  a116400097           mov eax, dword ptr [0x97004016]
// 004016a9  16                   push ss
// 004016aa  40                   inc eax
// 004016ab  009c1640009c16       add byte ptr [esi + edx + 0x169c0040], bl
// 004016b2  40                   inc eax
// 004016b3  0000                 add byte ptr [eax], al
// 004016b5  0303                 add eax, dword ptr [ebx]
// 004016b7  0303                 add eax, dword ptr [ebx]
// 004016b9  0303                 add eax, dword ptr [ebx]
// 004016bb  0303                 add eax, dword ptr [ebx]
// 004016bd  0303                 add eax, dword ptr [ebx]
// 004016bf  0301                 add eax, dword ptr [ecx]
// 004016c1  0303                 add eax, dword ptr [ebx]
// 004016c3  0303                 add eax, dword ptr [ebx]
// 004016c5  0303                 add eax, dword ptr [ebx]
// 004016c7  0303                 add eax, dword ptr [ebx]
// 004016c9  0302                 add eax, dword ptr [edx]
// 004016cb  0303                 add eax, dword ptr [ebx]
// 004016cd  0303                 add eax, dword ptr [ebx]
// 004016cf  0303                 add eax, dword ptr [ebx]
// 004016d1  0303                 add eax, dword ptr [ebx]
// 004016d3  0303                 add eax, dword ptr [ebx]
// 004016d5  0302                 add eax, dword ptr [edx]
// 004016d7  0303                 add eax, dword ptr [ebx]
// 004016d9  0303                 add eax, dword ptr [ebx]
// 004016db  0303                 add eax, dword ptr [ebx]
// 004016dd  0303                 add eax, dword ptr [ebx]
// 004016df  0303                 add eax, dword ptr [ebx]
// 004016e1  0303                 add eax, dword ptr [ebx]
// 004016e3  0303                 add eax, dword ptr [ebx]
// 004016e5  0303                 add eax, dword ptr [ebx]
// 004016e7  0303                 add eax, dword ptr [ebx]
// 004016e9  0303                 add eax, dword ptr [ebx]
// 004016eb  0303                 add eax, dword ptr [ebx]
// 004016ed  0303                 add eax, dword ptr [ebx]
// 004016ef  0303                 add eax, dword ptr [ebx]
// 004016f1  0303                 add eax, dword ptr [ebx]
// 004016f3  0303                 add eax, dword ptr [ebx]
// 004016f5  0303                 add eax, dword ptr [ebx]
// 004016f7  0303                 add eax, dword ptr [ebx]
// 004016f9  0303                 add eax, dword ptr [ebx]
// 004016fb  0303                 add eax, dword ptr [ebx]
// 004016fd  0303                 add eax, dword ptr [ebx]
// 004016ff  0303                 add eax, dword ptr [ebx]
// 00401701  0303                 add eax, dword ptr [ebx]
// 00401703  0300                 add eax, dword ptr [eax]
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ?AfxCrtErrorCheck@@YAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
