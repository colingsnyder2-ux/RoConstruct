// from server: 56% by atomic.potato
extern "C" void __cdecl InitializeMechanism();
extern "C" void CopySelection(void *, const void *);

struct RotateSelectionVerb
{
    RotateSelectionVerb();
};

RotateSelectionVerb::RotateSelectionVerb()
{
    InitializeMechanism();
    CopySelection(this, this);
}
