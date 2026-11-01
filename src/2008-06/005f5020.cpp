// from server: 100% by king_originala
namespace std {
    class exception {};
}

struct Stream;
extern int (__thiscall *pubsync)(Stream*);

struct S {
    char pad0[0x14];
    char** first;
    char pad1[0x0c];
    char** current;
    char pad2[0x0c];
    int* available;
    char pad3[0x0c];
    Stream* stream;
    char* buffer;
    int length;

    int sync();
};

int S::sync()
{
    int count = *current - *first;
    try {
        if (count > 0) {
            char* start = buffer;
            char* end = start + length;
            *first = start;
            *current = start;
            *available = end - start;
        }
        if (stream)
            pubsync(stream);
        return 0;
    }
    catch (const std::exception&) {
        volatile int result = -1;
        return result;
    }
}
