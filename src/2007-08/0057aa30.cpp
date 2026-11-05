// from server: 100% by colin
struct ArrowTool {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void doAction();
    int wrapper(int);
};

int ArrowTool::wrapper(int value)
{
    doAction();
    return 0;
}
