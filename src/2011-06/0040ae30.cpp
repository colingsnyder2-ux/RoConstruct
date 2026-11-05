// from server: 100% by atomic.potato
extern "C" void __cdecl sub_80B15D(int);

int dword_CB1728;
int dword_CB1720;
int dword_CB1724;

void function_0040AE30()
{
    if (!(dword_CB1728 & 1))
    {
        dword_CB1728 |= 1;
        dword_CB1720 = 0;
        dword_CB1724 = 0;
        sub_80B15D(0xA302D0);
    }
}
