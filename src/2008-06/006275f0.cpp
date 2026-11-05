// from server: 100% by auto
// roc 2008-06 006275f0  unit: seg_00620000  size: 284 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006275f0
//
// 006275f0  53                   push ebx
// 006275f1  55                   push ebp
// 006275f2  56                   push esi
// 006275f3  57                   push edi
// 006275f4  8bf1                 mov esi, ecx
// 006275f6  8b6e08               mov ebp, dword ptr [esi + 8]
// 006275f9  6a03                 push 3
// 006275fb  55                   push ebp
// 006275fc  8bd8                 mov ebx, eax
// 006275fe  e8fda7feff           call 0x611e00
// 00627603  83c0fd               add eax, -3
// 00627606  83c408               add esp, 8
// 00627609  83f803               cmp eax, 3
// 0062760c  0f87d4000000         ja 0x6276e6
// 00627612  ff2485fc766200       jmp dword ptr [eax*4 + 0x6276fc]
// 00627619  8b442418             mov eax, dword ptr [esp + 0x18]
// 0062761d  53                   push ebx
// 0062761e  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00627622  50                   push eax
// 00627623  8bc6                 mov eax, esi
// 00627625  e8e6feffff           call 0x627510
// 0062762a  83c408               add esp, 8
// 0062762d  5f                   pop edi
// 0062762e  5e                   pop esi
// 0062762f  5d                   pop ebp
// 00627630  5b                   pop ebx
// 00627631  c3                   ret 
// 00627632  6a03                 push 3
// 00627634  55                   push ebp
// 00627635  e896a7feff           call 0x611dd0
// 0062763a  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0062763e  53                   push ebx
// 0062763f  57                   push edi
// 00627640  8bc6                 mov eax, esi
// 00627642  e8d9faffff           call 0x627120
// 00627647  6a01                 push 1
// 00627649  50                   push eax
// 0062764a  55                   push ebp
// 0062764b  e8d0b2feff           call 0x612920
// 00627650  83c41c               add esp, 0x1c
// 00627653  eb1c                 jmp 0x627671
// 00627655  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00627659  8bc3                 mov eax, ebx
// 0062765b  33ff                 xor edi, edi
// 0062765d  e83efaffff           call 0x6270a0
// 00627662  6a03                 push 3
// 00627664  55                   push ebp
// 00627665  e8f6adfeff           call 0x612460
// 0062766a  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0062766e  83c408               add esp, 8
// 00627671  6aff                 push -1
// 00627673  55                   push ebp
// 00627674  e867a9feff           call 0x611fe0
// 00627679  83c408               add esp, 8
// 0062767c  85c0                 test eax, eax
// 0062767e  7527                 jne 0x6276a7
// 00627680  6afe                 push -2
// 00627682  55                   push ebp
// 00627683  e898a5feff           call 0x611c20
// 00627688  2bdf                 sub ebx, edi
// 0062768a  53                   push ebx
// 0062768b  57                   push edi
// 0062768c  55                   push ebp
// 0062768d  e8aeabfeff           call 0x612240
// 00627692  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00627696  83c414               add esp, 0x14
// 00627699  51                   push ecx
// 0062769a  e88199feff           call 0x611020
// 0062769f  83c404               add esp, 4
// 006276a2  5f                   pop edi
// 006276a3  5e                   pop esi
// 006276a4  5d                   pop ebp
// 006276a5  5b                   pop ebx
// 006276a6  c3                   ret 
// 006276a7  6aff                 push -1
// 006276a9  55                   push ebp
// 006276aa  e801a8feff           call 0x611eb0
// 006276af  83c408               add esp, 8
// 006276b2  85c0                 test eax, eax
// 006276b4  751e                 jne 0x6276d4
// 006276b6  6aff                 push -1
// 006276b8  55                   push ebp
// 006276b9  e842a7feff           call 0x611e00
// 006276be  50                   push eax
// 006276bf  55                   push ebp
// 006276c0  e85ba7feff           call 0x611e20
// 006276c5  50                   push eax
// 006276c6  6870528400           push 0x845270
// 006276cb  55                   push ebp
// 006276cc  e88f95feff           call 0x610c60
// 006276d1  83c41c               add esp, 0x1c
// 006276d4  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006276d8  51                   push ecx
// 006276d9  e84299feff           call 0x611020
// 006276de  83c404               add esp, 4
// 006276e1  5f                   pop edi
// 006276e2  5e                   pop esi
// 006276e3  5d                   pop ebp
// 006276e4  5b                   pop ebx
// 006276e5  c3                   ret 
// 006276e6  6850528400           push 0x845250
// 006276eb  6a03                 push 3
// 006276ed  55                   push ebp
// 006276ee  e8dd9dfeff           call 0x6114d0
// 006276f3  83c40c               add esp, 0xc
// 006276f6  5f                   pop edi
// 006276f7  5e                   pop esi
// 006276f8  5d                   pop ebp
// 006276f9  5b                   pop ebx
// 006276fa  c3                   ret 
// 006276fb  90                   nop 
// 006276fc  197662               sbb dword ptr [esi + 0x62], esi
// 006276ff  0019                 add byte ptr [ecx], bl
// 00627701  7662                 jbe 0x627765
// 00627703  005576               add byte ptr [ebp + 0x76], dl
// 00627706  6200                 bound eax, qword ptr [eax]
// 00627708  327662               xor dh, byte ptr [esi + 0x62]
// library lua-5.1/lstrlib.c (function _add_value)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
