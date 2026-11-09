// from server: 52% by colin
struct VInstanceMarshaledListener
{
    void* vtable;
    void* field_4;
    void* field_8;
    void* field_c;
    void* field_10;
    void* field_14;
    void* field_18;

    void destroy();
};

extern "C" void __cdecl sub_462210();
extern "C" void __cdecl sub_433660(void*);
extern "C" void __cdecl sub_62FC62(void*);

void VInstanceMarshaledListener::destroy()
{
    this->vtable = (void*)0x7921d0;
    sub_462210();
    sub_433660(this->field_18);
    if (this->field_8)
    {
        sub_62FC62(this->field_8);
    }
    this->field_8 = 0;
    this->field_c = 0;
    this->field_10 = 0;
    this->vtable = (void*)0x78835c;
}
