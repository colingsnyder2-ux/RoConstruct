// from server: 100% by king_originala
struct Value {
    unsigned int words[6];
};

inline void* operator new(unsigned int, void* p) {
    return p;
}

extern bool __cdecl func_0060a2f0(const Value&);

struct S {
    unsigned int tag;
    unsigned int reserved;
    Value value;

    void f(const Value& source);
};

void S::f(const Value& source) {
    if (!func_0060a2f0(source)) {
        new (&value) Value(source);
        tag = 0x00846160;
    } else {
        tag = 0;
    }
}
