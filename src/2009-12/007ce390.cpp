// from server: 100% by auto
// roc 2009-12 007ce390  unit: RBX::PartDropTool  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007ce390
//
// 007ce390  51                   push ecx
// 007ce391  55                   push ebp
// 007ce392  85ff                 test edi, edi
// 007ce394  7431                 je 0x7ce3c7
// 007ce396  b801000000           mov eax, 1
// 007ce39b  8bce                 mov ecx, esi
// 007ce39d  d3e0                 shl eax, cl
// 007ce39f  89442404             mov dword ptr [esp + 4], eax
// 007ce3a3  844706               test byte ptr [edi + 6], al
// 007ce3a6  751f                 jne 0x7ce3c7
// 007ce3a8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007ce3ac  8b4810               mov ecx, dword ptr [eax + 0x10]
// 007ce3af  8b94b1bc000000       mov edx, dword ptr [ecx + esi*4 + 0xbc]
// 007ce3b6  52                   push edx
// 007ce3b7  56                   push esi
// 007ce3b8  57                   push edi
// 007ce3b9  e892faffff           call 0x7cde50
// 007ce3be  8be8                 mov ebp, eax
// 007ce3c0  83c40c               add esp, 0xc
// 007ce3c3  85ed                 test ebp, ebp
// 007ce3c5  7505                 jne 0x7ce3cc
// 007ce3c7  33c0                 xor eax, eax
// 007ce3c9  5d                   pop ebp
// 007ce3ca  59                   pop ecx
// 007ce3cb  c3                   ret 
// 007ce3cc  3bfb                 cmp edi, ebx
// 007ce3ce  743a                 je 0x7ce40a
// 007ce3d0  85db                 test ebx, ebx
// 007ce3d2  74f3                 je 0x7ce3c7
// 007ce3d4  8a442404             mov al, byte ptr [esp + 4]
// 007ce3d8  844306               test byte ptr [ebx + 6], al
// 007ce3db  75ea                 jne 0x7ce3c7
// 007ce3dd  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007ce3e1  8b5110               mov edx, dword ptr [ecx + 0x10]
// 007ce3e4  8b84b2bc000000       mov eax, dword ptr [edx + esi*4 + 0xbc]
// 007ce3eb  50                   push eax
// 007ce3ec  56                   push esi
// 007ce3ed  53                   push ebx
// 007ce3ee  e85dfaffff           call 0x7cde50
// 007ce3f3  83c40c               add esp, 0xc
// 007ce3f6  85c0                 test eax, eax
// 007ce3f8  74cd                 je 0x7ce3c7
// 007ce3fa  50                   push eax
// 007ce3fb  55                   push ebp
// 007ce3fc  e82fbdfcff           call 0x79a130
// 007ce401  83c408               add esp, 8
// 007ce404  f7d8                 neg eax
// 007ce406  1bc0                 sbb eax, eax
// 007ce408  23c5                 and eax, ebp
// 007ce40a  5d                   pop ebp
// 007ce40b  59                   pop ecx
// 007ce40c  c3                   ret 
// library lua-5.1/lvm.c (function _get_compTM)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lvm.c
