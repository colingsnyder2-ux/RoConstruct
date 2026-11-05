// from server: 100% by atomic.potato
extern "C" int __stdcall sub_785fd0(int, int);

struct ArrowTool {
    void f(int);
    unsigned char pad[0x1c];
    unsigned char value;
};

void ArrowTool::f(int a1)
{
    value = sub_785fd0(a1, 0xb98888) != 0;
}
