// roc 2012-06 004c1fe0  unit: RBX::MeshGen  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004c1fe0
//
// 004c1fe0  8b442404             mov eax, dword ptr [esp + 4]
// 004c1fe4  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_004c1fe0 {

    int f(int a1);
};
int S_func_004c1fe0::f(int a1)
{
    return a1;
}
