// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct H { char* p; ~H(){ if (p) delete p; } };
struct MB { virtual ~MB(); void cleanup(); int a[3]; H h; };
MB::~MB(){ cleanup(); }
