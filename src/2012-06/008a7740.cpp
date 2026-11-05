// from server: 41% by atomic.potato
extern "C" void* __cdecl sub_98211a(unsigned int);

struct Inner {
    char pad[0xac4];
    int field;
};

struct VGameTool {
    char pad[0xc];
    Inner* field_c;
    void* method();
};

extern "C" void __fastcall sub_947f60(void*, int, int);

void* VGameTool::method() {
    void* p = sub_98211a(0x50);
    if (p) {
        int v = field_c->field;
        sub_947f60(p, 0, v);
    }
    return p;
}
