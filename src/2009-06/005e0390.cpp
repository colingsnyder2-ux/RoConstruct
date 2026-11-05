// from server: 100% by EspClaude
// from server: 72% by EspClaude
// roc 2009-06 005e0390  unit: RBX::VContentProvider::?$BoundFuncDesc  size: 214 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005e0390
//

// from server: 100% by king_originala
// roc 2008-06 00561e30  unit: RBX::VContentProvider::?$DescribedNonCreatable  size: 238 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00561e30
//

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

extern LoadError __cdecl format(const char *, ...);

struct Provider {
    Entry *find(Content, int, int);
    bool valid(Entry *);
    String load(Content);
};

String Provider::load(Content content) {
    Entry *entry = find(content, 2, 0);
    if (entry && valid(entry))
        return *entry->text;
    throw format("Unable to load %s", content.text.c_str());
}
