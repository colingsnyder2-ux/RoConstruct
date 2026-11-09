// from server: 52% by atomic.potato
typedef void (__thiscall *Fn)(void);

extern "C" void __cdecl sub_664000(int);

struct CameraTiltUpCommand
{
    int pad0[3];
    int object;
    int pad1[70];
    Fn function;

    void f();
};

void CameraTiltUpCommand::f()
{
    int object = this->object;
    Fn function = *(Fn *)(*(int *)(object + 0x118) + 8);
    function();
    sub_664000(-1);
}
