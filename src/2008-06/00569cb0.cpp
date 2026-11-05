// from server: 100% by king_originala
namespace ATL {
__declspec(noreturn) void __stdcall AtlThrowImpl(long);
}

__declspec(noreturn) void __cdecl allocation_failure();

extern "C" int (__cdecl *memcpy_s)(
    void*, unsigned int, const void*, unsigned int);

struct StringData {
    void* manager;
    int length;
    int capacity;
    long references;
};

struct StringManager {
    virtual StringData* Allocate(int length, int characterSize);
};

struct S {
    char* data;
    S(const char* source, int length, StringManager* manager);
};

S::S(const char* source, int length, StringManager* manager)
{
    if (!manager)
        ATL::AtlThrowImpl(0x80004005L);

    if (!source && length != 0)
        ATL::AtlThrowImpl(0x80070057L);

    StringData* allocation = manager->Allocate(length, 1);
    if (!allocation)
        allocation_failure();

    data = reinterpret_cast<char*>(allocation + 1);

    if (length < 0 ||
        length > (reinterpret_cast<StringData*>(data) - 1)->capacity)
        ATL::AtlThrowImpl(0x80070057L);

    (reinterpret_cast<StringData*>(data) - 1)->length = length;
    data[length] = 0;
    memcpy_s(data, length, source, length);
}
