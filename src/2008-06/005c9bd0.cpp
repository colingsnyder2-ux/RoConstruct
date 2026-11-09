// from server: 100% by tester
struct Base {
    void construct(int);
};

struct S : Base {
    S* init(int);
};

S* S::init(int a) {
    Base::construct(a);
    *(int*)((char*)this + 0x00) = 0x839d7c;
    *(int*)((char*)this + 0x10) = 0x839d6c;
    *(int*)((char*)this + 0x14) = 0x839d64;
    *(int*)((char*)this + 0x20) = 0x839d5c;
    *(int*)((char*)this + 0x24) = 0x839d4c;
    *(int*)((char*)this + 0x44) = 0x839d3c;
    *(int*)((char*)this + 0x64) = 0x839d2c;
    *(int*)((char*)this + 0x84) = 0x839d1c;
    *(int*)((char*)this + 0xa4) = 0x839d0c;
    *(int*)((char*)this + 0xc4) = 0x839cfc;
    return this;
}
