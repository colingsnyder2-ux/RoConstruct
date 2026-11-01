// from server: 100% by king_originala
struct Text {
    unsigned int allocator;
    union {
        char buffer[16];
        char *pointer;
    };
    unsigned int length;
    unsigned int capacity;
};

extern int (__cdecl *printCall)(void *, const char *, ...);
extern const char format[];

struct S {
    unsigned int reserved;
    void *stream;

    void prepare();
    void write(const Text &text);
};

void S::write(const Text &text)
{
    if (stream) {
        prepare();
        const char *p;
        if (text.capacity >= 16)
            p = text.pointer;
        else
            p = text.buffer;
        printCall(stream, format, p);
    }
}
