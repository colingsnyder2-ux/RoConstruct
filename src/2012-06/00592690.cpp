// from server: 44% by Intel




struct ServerReplicator;

extern "C" void __stdcall sub_581590(ServerReplicator* thisptr);
extern "C" void __cdecl sub_40c910(void* arg1, int arg2);
extern "C" void __stdcall sub_592150(void* thisptr);

struct ServerReplicator {
    void func(int a1, int a2);
};

void ServerReplicator::func(int a1, int a2) {
    int v3;
    if (a2) {
        v3 = a2 + 0x1C;
    } else {
        v3 = 0;
    }
    sub_581590(this);
    sub_40c910((void*)v3, a1);
    sub_592150((char*)this + 0x1EF8);
}
