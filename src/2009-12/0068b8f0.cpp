// from server: 100% by auto
// roc 2009-12 0068b8f0  unit: ArchiveBinder  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0068b8f0
//
// 0068b8f0  83ec14               sub esp, 0x14
// 0068b8f3  53                   push ebx
// 0068b8f4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0068b8f8  55                   push ebp
// 0068b8f9  56                   push esi
// 0068b8fa  8be9                 mov ebp, ecx
// 0068b8fc  57                   push edi
// 0068b8fd  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 0068b900  8b7704               mov esi, dword ptr [edi + 4]
// 0068b903  807e3100             cmp byte ptr [esi + 0x31], 0
// 0068b907  b001                 mov al, 1
// 0068b909  88442410             mov byte ptr [esp + 0x10], al
// 0068b90d  7526                 jne 0x68b935
// 0068b90f  90                   nop 
// 0068b910  8d460c               lea eax, [esi + 0xc]
// 0068b913  50                   push eax
// 0068b914  53                   push ebx
// 0068b915  8bfe                 mov edi, esi
// 0068b917  ff15d8b59800         call dword ptr [0x98b5d8]
// 0068b91d  83c408               add esp, 8
// 0068b920  88442410             mov byte ptr [esp + 0x10], al
// 0068b924  84c0                 test al, al
// 0068b926  7404                 je 0x68b92c
// 0068b928  8b36                 mov esi, dword ptr [esi]
// 0068b92a  eb03                 jmp 0x68b92f
// 0068b92c  8b7608               mov esi, dword ptr [esi + 8]
// 0068b92f  807e3100             cmp byte ptr [esi + 0x31], 0
// 0068b933  74db                 je 0x68b910
// 0068b935  8b7500               mov esi, dword ptr [ebp]
// 0068b938  897c2418             mov dword ptr [esp + 0x18], edi
// 0068b93c  89742414             mov dword ptr [esp + 0x14], esi
// 0068b940  84c0                 test al, al
// 0068b942  7458                 je 0x68b99c
// 0068b944  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0068b947  8b11                 mov edx, dword ptr [ecx]
// 0068b949  89542420             mov dword ptr [esp + 0x20], edx
// 0068b94d  85f6                 test esi, esi
// 0068b94f  7404                 je 0x68b955
// 0068b951  3bf6                 cmp esi, esi
// 0068b953  7406                 je 0x68b95b
// 0068b955  ff1560b79800         call dword ptr [0x98b760]
// 0068b95b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 0068b95f  752e                 jne 0x68b98f
// 0068b961  53                   push ebx
// 0068b962  57                   push edi
// 0068b963  6a01                 push 1
// 0068b965  8d442428             lea eax, [esp + 0x28]
// 0068b969  50                   push eax
// 0068b96a  8bcd                 mov ecx, ebp
// 0068b96c  e87ffdffff           call 0x68b6f0
// 0068b971  5f                   pop edi
// 0068b972  8bc8                 mov ecx, eax
// 0068b974  8b11                 mov edx, dword ptr [ecx]
// 0068b976  8b442424             mov eax, dword ptr [esp + 0x24]
// 0068b97a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0068b97d  5e                   pop esi
// 0068b97e  5d                   pop ebp
// 0068b97f  8910                 mov dword ptr [eax], edx
// 0068b981  894804               mov dword ptr [eax + 4], ecx
// 0068b984  c6400801             mov byte ptr [eax + 8], 1
// 0068b988  5b                   pop ebx
// 0068b989  83c414               add esp, 0x14
// 0068b98c  c20800               ret 8
// 0068b98f  8d4c2414             lea ecx, [esp + 0x14]
// 0068b993  e8c87ee8ff           call 0x513860
// 0068b998  8b742414             mov esi, dword ptr [esp + 0x14]
// 0068b99c  8b542418             mov edx, dword ptr [esp + 0x18]
// 0068b9a0  83c20c               add edx, 0xc
// 0068b9a3  53                   push ebx
// 0068b9a4  52                   push edx
// 0068b9a5  ff15d8b59800         call dword ptr [0x98b5d8]
// 0068b9ab  83c408               add esp, 8
// 0068b9ae  84c0                 test al, al
// 0068b9b0  740e                 je 0x68b9c0
// 0068b9b2  8b442410             mov eax, dword ptr [esp + 0x10]
// 0068b9b6  53                   push ebx
// 0068b9b7  57                   push edi
// 0068b9b8  50                   push eax
// 0068b9b9  8d4c2428             lea ecx, [esp + 0x28]
// 0068b9bd  51                   push ecx
// 0068b9be  ebaa                 jmp 0x68b96a
// 0068b9c0  8b442428             mov eax, dword ptr [esp + 0x28]
// 0068b9c4  8b542418             mov edx, dword ptr [esp + 0x18]
// 0068b9c8  5f                   pop edi
// 0068b9c9  8930                 mov dword ptr [eax], esi
// 0068b9cb  5e                   pop esi
// 0068b9cc  5d                   pop ebp
// 0068b9cd  895004               mov dword ptr [eax + 4], edx
// 0068b9d0  c6400800             mov byte ptr [eax + 8], 0
// 0068b9d4  5b                   pop ebx
// 0068b9d5  83c414               add esp, 0x14
// 0068b9d8  c20800               ret 8
// standard library map_str<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
