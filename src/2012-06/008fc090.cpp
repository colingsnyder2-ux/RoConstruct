// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct S;
struct Signal { void fire(S* sender, float value); };
extern Signal g_signal;
struct S {
    float compute(float, float, float);
    void f(float, float, float);
};
void S::f(float a, float b, float c) {
    g_signal.fire(this, compute(a, b, c));
}
