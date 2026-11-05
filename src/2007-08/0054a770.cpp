// from server: 100% by colin
struct ServiceProvider {
    ServiceProvider* construct();
};

extern void func_0054a690();

ServiceProvider* ServiceProvider::construct()
{
    func_0054a690();
    *(int*)((char*)this + 0x00) = 0x7a76dc;
    *(int*)((char*)this + 0x04) = 0x7a76d4;
    *(int*)((char*)this + 0x10) = 0x7a76cc;
    *(int*)((char*)this + 0x14) = 0x7a76bc;
    *(int*)((char*)this + 0x2c) = 0x7a76ac;
    *(int*)((char*)this + 0x44) = 0x7a769c;
    *(int*)((char*)this + 0x5c) = 0x7a768c;
    *(int*)((char*)this + 0x74) = 0x7a767c;
    *(int*)((char*)this + 0x8c) = 0x7a766c;
    *(int*)((char*)this + 0xe8) = 0x7a765c;
    *(int*)((char*)this + 0x100) = 0x7a764c;
    *(int*)((char*)this + 0x118) = 0x7a763c;
    return this;
}
