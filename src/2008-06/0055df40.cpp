// from server: 100% by king_originala
extern "C" unsigned int __cdecl strlen(const char *);
extern "C" unsigned int (__cdecl *strnlen)(const char *, unsigned int);
extern "C" int (__stdcall *PathAppendA)(char *, const char *);

namespace ATL {
    __declspec(noreturn) void __stdcall AtlThrowImpl(long);
}

struct S {
    char *data;
    void grow(int);
    int append(const char *);
};

int S::append(const char *path)
{
    int *header = reinterpret_cast<int *>(data);
    int oldLength = header[-3];
    int length = path == 0 ? 0 : static_cast<int>(strlen(path));
    int required = oldLength + length + 1;

    if (((1 - header[-1]) | (header[-2] - required)) < 0)
        grow(required);

    int result = PathAppendA(data, path);

    char *buffer = data;
    int capacity = *reinterpret_cast<int *>(
        reinterpret_cast<unsigned int>(buffer) - 8);
    int newLength = buffer == 0
        ? 0
        : static_cast<int>(strnlen(buffer, capacity));

    if (newLength < 0 ||
        newLength > reinterpret_cast<int *>(data)[-2])
        ATL::AtlThrowImpl(static_cast<long>(0x80070057UL));

    reinterpret_cast<int *>(data)[-3] = newLength;
    data[newLength] = 0;
    return result;
}
