// from server: 100% by king_originala
struct String;

extern void (__thiscall *string_construct)(String *, const char *);
extern void (__thiscall *string_destroy)(String *);

struct String {
    unsigned int allocator;
    union {
        char buffer[16];
        char *pointer;
    };
    unsigned int length;
    unsigned int capacity;

    String(const char *text) {
        string_construct(this, text);
    }

    ~String() {
        string_destroy(this);
    }
};

extern int (__cdecl *fprintf)(void *, const char *, ...);
extern int (__cdecl *fclose)(void *);

extern const char closing_message[];
extern const char shutdown_message[];
extern const char log_format[];

struct S {
    void *file;
    String name;

    virtual ~S();
    void log(const String &) throw();
    void timestamp();
};

extern S *current;

S::~S()
{
    log(String(closing_message));

    {
        String message(shutdown_message);
        if (file) {
            timestamp();
            fprintf(file, log_format,
                    message.capacity >= 16 ? message.pointer : message.buffer);
        }
    }

    if (current == this)
        current = 0;

    if (file)
        fclose(file);
}
