// from server: 34% by colin
struct FunctionDescriptor {
    char pad[0x11c];
    int field_11c;
    char pad2[0x4];
};

struct ArgHelper {
    char pad[0x174];
};

struct BoundFuncDesc : FunctionDescriptor {
    void construct(int a, int b);
};

extern "C" void __stdcall sub_49f8b0(void*, int, int, int);
extern "C" void __stdcall sub_49fc00(void*, int);
extern "C" void __stdcall sub_493930(void*);
extern "C" void __stdcall sub_4a0640(void*, void*);
extern "C" void __stdcall sub_4a06b0(void*, void*);
extern "C" void __stdcall sub_496dd0(void*, void*, void*);
extern "C" void __stdcall sub_4939a0(void*);
extern "C" void __stdcall sub_49f930(void*);

void BoundFuncDesc::construct(int a, int b) {
    int* p = (int*)b;
    char* c = (char*)p[5];
    int v = (unsigned char)c[0] - 0x4c;
    if (v == 0) {
        return;
    }
    v -= 1;
    if (v != 0) {
        return;
    }
    if (this->field_11c == 0) {
        return;
    }
    ArgHelper helper;
    sub_49f8b0(&helper, p[3], p[5], 0);
    sub_49fc00(&helper, 8);
    char buf[0x114];
    sub_493930(buf);
    sub_4a0640(&helper, buf);
    sub_4a0640(&helper, buf + 4);
    sub_4a06b0(&helper, buf + 8);
    sub_496dd0((void*)this->field_11c, buf, (char*)this + 0x120);
    sub_4939a0(buf);
    sub_49f930(&helper);
}
