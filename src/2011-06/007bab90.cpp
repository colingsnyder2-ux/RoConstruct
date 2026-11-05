// from server: 57% by atomic.potato
extern "C" void __stdcall Function007B9A50(void *, void *, float);

struct FilterDescendents
{
    void f(float value);
};

void FilterDescendents::f(float value)
{
    float threshold = 0.0f;
    Function007B9A50(&threshold, &value, threshold);
}
