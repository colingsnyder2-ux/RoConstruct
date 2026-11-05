// from server: 100% by colin
struct Base {
    void construct(int);
};

struct S : Base {
    S* ctor(int);
};

S* S::ctor(int a)
{
    Base::construct(a);
    *(int*)((char*)this + 0x00) = 0x7b77c4;
    *(int*)((char*)this + 0x04) = 0x7b77bc;
    *(int*)((char*)this + 0x10) = 0x7b77b4;
    *(int*)((char*)this + 0x14) = 0x7b77a4;
    *(int*)((char*)this + 0x2c) = 0x7b7794;
    *(int*)((char*)this + 0x44) = 0x7b7784;
    *(int*)((char*)this + 0x5c) = 0x7b7774;
    *(int*)((char*)this + 0x74) = 0x7b7764;
    *(int*)((char*)this + 0x8c) = 0x7b7754;
    *(int*)((char*)this + 0xe8) = 0x7b773c;
    return this;
}
