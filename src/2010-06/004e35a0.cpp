// from server: 100% by auto
// roc 2010-06 004e35a0  unit: RBX::Network::IdSerializer  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e35a0
//
// 004e35a0  83ec14               sub esp, 0x14
// 004e35a3  53                   push ebx
// 004e35a4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 004e35a8  55                   push ebp
// 004e35a9  56                   push esi
// 004e35aa  8be9                 mov ebp, ecx
// 004e35ac  57                   push edi
// 004e35ad  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 004e35b0  8b7704               mov esi, dword ptr [edi + 4]
// 004e35b3  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 004e35b7  b001                 mov al, 1
// 004e35b9  88442410             mov byte ptr [esp + 0x10], al
// 004e35bd  7526                 jne 0x4e35e5
// 004e35bf  90                   nop 
// 004e35c0  8d460c               lea eax, [esi + 0xc]
// 004e35c3  50                   push eax
// 004e35c4  53                   push ebx
// 004e35c5  8bfe                 mov edi, esi
// 004e35c7  ff151ca59e00         call dword ptr [0x9ea51c]
// 004e35cd  83c408               add esp, 8
// 004e35d0  88442410             mov byte ptr [esp + 0x10], al
// 004e35d4  84c0                 test al, al
// 004e35d6  7404                 je 0x4e35dc
// 004e35d8  8b36                 mov esi, dword ptr [esi]
// 004e35da  eb03                 jmp 0x4e35df
// 004e35dc  8b7608               mov esi, dword ptr [esi + 8]
// 004e35df  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 004e35e3  74db                 je 0x4e35c0
// 004e35e5  8b7500               mov esi, dword ptr [ebp]
// 004e35e8  897c2418             mov dword ptr [esp + 0x18], edi
// 004e35ec  89742414             mov dword ptr [esp + 0x14], esi
// 004e35f0  84c0                 test al, al
// 004e35f2  7458                 je 0x4e364c
// 004e35f4  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 004e35f7  8b11                 mov edx, dword ptr [ecx]
// 004e35f9  89542420             mov dword ptr [esp + 0x20], edx
// 004e35fd  85f6                 test esi, esi
// 004e35ff  7404                 je 0x4e3605
// 004e3601  3bf6                 cmp esi, esi
// 004e3603  7406                 je 0x4e360b
// 004e3605  ff150ca99e00         call dword ptr [0x9ea90c]
// 004e360b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 004e360f  752e                 jne 0x4e363f
// 004e3611  53                   push ebx
// 004e3612  57                   push edi
// 004e3613  6a01                 push 1
// 004e3615  8d442428             lea eax, [esp + 0x28]
// 004e3619  50                   push eax
// 004e361a  8bcd                 mov ecx, ebp
// 004e361c  e8dffbffff           call 0x4e3200
// 004e3621  5f                   pop edi
// 004e3622  8bc8                 mov ecx, eax
// 004e3624  8b11                 mov edx, dword ptr [ecx]
// 004e3626  8b442424             mov eax, dword ptr [esp + 0x24]
// 004e362a  8b4904               mov ecx, dword ptr [ecx + 4]
// 004e362d  5e                   pop esi
// 004e362e  5d                   pop ebp
// 004e362f  8910                 mov dword ptr [eax], edx
// 004e3631  894804               mov dword ptr [eax + 4], ecx
// 004e3634  c6400801             mov byte ptr [eax + 8], 1
// 004e3638  5b                   pop ebx
// 004e3639  83c414               add esp, 0x14
// 004e363c  c20800               ret 8
// 004e363f  8d4c2414             lea ecx, [esp + 0x14]
// 004e3643  e8d8612500           call 0x739820
// 004e3648  8b742414             mov esi, dword ptr [esp + 0x14]
// 004e364c  8b542418             mov edx, dword ptr [esp + 0x18]
// 004e3650  83c20c               add edx, 0xc
// 004e3653  53                   push ebx
// 004e3654  52                   push edx
// 004e3655  ff151ca59e00         call dword ptr [0x9ea51c]
// 004e365b  83c408               add esp, 8
// 004e365e  84c0                 test al, al
// 004e3660  740e                 je 0x4e3670
// 004e3662  8b442410             mov eax, dword ptr [esp + 0x10]
// 004e3666  53                   push ebx
// 004e3667  57                   push edi
// 004e3668  50                   push eax
// 004e3669  8d4c2428             lea ecx, [esp + 0x28]
// 004e366d  51                   push ecx
// 004e366e  ebaa                 jmp 0x4e361a
// 004e3670  8b442428             mov eax, dword ptr [esp + 0x28]
// 004e3674  8b542418             mov edx, dword ptr [esp + 0x18]
// 004e3678  5f                   pop edi
// 004e3679  8930                 mov dword ptr [eax], esi
// 004e367b  5e                   pop esi
// 004e367c  5d                   pop ebp
// 004e367d  895004               mov dword ptr [eax + 4], edx
// 004e3680  c6400800             mov byte ptr [eax + 8], 0
// 004e3684  5b                   pop ebx
// 004e3685  83c414               add esp, 0x14
// 004e3688  c20800               ret 8
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
