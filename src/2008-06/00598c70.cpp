// from server: 100% by king_originala
struct S;

struct Receiver
{
    void func_005ea4c0(unsigned int value);
};

extern Receiver* __cdecl func_005a3390(S* object);

struct S
{
    void func_00598c70();
};

void S::func_00598c70()
{
    Receiver* receiver = func_005a3390(this);
    if (receiver)
        receiver->func_005ea4c0(
            reinterpret_cast<unsigned int>(reinterpret_cast<char*>(this) + 0x228));
}
