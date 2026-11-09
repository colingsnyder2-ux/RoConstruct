// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);

struct S;

struct Owner {
    S** pointer;
    unsigned int unused[3];
    unsigned int a, b, c, d;
    Owner(S**);
    ~Owner();
};

struct State {
    unsigned char storage[12];
    State();
    ~State();
};

extern void* (__thiscall *construct_string)(void*);

struct String {
    unsigned char storage[28];
    String();
};

struct S {
    Owner owner;
    State state;
    String text;
    S();
};

__forceinline Owner::Owner(S** p)
    : pointer(p), a(0), b(0), c(0), d(0) {
}

__forceinline String::String() {
    construct_string(this);
}

S::S()
    : owner(new S*(this)), state(), text() {
}
