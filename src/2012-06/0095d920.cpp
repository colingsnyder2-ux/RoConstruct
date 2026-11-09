// from server: 94% by Intel
struct Climbing {
    void func_00903fd0();
    int func_009001b0();
    void func_00900f50(int*);
    void func_00903f50(int, float);

    void func_0095d920();
};

void Climbing::func_0095d920()
{
    int local[3];
    func_00903fd0();
    int result = func_009001b0();
    func_00900f50(local);
    float value = *(float*)((char*)local + 4);
    func_00903f50(result + 0x29c, value);
}
