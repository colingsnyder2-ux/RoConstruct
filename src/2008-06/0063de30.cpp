// from server: 100% by king_originala
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
