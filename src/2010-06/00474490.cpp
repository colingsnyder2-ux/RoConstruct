// from server: 100% by auto
// roc 2010-06 00474490  unit: CRobloxScriptReviewPaneView  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00474490
//
// 00474490  64a100000000         mov eax, dword ptr fs:[0]
// 00474496  6aff                 push -1
// 00474498  68c8669a00           push 0x9a66c8
// 0047449d  50                   push eax
// 0047449e  8b442410             mov eax, dword ptr [esp + 0x10]
// 004744a2  64892500000000       mov dword ptr fs:[0], esp
// 004744a9  83ec2c               sub esp, 0x2c
// 004744ac  55                   push ebp
// 004744ad  56                   push esi
// 004744ae  50                   push eax
// 004744af  8bf1                 mov esi, ecx
// 004744b1  e84aa32400           call 0x6be800
// 004744b6  8be8                 mov ebp, eax
// 004744b8  85f6                 test esi, esi
// 004744ba  7506                 jne 0x4744c2
// 004744bc  ff150ca99e00         call dword ptr [0x9ea90c]
// 004744c2  53                   push ebx
// 004744c3  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004744c6  57                   push edi
// 004744c7  8b3e                 mov edi, dword ptr [esi]
// 004744c9  85ff                 test edi, edi
// 004744cb  7404                 je 0x4744d1
// 004744cd  3bff                 cmp edi, edi
// 004744cf  7406                 je 0x4744d7
// 004744d1  ff150ca99e00         call dword ptr [0x9ea90c]
// 004744d7  3beb                 cmp ebp, ebx
// 004744d9  7416                 je 0x4744f1
// 004744db  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 004744df  8d4d0c               lea ecx, [ebp + 0xc]
// 004744e2  51                   push ecx
// 004744e3  52                   push edx
// 004744e4  ff151ca59e00         call dword ptr [0x9ea51c]
// 004744ea  83c408               add esp, 8
// 004744ed  84c0                 test al, al
// 004744ef  7447                 je 0x474538
// 004744f1  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 004744f5  50                   push eax
// 004744f6  8d4c241c             lea ecx, [esp + 0x1c]
// 004744fa  33db                 xor ebx, ebx
// 004744fc  ff150ca49e00         call dword ptr [0x9ea40c]
// 00474502  895c2434             mov dword ptr [esp + 0x34], ebx
// 00474506  895c2438             mov dword ptr [esp + 0x38], ebx
// 0047450a  8d4c2418             lea ecx, [esp + 0x18]
// 0047450e  51                   push ecx
// 0047450f  55                   push ebp
// 00474510  57                   push edi
// 00474511  8d54241c             lea edx, [esp + 0x1c]
// 00474515  52                   push edx
// 00474516  8bce                 mov ecx, esi
// 00474518  895c2454             mov dword ptr [esp + 0x54], ebx
// 0047451c  e8dfb82700           call 0x6efe00
// 00474521  8b38                 mov edi, dword ptr [eax]
// 00474523  8b6804               mov ebp, dword ptr [eax + 4]
// 00474526  8d4c2418             lea ecx, [esp + 0x18]
// 0047452a  c7442444ffffffff     mov dword ptr [esp + 0x44], 0xffffffff
// 00474532  ff1500a49e00         call dword ptr [0x9ea400]
// 00474538  85ff                 test edi, edi
// 0047453a  7529                 jne 0x474565
// 0047453c  ff150ca99e00         call dword ptr [0x9ea90c]
// 00474542  3b6f18               cmp ebp, dword ptr [edi + 0x18]
// 00474545  5f                   pop edi
// 00474546  5b                   pop ebx
// 00474547  7506                 jne 0x47454f
// 00474549  ff150ca99e00         call dword ptr [0x9ea90c]
// 0047454f  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00474553  5e                   pop esi
// 00474554  8d4528               lea eax, [ebp + 0x28]
// 00474557  5d                   pop ebp
// 00474558  64890d00000000       mov dword ptr fs:[0], ecx
// 0047455f  83c438               add esp, 0x38
// 00474562  c20400               ret 4
// 00474565  8b3f                 mov edi, dword ptr [edi]
// 00474567  ebd9                 jmp 0x474542
// standard library map_str<pod8> (function ??A?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@@std@@QAEAAUE@@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
