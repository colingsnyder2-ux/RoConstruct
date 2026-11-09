// from server: 100% by king_originala
struct Tool {
    void update();
};

struct CWebToolbox {
    char padding[0xF8];
    Tool* tool;

    void baseFunction(int a, int b, int c);
    void func_0046a6a0(int a, int b, int c);
};

void CWebToolbox::func_0046a6a0(int a, int b, int c)
{
    baseFunction(a, b, c);
    if (tool)
        tool->update();
}
