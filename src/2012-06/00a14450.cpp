// roc 2012-06 00a14450  unit: CXTPControlEdit  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a14450
//
// 00a14450  56                   push esi
// 00a14451  8bf1                 mov esi, ecx
// 00a14453  e888ffffff           call 0xa143e0
// 00a14458  8bce                 mov ecx, esi
// 00a1445a  5e                   pop esi
// 00a1445b  e9e002f7ff           jmp 0x984740
// auto-matched from its assembly shape

struct S_func_00a14450 { void f(); void a(); void b(); };
void S_func_00a14450::f()
{
    a();
    b();
}
