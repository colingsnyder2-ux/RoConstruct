// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Value {
    ~Value();
};

struct Owner {
    Value* pointer;
    Owner();
    ~Owner();
};

inline Owner::Owner() : pointer(0) {}
inline Owner::~Owner() {
    delete pointer;
}

struct Name {
    Owner value;
    Name();
    ~Name();
    void initialize();
};

inline Name::Name() {
    initialize();
}

inline Name::~Name() {}

extern Name* globalName;

void initializeGlobalName() {
    Name* replacement = new Name;
    Name* previous = globalName;
    globalName = replacement;
    delete previous;
}
