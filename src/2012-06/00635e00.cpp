// from server: 73% by Intel
struct std_string {
    void* _vftable;
    char _data[28];
};

extern "C" void __stdcall std_string_ctor_copy(std_string* this_ptr, const std_string* other);

struct TokenException {
    void* vftable;
    char padding[0x1c];
    unsigned char field_1c;
    int field_20;
    int field_24;
    int field_28;
    int field_2c;
    int field_30;
    int field_34;

    TokenException* ctor_copy(TokenException* other);
};

TokenException* TokenException::ctor_copy(TokenException* other) {
    std_string_ctor_copy(reinterpret_cast<std_string*>(this), reinterpret_cast<const std_string*>(other));
    field_1c = other->field_1c;
    field_20 = other->field_20;
    field_24 = other->field_24;
    field_28 = other->field_28;
    field_2c = other->field_2c;
    field_30 = other->field_30;
    field_34 = other->field_34;
    return this;
}
