// from server: 70% by colin
struct CXTIconHandle {
    int field0;
    int field4;
    int field8;
    int fieldC;
    char pad10[0x10];
    int field20;
    int field24;
    int field28;
    int field2C;

    CXTIconHandle();
};

extern "C" int __stdcall sub_4018B0(int);
extern "C" int __stdcall sub_4018D0(int);

extern unsigned char g_8bbe98;

CXTIconHandle::CXTIconHandle()
{
    sub_4018B0((int)(this->pad10));
    this->field0 = 0;
    this->field4 = 0x400000;
    this->field8 = 0x877704;
    this->fieldC = 0x877718;
    if (sub_4018D0((int)(this->pad10)) < 0)
    {
        g_8bbe98 = 1;
    }
    else
    {
        this->field0 = 0x28;
    }
}
