// from server: 100% by auto
// roc 2007-03 00595230  unit: seg_00590000  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00595230
//
// 00595230  8b442404             mov eax, dword ptr [esp + 4]
// 00595234  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00595238  8b542404             mov edx, dword ptr [esp + 4]
// 0059523c  56                   push esi
// 0059523d  8b742408             mov esi, dword ptr [esp + 8]
// 00595241  50                   push eax
// 00595242  51                   push ecx
// 00595243  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00595247  52                   push edx
// 00595248  8b542438             mov edx, dword ptr [esp + 0x38]
// 0059524c  83ec0c               sub esp, 0xc
// 0059524f  8bc4                 mov eax, esp
// 00595251  894804               mov dword ptr [eax + 4], ecx
// 00595254  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00595258  895008               mov dword ptr [eax + 8], edx
// 0059525b  8b542438             mov edx, dword ptr [esp + 0x38]
// 0059525f  c70000000000         mov dword ptr [eax], 0
// 00595265  83ec0c               sub esp, 0xc
// 00595268  8bc4                 mov eax, esp
// 0059526a  894804               mov dword ptr [eax + 4], ecx
// 0059526d  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00595271  895008               mov dword ptr [eax + 8], edx
// 00595274  8b542438             mov edx, dword ptr [esp + 0x38]
// 00595278  c70000000000         mov dword ptr [eax], 0
// 0059527e  83ec0c               sub esp, 0xc
// 00595281  8bc4                 mov eax, esp
// 00595283  56                   push esi
// 00595284  c70000000000         mov dword ptr [eax], 0
// 0059528a  894804               mov dword ptr [eax + 4], ecx
// 0059528d  895008               mov dword ptr [eax + 8], edx
// 00595290  e8fbf4ffff           call 0x594790
// 00595295  83c434               add esp, 0x34
// 00595298  8bc6                 mov eax, esi
// 0059529a  5e                   pop esi
// 0059529b  c3                   ret 
// library templates-boost-1_34_1/deque_double.cpp (function ??$copy@V?$_Deque_iterator@NV?$allocator@N@std@@$00@std@@V12@@std@@YA?AV?$_Deque_iterator@NV?$allocator@N@std@@$00@0@V10@00@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 deque_double.cpp
