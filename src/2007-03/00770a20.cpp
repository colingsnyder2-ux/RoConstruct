// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern "C" __declspec(noinline) void* make_00770a20(); struct Obj{void run(void*,void*);}; extern Obj obj; extern "C" void tail(void*);
void func(){void* x=make_00770a20();obj.run(x,(void*)0x79cfb0);*(void**)&obj=(void*)0x79c75c;tail((void*)0x778b80);}
