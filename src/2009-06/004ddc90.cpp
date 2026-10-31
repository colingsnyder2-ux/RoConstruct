// from server: 100% by EspClaude
// roc 2009-06 004ddc90  unit: RBX::Network::ConcurrentRakPeer::PacketJob  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004ddc90
//
// 004ddc90  56                   push esi
// 004ddc91  8b742408             mov esi, dword ptr [esp + 8]
// 004ddc95  57                   push edi
// 004ddc96  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004ddc9a  57                   push edi
// 004ddc9b  56                   push esi
// 004ddc9c  e8eff6ffff           call 0x4dd390
// 004ddca1  8d4704               lea eax, [edi + 4]
// 004ddca4  50                   push eax
// 004ddca5  56                   push esi
// 004ddca6  e8e5f6ffff           call 0x4dd390
// 004ddcab  83c708               add edi, 8
// 004ddcae  57                   push edi
// 004ddcaf  56                   push esi
// 004ddcb0  e8dbf6ffff           call 0x4dd390
// 004ddcb5  83c418               add esp, 0x18
// 004ddcb8  5f                   pop edi
// 004ddcb9  8bc6                 mov eax, esi
// 004ddcbb  5e                   pop esi
// 004ddcbc  c3                   ret 
// copied from an identical function in another client (function ?copy_three@ns_ROCX000067@@YAPAXPAXPBM@Z)

namespace ns_ROCX000067 {
extern void __cdecl transfer(void *destination, const float *source);

void *__cdecl copy_three(void *destination, const float *source)
{
    transfer(destination, source);
    transfer(destination, source + 1);
    transfer(destination, source + 2);
    return destination;
}
}
