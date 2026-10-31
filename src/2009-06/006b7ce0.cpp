// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00617f50  unit: RBX::NewNullTool  size: 147 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00617f50
//
// 00617f50  8b442404             mov eax, dword ptr [esp + 4]
// 00617f54  55                   push ebp
// 00617f55  56                   push esi
// 00617f56  57                   push edi
// 00617f57  8bf1                 mov esi, ecx
// 00617f59  8d7e3c               lea edi, [esi + 0x3c]
// 00617f5c  57                   push edi
// 00617f5d  50                   push eax
// 00617f5e  e82de0ffff           call 0x615f90
// 00617f63  6a00                 push 0
// 00617f65  57                   push edi
// 00617f66  8bce                 mov ecx, esi
// 00617f68  8be8                 mov ebp, eax
// 00617f6a  e8c1d8ffff           call 0x615830
// 00617f6f  51                   push ecx
// 00617f70  d91c24               fstp dword ptr [esp]
// 00617f73  55                   push ebp
// 00617f74  e8a71b0100           call 0x629b20
// 00617f79  83c40c               add esp, 0xc
// 00617f7c  85ed                 test ebp, ebp
// 00617f7e  744b                 je 0x617fcb
// 00617f80  84c0                 test al, al
// 00617f82  7418                 je 0x617f9c
// 00617f84  68603a8400           push 0x843a60
// 00617f89  8d4e1c               lea ecx, [esi + 0x1c]
// 00617f8c  ff154c248000         call dword ptr [0x80244c]
// 00617f92  5f                   pop edi
// 00617f93  c6463800             mov byte ptr [esi + 0x38], 0
// 00617f97  5e                   pop esi
// 00617f98  5d                   pop ebp
// 00617f99  c20400               ret 4
// 00617f9c  57                   push edi
// 00617f9d  8bce                 mov ecx, esi
// 00617f9f  e8dcd8ffff           call 0x615880
// 00617fa4  84c0                 test al, al
// 00617fa6  7423                 je 0x617fcb
// 00617fa8  8bce                 mov ecx, esi
// 00617faa  e8d1feffff           call 0x617e80
// 00617faf  84c0                 test al, al
// 00617fb1  7518                 jne 0x617fcb
// 00617fb3  6850388300           push 0x833850
// 00617fb8  8d4e1c               lea ecx, [esi + 0x1c]
// 00617fbb  ff154c248000         call dword ptr [0x80244c]
// 00617fc1  5f                   pop edi
// 00617fc2  c6463801             mov byte ptr [esi + 0x38], 1
// 00617fc6  5e                   pop esi
// 00617fc7  5d                   pop ebp
// 00617fc8  c20400               ret 4
// 00617fcb  68143c8400           push 0x843c14
// 00617fd0  8d4e1c               lea ecx, [esi + 0x1c]
// 00617fd3  ff154c248000         call dword ptr [0x80244c]
// 00617fd9  5f                   pop edi
// 00617fda  c6463800             mov byte ptr [esi + 0x38], 0
// 00617fde  5e                   pop esi
// 00617fdf  5d                   pop ebp
// 00617fe0  c20400               ret 4

struct CursorString {
    char storage[0x1c];
};

typedef CursorString& (__thiscall *AssignCursor)(CursorString*, const char*);
extern AssignCursor assignCursor;

extern "C" bool __cdecl testTarget(void*, float, int);

struct S {
    char padding[0x1c];
    CursorString cursor;
    bool active;
    char padding39[3];
    float position[3];

    void* findTarget(void*, float*);
    float distance(float*);
    bool canDrag(float*);
    bool blocked();
    void update(void*);
};

void S::update(void* event)
{
    void* target = findTarget(event, position);
    bool nearTarget = testTarget(target, distance(position), 0);

    if (target) {
        if (nearTarget) {
            assignCursor(&cursor, reinterpret_cast<const char*>(0x843a60));
            active = false;
            return;
        }

        if (canDrag(position) && !blocked()) {
            assignCursor(&cursor, reinterpret_cast<const char*>(0x833850));
            active = true;
            return;
        }
    }

    assignCursor(&cursor, reinterpret_cast<const char*>(0x843c14));
    active = false;
}
