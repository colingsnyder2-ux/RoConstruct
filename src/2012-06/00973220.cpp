// from server: 100% by Xemicl
// roc 2012-06 00973220  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::delete_data  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00973220
//
// 00973220  56                   push esi
// 00973221  8b742408             mov esi, dword ptr [esp + 8]
// 00973225  85f6                 test esi, esi
// 00973227  7411                 je 0x97323a
// 00973229  8bce                 mov ecx, esi
// 0097322b  ff153c26b200         call dword ptr [0xb2263c]
// 00973231  56                   push esi
// 00973232  e8ddee0000           call 0x982114
// 00973237  83c404               add esp, 4
// 0097323a  5e                   pop esi
// 0097323b  c20400               ret 4
// copied from an identical function in another client (function ?destroyX@@YGXPAUX@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct X { __declspec(dllimport) ~X(); int a; };
void __stdcall destroyX(X* p) { delete p; }