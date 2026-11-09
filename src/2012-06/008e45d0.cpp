// from server: 17% by atomic.potato
struct VPartInstance_SeatImpl {
    char pad[0x2d0];
    unsigned char flag;
    void method(unsigned char* arg);
};

extern "C" void* __fastcall sub_8e44d0(void* self);
extern "C" void* __fastcall sub_812310(void* self);
extern "C" void* __stdcall sub_79b020(void* p);
extern "C" void __fastcall sub_79db60(void* self, int);
extern "C" void __fastcall sub_684200(void* self, int, int);

void VPartInstance_SeatImpl::method(unsigned char* arg) {
    if (flag != 0) {
        flag = *arg;
        return;
    }
    if (*arg == 0) {
        flag = *arg;
        return;
    }
    void* p = sub_8e44d0(this);
    while (p != 0) {
        void* q = sub_812310(p);
        void* r = sub_79b020(q);
        if (r != 0) {
            sub_79db60(r, 0);
        }
        sub_684200(p, 0, 0);
        p = sub_8e44d0(this);
    }
    flag = *arg;
}
