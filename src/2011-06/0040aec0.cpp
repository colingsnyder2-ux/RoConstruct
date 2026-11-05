// from server: 100% by auto
// roc 2011-06 0040aec0  unit: VAuthoringSettings::?$FactoryProduct  size: 358 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0040aec0
//
// 0040aec0  51                   push ecx
// 0040aec1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040aec5  53                   push ebx
// 0040aec6  8b19                 mov ebx, dword ptr [ecx]
// 0040aec8  55                   push ebp
// 0040aec9  8b6904               mov ebp, dword ptr [ecx + 4]
// 0040aecc  56                   push esi
// 0040aecd  57                   push edi
// 0040aece  894c2410             mov dword ptr [esp + 0x10], ecx
// 0040aed2  85db                 test ebx, ebx
// 0040aed4  7508                 jne 0x40aede
// 0040aed6  81fd00000080         cmp ebp, 0x80000000
// 0040aedc  7451                 je 0x40af2f
// 0040aede  83fbff               cmp ebx, -1
// 0040aee1  7508                 jne 0x40aeeb
// 0040aee3  81fdffffff7f         cmp ebp, 0x7fffffff
// 0040aee9  7444                 je 0x40af2f
// 0040aeeb  83fbfe               cmp ebx, -2
// 0040aeee  750c                 jne 0x40aefc
// 0040aef0  81fdffffff7f         cmp ebp, 0x7fffffff
// 0040aef6  0f8411010000         je 0x40b00d
// 0040aefc  8b30                 mov esi, dword ptr [eax]
// 0040aefe  8b7804               mov edi, dword ptr [eax + 4]
// 0040af01  85f6                 test esi, esi
// 0040af03  7508                 jne 0x40af0d
// 0040af05  81ff00000080         cmp edi, 0x80000000
// 0040af0b  7422                 je 0x40af2f
// 0040af0d  83feff               cmp esi, -1
// 0040af10  7508                 jne 0x40af1a
// 0040af12  81ffffffff7f         cmp edi, 0x7fffffff
// 0040af18  7415                 je 0x40af2f
// 0040af1a  83fefe               cmp esi, -2
// 0040af1d  0f85d5000000         jne 0x40aff8
// 0040af23  81ffffffff7f         cmp edi, 0x7fffffff
// 0040af29  0f85c9000000         jne 0x40aff8
// 0040af2f  83fbfe               cmp ebx, -2
// 0040af32  750c                 jne 0x40af40
// 0040af34  81fdffffff7f         cmp ebp, 0x7fffffff
// 0040af3a  0f84cd000000         je 0x40b00d
// 0040af40  8b30                 mov esi, dword ptr [eax]
// 0040af42  8b7804               mov edi, dword ptr [eax + 4]
// 0040af45  83fefe               cmp esi, -2
// 0040af48  750c                 jne 0x40af56
// 0040af4a  81ffffffff7f         cmp edi, 0x7fffffff
// 0040af50  0f84b7000000         je 0x40b00d
// 0040af56  83fbff               cmp ebx, -1
// 0040af59  7514                 jne 0x40af6f
// 0040af5b  81fdffffff7f         cmp ebp, 0x7fffffff
// 0040af61  750c                 jne 0x40af6f
// 0040af63  3bf3                 cmp esi, ebx
// 0040af65  7508                 jne 0x40af6f
// 0040af67  3bfd                 cmp edi, ebp
// 0040af69  0f849e000000         je 0x40b00d
// 0040af6f  85db                 test ebx, ebx
// 0040af71  7514                 jne 0x40af87
// 0040af73  81fd00000080         cmp ebp, 0x80000000
// 0040af79  750c                 jne 0x40af87
// 0040af7b  85f6                 test esi, esi
// 0040af7d  7508                 jne 0x40af87
// 0040af7f  3bfd                 cmp edi, ebp
// 0040af81  0f8486000000         je 0x40b00d
// 0040af87  e8f4f3ffff           call 0x40a380
// 0040af8c  84c0                 test al, al
// 0040af8e  741a                 je 0x40afaa
// 0040af90  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040af94  8b11                 mov edx, dword ptr [ecx]
// 0040af96  8b442418             mov eax, dword ptr [esp + 0x18]
// 0040af9a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0040af9d  5f                   pop edi
// 0040af9e  5e                   pop esi
// 0040af9f  5d                   pop ebp
// 0040afa0  8910                 mov dword ptr [eax], edx
// 0040afa2  894804               mov dword ptr [eax + 4], ecx
// 0040afa5  5b                   pop ebx
// 0040afa6  59                   pop ecx
// 0040afa7  c20800               ret 8
// 0040afaa  57                   push edi
// 0040afab  56                   push esi
// 0040afac  e88ff3ffff           call 0x40a340
// 0040afb1  83c408               add esp, 8
// 0040afb4  84c0                 test al, al
// 0040afb6  7419                 je 0x40afd1
// 0040afb8  8b442418             mov eax, dword ptr [esp + 0x18]
// 0040afbc  5f                   pop edi
// 0040afbd  5e                   pop esi
// 0040afbe  5d                   pop ebp
// 0040afbf  c70000000000         mov dword ptr [eax], 0
// 0040afc5  c7400400000080       mov dword ptr [eax + 4], 0x80000000
// 0040afcc  5b                   pop ebx
// 0040afcd  59                   pop ecx
// 0040afce  c20800               ret 8
// 0040afd1  57                   push edi
// 0040afd2  56                   push esi
// 0040afd3  e888f3ffff           call 0x40a360
// 0040afd8  83c408               add esp, 8
// 0040afdb  84c0                 test al, al
// 0040afdd  7419                 je 0x40aff8
// 0040afdf  8b442418             mov eax, dword ptr [esp + 0x18]
// 0040afe3  5f                   pop edi
// 0040afe4  5e                   pop esi
// 0040afe5  5d                   pop ebp
// 0040afe6  c700ffffffff         mov dword ptr [eax], 0xffffffff
// 0040afec  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 0040aff3  5b                   pop ebx
// 0040aff4  59                   pop ecx
// 0040aff5  c20800               ret 8
// 0040aff8  8b442418             mov eax, dword ptr [esp + 0x18]
// 0040affc  2bde                 sub ebx, esi
// 0040affe  1bef                 sbb ebp, edi
// 0040b000  5f                   pop edi
// 0040b001  5e                   pop esi
// 0040b002  896804               mov dword ptr [eax + 4], ebp
// 0040b005  5d                   pop ebp
// 0040b006  8918                 mov dword ptr [eax], ebx
// 0040b008  5b                   pop ebx
// 0040b009  59                   pop ecx
// 0040b00a  c20800               ret 8
// 0040b00d  8b442418             mov eax, dword ptr [esp + 0x18]
// 0040b011  5f                   pop edi
// 0040b012  5e                   pop esi
// 0040b013  5d                   pop ebp
// 0040b014  c700feffffff         mov dword ptr [eax], 0xfffffffe
// 0040b01a  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 0040b021  5b                   pop ebx
// 0040b022  59                   pop ecx
// 0040b023  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??$?G_J@?$int_adapter@_J@date_time@boost@@QBE?AV012@ABV012@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
