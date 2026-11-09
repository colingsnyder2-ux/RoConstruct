// from server: 100% by king_originala
struct String {};
struct StreamBuffer {};

typedef String& (__thiscall *AppendFunction)(String*, const char*, unsigned int);
typedef int (__thiscall *SyncFunction)(StreamBuffer*);

extern AppendFunction append;
extern SyncFunction pubsync;

struct S
{
    char padding0[0x14];
    char** begin;
    char padding1[0x0C];
    char** end;
    char padding2[0x0C];
    int* remaining;
    char padding3[0x08];
    String* destination;
    int padding4;
    StreamBuffer* stream;
    char* buffer;
    int capacity;

    bool f();
};

bool S::f()
{
    try
    {
        char* last = *end;
        char* first = *begin;
        int length = last - first;
        if (length > 0)
        {
            append(destination, first, length);
            char* base = buffer;
            char* limit = base + capacity;
            *begin = base;
            *end = base;
            *remaining = limit - base;
        }

        bool result = true;
        if (stream && pubsync(stream) == -1)
            result = false;
        return result;
    }
    catch (...)
    {
        return false;
    }
}
