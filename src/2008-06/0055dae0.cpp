// from server: 100% by king_originala
extern "C" {
    extern int (__cdecl * const _vscprintf)(const char *, char *);
    extern int (__cdecl * const vsprintf_s)(char *, unsigned int, const char *, char *);
}

namespace ATL {
    __declspec(noreturn) void __stdcall AtlThrowImpl(long);
}

struct StringData {
    void *manager;
    int length;
    int capacity;
    int references;
};

struct S {
    char *data;
    void prepare(int);
    void format(const char *, char *);
};

void S::format(const char *formatString, char *arguments)
{
    if (!formatString)
        ATL::AtlThrowImpl((long)0x80070057);

    int length = _vscprintf(formatString, arguments);
    StringData *header = reinterpret_cast<StringData *>(data) - 1;

    if (((1 - header->references) | (header->capacity - length)) < 0)
        prepare(length);

    vsprintf_s(data, length + 1, formatString, arguments);

    if (length < 0 ||
        length > (reinterpret_cast<StringData *>(data) - 1)->capacity)
        ATL::AtlThrowImpl((long)0x80070057);

    (reinterpret_cast<StringData *>(data) - 1)->length = length;
    data[length] = 0;
}
