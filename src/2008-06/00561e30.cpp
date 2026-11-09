// from server: 100% by king_originala
struct String;

extern void (__thiscall *stringCopy)(String *, const String &);
extern void (__thiscall *stringDestroy)(String *);

struct String {
    unsigned int allocator;
    union {
        char local[16];
        char *heap;
    } storage;
    unsigned int length;
    unsigned int capacity;

    String(const String &);
    ~String();
    const char *c_str() const;
};

__forceinline String::String(const String &other) {
    stringCopy(this, other);
}

__forceinline String::~String() {
    stringDestroy(this);
}

__forceinline const char *String::c_str() const {
    const char *result = storage.heap;
    if (capacity < 16)
        result = storage.local;
    return result;
}

struct Content {
    String text;
    unsigned int tag;
};

struct Entry {
    unsigned int reserved[2];
    String *text;
};

struct LoadError {
    char storage[40];
    LoadError(const String &);
    LoadError(const LoadError &);
    ~LoadError();
};

extern String __cdecl format(const char *, ...);

struct Provider {
    Entry *find(Content, int, int);
    bool valid(Entry *);
    String load(Content);
};

String Provider::load(Content content) {
    Entry *entry = find(content, 2, 0);
    if (entry && valid(entry))
        return *entry->text;
    throw LoadError(format("Unable to load %s", content.text.c_str()));
}
