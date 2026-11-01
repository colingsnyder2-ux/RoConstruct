// from server: 100% by tester
struct lua_exception {
    void* vfptr;
    char pad[8];
    int field_c;
    int field_10;
    char field_14;
    lua_exception* construct(lua_exception* other);
};

extern "C" void (__stdcall *sub_77e6f8)();

lua_exception* lua_exception::construct(lua_exception* other)
{
    sub_77e6f8();
    this->vfptr = (void*)0x7b967c;
    this->field_c = other->field_c;
    this->field_10 = other->field_10;
    this->field_14 = other->field_14;
    other->field_14 = 1;
    return this;
}
