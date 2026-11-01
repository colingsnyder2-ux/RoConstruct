// from server: 100% by colin
namespace std {
    template<class T> struct char_traits;
    template<class T, class Traits> class basic_streambuf;
}

typedef std::basic_streambuf<char, std::char_traits<char> > Buffer;
typedef int (__thiscall *SyncFunction)(Buffer*);

extern SyncFunction pubsync;
__declspec(noreturn) void __stdcall write_buffer(
    void*, Buffer*, const char*, int);

struct S {
    char padding0[0x14];
    char** begin;
    char padding1[0x0C];
    char** end;
    char padding2[0x18];
    char writer[8];
    Buffer* output;

    bool sync();
};

bool S::sync()
{
    const char* last = *end;
    const char* first = *begin;
    int count = last - first;

    try {
        if (count > 0) {
            Buffer* out = output;
            write_buffer(writer, out, first, count);
        }

        bool result = true;
        if (output && pubsync(output) == -1)
            result = false;
        return result;
    }
    catch (...) {
        return false;
    }
}
