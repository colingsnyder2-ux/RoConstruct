// roc 2012-06 005c8050  unit: RakNet::RakPeer  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c8050
//
// 005c8050  56                   push esi
// 005c8051  8bf1                 mov esi, ecx
// 005c8053  e8c8fdffff           call 0x5c7e20
// 005c8058  8bce                 mov ecx, esi
// 005c805a  5e                   pop esi
// 005c805b  e9c0fdffff           jmp 0x5c7e20
// auto-matched from its assembly shape

struct S_func_005c8050 { void f(); void a(); void b(); };
void S_func_005c8050::f()
{
    a();
    b();
}
