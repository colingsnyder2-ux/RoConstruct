// from server: 100% by colin
struct VPartInstance {
    char pad[0x1d8];
    void* field_1d8;
    void sub_573D60();
};

struct Helper {
    void sub_5A9B00(void*);
};

extern "C" void* __cdecl sub_57D530(void*);

void VPartInstance::sub_573D60()
{
    void* p = sub_57D530(this);
    if (p) {
        ((Helper*)p)->sub_5A9B00(this->field_1d8);
    }
}
