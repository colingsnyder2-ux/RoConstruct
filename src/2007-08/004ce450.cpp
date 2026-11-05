// from server: 100% by colin
struct View {
    void* field0;
    void* field4;
    void* field8;
    void construct(void* a, void* b, void* c);
};

extern "C" char __cdecl sub_4879D0(void*);
extern "C" void* __cdecl sub_62FEF6(unsigned int);

void View::construct(void* a, void* b, void* c)
{
    void* local[3];
    local[0] = a;
    local[1] = b;
    local[2] = c;

    if (!sub_4879D0(local)) {
        field8 = (void*)0x4D2D50;
        field0 = (void*)0x4CDB40;
        void* p = sub_62FEF6(0xC);
        if (p) {
            *(void**)p = local[0];
            *(void**)((char*)p + 4) = local[1];
            *(void**)((char*)p + 8) = local[2];
        }
        field4 = p;
    }
}
