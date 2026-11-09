// from server: 100% by auto
// roc 2010-06 005cf8c0  unit: RBX::VInstance::?$NonFactoryProduct  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005cf8c0
//
// 005cf8c0  83ec14               sub esp, 0x14
// 005cf8c3  53                   push ebx
// 005cf8c4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 005cf8c8  55                   push ebp
// 005cf8c9  56                   push esi
// 005cf8ca  8be9                 mov ebp, ecx
// 005cf8cc  57                   push edi
// 005cf8cd  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005cf8d0  8b7704               mov esi, dword ptr [edi + 4]
// 005cf8d3  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 005cf8d7  b001                 mov al, 1
// 005cf8d9  88442410             mov byte ptr [esp + 0x10], al
// 005cf8dd  7526                 jne 0x5cf905
// 005cf8df  90                   nop 
// 005cf8e0  8d460c               lea eax, [esi + 0xc]
// 005cf8e3  50                   push eax
// 005cf8e4  53                   push ebx
// 005cf8e5  8bfe                 mov edi, esi
// 005cf8e7  ff151ca59e00         call dword ptr [0x9ea51c]
// 005cf8ed  83c408               add esp, 8
// 005cf8f0  88442410             mov byte ptr [esp + 0x10], al
// 005cf8f4  84c0                 test al, al
// 005cf8f6  7404                 je 0x5cf8fc
// 005cf8f8  8b36                 mov esi, dword ptr [esi]
// 005cf8fa  eb03                 jmp 0x5cf8ff
// 005cf8fc  8b7608               mov esi, dword ptr [esi + 8]
// 005cf8ff  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 005cf903  74db                 je 0x5cf8e0
// 005cf905  8b7500               mov esi, dword ptr [ebp]
// 005cf908  897c2418             mov dword ptr [esp + 0x18], edi
// 005cf90c  89742414             mov dword ptr [esp + 0x14], esi
// 005cf910  84c0                 test al, al
// 005cf912  7458                 je 0x5cf96c
// 005cf914  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 005cf917  8b11                 mov edx, dword ptr [ecx]
// 005cf919  89542420             mov dword ptr [esp + 0x20], edx
// 005cf91d  85f6                 test esi, esi
// 005cf91f  7404                 je 0x5cf925
// 005cf921  3bf6                 cmp esi, esi
// 005cf923  7406                 je 0x5cf92b
// 005cf925  ff150ca99e00         call dword ptr [0x9ea90c]
// 005cf92b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 005cf92f  752e                 jne 0x5cf95f
// 005cf931  53                   push ebx
// 005cf932  57                   push edi
// 005cf933  6a01                 push 1
// 005cf935  8d442428             lea eax, [esp + 0x28]
// 005cf939  50                   push eax
// 005cf93a  8bcd                 mov ecx, ebp
// 005cf93c  e8cff0ffff           call 0x5cea10
// 005cf941  5f                   pop edi
// 005cf942  8bc8                 mov ecx, eax
// 005cf944  8b11                 mov edx, dword ptr [ecx]
// 005cf946  8b442424             mov eax, dword ptr [esp + 0x24]
// 005cf94a  8b4904               mov ecx, dword ptr [ecx + 4]
// 005cf94d  5e                   pop esi
// 005cf94e  5d                   pop ebp
// 005cf94f  8910                 mov dword ptr [eax], edx
// 005cf951  894804               mov dword ptr [eax + 4], ecx
// 005cf954  c6400801             mov byte ptr [eax + 8], 1
// 005cf958  5b                   pop ebx
// 005cf959  83c414               add esp, 0x14
// 005cf95c  c20800               ret 8
// 005cf95f  8d4c2414             lea ecx, [esp + 0x14]
// 005cf963  e8b89e1600           call 0x739820
// 005cf968  8b742414             mov esi, dword ptr [esp + 0x14]
// 005cf96c  8b542418             mov edx, dword ptr [esp + 0x18]
// 005cf970  83c20c               add edx, 0xc
// 005cf973  53                   push ebx
// 005cf974  52                   push edx
// 005cf975  ff151ca59e00         call dword ptr [0x9ea51c]
// 005cf97b  83c408               add esp, 8
// 005cf97e  84c0                 test al, al
// 005cf980  740e                 je 0x5cf990
// 005cf982  8b442410             mov eax, dword ptr [esp + 0x10]
// 005cf986  53                   push ebx
// 005cf987  57                   push edi
// 005cf988  50                   push eax
// 005cf989  8d4c2428             lea ecx, [esp + 0x28]
// 005cf98d  51                   push ecx
// 005cf98e  ebaa                 jmp 0x5cf93a
// 005cf990  8b442428             mov eax, dword ptr [esp + 0x28]
// 005cf994  8b542418             mov edx, dword ptr [esp + 0x18]
// 005cf998  5f                   pop edi
// 005cf999  8930                 mov dword ptr [eax], esi
// 005cf99b  5e                   pop esi
// 005cf99c  5d                   pop ebp
// 005cf99d  895004               mov dword ptr [eax + 4], edx
// 005cf9a0  c6400800             mov byte ptr [eax + 8], 0
// 005cf9a4  5b                   pop ebx
// 005cf9a5  83c414               add esp, 0x14
// 005cf9a8  c20800               ret 8
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
