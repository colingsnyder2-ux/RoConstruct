// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2
struct S{char pad[0x98]; void f(float v);};
void S::f(float v){*(float*)((char*)this+0x98)=v;}
