// from server: 100% by tester
extern "C" void __cdecl sub_80B15D(int);

int dword_CB1734;
int dword_CB172C;
int dword_CB1730;

struct ICombinedSignalData
{
    void init();
};

void ICombinedSignalData::init()
{
    if (!(dword_CB1734 & 1))
    {
        dword_CB1734 |= 1;
        dword_CB172C = 0;
        dword_CB1730 = 0;
        sub_80B15D(0xA30290);
    }
}
