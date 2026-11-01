// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);

struct Product;

struct Deleter {
    void operator()(Product*) const;
};

struct ControlBlock {
    long strongCount;
    long weakCount;
    Product* object;
    Deleter deleter;

    ControlBlock(Product* p, Deleter d)
        : strongCount(1), weakCount(1), object(p), deleter(d) {}

    virtual ~ControlBlock();
    virtual void dispose();
    virtual void destroy();
    virtual void* getDeleter(const void*);
};

struct SharedCount {
    ControlBlock* block;

    SharedCount(Product* p, Deleter d);
};

SharedCount::SharedCount(Product* p, Deleter d) : block(0)
{
    try {
        block = new ControlBlock(p, d);
    } catch (...) {
        d(p);
        throw;
    }
}
