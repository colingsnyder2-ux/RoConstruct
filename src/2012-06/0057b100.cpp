// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct String{char d[0x1c]; __declspec(dllimport) ~String();}; struct M{ char d[0x218]; ~M() throw(); }; struct X{ char pad[0x10]; M m; String arr[0x80]; ~X(); }; X::~X(){}
