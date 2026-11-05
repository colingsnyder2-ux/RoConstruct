// from server: 33% by colin
// from server: 36% by colin
// roc 2007-08 004b54d0  unit: RBX::Network::Server::ClientProxy  size: 399 bytes
// library rbxgs-net Replicator.cpp

extern "C" {
    __declspec(dllimport) unsigned long __stdcall GetCurrentThread();
    __declspec(dllimport) int __stdcall GetThreadTimes(void*, void*, void*, void*, void*);
    __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
    __declspec(dllimport) int __stdcall TlsSetValue(unsigned long, void*);
}

struct RBX_Network_Server_ClientProxy {
    char pad[0x1e00];
    int field_1e00;
    void sub_4ac190(void*);
    void sub_4b44e0(void*);
    void sub_4b4ab0(void*);
    void sub_4b2620(void*);
    void func(int* arg);
};

extern "C" void __cdecl sub_44b190();
extern "C" void __cdecl sub_44b200(void*, int);
extern "C" void __cdecl sub_49f8b0(void*, int, int, int);
extern "C" void __cdecl sub_49f9a0(void*, int*, int, int);
extern "C" void __cdecl sub_49fc00(void*, int);
extern "C" void* __cdecl sub_725f70();
extern "C" void __cdecl sub_725a20(void*);
extern "C" void __cdecl sub_726210(void*);

extern unsigned long g_8c4c34;

void RBX_Network_Server_ClientProxy::func(int* arg)
{
    unsigned long* tls = &g_8c4c34;
    unsigned long threadId;
    int local_18;
    int local_1c;
    unsigned char local_11;
    unsigned char local_28;
    void* local_50;
    void* local_4c;
    void* local_48;
    void* local_40;
    void* local_38;
    void* local_30;
    int local_4;
    int local_0[0x11];

    local_50 = (void*)((char*)this + 0x1e00);
    local_28 = 0;

    if (*tls != 0) {
        threadId = GetCurrentThread();
        local_4c = (void*)threadId;
        GetThreadTimes((void*)threadId, &local_48, &local_40, &local_38, &local_30);
        TlsSetValue(*tls, local_4c);
    }

    local_4 = 0;
    sub_49f8b0(local_0, arg[3], arg[5], 0);
    local_4 = 1;
    sub_49fc00(local_0, 8);
    local_4 = 2;
    sub_44b200(&local_1c, 6);
    local_4 = 3;
    local_11 = 0;

    while (local_11 == 0) {
        local_18 = 0;
        sub_49f9a0(local_0, &local_18, 2, 1);
        if (local_18 < 1 || local_18 > 3) {
            sub_49f9a0(local_0, &local_18, 0x20, 1);
        }
        if (local_18 > 4) {
            continue;
        }
        switch (local_18) {
        case 0:
            sub_4ac190(local_0);
            break;
        case 1:
            sub_4b44e0(local_0);
            break;
        case 2:
            sub_4b4ab0(local_0);
            break;
        case 3:
            sub_4b2620(local_0);
            break;
        case 4:
            local_11 = 1;
            break;
        }
    }

    {
        void* p1 = (void*)local_1c;
        local_4 = 2;
        sub_44b190();
        void* p3 = sub_725f70();
        if (p3 != p1) {
            sub_726210(p1);
            if (p3 != 0) {
                sub_725a20(p3);
            }
        }
    }
    local_4 = 1;
}
