// from server: 100% by auto
// roc 2009-12 00445190  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 184 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00445190
//
// 00445190  51                   push ecx
// 00445191  53                   push ebx
// 00445192  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00445196  55                   push ebp
// 00445197  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0044519d  56                   push esi
// 0044519e  8bf1                 mov esi, ecx
// 004451a0  57                   push edi
// 004451a1  c70300000000         mov dword ptr [ebx], 0
// 004451a7  85f6                 test esi, esi
// 004451a9  740e                 je 0x4451b9
// 004451ab  8b442420             mov eax, dword ptr [esp + 0x20]
// 004451af  39460c               cmp dword ptr [esi + 0xc], eax
// 004451b2  7705                 ja 0x4451b9
// 004451b4  3b4610               cmp eax, dword ptr [esi + 0x10]
// 004451b7  7606                 jbe 0x4451bf
// 004451b9  ffd5                 call ebp
// 004451bb  8b442420             mov eax, dword ptr [esp + 0x20]
// 004451bf  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004451c3  8b0e                 mov ecx, dword ptr [esi]
// 004451c5  890b                 mov dword ptr [ebx], ecx
// 004451c7  894304               mov dword ptr [ebx + 4], eax
// 004451ca  397e0c               cmp dword ptr [esi + 0xc], edi
// 004451cd  7705                 ja 0x4451d4
// 004451cf  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004451d2  7606                 jbe 0x4451da
// 004451d4  ffd5                 call ebp
// 004451d6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004451da  8b03                 mov eax, dword ptr [ebx]
// 004451dc  8b0e                 mov ecx, dword ptr [esi]
// 004451de  85c0                 test eax, eax
// 004451e0  7404                 je 0x4451e6
// 004451e2  3bc1                 cmp eax, ecx
// 004451e4  7402                 je 0x4451e8
// 004451e6  ffd5                 call ebp
// 004451e8  8b4b04               mov ecx, dword ptr [ebx + 4]
// 004451eb  3bcf                 cmp ecx, edi
// 004451ed  744f                 je 0x44523e
// 004451ef  8b4610               mov eax, dword ptr [esi + 0x10]
// 004451f2  c644241000           mov byte ptr [esp + 0x10], 0
// 004451f7  8b542410             mov edx, dword ptr [esp + 0x10]
// 004451fb  52                   push edx
// 004451fc  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00445200  52                   push edx
// 00445201  8b542420             mov edx, dword ptr [esp + 0x20]
// 00445205  52                   push edx
// 00445206  51                   push ecx
// 00445207  50                   push eax
// 00445208  57                   push edi
// 00445209  e8b2f0ffff           call 0x4442c0
// 0044520e  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 00445211  8bd8                 mov ebx, eax
// 00445213  83c418               add esp, 0x18
// 00445216  8bfb                 mov edi, ebx
// 00445218  3bdd                 cmp ebx, ebp
// 0044521a  7413                 je 0x44522f
// 0044521c  8d642400             lea esp, [esp]
// 00445220  8bcf                 mov ecx, edi
// 00445222  ff15e4b69800         call dword ptr [0x98b6e4]
// 00445228  83c71c               add edi, 0x1c
// 0044522b  3bfd                 cmp edi, ebp
// 0044522d  75f1                 jne 0x445220
// 0044522f  8b442418             mov eax, dword ptr [esp + 0x18]
// 00445233  5f                   pop edi
// 00445234  895e10               mov dword ptr [esi + 0x10], ebx
// 00445237  5e                   pop esi
// 00445238  5d                   pop ebp
// 00445239  5b                   pop ebx
// 0044523a  59                   pop ecx
// 0044523b  c21400               ret 0x14
// 0044523e  5f                   pop edi
// 0044523f  5e                   pop esi
// 00445240  5d                   pop ebp
// 00445241  8bc3                 mov eax, ebx
// 00445243  5b                   pop ebx
// 00445244  59                   pop ecx
// 00445245  c21400               ret 0x14
// standard library vector<string> (function ?erase@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Vector_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@V?$_Vector_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@0@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
