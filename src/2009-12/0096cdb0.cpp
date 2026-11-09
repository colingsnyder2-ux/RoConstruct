// from server: 100% by sophus
struct Callee
{
    void __thiscall invoke(int, const void *, const void *, const void *, int);
};

extern "C" void func_007f4929(const void *);

extern const char global_009bbf08;
extern const char global_009bbf1c;
extern const char global_009bbf24;
extern const char global_009800e0;

void func_0096cdb0()
{
    ((Callee *)0x00b7fd70)->invoke(0x140, &global_009bbf08, &global_009bbf1c,
                                   &global_009bbf24, 1);
    func_007f4929(&global_009800e0);
}
