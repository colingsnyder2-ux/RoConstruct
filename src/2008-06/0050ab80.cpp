// from server: 100% by king_originala
extern void (__thiscall* constructException)(void*, const char* const&);
extern char exceptionType;
extern "C" __declspec(noreturn) void __stdcall throwException(void*, void*);

struct S {
    char padding[0x34];
    int size;
    int capacity;
    int position;
    int reserved;
    int offset;

    void resize(int requested);
    void grow(int difference, int oldSize);
};

void S::resize(int requested)
{
    int adjusted = requested - offset;
    if (adjusted < 0) {
        int exceptionObject[3];
        requested = reinterpret_cast<int>("Cannot resize huge files to be shorter.");
        constructException(exceptionObject,
                           reinterpret_cast<const char* const&>(requested));
        throwException(exceptionObject, &exceptionType);
    }

    int oldSize = size;
    if (adjusted < oldSize)
        position = adjusted;

    if (adjusted > oldSize) {
        int difference = adjusted - oldSize;
        int newSize = position + difference;
        if (oldSize >= newSize)
            newSize = oldSize;
        size = newSize;
        if (newSize > capacity)
            grow(difference, oldSize);
    }
}
