// from server: 74% by atomic.potato
struct FirstPersonCommand
{
    int unused_00;
    void* field_0c;
    int f();
};

extern "C" void* __cdecl sub_680260(void*);
extern float global_00a7fb58;

int FirstPersonCommand::f()
{
    void* p = sub_680260(field_0c);
    if (!p)
        return 0;
    return global_00a7fb58 > *(float*)((char*)p + 0x160) ? 1 : 0;
}
