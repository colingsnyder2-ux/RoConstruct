// from server: 100% by colin
// roc-flags: /O2 /GS- /MD
extern "C" void* alloc(int);
void* func(){void* p=alloc(0x148); if(p) *(void**)p=p; if((char*)p+4) *(void**)((char*)p+4)=p; return p;}
