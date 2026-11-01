// from server: 29% by Intel
struct EnumDesc
{
    void Initialize();
};

extern "C" void __stdcall func_004125d0(int);
extern "C" void __stdcall func_006cab60(int, int);
extern "C" void __stdcall func_009831f5(int);

int dword_BE640C;
int dword_E3BB78;
char byte_E3BD5C;

void EnumDesc::Initialize()
{
    int v1 = 1;
    if (!byte_E3BD5C)
    {
        byte_E3BD5C = 1;
        char buffer[16] = {0};
        *(int*)(buffer + 8) = 27;
        func_004125d0(dword_BE640C);
        func_006cab60(dword_E3BB78, 0);
        func_009831f5(0xB1B260);
    }
}
