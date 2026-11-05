// from server: 26% by atomic.potato
struct S {
    char pad0[0x1c];
    char field1c[0xc];
};

extern "C" void __stdcall sub_9ea40c();

void __fastcall copy_string(void* dst, void* src);

void __fastcall S_ctor(S* self, void* src)
{
    S* p = self;
    if (p) {
        copy_string(p, src);
        *(int*)((char*)p + 0x1c) = *(int*)((char*)src + 0x1c);
        *(int*)((char*)p + 0x20) = *(int*)((char*)src + 0x20);
        *(int*)((char*)p + 0x24) = *(int*)((char*)src + 0x24);
    }
}
