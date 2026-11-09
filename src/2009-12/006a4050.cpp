// from server: 87% by atomic.potato
extern "C" int __cdecl sub_788c80(int a, int b);
extern "C" int __cdecl sub_789130(int a, int b);
extern "C" int __cdecl sub_788ff0(int a, int b, int c);
extern "C" int __cdecl sub_788a70(int a, int b, int c);
extern "C" int __cdecl sub_7887b0(int a, int b);
extern "C" int __cdecl sub_6a3960(int a);

struct VScriptContext {
    char pad[0x20];
    bool FactoryProduct(int a, int b);
};

bool VScriptContext::FactoryProduct(int a, int b) {
    int edi = sub_788c80(a, b);
    if (edi != 0) {
        if (sub_789130(a, b) != 0) {
            sub_788ff0(a, -10000, *(int*)0xb62b58);
            if (sub_788a70(a, -1, -2) != 0) {
                sub_7887b0(a, -3);
                int ecx = *(int*)((char*)this + 0x20);
                sub_6a3960(edi);
                return true;
            }
            sub_7887b0(a, -3);
        }
    }
    return false;
}
