// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct G{ unsigned long d1; unsigned short d2,d3; unsigned char d4[8]; };
struct I{ virtual long __stdcall QI(const G& iid, void** pp)=0; virtual unsigned long __stdcall AR()=0; virtual unsigned long __stdcall RL()=0; };
unsigned long __stdcall f(char* self){ return (*(I**)(self-8))->RL(); }
