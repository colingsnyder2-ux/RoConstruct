// from server: 48% by colin
struct VInstanceMarshaledListener
{
    void* vtable;
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

void VInstanceMarshaledListener::destroy()
{
    this->vtable = (void*)0x787f54;
    sub_462210();
    sub_433660(this->field18);
    if (this->field8)
    {
        sub_62FC62(this->field8);
    }
    this->field8 = 0;
    this->fieldC = 0;
    this->field10 = 0;
    this->vtable = (void*)0x787e9c;
}
