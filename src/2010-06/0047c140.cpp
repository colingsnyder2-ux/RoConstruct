// from server: 100% by atomic.potato
extern "C" int __stdcall sub_007a7d4e(void*);

struct CWebToolbox
{
    int field_0;
    int field_4;
    void func_0047c140(void*);
};

void CWebToolbox::func_0047c140(void* arg)
{
    if (sub_007a7d4e(arg) == 0)
        ((CWebToolbox*)arg)->field_4 |= 0x01844017;
}
