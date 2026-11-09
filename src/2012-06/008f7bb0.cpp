// from server: 27% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_00b22648();
extern "C" void __stdcall sub_00b2263c();

extern void __cdecl sub_00428540(void *);
extern void __cdecl sub_004bb290();
extern void __cdecl sub_004c43a0();
extern void __cdecl sub_00684840();
extern void __cdecl sub_008f6ee0();
extern void __cdecl sub_008f78c0();
extern void __cdecl sub_008f78f0();
extern void __cdecl sub_00973130();

struct VAnimationTrack_EventDesc
{
    void *vptr0;
    void *vptr1;
    char pad_08[0x10];
    void *vptr18;
    void *vptr1c;
    char pad_20[0x60];
    unsigned char flag61;
    char pad_62[0x1e];
    int field80;
    int field84;
    int field88;
    int field8c;
    int field90;
    char pad_94[0x4];
    int field94;
    int field98;
    int field9c;
};

void __stdcall VAnimationTrack_EventDesc_ctor(VAnimationTrack_EventDesc *self, int a2, int a3, int a4, int a5)
{
    self->vptr0 = (void *)0xbf0454;
    self->vptr1 = (void *)0xbf044c;
    self->vptr18 = (void *)0xbf0440;
    self->vptr1c = (void *)0xbf0434;
    self->field80 = a2;
    self->field84 = a3;
    if (a3)
    {
        _InterlockedExchangeAdd((volatile long *)(a3 + 4), 1);
    }
    self->field88 = a4;
    self->field8c = a5;
    if (a5)
    {
        _InterlockedExchangeAdd((volatile long *)(a5 + 8), 1);
    }
    self->field90 = 0;
    sub_004bb290();
    sub_004c43a0();
    sub_00b22648();
    sub_00684840();
    sub_00b2263c();
    sub_008f78c0();
    sub_00973130();
    if (self->field90)
    {
        sub_00428540((void *)(self->field90 + 5));
    }
    self->flag61 = 1;
    if (a3)
    {
        if (_InterlockedExchangeAdd((volatile long *)(a3 + 4), -1) == 1)
        {
            (*(void (__thiscall **)(void *))(*(int *)a3 + 4))(self);
            if (_InterlockedExchangeAdd((volatile long *)(a3 + 8), -1) == 1)
            {
                (*(void (__thiscall **)(void *))(*(int *)a3 + 8))(self);
            }
        }
    }
    if (a5)
    {
        if (_InterlockedExchangeAdd((volatile long *)(a5 + 8), -1) == 1)
        {
            (*(void (__thiscall **)(void *))(*(int *)a5 + 8))(self);
        }
    }
}
