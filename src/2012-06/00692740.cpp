// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" int __stdcall sub_981ff4(int, unsigned char*);

struct BoundFuncDesc {
    char pad[0x88];
    int handle;
    char pad2[0xbc - 0x8c];
    int other;
    unsigned char f();
};

unsigned char BoundFuncDesc::f() {
    if (handle == 0)
        return other == 0;
    unsigned char result;
    if (sub_981ff4(handle, &result) == 0x24)
        result = 1;
    return result;
}
