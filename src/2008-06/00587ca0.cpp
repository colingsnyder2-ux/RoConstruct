// from server: 100% by auto
// roc 2008-06 00587ca0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00587ca0
//
// 00587ca0  8b442404             mov eax, dword ptr [esp + 4]
// 00587ca4  53                   push ebx
// 00587ca5  56                   push esi
// 00587ca6  57                   push edi
// 00587ca7  8bf1                 mov esi, ecx
// 00587ca9  8b7e14               mov edi, dword ptr [esi + 0x14]
// 00587cac  8b4f04               mov ecx, dword ptr [edi + 4]
// 00587caf  50                   push eax
// 00587cb0  51                   push ecx
// 00587cb1  57                   push edi
// 00587cb2  8bce                 mov ecx, esi
// 00587cb4  e8f7530c00           call 0x64d0b0
// 00587cb9  6a01                 push 1
// 00587cbb  8bce                 mov ecx, esi
// 00587cbd  8bd8                 mov ebx, eax
// 00587cbf  e8fca90600           call 0x5f26c0
// 00587cc4  895f04               mov dword ptr [edi + 4], ebx
// 00587cc7  8b5304               mov edx, dword ptr [ebx + 4]
// 00587cca  5f                   pop edi
// 00587ccb  5e                   pop esi
// 00587ccc  891a                 mov dword ptr [edx], ebx
// 00587cce  5b                   pop ebx
// 00587ccf  c20400               ret 4
// standard library list<ptr> (function ?push_back@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
