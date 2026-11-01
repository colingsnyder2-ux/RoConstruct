// from server: 100% by auto
// roc 2007-03 005448f0  unit: seg_00540000  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005448f0
//
// 005448f0  8b442404             mov eax, dword ptr [esp + 4]
// 005448f4  83f850               cmp eax, 0x50
// 005448f7  7722                 ja 0x54491b
// 005448f9  0fb68838495400       movzx ecx, byte ptr [eax + 0x544938]
// 00544900  ff248d28495400       jmp dword ptr [ecx*4 + 0x544928]
// 00544907  680e000780           push 0x8007000e
// 0054490c  e8efc6ebff           call 0x401000
// 00544911  6857000780           push 0x80070057
// 00544916  e8e5c6ebff           call 0x401000
// 0054491b  6805400080           push 0x80004005
// 00544920  e8dbc6ebff           call 0x401000
// 00544925  c3                   ret 
// 00544926  8bff                 mov edi, edi
// 00544928  2549540007           and eax, 0x7005449
// 0054492d  49                   dec ecx
// 0054492e  54                   push esp
// 0054492f  0011                 add byte ptr [ecx], dl
// 00544931  49                   dec ecx
// 00544932  54                   push esp
// 00544933  001b                 add byte ptr [ebx], bl
// 00544935  49                   dec ecx
// 00544936  54                   push esp
// 00544937  0000                 add byte ptr [eax], al
// 00544939  0303                 add eax, dword ptr [ebx]
// 0054493b  0303                 add eax, dword ptr [ebx]
// 0054493d  0303                 add eax, dword ptr [ebx]
// 0054493f  0303                 add eax, dword ptr [ebx]
// 00544941  0303                 add eax, dword ptr [ebx]
// 00544943  0301                 add eax, dword ptr [ecx]
// 00544945  0303                 add eax, dword ptr [ebx]
// 00544947  0303                 add eax, dword ptr [ebx]
// 00544949  0303                 add eax, dword ptr [ebx]
// 0054494b  0303                 add eax, dword ptr [ebx]
// 0054494d  0302                 add eax, dword ptr [edx]
// 0054494f  0303                 add eax, dword ptr [ebx]
// 00544951  0303                 add eax, dword ptr [ebx]
// 00544953  0303                 add eax, dword ptr [ebx]
// 00544955  0303                 add eax, dword ptr [ebx]
// 00544957  0303                 add eax, dword ptr [ebx]
// 00544959  0302                 add eax, dword ptr [edx]
// 0054495b  0303                 add eax, dword ptr [ebx]
// 0054495d  0303                 add eax, dword ptr [ebx]
// 0054495f  0303                 add eax, dword ptr [ebx]
// 00544961  0303                 add eax, dword ptr [ebx]
// 00544963  0303                 add eax, dword ptr [ebx]
// 00544965  0303                 add eax, dword ptr [ebx]
// 00544967  0303                 add eax, dword ptr [ebx]
// 00544969  0303                 add eax, dword ptr [ebx]
// 0054496b  0303                 add eax, dword ptr [ebx]
// 0054496d  0303                 add eax, dword ptr [ebx]
// 0054496f  0303                 add eax, dword ptr [ebx]
// 00544971  0303                 add eax, dword ptr [ebx]
// 00544973  0303                 add eax, dword ptr [ebx]
// 00544975  0303                 add eax, dword ptr [ebx]
// 00544977  0303                 add eax, dword ptr [ebx]
// 00544979  0303                 add eax, dword ptr [ebx]
// 0054497b  0303                 add eax, dword ptr [ebx]
// 0054497d  0303                 add eax, dword ptr [ebx]
// 0054497f  0303                 add eax, dword ptr [ebx]
// 00544981  0303                 add eax, dword ptr [ebx]
// 00544983  0303                 add eax, dword ptr [ebx]
// 00544985  0303                 add eax, dword ptr [ebx]
// 00544987  0300                 add eax, dword ptr [eax]
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ?AtlCrtErrorCheck@ATL@@YAHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
