// roc 2012-06 00759e90  unit: RBX::VPartInstance::?$EventDesc  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00759e90
//
// 00759e90  8b442404             mov eax, dword ptr [esp + 4]
// 00759e94  d900                 fld dword ptr [eax]
// 00759e96  83ec08               sub esp, 8
// 00759e99  dd1424               fst qword ptr [esp]
// 00759e9c  6820b6b900           push 0xb9b620
// 00759ea1  83ec08               sub esp, 8
// 00759ea4  dd1c24               fstp qword ptr [esp]
// 00759ea7  51                   push ecx
// 00759ea8  e833ffffff           call 0x759de0
// 00759ead  83c418               add esp, 0x18
// 00759eb0  c20400               ret 4
// copied from an identical function in another client (function ?f@S@@QAEXPAM@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void G1_func_0065bbd0(void *, double, const char *, double);

struct S
{
    void f(float *);
};

void S::f(float *p)
{
    double d = *p;
    G1_func_0065bbd0(this, d, "%.3g", d);
}