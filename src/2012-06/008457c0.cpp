// from server: 47% by Intel
struct std_string {
    char _buf[28];
};

extern "C" void __stdcall std_string_ctor_copy(std_string* this_ptr, const std_string* other);

struct VWaitScriptSlot {
    char pad0[28];
    std_string str1;
    char pad1[28];
    std_string str2;
    char pad2[4];
    unsigned char byte38;

    VWaitScriptSlot* ctor_copy(VWaitScriptSlot* other);
};

extern "C" void __stdcall unknown_call(void*);

VWaitScriptSlot* VWaitScriptSlot::ctor_copy(VWaitScriptSlot* other) {
    unknown_call(&str1);
    unknown_call(&other->str1);
    unknown_call(&str2);
    unknown_call(&other->str2);
    byte38 = other->byte38;
    return this;
}
