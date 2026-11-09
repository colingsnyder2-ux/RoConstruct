// from server: 65% by atomic.potato
extern "C" void * __cdecl PrimitiveCreate();
extern "C" void __stdcall CopyNineWords(void *, void *);

struct RotateSelectionVerb
{
    RotateSelectionVerb();
};

RotateSelectionVerb::RotateSelectionVerb()
{
    CopyNineWords(this, PrimitiveCreate());
}
