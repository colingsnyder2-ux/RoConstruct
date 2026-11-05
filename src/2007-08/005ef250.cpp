// from server: 100% by colin
struct FunctionDescriptor {
    FunctionDescriptor(const char*);
};

struct BoundFuncDesc : FunctionDescriptor {
    BoundFuncDesc(const char*);
};

BoundFuncDesc::BoundFuncDesc(const char* name)
    : FunctionDescriptor(name)
{
    *(int*)((char*)this + 0x00) = 0x7bfc14;
    *(int*)((char*)this + 0x04) = 0x7bfc08;
    *(int*)((char*)this + 0x10) = 0x7bfc00;
    *(int*)((char*)this + 0x14) = 0x7bfbf0;
    *(int*)((char*)this + 0x2c) = 0x7bfbe0;
    *(int*)((char*)this + 0x44) = 0x7bfbd0;
    *(int*)((char*)this + 0x5c) = 0x7bfbc0;
    *(int*)((char*)this + 0x74) = 0x7bfbb0;
    *(int*)((char*)this + 0x8c) = 0x7bfba0;
    *(int*)((char*)this + 0xe8) = 0x7bfb88;
    *(int*)((char*)this + 0xf0) = 0x7bfb7c;
}
