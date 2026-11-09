// from server: 100% by king_originala
struct Empty {};

struct Signal {
    void emit(Empty* result, bool value);
};

struct Entry {
    char padding[16];
    Signal signal;
};

struct Registry {
    Entry* find(void* key);
};

struct S {
    char padding[304];
    bool value;
    void notify(int unused);
};

void S::notify(int unused)
{
    void* key = this ? static_cast<void*>(padding + 20) : 0;
    bool current = value;
    Entry* entry = reinterpret_cast<Registry*>(0x97d218)->find(key);
    if (entry) {
        Empty result;
        entry->signal.emit(&result, current);
    }
}
