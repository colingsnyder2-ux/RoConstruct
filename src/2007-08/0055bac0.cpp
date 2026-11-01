// from server: 44% by colin
struct RBXName {
    static const RBXName& declare(const char*);
};

struct CreatorBase {
    virtual void v0();
    virtual void v1();
};

struct Creator : CreatorBase {
    int field4;
    int field8;
    Creator();
};

extern "C" void __stdcall sub_4108B0(int);
extern "C" void __fastcall sub_5598A0(void*);

extern const char sClassName[];
extern int g_isConstructed;

Creator::Creator()
{
    field4 = -1;
    field8 = -1;
    sub_4108B0(-1);
    sub_5598A0(&field8);
}
