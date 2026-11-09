// from server: 100% by king_originala
typedef int (__thiscall *SyncFunction)(void *);
extern SyncFunction pubsync;

struct S {
    char padding0[0x14];
    char **base;
    char padding1[0x0c];
    char **current;
    char padding2[0x0c];
    int *remaining;
    char padding3[0x0c];
    void *stream;
    char *buffer;
    int size;

    bool sync();
};

bool S::sync()
{
    int count = *current - *base;
    try {
        if (count > 0) {
            char *first = buffer;
            char *last = first + size;
            *base = first;
            *current = first;
            *remaining = last - first;
        }
        bool result = true;
        if (stream && pubsync(stream) == -1)
            result = false;
        return result;
    }
    catch (...) {
        return false;
    }
}
