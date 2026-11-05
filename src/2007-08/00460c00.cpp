// from server: 52% by colin
struct MarshaledListener {
    void* vtable;
    int field_4;
    void* field_8;
    int field_c;
    int field_10;
    int field_14;
    int field_18;
    void destroy();
};

extern "C" void __cdecl sub_462210();
extern "C" void __cdecl sub_433660(void*);
extern "C" void __cdecl sub_62FC62(void*);

void MarshaledListener::destroy()
{
    this->vtable = (void*)0x794b60;
    sub_462210();
    sub_433660((void*)this->field_18);
    if (this->field_8) {
        sub_62FC62(this->field_8);
    }
    this->field_8 = 0;
    this->field_c = 0;
    this->field_10 = 0;
    this->vtable = (void*)0x788344;
}
