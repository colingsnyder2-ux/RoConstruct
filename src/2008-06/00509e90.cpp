// from server: 100% by tester
extern "C" int (__cdecl *fprintf)(void *, const char *, ...);

struct String {
    unsigned allocator;
    union {
        char buffer[16];
        char *pointer;
    };
    unsigned length;
    unsigned capacity;
};

struct Shader {
    unsigned reserved;
    void *file;
    void write(const String &text);
};

void Shader::write(const String &text)
{
    if (file) {
        int (__cdecl *print)(void *, const char *, ...) = fprintf;
        print(file, "_____________________________________________________\n");
        print(file, "\n    ###    %s    ###\n\n",
              text.capacity >= 16 ? text.pointer : text.buffer);
    }
}
