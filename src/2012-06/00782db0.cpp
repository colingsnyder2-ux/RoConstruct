// from server: 39% by atomic.potato
extern "C" int __stdcall sub_4125d0(int);
extern "C" int __stdcall sub_6cab60(int, int);
extern "C" int __stdcall sub_9831f5(int);

extern int dword_BC0BB4;
extern int dword_E47DE4;
extern int dword_E47C00;

void func_00782db0()
{
    if ((dword_E47DE4 & 1) == 0)
    {
        dword_E47DE4 |= 1;
        char buf[12];
        buf[0] = 0;
        buf[1] = 0;
        *(int*)(buf + 4) = 0;
        *(int*)(buf + 8) = 0x1b;
        int v = sub_4125d0(dword_BC0BB4);
        sub_6cab60(v, (int)buf);
        sub_9831f5(0xb1ac10);
    }
}
