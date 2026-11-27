// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S { int vt; int f4; void* fn; int adj;
  int* f(int* out, void* obj); };
int* S::f(int* out, void* obj)
{
    int x = obj ? (int)((char*)obj - 0x1c) : 0;
    int* r = ((int* (__thiscall*)(int, void**))fn)(adj + x, &obj);
    *out = *r;
    return out;
}
