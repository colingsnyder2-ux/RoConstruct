// from server: 1% by colin
// roc-lang: cpp
// PBVTextureFormat::?$Table - matching target 00471df0
// External helpers from target binary

struct PBVTextureFormat {
    int code;
    int glFormat;
    int glBaseFormat;
    int bitsPerTexel;
    bool compressed;
    bool floatingPoint;
};

// External helpers matching observed calling conventions
void* __cdecl sub_470600(void);
void* __cdecl sub_4709a0(void);
void* __cdecl sub_471070(void);
void* __cdecl sub_4713f0(void);
void* __cdecl sub_471590(void);

// Target-like init function with matching stack args
void initPBVTextureFormatTable(
    int arg15, int arg16, int arg20, int arg24,
    int arg48, int arg52, int arg76, int arg80
) {
    // Call observed external helpers - may produce matching assembly
    sub_470600();
    sub_4709a0();
    sub_471070();
    sub_4713f0();
    sub_471590();
}