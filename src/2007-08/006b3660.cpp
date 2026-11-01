// from server: 100% by colin
struct Inner {
    char pad[0xd0];
    int value;
};

struct Outer {
    char pad[0x178];
    Inner inner;
};

extern "C" Inner* __fastcall get_inner(Outer* self);

struct CXTPControlGallery {
    int getValue();
};

int CXTPControlGallery::getValue() {
    Outer* o = (Outer*)((char*)this - 0x178);
    Inner* in = get_inner(o);
    return in->value;
}
