// from server: 54% by atomic.potato
struct CRobloxApp
{
    void f(int, int);
};

extern "C" void __declspec(nothrow) __fastcall call_423950(void*, int, int);

void CRobloxApp::f(int a, int b)
{
    char* p = reinterpret_cast<char*>(this) + 0xa4;
    call_423950(p, a, b);
}
