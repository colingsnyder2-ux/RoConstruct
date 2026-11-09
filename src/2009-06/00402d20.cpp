// from server: 100% by auto
// roc 2009-06 00402d20  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00402d20
//
// 00402d20  8b442404             mov eax, dword ptr [esp + 4]
// 00402d24  83f850               cmp eax, 0x50
// 00402d27  7713                 ja 0x402d3c
// 00402d29  0fb688542d4000       movzx ecx, byte ptr [eax + 0x402d54]
// 00402d30  ff248d442d4000       jmp dword ptr [ecx*4 + 0x402d44]
// 00402d37  e9ae5f3100           jmp 0x718cea
// 00402d3c  e9a35f3100           jmp 0x718ce4
// 00402d41  c3                   ret 
// 00402d42  8bff                 mov edi, edi
// 00402d44  41                   inc ecx
// 00402d45  2d4000372d           sub eax, 0x2d370040
// 00402d4a  40                   inc eax
// 00402d4b  003c2d40003c2d       add byte ptr [ebp + 0x2d3c0040], bh
// 00402d52  40                   inc eax
// 00402d53  0000                 add byte ptr [eax], al
// 00402d55  0303                 add eax, dword ptr [ebx]
// 00402d57  0303                 add eax, dword ptr [ebx]
// 00402d59  0303                 add eax, dword ptr [ebx]
// 00402d5b  0303                 add eax, dword ptr [ebx]
// 00402d5d  0303                 add eax, dword ptr [ebx]
// 00402d5f  0301                 add eax, dword ptr [ecx]
// 00402d61  0303                 add eax, dword ptr [ebx]
// 00402d63  0303                 add eax, dword ptr [ebx]
// 00402d65  0303                 add eax, dword ptr [ebx]
// 00402d67  0303                 add eax, dword ptr [ebx]
// 00402d69  0302                 add eax, dword ptr [edx]
// 00402d6b  0303                 add eax, dword ptr [ebx]
// 00402d6d  0303                 add eax, dword ptr [ebx]
// 00402d6f  0303                 add eax, dword ptr [ebx]
// 00402d71  0303                 add eax, dword ptr [ebx]
// 00402d73  0303                 add eax, dword ptr [ebx]
// 00402d75  0302                 add eax, dword ptr [edx]
// 00402d77  0303                 add eax, dword ptr [ebx]
// 00402d79  0303                 add eax, dword ptr [ebx]
// 00402d7b  0303                 add eax, dword ptr [ebx]
// 00402d7d  0303                 add eax, dword ptr [ebx]
// 00402d7f  0303                 add eax, dword ptr [ebx]
// 00402d81  0303                 add eax, dword ptr [ebx]
// 00402d83  0303                 add eax, dword ptr [ebx]
// 00402d85  0303                 add eax, dword ptr [ebx]
// 00402d87  0303                 add eax, dword ptr [ebx]
// 00402d89  0303                 add eax, dword ptr [ebx]
// 00402d8b  0303                 add eax, dword ptr [ebx]
// 00402d8d  0303                 add eax, dword ptr [ebx]
// 00402d8f  0303                 add eax, dword ptr [ebx]
// 00402d91  0303                 add eax, dword ptr [ebx]
// 00402d93  0303                 add eax, dword ptr [ebx]
// 00402d95  0303                 add eax, dword ptr [ebx]
// 00402d97  0303                 add eax, dword ptr [ebx]
// 00402d99  0303                 add eax, dword ptr [ebx]
// 00402d9b  0303                 add eax, dword ptr [ebx]
// 00402d9d  0303                 add eax, dword ptr [ebx]
// 00402d9f  0303                 add eax, dword ptr [ebx]
// 00402da1  0303                 add eax, dword ptr [ebx]
// 00402da3  0300                 add eax, dword ptr [eax]
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ?AfxCrtErrorCheck@@YAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
