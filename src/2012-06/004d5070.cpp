// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef unsigned size_t; __declspec(dllimport) void* __cdecl operator new(size_t, int, int, int); __declspec(dllimport) void __cdecl operator delete(void*, int, int, int); struct RSM; struct Node{ char d[0x214]; Node(RSM*, int); }; struct RSM{ Node* make(int a); }; Node* RSM::make(int a){ return new(0,0,0) Node(this,a); }
