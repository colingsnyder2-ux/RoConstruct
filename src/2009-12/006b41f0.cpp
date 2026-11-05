// from server: 33% by atomic.potato
struct BackpackItem {
    char pad0[8];
    void* field8;
    char padC[4];
    void* fieldC;
    char pad10[0x0C];
    void* field1C;
};

struct GetSetImpl {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    char pad10[0x0C];
    void* field1C;
};

extern "C" void* __stdcall sub_98B6F0(void*);
extern "C" void __stdcall sub_98B6E4(void*);

struct String {
    char pad[0x1C];
};

struct S {
    char pad0[8];
    void* field8;
    void* fieldC;
    void* field10;
    char pad14[8];
    void* field1C;
    void* method(void* arg1, void* arg2);
};

void* S::method(void* arg1, void* arg2) {
    void* p = 0;
    if (arg1) {
        p = (char*)arg1 - 0x1C;
    }
    String local;
    void* result = 0;
    void* (*fn)(void*, void*, void*) = (void* (*)(void*, void*, void*))this->field8;
    result = fn((char*)this->fieldC + (int)p, &local, arg2);
    void* item = result;
    void* target = arg2;
    sub_98B6F0(item);
    *(void**)((char*)target + 0x1C) = *(void**)((char*)item + 0x1C);
    sub_98B6E4(&local);
    return target;
}
