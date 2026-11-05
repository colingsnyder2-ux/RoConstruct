// from server: 100% by auto
// roc 2007-08 0061e7f0  unit: RBX::ScoreHud  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061e7f0
//
// 0061e7f0  83ec0c               sub esp, 0xc
// 0061e7f3  55                   push ebp
// 0061e7f4  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0061e7f8  56                   push esi
// 0061e7f9  57                   push edi
// 0061e7fa  8bf9                 mov edi, ecx
// 0061e7fc  8b7704               mov esi, dword ptr [edi + 4]
// 0061e7ff  8b4604               mov eax, dword ptr [esi + 4]
// 0061e802  80782100             cmp byte ptr [eax + 0x21], 0
// 0061e806  b101                 mov cl, 1
// 0061e808  884c240c             mov byte ptr [esp + 0xc], cl
// 0061e80c  7520                 jne 0x61e82e
// 0061e80e  8b5500               mov edx, dword ptr [ebp]
// 0061e811  3b500c               cmp edx, dword ptr [eax + 0xc]
// 0061e814  8bf0                 mov esi, eax
// 0061e816  0f92c1               setb cl
// 0061e819  84c9                 test cl, cl
// 0061e81b  884c240c             mov byte ptr [esp + 0xc], cl
// 0061e81f  7404                 je 0x61e825
// 0061e821  8b00                 mov eax, dword ptr [eax]
// 0061e823  eb03                 jmp 0x61e828
// 0061e825  8b4008               mov eax, dword ptr [eax + 8]
// 0061e828  80782100             cmp byte ptr [eax + 0x21], 0
// 0061e82c  74e3                 je 0x61e811
// 0061e82e  84c9                 test cl, cl
// 0061e830  8bd6                 mov edx, esi
// 0061e832  89542414             mov dword ptr [esp + 0x14], edx
// 0061e836  897c2410             mov dword ptr [esp + 0x10], edi
// 0061e83a  743d                 je 0x61e879
// 0061e83c  8b4704               mov eax, dword ptr [edi + 4]
// 0061e83f  3b30                 cmp esi, dword ptr [eax]
// 0061e841  8d4c2410             lea ecx, [esp + 0x10]
// 0061e845  7529                 jne 0x61e870
// 0061e847  55                   push ebp
// 0061e848  56                   push esi
// 0061e849  6a01                 push 1
// 0061e84b  51                   push ecx
// 0061e84c  8bcf                 mov ecx, edi
// 0061e84e  e8adfcffff           call 0x61e500
// 0061e853  8bc8                 mov ecx, eax
// 0061e855  8b11                 mov edx, dword ptr [ecx]
// 0061e857  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061e85b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0061e85e  5f                   pop edi
// 0061e85f  5e                   pop esi
// 0061e860  8910                 mov dword ptr [eax], edx
// 0061e862  894804               mov dword ptr [eax + 4], ecx
// 0061e865  c6400801             mov byte ptr [eax + 8], 1
// 0061e869  5d                   pop ebp
// 0061e86a  83c40c               add esp, 0xc
// 0061e86d  c20800               ret 8
// 0061e870  e83b1be8ff           call 0x4a03b0
// 0061e875  8b542414             mov edx, dword ptr [esp + 0x14]
// 0061e879  8b420c               mov eax, dword ptr [edx + 0xc]
// 0061e87c  3b4500               cmp eax, dword ptr [ebp]
// 0061e87f  730e                 jae 0x61e88f
// 0061e881  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0061e885  55                   push ebp
// 0061e886  56                   push esi
// 0061e887  51                   push ecx
// 0061e888  8d54241c             lea edx, [esp + 0x1c]
// 0061e88c  52                   push edx
// 0061e88d  ebbd                 jmp 0x61e84c
// 0061e88f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061e893  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0061e897  5f                   pop edi
// 0061e898  5e                   pop esi
// 0061e899  8908                 mov dword ptr [eax], ecx
// 0061e89b  895004               mov dword ptr [eax + 4], edx
// 0061e89e  c6400800             mov byte ptr [eax + 8], 0
// 0061e8a2  5d                   pop ebp
// 0061e8a3  83c40c               add esp, 0xc
// 0061e8a6  c20800               ret 8
// standard library map_ptr<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod16>
struct E { int v[4]; };
#include <map>
struct K; template class std::map<K*, E>;
