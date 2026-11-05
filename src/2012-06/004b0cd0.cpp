// roc 2012-06 004b0cd0  unit: CWebToolbox  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004b0cd0
//
// 004b0cd0  56                   push esi
// 004b0cd1  8b742408             mov esi, dword ptr [esp + 8]
// 004b0cd5  56                   push esi
// 004b0cd6  e8db174d00           call 0x9824b6
// 004b0cdb  85c0                 test eax, eax
// 004b0cdd  7507                 jne 0x4b0ce6
// 004b0cdf  814e0417408401       or dword ptr [esi + 4], 0x1844017
// 004b0ce6  5e                   pop esi
// 004b0ce7  c20400               ret 4
// copied from an identical function in another client (function ?sub_42a530@ns_ROCX000007@@YGHPAH@Z)

namespace ns_ROCX000007 {
extern "C" int __stdcall sub_630010(int* p);

int __stdcall sub_42a530(int* p)
{
    int result = sub_630010(p);
    if (result == 0)
        p[1] |= 0x1844017;
    return result;
}
}
