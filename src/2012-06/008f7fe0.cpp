// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Slot {
    virtual void call(float a, float b, float c);
};
struct Track {
    int padding[2];
    Slot slot;
    int pad2;
    int active;
};
void func_008f7fe0(Track* track, float a, float b, float c)
{
    if (track->active != 0)
        track->slot.call(a, b, c);
}