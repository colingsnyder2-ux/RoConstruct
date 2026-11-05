// from server: 100% by colin
struct S_func_005ec880 {
    char pad[0x100];
    void construct();
};

void S_func_005ec880::construct()
{
    *(int*)((char*)this + 0x00) = 0x7bebc4;
    *(int*)((char*)this + 0x04) = 0x7bebbc;
    *(int*)((char*)this + 0x10) = 0x7bebb4;
    *(int*)((char*)this + 0x14) = 0x7beba4;
    *(int*)((char*)this + 0x2c) = 0x7beb94;
    *(int*)((char*)this + 0x44) = 0x7beb84;
    *(int*)((char*)this + 0x5c) = 0x7beb74;
    *(int*)((char*)this + 0x74) = 0x7beb64;
    *(int*)((char*)this + 0x8c) = 0x7beb54;
    *(int*)((char*)this + 0xe8) = 0x7beb3c;
    *(int*)((char*)this + 0xf0) = 0x7beb30;
    extern void __fastcall sub_005eb650(void*);
    sub_005eb650(this);
}
