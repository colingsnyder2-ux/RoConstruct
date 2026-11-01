// from server: 100% by auto
// roc 2009-12 0063eb20  unit: RBX::VStandardOut::?$sp_counted_impl_p  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0063eb20
//
// 0063eb20  8b442404             mov eax, dword ptr [esp + 4]
// 0063eb24  83f850               cmp eax, 0x50
// 0063eb27  7722                 ja 0x63eb4b
// 0063eb29  0fb68868eb6300       movzx ecx, byte ptr [eax + 0x63eb68]
// 0063eb30  ff248d58eb6300       jmp dword ptr [ecx*4 + 0x63eb58]
// 0063eb37  680e000780           push 0x8007000e
// 0063eb3c  e83f40dcff           call 0x402b80
// 0063eb41  6857000780           push 0x80070057
// 0063eb46  e83540dcff           call 0x402b80
// 0063eb4b  6805400080           push 0x80004005
// 0063eb50  e82b40dcff           call 0x402b80
// 0063eb55  c3                   ret 
// 0063eb56  8bff                 mov edi, edi
// 0063eb58  55                   push ebp
// 0063eb59  eb63                 jmp 0x63ebbe
// 0063eb5b  0037                 add byte ptr [edi], dh
// 0063eb5d  eb63                 jmp 0x63ebc2
// 0063eb5f  0041eb               add byte ptr [ecx - 0x15], al
// 0063eb62  6300                 arpl word ptr [eax], ax
// 0063eb64  4b                   dec ebx
// 0063eb65  eb63                 jmp 0x63ebca
// 0063eb67  0000                 add byte ptr [eax], al
// 0063eb69  0303                 add eax, dword ptr [ebx]
// 0063eb6b  0303                 add eax, dword ptr [ebx]
// 0063eb6d  0303                 add eax, dword ptr [ebx]
// 0063eb6f  0303                 add eax, dword ptr [ebx]
// 0063eb71  0303                 add eax, dword ptr [ebx]
// 0063eb73  0301                 add eax, dword ptr [ecx]
// 0063eb75  0303                 add eax, dword ptr [ebx]
// 0063eb77  0303                 add eax, dword ptr [ebx]
// 0063eb79  0303                 add eax, dword ptr [ebx]
// 0063eb7b  0303                 add eax, dword ptr [ebx]
// 0063eb7d  0302                 add eax, dword ptr [edx]
// 0063eb7f  0303                 add eax, dword ptr [ebx]
// 0063eb81  0303                 add eax, dword ptr [ebx]
// 0063eb83  0303                 add eax, dword ptr [ebx]
// 0063eb85  0303                 add eax, dword ptr [ebx]
// 0063eb87  0303                 add eax, dword ptr [ebx]
// 0063eb89  0302                 add eax, dword ptr [edx]
// 0063eb8b  0303                 add eax, dword ptr [ebx]
// 0063eb8d  0303                 add eax, dword ptr [ebx]
// 0063eb8f  0303                 add eax, dword ptr [ebx]
// 0063eb91  0303                 add eax, dword ptr [ebx]
// 0063eb93  0303                 add eax, dword ptr [ebx]
// 0063eb95  0303                 add eax, dword ptr [ebx]
// 0063eb97  0303                 add eax, dword ptr [ebx]
// 0063eb99  0303                 add eax, dword ptr [ebx]
// 0063eb9b  0303                 add eax, dword ptr [ebx]
// 0063eb9d  0303                 add eax, dword ptr [ebx]
// 0063eb9f  0303                 add eax, dword ptr [ebx]
// 0063eba1  0303                 add eax, dword ptr [ebx]
// 0063eba3  0303                 add eax, dword ptr [ebx]
// 0063eba5  0303                 add eax, dword ptr [ebx]
// 0063eba7  0303                 add eax, dword ptr [ebx]
// 0063eba9  0303                 add eax, dword ptr [ebx]
// 0063ebab  0303                 add eax, dword ptr [ebx]
// 0063ebad  0303                 add eax, dword ptr [ebx]
// 0063ebaf  0303                 add eax, dword ptr [ebx]
// 0063ebb1  0303                 add eax, dword ptr [ebx]
// 0063ebb3  0303                 add eax, dword ptr [ebx]
// 0063ebb5  0303                 add eax, dword ptr [ebx]
// 0063ebb7  0300                 add eax, dword ptr [eax]
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ?AtlCrtErrorCheck@ATL@@YAHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
