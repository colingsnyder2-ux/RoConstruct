// from server: 100% by auto
// roc 2009-12 004029f0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004029f0
//
// 004029f0  8b442404             mov eax, dword ptr [esp + 4]
// 004029f4  83f850               cmp eax, 0x50
// 004029f7  7713                 ja 0x402a0c
// 004029f9  0fb688242a4000       movzx ecx, byte ptr [eax + 0x402a24]
// 00402a00  ff248d142a4000       jmp dword ptr [ecx*4 + 0x402a14]
// 00402a07  e906113f00           jmp 0x7f3b12
// 00402a0c  e9fb103f00           jmp 0x7f3b0c
// 00402a11  c3                   ret 
// 00402a12  8bff                 mov edi, edi
// 00402a14  112a                 adc dword ptr [edx], ebp
// 00402a16  40                   inc eax
// 00402a17  0007                 add byte ptr [edi], al
// 00402a19  2a4000               sub al, byte ptr [eax]
// 00402a1c  0c2a                 or al, 0x2a
// 00402a1e  40                   inc eax
// 00402a1f  000c2a               add byte ptr [edx + ebp], cl
// 00402a22  40                   inc eax
// 00402a23  0000                 add byte ptr [eax], al
// 00402a25  0303                 add eax, dword ptr [ebx]
// 00402a27  0303                 add eax, dword ptr [ebx]
// 00402a29  0303                 add eax, dword ptr [ebx]
// 00402a2b  0303                 add eax, dword ptr [ebx]
// 00402a2d  0303                 add eax, dword ptr [ebx]
// 00402a2f  0301                 add eax, dword ptr [ecx]
// 00402a31  0303                 add eax, dword ptr [ebx]
// 00402a33  0303                 add eax, dword ptr [ebx]
// 00402a35  0303                 add eax, dword ptr [ebx]
// 00402a37  0303                 add eax, dword ptr [ebx]
// 00402a39  0302                 add eax, dword ptr [edx]
// 00402a3b  0303                 add eax, dword ptr [ebx]
// 00402a3d  0303                 add eax, dword ptr [ebx]
// 00402a3f  0303                 add eax, dword ptr [ebx]
// 00402a41  0303                 add eax, dword ptr [ebx]
// 00402a43  0303                 add eax, dword ptr [ebx]
// 00402a45  0302                 add eax, dword ptr [edx]
// 00402a47  0303                 add eax, dword ptr [ebx]
// 00402a49  0303                 add eax, dword ptr [ebx]
// 00402a4b  0303                 add eax, dword ptr [ebx]
// 00402a4d  0303                 add eax, dword ptr [ebx]
// 00402a4f  0303                 add eax, dword ptr [ebx]
// 00402a51  0303                 add eax, dword ptr [ebx]
// 00402a53  0303                 add eax, dword ptr [ebx]
// 00402a55  0303                 add eax, dword ptr [ebx]
// 00402a57  0303                 add eax, dword ptr [ebx]
// 00402a59  0303                 add eax, dword ptr [ebx]
// 00402a5b  0303                 add eax, dword ptr [ebx]
// 00402a5d  0303                 add eax, dword ptr [ebx]
// 00402a5f  0303                 add eax, dword ptr [ebx]
// 00402a61  0303                 add eax, dword ptr [ebx]
// 00402a63  0303                 add eax, dword ptr [ebx]
// 00402a65  0303                 add eax, dword ptr [ebx]
// 00402a67  0303                 add eax, dword ptr [ebx]
// 00402a69  0303                 add eax, dword ptr [ebx]
// 00402a6b  0303                 add eax, dword ptr [ebx]
// 00402a6d  0303                 add eax, dword ptr [ebx]
// 00402a6f  0303                 add eax, dword ptr [ebx]
// 00402a71  0303                 add eax, dword ptr [ebx]
// 00402a73  0300                 add eax, dword ptr [eax]
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ?AfxCrtErrorCheck@@YAHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
