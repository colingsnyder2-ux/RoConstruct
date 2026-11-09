// from server: 100% by why2
struct PartInstance {
    char pad[0x118];
    void* field_118;
    void* getSomething();
};

extern "C" void* __fastcall sub_670f10(void* p);

void* PartInstance::getSomething() {
    void* p = sub_670f10(field_118);
    return (char*)p + 0x24;
}
