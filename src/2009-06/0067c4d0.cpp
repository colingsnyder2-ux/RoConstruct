// from server: 94% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005e4490  unit: RBX::VMotor::?$FactoryProduct  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e4490
//
// 005e4490  8b442404             mov eax, dword ptr [esp + 4]
// 005e4494  56                   push esi
// 005e4495  8bf1                 mov esi, ecx
// 005e4497  8b8e50010000         mov ecx, dword ptr [esi + 0x150]
// 005e449d  50                   push eax
// 005e449e  6a00                 push 0
// 005e44a0  e8ab120600           call 0x645750
// 005e44a5  683cab9700           push 0x97ab3c
// 005e44aa  8bce                 mov ecx, esi
// 005e44ac  e84f96e2ff           call 0x40db00
// 005e44b1  5e                   pop esi
// 005e44b2  c20400               ret 4

extern unsigned char property;

struct MotorData
{
    void set(int index, int value);
};

struct S
{
    unsigned char padding[0x150];
    MotorData* motor;

    void notify(const void* descriptor);
    void setValue(int value);
};

void S::setValue(int value)
{
    motor->set(0, value);
    notify(&property);
}
