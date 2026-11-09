// from server: 100% by auto
// roc 2009-06 005e1e00  unit: RBX::VStandardOut::?$sp_counted_impl_p  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005e1e00
//
// 005e1e00  8b442404             mov eax, dword ptr [esp + 4]
// 005e1e04  83f850               cmp eax, 0x50
// 005e1e07  7722                 ja 0x5e1e2b
// 005e1e09  0fb688481e5e00       movzx ecx, byte ptr [eax + 0x5e1e48]
// 005e1e10  ff248d381e5e00       jmp dword ptr [ecx*4 + 0x5e1e38]
// 005e1e17  680e000780           push 0x8007000e
// 005e1e1c  e88f10e2ff           call 0x402eb0
// 005e1e21  6857000780           push 0x80070057
// 005e1e26  e88510e2ff           call 0x402eb0
// 005e1e2b  6805400080           push 0x80004005
// 005e1e30  e87b10e2ff           call 0x402eb0
// 005e1e35  c3                   ret 
// 005e1e36  8bff                 mov edi, edi
// 005e1e38  351e5e0017           xor eax, 0x17005e1e
// 005e1e3d  1e                   push ds
// 005e1e3e  5e                   pop esi
// 005e1e3f  0021                 add byte ptr [ecx], ah
// 005e1e41  1e                   push ds
// 005e1e42  5e                   pop esi
// 005e1e43  002b                 add byte ptr [ebx], ch
// 005e1e45  1e                   push ds
// 005e1e46  5e                   pop esi
// 005e1e47  0000                 add byte ptr [eax], al
// 005e1e49  0303                 add eax, dword ptr [ebx]
// 005e1e4b  0303                 add eax, dword ptr [ebx]
// 005e1e4d  0303                 add eax, dword ptr [ebx]
// 005e1e4f  0303                 add eax, dword ptr [ebx]
// 005e1e51  0303                 add eax, dword ptr [ebx]
// 005e1e53  0301                 add eax, dword ptr [ecx]
// 005e1e55  0303                 add eax, dword ptr [ebx]
// 005e1e57  0303                 add eax, dword ptr [ebx]
// 005e1e59  0303                 add eax, dword ptr [ebx]
// 005e1e5b  0303                 add eax, dword ptr [ebx]
// 005e1e5d  0302                 add eax, dword ptr [edx]
// 005e1e5f  0303                 add eax, dword ptr [ebx]
// 005e1e61  0303                 add eax, dword ptr [ebx]
// 005e1e63  0303                 add eax, dword ptr [ebx]
// 005e1e65  0303                 add eax, dword ptr [ebx]
// 005e1e67  0303                 add eax, dword ptr [ebx]
// 005e1e69  0302                 add eax, dword ptr [edx]
// 005e1e6b  0303                 add eax, dword ptr [ebx]
// 005e1e6d  0303                 add eax, dword ptr [ebx]
// 005e1e6f  0303                 add eax, dword ptr [ebx]
// 005e1e71  0303                 add eax, dword ptr [ebx]
// 005e1e73  0303                 add eax, dword ptr [ebx]
// 005e1e75  0303                 add eax, dword ptr [ebx]
// 005e1e77  0303                 add eax, dword ptr [ebx]
// 005e1e79  0303                 add eax, dword ptr [ebx]
// 005e1e7b  0303                 add eax, dword ptr [ebx]
// 005e1e7d  0303                 add eax, dword ptr [ebx]
// 005e1e7f  0303                 add eax, dword ptr [ebx]
// 005e1e81  0303                 add eax, dword ptr [ebx]
// 005e1e83  0303                 add eax, dword ptr [ebx]
// 005e1e85  0303                 add eax, dword ptr [ebx]
// 005e1e87  0303                 add eax, dword ptr [ebx]
// 005e1e89  0303                 add eax, dword ptr [ebx]
// 005e1e8b  0303                 add eax, dword ptr [ebx]
// 005e1e8d  0303                 add eax, dword ptr [ebx]
// 005e1e8f  0303                 add eax, dword ptr [ebx]
// 005e1e91  0303                 add eax, dword ptr [ebx]
// 005e1e93  0303                 add eax, dword ptr [ebx]
// 005e1e95  0303                 add eax, dword ptr [ebx]
// 005e1e97  0300                 add eax, dword ptr [eax]
// library mfc-9.0/atlmfc\src\mfc\appcore.cpp (function ?AtlCrtErrorCheck@ATL@@YAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/appcore.cpp
