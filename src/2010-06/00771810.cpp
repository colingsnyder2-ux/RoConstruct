// from server: 100% by auto
// roc 2010-06 00771810  unit: RBX::ScoreHud  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00771810
//
// 00771810  83ec14               sub esp, 0x14
// 00771813  53                   push ebx
// 00771814  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00771818  55                   push ebp
// 00771819  56                   push esi
// 0077181a  8be9                 mov ebp, ecx
// 0077181c  57                   push edi
// 0077181d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 00771820  8b7704               mov esi, dword ptr [edi + 4]
// 00771823  807e4900             cmp byte ptr [esi + 0x49], 0
// 00771827  b001                 mov al, 1
// 00771829  88442410             mov byte ptr [esp + 0x10], al
// 0077182d  7526                 jne 0x771855
// 0077182f  90                   nop 
// 00771830  8d460c               lea eax, [esi + 0xc]
// 00771833  50                   push eax
// 00771834  53                   push ebx
// 00771835  8bfe                 mov edi, esi
// 00771837  ff151ca59e00         call dword ptr [0x9ea51c]
// 0077183d  83c408               add esp, 8
// 00771840  88442410             mov byte ptr [esp + 0x10], al
// 00771844  84c0                 test al, al
// 00771846  7404                 je 0x77184c
// 00771848  8b36                 mov esi, dword ptr [esi]
// 0077184a  eb03                 jmp 0x77184f
// 0077184c  8b7608               mov esi, dword ptr [esi + 8]
// 0077184f  807e4900             cmp byte ptr [esi + 0x49], 0
// 00771853  74db                 je 0x771830
// 00771855  8b7500               mov esi, dword ptr [ebp]
// 00771858  897c2418             mov dword ptr [esp + 0x18], edi
// 0077185c  89742414             mov dword ptr [esp + 0x14], esi
// 00771860  84c0                 test al, al
// 00771862  7458                 je 0x7718bc
// 00771864  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00771867  8b11                 mov edx, dword ptr [ecx]
// 00771869  89542420             mov dword ptr [esp + 0x20], edx
// 0077186d  85f6                 test esi, esi
// 0077186f  7404                 je 0x771875
// 00771871  3bf6                 cmp esi, esi
// 00771873  7406                 je 0x77187b
// 00771875  ff150ca99e00         call dword ptr [0x9ea90c]
// 0077187b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 0077187f  752e                 jne 0x7718af
// 00771881  53                   push ebx
// 00771882  57                   push edi
// 00771883  6a01                 push 1
// 00771885  8d442428             lea eax, [esp + 0x28]
// 00771889  50                   push eax
// 0077188a  8bcd                 mov ecx, ebp
// 0077188c  e86ff3ffff           call 0x770c00
// 00771891  5f                   pop edi
// 00771892  8bc8                 mov ecx, eax
// 00771894  8b11                 mov edx, dword ptr [ecx]
// 00771896  8b442424             mov eax, dword ptr [esp + 0x24]
// 0077189a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0077189d  5e                   pop esi
// 0077189e  5d                   pop ebp
// 0077189f  8910                 mov dword ptr [eax], edx
// 007718a1  894804               mov dword ptr [eax + 4], ecx
// 007718a4  c6400801             mov byte ptr [eax + 8], 1
// 007718a8  5b                   pop ebx
// 007718a9  83c414               add esp, 0x14
// 007718ac  c20800               ret 8
// 007718af  8d4c2414             lea ecx, [esp + 0x14]
// 007718b3  e87880e7ff           call 0x5e9930
// 007718b8  8b742414             mov esi, dword ptr [esp + 0x14]
// 007718bc  8b542418             mov edx, dword ptr [esp + 0x18]
// 007718c0  83c20c               add edx, 0xc
// 007718c3  53                   push ebx
// 007718c4  52                   push edx
// 007718c5  ff151ca59e00         call dword ptr [0x9ea51c]
// 007718cb  83c408               add esp, 8
// 007718ce  84c0                 test al, al
// 007718d0  740e                 je 0x7718e0
// 007718d2  8b442410             mov eax, dword ptr [esp + 0x10]
// 007718d6  53                   push ebx
// 007718d7  57                   push edi
// 007718d8  50                   push eax
// 007718d9  8d4c2428             lea ecx, [esp + 0x28]
// 007718dd  51                   push ecx
// 007718de  ebaa                 jmp 0x77188a
// 007718e0  8b442428             mov eax, dword ptr [esp + 0x28]
// 007718e4  8b542418             mov edx, dword ptr [esp + 0x18]
// 007718e8  5f                   pop edi
// 007718e9  8930                 mov dword ptr [eax], esi
// 007718eb  5e                   pop esi
// 007718ec  5d                   pop ebp
// 007718ed  895004               mov dword ptr [eax + 4], edx
// 007718f0  c6400800             mov byte ptr [eax + 8], 0
// 007718f4  5b                   pop ebx
// 007718f5  83c414               add esp, 0x14
// 007718f8  c20800               ret 8
// standard library map_str<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
