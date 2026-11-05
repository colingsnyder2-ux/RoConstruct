// from server: 39% by atomic.potato
struct S_func_00408d80 {
    char pad0[0x20];
    void* field20;
    char pad24[0x04];
    void* field28;
    char pad2c[0x18];
    void* field44;
    ~S_func_00408d80();
};

extern "C" void __stdcall sub_9ea400(void*);
extern "C" void __stdcall sub_795310(void*);

S_func_00408d80::~S_func_00408d80()
{
    sub_9ea400(&field44);
    sub_9ea400(&field28);
    sub_795310(&field20);
    sub_9ea400(this);
}
