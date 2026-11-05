// from server: 100% by colin
struct CXTPCommandBars {
    char pad[0xa0];
    void* m_p;
    int Func(int, int, int);
};

struct SubA {
    int Method(void*, int);
};

extern "C" int __stdcall sub_6A29D0(void*, void*, int);
extern "C" int __stdcall sub_6A0FF0(void*);

int CXTPCommandBars::Func(int a2, int a3, int a4)
{
    void* p = m_p;
    int r = (*(int (__thiscall**)(int, void*, int))(*(int*)a2 + 0x1f4))(a2, p, 0);
    if (r == 0)
        return 0;
    ((SubA*)a4)->Method((void*)a2, a3);
    int v = ((int (__thiscall*)(void*))sub_6A0FF0)((void*)a4);
    *(int*)((char*)a2 + 0xfc) = v;
    return 1;
}
