// from server: 100% by colin
struct Accoutrement {
    char pad[0x100];
    void construct();
};

extern void func_00581310();

void Accoutrement::construct()
{
    int* p = *(int**)((char*)this + 0xf8);
    *(int*)((char*)this + 0x00) = 0x7ac2ac;
    *(int*)((char*)this + 0x04) = 0x7ac2a4;
    *(int*)((char*)this + 0x10) = 0x7ac29c;
    *(int*)((char*)this + 0x14) = 0x7ac28c;
    *(int*)((char*)this + 0x2c) = 0x7ac27c;
    *(int*)((char*)this + 0x44) = 0x7ac26c;
    *(int*)((char*)this + 0x5c) = 0x7ac25c;
    *(int*)((char*)this + 0x74) = 0x7ac24c;
    *(int*)((char*)this + 0x8c) = 0x7ac23c;
    *(int*)((char*)this + 0xe8) = 0x7ac224;
    int* q = *(int**)((char*)p + 4);
    *(int*)((char*)this + (int)q + 0xf8) = 0x7ac21c;
    int* r = *(int**)((char*)this + 0xf8);
    int* s = *(int**)((char*)r + 4);
    *(int*)((char*)this + (int)s + 0xf4) = (int)s - 0x84;
    func_00581310();
}
