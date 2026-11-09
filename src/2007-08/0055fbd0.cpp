// from server: 43% by colin
struct FilteredSelection {
    char pad[8];
    void* field8;
    void* fieldC;
    ~FilteredSelection();
};

extern "C" void __fastcall sub_40F800(void*);
extern "C" void __cdecl sub_62FC62(void*);

FilteredSelection::~FilteredSelection()
{
    void* p = this->fieldC;
    if (p) {
        sub_40F800((char*)p + 8);
        sub_62FC62(p);
    }
    void* q = this->field8;
    if (q) {
        sub_40F800((char*)q + 8);
        sub_62FC62(q);
    }
}
