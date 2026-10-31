// from server: 100% by Intel
struct VCornerWedgeInstance
{
    int Initialize(int a1);
};

extern "C" int __stdcall sub_7B53A0(int);

int VCornerWedgeInstance::Initialize(int a1)
{
    if (a1)
    {
        *(int *)((char *)this + 0x84) = 0xBB8D40;
        *(int *)((char *)this + 0xB8) = 0xBBF218;
    }
    sub_7B53A0(0);
    int v2 = *(int *)((char *)this + 0x84);
    *(int *)this = 0xBE7324;
    *(int *)((char *)this + 4) = 0xBE7318;
    *(int *)((char *)this + 0x18) = 0xBE730C;
    *(int *)((char *)this + 0x1C) = 0xBE7300;
    *(int *)((char *)this + 0x80) = 0xBE72F8;
    *(int *)((char *)this + 0x90) = 0xBE72E0;
    *(int *)((char *)this + 0x9C) = 0xBE72B4;
    *(int *)((char *)this + 0xB4) = 0xBE7288;
    *(int *)((char *)this + 0xC8) = 0xBE7280;
    int v3 = *(int *)(v2 + 4);
    *(int *)((char *)this + v3 + 0x84) = 0xBE7278;
    int v4 = *(int *)((char *)this + 0x84);
    int v5 = *(int *)(v4 + 4);
    *(int *)((char *)this + v5 + 0x80) = v5 - 0x250;
    return (int)this;
}
