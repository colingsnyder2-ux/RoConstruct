// roc 2012-06 0081c130  unit: RBX::Reflection::UTuple::$$A6A?AV?$shared_ptr::V?$function::?$sp_counted_impl_p  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0081c130
//
// 0081c130  807c240400           cmp byte ptr [esp + 4], 0
// 0081c135  8b01                 mov eax, dword ptr [ecx]
// 0081c137  7411                 je 0x81c14a
// 0081c139  83f801               cmp eax, 1
// 0081c13c  7e1a                 jle 0x81c158
// 0081c13e  99                   cdq 
// 0081c13f  2bc2                 sub eax, edx
// 0081c141  d1f8                 sar eax, 1
// 0081c143  8901                 mov dword ptr [ecx], eax
// 0081c145  b001                 mov al, 1
// 0081c147  c20400               ret 4
// 0081c14a  83f810               cmp eax, 0x10
// 0081c14d  7d09                 jge 0x81c158
// 0081c14f  03c0                 add eax, eax
// 0081c151  8901                 mov dword ptr [ecx], eax
// 0081c153  b001                 mov al, 1
// 0081c155  c20400               ret 4
// 0081c158  32c0                 xor al, al
// 0081c15a  c20400               ret 4
// copied from an identical function in another client (function ?f@EventDesc@ns_ROCX000013@@QAEEE@Z)

namespace ns_ROCX000013 {
// from server: 100% by atomic.potato
struct EventDesc
{
    int value;
    unsigned char update;

    unsigned char __thiscall f(unsigned char update);
};

unsigned char __thiscall EventDesc::f(unsigned char update)
{
    if (update)
    {
        if (value > 1)
        {
            value = value / 2;
            return 1;
        }
    }
    else
    {
        if (value < 0x10)
        {
            value += value;
            return 1;
        }
    }
    return 0;
}
}