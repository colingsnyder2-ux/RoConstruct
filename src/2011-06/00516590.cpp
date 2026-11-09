// from server: 34% by atomic.potato
// roc 2011-06 00516590  unit: RBX::Network::NetworkOwnerJob  size: 383 bytes




extern "C" void* __stdcall sub_80A05E(unsigned int);
extern "C" void __stdcall sub_80B15D(void*);
extern "C" void __stdcall sub_851300(void*);
extern "C" void __stdcall sub_511A80(void*, const char*, int, void*);
extern "C" void __stdcall sub_4159A0(void*);
extern "C" void* __stdcall sub_5164A0(void*);
extern "C" void __stdcall sub_52D8D0(void*);
extern "C" void* __stdcall sub_C2EE84(unsigned int, const char*, int);

struct NetworkOwnerJob {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
    void* field14;
    void construct(int);
};

void NetworkOwnerJob::construct(int param) {
    void* p = sub_5164A0(this);
    sub_52D8D0(p);
    if (*(int*)0xcb89dc == 0) {
        int i = 0x80;
        do {
            void* v = sub_C2EE84(0x84, (const char*)0xa7e6b4, 0x383);
            void* obj = sub_80A05E(0x18);
            if (obj) {
                sub_851300(obj);
            } else {
                obj = 0;
            }
            *(void**)v = obj;
            sub_511A80((void*)0xcb89d8, (const char*)0xa7e6b4, 0x385, v);
            i--;
        } while (i != 0);
    }
    int idx = *(int*)0xcb89dc;
    void* arr = *(void**)0xcb89d8;
    *(void**)this = *(void**)((char*)arr + idx * 4 - 4);
    int newIdx = idx - 1;
    if ((unsigned int)newIdx < (unsigned int)idx) {
        *(int*)0xcb89dc = newIdx;
    }
    if ((*(unsigned char*)0xcb89c8 & 1) == 0) {
        *(int*)0xcb89c8 |= 1;
        sub_851300((void*)0xcb89b0);
        sub_80B15D((void*)0xa34160);
    }
    sub_4159A0((void*)0xcb89b0);
    void* p2 = *(void**)this;
    *(int*)((char*)p2 + 4) = 1;
    void* p3 = *(void**)this;
    if (param > 0x70) {
        *(int*)((char*)p3 + 8) = param * 2;
        void* p4 = *(void**)this;
        int sz = *(int*)((char*)p4 + 8);
        void* buf = sub_C2EE84(sz, (const char*)0xa7e6b4, 0x397);
        void* p5 = *(void**)this;
        *(void**)((char*)p5 + 0xc) = buf;
        void* p6 = *(void**)this;
        *(void**)((char*)p6 + 0x10) = *(void**)((char*)p6 + 0xc);
    } else {
        *(int*)((char*)p3 + 8) = 0x70;
        void* p7 = *(void**)this;
        *(void**)((char*)p7 + 0x10) = (char*)p7 + 0x14;
    }
}
