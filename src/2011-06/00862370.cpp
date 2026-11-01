// from server: 100% by auto
// roc 2011-06 00862370  unit: CXTPPropExchangeXMLNode  size: 304 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00862370
//
// 00862370  83ec20               sub esp, 0x20
// 00862373  56                   push esi
// 00862374  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00862378  33c0                 xor eax, eax
// 0086237a  57                   push edi
// 0086237b  8b3d9809a400         mov edi, dword ptr [0xa40998]
// 00862381  89442418             mov dword ptr [esp + 0x18], eax
// 00862385  8944241c             mov dword ptr [esp + 0x1c], eax
// 00862389  89442420             mov dword ptr [esp + 0x20], eax
// 0086238d  89442424             mov dword ptr [esp + 0x24], eax
// 00862391  8d442424             lea eax, [esp + 0x24]
// 00862395  50                   push eax
// 00862396  8d4c2426             lea ecx, [esp + 0x26]
// 0086239a  51                   push ecx
// 0086239b  8d542428             lea edx, [esp + 0x28]
// 0086239f  52                   push edx
// 008623a0  8d442426             lea eax, [esp + 0x26]
// 008623a4  50                   push eax
// 008623a5  8d4c242e             lea ecx, [esp + 0x2e]
// 008623a9  51                   push ecx
// 008623aa  8d54242c             lea edx, [esp + 0x2c]
// 008623ae  52                   push edx
// 008623af  6804abac00           push 0xacab04
// 008623b4  56                   push esi
// 008623b5  ffd7                 call edi
// 008623b7  83c420               add esp, 0x20
// 008623ba  83f803               cmp eax, 3
// 008623bd  0f848d000000         je 0x862450
// 008623c3  83f805               cmp eax, 5
// 008623c6  0f8484000000         je 0x862450
// 008623cc  83f806               cmp eax, 6
// 008623cf  747f                 je 0x862450
// 008623d1  33c0                 xor eax, eax
// 008623d3  89442418             mov dword ptr [esp + 0x18], eax
// 008623d7  8944241c             mov dword ptr [esp + 0x1c], eax
// 008623db  89442420             mov dword ptr [esp + 0x20], eax
// 008623df  89442424             mov dword ptr [esp + 0x24], eax
// 008623e3  8d442424             lea eax, [esp + 0x24]
// 008623e7  50                   push eax
// 008623e8  8d4c2426             lea ecx, [esp + 0x26]
// 008623ec  51                   push ecx
// 008623ed  8d542428             lea edx, [esp + 0x28]
// 008623f1  52                   push edx
// 008623f2  68f8aaac00           push 0xacaaf8
// 008623f7  56                   push esi
// 008623f8  ffd7                 call edi
// 008623fa  83c414               add esp, 0x14
// 008623fd  83f802               cmp eax, 2
// 00862400  7405                 je 0x862407
// 00862402  83f803               cmp eax, 3
// 00862405  7572                 jne 0x862479
// 00862407  0fb7442420           movzx eax, word ptr [esp + 0x20]
// 0086240c  0fb7542422           movzx edx, word ptr [esp + 0x22]
// 00862411  8bc8                 mov ecx, eax
// 00862413  c1e104               shl ecx, 4
// 00862416  2bc8                 sub ecx, eax
// 00862418  8d048a               lea eax, [edx + ecx*4]
// 0086241b  0fb7542424           movzx edx, word ptr [esp + 0x24]
// 00862420  8bc8                 mov ecx, eax
// 00862422  c1e104               shl ecx, 4
// 00862425  2bc8                 sub ecx, eax
// 00862427  8d048a               lea eax, [edx + ecx*4]
// 0086242a  89442408             mov dword ptr [esp + 8], eax
// 0086242e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00862432  5f                   pop edi
// 00862433  db442404             fild dword ptr [esp + 4]
// 00862437  c7400800000000       mov dword ptr [eax + 8], 0
// 0086243e  5e                   pop esi
// 0086243f  dc35f0aaac00         fdiv qword ptr [0xacaaf0]
// 00862445  dd18                 fstp qword ptr [eax]
// 00862447  b801000000           mov eax, 1
// 0086244c  83c420               add esp, 0x20
// 0086244f  c3                   ret 
// 00862450  d9ee                 fldz 
// 00862452  8d4c240c             lea ecx, [esp + 0xc]
// 00862456  51                   push ecx
// 00862457  dd5c2410             fstp qword ptr [esp + 0x10]
// 0086245b  8d54241c             lea edx, [esp + 0x1c]
// 0086245f  52                   push edx
// 00862460  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00862468  e80392c2ff           call 0x48b670
// 0086246d  83c408               add esp, 8
// 00862470  f7d8                 neg eax
// 00862472  1bc0                 sbb eax, eax
// 00862474  83c001               add eax, 1
// 00862477  7408                 je 0x862481
// 00862479  5f                   pop edi
// 0086247a  33c0                 xor eax, eax
// 0086247c  5e                   pop esi
// 0086247d  83c420               add esp, 0x20
// 00862480  c3                   ret 
// 00862481  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00862485  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00862489  8911                 mov dword ptr [ecx], edx
// 0086248b  8b542410             mov edx, dword ptr [esp + 0x10]
// 0086248f  895104               mov dword ptr [ecx + 4], edx
// 00862492  5f                   pop edi
// 00862493  894108               mov dword ptr [ecx + 8], eax
// 00862496  b801000000           mov eax, 1
// 0086249b  5e                   pop esi
// 0086249c  83c420               add esp, 0x20
// 0086249f  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?ParseDateTimeISO8601@@YAHAAVCOleDateTime@ATL@@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
