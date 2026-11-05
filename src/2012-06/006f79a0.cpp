// from server: 56% by atomic.potato
typedef unsigned int DWORD;

struct BasicString
{
    BasicString(const char *);
};

extern "C" void __stdcall ClearStarterpackHelper(void *, BasicString *);

struct ClearStarterpack
{
    int f(int);
};

int ClearStarterpack::f(int value)
{
    BasicString text("Gui:SelectChildrenOfSelection");
    ClearStarterpackHelper(this, &text);
    *(DWORD *)this = 0xB9C680;
    return (int)this;
}
