// from server: 56% by colin
struct SignalDesc {
    void* vtable;
    int field_4;
    void* field_8;
    int field_c;
    int field_10;
    void destroy();
};

void __cdecl free_ptr(void* p);

void SignalDesc::destroy()
{
    this->vtable = (void*)0x7b5880;
    if (this->field_8) {
        free_ptr(this->field_8);
    }
    this->field_8 = 0;
    this->field_c = 0;
    this->field_10 = 0;
}
