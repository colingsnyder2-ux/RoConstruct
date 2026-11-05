// from server: 100% by auto
// roc 2007-08 00440c20  unit: CSelectionPropGrid  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00440c20
//
// 00440c20  83ec0c               sub esp, 0xc
// 00440c23  55                   push ebp
// 00440c24  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00440c28  56                   push esi
// 00440c29  57                   push edi
// 00440c2a  8bf9                 mov edi, ecx
// 00440c2c  8b7704               mov esi, dword ptr [edi + 4]
// 00440c2f  8b4604               mov eax, dword ptr [esi + 4]
// 00440c32  80782100             cmp byte ptr [eax + 0x21], 0
// 00440c36  b101                 mov cl, 1
// 00440c38  884c240c             mov byte ptr [esp + 0xc], cl
// 00440c3c  7520                 jne 0x440c5e
// 00440c3e  8b5500               mov edx, dword ptr [ebp]
// 00440c41  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00440c44  8bf0                 mov esi, eax
// 00440c46  0f92c1               setb cl
// 00440c49  84c9                 test cl, cl
// 00440c4b  884c240c             mov byte ptr [esp + 0xc], cl
// 00440c4f  7404                 je 0x440c55
// 00440c51  8b00                 mov eax, dword ptr [eax]
// 00440c53  eb03                 jmp 0x440c58
// 00440c55  8b4008               mov eax, dword ptr [eax + 8]
// 00440c58  80782100             cmp byte ptr [eax + 0x21], 0
// 00440c5c  74e3                 je 0x440c41
// 00440c5e  84c9                 test cl, cl
// 00440c60  8bd6                 mov edx, esi
// 00440c62  89542414             mov dword ptr [esp + 0x14], edx
// 00440c66  897c2410             mov dword ptr [esp + 0x10], edi
// 00440c6a  743d                 je 0x440ca9
// 00440c6c  8b4704               mov eax, dword ptr [edi + 4]
// 00440c6f  3b30                 cmp esi, dword ptr [eax]
// 00440c71  8d4c2410             lea ecx, [esp + 0x10]
// 00440c75  7529                 jne 0x440ca0
// 00440c77  55                   push ebp
// 00440c78  56                   push esi
// 00440c79  6a01                 push 1
// 00440c7b  51                   push ecx
// 00440c7c  8bcf                 mov ecx, edi
// 00440c7e  e8bde7ffff           call 0x43f440
// 00440c83  8bc8                 mov ecx, eax
// 00440c85  8b11                 mov edx, dword ptr [ecx]
// 00440c87  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00440c8b  8b4904               mov ecx, dword ptr [ecx + 4]
// 00440c8e  5f                   pop edi
// 00440c8f  5e                   pop esi
// 00440c90  8910                 mov dword ptr [eax], edx
// 00440c92  894804               mov dword ptr [eax + 4], ecx
// 00440c95  c6400801             mov byte ptr [eax + 8], 1
// 00440c99  5d                   pop ebp
// 00440c9a  83c40c               add esp, 0xc
// 00440c9d  c20800               ret 8
// 00440ca0  e80bf70500           call 0x4a03b0
// 00440ca5  8b542414             mov edx, dword ptr [esp + 0x14]
// 00440ca9  8b420c               mov eax, dword ptr [edx + 0xc]
// 00440cac  3b4500               cmp eax, dword ptr [ebp]
// 00440caf  730e                 jae 0x440cbf
// 00440cb1  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00440cb5  55                   push ebp
// 00440cb6  56                   push esi
// 00440cb7  51                   push ecx
// 00440cb8  8d54241c             lea edx, [esp + 0x1c]
// 00440cbc  52                   push edx
// 00440cbd  ebbd                 jmp 0x440c7c
// 00440cbf  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00440cc3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00440cc7  5f                   pop edi
// 00440cc8  5e                   pop esi
// 00440cc9  8908                 mov dword ptr [eax], ecx
// 00440ccb  895004               mov dword ptr [eax + 4], edx
// 00440cce  c6400800             mov byte ptr [eax + 8], 0
// 00440cd2  5d                   pop ebp
// 00440cd3  83c40c               add esp, 0xc
// 00440cd6  c20800               ret 8
// standard library map_ptr<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod16>
struct E { int v[4]; };
#include <map>
struct K; template class std::map<K*, E>;
