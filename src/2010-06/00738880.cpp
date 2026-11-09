// from server: 100% by auto
// roc 2010-06 00738880  unit: seg_00730000  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00738880
//
// 00738880  83ec14               sub esp, 0x14
// 00738883  53                   push ebx
// 00738884  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00738888  55                   push ebp
// 00738889  56                   push esi
// 0073888a  8be9                 mov ebp, ecx
// 0073888c  57                   push edi
// 0073888d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 00738890  8b7704               mov esi, dword ptr [edi + 4]
// 00738893  807e3900             cmp byte ptr [esi + 0x39], 0
// 00738897  b001                 mov al, 1
// 00738899  88442410             mov byte ptr [esp + 0x10], al
// 0073889d  7526                 jne 0x7388c5
// 0073889f  90                   nop 
// 007388a0  8d460c               lea eax, [esi + 0xc]
// 007388a3  50                   push eax
// 007388a4  53                   push ebx
// 007388a5  8bfe                 mov edi, esi
// 007388a7  ff151ca59e00         call dword ptr [0x9ea51c]
// 007388ad  83c408               add esp, 8
// 007388b0  88442410             mov byte ptr [esp + 0x10], al
// 007388b4  84c0                 test al, al
// 007388b6  7404                 je 0x7388bc
// 007388b8  8b36                 mov esi, dword ptr [esi]
// 007388ba  eb03                 jmp 0x7388bf
// 007388bc  8b7608               mov esi, dword ptr [esi + 8]
// 007388bf  807e3900             cmp byte ptr [esi + 0x39], 0
// 007388c3  74db                 je 0x7388a0
// 007388c5  8b7500               mov esi, dword ptr [ebp]
// 007388c8  897c2418             mov dword ptr [esp + 0x18], edi
// 007388cc  89742414             mov dword ptr [esp + 0x14], esi
// 007388d0  84c0                 test al, al
// 007388d2  7458                 je 0x73892c
// 007388d4  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 007388d7  8b11                 mov edx, dword ptr [ecx]
// 007388d9  89542420             mov dword ptr [esp + 0x20], edx
// 007388dd  85f6                 test esi, esi
// 007388df  7404                 je 0x7388e5
// 007388e1  3bf6                 cmp esi, esi
// 007388e3  7406                 je 0x7388eb
// 007388e5  ff150ca99e00         call dword ptr [0x9ea90c]
// 007388eb  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 007388ef  752e                 jne 0x73891f
// 007388f1  53                   push ebx
// 007388f2  57                   push edi
// 007388f3  6a01                 push 1
// 007388f5  8d442428             lea eax, [esp + 0x28]
// 007388f9  50                   push eax
// 007388fa  8bcd                 mov ecx, ebp
// 007388fc  e8bffcffff           call 0x7385c0
// 00738901  5f                   pop edi
// 00738902  8bc8                 mov ecx, eax
// 00738904  8b11                 mov edx, dword ptr [ecx]
// 00738906  8b442424             mov eax, dword ptr [esp + 0x24]
// 0073890a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0073890d  5e                   pop esi
// 0073890e  5d                   pop ebp
// 0073890f  8910                 mov dword ptr [eax], edx
// 00738911  894804               mov dword ptr [eax + 4], ecx
// 00738914  c6400801             mov byte ptr [eax + 8], 1
// 00738918  5b                   pop ebx
// 00738919  83c414               add esp, 0x14
// 0073891c  c20800               ret 8
// 0073891f  8d4c2414             lea ecx, [esp + 0x14]
// 00738923  e838e41800           call 0x8c6d60
// 00738928  8b742414             mov esi, dword ptr [esp + 0x14]
// 0073892c  8b542418             mov edx, dword ptr [esp + 0x18]
// 00738930  83c20c               add edx, 0xc
// 00738933  53                   push ebx
// 00738934  52                   push edx
// 00738935  ff151ca59e00         call dword ptr [0x9ea51c]
// 0073893b  83c408               add esp, 8
// 0073893e  84c0                 test al, al
// 00738940  740e                 je 0x738950
// 00738942  8b442410             mov eax, dword ptr [esp + 0x10]
// 00738946  53                   push ebx
// 00738947  57                   push edi
// 00738948  50                   push eax
// 00738949  8d4c2428             lea ecx, [esp + 0x28]
// 0073894d  51                   push ecx
// 0073894e  ebaa                 jmp 0x7388fa
// 00738950  8b442428             mov eax, dword ptr [esp + 0x28]
// 00738954  8b542418             mov edx, dword ptr [esp + 0x18]
// 00738958  5f                   pop edi
// 00738959  8930                 mov dword ptr [eax], esi
// 0073895b  5e                   pop esi
// 0073895c  5d                   pop ebp
// 0073895d  895004               mov dword ptr [eax + 4], edx
// 00738960  c6400800             mov byte ptr [eax + 8], 0
// 00738964  5b                   pop ebx
// 00738965  83c414               add esp, 0x14
// 00738968  c20800               ret 8
// standard library map_str<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod16>
struct E { int v[4]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
