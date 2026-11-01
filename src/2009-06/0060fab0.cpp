// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00582770  unit: RBX::StopCommand  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00582770
//
// 00582770  6a01                 push 1
// 00582772  83c110               add ecx, 0x10
// 00582775  e886f4ffff           call 0x581c00
// 0058277a  33c9                 xor ecx, ecx
// 0058277c  83b8b401000001       cmp dword ptr [eax + 0x1b4], 1
// 00582783  0f94c1               sete cl
// 00582786  8ac1                 mov al, cl
// 00582788  c3                   ret 

struct State {
    char padding[0x9C];
    int value;
};

struct Resolver {
    State* get(int);
};

struct S {
    char padding[0x10];
    Resolver resolver;
    bool f();
};

bool S::f()
{
    return resolver.get(1)->value == 1;
}
