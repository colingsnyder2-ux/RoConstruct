// from server: 71% by atomic.potato
struct TexturePtr {
    void operator=(const TexturePtr&);
};

struct ManualObject {
    char pad0[0x10];
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    char field24;
    ManualObject* assign(const ManualObject* other);
};

extern "C" void* __stdcall sub_b230b0(void*);

ManualObject* ManualObject::assign(const ManualObject* other) {
    sub_b230b0((void*)&field10);
    field10 = other->field10;
    field14 = other->field14;
    field18 = other->field18;
    field1c = other->field1c;
    field20 = other->field20;
    field24 = other->field24;
    return this;
}
