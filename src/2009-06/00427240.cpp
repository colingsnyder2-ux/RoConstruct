// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0042e4c0  unit: MyXTPCommandBars  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042e4c0
//
// 0042e4c0  56                   push esi
// 0042e4c1  6a00                 push 0
// 0042e4c3  8bf1                 mov esi, ecx
// 0042e4c5  689c088100           push 0x81089c
// 0042e4ca  56                   push esi
// 0042e4cb  8d8e0c010000         lea ecx, [esi + 0x10c]
// 0042e4d1  e87a682b00           call 0x6e4d50
// 0042e4d6  8b442408             mov eax, dword ptr [esp + 8]
// 0042e4da  85c0                 test eax, eax
// 0042e4dc  7406                 je 0x42e4e4
// 0042e4de  8b8614010000         mov eax, dword ptr [esi + 0x114]
// 0042e4e4  50                   push eax
// 0042e4e5  8bce                 mov ecx, esi
// 0042e4e7  e882242700           call 0x6a096e
// 0042e4ec  f7d8                 neg eax
// 0042e4ee  1bc0                 sbb eax, eax
// 0042e4f0  f7d8                 neg eax
// 0042e4f2  5e                   pop esi
// 0042e4f3  c20400               ret 4

struct S;

struct Helper
{
    unsigned char padding[8];
    void initialize(S* owner, const void* type, int flag);
};

struct S
{
    unsigned char padding[0x110];
    Helper helper;
    int value;

    int create(int value);
    int f(int enabled);
};

int S::f(int enabled)
{
    helper.initialize(this, "CMainFrameV2", 0);
    int argument = enabled;
    if (argument)
        argument = value;
    return create(argument) != 0;
}
