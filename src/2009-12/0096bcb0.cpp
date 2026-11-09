// from server: 100% by sophus
struct Callee
{
    void __thiscall invoke(unsigned int, const void *, const void *, const void *, int);
};

extern "C" void func_007f4929(const void *);

extern const char global_009bb0fc;
extern const char global_009bb104;
extern const char global_009bb10c;
extern const char global_0097f8b0;

void func_0096bcb0()
{
    ((Callee *)0x00b7e6e0)->invoke(0x120, &global_009bb0fc,
                                   &global_009bb104, &global_009bb10c, 1);
    func_007f4929(&global_0097f8b0);
}
