// from server: 100% by auto
// roc 2010-06 00665000  unit: RBX::Network::VPlayer::?$RemoteEventDesc  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00665000
//
// 00665000  6aff                 push -1
// 00665002  68b8d19b00           push 0x9bd1b8
// 00665007  64a100000000         mov eax, dword ptr fs:[0]
// 0066500d  50                   push eax
// 0066500e  64892500000000       mov dword ptr fs:[0], esp
// 00665015  83ec0c               sub esp, 0xc
// 00665018  56                   push esi
// 00665019  8bf1                 mov esi, ecx
// 0066501b  89742404             mov dword ptr [esp + 4], esi
// 0066501f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00665022  8b0e                 mov ecx, dword ptr [esi]
// 00665024  8b10                 mov edx, dword ptr [eax]
// 00665026  50                   push eax
// 00665027  51                   push ecx
// 00665028  52                   push edx
// 00665029  51                   push ecx
// 0066502a  8d442418             lea eax, [esp + 0x18]
// 0066502e  50                   push eax
// 0066502f  8bce                 mov ecx, esi
// 00665031  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00665039  e8f2f7ffff           call 0x664830
// 0066503e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00665041  51                   push ecx
// 00665042  e853291400           call 0x7a799a
// 00665047  8b16                 mov edx, dword ptr [esi]
// 00665049  52                   push edx
// 0066504a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00665051  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00665058  e83d291400           call 0x7a799a
// 0066505d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00665061  83c408               add esp, 8
// 00665064  5e                   pop esi
// 00665065  64890d00000000       mov dword ptr fs:[0], ecx
// 0066506c  83c418               add esp, 0x18
// 0066506f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
