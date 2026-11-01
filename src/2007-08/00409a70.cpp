// from server: 72% by colin
struct VCAppCComObject {
    void* vfptr0;
    void* vfptr4;
    void* field8;
    void* fieldC;
    void* field10;
    void* field14;
    void* field18;
    void* field1C;
    void* field20;
    void* field24;
    void* field28;
    VCAppCComObject* Initialize(int);
};

VCAppCComObject* VCAppCComObject::Initialize(int)
{
    void* zero = 0;
    this->field28 = zero;
    this->field10 = zero;
    this->fieldC = zero;
    this->field8 = (void*)0x785288;
    this->field14 = (void*)0x7851d0;
    this->field18 = zero;
    this->field20 = zero;
    this->vfptr0 = (void*)0x7853b8;
    this->vfptr4 = (void*)0x7853a0;
    this->field8 = (void*)0x78537c;
    this->field14 = (void*)0x785364;
    this->field1C = (void*)0x785348;
    this->field24 = (void*)0x7852fc;
    void** global = (void**)0x8bae44;
    void* obj = *global;
    void** vtbl = (void**)obj;
    void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vtbl[1];
    fn(obj);
    return this;
}
