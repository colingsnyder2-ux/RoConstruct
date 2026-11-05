// from server: 100% by king_originala
struct Value {
    unsigned int a, b, c, d;
};

extern bool __cdecl func_0060a2f0(const Value *);
extern unsigned char descriptor;

inline void *__cdecl operator new(unsigned int, void *p) {
    return p;
}

struct S {
    void *type;
    unsigned int reserved;
    Value value;

    S(Value input, unsigned int unused);
};

S::S(Value input, unsigned int unused) {
    type = 0;
    if (!func_0060a2f0(&input)) {
        new (&value) Value(input);
        type = &descriptor;
    } else {
        type = 0;
    }
}
