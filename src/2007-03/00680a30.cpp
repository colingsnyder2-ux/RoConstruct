// from server: 100% by colin
// roc-flags: /O2 /GS- /MD
extern "C" void* __stdcall get(int); struct B{void* use();};
void* func(){B* p=(B*)get(8); return p?p->use():0;}
