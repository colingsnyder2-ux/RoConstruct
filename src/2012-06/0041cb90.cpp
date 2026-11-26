// from server: 100% by Xemicl
// roc 2012-06 0041cb90  unit: RBX::Reflection::$$CBUTuple::$$A6AXV?$shared_ptr::PAV?$function::?$sp_counted_impl_pd  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0041cb90
//
// 0041cb90  51                   push ecx
// 0041cb91  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041cb95  56                   push esi
// 0041cb96  50                   push eax
// 0041cb97  c744240800000000     mov dword ptr [esp + 8], 0
// 0041cb9f  e83c2cffff           call 0x40f7e0
// 0041cba4  8b742410             mov esi, dword ptr [esp + 0x10]
// 0041cba8  83c404               add esp, 4
// 0041cbab  50                   push eax
// 0041cbac  8bce                 mov ecx, esi
// 0041cbae  ff154426b200         call dword ptr [0xb22644]
// 0041cbb4  8bc6                 mov eax, esi
// 0041cbb6  5e                   pop esi
// 0041cbb7  59                   pop ecx
// 0041cbb8  c3                   ret 
// copied from an identical function in another client (function ?f@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AAVany@boost@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace boost { class any; }
const std::string& CopyVerb(boost::any* a);
std::string f(boost::any& a)
{
    return CopyVerb(&a);
}