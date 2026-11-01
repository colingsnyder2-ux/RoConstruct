// from server: 100% by king_originala
extern "C" void* (__stdcall *CreateSemaphoreA)(void*, long, long, const char*);
extern "C" void* (__stdcall *CreateMutexA)(void*, int, const char*);
extern "C" int (__stdcall *CloseHandle)(void*);

struct Error {
    void* vfptr;
    int pad[2];
    int field_c;
    Error* init();
};

extern unsigned char exception_type[];
extern "C" __declspec(noreturn) void __stdcall raise_exception(void*, void*);

struct S {
    void* semaphore;
    void* limit;
    void* mutex;
    int field_c;
    int field_10;
    int field_14;
    S* init();
};

S* S::init()
{
    void* (__stdcall *create)(void*, long, long, const char*) = CreateSemaphoreA;

    field_c = 0;
    field_10 = 0;
    field_14 = 0;

    semaphore = create(0, 1, 1, 0);
    limit = create(0, 0, 0x7fffffff, 0);

    void* handle = CreateMutexA(0, 0, 0);
    int (__stdcall *close)(void*) = CloseHandle;
    mutex = handle;

    if (semaphore && limit && mutex)
        return this;

    if (semaphore)
        close(semaphore);
    if (limit)
        close(limit);
    if (mutex)
        close(mutex);

    Error error;
    error.init();
    raise_exception(&error, exception_type);
}
