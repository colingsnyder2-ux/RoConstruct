// from server: 51% by colin
struct FunctionDescriptor {
    FunctionDescriptor();
    void* vtable;
};

struct BoundFuncDesc : FunctionDescriptor {
    void* field4;
    char pad8[8];
    void* field10;
    void* field14;
    char pad18[0x14];
    void* field2c;
    char pad30[0x14];
    void* field44;
    char pad48[0x14];
    void* field5c;
    char pad60[0x14];
    void* field74;
    char pad78[0x14];
    void* field8c;
    char pad90[0x80];
    void* field110;
    void* field114;
    void* field118;

    BoundFuncDesc(void* function, const char* name, int security, int attributes);
};

extern "C" void __stdcall sub_45AAC0();
extern "C" void __stdcall sub_4ACA90(void*, void*);

BoundFuncDesc::BoundFuncDesc(void* function, const char* name, int security, int attributes)
{
    FunctionDescriptor();
    this->vtable = (void*)0x79dc44;
    this->field4 = (void*)0x79dc3c;
    this->field10 = (void*)0x79dc34;
    this->field14 = (void*)0x79dc24;
    this->field2c = (void*)0x79dc14;
    this->field44 = (void*)0x79dc04;
    this->field5c = (void*)0x79dbf4;
    this->field74 = (void*)0x79dbe4;
    this->field8c = (void*)0x79dbd4;
    this->field110 = 0;
    this->field114 = 0;
    this->field118 = 0;
    sub_4ACA90((void*)0x5b9940, function);
}
