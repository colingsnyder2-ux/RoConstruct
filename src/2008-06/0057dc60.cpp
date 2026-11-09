// from server: 100% by king_originala
struct Value {
    unsigned char data[48];
};

struct Source {
    Value get();
};

struct Provider {
    virtual void slot0();
    virtual void slot1();
    virtual Source& source();
};

struct Owner {
    unsigned char padding[648];
    Provider provider;
};

extern "C" void* __cdecl convert(const Value&);
extern "C" void __cdecl assign(void*, void*);

struct TiltSelectionVerb {
    unsigned char padding[12];
    Owner* owner;

    void* execute(void* result);
};

void* TiltSelectionVerb::execute(void* result)
{
    assign(result, convert(owner->provider.source().get()));
    return result;
}
