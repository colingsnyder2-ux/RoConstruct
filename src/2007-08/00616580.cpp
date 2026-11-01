// from server: 100% by auto
// roc 2007-08 00616580  unit: seg_00610000  size: 288 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00616580
//
// 00616580  83ec18               sub esp, 0x18
// 00616583  53                   push ebx
// 00616584  56                   push esi
// 00616585  8bf0                 mov esi, eax
// 00616587  8b5e30               mov ebx, dword ptr [esi + 0x30]
// 0061658a  56                   push esi
// 0061658b  e860240000           call 0x6189f0
// 00616590  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00616593  8d81fcfeffff         lea eax, [ecx - 0x104]
// 00616599  83c404               add esp, 4
// 0061659c  83f81b               cmp eax, 0x1b
// 0061659f  770e                 ja 0x6165af
// 006165a1  0fb68084666100       movzx eax, byte ptr [eax + 0x616684]
// 006165a8  ff24857c666100       jmp dword ptr [eax*4 + 0x61667c]
// 006165af  83f93b               cmp ecx, 0x3b
// 006165b2  0f84ad000000         je 0x616665
// 006165b8  57                   push edi
// 006165b9  8d7c240c             lea edi, [esp + 0xc]
// 006165bd  e8eee4ffff           call 0x614ab0
// 006165c2  8bf0                 mov esi, eax
// 006165c4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006165c8  83f80d               cmp eax, 0xd
// 006165cb  5f                   pop edi
// 006165cc  744c                 je 0x61661a
// 006165ce  83f80e               cmp eax, 0xe
// 006165d1  7447                 je 0x61661a
// 006165d3  83fe01               cmp esi, 1
// 006165d6  751f                 jne 0x6165f7
// 006165d8  8d4c2408             lea ecx, [esp + 8]
// 006165dc  51                   push ecx
// 006165dd  53                   push ebx
// 006165de  e82d2e0100           call 0x629410
// 006165e3  83c408               add esp, 8
// 006165e6  56                   push esi
// 006165e7  50                   push eax
// 006165e8  53                   push ebx
// 006165e9  e862290100           call 0x628f50
// 006165ee  83c40c               add esp, 0xc
// 006165f1  5e                   pop esi
// 006165f2  5b                   pop ebx
// 006165f3  83c418               add esp, 0x18
// 006165f6  c3                   ret 
// 006165f7  8d542408             lea edx, [esp + 8]
// 006165fb  52                   push edx
// 006165fc  53                   push ebx
// 006165fd  e88e2d0100           call 0x629390
// 00616602  0fb64332             movzx eax, byte ptr [ebx + 0x32]
// 00616606  83c408               add esp, 8
// 00616609  56                   push esi
// 0061660a  50                   push eax
// 0061660b  53                   push ebx
// 0061660c  e83f290100           call 0x628f50
// 00616611  83c40c               add esp, 0xc
// 00616614  5e                   pop esi
// 00616615  5b                   pop ebx
// 00616616  83c418               add esp, 0x18
// 00616619  c3                   ret 
// 0061661a  6aff                 push -1
// 0061661c  8d44240c             lea eax, [esp + 0xc]
// 00616620  50                   push eax
// 00616621  53                   push ebx
// 00616622  e869240100           call 0x628a90
// 00616627  83c40c               add esp, 0xc
// 0061662a  837c24080d           cmp dword ptr [esp + 8], 0xd
// 0061662f  751c                 jne 0x61664d
// 00616631  83fe01               cmp esi, 1
// 00616634  7517                 jne 0x61664d
// 00616636  8b0b                 mov ecx, dword ptr [ebx]
// 00616638  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0061663b  8b442410             mov eax, dword ptr [esp + 0x10]
// 0061663f  8b0c82               mov ecx, dword ptr [edx + eax*4]
// 00616642  8d0482               lea eax, [edx + eax*4]
// 00616645  83e1dd               and ecx, 0xffffffdd
// 00616648  83c91d               or ecx, 0x1d
// 0061664b  8908                 mov dword ptr [eax], ecx
// 0061664d  0fb64332             movzx eax, byte ptr [ebx + 0x32]
// 00616651  83ceff               or esi, 0xffffffff
// 00616654  56                   push esi
// 00616655  50                   push eax
// 00616656  53                   push ebx
// 00616657  e8f4280100           call 0x628f50
// 0061665c  83c40c               add esp, 0xc
// 0061665f  5e                   pop esi
// 00616660  5b                   pop ebx
// 00616661  83c418               add esp, 0x18
// 00616664  c3                   ret 
// 00616665  33f6                 xor esi, esi
// 00616667  33c0                 xor eax, eax
// 00616669  56                   push esi
// 0061666a  50                   push eax
// 0061666b  53                   push ebx
// 0061666c  e8df280100           call 0x628f50
// 00616671  83c40c               add esp, 0xc
// 00616674  5e                   pop esi
// 00616675  5b                   pop ebx
// 00616676  83c418               add esp, 0x18
// 00616679  c3                   ret 
// 0061667a  8bff                 mov edi, edi
// 0061667c  656661               popaw 
// 0061667f  00af65610000         add byte ptr [edi + 0x6165], ch
// 00616685  0000                 add byte ptr [eax], al
// 00616687  0101                 add dword ptr [ecx], eax
// 00616689  0101                 add dword ptr [ecx], eax
// 0061668b  0101                 add dword ptr [ecx], eax
// 0061668d  0101                 add dword ptr [ecx], eax
// 0061668f  0101                 add dword ptr [ecx], eax
// 00616691  0101                 add dword ptr [ecx], eax
// 00616693  0100                 add dword ptr [eax], eax
// 00616695  0101                 add dword ptr [ecx], eax
// 00616697  0101                 add dword ptr [ecx], eax
// 00616699  0101                 add dword ptr [ecx], eax
// 0061669b  0101                 add dword ptr [ecx], eax
// 0061669d  0101                 add dword ptr [ecx], eax
// library lua-5.1/lparser.c (function _retstat)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
