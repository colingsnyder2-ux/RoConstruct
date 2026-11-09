// from server: 100% by colin
// from server: 88% by king_originala
struct Buffer {
    char unused;
};

extern int (__thiscall *pubsync)(Buffer *);

struct Stream {
    int padding;
    Buffer buffer;
};

struct S {
    Stream *volatile *stream;
    volatile unsigned int flags;
    ~S();
};

S::~S()
{
    try {
        unsigned int state = flags;
        Stream *p = *stream;
        if (state & 2)
            pubsync(&p->buffer);
    }
    catch (...) {
        flags |= 4;
    }
}
