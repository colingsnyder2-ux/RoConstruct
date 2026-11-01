// from server: 100% by colin
struct PartInstance {
    void sub_005BD420();
    void func_00573EA0(int);
};

void PartInstance::func_00573EA0(int)
{
    *(unsigned char*)((char*)this + 0x250) = 1;
    *(unsigned char*)((char*)this + 0xf9) = 1;
    *(unsigned char*)((char*)this + 0x269) = 1;
    ((PartInstance*)((char*)this + 0x17c))->sub_005BD420();
}
