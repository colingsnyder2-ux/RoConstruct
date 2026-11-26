// from server: 100% by Xemicl
// roc 2012-06 0041cbc0  unit: RBX::Reflection::$$CBUTuple::$$A6AXV?$shared_ptr::PAV?$function::?$sp_counted_impl_pd  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0041cbc0
//
// 0041cbc0  51                   push ecx
// 0041cbc1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041cbc5  56                   push esi
// 0041cbc6  57                   push edi
// 0041cbc7  50                   push eax
// 0041cbc8  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0041cbd0  e88b612a00           call 0x6c2d60
// 0041cbd5  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0041cbd9  83c404               add esp, 4
// 0041cbdc  8bf0                 mov esi, eax
// 0041cbde  56                   push esi
// 0041cbdf  8bcf                 mov ecx, edi
// 0041cbe1  ff154426b200         call dword ptr [0xb22644]
// 0041cbe7  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0041cbea  894f1c               mov dword ptr [edi + 0x1c], ecx
// 0041cbed  8bc7                 mov eax, edi
// 0041cbef  5f                   pop edi
// 0041cbf0  5e                   pop esi
// 0041cbf1  59                   pop ecx
// 0041cbf2  c3                   ret 
// copied from an identical function in another client (function ??$any_cast@US@boost@@@boost@@YA?AUS@0@AAVany@0@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace boost {
class any;
struct S { std::string s; int v; };
template<class T> T* any_cast(any* operand);
template<> S* any_cast<S>(any* operand);
template<class T> T any_cast(any& operand) { return *any_cast<T>(&operand); }
template S any_cast<S>(any& operand);
}