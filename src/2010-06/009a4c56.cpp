// from server: 78% by atomic.potato
extern "C" void __stdcall func_007a8ade(void*, int, int, const char*);

struct seg_009a0000
{
    void func_009a4c56();
};

void seg_009a0000::func_009a4c56()
{
    func_007a8ade((char*)this + 0xdc, 0x1c, 2, "SUVW");
}
