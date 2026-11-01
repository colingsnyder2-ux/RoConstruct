// from server: 82% by atomic.potato
struct Joint {
    char pad[0xb4];
    void* field_b4;
    void set(int arg);
};

extern "C" void* __stdcall sub_80b2ea(void* a, int b, int c, int d, int e);
extern "C" void __stdcall sub_411f60(void* a, int b);

void Joint::set(int arg)
{
    void* p1 = sub_80b2ea(this->field_b4, 0, 0xc5b974, 0xc6fda4, 0);
    void* p2 = sub_80b2ea(this->field_b4, 0, 0xc5b974, 0xc6fe8c, 0);
    if (p1 != 0) {
        if (arg != *(int*)((char*)p1 + 0x98)) {
            *(int*)((char*)p1 + 0x98) = arg;
            sub_411f60(this, 0xcd1628);
        }
    } else if (p2 != 0) {
        if (arg != *(int*)((char*)p2 + 0x100)) {
            *(int*)((char*)p2 + 0x100) = arg;
            sub_411f60(this, 0xcd1628);
        }
    }
}
