// from server: 100% by colin
struct Texture {
    void* field0;
    void* field4;
    void* field8;
    void construct(void* a, void* b, void* c);
};

extern "C" char __cdecl sub_4879D0(void*);
extern "C" void* __cdecl sub_62FEF6(unsigned int);

void Texture::construct(void* a, void* b, void* c)
{
    void* local[3];
    local[0] = a;
    local[1] = b;
    local[2] = c;

    if (sub_4879D0(local) == 0) {
        this->field8 = (void*)0x4d2d50;
        this->field0 = (void*)0x4d2530;
        void* p = sub_62FEF6(0xc);
        if (p != 0) {
            *(void**)p = local[0];
            *(void**)((char*)p + 4) = local[1];
            *(void**)((char*)p + 8) = local[2];
        }
        this->field4 = p;
    }
}
