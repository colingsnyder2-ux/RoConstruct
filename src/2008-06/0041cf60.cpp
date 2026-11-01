// from server: 100% by king_originala
struct String {
    char storage[28];
    ~String();
};

struct Argument {
    char prefix[8];
    String text;
    char suffix[24];
};

extern bool __cdecl func_0060a2f0();
extern void* __cdecl allocate(unsigned int);
extern void __cdecl initialize(void*, Argument*);
extern char tag[];

struct Creator {
    void* kind;
    unsigned int reserved;
    void* object;

    Creator(Argument);
};

Creator::Creator(Argument argument)
{
    kind = 0;
    if (!reinterpret_cast<bool (__cdecl *)(Argument*)>(
            func_0060a2f0)(&argument)) {
        void* p = allocate(0x38);
        initialize(p, &argument);
        object = p;
        kind = tag;
    } else {
        kind = 0;
    }
}
