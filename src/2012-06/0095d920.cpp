// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Vector3 { float x, y, z; };
struct Climbing {
    void func_00903fd0();
    int func_009001b0();
    Vector3 func_00900f50();
    void func_00903f50(int, float);
    void func_0095d920();
};
void Climbing::func_0095d920()
{
    func_00903fd0();
    int result = func_009001b0();
    func_00903f50(result + 0x29c, func_00900f50().y);
}
