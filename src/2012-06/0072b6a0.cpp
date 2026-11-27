// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void reg(void*, void*); int conv(void*); struct W { int a; int b; W(); }; W::W() { reg((void*)0xe32b68, (void*)0x72b4d0); a = *(int*)0xe32b54; b = conv((void*)0xe32b58); }
