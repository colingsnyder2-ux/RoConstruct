// from server: 12% by colin
// roc 2007-08 00560fe0  unit: RBX::VModelInstance::?$FilteredSelection  size: 426 bytes

struct FilteredSelection;

struct Selection {
    void clearSelection();
};

struct Instance {
    void setName(const char*);
};

struct FilteredSelection : Instance {
    Selection* rootSelection;
    void* filteredSelection[3];

    FilteredSelection();
    ~FilteredSelection();
    void addFilteredSelection(FilteredSelection*);
    void removeFilteredSelection(FilteredSelection*);
};

extern "C" void __stdcall sub_725520(void*, void*);
extern "C" void __cdecl sub_55e820();
extern "C" void __cdecl sub_40e470();
extern "C" void __cdecl sub_444e70();
extern "C" void __cdecl sub_52cb30();
extern "C" void __cdecl sub_554de0();
extern "C" void __cdecl sub_492360();
extern "C" void __cdecl sub_402a60();
extern "C" void __cdecl _invalid_parameter_noinfo();

extern unsigned char byte_8C2338;
extern unsigned int dword_8C233C;

FilteredSelection::FilteredSelection()
{
    sub_725520((void*)0x8C232C, (void*)0x55ED80);
    sub_55e820();
    rootSelection = 0;
    filteredSelection[0] = 0;
    filteredSelection[1] = 0;
    filteredSelection[2] = 0;
    setName("FilteredSelection");
}

FilteredSelection::~FilteredSelection()
{
    if (rootSelection != 0)
        rootSelection->clearSelection();
}
