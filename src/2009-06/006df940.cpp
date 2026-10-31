// from server: 93% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0064dc70  unit: RBX::Point  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064dc70
//
// 0064dc70  8bc1                 mov eax, ecx
// 0064dc72  8b480c               mov ecx, dword ptr [eax + 0xc]
// 0064dc75  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0064dc78  8b4a2c               mov ecx, dword ptr [edx + 0x2c]
// 0064dc7b  85c9                 test ecx, ecx
// 0064dc7d  740d                 je 0x64dc8c
// 0064dc7f  8d501c               lea edx, [eax + 0x1c]
// 0064dc82  52                   push edx
// 0064dc83  83c028               add eax, 0x28
// 0064dc86  50                   push eax
// 0064dc87  e82453fcff           call 0x612fb0
// 0064dc8c  c3                   ret 

struct Vector3 {
    float x, y, z;
};

struct Receiver {
    void update(const Vector3*, const Vector3*);
};

struct Owner {
    char padding[0x2C];
    Receiver* receiver;
};

struct Link {
    char padding[0x10];
    Owner* owner;
};

struct Point {
    char padding0[0x0C];
    Link* link;
    char padding1[0x0C];
    Vector3 first;
    Vector3 second;

    void update();
};

void Point::update()
{
    Receiver* receiver = link->owner->receiver;
    if (receiver)
        receiver->update(&second, &first);
}
