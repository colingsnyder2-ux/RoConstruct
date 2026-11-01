// from server: 100% by colin
struct Base {
    void construct(int);
};

struct S : Base {
    S* S_ctor(int);
};

S* S::S_ctor(int arg)
{
    construct(arg);
    *(int*)((char*)this + 0x00) = 0x7b72e4;
    *(int*)((char*)this + 0x04) = 0x7b72dc;
    *(int*)((char*)this + 0x10) = 0x7b72d4;
    *(int*)((char*)this + 0x14) = 0x7b72c4;
    *(int*)((char*)this + 0x2c) = 0x7b72b4;
    *(int*)((char*)this + 0x44) = 0x7b72a4;
    *(int*)((char*)this + 0x5c) = 0x7b7294;
    *(int*)((char*)this + 0x74) = 0x7b7284;
    *(int*)((char*)this + 0x8c) = 0x7b7274;
    *(int*)((char*)this + 0xe8) = 0x7b725c;
    return this;
}
