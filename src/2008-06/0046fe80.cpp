// from server: 59% by king_originala
struct String {
    unsigned char storage[28];
    ~String();
};

extern bool (__cdecl *operation)(int, int, int, int, const String *, int);
extern "C" void __cdecl exit(int);
extern void __cdecl finishLog();
extern bool resultFlag;

bool run()
{
    bool stop;
    {
        String text;
        stop = operation(0, 0, 0, 0, &text, 1) ? true : false;
    }

    if (stop)
        exit(-1);

    finishLog();
    return resultFlag;
}
