// from server: 100% by auto
// roc 2007-08 005870f0  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005870f0
//
// 005870f0  8b442404             mov eax, dword ptr [esp + 4]
// 005870f4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005870f8  3bc1                 cmp eax, ecx
// 005870fa  7411                 je 0x58710d
// 005870fc  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00587100  56                   push esi
// 00587101  8b32                 mov esi, dword ptr [edx]
// 00587103  8930                 mov dword ptr [eax], esi
// 00587105  83c004               add eax, 4
// 00587108  3bc1                 cmp eax, ecx
// 0058710a  75f5                 jne 0x587101
// 0058710c  5e                   pop esi
// 0058710d  c3                   ret 
// standard library vector<ptr> (function ??$_Fill@PAPAUT@@PAU1@@std@@YAXPAPAUT@@0ABQAU1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
