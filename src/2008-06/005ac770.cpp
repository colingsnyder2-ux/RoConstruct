// from server: 49% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Control {
    virtual void reserved() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* control;
    ~Shared();
};

inline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedExchangeAdd(&p->strong, -1) == 0) {
        p->dispose();
        if (_InterlockedExchangeAdd(&p->weak, -1) == 0)
            p->destroy();
    }
}

struct Frame {
    int position;
    char reserved[40];
    int line;
    char remaining[80];
};

extern Shared __cdecl acquire();
extern void __cdecl report(void*, int, const char*, ...);
extern const char* __cdecl getText(void*, int, unsigned int*);

void __cdecl trace(void* state, int category, int index,
                   int count, bool more, const char* text, int line)
{
    volatile bool pending = more;
    volatile Frame frame;
    char buffer[64];
    frame.position = count;
    frame.line = line;

    if (index >= 0) {
        do {
            int n = 0;
            while (n < 63 && text[n]) {
                buffer[n] = text[n];
                ++n;
            }
            buffer[n] = 0;
            if (!n)
                break;
            ++frame.position;
            report(acquire().object, category,
                   "%s, line %d", buffer, frame.line);
        } while (frame.position < 12);

        if (pending && frame.position < 12)
            report(acquire().object, category, "   stack end");
    } else {
        report(acquire().object, 3, "HRESULT = %d: %s",
               getText(state, -1, 0));
    }
}
