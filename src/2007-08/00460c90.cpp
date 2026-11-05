// from server: 52% by colin
struct MarshaledListener {
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
    this->field0 = (void*)0x794b74;
    sub_462210();
    sub_433660(this->field18);
    if (this->field8) {
        sub_62FC62(this->field8);
    }
    this->field8 = 0;
    this->fieldC = 0;
    this->field10 = 0;
    this->field0 = (void*)0x794a84;
}
