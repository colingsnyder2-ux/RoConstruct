// from server: 100% by auto
// roc 2010-06 005d0320  unit: RBX::VInstance::?$NonFactoryProduct  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005d0320
//
// 005d0320  83ec0c               sub esp, 0xc
// 005d0323  53                   push ebx
// 005d0324  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 005d0328  55                   push ebp
// 005d0329  56                   push esi
// 005d032a  57                   push edi
// 005d032b  8bf9                 mov edi, ecx
// 005d032d  8b7718               mov esi, dword ptr [edi + 0x18]
// 005d0330  8b4604               mov eax, dword ptr [esi + 4]
// 005d0333  80781900             cmp byte ptr [eax + 0x19], 0
// 005d0337  b101                 mov cl, 1
// 005d0339  884c2410             mov byte ptr [esp + 0x10], cl
// 005d033d  751f                 jne 0x5d035e
// 005d033f  8b13                 mov edx, dword ptr [ebx]
// 005d0341  3b500c               cmp edx, dword ptr [eax + 0xc]
// 005d0344  8bf0                 mov esi, eax
// 005d0346  0f9cc1               setl cl
// 005d0349  884c2410             mov byte ptr [esp + 0x10], cl
// 005d034d  84c9                 test cl, cl
// 005d034f  7404                 je 0x5d0355
// 005d0351  8b00                 mov eax, dword ptr [eax]
// 005d0353  eb03                 jmp 0x5d0358
// 005d0355  8b4008               mov eax, dword ptr [eax + 8]
// 005d0358  80781900             cmp byte ptr [eax + 0x19], 0
// 005d035c  74e3                 je 0x5d0341
// 005d035e  8b17                 mov edx, dword ptr [edi]
// 005d0360  8bee                 mov ebp, esi
// 005d0362  896c2418             mov dword ptr [esp + 0x18], ebp
// 005d0366  89542414             mov dword ptr [esp + 0x14], edx
// 005d036a  84c9                 test cl, cl
// 005d036c  7452                 je 0x5d03c0
// 005d036e  8b4718               mov eax, dword ptr [edi + 0x18]
// 005d0371  8b28                 mov ebp, dword ptr [eax]
// 005d0373  85d2                 test edx, edx
// 005d0375  7404                 je 0x5d037b
// 005d0377  3bd2                 cmp edx, edx
// 005d0379  7406                 je 0x5d0381
// 005d037b  ff150ca99e00         call dword ptr [0x9ea90c]
// 005d0381  8d4c2414             lea ecx, [esp + 0x14]
// 005d0385  3bf5                 cmp esi, ebp
// 005d0387  752a                 jne 0x5d03b3
// 005d0389  53                   push ebx
// 005d038a  56                   push esi
// 005d038b  6a01                 push 1
// 005d038d  51                   push ecx
// 005d038e  8bcf                 mov ecx, edi
// 005d0390  e85ba9f1ff           call 0x4eacf0
// 005d0395  5f                   pop edi
// 005d0396  8bc8                 mov ecx, eax
// 005d0398  8b11                 mov edx, dword ptr [ecx]
// 005d039a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005d039e  8b4904               mov ecx, dword ptr [ecx + 4]
// 005d03a1  5e                   pop esi
// 005d03a2  5d                   pop ebp
// 005d03a3  894804               mov dword ptr [eax + 4], ecx
// 005d03a6  c6400801             mov byte ptr [eax + 8], 1
// 005d03aa  8910                 mov dword ptr [eax], edx
// 005d03ac  5b                   pop ebx
// 005d03ad  83c40c               add esp, 0xc
// 005d03b0  c20800               ret 8
// 005d03b3  e8083fe6ff           call 0x4342c0
// 005d03b8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 005d03bc  8b542414             mov edx, dword ptr [esp + 0x14]
// 005d03c0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005d03c3  3b03                 cmp eax, dword ptr [ebx]
// 005d03c5  7d31                 jge 0x5d03f8
// 005d03c7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005d03cb  53                   push ebx
// 005d03cc  56                   push esi
// 005d03cd  51                   push ecx
// 005d03ce  8d542420             lea edx, [esp + 0x20]
// 005d03d2  52                   push edx
// 005d03d3  8bcf                 mov ecx, edi
// 005d03d5  e816a9f1ff           call 0x4eacf0
// 005d03da  5f                   pop edi
// 005d03db  8bc8                 mov ecx, eax
// 005d03dd  8b11                 mov edx, dword ptr [ecx]
// 005d03df  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005d03e3  8b4904               mov ecx, dword ptr [ecx + 4]
// 005d03e6  5e                   pop esi
// 005d03e7  5d                   pop ebp
// 005d03e8  894804               mov dword ptr [eax + 4], ecx
// 005d03eb  c6400801             mov byte ptr [eax + 8], 1
// 005d03ef  8910                 mov dword ptr [eax], edx
// 005d03f1  5b                   pop ebx
// 005d03f2  83c40c               add esp, 0xc
// 005d03f5  c20800               ret 8
// 005d03f8  8b442420             mov eax, dword ptr [esp + 0x20]
// 005d03fc  5f                   pop edi
// 005d03fd  5e                   pop esi
// 005d03fe  896804               mov dword ptr [eax + 4], ebp
// 005d0401  5d                   pop ebp
// 005d0402  c6400800             mov byte ptr [eax + 8], 0
// 005d0406  8910                 mov dword ptr [eax], edx
// 005d0408  5b                   pop ebx
// 005d0409  83c40c               add esp, 0xc
// 005d040c  c20800               ret 8
// standard library map_int<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
