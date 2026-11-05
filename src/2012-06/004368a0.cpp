// from server: 35% by atomic.potato




struct Msg {
    int type;
    char pad0[4];
    void* obj;
    char pad1[8];
    int val;
    char pad2[4];
};

extern "C" void* __stdcall sub_99f320(void*);
extern "C" void* __stdcall sub_9824e6(void*, void*);
extern "C" void* __stdcall sub_9d3ba0();
extern "C" int __stdcall sub_9f1620(void*);
extern "C" void __stdcall sub_984b20(void*, int);
extern "C" void* __stdcall sub_98211a(int);
extern "C" void* __stdcall sub_435090();
extern "C" void __stdcall sub_98e890(void*, int);
extern "C" void __stdcall sub_9850a0(void*, void*);
extern "C" void __stdcall sub_415300(void*, int);
extern "C" void* __stdcall sub_9caa90();
extern "C" void* __stdcall sub_9cbcf0(void*);
extern "C" void __stdcall sub_9c94c0(void*, void*);
extern "C" void* __stdcall sub_4785b0();
extern "C" void __stdcall sub_9d1ea0(void*, void*, int, int, int, int);
extern "C" void __stdcall sub_9cb810(void*, void*, int, int);
extern "C" void __stdcall sub_434d10(void*, int);
extern "C" void __stdcall sub_98268a(void*);
extern "C" void* __stdcall sub_479a50();

struct CPatchedControlComboBox {
    int method(Msg* msg);
};

int CPatchedControlComboBox::method(Msg* msg) {
    if (msg->obj == 0)
        return 0;
    if (sub_9824e6(sub_99f320(*(void**)((char*)msg + 0x14)), 0) == 0)
        return 0;
    int t = msg->type;
    if (t == 0xe12b || t == 0xe12c) {
        msg->val = 4;
        return 1;
    }
    if (t == 0x80db || t == 0x80f6) {
        void* p = sub_9d3ba0();
        msg->obj = p;
        sub_984b20(p, sub_9f1620(p) & 0xfffffff7);
        sub_415300(msg->obj, 1);
        return 1;
    }
    if (t == 0x80c3) {
        void* p = sub_98211a(0x1e0);
        void* q = 0;
        if (p) {
            q = sub_435090();
        }
        sub_98e890(q, 1);
        sub_9850a0(q, (void*)0xb4fd4c);
        sub_415300(q, 1);
        sub_984b20(q, 0x20);
        msg->obj = q;
        return 1;
    }
    if (t == 0x8040) {
        void* a = sub_9caa90();
        void* b = sub_9cbcf0(*(void**)((char*)this + 0xec));
        sub_9c94c0(a, b);
        void* p = sub_98211a(0x184);
        void* q = 0;
        if (p) {
            q = sub_4785b0();
        }
        sub_9d1ea0(*(void**)((char*)b + 0xfc), q, 0x8d, 0, -1, 0);
        sub_9cb810(b, (void*)0xb4fd44, msg->type, 0);
        sub_434d10(b, 1);
        sub_98268a(b);
        msg->obj = a;
        return 1;
    }
    if (t == 0x8049) {
        void* a = sub_9caa90();
        void* b = sub_9cbcf0(*(void**)((char*)this + 0xec));
        sub_9c94c0(a, b);
        void* p = sub_98211a(0x18c);
        void* q = 0;
        if (p) {
            q = sub_479a50();
        }
        sub_9d1ea0(*(void**)((char*)b + 0xfc), q, 0xdc, 0, -1, 0);
        sub_9cb810(b, (void*)0xb4fd38, msg->type, 0);
        sub_434d10(b, 1);
        sub_98268a(b);
        msg->obj = a;
        return 1;
    }
    return 0;
}
