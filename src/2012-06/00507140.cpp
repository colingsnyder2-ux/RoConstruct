// from server: 88% by Xemicl
// roc-cl: 50727
// roc-flags: /O1 /GS- /EHsc /MD
char* g(char*); char* __stdcall f(char** a){ char* p=*a; return p ? g(p+5) : p; }
