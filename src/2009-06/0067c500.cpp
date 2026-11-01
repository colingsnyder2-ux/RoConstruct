// from server: 100% by EspClaude
// from server: 94% by EspClaude
// roc 2009-06 0067c500  unit: RBX::JointInstance  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0067c500
//
// 0067c500  8b442404             mov eax, dword ptr [esp + 4]
// 0067c504  56                   push esi
// 0067c505  8bf1                 mov esi, ecx
// 0067c507  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0067c50d  50                   push eax
// 0067c50e  6a01                 push 1
// 0067c510  e8bb9f0200           call 0x6a64d0
// 0067c515  6830e5a400           push 0xa4e530
// 0067c51a  8bce                 mov ecx, esi
// 0067c51c  e8affdd8ff           call 0x40c2d0
// 0067c521  5e                   pop esi
// 0067c522  c20400               ret 4

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
    char padding[0xac];
    Target* target;

    void notify(const void* descriptor);
    void f(int value);
};

void S::f(int value)
{
    target->set(1, value);
    notify(&event);
}
