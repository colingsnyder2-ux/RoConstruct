// from server: 100% by king_originala
struct Shared {
    void* pointer;
    void* control;
    Shared(void*);
    Shared(const Shared&);
    ~Shared();
};

struct Holder {
    void set(Shared);
};

struct Output {
    char padding[16];
    Holder holder;
};

struct Getter {
    virtual void slot0();
    virtual void slot1();
    virtual void* get(void*);
};

struct Descriptor {
    char padding[28];
    Getter* getter;
    void read(void*, Output*);
};

void Descriptor::read(void* object, Output* output)
{
    output->holder.set(Shared(getter->get(object)));
}
