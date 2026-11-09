// from server: 46% by colin
struct VDHTMLWindow_BoundFuncDesc
{
    char pad0[0x28];
    int field28;
    int field2c;
    char field30[0x08];
    char field38[0x08];
    char field40[0x08];

    VDHTMLWindow_BoundFuncDesc(int a, int b, int c, int d, int e, int f, int g);
};

extern "C" int __cdecl sub_419110(int a, int b);
extern "C" int __stdcall sub_570DB0(int a);
extern "C" int __stdcall sub_56D3C0(void* p);
extern "C" int __stdcall sub_4138A0(int a, int b, int c);

VDHTMLWindow_BoundFuncDesc::VDHTMLWindow_BoundFuncDesc(int a, int b, int c, int d, int e, int f, int g)
{
    int r = sub_419110(d, e);
    sub_570DB0(r);
    field28 = f;
    field2c = g;
    sub_56D3C0(&field30);
    sub_56D3C0(&field38);
    sub_56D3C0(&field40);
    sub_4138A0(a, b, c);
}
