// from server: 100% by tester
struct FactoryProduct {
    void construct();
};

extern "C" void __stdcall sub_715990();

void FactoryProduct::construct()
{
    *(int*)((char*)this + 0) = 0x9decdc;
    *(int*)((char*)this + 4) = 0x9decd0;
    *(int*)((char*)this + 0x18) = 0x9decc4;
    *(int*)((char*)this + 0x1c) = 0x9decbc;
    *(int*)((char*)this + 0x94) = 0x9deca4;
    sub_715990();
}
