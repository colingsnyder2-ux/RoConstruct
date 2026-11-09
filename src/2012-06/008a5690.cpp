// from server: 100% by atomic.potato
extern "C" void sub_8a54e0();
extern "C" void __cdecl sub_982114(void*);

struct AdvMoveTool
{
    int vtable0;
    int vtable1;
    AdvMoveTool(unsigned char);
};

AdvMoveTool::AdvMoveTool(unsigned char destroy)
{
    vtable0 = 0x00bdef4c;
    vtable1 = 0x00bdef20;
    sub_8a54e0();
    if (destroy & 1)
        sub_982114(this);
}
