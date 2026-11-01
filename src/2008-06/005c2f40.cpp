// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern const unsigned int controlBlockTable[];

struct Object {
    virtual ~Object();
};

struct Deleter {
    void operator()(Object* p) const { delete p; }
};

struct ControlBlock {
    const unsigned int* table;
    long strongCount;
    long weakCount;
    Object* object;
    Deleter deleter;

    ControlBlock(Object* p, Deleter d);
};

inline ControlBlock::ControlBlock(Object* p, Deleter d)
    : table(controlBlockTable), strongCount(1), weakCount(1),
      object(p), deleter(d)
{
}

struct SharedCount {
    ControlBlock* block;
    SharedCount(Object* p, Deleter d);
};

SharedCount::SharedCount(Object* p, Deleter d) : block(0)
{
    try {
        block = new ControlBlock(p, d);
    } catch (...) {
        d(p);
        throw;
    }
}
