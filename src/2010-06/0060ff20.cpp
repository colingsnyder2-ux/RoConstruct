// from server: 100% by auto
// roc 2010-06 0060ff20  unit: RBX::VScriptContext::?$FactoryProduct  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0060ff20
//
// 0060ff20  83ec14               sub esp, 0x14
// 0060ff23  53                   push ebx
// 0060ff24  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0060ff28  55                   push ebp
// 0060ff29  56                   push esi
// 0060ff2a  8be9                 mov ebp, ecx
// 0060ff2c  57                   push edi
// 0060ff2d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 0060ff30  8b7704               mov esi, dword ptr [edi + 4]
// 0060ff33  807e4900             cmp byte ptr [esi + 0x49], 0
// 0060ff37  b001                 mov al, 1
// 0060ff39  88442410             mov byte ptr [esp + 0x10], al
// 0060ff3d  7526                 jne 0x60ff65
// 0060ff3f  90                   nop 
// 0060ff40  8d460c               lea eax, [esi + 0xc]
// 0060ff43  50                   push eax
// 0060ff44  53                   push ebx
// 0060ff45  8bfe                 mov edi, esi
// 0060ff47  ff151ca59e00         call dword ptr [0x9ea51c]
// 0060ff4d  83c408               add esp, 8
// 0060ff50  88442410             mov byte ptr [esp + 0x10], al
// 0060ff54  84c0                 test al, al
// 0060ff56  7404                 je 0x60ff5c
// 0060ff58  8b36                 mov esi, dword ptr [esi]
// 0060ff5a  eb03                 jmp 0x60ff5f
// 0060ff5c  8b7608               mov esi, dword ptr [esi + 8]
// 0060ff5f  807e4900             cmp byte ptr [esi + 0x49], 0
// 0060ff63  74db                 je 0x60ff40
// 0060ff65  8b7500               mov esi, dword ptr [ebp]
// 0060ff68  897c2418             mov dword ptr [esp + 0x18], edi
// 0060ff6c  89742414             mov dword ptr [esp + 0x14], esi
// 0060ff70  84c0                 test al, al
// 0060ff72  7458                 je 0x60ffcc
// 0060ff74  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0060ff77  8b11                 mov edx, dword ptr [ecx]
// 0060ff79  89542420             mov dword ptr [esp + 0x20], edx
// 0060ff7d  85f6                 test esi, esi
// 0060ff7f  7404                 je 0x60ff85
// 0060ff81  3bf6                 cmp esi, esi
// 0060ff83  7406                 je 0x60ff8b
// 0060ff85  ff150ca99e00         call dword ptr [0x9ea90c]
// 0060ff8b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 0060ff8f  752e                 jne 0x60ffbf
// 0060ff91  53                   push ebx
// 0060ff92  57                   push edi
// 0060ff93  6a01                 push 1
// 0060ff95  8d442428             lea eax, [esp + 0x28]
// 0060ff99  50                   push eax
// 0060ff9a  8bcd                 mov ecx, ebp
// 0060ff9c  e87ff7ffff           call 0x60f720
// 0060ffa1  5f                   pop edi
// 0060ffa2  8bc8                 mov ecx, eax
// 0060ffa4  8b11                 mov edx, dword ptr [ecx]
// 0060ffa6  8b442424             mov eax, dword ptr [esp + 0x24]
// 0060ffaa  8b4904               mov ecx, dword ptr [ecx + 4]
// 0060ffad  5e                   pop esi
// 0060ffae  5d                   pop ebp
// 0060ffaf  8910                 mov dword ptr [eax], edx
// 0060ffb1  894804               mov dword ptr [eax + 4], ecx
// 0060ffb4  c6400801             mov byte ptr [eax + 8], 1
// 0060ffb8  5b                   pop ebx
// 0060ffb9  83c414               add esp, 0x14
// 0060ffbc  c20800               ret 8
// 0060ffbf  8d4c2414             lea ecx, [esp + 0x14]
// 0060ffc3  e86899fdff           call 0x5e9930
// 0060ffc8  8b742414             mov esi, dword ptr [esp + 0x14]
// 0060ffcc  8b542418             mov edx, dword ptr [esp + 0x18]
// 0060ffd0  83c20c               add edx, 0xc
// 0060ffd3  53                   push ebx
// 0060ffd4  52                   push edx
// 0060ffd5  ff151ca59e00         call dword ptr [0x9ea51c]
// 0060ffdb  83c408               add esp, 8
// 0060ffde  84c0                 test al, al
// 0060ffe0  740e                 je 0x60fff0
// 0060ffe2  8b442410             mov eax, dword ptr [esp + 0x10]
// 0060ffe6  53                   push ebx
// 0060ffe7  57                   push edi
// 0060ffe8  50                   push eax
// 0060ffe9  8d4c2428             lea ecx, [esp + 0x28]
// 0060ffed  51                   push ecx
// 0060ffee  ebaa                 jmp 0x60ff9a
// 0060fff0  8b442428             mov eax, dword ptr [esp + 0x28]
// 0060fff4  8b542418             mov edx, dword ptr [esp + 0x18]
// 0060fff8  5f                   pop edi
// 0060fff9  8930                 mov dword ptr [eax], esi
// 0060fffb  5e                   pop esi
// 0060fffc  5d                   pop ebp
// 0060fffd  895004               mov dword ptr [eax + 4], edx
// 00610000  c6400800             mov byte ptr [eax + 8], 0
// 00610004  5b                   pop ebx
// 00610005  83c414               add esp, 0x14
// 00610008  c20800               ret 8
// standard library map_str<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
