// from server: 73% by atomic.potato
extern "C" void __cdecl MechanismFunction();
extern "C" void CopyMemoryWords(void *, const void *);

struct RotateSelectionVerb
{
    int f(int *);
};

int RotateSelectionVerb::f(int *value)
{
    MechanismFunction();
    CopyMemoryWords(this, value);
    return (int)this;
}
