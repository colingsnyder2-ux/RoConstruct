// from server: 100% by atomic.potato
struct Server {
    void init();
};

extern "C" void __stdcall sub_550330();

void Server::init() {
    *(int*)((char*)this + 0x00) = 0x9bc7cc;
    *(int*)((char*)this + 0x04) = 0x9bc7c0;
    *(int*)((char*)this + 0x18) = 0x9bc7b4;
    *(int*)((char*)this + 0x1c) = 0x9bc7ac;
    *(int*)((char*)this + 0x94) = 0x9bc77c;
    sub_550330();
}
