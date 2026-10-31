// from server: 88% by EspClaude
// from server: 100% by colin
// roc 2008-06 0064ddf0  unit: RBX::Point  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064ddf0
//
// 0064ddf0  6aff                 push -1
// 0064ddf2  6828ae7d00           push 0x7dae28
// 0064ddf7  64a100000000         mov eax, dword ptr fs:[0]
// 0064ddfd  50                   push eax
// 0064ddfe  64892500000000       mov dword ptr fs:[0], esp
// 0064de05  83ec28               sub esp, 0x28
// 0064de08  d9ee                 fldz 
// 0064de0a  56                   push esi
// 0064de0b  8bf1                 mov esi, ecx
// 0064de0d  d9542404             fst dword ptr [esp + 4]
// 0064de11  8b4624               mov eax, dword ptr [esi + 0x24]
// 0064de14  d9542408             fst dword ptr [esp + 8]
// 0064de18  57                   push edi
// 0064de19  d95c2410             fstp dword ptr [esp + 0x10]
// 0064de1d  50                   push eax
// 0064de1e  e88dbdf8ff           call 0x5d9bb0
// 0064de23  8bf8                 mov edi, eax
// 0064de25  83c404               add esp, 4
// 0064de28  85ff                 test edi, edi
// 0064de2a  0f8496000000         je 0x64dec6
// 0064de30  53                   push ebx
// 0064de31  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 0064de35  8d44240c             lea eax, [esp + 0xc]
// 0064de39  50                   push eax
// 0064de3a  53                   push ebx
// 0064de3b  8bce                 mov ecx, esi
// 0064de3d  e84e81fcff           call 0x615f90
// 0064de42  85c0                 test eax, eax
// 0064de44  7573                 jne 0x64deb9
// 0064de46  53                   push ebx
// 0064de47  8d4c241c             lea ecx, [esp + 0x1c]
// 0064de4b  51                   push ecx
// 0064de4c  8bce                 mov ecx, esi
// 0064de4e  e8ed7efcff           call 0x615d40
// 0064de53  8bcf                 mov ecx, edi
// 0064de55  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 0064de5d  e8aeabf8ff           call 0x5d8a10
// 0064de62  85c0                 test eax, eax
// 0064de64  7413                 je 0x64de79
// 0064de66  8bcf                 mov ecx, edi
// 0064de68  e8a3abf8ff           call 0x5d8a10
// 0064de6d  8bc8                 mov ecx, eax
// 0064de6f  e83caef4ff           call 0x598cb0
// 0064de74  83c024               add eax, 0x24
// 0064de77  eb04                 jmp 0x64de7d
// 0064de79  8d44241c             lea eax, [esp + 0x1c]
// 0064de7d  d900                 fld dword ptr [eax]
// 0064de7f  c744243cffffffff     mov dword ptr [esp + 0x3c], 0xffffffff
// 0064de87  d954240c             fst dword ptr [esp + 0xc]
// 0064de8b  d94004               fld dword ptr [eax + 4]
// 0064de8e  d9542410             fst dword ptr [esp + 0x10]
// 0064de92  d94008               fld dword ptr [eax + 8]
// 0064de95  c7442418c4828200     mov dword ptr [esp + 0x18], 0x8282c4
// 0064de9d  d9442428             fld dword ptr [esp + 0x28]
// 0064dea1  dec3                 faddp st(3)
// 0064dea3  d9ca                 fxch st(2)
// 0064dea5  d95c240c             fstp dword ptr [esp + 0xc]
// 0064dea9  d844242c             fadd dword ptr [esp + 0x2c]
// 0064dead  d95c2410             fstp dword ptr [esp + 0x10]
// 0064deb1  d8442430             fadd dword ptr [esp + 0x30]
// 0064deb5  d95c2414             fstp dword ptr [esp + 0x14]
// 0064deb9  8d54240c             lea edx, [esp + 0xc]
// 0064debd  52                   push edx
// 0064debe  8bcf                 mov ecx, edi
// 0064dec0  e82be4f8ff           call 0x5dc2f0
// 0064dec5  5b                   pop ebx
// 0064dec6  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0064deca  5f                   pop edi
// 0064decb  5e                   pop esi
// 0064decc  64890d00000000       mov dword ptr fs:[0], ecx
// 0064ded3  83c434               add esp, 0x34
// 0064ded6  c20400               ret 4

// from server: 97% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Vector3
{
    float x, y, z;
    Vector3& operator=(const Vector3&);
};

inline Vector3& Vector3::operator=(const Vector3& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

struct Frame
{
    virtual ~Frame();
    Vector3 origin;
    Vector3 offset;
};

inline Frame::~Frame()
{
}

struct Root
{
    char padding[0x24];
    Vector3 position;
};

struct Part
{
    Root* getRoot();
};

struct Humanoid
{
    Part* getPart();
    void setPosition(const Vector3&);
};

struct Player;
extern Humanoid* __cdecl findHumanoid(const Player*);

struct Point
{
    char padding[0x24];
    const Player* player;

    int resolve(int, Vector3&);
    Frame getFrame(int);
    void update(int);
};

void Point::update(int value)
{
    Vector3 position = { 0.0f, 0.0f, 0.0f };
    const Player* playerCopy = player;
    Humanoid* humanoid = findHumanoid(playerCopy);

    if (humanoid)
    {
        if (!resolve(value, position))
        {
            Frame frame = getFrame(value);
            const Vector3& origin = humanoid->getPart()
                ? humanoid->getPart()->getRoot()->position
                : frame.origin;

            position = origin;
            position.x += frame.offset.x;
            position.y += frame.offset.y;
            position.z += frame.offset.z;
        }

        humanoid->setPosition(position);
    }
}
