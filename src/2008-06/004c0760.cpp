// from server: 100% by auto
// roc 2008-06 004c0760  unit: ProfiledRakPeer  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c0760
//
// 004c0760  8b442408             mov eax, dword ptr [esp + 8]
// 004c0764  8b542404             mov edx, dword ptr [esp + 4]
// 004c0768  56                   push esi
// 004c0769  57                   push edi
// 004c076a  8bf1                 mov esi, ecx
// 004c076c  50                   push eax
// 004c076d  8d4c2414             lea ecx, [esp + 0x14]
// 004c0771  51                   push ecx
// 004c0772  52                   push edx
// 004c0773  8bce                 mov ecx, esi
// 004c0775  e876d1ffff           call 0x4bd8f0
// 004c077a  807c241000           cmp byte ptr [esp + 0x10], 0
// 004c077f  8bf8                 mov edi, eax
// 004c0781  7507                 jne 0x4c078a
// 004c0783  5f                   pop edi
// 004c0784  33c0                 xor eax, eax
// 004c0786  5e                   pop esi
// 004c0787  c20800               ret 8
// 004c078a  57                   push edi
// 004c078b  8bce                 mov ecx, esi
// 004c078d  e82ed4ffff           call 0x4bdbc0
// 004c0792  8bc7                 mov eax, edi
// 004c0794  5f                   pop edi
// 004c0795  5e                   pop esi
// 004c0796  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?Remove@?$OrderedList@USystemAddress@@USystemAddressAndIndex@@$1?SystemAddressAndIndexComp@@YAHABU1@ABU2@@Z@DataStructures@@QAEIABUSystemAddress@@P6AH0ABUSystemAddressAndIndex@@@Z@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
