// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Base { char padding[0x3bc - 4]; Base(); virtual ~Base(); };
struct Member { Member(); virtual void a(); ~Member(); };
struct V : Base, Member { V(); virtual ~V(); };
V::V() : Base(), Member() {}
