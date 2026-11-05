// from server: 100% by colin
struct Server {
    char pad[0x8c];
    int field_8c;
    char pad2[0x58];
    int field_e8;
    int field_ec;
    void init();
    Server();
};

extern "C" void __fastcall sub_49e520(Server* self);

Server::Server()
{
    sub_49e520(this);
    *(int*)((char*)this + 0x00) = 0x79cb74;
    *(int*)((char*)this + 0x04) = 0x79cb68;
    *(int*)((char*)this + 0x10) = 0x79cb60;
    *(int*)((char*)this + 0x14) = 0x79cb50;
    *(int*)((char*)this + 0x2c) = 0x79cb40;
    *(int*)((char*)this + 0x44) = 0x79cb30;
    *(int*)((char*)this + 0x5c) = 0x79cb20;
    *(int*)((char*)this + 0x74) = 0x79cb10;
    *(int*)((char*)this + 0x8c) = 0x79cb00;
    *(int*)((char*)this + 0xe8) = 0x79cad0;
    *(int*)((char*)this + 0xec) = 0x79cac4;
}
