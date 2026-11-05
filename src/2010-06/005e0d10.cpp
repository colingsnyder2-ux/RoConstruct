// from server: 65% by atomic.potato
struct FirstPersonCommand
{
    int value;
    int pad0;
    int pad1;
    int handle;
    int f();
};

extern "C" void* __cdecl sub_66E840(int);

int FirstPersonCommand::f()
{
    void* p = sub_66E840(handle);
    if (!p)
        return 0;
    return *(float*)((char*)p + 0x164) < *(float*)0xA2E0B0 ? 1 : 0;
}
