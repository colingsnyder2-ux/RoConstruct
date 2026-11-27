// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Base { Base(); ~Base(); };
struct Rocky : Base { Rocky(); void init(int); };
Rocky::Rocky() : Base() { init(0); }
