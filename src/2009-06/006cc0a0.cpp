// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0063fae0  unit: RBX::GrabTool  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063fae0
//
// 0063fae0  8b442404             mov eax, dword ptr [esp + 4]
// 0063fae4  56                   push esi
// 0063fae5  68e0be9700           push 0x97bee0
// 0063faea  50                   push eax
// 0063faeb  8bf1                 mov esi, ecx
// 0063faed  e80e65fdff           call 0x616000
// 0063faf2  85c0                 test eax, eax
// 0063faf4  7512                 jne 0x63fb08
// 0063faf6  68143c8400           push 0x843c14
// 0063fafb  8d4e1c               lea ecx, [esi + 0x1c]
// 0063fafe  ff154c248000         call dword ptr [0x80244c]
// 0063fb04  5e                   pop esi
// 0063fb05  c20400               ret 4
// 0063fb08  80b8f001000000       cmp byte ptr [eax + 0x1f0], 0
// 0063fb0f  7412                 je 0x63fb23
// 0063fb11  6850388300           push 0x833850
// 0063fb16  8d4e1c               lea ecx, [esi + 0x1c]
// 0063fb19  ff154c248000         call dword ptr [0x80244c]
// 0063fb1f  5e                   pop esi
// 0063fb20  c20400               ret 4
// 0063fb23  68603a8400           push 0x843a60
// 0063fb28  8d4e1c               lea ecx, [esi + 0x1c]
// 0063fb2b  ff154c248000         call dword ptr [0x80244c]
// 0063fb31  5e                   pop esi
// 0063fb32  c20400               ret 4

struct CursorString;

extern CursorString& (__thiscall *assignCursor)(
    CursorString*, const char*);

extern const char cursorUnavailable[];
extern const char cursorBlocked[];
extern const char cursorDraggable[];
extern const char typeDescriptor[];

struct Part {
    char padding[0x130];
    unsigned char blocked;
};

extern Part* __stdcall findPart(void*, const void*);

struct CursorString {
    char storage[28];
};

struct GrabTool {
    char padding[0x1c];
    CursorString cursor;
    void updateCursor(void*);
};

void GrabTool::updateCursor(void* object)
{
    Part* part = findPart(object, typeDescriptor);
    if (!part) {
        assignCursor(&cursor, cursorUnavailable);
        return;
    }
    if (part->blocked) {
        assignCursor(&cursor, cursorBlocked);
        return;
    }
    assignCursor(&cursor, cursorDraggable);
}
