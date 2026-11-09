// from server: 42% by colin
struct StandardOut {
    void* vtable;
    int pad1;
    void* field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    void destroy();
};

void __stdcall sub_462210();
void __stdcall sub_433660(void*);
void __stdcall sub_62FC62(void*);

void StandardOut::destroy()
{
    this->vtable = (void*)0x78cdfc;
    sub_462210();
    sub_433660((void*)this->field18);
    if (this->field8) {
        sub_62FC62(this->field8);
    }
    this->field8 = 0;
    this->fieldC = 0;
    this->field10 = 0;
    this->vtable = (void*)0x78cd94;
}
