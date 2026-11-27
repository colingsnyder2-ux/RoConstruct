// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V2 { float x, y; V2(){} V2(const V2& o):x(o.x),y(o.y){} };
struct S { int vt; int f4; void* fn; int adj;
  V2 f(void* obj); };
V2 S::f(void* obj)
{
    int x = obj ? (int)((char*)obj - 0x1c) : 0;
    const V2* r = ((const V2* (__thiscall*)(int))fn)(adj + x);
    return *r;
}
