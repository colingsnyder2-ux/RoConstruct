// from server: 100% by EspClaude
// roc 2009-06 00710770  unit: RBX::TaskScheduler::VThread::?$sp_counted_impl_p  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00710770
//
// 00710770  837c240803           cmp dword ptr [esp + 8], 3
// 00710775  7505                 jne 0x71077c
// 00710777  e8f48bffff           call 0x709370
// 0071077c  c20c00               ret 0xc
// copied from an identical function in another client (function ?fn_ROCX00000c_0061a3f0@S@ns_ROCX00000c@@QAEXHHH@Z)

namespace ns_ROCX00000c {
struct S
{
    void target();
    void fn_ROCX00000c_0061a3f0(int, int, int);
};

void S::fn_ROCX00000c_0061a3f0(int, int value, int)
{
    if (value == 3)
        target();
}
}
