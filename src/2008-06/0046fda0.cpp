// from server: 53% by king_originala
struct String {
    char storage[24];
    String();
    ~String();
};

extern String existingString;
extern char (__cdecl *callback)(int, int, int, int, int, const String&);
extern void (__stdcall *exitProc)(int);
extern void __cdecl flushLog();
extern bool resultFlag;

bool __cdecl function()
{
    bool failed = callback(0, 0, 0, 0, 0,
                          resultFlag ? existingString : String()) != 0;
    if (failed)
        exitProc(-1);
    flushLog();
    return resultFlag;
}
