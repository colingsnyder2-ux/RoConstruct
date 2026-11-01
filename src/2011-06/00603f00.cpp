// from server: 100% by tester
extern "C" void __stdcall SetGridToOne(int);

void __stdcall SetGridToOne(int)
{
    int* ptr = (int*)0xcd51d0;
    *ptr = 0;
}