// roc 2012-06 00789180  unit: RBX::N$E?sDoubleConstrainedValue::V?$ConstrainedValue::?$FactoryProduct::Creator  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00789180
//
// 00789180  8b442404             mov eax, dword ptr [esp + 4]
// 00789184  83781000             cmp dword ptr [eax + 0x10], 0
// 00789188  741b                 je 0x7891a5
// 0078918a  dd442410             fld qword ptr [esp + 0x10]
// 0078918e  8d4808               lea ecx, [eax + 8]
// 00789191  8b01                 mov eax, dword ptr [ecx]
// 00789193  8b10                 mov edx, dword ptr [eax]
// 00789195  83ec10               sub esp, 0x10
// 00789198  dd5c2408             fstp qword ptr [esp + 8]
// 0078919c  dd442418             fld qword ptr [esp + 0x18]
// 007891a0  dd1c24               fstp qword ptr [esp]
// 007891a3  ffd2                 call edx
// 007891a5  c3                   ret 
// copied from an identical function in another client (function ?f@@YAXPAXNN@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S {
};

void __cdecl f(void *p, double a, double b)
{
    if (*(int *)((char *)p + 0x10) != 0)
        (*(void (__thiscall **)(void *, double, double))(*(int **)((char *)p + 8)))((char *)p + 8, a, b);
}