// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /GR
struct IHasLocation { virtual void loc(); };
struct I0 { virtual void a(); };
struct I1 { virtual void b(); };
struct I2 { virtual void c(); };
struct I3 { virtual void d(); };
struct IHasPrimaryPart { virtual void e(); };
struct L0 : I0, I1 { int pad[4]; };
struct L2 : I3 { char pad[0x60]; };
struct Inst : L0, I2, L2 { };
struct PV : Inst, IHasPrimaryPart, virtual IHasLocation
{
    int m[4];
    ~PV();
};
struct FP : PV
{
    ~FP();
};
FP::~FP() { }