// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" int __stdcall sub(int,void*,int,int); extern int g;
int __stdcall func(int a,int b,int c){return sub(a,&g,b,c);}
