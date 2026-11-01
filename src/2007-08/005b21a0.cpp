// from server: 100% by colin
struct Base {
    void construct(int);
};

struct S : Base {
    S* S_ctor(int);
};

S* S::S_ctor(int arg)
{
    Base::construct(arg);
    *(int*)((char*)this + 0x00) = 0x7b796c;
    *(int*)((char*)this + 0x04) = 0x7b7964;
    *(int*)((char*)this + 0x10) = 0x7b795c;
    *(int*)((char*)this + 0x14) = 0x7b794c;
    *(int*)((char*)this + 0x2c) = 0x7b793c;
    *(int*)((char*)this + 0x44) = 0x7b792c;
    *(int*)((char*)this + 0x5c) = 0x7b791c;
    *(int*)((char*)this + 0x74) = 0x7b790c;
    *(int*)((char*)this + 0x8c) = 0x7b78fc;
    *(int*)((char*)this + 0xe8) = 0x7b78e4;
    return this;
}
