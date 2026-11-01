// from server: 100% by king_originala
struct Text;

extern "C" __int64 __cdecl _time64(__int64 *);
extern "C" int __cdecl fprintf(void *, const char *, ...);

extern __int64 (__cdecl *timeCall)(__int64 *);
extern int (__cdecl *printCall)(void *, const char *, ...);
extern void (__thiscall *constructText)(Text *, const char *);
extern void (__thiscall *destroyText)(Text *);

struct Text {
    unsigned int allocator;
    union {
        char buffer[16];
        char *pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;

    Text(const char *);
    ~Text();
};

inline Text::Text(const char *value) {
    constructText(this, value);
}

inline Text::~Text() {
    destroyText(this);
}

struct S {
    unsigned int reserved;
    void *file;

    void f();
};

void S::f() {
    __int64 value;
    if (timeCall(&value) == -1) {
        Text message("[Error getting time]");
        if (file) {
            f();
            const char *text = message.storage.pointer;
            if (message.capacity < 16)
                text = message.storage.buffer;
            printCall(file, "%s\n", text);
        }
    }
}
