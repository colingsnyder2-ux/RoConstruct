// from server: 100% by Intel
extern "C" void __stdcall SetGridToOne(int);

void __stdcall SetGridToOne(int)
{
    int* ptr = (int*)0x00E52558;
    *ptr = 0;
}
