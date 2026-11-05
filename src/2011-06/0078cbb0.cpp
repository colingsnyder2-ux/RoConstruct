// from server: 60% by atomic.potato
struct FlatTool
{
    int data;
    void value();
};

extern "C" void __cdecl sub_66C7E0(int);
extern "C" void __cdecl sub_75EBB0(FlatTool *);
extern "C" void __cdecl sub_66C800(int);

void FlatTool::value()
{
    FlatTool *p = this;
    sub_66C7E0(p->data);
    sub_75EBB0(p);
    sub_66C800(p->data);
}
