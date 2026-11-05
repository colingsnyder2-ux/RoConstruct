// roc 2012-06 008598e0  unit: boost::iostreams::Uinput::V?$chain::?$chain_client  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008598e0
//
// 008598e0  80790400             cmp byte ptr [ecx + 4], 0
// 008598e4  7404                 je 0x8598ea
// 008598e6  c6410400             mov byte ptr [ecx + 4], 0
// 008598ea  c3                   ret 
// copied from an identical function in another client (function ?f@S_func_0054b1a0@ns_ROCX000004@@QAEXXZ)

namespace ns_ROCX000004 {
struct S_func_0054b1a0
{
    int z0;
    char flag;
    void f();
};

void S_func_0054b1a0::f()
{
    if (flag)
        flag = 0;
}
}
