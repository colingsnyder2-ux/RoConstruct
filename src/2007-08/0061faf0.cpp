// from server: 100% by auto
// roc 2007-08 0061faf0  unit: RBX::ScoreHud  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061faf0
//
// 0061faf0  83ec0c               sub esp, 0xc
// 0061faf3  55                   push ebp
// 0061faf4  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0061faf8  56                   push esi
// 0061faf9  57                   push edi
// 0061fafa  8bf9                 mov edi, ecx
// 0061fafc  8b7704               mov esi, dword ptr [edi + 4]
// 0061faff  8b4604               mov eax, dword ptr [esi + 4]
// 0061fb02  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0061fb06  b101                 mov cl, 1
// 0061fb08  884c240c             mov byte ptr [esp + 0xc], cl
// 0061fb0c  7520                 jne 0x61fb2e
// 0061fb0e  8b5500               mov edx, dword ptr [ebp]
// 0061fb11  3b500c               cmp edx, dword ptr [eax + 0xc]
// 0061fb14  8bf0                 mov esi, eax
// 0061fb16  0f92c1               setb cl
// 0061fb19  84c9                 test cl, cl
// 0061fb1b  884c240c             mov byte ptr [esp + 0xc], cl
// 0061fb1f  7404                 je 0x61fb25
// 0061fb21  8b00                 mov eax, dword ptr [eax]
// 0061fb23  eb03                 jmp 0x61fb28
// 0061fb25  8b4008               mov eax, dword ptr [eax + 8]
// 0061fb28  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0061fb2c  74e3                 je 0x61fb11
// 0061fb2e  84c9                 test cl, cl
// 0061fb30  8bd6                 mov edx, esi
// 0061fb32  89542414             mov dword ptr [esp + 0x14], edx
// 0061fb36  897c2410             mov dword ptr [esp + 0x10], edi
// 0061fb3a  743d                 je 0x61fb79
// 0061fb3c  8b4704               mov eax, dword ptr [edi + 4]
// 0061fb3f  3b30                 cmp esi, dword ptr [eax]
// 0061fb41  8d4c2410             lea ecx, [esp + 0x10]
// 0061fb45  7529                 jne 0x61fb70
// 0061fb47  55                   push ebp
// 0061fb48  56                   push esi
// 0061fb49  6a01                 push 1
// 0061fb4b  51                   push ecx
// 0061fb4c  8bcf                 mov ecx, edi
// 0061fb4e  e8bdf7ffff           call 0x61f310
// 0061fb53  8bc8                 mov ecx, eax
// 0061fb55  8b11                 mov edx, dword ptr [ecx]
// 0061fb57  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061fb5b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0061fb5e  5f                   pop edi
// 0061fb5f  5e                   pop esi
// 0061fb60  8910                 mov dword ptr [eax], edx
// 0061fb62  894804               mov dword ptr [eax + 4], ecx
// 0061fb65  c6400801             mov byte ptr [eax + 8], 1
// 0061fb69  5d                   pop ebp
// 0061fb6a  83c40c               add esp, 0xc
// 0061fb6d  c20800               ret 8
// 0061fb70  e8cbcefeff           call 0x60ca40
// 0061fb75  8b542414             mov edx, dword ptr [esp + 0x14]
// 0061fb79  8b420c               mov eax, dword ptr [edx + 0xc]
// 0061fb7c  3b4500               cmp eax, dword ptr [ebp]
// 0061fb7f  730e                 jae 0x61fb8f
// 0061fb81  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0061fb85  55                   push ebp
// 0061fb86  56                   push esi
// 0061fb87  51                   push ecx
// 0061fb88  8d54241c             lea edx, [esp + 0x1c]
// 0061fb8c  52                   push edx
// 0061fb8d  ebbd                 jmp 0x61fb4c
// 0061fb8f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061fb93  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0061fb97  5f                   pop edi
// 0061fb98  5e                   pop esi
// 0061fb99  8908                 mov dword ptr [eax], ecx
// 0061fb9b  895004               mov dword ptr [eax + 4], edx
// 0061fb9e  c6400800             mov byte ptr [eax + 8], 0
// 0061fba2  5d                   pop ebp
// 0061fba3  83c40c               add esp, 0xc
// 0061fba6  c20800               ret 8
// standard library map_ptr<pod12> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod12>
struct E { int v[3]; };
#include <map>
struct K; template class std::map<K*, E>;
