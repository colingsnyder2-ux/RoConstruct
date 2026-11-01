// from server: 100% by colin
// from server: 87% by king_originala
struct StreamBuffer;

typedef int (__thiscall *SyncFunction)(StreamBuffer*);
extern SyncFunction syncFunction;

struct S {
    char padding[0x8c];
    StreamBuffer* buffer;

    void finish();
    bool f();
};

bool S::f()
{
    try {
        finish();
        if (buffer)
            syncFunction(buffer);
    }
    catch (...) {
        throw;
    }
    return false;
}
