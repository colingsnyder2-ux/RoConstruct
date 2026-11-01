// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Argument;
struct Entry;

struct RefCount {
    virtual void slot0() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
    void release();
};

inline void RefCount::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Manager {
    Entry* lookup(Argument*);
};

struct Shared {
    Manager* pointer;
    RefCount* count;
    ~Shared();
    Manager* get() const;
};

inline Shared::~Shared()
{
    if (count)
        count->release();
}

inline Manager* Shared::get() const
{
    return pointer;
}

extern Shared __cdecl getManager();

struct Entry {
    char padding[0x130];
    unsigned char enabled;
    unsigned char requiresFirst;
    unsigned char requiresSecond;
};

struct Settings {
    char padding[0x130];
    unsigned char first;
    unsigned char second;
};

extern Settings* __cdecl getSettings();

struct String {
    char storage[1];
};

struct Name {
    char padding[4];
    String text;
};

extern const char* (__thiscall *string_c_str)(const String*);

struct Argument {
    unsigned long unused;
    Name* name;
    unsigned long unused2;
    unsigned long identifier;
    unsigned char flags;
};

struct CDeclarationView {
    char padding[0xa8];
    unsigned char all;
    char alignment[3];
    unsigned long identifier;

    void process(Argument*);
    void* insert(int, const char*, int, int, int, int, int,
                 unsigned long, unsigned long);
    void configure(void*, int, int, int, int, int, int, Argument*);
    void finish(void*, Entry*);
};

void CDeclarationView::process(Argument* argument)
{
    if (!all && argument->identifier != identifier)
        return;

    Entry* entry = getManager().get()->lookup(argument);

    if (entry) {
        Settings* settings = getSettings();
        if (entry->requiresFirst && !settings->first)
            return;
        if (entry->requiresSecond && !settings->second)
            return;
        if (!entry->enabled)
            return;
    }

    if (argument->flags & 1) {
        Name* name = argument->name;
        const char* text = string_c_str(&name->text);
        void* handle = insert(0x23, text, 6, 6, 0, 0, 0,
                              0xffff0000UL, 0xffff0002UL);
        configure(handle, 4, 0, 0, 0, 0, 0, argument);
        finish(handle, entry);
    }
}
