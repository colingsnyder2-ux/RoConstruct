// from server: 100% by auto
// roc 2007-08 00605240  unit: RBX::SleepStage  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00605240
//
// 00605240  83ec0c               sub esp, 0xc
// 00605243  55                   push ebp
// 00605244  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00605248  56                   push esi
// 00605249  57                   push edi
// 0060524a  8bf9                 mov edi, ecx
// 0060524c  8b7704               mov esi, dword ptr [edi + 4]
// 0060524f  8b4604               mov eax, dword ptr [esi + 4]
// 00605252  80781900             cmp byte ptr [eax + 0x19], 0
// 00605256  b101                 mov cl, 1
// 00605258  884c240c             mov byte ptr [esp + 0xc], cl
// 0060525c  7520                 jne 0x60527e
// 0060525e  8b5500               mov edx, dword ptr [ebp]
// 00605261  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00605264  8bf0                 mov esi, eax
// 00605266  0f92c1               setb cl
// 00605269  84c9                 test cl, cl
// 0060526b  884c240c             mov byte ptr [esp + 0xc], cl
// 0060526f  7404                 je 0x605275
// 00605271  8b00                 mov eax, dword ptr [eax]
// 00605273  eb03                 jmp 0x605278
// 00605275  8b4008               mov eax, dword ptr [eax + 8]
// 00605278  80781900             cmp byte ptr [eax + 0x19], 0
// 0060527c  74e3                 je 0x605261
// 0060527e  84c9                 test cl, cl
// 00605280  8bd6                 mov edx, esi
// 00605282  89542414             mov dword ptr [esp + 0x14], edx
// 00605286  897c2410             mov dword ptr [esp + 0x10], edi
// 0060528a  743d                 je 0x6052c9
// 0060528c  8b4704               mov eax, dword ptr [edi + 4]
// 0060528f  3b30                 cmp esi, dword ptr [eax]
// 00605291  8d4c2410             lea ecx, [esp + 0x10]
// 00605295  7529                 jne 0x6052c0
// 00605297  55                   push ebp
// 00605298  56                   push esi
// 00605299  6a01                 push 1
// 0060529b  51                   push ecx
// 0060529c  8bcf                 mov ecx, edi
// 0060529e  e8bdfbffff           call 0x604e60
// 006052a3  8bc8                 mov ecx, eax
// 006052a5  8b11                 mov edx, dword ptr [ecx]
// 006052a7  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006052ab  8b4904               mov ecx, dword ptr [ecx + 4]
// 006052ae  5f                   pop edi
// 006052af  5e                   pop esi
// 006052b0  8910                 mov dword ptr [eax], edx
// 006052b2  894804               mov dword ptr [eax + 4], ecx
// 006052b5  c6400801             mov byte ptr [eax + 8], 1
// 006052b9  5d                   pop ebp
// 006052ba  83c40c               add esp, 0xc
// 006052bd  c20800               ret 8
// 006052c0  e86b29f8ff           call 0x587c30
// 006052c5  8b542414             mov edx, dword ptr [esp + 0x14]
// 006052c9  8b420c               mov eax, dword ptr [edx + 0xc]
// 006052cc  3b4500               cmp eax, dword ptr [ebp]
// 006052cf  730e                 jae 0x6052df
// 006052d1  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006052d5  55                   push ebp
// 006052d6  56                   push esi
// 006052d7  51                   push ecx
// 006052d8  8d54241c             lea edx, [esp + 0x1c]
// 006052dc  52                   push edx
// 006052dd  ebbd                 jmp 0x60529c
// 006052df  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006052e3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006052e7  5f                   pop edi
// 006052e8  5e                   pop esi
// 006052e9  8908                 mov dword ptr [eax], ecx
// 006052eb  895004               mov dword ptr [eax + 4], edx
// 006052ee  c6400800             mov byte ptr [eax + 8], 0
// 006052f2  5d                   pop ebp
// 006052f3  83c40c               add esp, 0xc
// 006052f6  c20800               ret 8
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
