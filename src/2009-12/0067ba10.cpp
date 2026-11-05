// from server: 56% by atomic.potato
typedef unsigned long DWORD;

extern "C" DWORD sub_67acd0(DWORD, unsigned long);
extern "C" DWORD sub_6bad70(DWORD);

struct CameraVerb
{
    DWORD value;
    int f(DWORD arg);
};

int CameraVerb::f(DWORD arg)
{
    DWORD value = sub_67acd0(*(DWORD *)((char *)this + 0x0c), 0x0b);
    sub_6bad70(value);
    *(DWORD *)arg = 1;
    return ((int (**)(DWORD))(*(DWORD **)arg))[0](arg);
}
