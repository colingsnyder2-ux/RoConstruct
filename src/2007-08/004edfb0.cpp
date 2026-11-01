// from server: 100% by Yeetserama
// roc 2007-08 004edfb0  unit: HeadBuilder  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004edfb0
//
// 004edfb0  83ec0c               sub esp, 0xc
// 004edfb3  8b4124               mov eax, dword ptr [ecx + 0x24]
// 004edfb6  d94120               fld dword ptr [ecx + 0x20]
// 004edfb9  83c001               add eax, 1
// 004edfbc  d95c2404             fstp dword ptr [esp + 4]
// 004edfc0  99                   cdq 
// 004edfc1  2bc2                 sub eax, edx
// 004edfc3  8b5124               mov edx, dword ptr [ecx + 0x24]
// 004edfc6  66891424             mov word ptr [esp], dx
// 004edfca  6689542402           mov word ptr [esp + 2], dx
// 004edfcf  8b542410             mov edx, dword ptr [esp + 0x10]
// 004edfd3  52                   push edx
// 004edfd4  8b542404             mov edx, dword ptr [esp + 4]
// 004edfd8  d1f8                 sar eax, 1
// 004edfda  52                   push edx
// 004edfdb  50                   push eax
// 004edfdc  8b442410             mov eax, dword ptr [esp + 0x10]
// 004edfe0  50                   push eax
// 004edfe1  e8baf2ffff           call 0x4ed2a0
// 004edfe6  83c40c               add esp, 0xc
// 004edfe9  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX00000d_005000c0@S@ns_ROCX00000d@@QAEXH@Z)

namespace ns_ROCX00000d {
// from server: 100% by colin
struct Pair
{
    short first;
    short second;
};

struct FloatValue
{
    float value;
};

struct Data
{
    Pair pair;
    FloatValue value;
    int half;
};

struct S
{
    char padding[32];
    float value;
    volatile int count;

    void helper(FloatValue value, int half, Pair pair, int argument);
    void fn_ROCX00000d_005000c0(int argument);
};

void S::fn_ROCX00000d_005000c0(int argument)
{
    Data data;
    data.value.value = value;
    data.half = (count + 1) / 2;
    int n = count;
    data.pair.first = (short)n;
    data.pair.second = (short)n;
    helper(data.value, data.half, data.pair, argument);
}
}
