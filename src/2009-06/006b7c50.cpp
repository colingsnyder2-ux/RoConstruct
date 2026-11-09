// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00617ec0  unit: RBX::NewNullTool  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00617ec0
//
// 00617ec0  8b442404             mov eax, dword ptr [esp + 4]
// 00617ec4  53                   push ebx
// 00617ec5  56                   push esi
// 00617ec6  57                   push edi
// 00617ec7  8bf1                 mov esi, ecx
// 00617ec9  8d7e3c               lea edi, [esi + 0x3c]
// 00617ecc  57                   push edi
// 00617ecd  50                   push eax
// 00617ece  e8bde0ffff           call 0x615f90
// 00617ed3  6a00                 push 0
// 00617ed5  57                   push edi
// 00617ed6  8bce                 mov ecx, esi
// 00617ed8  8bd8                 mov ebx, eax
// 00617eda  e851d9ffff           call 0x615830
// 00617edf  51                   push ecx
// 00617ee0  d91c24               fstp dword ptr [esp]
// 00617ee3  53                   push ebx
// 00617ee4  e8371c0100           call 0x629b20
// 00617ee9  83c40c               add esp, 0xc
// 00617eec  85db                 test ebx, ebx
// 00617eee  7443                 je 0x617f33
// 00617ef0  84c0                 test al, al
// 00617ef2  7414                 je 0x617f08
// 00617ef4  68603a8400           push 0x843a60
// 00617ef9  8d4e1c               lea ecx, [esi + 0x1c]
// 00617efc  ff154c248000         call dword ptr [0x80244c]
// 00617f02  5f                   pop edi
// 00617f03  5e                   pop esi
// 00617f04  5b                   pop ebx
// 00617f05  c20400               ret 4
// 00617f08  57                   push edi
// 00617f09  8bce                 mov ecx, esi
// 00617f0b  e870d9ffff           call 0x615880
// 00617f10  84c0                 test al, al
// 00617f12  741f                 je 0x617f33
// 00617f14  8bce                 mov ecx, esi
// 00617f16  e865ffffff           call 0x617e80
// 00617f1b  84c0                 test al, al
// 00617f1d  7514                 jne 0x617f33
// 00617f1f  6850388300           push 0x833850
// 00617f24  8d4e1c               lea ecx, [esi + 0x1c]
// 00617f27  ff154c248000         call dword ptr [0x80244c]
// 00617f2d  5f                   pop edi
// 00617f2e  5e                   pop esi
// 00617f2f  5b                   pop ebx
// 00617f30  c20400               ret 4
// 00617f33  68143c8400           push 0x843c14
// 00617f38  8d4e1c               lea ecx, [esi + 0x1c]
// 00617f3b  ff154c248000         call dword ptr [0x80244c]
// 00617f41  5f                   pop edi
// 00617f42  5e                   pop esi
// 00617f43  5b                   pop ebx
// 00617f44  c20400               ret 4

struct CursorString {
    char storage[28];
};

struct Position {
    float x, y, z;
};

extern CursorString& (__thiscall *assignCursor)(CursorString*, const char*);
extern "C" bool __cdecl checkTarget(void*, float, int);

struct S {
    char padding[0x1c];
    CursorString cursor;
    char gap[4];
    Position position;

    void* findTarget(void*, Position*);
    float getDistance(Position*);
    bool checkPosition(Position*);
    bool getValue();
    void updateCursor(void*);
};

void S::updateCursor(void* argument)
{
    void* target = findTarget(argument, &position);
    bool valid = checkTarget(target, getDistance(&position), 0);

    if (target) {
        if (valid) {
            assignCursor(&cursor, reinterpret_cast<const char*>(0x843a60));
            return;
        }
        if (checkPosition(&position) && !getValue()) {
            assignCursor(&cursor, reinterpret_cast<const char*>(0x833850));
            return;
        }
    }
    assignCursor(&cursor, reinterpret_cast<const char*>(0x843c14));
}
