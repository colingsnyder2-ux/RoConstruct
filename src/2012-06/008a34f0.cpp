// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE /fp:fast
extern int gItem;
static float gValue;
void __stdcall notify(const void*);
void __stdcall setValue(float v) {
    if (v != gValue) { gValue = v; notify(&gItem); }
}