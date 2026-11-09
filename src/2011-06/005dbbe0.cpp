// from server: 78% by atomic.potato
extern "C" void __cdecl sub_80B15D();

unsigned char g_33C0CC;
unsigned int g_CCA2C4;
unsigned int g_CCA2C8;

void sub_5DBBE0(unsigned int value)
{
    g_33C0CC = (unsigned char)value;
    g_CCA2C4 = value;
    g_CCA2C8 = value;
    sub_80B15D();
}
