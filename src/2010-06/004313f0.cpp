// from server: 100% by auto
// roc 2010-06 004313f0  unit: COutputView  size: 350 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004313f0
//
// 004313f0  51                   push ecx
// 004313f1  8b542408             mov edx, dword ptr [esp + 8]
// 004313f5  53                   push ebx
// 004313f6  8bd9                 mov ebx, ecx
// 004313f8  8b4314               mov eax, dword ptr [ebx + 0x14]
// 004313fb  b9ffffff0f           mov ecx, 0xfffffff
// 00431400  2bc8                 sub ecx, eax
// 00431402  3bca                 cmp ecx, edx
// 00431404  7305                 jae 0x43140b
// 00431406  e8c5e90800           call 0x4bfdd0
// 0043140b  8bc8                 mov ecx, eax
// 0043140d  d1e9                 shr ecx, 1
// 0043140f  83f908               cmp ecx, 8
// 00431412  7305                 jae 0x431419
// 00431414  b908000000           mov ecx, 8
// 00431419  55                   push ebp
// 0043141a  56                   push esi
// 0043141b  57                   push edi
// 0043141c  3bd1                 cmp edx, ecx
// 0043141e  7311                 jae 0x431431
// 00431420  beffffff0f           mov esi, 0xfffffff
// 00431425  2bf1                 sub esi, ecx
// 00431427  3bc6                 cmp eax, esi
// 00431429  7706                 ja 0x431431
// 0043142b  894c2418             mov dword ptr [esp + 0x18], ecx
// 0043142f  8bd1                 mov edx, ecx
// 00431431  8b6b18               mov ebp, dword ptr [ebx + 0x18]
// 00431434  03c2                 add eax, edx
// 00431436  6a00                 push 0
// 00431438  50                   push eax
// 00431439  c1ed02               shr ebp, 2
// 0043143c  e8cf3e4a00           call 0x8d5310
// 00431441  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00431444  89442418             mov dword ptr [esp + 0x18], eax
// 00431448  8d34ad00000000       lea esi, [ebp*4]
// 0043144f  8d3c06               lea edi, [esi + eax]
// 00431452  8b4314               mov eax, dword ptr [ebx + 0x14]
// 00431455  03c0                 add eax, eax
// 00431457  03c0                 add eax, eax
// 00431459  8d140e               lea edx, [esi + ecx]
// 0043145c  2bc2                 sub eax, edx
// 0043145e  03c1                 add eax, ecx
// 00431460  c1f802               sar eax, 2
// 00431463  8d0c8500000000       lea ecx, [eax*4]
// 0043146a  83c408               add esp, 8
// 0043146d  03f9                 add edi, ecx
// 0043146f  85c0                 test eax, eax
// 00431471  7614                 jbe 0x431487
// 00431473  51                   push ecx
// 00431474  52                   push edx
// 00431475  8b542418             mov edx, dword ptr [esp + 0x18]
// 00431479  51                   push ecx
// 0043147a  8d0416               lea eax, [esi + edx]
// 0043147d  50                   push eax
// 0043147e  ff1580a89e00         call dword ptr [0x9ea880]
// 00431484  83c410               add esp, 0x10
// 00431487  8b442418             mov eax, dword ptr [esp + 0x18]
// 0043148b  3be8                 cmp ebp, eax
// 0043148d  773d                 ja 0x4314cc
// 0043148f  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00431492  c1fe02               sar esi, 2
// 00431495  8bce                 mov ecx, esi
// 00431497  8d148d00000000       lea edx, [ecx*4]
// 0043149e  8d343a               lea esi, [edx + edi]
// 004314a1  85c9                 test ecx, ecx
// 004314a3  760d                 jbe 0x4314b2
// 004314a5  52                   push edx
// 004314a6  50                   push eax
// 004314a7  52                   push edx
// 004314a8  57                   push edi
// 004314a9  ff1580a89e00         call dword ptr [0x9ea880]
// 004314af  83c410               add esp, 0x10
// 004314b2  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004314b6  2bcd                 sub ecx, ebp
// 004314b8  7406                 je 0x4314c0
// 004314ba  33c0                 xor eax, eax
// 004314bc  8bfe                 mov edi, esi
// 004314be  f3ab                 rep stosd dword ptr es:[edi], eax
// 004314c0  85ed                 test ebp, ebp
// 004314c2  7664                 jbe 0x431528
// 004314c4  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004314c8  8bcd                 mov ecx, ebp
// 004314ca  eb58                 jmp 0x431524
// 004314cc  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004314cf  8d2c8500000000       lea ebp, [eax*4]
// 004314d6  8bc5                 mov eax, ebp
// 004314d8  c1f802               sar eax, 2
// 004314db  85c0                 test eax, eax
// 004314dd  7611                 jbe 0x4314f0
// 004314df  03c0                 add eax, eax
// 004314e1  03c0                 add eax, eax
// 004314e3  50                   push eax
// 004314e4  51                   push ecx
// 004314e5  50                   push eax
// 004314e6  57                   push edi
// 004314e7  ff1580a89e00         call dword ptr [0x9ea880]
// 004314ed  83c410               add esp, 0x10
// 004314f0  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004314f3  8b542410             mov edx, dword ptr [esp + 0x10]
// 004314f7  8d0c28               lea ecx, [eax + ebp]
// 004314fa  2bf1                 sub esi, ecx
// 004314fc  03f0                 add esi, eax
// 004314fe  c1fe02               sar esi, 2
// 00431501  8d04b500000000       lea eax, [esi*4]
// 00431508  8d3c10               lea edi, [eax + edx]
// 0043150b  85f6                 test esi, esi
// 0043150d  760d                 jbe 0x43151c
// 0043150f  50                   push eax
// 00431510  51                   push ecx
// 00431511  50                   push eax
// 00431512  52                   push edx
// 00431513  ff1580a89e00         call dword ptr [0x9ea880]
// 00431519  83c410               add esp, 0x10
// 0043151c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00431520  85c9                 test ecx, ecx
// 00431522  7604                 jbe 0x431528
// 00431524  33c0                 xor eax, eax
// 00431526  f3ab                 rep stosd dword ptr es:[edi], eax
// 00431528  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0043152b  5f                   pop edi
// 0043152c  5e                   pop esi
// 0043152d  5d                   pop ebp
// 0043152e  85c0                 test eax, eax
// 00431530  7409                 je 0x43153b
// 00431532  50                   push eax
// 00431533  e862643700           call 0x7a799a
// 00431538  83c404               add esp, 4
// 0043153b  8b442404             mov eax, dword ptr [esp + 4]
// 0043153f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00431543  014b14               add dword ptr [ebx + 0x14], ecx
// 00431546  894310               mov dword ptr [ebx + 0x10], eax
// 00431549  5b                   pop ebx
// 0043154a  59                   pop ecx
// 0043154b  c20400               ret 4
// standard library deque<ptr> (function ?_Growmap@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXI@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
