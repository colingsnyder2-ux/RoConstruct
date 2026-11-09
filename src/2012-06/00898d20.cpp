// from server: 100% by tester
extern "C" void __stdcall sub_8988C0();

void __stdcall sub_898D20(int arg)
{
    *(volatile char*)0x00E5255C = 1;
    sub_8988C0();
}
