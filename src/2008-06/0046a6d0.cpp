// from server: 100% by king_originala
struct Child
{
    void update();
};

struct CWebToolbox
{
    char padding[0xF8];
    Child* child;

    void baseCall(int value);
    void func_0046a6d0(int value);
};

void CWebToolbox::func_0046a6d0(int value)
{
    baseCall(value);
    if (child)
        child->update();
}
