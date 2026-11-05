// from server: 100% by auto
// roc 2007-08 0056a260  unit: RBX::ModelInstance  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0056a260
//
// 0056a260  83ec0c               sub esp, 0xc
// 0056a263  55                   push ebp
// 0056a264  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0056a268  56                   push esi
// 0056a269  57                   push edi
// 0056a26a  8bf9                 mov edi, ecx
// 0056a26c  8b7704               mov esi, dword ptr [edi + 4]
// 0056a26f  8b4604               mov eax, dword ptr [esi + 4]
// 0056a272  80781900             cmp byte ptr [eax + 0x19], 0
// 0056a276  b101                 mov cl, 1
// 0056a278  884c240c             mov byte ptr [esp + 0xc], cl
// 0056a27c  7520                 jne 0x56a29e
// 0056a27e  8b5500               mov edx, dword ptr [ebp]
// 0056a281  3b500c               cmp edx, dword ptr [eax + 0xc]
// 0056a284  8bf0                 mov esi, eax
// 0056a286  0f92c1               setb cl
// 0056a289  84c9                 test cl, cl
// 0056a28b  884c240c             mov byte ptr [esp + 0xc], cl
// 0056a28f  7404                 je 0x56a295
// 0056a291  8b00                 mov eax, dword ptr [eax]
// 0056a293  eb03                 jmp 0x56a298
// 0056a295  8b4008               mov eax, dword ptr [eax + 8]
// 0056a298  80781900             cmp byte ptr [eax + 0x19], 0
// 0056a29c  74e3                 je 0x56a281
// 0056a29e  84c9                 test cl, cl
// 0056a2a0  8bd6                 mov edx, esi
// 0056a2a2  89542414             mov dword ptr [esp + 0x14], edx
// 0056a2a6  897c2410             mov dword ptr [esp + 0x10], edi
// 0056a2aa  743d                 je 0x56a2e9
// 0056a2ac  8b4704               mov eax, dword ptr [edi + 4]
// 0056a2af  3b30                 cmp esi, dword ptr [eax]
// 0056a2b1  8d4c2410             lea ecx, [esp + 0x10]
// 0056a2b5  7529                 jne 0x56a2e0
// 0056a2b7  55                   push ebp
// 0056a2b8  56                   push esi
// 0056a2b9  6a01                 push 1
// 0056a2bb  51                   push ecx
// 0056a2bc  8bcf                 mov ecx, edi
// 0056a2be  e81ded0100           call 0x588fe0
// 0056a2c3  8bc8                 mov ecx, eax
// 0056a2c5  8b11                 mov edx, dword ptr [ecx]
// 0056a2c7  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0056a2cb  8b4904               mov ecx, dword ptr [ecx + 4]
// 0056a2ce  5f                   pop edi
// 0056a2cf  5e                   pop esi
// 0056a2d0  8910                 mov dword ptr [eax], edx
// 0056a2d2  894804               mov dword ptr [eax + 4], ecx
// 0056a2d5  c6400801             mov byte ptr [eax + 8], 1
// 0056a2d9  5d                   pop ebp
// 0056a2da  83c40c               add esp, 0xc
// 0056a2dd  c20800               ret 8
// 0056a2e0  e84bd90100           call 0x587c30
// 0056a2e5  8b542414             mov edx, dword ptr [esp + 0x14]
// 0056a2e9  8b420c               mov eax, dword ptr [edx + 0xc]
// 0056a2ec  3b4500               cmp eax, dword ptr [ebp]
// 0056a2ef  730e                 jae 0x56a2ff
// 0056a2f1  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0056a2f5  55                   push ebp
// 0056a2f6  56                   push esi
// 0056a2f7  51                   push ecx
// 0056a2f8  8d54241c             lea edx, [esp + 0x1c]
// 0056a2fc  52                   push edx
// 0056a2fd  ebbd                 jmp 0x56a2bc
// 0056a2ff  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0056a303  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0056a307  5f                   pop edi
// 0056a308  5e                   pop esi
// 0056a309  8908                 mov dword ptr [eax], ecx
// 0056a30b  895004               mov dword ptr [eax + 4], edx
// 0056a30e  c6400800             mov byte ptr [eax + 8], 0
// 0056a312  5d                   pop ebp
// 0056a313  83c40c               add esp, 0xc
// 0056a316  c20800               ret 8
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
