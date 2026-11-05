// from server: 100% by colin
struct Base {
    void construct(int);
};

struct S : Base {
    S* init(int);
};

S* S::init(int a) {
    Base::construct(a);
    *(int*)((char*)this + 0x00) = 0x7bf4c4;
    *(int*)((char*)this + 0x04) = 0x7bf4bc;
    *(int*)((char*)this + 0x10) = 0x7bf4b4;
    *(int*)((char*)this + 0x14) = 0x7bf4a4;
    *(int*)((char*)this + 0x2c) = 0x7bf494;
    *(int*)((char*)this + 0x44) = 0x7bf484;
    *(int*)((char*)this + 0x5c) = 0x7bf474;
    *(int*)((char*)this + 0x74) = 0x7bf464;
    *(int*)((char*)this + 0x8c) = 0x7bf454;
    *(int*)((char*)this + 0xe8) = 0x7bf43c;
    *(int*)((char*)this + 0xf0) = 0x7bf430;
    return this;
}
