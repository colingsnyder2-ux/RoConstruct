// from server: 51% by atomic.potato
extern "C" int __cdecl sub_8677E0(void*);
extern "C" void __cdecl sub_5C9FE8(int, int, void*);

extern unsigned char g_byte_E31AA5;

struct LockTool {
    void* vfptr0;
    void* vfptr1;
    char pad[0x2C];
    int field34;
    int field38;
    void ctor(void* arg);
};

void LockTool::ctor(void* arg)
{
    sub_8677E0(arg);
    this->vfptr0 = (void*)0xC00664;
    this->vfptr1 = (void*)0xC00634;
    this->field34 = 0;
    this->field38 = 0;
    unsigned char al = g_byte_E31AA5;
    if (al != 0)
        sub_5C9FE8((int)al, 0xC006F4, this);
}
