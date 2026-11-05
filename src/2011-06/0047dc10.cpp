// from server: 100% by auto
// roc 2011-06 0047dc10  unit: VCRobloxPlayer::?$CComObjectNoLock  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0047dc10
//
// 0047dc10  8b442408             mov eax, dword ptr [esp + 8]
// 0047dc14  8b08                 mov ecx, dword ptr [eax]
// 0047dc16  3b0d94daa600         cmp ecx, dword ptr [0xa6da94]
// 0047dc1c  7532                 jne 0x47dc50
// 0047dc1e  8b5004               mov edx, dword ptr [eax + 4]
// 0047dc21  3b1598daa600         cmp edx, dword ptr [0xa6da98]
// 0047dc27  7527                 jne 0x47dc50
// 0047dc29  8b4808               mov ecx, dword ptr [eax + 8]
// 0047dc2c  3b0d9cdaa600         cmp ecx, dword ptr [0xa6da9c]
// 0047dc32  751c                 jne 0x47dc50
// 0047dc34  8b500c               mov edx, dword ptr [eax + 0xc]
// 0047dc37  3b15a0daa600         cmp edx, dword ptr [0xa6daa0]
// 0047dc3d  7511                 jne 0x47dc50
// 0047dc3f  b801000000           mov eax, 1
// 0047dc44  33c9                 xor ecx, ecx
// 0047dc46  85c0                 test eax, eax
// 0047dc48  0f94c1               sete cl
// 0047dc4b  8bc1                 mov eax, ecx
// 0047dc4d  c20800               ret 8
// 0047dc50  33c0                 xor eax, eax
// 0047dc52  33c9                 xor ecx, ecx
// 0047dc54  85c0                 test eax, eax
// 0047dc56  0f94c1               sete cl
// 0047dc59  8bc1                 mov eax, ecx
// 0047dc5b  c20800               ret 8
// copied from an identical function in another client (function ?f@S_func_0040b570@ns_ROCX000002@ns_ROCX0000ed@@QAEHHPBH@Z)

namespace ns_ROCX000002 {
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/IPipelined.cpp
}
