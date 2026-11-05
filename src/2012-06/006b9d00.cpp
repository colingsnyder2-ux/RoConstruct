// from server: 100% by auto
// roc 2012-06 006b9d00  unit: RBX::VStandardOut::?$sp_counted_impl_p  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006b9d00
//
// 006b9d00  8b442404             mov eax, dword ptr [esp + 4]
// 006b9d04  83f850               cmp eax, 0x50
// 006b9d07  7722                 ja 0x6b9d2b
// 006b9d09  0fb688489d6b00       movzx ecx, byte ptr [eax + 0x6b9d48]
// 006b9d10  ff248d389d6b00       jmp dword ptr [ecx*4 + 0x6b9d38]
// 006b9d17  680e000780           push 0x8007000e
// 006b9d1c  e88fa4d4ff           call 0x4041b0
// 006b9d21  6857000780           push 0x80070057
// 006b9d26  e885a4d4ff           call 0x4041b0
// 006b9d2b  6805400080           push 0x80004005
// 006b9d30  e87ba4d4ff           call 0x4041b0
// 006b9d35  c3                   ret 
// 006b9d36  8bff                 mov edi, edi
// 006b9d38  359d6b0017           xor eax, 0x17006b9d
// 006b9d3d  9d                   popfd 
// 006b9d3e  6b0021               imul eax, dword ptr [eax], 0x21
// 006b9d41  9d                   popfd 
// 006b9d42  6b002b               imul eax, dword ptr [eax], 0x2b
// 006b9d45  9d                   popfd 
// 006b9d46  6b0000               imul eax, dword ptr [eax], 0
// 006b9d49  0303                 add eax, dword ptr [ebx]
// 006b9d4b  0303                 add eax, dword ptr [ebx]
// 006b9d4d  0303                 add eax, dword ptr [ebx]
// 006b9d4f  0303                 add eax, dword ptr [ebx]
// 006b9d51  0303                 add eax, dword ptr [ebx]
// 006b9d53  0301                 add eax, dword ptr [ecx]
// 006b9d55  0303                 add eax, dword ptr [ebx]
// 006b9d57  0303                 add eax, dword ptr [ebx]
// 006b9d59  0303                 add eax, dword ptr [ebx]
// 006b9d5b  0303                 add eax, dword ptr [ebx]
// 006b9d5d  0302                 add eax, dword ptr [edx]
// 006b9d5f  0303                 add eax, dword ptr [ebx]
// 006b9d61  0303                 add eax, dword ptr [ebx]
// 006b9d63  0303                 add eax, dword ptr [ebx]
// 006b9d65  0303                 add eax, dword ptr [ebx]
// 006b9d67  0303                 add eax, dword ptr [ebx]
// 006b9d69  0302                 add eax, dword ptr [edx]
// 006b9d6b  0303                 add eax, dword ptr [ebx]
// 006b9d6d  0303                 add eax, dword ptr [ebx]
// 006b9d6f  0303                 add eax, dword ptr [ebx]
// 006b9d71  0303                 add eax, dword ptr [ebx]
// 006b9d73  0303                 add eax, dword ptr [ebx]
// 006b9d75  0303                 add eax, dword ptr [ebx]
// 006b9d77  0303                 add eax, dword ptr [ebx]
// 006b9d79  0303                 add eax, dword ptr [ebx]
// 006b9d7b  0303                 add eax, dword ptr [ebx]
// 006b9d7d  0303                 add eax, dword ptr [ebx]
// 006b9d7f  0303                 add eax, dword ptr [ebx]
// 006b9d81  0303                 add eax, dword ptr [ebx]
// 006b9d83  0303                 add eax, dword ptr [ebx]
// 006b9d85  0303                 add eax, dword ptr [ebx]
// 006b9d87  0303                 add eax, dword ptr [ebx]
// 006b9d89  0303                 add eax, dword ptr [ebx]
// 006b9d8b  0303                 add eax, dword ptr [ebx]
// 006b9d8d  0303                 add eax, dword ptr [ebx]
// 006b9d8f  0303                 add eax, dword ptr [ebx]
// 006b9d91  0303                 add eax, dword ptr [ebx]
// 006b9d93  0303                 add eax, dword ptr [ebx]
// 006b9d95  0303                 add eax, dword ptr [ebx]
// 006b9d97  0300                 add eax, dword ptr [eax]
// library mfc-9.0/atlmfc\src\mfc\appcore.cpp (function ?AtlCrtErrorCheck@ATL@@YAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/appcore.cpp
