// from server: 100% by atomic.potato
extern "C" void __cdecl func_007f4394();

struct S
{
    S();
};

S::S()
{
    func_007f4394();
    *(int*)this = 0x9b077c;
    *((char*)this + 0xf4) = 0;
}
