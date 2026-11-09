// from server: 100% by auto
// roc 2009-06 00406080  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00406080
//
// 00406080  56                   push esi
// 00406081  8bf1                 mov esi, ecx
// 00406083  8d4608               lea eax, [esi + 8]
// 00406086  c74604010000c0       mov dword ptr [esi + 4], 0xc0000001
// 0040608d  c706acce8a00         mov dword ptr [esi], 0x8aceac
// 00406093  80781800             cmp byte ptr [eax + 0x18], 0
// 00406097  740b                 je 0x4060a4
// 00406099  50                   push eax
// 0040609a  c6401800             mov byte ptr [eax + 0x18], 0
// 0040609e  ff1544e38900         call dword ptr [0x89e344]
// 004060a4  f644240801           test byte ptr [esp + 8], 1
// 004060a9  7409                 je 0x4060b4
// 004060ab  56                   push esi
// 004060ac  e881293100           call 0x718a32
// 004060b1  83c404               add esp, 4
// 004060b4  8bc6                 mov eax, esi
// 004060b6  5e                   pop esi
// 004060b7  c20400               ret 4
// library atl-8.0/atl.cpp (function ??_G?$CComObjectNoLock@VCComClassFactory@ATL@@@ATL@@QAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
