// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct T{ __declspec(dllimport) ~T(); };
struct S{ T* p; void f(); };
void S::f(){ delete p; }
