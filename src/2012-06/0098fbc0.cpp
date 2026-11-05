// roc 2012-06 0098fbc0  unit: CPatchedControlComboBox  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0098fbc0
//
// 0098fbc0  56                   push esi
// 0098fbc1  8bf1                 mov esi, ecx
// 0098fbc3  e888ffffff           call 0x98fb50
// 0098fbc8  8bce                 mov ecx, esi
// 0098fbca  5e                   pop esi
// 0098fbcb  e9704bffff           jmp 0x984740
// auto-matched from its assembly shape

struct S_func_0098fbc0 { void f(); void a(); void b(); };
void S_func_0098fbc0::f()
{
    a();
    b();
}
