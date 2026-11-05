// from server: 65% by colin
struct CXTTreeBase
{
    int Get(int index);
    int getValue();
};

struct CXTPTabPaintManager_CColorSetWhidbey
{
    char pad_0000[4];
    char field_0004[0x44];
    int field_0048;
    char pad_004c[0x50];
    int field_009c;
    char pad_00a0[0xb4];
    int field_0154;
    char pad_0158[0xc0];
    int field_0218;
    void construct();
};

extern "C" void* __cdecl sub_668f70();
extern "C" void __cdecl sub_668ec0(void*, int);
extern "C" int __cdecl sub_668770(void*, int);
extern "C" void __cdecl sub_71be90();

void CXTPTabPaintManager_CColorSetWhidbey::construct()
{
    CXTTreeBase* p = (CXTTreeBase*)sub_668f70();
    if (p == 0)
    {
        sub_71be90();
        return;
    }

    int v = p->getValue();
    if (v > 0)
    {
        if (v <= 2)
        {
            sub_668ec0((char*)this + 4, 0xd5e2e4);
            this->field_0218 = 1;
        }
        else if (v == 3)
        {
            this->field_009c = 0xf8f5f5;
            sub_668ec0((char*)this + 4, 0xeeeeee);
            this->field_0218 = 1;
        }
    }

    CXTTreeBase* p2 = (CXTTreeBase*)sub_668f70();
    this->field_0154 = sub_668770(p2, 0x39);

    CXTTreeBase* p3 = (CXTTreeBase*)sub_668f70();
    this->field_0048 = sub_668770(p3, 0x39);
}
