// from server: 100% by colin
// roc 2008-06 00562a30
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Text;
struct Input;
struct Output;
struct Buffer;
struct Header;

extern void (__thiscall *textConstruct)(Text*, const char*);
extern void (__thiscall *textCopy)(Text*, const Text&);
extern void (__thiscall *textDestroy)(Text*);
extern void (__thiscall *outputConstruct)(Output*, int);
extern void (__thiscall *outputDestroy)(Output*);
extern void (__thiscall *outputOpen)(Output*, const char*, int, int);
extern void (__thiscall *inputClear)(void*, int, bool);
extern Input& (__thiscall *inputSeek)(Input*, long, int);
extern Input& (__thiscall *inputGet)(Input*, char&);

extern void* __cdecl getLocalScope();
extern void __cdecl initializeBuffer(Buffer*, int);
extern void __cdecl writeCharacter(Output*, char);

struct Text {
    unsigned int allocator;
    union {
        char small[16];
        char* large;
    } storage;
    unsigned int length;
    unsigned int capacity;

    Text(const char*);
    Text(const Text&);
    ~Text();
};

inline Text::Text(const char* value) {
    textConstruct(this, value);
}

inline Text::Text(const Text& value) {
    textCopy(this, value);
}

inline Text::~Text() {
    textDestroy(this);
}

struct Name : Text {
    void* scope;

    Name(const char*);
    Name(const Name&);
};

inline Name::Name(const char* value) : Text(value) {
    scope = getLocalScope();
}

inline Name::Name(const Name& value) : Text(value) {
    scope = value.scope;
}

struct Manager {
    virtual void unused() = 0;
    virtual void release(Header*) = 0;
};

struct Header {
    Manager* manager;
    unsigned int reserved[2];
    volatile long references;
};

struct Buffer {
    char* data;

    Buffer(int);
    ~Buffer();
    void assign(const char*);
};

inline Buffer::Buffer(int value) {
    initializeBuffer(this, value);
}

inline Buffer::~Buffer() {
    Header* header = reinterpret_cast<Header*>(data - 16);
    volatile long* refs = &header->references;
    if (_InterlockedExchangeAdd(refs, -1) - 1 <= 0)
        header->manager->release(header);
}

struct Output {
    char storage[136];

    Output();
    ~Output();
    void open(const char*, int, int);
};

inline Output::Output() {
    outputConstruct(this, 1);
}

inline Output::~Output() {
    outputDestroy(this);
}

inline void Output::open(const char* name, int mode, int protection) {
    outputOpen(this, name, mode, protection);
}

struct Input {
    int* table;
};

struct S {
    bool prepare(Name);
    Name extract(const char*, Input*, unsigned int);
};

Name S::extract(const char* value, Input* input, unsigned int count) {
    Name result(value);
    if (prepare(result)) {
        inputClear(reinterpret_cast<char*>(input) + input->table[1], 0, false);
        inputSeek(input, count, 1);
    } else {
        Buffer buffer(1);
        buffer.assign(result.capacity >= 16
            ? result.storage.large : result.storage.small);
        Output output;
        output.open(buffer.data, 34, 64);
        if (count > 0) {
            do {
                char character;
                inputGet(input, character);
                writeCharacter(&output, character);
            } while (--count);
        }
    }
    return result;
}
