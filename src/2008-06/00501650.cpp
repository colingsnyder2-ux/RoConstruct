// from server: 100% by king_originala
struct String;
extern void (__thiscall *destroyString)(String *);

struct String {
    unsigned char storage[28];
    ~String() { destroyString(this); }
};

extern String __cdecl formatString(const char *, ...);
extern bool __cdecl keyExists(const String &);

int countProcessors()
{
    int count = 0;
    for (;;) {
        String key = formatString(
            "HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\%d",
            count);
        if (!keyExists(key))
            break;
        ++count;
    }
    return count;
}
