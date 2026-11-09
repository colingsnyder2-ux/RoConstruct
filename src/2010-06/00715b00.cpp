// from server: 65% by atomic.potato
struct GeoPairConnector {
    void* vtable;
    int field_4;
    char pad_8[0x1c];
    int field_24;
    int field_28;
    char pad_2c[0x10];
    int field_3c;
    int field_40;
    int field_44;
    float field_48;
    float field_4c;
    float field_50;
    float field_54;
    float field_58;
    float field_5c;
    GeoPairConnector(int, int, int*);
};

extern "C" void __stdcall sub_778d70(void*);

GeoPairConnector::GeoPairConnector(int a, int b, int* c) {
    this->field_4 = -1;
    this->vtable = (void*)0xa4c96c;
    sub_778d70(&this->pad_8[0]);
    this->field_3c = c[0];
    this->field_40 = c[1];
    this->field_44 = c[2];
    this->field_54 = 0.0f;
    this->field_58 = 0.0f;
    this->field_5c = 0.0f;
    this->field_24 = a;
    this->field_28 = b;
    this->field_48 = 0.0f;
    this->field_4c = 0.0f;
    this->field_50 = 0.0f;
    this->vtable = (void*)0xa4c9ac;
}
