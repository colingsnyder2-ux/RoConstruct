// from server: 25% by atomic.potato
struct XItem
{
    virtual void SetValue(float *);
};

extern "C" void __cdecl CreateValue(double *);

void __thiscall XItem::SetValue(float *value)
{
    CreateValue(0);
}
