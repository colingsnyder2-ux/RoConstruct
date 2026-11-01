// from server: 100% by colin
struct BodyThrust {
    void construct();
};

void BodyThrust::construct()
{
    *(int*)((char*)this + 0x00) = 0x7be764;
    *(int*)((char*)this + 0x04) = 0x7be75c;
    *(int*)((char*)this + 0x10) = 0x7be754;
    *(int*)((char*)this + 0x14) = 0x7be744;
    *(int*)((char*)this + 0x2c) = 0x7be734;
    *(int*)((char*)this + 0x44) = 0x7be724;
    *(int*)((char*)this + 0x5c) = 0x7be714;
    *(int*)((char*)this + 0x74) = 0x7be704;
    *(int*)((char*)this + 0x8c) = 0x7be6f4;
    *(int*)((char*)this + 0xe8) = 0x7be6dc;
    *(int*)((char*)this + 0xf0) = 0x7be6d0;
    extern void func_005eb650();
    func_005eb650();
}
