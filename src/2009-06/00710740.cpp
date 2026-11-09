// from server: 100% by EspClaude
// roc 2009-06 00710740  unit: RBX::TaskScheduler::VThread::?$sp_counted_impl_p  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00710740
//
// 00710740  6870937000           push 0x709370
// 00710745  e8b1930000           call 0x719afb
// 0071074a  83c404               add esp, 4
// 0071074d  e88e42f6ff           call 0x6749e0
// 00710752  33c0                 xor eax, eax
// 00710754  c3                   ret 
// copied from an identical function in another client (function ?f@ns_ROCX00000b@@YAHXZ)

namespace ns_ROCX00000b {
extern "C" void __cdecl cleanup();
extern "C" int __cdecl register_exit(void (__cdecl *)());
extern "C" void __cdecl initialize();

int __cdecl f()
{
    register_exit(cleanup);
    initialize();
    return 0;
}
}
