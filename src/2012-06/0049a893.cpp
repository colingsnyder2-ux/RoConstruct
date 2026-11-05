// from server: 52% by atomic.potato
extern "C" int __cdecl sub_431560();
extern "C" int __cdecl sub_4321f0(int);
extern "C" int __cdecl sub_983144(int, int);

struct CRobloxWnd
{
    int RenderJob();
};

int CRobloxWnd::RenderJob()
{
    int value = sub_431560();
    sub_4321f0(value);
    return sub_983144(0, 0);
}
