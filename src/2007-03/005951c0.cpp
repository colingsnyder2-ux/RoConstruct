// from server: 100% by auto
// roc 2007-03 005951c0  unit: seg_00590000  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005951c0
//
// 005951c0  8b442404             mov eax, dword ptr [esp + 4]
// 005951c4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005951c8  8b542404             mov edx, dword ptr [esp + 4]
// 005951cc  56                   push esi
// 005951cd  8b742408             mov esi, dword ptr [esp + 8]
// 005951d1  50                   push eax
// 005951d2  51                   push ecx
// 005951d3  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 005951d7  52                   push edx
// 005951d8  8b542438             mov edx, dword ptr [esp + 0x38]
// 005951dc  83ec0c               sub esp, 0xc
// 005951df  8bc4                 mov eax, esp
// 005951e1  894804               mov dword ptr [eax + 4], ecx
// 005951e4  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 005951e8  895008               mov dword ptr [eax + 8], edx
// 005951eb  8b542438             mov edx, dword ptr [esp + 0x38]
// 005951ef  c70000000000         mov dword ptr [eax], 0
// 005951f5  83ec0c               sub esp, 0xc
// 005951f8  8bc4                 mov eax, esp
// 005951fa  894804               mov dword ptr [eax + 4], ecx
// 005951fd  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00595201  895008               mov dword ptr [eax + 8], edx
// 00595204  8b542438             mov edx, dword ptr [esp + 0x38]
// 00595208  c70000000000         mov dword ptr [eax], 0
// 0059520e  83ec0c               sub esp, 0xc
// 00595211  8bc4                 mov eax, esp
// 00595213  56                   push esi
// 00595214  c70000000000         mov dword ptr [eax], 0
// 0059521a  894804               mov dword ptr [eax + 4], ecx
// 0059521d  895008               mov dword ptr [eax + 8], edx
// 00595220  e8abf4ffff           call 0x5946d0
// 00595225  83c434               add esp, 0x34
// 00595228  8bc6                 mov eax, esi
// 0059522a  5e                   pop esi
// 0059522b  c3                   ret 
// library templates-boost-1_34_1/deque_double.cpp (function ??$copy@V?$_Deque_iterator@NV?$allocator@N@std@@$00@std@@V12@@std@@YA?AV?$_Deque_iterator@NV?$allocator@N@std@@$00@0@V10@00@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 deque_double.cpp
