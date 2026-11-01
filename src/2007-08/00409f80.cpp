// from server: 100% by colin
struct VCApp {
    char pad[0xec];
    int value;
};

extern VCApp* __cdecl sub_409920();

int __stdcall sub_409f80(int, int* out)
{
    VCApp* p = sub_409920();
    *out = p->value;
    return 0;
}
