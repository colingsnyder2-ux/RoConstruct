// from server: 100% by auto
// roc 2007-08 004ab020  unit: RBX::Network::Peer  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ab020
//
// 004ab020  83ec0c               sub esp, 0xc
// 004ab023  55                   push ebp
// 004ab024  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004ab028  56                   push esi
// 004ab029  57                   push edi
// 004ab02a  8bf9                 mov edi, ecx
// 004ab02c  8b7704               mov esi, dword ptr [edi + 4]
// 004ab02f  8b4604               mov eax, dword ptr [esi + 4]
// 004ab032  80781900             cmp byte ptr [eax + 0x19], 0
// 004ab036  b101                 mov cl, 1
// 004ab038  884c240c             mov byte ptr [esp + 0xc], cl
// 004ab03c  7520                 jne 0x4ab05e
// 004ab03e  8b5500               mov edx, dword ptr [ebp]
// 004ab041  3b500c               cmp edx, dword ptr [eax + 0xc]
// 004ab044  8bf0                 mov esi, eax
// 004ab046  0f92c1               setb cl
// 004ab049  84c9                 test cl, cl
// 004ab04b  884c240c             mov byte ptr [esp + 0xc], cl
// 004ab04f  7404                 je 0x4ab055
// 004ab051  8b00                 mov eax, dword ptr [eax]
// 004ab053  eb03                 jmp 0x4ab058
// 004ab055  8b4008               mov eax, dword ptr [eax + 8]
// 004ab058  80781900             cmp byte ptr [eax + 0x19], 0
// 004ab05c  74e3                 je 0x4ab041
// 004ab05e  84c9                 test cl, cl
// 004ab060  8bd6                 mov edx, esi
// 004ab062  89542414             mov dword ptr [esp + 0x14], edx
// 004ab066  897c2410             mov dword ptr [esp + 0x10], edi
// 004ab06a  743d                 je 0x4ab0a9
// 004ab06c  8b4704               mov eax, dword ptr [edi + 4]
// 004ab06f  3b30                 cmp esi, dword ptr [eax]
// 004ab071  8d4c2410             lea ecx, [esp + 0x10]
// 004ab075  7529                 jne 0x4ab0a0
// 004ab077  55                   push ebp
// 004ab078  56                   push esi
// 004ab079  6a01                 push 1
// 004ab07b  51                   push ecx
// 004ab07c  8bcf                 mov ecx, edi
// 004ab07e  e82de8ffff           call 0x4a98b0
// 004ab083  8bc8                 mov ecx, eax
// 004ab085  8b11                 mov edx, dword ptr [ecx]
// 004ab087  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ab08b  8b4904               mov ecx, dword ptr [ecx + 4]
// 004ab08e  5f                   pop edi
// 004ab08f  5e                   pop esi
// 004ab090  8910                 mov dword ptr [eax], edx
// 004ab092  894804               mov dword ptr [eax + 4], ecx
// 004ab095  c6400801             mov byte ptr [eax + 8], 1
// 004ab099  5d                   pop ebp
// 004ab09a  83c40c               add esp, 0xc
// 004ab09d  c20800               ret 8
// 004ab0a0  e88bcb0d00           call 0x587c30
// 004ab0a5  8b542414             mov edx, dword ptr [esp + 0x14]
// 004ab0a9  8b420c               mov eax, dword ptr [edx + 0xc]
// 004ab0ac  3b4500               cmp eax, dword ptr [ebp]
// 004ab0af  730e                 jae 0x4ab0bf
// 004ab0b1  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004ab0b5  55                   push ebp
// 004ab0b6  56                   push esi
// 004ab0b7  51                   push ecx
// 004ab0b8  8d54241c             lea edx, [esp + 0x1c]
// 004ab0bc  52                   push edx
// 004ab0bd  ebbd                 jmp 0x4ab07c
// 004ab0bf  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ab0c3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004ab0c7  5f                   pop edi
// 004ab0c8  5e                   pop esi
// 004ab0c9  8908                 mov dword ptr [eax], ecx
// 004ab0cb  895004               mov dword ptr [eax + 4], edx
// 004ab0ce  c6400800             mov byte ptr [eax + 8], 0
// 004ab0d2  5d                   pop ebp
// 004ab0d3  83c40c               add esp, 0xc
// 004ab0d6  c20800               ret 8
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
