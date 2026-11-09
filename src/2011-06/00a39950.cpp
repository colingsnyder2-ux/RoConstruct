// from server: 100% by colin
// roc-flags: /O2 /GS- /MD
extern int g; extern "C" void helper(int);
struct Obj{void m();}; extern Obj obj;
void func(){helper(g); obj.m();}
