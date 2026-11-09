// from server: 100% by auto
// roc 2009-12 007dd750  unit: RBX::GroupDragTool  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dd750
//
// 007dd750  8b442404             mov eax, dword ptr [esp + 4]
// 007dd754  8b4818               mov ecx, dword ptr [eax + 0x18]
// 007dd757  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007dd75b  3bd1                 cmp edx, ecx
// 007dd75d  751b                 jne 0x7dd77a
// 007dd75f  89481c               mov dword ptr [eax + 0x1c], ecx
// 007dd762  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007dd766  8d5020               lea edx, [eax + 0x20]
// 007dd769  894c240c             mov dword ptr [esp + 0xc], ecx
// 007dd76d  89542408             mov dword ptr [esp + 8], edx
// 007dd771  89442404             mov dword ptr [esp + 4], eax
// 007dd775  e956e9ffff           jmp 0x7dc0d0
// 007dd77a  52                   push edx
// 007dd77b  68ff000000           push 0xff
// 007dd780  52                   push edx
// 007dd781  50                   push eax
// 007dd782  8b442418             mov eax, dword ptr [esp + 0x18]
// 007dd786  e885e8ffff           call 0x7dc010
// 007dd78b  83c410               add esp, 0x10
// 007dd78e  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_patchlist)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
