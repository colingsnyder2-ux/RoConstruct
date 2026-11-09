// from server: 60% by king_originala
struct String {
    char storage[24];
    ~String();
};

extern bool (__cdecl *callback)(const char *, const char *, const char *,
                               int, int, int);
extern "C" void __cdecl exit(int);
extern void __cdecl flushLog();
extern bool result;

bool check()
{
    bool terminate;
    {
        String text;
        terminate = callback(text.storage, 0, 0, 0, 0, 1);
    }
    if (terminate)
        exit(-1);
    flushLog();
    return result;
}
