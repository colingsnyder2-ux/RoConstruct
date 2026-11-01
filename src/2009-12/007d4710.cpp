// from server: 100% by auto
// roc 2009-12 007d4710  unit: seg_007d0000  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d4710
//
// 007d4710  51                   push ecx
// 007d4711  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d4714  6a04                 push 4
// 007d4716  8d442404             lea eax, [esp + 4]
// 007d471a  50                   push eax
// 007d471b  51                   push ecx
// 007d471c  e87fcaffff           call 0x7d11a0
// 007d4721  83c40c               add esp, 0xc
// 007d4724  85c0                 test eax, eax
// 007d4726  7423                 je 0x7d474b
// 007d4728  8b560c               mov edx, dword ptr [esi + 0xc]
// 007d472b  8b06                 mov eax, dword ptr [esi]
// 007d472d  6858f09e00           push 0x9ef058
// 007d4732  52                   push edx
// 007d4733  683cf09e00           push 0x9ef03c
// 007d4738  50                   push eax
// 007d4739  e8425efcff           call 0x79a580
// 007d473e  8b0e                 mov ecx, dword ptr [esi]
// 007d4740  6a03                 push 3
// 007d4742  51                   push ecx
// 007d4743  e80831fcff           call 0x797850
// 007d4748  83c418               add esp, 0x18
// 007d474b  8b0424               mov eax, dword ptr [esp]
// 007d474e  85c0                 test eax, eax
// 007d4750  7d27                 jge 0x7d4779
// 007d4752  8b560c               mov edx, dword ptr [esi + 0xc]
// 007d4755  8b06                 mov eax, dword ptr [esi]
// 007d4757  6868f09e00           push 0x9ef068
// 007d475c  52                   push edx
// 007d475d  683cf09e00           push 0x9ef03c
// 007d4762  50                   push eax
// 007d4763  e8185efcff           call 0x79a580
// 007d4768  8b0e                 mov ecx, dword ptr [esi]
// 007d476a  6a03                 push 3
// 007d476c  51                   push ecx
// 007d476d  e8de30fcff           call 0x797850
// 007d4772  8b442418             mov eax, dword ptr [esp + 0x18]
// 007d4776  83c418               add esp, 0x18
// 007d4779  59                   pop ecx
// 007d477a  c3                   ret 
// library lua-5.1/lundump.c (function _LoadInt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lundump.c
