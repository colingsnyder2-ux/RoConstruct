// from server: 94% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005e44c0  unit: RBX::VMotor::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e44c0
//
// 005e44c0  8b442404             mov eax, dword ptr [esp + 4]
// 005e44c4  56                   push esi
// 005e44c5  8bf1                 mov esi, ecx
// 005e44c7  8b8e50010000         mov ecx, dword ptr [esi + 0x150]
// 005e44cd  50                   push eax
// 005e44ce  6a01                 push 1
// 005e44d0  e87b120600           call 0x645750
// 005e44d5  6890ab9700           push 0x97ab90
// 005e44da  8bce                 mov ecx, esi
// 005e44dc  e81f96e2ff           call 0x40db00
// 005e44e1  5e                   pop esi
// 005e44e2  c20400               ret 4

extern char event;

struct Target {
    void set(int mode, int value);
};

struct S {
    char padding[0x150];
    Target* target;

    void notify(const void* descriptor);
    void f(int value);
};

void S::f(int value)
{
    target->set(1, value);
    notify(&event);
}
