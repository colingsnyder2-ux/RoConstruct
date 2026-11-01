// from server: 100% by king_originala
struct Tool {
    void update();
};

struct CWebToolbox {
    char padding[0xf8];
    Tool* tool;

    void prepare();
    void f(int, int, int);
};

void CWebToolbox::f(int, int, int)
{
    prepare();
    if (tool)
        tool->update();
}
