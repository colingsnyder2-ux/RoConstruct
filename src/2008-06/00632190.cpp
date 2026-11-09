// from server: 100% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern unsigned char table0[];
extern unsigned char table10[];
extern unsigned char table14[];
extern unsigned char table20[];
extern unsigned char table24[];
extern unsigned char table44[];
extern unsigned char table64[];
extern unsigned char table84[];
extern unsigned char tableA4[];
extern unsigned char tableC4[];
extern unsigned char table130[];
extern unsigned char table138[];

extern float g148;
extern float g14C;
extern float g150;
extern float g160;

extern const char className[];

struct S {
    unsigned char *v0;
    unsigned char pad04[12];
    unsigned char *v10;
    unsigned char *v14;
    unsigned char pad18[8];
    unsigned char *v20;
    unsigned char *v24;
    unsigned char pad28[28];
    unsigned char *v44;
    unsigned char pad48[28];
    unsigned char *v64;
    unsigned char pad68[28];
    unsigned char *v84;
    unsigned char pad88[28];
    unsigned char *vA4;
    unsigned char padA8[28];
    unsigned char *vC4;
    unsigned char padC8[104];
    unsigned char *v130;
    unsigned char pad134[4];
    unsigned char *v138;
    unsigned char pad13C[12];
    volatile float f148;
    volatile float f14C;
    volatile float f150;
    volatile float f154;
    volatile float f158;
    volatile float f15C;
    volatile float f160;
    volatile float f164;
    volatile float f168;
    volatile float f16C;
    volatile float f170;

    S *construct();
    void initialize(const char*);
};

S *S::construct()
{
    initialize(className);

    f148 = g148;
    v0 = table0;
    f14C = g14C;
    v10 = table10;
    v14 = table14;
    float t = g150;
    v20 = table20;
    v24 = table24;
    v44 = table44;
    v64 = table64;
    v84 = table84;
    vA4 = tableA4;
    vC4 = tableC4;
    v130 = table130;
    v138 = table138;
    f150 = t;
    f154 = t;
    f158 = t;
    f15C = 0.0f;
    f160 = g160;
    f164 = 0.0f;
    f168 = 0.0f;
    f16C = 0.0f;
    f170 = 0.0f;
    return this;
}
