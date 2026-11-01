// from server: 100% by king_originala
struct String {
    void* proxy;
    union {
        char local[16];
        char* heap;
    };
    unsigned size;
    unsigned capacity;
};

struct Exception {
    void* vtable;
    const char* message;
    int owned;
};

struct S {
    String filename;
    char reserved[20];
    char* buffer;
    int used;
    int capacity;
    int position;
    int reserved40;
    unsigned written;

    void flush(int count);
    void reserve(int count);
};

extern bool (__cdecl *string_equal)(const String*, const char*);
extern Exception* (__thiscall *exception_construct)(Exception*, const char* const*);
extern void* (__cdecl *file_open)(const char*, const char*);
extern unsigned (__cdecl *file_write)(const void*, unsigned, unsigned, void*);
extern int (__cdecl *file_close)(void*);
extern char exception_type;
extern "C" __declspec(noreturn) void __stdcall throw_exception(void*, void*);
extern "C" void* __cdecl move_bytes(void*, const void*, unsigned);

void S::flush(int count)
{
    if (string_equal(&filename, "<memory>")) {
        const char* message =
            "Out of memory while writing to memory in BinaryOutput (no RAM left).";
        Exception error;
        exception_construct(&error, &message);
        throw_exception(&error, &exception_type);
    }

    if (count > capacity) {
        const char* message =
            "Out of memory while writing to disk in BinaryOutput (could not create a large enough buffer).";
        Exception error;
        exception_construct(&error, &message);
        throw_exception(&error, &exception_type);
    }

    int amount = used - 0xA00000;
    if (amount < used / 3)
        amount = used;

    const char* mode = written > 0 ? "ab" : "wb";
    const char* name = filename.capacity >= 16
        ? filename.heap : filename.local;
    void* file = file_open(name, mode);
    file_write(buffer, 1, amount, file);
    file_close(file);

    used -= amount;
    written += amount;
    position -= amount;
    move_bytes(buffer, buffer + amount, used);
    reserve(count);
}
