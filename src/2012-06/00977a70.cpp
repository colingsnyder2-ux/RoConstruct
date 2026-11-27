// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Time {
    int lo;
    int hi;
    Time();
    static Time now();
};
struct VCEvent {
    char pad0[0x9c];
    int field_9c;
    char pad1[0x10];
    Time stamp;
    void func();
};
void VCEvent::func()
{
    field_9c = 1;
    stamp = Time::now();
}