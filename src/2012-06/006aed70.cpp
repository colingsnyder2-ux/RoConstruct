// from server: 32% by Intel
typedef unsigned int DWORD;

extern "C" int __cdecl sub_534590(void *, void *, void *);
extern "C" void __cdecl sub_6AEDD0(void *, void *, void *, void *, void *);

struct BoundFuncDesc
{
    char padding[0x30];
    void *field30;
    void *field34;
    void *field38;
    void invoke(void *, void *);
};

void BoundFuncDesc::invoke(void *a, void *b)
{
    void *p = a ? static_cast<char *>(a) - 0x1c : 0;
    char result = static_cast<char>(sub_534590(p, field38, b));
    void *arg1 = b ? static_cast<char *>(b) + 4 : 0;
    void *arg2 = b ? static_cast<char *>(b) - 0x1c : 0;
    sub_6AEDD0(field30, field34, arg1, arg2, &result);
}
