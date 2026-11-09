// from server: 100% by nuck16
// roc 2009-12 00477920  unit: RBX::Reflection::VValue::V?$vector::?$sp_counted_impl_p  size: 103 bytes
//
// 00477920  64a100000000         mov eax, dword ptr fs:[0]
// 00477926  6aff                 push -1
// 00477928  686ee09200           push 0x92e06e
// 0047792d  50                   push eax
// 0047792e  b801000000           mov eax, 1
// 00477933  64892500000000       mov dword ptr fs:[0], esp
// 0047793a  840518cbb700         test byte ptr [0xb7cb18], al
// 00477940  7532                 jne 0x477974
// 00477942  090518cbb700         or dword ptr [0xb7cb18], eax
// 00477948  6a00                 push 0
// 0047794a  68fc24b400           push 0xb424fc
// 0047794f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00477957  e8542af9ff           call 0x40a3b0
// 0047795c  50                   push eax
// 0047795d  b920cab700           mov ecx, 0xb7ca20
// 00477962  e899c61e00           call 0x664000
// 00477967  6840ed9700           push 0x97ed40
// 0047796c  e8b8cf3700           call 0x7f4929
// 00477971  83c404               add esp, 4
// 00477974  8b0c24               mov ecx, dword ptr [esp]
// 00477977  b820cab700           mov eax, 0xb7ca20
// 0047797c  64890d00000000       mov dword ptr fs:[0], ecx
// 00477983  83c40c               add esp, 0xc
// 00477986  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b424fc[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b424fc, 0);
    return object;
}
