// from server: 100% by atomic.potato
struct ClientPhysics {
    char pad[8];
    double field_8;
    void method_4b8310();
    void method_4b8400(int, int, int);
};

extern "C" double __fastcall func_004fff30(void*);
extern "C" void* __fastcall func_00498f60();

void ClientPhysics::method_4b8400(int a1, int a2, int a3)
{
    double d = func_004fff30(this);
    void* p = func_00498f60();
    float f = *(float*)((char*)p + 0xf0);
    if ((double)f + field_8 < d) {
        method_4b8310();
    }
}
