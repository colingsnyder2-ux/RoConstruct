// from server: 33% by colin
// roc 2007-08 005e5950  unit: RBX::ArrowTool  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005e5950

struct Tool;

struct ToolSignal {
    void setEnabled(int);
};

struct Tool {
    char pad0[0x20];
    ToolSignal signal;      // +0x20
    char pad1[0x14];        // +0x24 .. +0x37
    void* ptr38;            // +0x38
    void* ptr3c;            // +0x3c

    void func(Tool* other);
};

extern "C" void __stdcall sub_562300(ToolSignal*, int);
extern "C" void __stdcall sub_5e4600(int, int, int, int, int, int, int, int, int, int, int, int);
extern "C" void __stdcall sub_5b3a60(int, int, int, int, int);
extern "C" void __stdcall sub_538410(int);

void Tool::func(Tool* other)
{
    ToolSignal* sig = &this->signal;
    sub_562300(sig, 1);

    int a = *(int*)this->ptr3c;
    int b = *(int*)other->ptr38;

    int local = 0;
    int v38_4 = *(int*)((char*)this + 0x3c);
    sub_5e4600(b, *(int*)other->ptr38, *(int*)((char*)this + 0x3c), 0, *(int*)((char*)this + 0x3c), b, *(int*)other->ptr38, *(int*)((char*)this + 0x3c), b, *(int*)other->ptr38, *(int*)((char*)this + 0x3c), local);

    sub_562300(sig, 1);

    int c = *(int*)this->ptr38;
    int d = *(int*)other->ptr38;

    local = 0;
    sub_5e4600(d, *(int*)other->ptr38, *(int*)((char*)this + 0x3c), 0, *(int*)other->ptr38, d, *(int*)((char*)this + 0x3c), *(int*)other->ptr38, d, *(int*)((char*)this + 0x3c), *(int*)other->ptr38, local);

    if (this != other) {
        int e = *(int*)this->ptr38;
        sub_5b3a60(*(int*)e, e, (int)this, *(int*)e, (int)&local);
        sub_538410((int)other);
    }
}
