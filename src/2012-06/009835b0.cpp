// from server: 29% by atomic.potato
// roc 2012-06 009835b0  unit: boost::exception  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009835b0
//
// 009835b0  833d6003e60000       cmp dword ptr [0xe60360], 0
// 009835b7  742d                 je 0x9835e6
// 009835b9  55                   push ebp
// 009835ba  8bec                 mov ebp, esp
// 009835bc  83ec08               sub esp, 8
// 009835bf  83e4f8               and esp, 0xfffffff8
// 009835c2  dd1c24               fstp qword ptr [esp]
// 009835c5  f20f2c0424           cvttsd2si eax, qword ptr [esp]
// 009835ca  c9                   leave
// 009835cb  c3                   ret
// 009835cc  833d6003e60000       cmp dword ptr [0xe60360], 0
// 009835d3  7411                 je 0x9835e6
// 009835d5  83ec04               sub esp, 4
// 009835d8  d93c24               fnstcw word ptr [esp]
// 009835db  58                   pop eax
// 009835dc  6683e07f             and ax, 0x7f
// 009835e0  6683f87f             cmp ax, 0x7f
// 009835e4  74d3                 je 0x9835b9
// 009835e6  c3                   ret

extern "C" int _fltused;

extern int g_flag;

extern "C" int __cdecl convert_double(double value)
{
    if (g_flag == 0)
        return 0;
    return (int)value;
}

extern "C" int __cdecl convert_float(float value)
{
    if (g_flag == 0)
        return 0;
    return (int)value;
}
