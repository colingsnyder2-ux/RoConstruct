// from server: 100% by king_originala
struct StreamBuffer;

extern int (__thiscall *pubsync)(StreamBuffer*);

struct S {
    char reserved[0x8c];
    StreamBuffer* buffer;

    void flush();
    int sync();
};

int S::sync()
{
    try {
        flush();
        if (buffer)
            pubsync(buffer);
        return 0;
    }
    catch (...) {
        return -1;
    }
}
