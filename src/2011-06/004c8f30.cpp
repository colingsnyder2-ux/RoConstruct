// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
extern "C" void* alloc(int);
void* func(){void* p=alloc(0x54); if(p) *(void**)p=p; if((char*)p+4) *(void**)((char*)p+4)=p; return p;}
