// roc 2009-12 00810460  unit: CXTPImageManager  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00810460
//
// 00810460  8b442404             mov eax, dword ptr [esp + 4]
// 00810464  83f801               cmp eax, 1
// 00810467  7509                 jne 0x810472
// 00810469  89442404             mov dword ptr [esp + 4], eax
// 0081046d  e92efdffff           jmp 0x8101a0
// 00810472  83f802               cmp eax, 2
// 00810475  7508                 jne 0x81047f
// 00810477  e8d4a6ffff           call 0x80ab50
// 0081047c  c20400               ret 4
// 0081047f  83f803               cmp eax, 3
// 00810482  7508                 jne 0x81048c
// 00810484  e8e7a6ffff           call 0x80ab70
// 00810489  c20400               ret 4
// 0081048c  83f804               cmp eax, 4
// 0081048f  7508                 jne 0x810499
// 00810491  e8faa6ffff           call 0x80ab90
// 00810496  c20400               ret 4
// 00810499  e8a28cffff           call 0x809140
// 0081049e  c20400               ret 4
// copied from an identical function in another client (function ?func@CXTPImageManagerIconSet@ns_ROCX000032@ns_ROCX000018@@QAEXH@Z)

namespace ns_ROCX000032 {
extern void G1_func_00740370();
void fn_ROCX000032()
{
    G1_func_00740370();
}
}
