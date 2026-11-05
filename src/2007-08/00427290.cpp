// from server: 100% by colin
struct VMember
{
    void base_init();
    int f();
};

int VMember::f()
{
    base_init();
    *(int*)((char*)this + 0x00) = 0x789e9c;
    *(int*)((char*)this + 0x04) = 0x789e94;
    *(int*)((char*)this + 0x10) = 0x789e8c;
    *(int*)((char*)this + 0x14) = 0x789e7c;
    *(int*)((char*)this + 0x2c) = 0x789e6c;
    *(int*)((char*)this + 0x44) = 0x789e5c;
    *(int*)((char*)this + 0x5c) = 0x789e4c;
    *(int*)((char*)this + 0x74) = 0x789e3c;
    *(int*)((char*)this + 0x8c) = 0x789e2c;
    *(int*)((char*)this + 0x108) = -1;
    *(int*)((char*)this + 0x10c) = 0;
    return (int)this;
}
