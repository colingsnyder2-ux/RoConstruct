// from server: 61% by atomic.potato
struct LeftMotorTool
{
    int SetSomething(unsigned char value, int);
};

int LeftMotorTool::SetSomething(unsigned char value, int)
{
    *(int*)this = 0xAB9340;
    *((unsigned char*)this + 0x1C) = value;
    return (int)this;
}
