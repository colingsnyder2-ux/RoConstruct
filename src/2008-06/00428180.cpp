// from server: 100% by king_originala
typedef unsigned int size_t;

void * __cdecl operator new(size_t);
void __cdecl operator delete(void *) throw();

struct String;
struct TextResult;

extern void (__thiscall *string_construct)(String *, const char *);
extern String & (__thiscall *string_append)(String *, const String &);
extern String & (__thiscall *string_erase)(String *, unsigned int, unsigned int);
extern const char * (__thiscall *string_c_str)(const String *, int);
extern void (__thiscall *string_destroy)(String *);
extern const unsigned int *string_npos;

extern const char * (__thiscall *getText)(TextResult *);
extern void (__thiscall *releaseText)(TextResult *);

struct TextResult {
    unsigned int data;
    const char *get();
    ~TextResult();
};

inline const char *TextResult::get()
{
    return getText(this);
}

inline TextResult::~TextResult()
{
    releaseText(this);
}

struct String {
    unsigned char data[28];
    String(const char *);
    ~String();
    TextResult text();
};

inline String::String(const char *value)
{
    string_construct(this, value);
}

inline String::~String()
{
    string_destroy(this);
}

struct Buffer {
    unsigned char data[2000];
    Buffer(const char *, const char *);
    void start();
};

struct MainLogManager {
    unsigned int reserved;
    String source;
    unsigned char padding[12];
    Buffer *buffer;
    String suffix;
    Buffer *replace(Buffer *);
    void run();
};

inline Buffer *MainLogManager::replace(Buffer *value)
{
    Buffer *old = buffer;
    buffer = value;
    return old;
}

void MainLogManager::run()
{
    String name("log_");
    string_append(&name, suffix);
    string_erase(&name, 12, *string_npos);
    string_erase(&name, 4, 3);
    operator delete(replace(new Buffer(source.text().get(),
                                      string_c_str(&name, 1))));
    buffer->start();
}
