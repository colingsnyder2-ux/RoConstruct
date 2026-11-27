// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct T { char d[0x28]; ~T(); };
struct V { int a, b; T arr[0x28]; };
void Function5b65e0(V *value) { delete value; }
