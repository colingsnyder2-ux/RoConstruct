// from server: 57% by colin
struct VCWorkspace_CComObject
{
    void __stdcall sub_468740(int, int);
};

extern "C" void __stdcall sub_62FF38(void*, int);
extern "C" void __stdcall sub_427DB0(int, unsigned int, unsigned int, int);
extern "C" void __stdcall sub_467010(unsigned int, unsigned int);

void VCWorkspace_CComObject::sub_468740(int a1, int a2)
{
    *(int*)(a1 + 4) = (int)this;
    if (*(int*)((char*)this - 0x28) != 0)
    {
        sub_62FF38(*(void**)((char*)this - 0x2c), 0);
    }
    sub_427DB0(1, 0x80004003, 0x796058, 0x12a);
    sub_467010(0x80004003, 0x790270);
}
