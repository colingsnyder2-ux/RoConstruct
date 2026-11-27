// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) int __stdcall imp(unsigned,int,int,const char*,int);
int f(unsigned s,int b,int lv){ return imp(s,lv,0xe,(const char*)&b,4); }
