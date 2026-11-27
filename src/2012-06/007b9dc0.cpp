// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Block
{
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual int kind();
    virtual void v5();
    virtual int shape();
};
inline bool A(Block *b){ if (b->kind()!=0) return false; int s=b->shape(); return s==0xb||s==0; } inline bool B(Block *b){ return b->kind()==0 && b->shape()==0xc; } inline bool C(Block *b){ if (b->kind()!=0) return false; int s=b->shape(); return s==2||s==0xa; } int func(Block *b){ return !A(b) && !B(b) && !C(b); }
