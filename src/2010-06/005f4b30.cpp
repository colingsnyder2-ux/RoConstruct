// from server: 56% by atomic.potato
struct RBX_Instance {
    char pad[0x4c];
    RBX_Instance* field_4c;
    int getSomething();
};

extern "C" int __stdcall sub_7a8bea(void*, void*, void*, void*, void*);
extern "C" int __stdcall sub_470bd0();
extern "C" int __stdcall sub_4b0710();
extern "C" int __stdcall sub_607840();

int RBX_Instance::getSomething() {
    if (this == 0)
        return 0;
    RBX_Instance* p = this->field_4c;
    if (p != 0) {
        RBX_Instance* q = p->field_4c;
        if (q != 0) {
            sub_470bd0();
        } else {
            p = q;
        }
    } else {
        p = this;
    }
    if (p == 0)
        return 0;
    int r = sub_7a8bea(p, 0, (void*)0xb78e40, (void*)0xb7cc50, 0);
    if (r == 0)
        return 0;
    int s = sub_4b0710();
    if (s == 0)
        return 0;
    return sub_607840();
}
