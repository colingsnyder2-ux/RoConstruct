// from server: 48% by colin
struct MarshaledListener
{
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
    void* field14;
    void* field18;
    void destroy();
};

extern "C" void __cdecl sub_462210();
extern "C" void __cdecl sub_433660(void*);
extern "C" void __cdecl sub_62FC62(void*);

void MarshaledListener::destroy()
{
    *(void**)this = (void*)0x787f74;
    sub_462210();
    sub_433660(field18);
    if (field8)
    {
        sub_62FC62(field8);
    }
    field8 = 0;
    fieldC = 0;
    field10 = 0;
    *(void**)this = (void*)0x787ea8;
}
