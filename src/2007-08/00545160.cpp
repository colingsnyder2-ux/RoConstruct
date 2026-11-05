// from server: 100% by auto
// roc 2007-08 00545160  unit: RBX::VDebugSettings::?$GlobalSettingsItem  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00545160
//
// 00545160  8b442404             mov eax, dword ptr [esp + 4]
// 00545164  83f850               cmp eax, 0x50
// 00545167  7722                 ja 0x54518b
// 00545169  0fb688a8515400       movzx ecx, byte ptr [eax + 0x5451a8]
// 00545170  ff248d98515400       jmp dword ptr [ecx*4 + 0x545198]
// 00545177  680e000780           push 0x8007000e
// 0054517c  e87fbeebff           call 0x401000
// 00545181  6857000780           push 0x80070057
// 00545186  e875beebff           call 0x401000
// 0054518b  6805400080           push 0x80004005
// 00545190  e86bbeebff           call 0x401000
// 00545195  c3                   ret 
// 00545196  8bff                 mov edi, edi
// 00545198  95                   xchg ebp, eax
// 00545199  51                   push ecx
// 0054519a  54                   push esp
// 0054519b  007751               add byte ptr [edi + 0x51], dh
// 0054519e  54                   push esp
// 0054519f  00815154008b         add byte ptr [ecx - 0x74ffabaf], al
// 005451a5  51                   push ecx
// 005451a6  54                   push esp
// 005451a7  0000                 add byte ptr [eax], al
// 005451a9  0303                 add eax, dword ptr [ebx]
// 005451ab  0303                 add eax, dword ptr [ebx]
// 005451ad  0303                 add eax, dword ptr [ebx]
// 005451af  0303                 add eax, dword ptr [ebx]
// 005451b1  0303                 add eax, dword ptr [ebx]
// 005451b3  0301                 add eax, dword ptr [ecx]
// 005451b5  0303                 add eax, dword ptr [ebx]
// 005451b7  0303                 add eax, dword ptr [ebx]
// 005451b9  0303                 add eax, dword ptr [ebx]
// 005451bb  0303                 add eax, dword ptr [ebx]
// 005451bd  0302                 add eax, dword ptr [edx]
// 005451bf  0303                 add eax, dword ptr [ebx]
// 005451c1  0303                 add eax, dword ptr [ebx]
// 005451c3  0303                 add eax, dword ptr [ebx]
// 005451c5  0303                 add eax, dword ptr [ebx]
// 005451c7  0303                 add eax, dword ptr [ebx]
// 005451c9  0302                 add eax, dword ptr [edx]
// 005451cb  0303                 add eax, dword ptr [ebx]
// 005451cd  0303                 add eax, dword ptr [ebx]
// 005451cf  0303                 add eax, dword ptr [ebx]
// 005451d1  0303                 add eax, dword ptr [ebx]
// 005451d3  0303                 add eax, dword ptr [ebx]
// 005451d5  0303                 add eax, dword ptr [ebx]
// 005451d7  0303                 add eax, dword ptr [ebx]
// 005451d9  0303                 add eax, dword ptr [ebx]
// 005451db  0303                 add eax, dword ptr [ebx]
// 005451dd  0303                 add eax, dword ptr [ebx]
// 005451df  0303                 add eax, dword ptr [ebx]
// 005451e1  0303                 add eax, dword ptr [ebx]
// 005451e3  0303                 add eax, dword ptr [ebx]
// 005451e5  0303                 add eax, dword ptr [ebx]
// 005451e7  0303                 add eax, dword ptr [ebx]
// 005451e9  0303                 add eax, dword ptr [ebx]
// 005451eb  0303                 add eax, dword ptr [ebx]
// 005451ed  0303                 add eax, dword ptr [ebx]
// 005451ef  0303                 add eax, dword ptr [ebx]
// 005451f1  0303                 add eax, dword ptr [ebx]
// 005451f3  0303                 add eax, dword ptr [ebx]
// 005451f5  0303                 add eax, dword ptr [ebx]
// 005451f7  0300                 add eax, dword ptr [eax]
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ?AtlCrtErrorCheck@ATL@@YAHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
