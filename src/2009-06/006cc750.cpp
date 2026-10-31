// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00640190  unit: RBX::GameTool  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00640190
//
// 00640190  8b442404             mov eax, dword ptr [esp + 4]
// 00640194  83ec0c               sub esp, 0xc
// 00640197  6683781000           cmp word ptr [eax + 0x10], 0
// 0064019c  56                   push esi
// 0064019d  8bf1                 mov esi, ecx
// 0064019f  746f                 je 0x640210
// 006401a1  6683781200           cmp word ptr [eax + 0x12], 0
// 006401a6  7468                 je 0x640210
// 006401a8  d9ee                 fldz 
// 006401aa  8d4c2404             lea ecx, [esp + 4]
// 006401ae  51                   push ecx
// 006401af  d9542408             fst dword ptr [esp + 8]
// 006401b3  d954240c             fst dword ptr [esp + 0xc]
// 006401b7  50                   push eax
// 006401b8  8bce                 mov ecx, esi
// 006401ba  d95c2414             fstp dword ptr [esp + 0x14]
// 006401be  e83d5efdff           call 0x616000
// 006401c3  85c0                 test eax, eax
// 006401c5  7515                 jne 0x6401dc
// 006401c7  68143c8400           push 0x843c14
// 006401cc  8d4e1c               lea ecx, [esi + 0x1c]
// 006401cf  ff154c248000         call dword ptr [0x80244c]
// 006401d5  5e                   pop esi
// 006401d6  83c40c               add esp, 0xc
// 006401d9  c20400               ret 4
// 006401dc  8d542404             lea edx, [esp + 4]
// 006401e0  52                   push edx
// 006401e1  50                   push eax
// 006401e2  8bce                 mov ecx, esi
// 006401e4  e867ffffff           call 0x640150
// 006401e9  84c0                 test al, al
// 006401eb  7515                 jne 0x640202
// 006401ed  6850388300           push 0x833850
// 006401f2  8d4e1c               lea ecx, [esi + 0x1c]
// 006401f5  ff154c248000         call dword ptr [0x80244c]
// 006401fb  5e                   pop esi
// 006401fc  83c40c               add esp, 0xc
// 006401ff  c20400               ret 4
// 00640202  68603a8400           push 0x843a60
// 00640207  8d4e1c               lea ecx, [esi + 0x1c]
// 0064020a  ff154c248000         call dword ptr [0x80244c]
// 00640210  5e                   pop esi
// 00640211  83c40c               add esp, 0xc
// 00640214  c20400               ret 4

struct Input {
    char padding[16];
    short x;
    short y;
};

struct Vector3 {
    float x, y, z;
};

struct Object;
struct String {
    char storage[28];
};

extern String& (__thiscall *assignString)(String*, const char*);

struct GameTool {
    char padding[28];
    String cursor;

    Object* pick(Input*, Vector3*);
    bool canDrag(Object*, Vector3*);
    void updateCursor(Input*);
};

void GameTool::updateCursor(Input* input)
{
    if (input->x != 0 && input->y != 0) {
        Vector3 position = { 0.0f, 0.0f, 0.0f };
        Object* object = pick(input, &position);
        if (!object) {
            assignString(&cursor, "ArrowFarCursor");
            return;
        }
        if (!canDrag(object, &position)) {
            assignString(&cursor, "ArrowCursor");
            return;
        }
        assignString(&cursor, "DragCursor");
    }
}
