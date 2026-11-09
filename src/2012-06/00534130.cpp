// from server: 17% by atomic.potato
extern "C" void __stdcall helper_0052cf50();
extern "C" void __stdcall helper_00541330();
extern "C" void __stdcall helper_007092a0();

struct VPlayerBoundFuncDesc {
    void construct(int, int, int, int, int, int, int, int);
};

void VPlayerBoundFuncDesc::construct(int a, int b, int c, int d, int e, int f, int g, int h)
{
    helper_0052cf50();
    *(int*)((char*)this + 0x30) = c;
    *(int*)((char*)this + 0x34) = d;
    *(int*)((char*)this + 0x38) = 0;
    *(int*)((char*)this + 0x3c) = 0;
    helper_007092a0();
    helper_007092a0();
    helper_00541330();
}
