// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE /fp:fast
struct S {
    int vt; int f4; void* fn; int adj;
    void f(void* p, float* value);
};
void S::f(void* p, float* value)
{
    int x = p ? (int)((char*)p - 0x1c) : 0;
    ((void (__thiscall*)(int, int))fn)(adj + x, (int)*value);
}
