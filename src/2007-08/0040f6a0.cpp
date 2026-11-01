// from server: 64% by colin
struct CopyVerb {
    char pad[0x14c];
    CopyVerb(char* name, void* container);
};

extern "C" void* __stdcall sub_77e698(void*);
extern "C" void __fastcall sub_40f5e0(void*, void*, char*);
extern char DAT_00786d78;
extern char DAT_00786d8c;

CopyVerb::CopyVerb(char* name, void* container)
{
    char* base = (char*)this;
    void* p = (container != 0) ? (char*)container + 0x14c : 0;
    char buf[0x1c];
    sub_77e698(&DAT_00786d8c);
    sub_40f5e0(base, p, name);
    *(void**)base = &DAT_00786d78;
}
