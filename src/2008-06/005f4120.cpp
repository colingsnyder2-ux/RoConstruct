// from server: 100% by king_originala
typedef void* (__thiscall *AppendFunction)(void*, const char*, unsigned int);
typedef int (__thiscall *SyncFunction)(void*);

extern AppendFunction basic_string_append;
extern SyncFunction basic_streambuf_pubsync;

struct S {
    char reserved0[0x14];
    char** first;
    char reserved1[0x0C];
    char** next;
    char reserved2[0x0C];
    int* remaining;
    char reserved3[0x08];
    void* string;
    char reserved4[0x04];
    void* streambuf;
    char* buffer;
    int capacity;

    int sync();
};

int S::sync()
{
    char* finish = *next;
    char* start = *first;
    int count = finish - start;
    try {
        if (count > 0) {
            basic_string_append(string, start, count);
            char* begin = buffer;
            char* end = begin + capacity;
            *first = begin;
            *next = begin;
            *remaining = end - begin;
        }
        if (streambuf)
            basic_streambuf_pubsync(streambuf);
    }
    catch (...) {
        volatile int result = -1;
        return result;
    }
    return 0;
}
