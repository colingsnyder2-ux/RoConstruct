// from server: 100% by atomic.potato
struct CMainFrame
{
    char pad_0000[0x104];
    unsigned char field_0104;
    unsigned char field_0105;
    unsigned char field_0106;
    void method_009826de();
    void func_00435ac0(void* arg);
};

void CMainFrame::func_00435ac0(void* arg)
{
    this->method_009826de();
    if (this->field_0104 != 0 && this->field_0106 == 0)
    {
        *(unsigned int*)((char*)arg + 0x18) |= 3;
    }
}
