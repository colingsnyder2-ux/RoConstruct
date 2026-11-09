// from server: 100% by tajop
struct PrimaryControllerCommand {
    virtual void v0();
    virtual void v1(int);
    int field4;
    void method_5621B0(int);
    void method_4108B0(int);
    void func(int);
};

void PrimaryControllerCommand::func(int arg)
{
    method_5621B0(1);
    PrimaryControllerCommand* self = (PrimaryControllerCommand*)arg;
    self->method_4108B0(-1);
    self->field4 = -1;
    self->v1(1);
}
