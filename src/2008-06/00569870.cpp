// from server: 100% by auto
// roc 2008-06 00569870  unit: RBX::StandardOut  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00569870
//
// 00569870  8b442404             mov eax, dword ptr [esp + 4]
// 00569874  83f850               cmp eax, 0x50
// 00569877  7722                 ja 0x56989b
// 00569879  0fb688b8985600       movzx ecx, byte ptr [eax + 0x5698b8]
// 00569880  ff248da8985600       jmp dword ptr [ecx*4 + 0x5698a8]
// 00569887  680e000780           push 0x8007000e
// 0056988c  e86f77e9ff           call 0x401000
// 00569891  6857000780           push 0x80070057
// 00569896  e86577e9ff           call 0x401000
// 0056989b  6805400080           push 0x80004005
// 005698a0  e85b77e9ff           call 0x401000
// 005698a5  c3                   ret 
// 005698a6  8bff                 mov edi, edi
// 005698a8  a5                   movsd dword ptr es:[edi], dword ptr [esi]
// 005698a9  98                   cwde 
// 005698aa  56                   push esi
// 005698ab  008798560091         add byte ptr [edi - 0x6effa968], al
// 005698b1  98                   cwde 
// 005698b2  56                   push esi
// 005698b3  009b98560000         add byte ptr [ebx + 0x5698], bl
// 005698b9  0303                 add eax, dword ptr [ebx]
// 005698bb  0303                 add eax, dword ptr [ebx]
// 005698bd  0303                 add eax, dword ptr [ebx]
// 005698bf  0303                 add eax, dword ptr [ebx]
// 005698c1  0303                 add eax, dword ptr [ebx]
// 005698c3  0301                 add eax, dword ptr [ecx]
// 005698c5  0303                 add eax, dword ptr [ebx]
// 005698c7  0303                 add eax, dword ptr [ebx]
// 005698c9  0303                 add eax, dword ptr [ebx]
// 005698cb  0303                 add eax, dword ptr [ebx]
// 005698cd  0302                 add eax, dword ptr [edx]
// 005698cf  0303                 add eax, dword ptr [ebx]
// 005698d1  0303                 add eax, dword ptr [ebx]
// 005698d3  0303                 add eax, dword ptr [ebx]
// 005698d5  0303                 add eax, dword ptr [ebx]
// 005698d7  0303                 add eax, dword ptr [ebx]
// 005698d9  0302                 add eax, dword ptr [edx]
// 005698db  0303                 add eax, dword ptr [ebx]
// 005698dd  0303                 add eax, dword ptr [ebx]
// 005698df  0303                 add eax, dword ptr [ebx]
// 005698e1  0303                 add eax, dword ptr [ebx]
// 005698e3  0303                 add eax, dword ptr [ebx]
// 005698e5  0303                 add eax, dword ptr [ebx]
// 005698e7  0303                 add eax, dword ptr [ebx]
// 005698e9  0303                 add eax, dword ptr [ebx]
// 005698eb  0303                 add eax, dword ptr [ebx]
// 005698ed  0303                 add eax, dword ptr [ebx]
// 005698ef  0303                 add eax, dword ptr [ebx]
// 005698f1  0303                 add eax, dword ptr [ebx]
// 005698f3  0303                 add eax, dword ptr [ebx]
// 005698f5  0303                 add eax, dword ptr [ebx]
// 005698f7  0303                 add eax, dword ptr [ebx]
// 005698f9  0303                 add eax, dword ptr [ebx]
// 005698fb  0303                 add eax, dword ptr [ebx]
// 005698fd  0303                 add eax, dword ptr [ebx]
// 005698ff  0303                 add eax, dword ptr [ebx]
// 00569901  0303                 add eax, dword ptr [ebx]
// 00569903  0303                 add eax, dword ptr [ebx]
// 00569905  0303                 add eax, dword ptr [ebx]
// 00569907  0300                 add eax, dword ptr [eax]
// library mfc-9.0/atlmfc\src\mfc\appcore.cpp (function ?AtlCrtErrorCheck@ATL@@YAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/appcore.cpp
