// from server: 100% by atomic.potato
extern "C" void __cdecl sub_787260();
extern "C" void __cdecl sub_80A058(void*);

struct AdvMoveTool
{
    int first;
    int second;
    AdvMoveTool(int);
};

AdvMoveTool::AdvMoveTool(int flag)
{
    first = 0xAB8C0C;
    second = 0xAB8BE4;
    sub_787260();
    if (flag & 1)
        sub_80A058(this);
}
