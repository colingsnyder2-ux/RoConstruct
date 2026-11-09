// from server: 59% by atomic.potato
struct SimpleThrottlingArbiter {
    char pad0[0x828];
    unsigned char flag828;
    char pad1[3];
    char pad2[0x82c - 0x829];
    char field82c;
    bool check();
};

extern "C" int __stdcall sub_97c280(void* a, int b);
extern "C" int __stdcall sub_97c260(void* a);
extern "C" void* __stdcall sub_9776b0();
extern "C" void __fastcall sub_6d4530(SimpleThrottlingArbiter* self);

extern unsigned char byte_e581b0;
extern int dword_e581ac;
extern double qword_b4fd78;
extern double qword_b68828;

bool SimpleThrottlingArbiter::check()
{
    if (byte_e581b0 == 0)
        return false;
    int n = dword_e581ac;
    if (n <= 1)
        return false;
    if (sub_97c280(&field82c, 1) != 0)
        return flag828 != 0;
    int v = *(int*)((char*)sub_9776b0() + 0x1ac);
    double d = (double)v;
    if (v < 0)
        d += qword_b4fd78;
    d /= (double)n;
    if (flag828 != 0) {
        sub_6d4530(this);
    } else {
        sub_6d4530(this);
        d *= qword_b68828;
    }
    bool r;
    if (d < (double)n)
        r = false;
    else
        r = true;
    flag828 = r ? 1 : 0;
    sub_97c260(&field82c);
    return flag828 != 0;
}
