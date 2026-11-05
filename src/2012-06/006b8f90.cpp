// from server: 33% by atomic.potato
extern "C" void __stdcall sub_4015A0(int, int);
extern "C" void __stdcall sub_9831F5(int);

struct RBX_MD5HasherImpl {
    int field_0;
    void init();
};

void RBX_MD5HasherImpl::init()
{
    field_0 = 0;
    sub_4015A0(0x44d700, 0xe189c8);
    if ((*(unsigned char*)0xe189b8 & 1) != 0) {
        *(unsigned int*)0xe189b8 |= 1;
        *(unsigned int*)0xe189b0 = 0;
        *(unsigned int*)0xe189b4 = 0;
        sub_9831F5(0xb11b80);
    }
}
