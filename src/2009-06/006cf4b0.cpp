// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 006439b0  unit: RBX::HUMAN::Landed  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006439b0
//
// 006439b0  8b4908               mov ecx, dword ptr [ecx + 8]
// 006439b3  83ec24               sub esp, 0x24
// 006439b6  56                   push esi
// 006439b7  e8a457f9ff           call 0x5d9160
// 006439bc  8bf0                 mov esi, eax
// 006439be  85f6                 test esi, esi
// 006439c0  7464                 je 0x643a26
// 006439c2  b801000000           mov eax, 1
// 006439c7  8405a4289700         test byte ptr [0x9728a4], al
// 006439cd  751c                 jne 0x6439eb
// 006439cf  d9ee                 fldz 
// 006439d1  0905a4289700         or dword ptr [0x9728a4], eax
// 006439d7  d91598289700         fst dword ptr [0x972898]
// 006439dd  d9e8                 fld1 
// 006439df  d91d9c289700         fstp dword ptr [0x97289c]
// 006439e5  d91da0289700         fstp dword ptr [0x9728a0]
// 006439eb  8bce                 mov ecx, esi
// 006439ed  e86e59f5ff           call 0x599360
// 006439f2  8d442404             lea eax, [esp + 4]
// 006439f6  50                   push eax
// 006439f7  8d8e94000000         lea ecx, [esi + 0x94]
// 006439fd  e80efbecff           call 0x513510
// 00643a02  d94014               fld dword ptr [eax + 0x14]
// 00643a05  d80da0289700         fmul dword ptr [0x9728a0]
// 00643a0b  5e                   pop esi
// 00643a0c  d94010               fld dword ptr [eax + 0x10]
// 00643a0f  d80d9c289700         fmul dword ptr [0x97289c]
// 00643a15  dec1                 faddp st(1)
// 00643a17  d9400c               fld dword ptr [eax + 0xc]
// 00643a1a  d80d98289700         fmul dword ptr [0x972898]
// 00643a20  dec1                 faddp st(1)
// 00643a22  83c424               add esp, 0x24
// 00643a25  c3                   ret 
// 00643a26  d9e8                 fld1 
// 00643a28  5e                   pop esi
// 00643a29  83c424               add esp, 0x24
// 00643a2c  c3                   ret 

struct Vector
{
    float x, y, z;
    Vector(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct Matrix
{
    float values[9];
};

struct Camera
{
    Matrix* rotation(Matrix* result) const;
};

struct Body
{
    char padding[0x94];
    Camera camera;

    const void* get();
};

struct Owner
{
    int f();
};

struct S
{
    char padding[8];
    Owner* owner;

    double f();
};

double S::f()
{
    Body* body = (Body*)owner->f();
    if (body)
    {
        static Vector up(0.0f, 1.0f, 0.0f);

        body->get();
        Matrix storage;
        Matrix* rotation = body->camera.rotation(&storage);
        return rotation->values[4] * up.y
             + rotation->values[5] * up.z
             + rotation->values[3] * up.x;
    }
    return 1.0;
}
