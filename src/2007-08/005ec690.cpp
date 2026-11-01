// from server: 100% by colin
struct S_005ec690 {
    char pad[0x100];
    void ctor();
};

void S_005ec690::ctor()
{
    *(int*)((char*)this + 0x00) = 0x7be844;
    *(int*)((char*)this + 0x04) = 0x7be83c;
    *(int*)((char*)this + 0x10) = 0x7be834;
    *(int*)((char*)this + 0x14) = 0x7be824;
    *(int*)((char*)this + 0x2c) = 0x7be814;
    *(int*)((char*)this + 0x44) = 0x7be804;
    *(int*)((char*)this + 0x5c) = 0x7be7f4;
    *(int*)((char*)this + 0x74) = 0x7be7e4;
    *(int*)((char*)this + 0x8c) = 0x7be7d4;
    *(int*)((char*)this + 0xe8) = 0x7be7bc;
    *(int*)((char*)this + 0xf0) = 0x7be7b0;
    extern void __stdcall sub_005eb650();
    sub_005eb650();
}
