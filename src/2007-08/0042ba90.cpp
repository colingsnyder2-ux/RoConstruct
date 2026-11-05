// from server: 100% by auto
// roc 2007-08 0042ba90  unit: VCLuaFunction::?$CComObjectNoLock  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042ba90
//
// 0042ba90  8b442404             mov eax, dword ptr [esp + 4]
// 0042ba94  53                   push ebx
// 0042ba95  56                   push esi
// 0042ba96  57                   push edi
// 0042ba97  8bf1                 mov esi, ecx
// 0042ba99  8b7e04               mov edi, dword ptr [esi + 4]
// 0042ba9c  8b4f04               mov ecx, dword ptr [edi + 4]
// 0042ba9f  50                   push eax
// 0042baa0  51                   push ecx
// 0042baa1  57                   push edi
// 0042baa2  8bce                 mov ecx, esi
// 0042baa4  e8f7f5ffff           call 0x42b0a0
// 0042baa9  6a01                 push 1
// 0042baab  8bce                 mov ecx, esi
// 0042baad  8bd8                 mov ebx, eax
// 0042baaf  e86cf0ffff           call 0x42ab20
// 0042bab4  895f04               mov dword ptr [edi + 4], ebx
// 0042bab7  8b5304               mov edx, dword ptr [ebx + 4]
// 0042baba  5f                   pop edi
// 0042babb  5e                   pop esi
// 0042babc  891a                 mov dword ptr [edx], ebx
// 0042babe  5b                   pop ebx
// 0042babf  c20400               ret 4
// standard library list<ptr> (function ?push_back@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
