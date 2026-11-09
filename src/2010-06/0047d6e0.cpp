// from server: 100% by auto
// roc 2010-06 0047d6e0  unit: VCContent::?$CComObject  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0047d6e0
//
// 0047d6e0  83ec08               sub esp, 8
// 0047d6e3  53                   push ebx
// 0047d6e4  55                   push ebp
// 0047d6e5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0047d6eb  56                   push esi
// 0047d6ec  8bf1                 mov esi, ecx
// 0047d6ee  8b4618               mov eax, dword ptr [esi + 0x18]
// 0047d6f1  8b18                 mov ebx, dword ptr [eax]
// 0047d6f3  8b06                 mov eax, dword ptr [esi]
// 0047d6f5  57                   push edi
// 0047d6f6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0047d6fa  85ff                 test edi, edi
// 0047d6fc  7404                 je 0x47d702
// 0047d6fe  3bf8                 cmp edi, eax
// 0047d700  7406                 je 0x47d708
// 0047d702  ffd5                 call ebp
// 0047d704  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0047d708  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0047d70c  7562                 jne 0x47d770
// 0047d70e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0047d712  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0047d715  8b06                 mov eax, dword ptr [esi]
// 0047d717  85c9                 test ecx, ecx
// 0047d719  7404                 je 0x47d71f
// 0047d71b  3bc8                 cmp ecx, eax
// 0047d71d  7406                 je 0x47d725
// 0047d71f  ffd5                 call ebp
// 0047d721  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0047d725  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0047d729  7545                 jne 0x47d770
// 0047d72b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0047d72e  8b5104               mov edx, dword ptr [ecx + 4]
// 0047d731  52                   push edx
// 0047d732  8bce                 mov ecx, esi
// 0047d734  e807c52b00           call 0x739c40
// 0047d739  8b4618               mov eax, dword ptr [esi + 0x18]
// 0047d73c  894004               mov dword ptr [eax + 4], eax
// 0047d73f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0047d742  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0047d749  8900                 mov dword ptr [eax], eax
// 0047d74b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0047d74e  894008               mov dword ptr [eax + 8], eax
// 0047d751  8b4618               mov eax, dword ptr [esi + 0x18]
// 0047d754  8b16                 mov edx, dword ptr [esi]
// 0047d756  8b08                 mov ecx, dword ptr [eax]
// 0047d758  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0047d75c  5f                   pop edi
// 0047d75d  5e                   pop esi
// 0047d75e  5d                   pop ebp
// 0047d75f  894804               mov dword ptr [eax + 4], ecx
// 0047d762  8910                 mov dword ptr [eax], edx
// 0047d764  5b                   pop ebx
// 0047d765  83c408               add esp, 8
// 0047d768  c21400               ret 0x14
// 0047d76b  eb03                 jmp 0x47d770
// 0047d76d  8d4900               lea ecx, [ecx]
// 0047d770  85ff                 test edi, edi
// 0047d772  7406                 je 0x47d77a
// 0047d774  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0047d778  7406                 je 0x47d780
// 0047d77a  ffd5                 call ebp
// 0047d77c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0047d780  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0047d784  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0047d788  741d                 je 0x47d7a7
// 0047d78a  8d4c2420             lea ecx, [esp + 0x20]
// 0047d78e  e8ad8a4400           call 0x8c6240
// 0047d793  53                   push ebx
// 0047d794  57                   push edi
// 0047d795  8d442418             lea eax, [esp + 0x18]
// 0047d799  50                   push eax
// 0047d79a  8bce                 mov ecx, esi
// 0047d79c  e8bffbffff           call 0x47d360
// 0047d7a1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0047d7a5  ebc9                 jmp 0x47d770
// 0047d7a7  8b36                 mov esi, dword ptr [esi]
// 0047d7a9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0047d7ad  5f                   pop edi
// 0047d7ae  8930                 mov dword ptr [eax], esi
// 0047d7b0  5e                   pop esi
// 0047d7b1  5d                   pop ebp
// 0047d7b2  895804               mov dword ptr [eax + 4], ebx
// 0047d7b5  5b                   pop ebx
// 0047d7b6  83c408               add esp, 8
// 0047d7b9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
