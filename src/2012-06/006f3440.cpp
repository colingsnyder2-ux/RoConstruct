// from server: 100% by tester
extern "C" void __stdcall SetGridToOne(int);

void __stdcall SetGridToOne(int)
{
    int* ptr = (int*)0xde92ec;
    *ptr = 0;
}