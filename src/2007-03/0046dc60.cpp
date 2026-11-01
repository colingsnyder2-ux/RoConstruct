// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Obj{void run(int);}; extern Obj obj;
void func(int arg){obj.run(arg);}
