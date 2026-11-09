// from server: 83% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct S{char pad[0x68]; char* begin; char* end; int f(int);};
extern "C" int* sub(int);
int S::f(int index){int* p=sub(index); int v=*p; if(v<0)return 0; if((unsigned)v>=(unsigned)((end-begin)>>2))return 0; return ((int*)begin)[v];}
