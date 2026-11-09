// from server: 100% by colin
struct CChildFrame {
    char pad[0x20];
    int field_20;
    int method(int);
int sub_6303B2(int);
};

extern "C" void* (__stdcall *GetParent)(void*);
extern "C" void* (__stdcall *GetWindow)(void*, unsigned int);
extern "C" void* __stdcall sub_6301C0(void*);


int CChildFrame::method(int arg) {
    void* p = GetParent((void*)field_20);
    void* q = sub_6301C0(p);
    void* r = GetWindow((void*)*(int*)((char*)q + 0x20), 5);
    void* s = sub_6301C0(r);
    int result;
    if (s == this) {
        result = 3;
    } else {
        result = arg;
    }
    return sub_6303B2(result);
}
