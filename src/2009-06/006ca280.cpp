// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0063de30  unit: RBX::LockTool  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063de30
//
// 0063de30  51                   push ecx
// 0063de31  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 0063de34  56                   push esi
// 0063de35  c744240400000000     mov dword ptr [esp + 4], 0
// 0063de3d  85c0                 test eax, eax
// 0063de3f  7425                 je 0x63de66
// 0063de41  50                   push eax
// 0063de42  e8f9c1f5ff           call 0x59a040
// 0063de47  8b742410             mov esi, dword ptr [esp + 0x10]
// 0063de4b  83c404               add esp, 4
// 0063de4e  8bce                 mov ecx, esi
// 0063de50  84c0                 test al, al
// 0063de52  7418                 je 0x63de6c
// 0063de54  68b4a28400           push 0x84a2b4
// 0063de59  ff1558248000         call dword ptr [0x802458]
// 0063de5f  8bc6                 mov eax, esi
// 0063de61  5e                   pop esi
// 0063de62  59                   pop ecx
// 0063de63  c20400               ret 4
// 0063de66  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0063de6a  8bce                 mov ecx, esi
// 0063de6c  68a8a28400           push 0x84a2a8
// 0063de71  ff1558248000         call dword ptr [0x802458]
// 0063de77  8bc6                 mov eax, esi
// 0063de79  5e                   pop esi
// 0063de7a  59                   pop ecx
// 0063de7b  c20400               ret 4

struct String {
    unsigned char data[28];
};

extern "C" bool __cdecl isLocked(void *);
extern void (__thiscall *constructString)(String *, const char *);
extern const char unlockCursor[];
extern const char lockCursor[];

struct LockTool {
    unsigned char padding[28];
    void *object;

    String *cursorName(String *result);
};

String *LockTool::cursorName(String *result)
{
    volatile int state = 0;

    if (object) {
        bool locked = isLocked(object);
        String *out = result;

        if (locked) {
            constructString(out, unlockCursor);
            return out;
        }

        constructString(out, lockCursor);
        return out;
    }

    constructString(result, lockCursor);
    return result;
}
