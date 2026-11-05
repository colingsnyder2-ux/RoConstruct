// from server: 100% by tester
struct TypedPropertyDescriptor {
    void construct();
};

void TypedPropertyDescriptor::construct()
{
    *(int*)((char*)this + 0x00) = 0x8ad2bc;
    *(int*)((char*)this + 0x14) = 0x8ad2ac;
    *(int*)((char*)this + 0x18) = 0x8ad2a4;
    *(int*)((char*)this + 0x20) = 0x8ad29c;
    extern void __stdcall sub_5d2b60();
    sub_5d2b60();
}
