// from server: 100% by colin
// roc-flags: /O2 /GS- /MD
struct S{int f(int); int sub(int*);}; extern "C" int* sub1(int);
int S::f(int value){int v=*sub1(value+4); return sub(&v);}
