// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern "C" int helper(const char*,int); extern int g;
void func(){g=helper((const char*)0x7954e0,-1);}
