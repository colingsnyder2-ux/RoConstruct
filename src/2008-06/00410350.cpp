// from server: 100% by auto
// roc 2008-06 00410350  unit: VCBrowserViewExternal::?$CComObject  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00410350
//
// 00410350  83ec08               sub esp, 8
// 00410353  8b442410             mov eax, dword ptr [esp + 0x10]
// 00410357  53                   push ebx
// 00410358  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0041035e  56                   push esi
// 0041035f  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00410363  57                   push edi
// 00410364  8bf9                 mov edi, ecx
// 00410366  8944240c             mov dword ptr [esp + 0xc], eax
// 0041036a  85c0                 test eax, eax
// 0041036c  750a                 jne 0x410378
// 0041036e  ffd3                 call ebx
// 00410370  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00410374  85c0                 test eax, eax
// 00410376  7404                 je 0x41037c
// 00410378  8b00                 mov eax, dword ptr [eax]
// 0041037a  eb02                 jmp 0x41037e
// 0041037c  33c0                 xor eax, eax
// 0041037e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00410382  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 00410385  7502                 jne 0x410389
// 00410387  ffd3                 call ebx
// 00410389  8b542420             mov edx, dword ptr [esp + 0x20]
// 0041038d  8b02                 mov eax, dword ptr [edx]
// 0041038f  89442420             mov dword ptr [esp + 0x20], eax
// 00410393  3b7714               cmp esi, dword ptr [edi + 0x14]
// 00410396  7424                 je 0x4103bc
// 00410398  8b4e04               mov ecx, dword ptr [esi + 4]
// 0041039b  8b16                 mov edx, dword ptr [esi]
// 0041039d  8911                 mov dword ptr [ecx], edx
// 0041039f  8b4e04               mov ecx, dword ptr [esi + 4]
// 004103a2  8b06                 mov eax, dword ptr [esi]
// 004103a4  894804               mov dword ptr [eax + 4], ecx
// 004103a7  8d4e08               lea ecx, [esi + 8]
// 004103aa  ff1568248000         call dword ptr [0x802468]
// 004103b0  56                   push esi
// 004103b1  e8c4022900           call 0x6a067a
// 004103b6  83c404               add esp, 4
// 004103b9  ff4f18               dec dword ptr [edi + 0x18]
// 004103bc  8b0f                 mov ecx, dword ptr [edi]
// 004103be  8b442418             mov eax, dword ptr [esp + 0x18]
// 004103c2  8b542420             mov edx, dword ptr [esp + 0x20]
// 004103c6  5f                   pop edi
// 004103c7  5e                   pop esi
// 004103c8  895004               mov dword ptr [eax + 4], edx
// 004103cb  8908                 mov dword ptr [eax], ecx
// 004103cd  5b                   pop ebx
// 004103ce  83c408               add esp, 8
// 004103d1  c20c00               ret 0xc
// standard library list<string> (function ?erase@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@@Z)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
