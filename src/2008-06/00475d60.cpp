// from server: 100% by king_originala
extern unsigned long totalSize;
extern int allocationMode;
extern bool ignoreAssertion;

void __cdecl lockLog();
void __cdecl unlockLog();

extern long (__stdcall *decrementReference)(long *);
extern void (__cdecl *releaseMemory)(void *);
extern void (__stdcall *terminateProcess)(int);
extern void (__stdcall *deleteTextures)(int, unsigned long *);

struct Image {
    virtual ~Image();
    long references;
    void release();
};

struct ImageRef {
    Image *p;
    ~ImageRef();
};

inline ImageRef::~ImageRef() {
    if (p) {
        if (decrementReference(&p->references) == 0) {
            p->release();
            if (p)
                delete p;
        }
        p = 0;
    }
}

struct String {
    unsigned char data[28];
    String(const char *);
    ~String();
};

extern void (__thiscall *constructString)(String *, const char *);
extern void (__thiscall *destroyString)(String *);

inline String::String(const char *s) {
    constructString(this, s);
}

inline String::~String() {
    destroyString(this);
}

extern bool (__cdecl *assertionHandler)(
    const char *, const String &, const char *, int, bool *, bool);

struct Base {
    virtual ~Base();
};

inline Base::~Base() {
}

struct S : Base {
    unsigned long padding0[2];
    ImageRef image;
    unsigned long padding1[6];
    unsigned long size;
    unsigned long texture;
    void *memory;
    virtual ~S();
};

S::~S() {
    totalSize -= size;

    if (size) {
        switch (allocationMode) {
        case 1:
            deleteTextures(1, &texture);
            texture = 0;
            break;

        case 2:
            releaseMemory(memory);
            memory = 0;
            break;

        default:
            if (!ignoreAssertion) {
                lockLog();
                if (assertionHandler &&
                    assertionHandler(
                        (const char *)0x81e21c,
                        String((const char *)0x81e420),
                        (const char *)0x81e408,
                        136,
                        &ignoreAssertion,
                        true))
                    terminateProcess(-1);
                unlockLog();
            }
            break;
        }
        size = 0;
    }
}
