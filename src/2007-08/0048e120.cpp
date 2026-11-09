// from server: 100% by colin
struct RBXInstance {
    char pad[0xbc];
    RBXInstance* next;
};

extern "C" int __cdecl sub_630d36(RBXInstance*, int, const char*, const char*, int);
extern "C" void* __fastcall sub_48cda0(void*);

void* __cdecl sub_48e120(RBXInstance* p)
{
    while (p) {
        int r = sub_630d36(p, 0, (const char*)0x881f4c, (const char*)0x884e04, 0);
        if (r)
            return sub_48cda0((void*)r);
        p = p->next;
    }
    return 0;
}
