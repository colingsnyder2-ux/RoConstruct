// from server: 100% by king_originala
extern "C" int (__stdcall * const lstrlenW)(const wchar_t *);
extern "C" void * __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)

extern bool __cdecl stackAvailable(int);
extern char * __stdcall convertWide(char *, const wchar_t *, int, unsigned int);

struct Buffer
{
    void *head;
    ~Buffer() throw();
    char *allocate(int);
};

struct Processor
{
    int process(char *, void *);
};

struct Object
{
    unsigned int reserved;
    Processor processor;
};

int __stdcall convertAndProcess(Object *object, const wchar_t *text, void *output)
{
    if (!text || !output)
        return (int)0x80070057;

    Buffer buffer = { 0 };
    __int64 bytes = (__int64)(lstrlenW(text) + 1) * 2;
    char *converted = 0;

    if (bytes <= 2147483647i64 && bytes >= -2147483648i64)
    {
        int size = (int)bytes;
        char *storage;
        if (size <= 1024 && stackAvailable(size))
            storage = (char *)_alloca(size);
        else
            storage = buffer.allocate(size);

        converted = convertWide(storage, text, size, 3);
    }

    if (!converted)
        return (int)0x8007000e;

    return object->processor.process(converted, output)
        ? 0 : (int)0x8007000e;
}
