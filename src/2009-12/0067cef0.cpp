// from server: 100% by atomic.potato
struct ResultObj {
    char pad[0xa8];
    int value;
};

struct Helper {
    ResultObj* get(int flag);
};

struct Outer {
    char pad[0xc];
    int fieldC;
    Helper helper;
    int RunCommand();
};

extern "C" char __cdecl sub_5123A0(int, int);

int Outer::RunCommand()
{
    int v = this->helper.get(1)->value;
    if (sub_5123A0(this->fieldC, 1) == 0 && v != 1) {
        return 1;
    }
    return 0;
}
