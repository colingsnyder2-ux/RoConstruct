// from server: 100% by colin
struct RBX_Network_Client
{
    RBX_Network_Client* construct();
};

extern void sub_0049AD70();

RBX_Network_Client* RBX_Network_Client::construct()
{
    sub_0049AD70();
    *(int*)((char*)this + 0x00) = 0x79c454;
    *(int*)((char*)this + 0x04) = 0x79c448;
    *(int*)((char*)this + 0x10) = 0x79c440;
    *(int*)((char*)this + 0x14) = 0x79c430;
    *(int*)((char*)this + 0x2c) = 0x79c420;
    *(int*)((char*)this + 0x44) = 0x79c410;
    *(int*)((char*)this + 0x5c) = 0x79c400;
    *(int*)((char*)this + 0x74) = 0x79c3f0;
    *(int*)((char*)this + 0x8c) = 0x79c3e0;
    *(int*)((char*)this + 0xe8) = 0x79c3b0;
    *(int*)((char*)this + 0xec) = 0x79c3a4;
    return this;
}
