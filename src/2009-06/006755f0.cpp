// from server: 100% by auto
// roc 2009-06 006755f0  unit: RBX::VTimerService::?$FactoryProduct  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006755f0
//
// 006755f0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006755f4  8b5004               mov edx, dword ptr [eax + 4]
// 006755f7  53                   push ebx
// 006755f8  56                   push esi
// 006755f9  57                   push edi
// 006755fa  8bd9                 mov ebx, ecx
// 006755fc  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00675600  8d7804               lea edi, [eax + 4]
// 00675603  51                   push ecx
// 00675604  52                   push edx
// 00675605  50                   push eax
// 00675606  8bcb                 mov ecx, ebx
// 00675608  e853ffffff           call 0x675560
// 0067560d  6a01                 push 1
// 0067560f  8bcb                 mov ecx, ebx
// 00675611  8bf0                 mov esi, eax
// 00675613  e8584cf6ff           call 0x5da270
// 00675618  8937                 mov dword ptr [edi], esi
// 0067561a  8b4604               mov eax, dword ptr [esi + 4]
// 0067561d  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 00675623  8930                 mov dword ptr [eax], esi
// 00675625  8b442414             mov eax, dword ptr [esp + 0x14]
// 00675629  85c0                 test eax, eax
// 0067562b  7506                 jne 0x675633
// 0067562d  ffd7                 call edi
// 0067562f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00675633  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00675637  8b4904               mov ecx, dword ptr [ecx + 4]
// 0067563a  894c2418             mov dword ptr [esp + 0x18], ecx
// 0067563e  85c0                 test eax, eax
// 00675640  7404                 je 0x675646
// 00675642  8b00                 mov eax, dword ptr [eax]
// 00675644  eb02                 jmp 0x675648
// 00675646  33c0                 xor eax, eax
// 00675648  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 0067564b  7506                 jne 0x675653
// 0067564d  ffd7                 call edi
// 0067564f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00675653  8b742410             mov esi, dword ptr [esp + 0x10]
// 00675657  c70600000000         mov dword ptr [esi], 0
// 0067565d  894e04               mov dword ptr [esi + 4], ecx
// 00675660  85db                 test ebx, ebx
// 00675662  7502                 jne 0x675666
// 00675664  ffd7                 call edi
// 00675666  8b13                 mov edx, dword ptr [ebx]
// 00675668  5f                   pop edi
// 00675669  8916                 mov dword ptr [esi], edx
// 0067566b  8bc6                 mov eax, esi
// 0067566d  5e                   pop esi
// 0067566e  5b                   pop ebx
// 0067566f  c21000               ret 0x10
// standard library list<ptr> (function ?insert@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
