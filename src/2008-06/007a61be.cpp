// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O1 /GS- /MD /hotpatch
extern volatile int dword_97f2ac;
struct Tail { ~Tail(); };
struct CXTIconHandle {
    char padding[0x20];
    Tail tail;
    __declspec(noinline) ~CXTIconHandle();
};
extern "C" void __stdcall sub_7a6132(CXTIconHandle *, int);
CXTIconHandle::~CXTIconHandle() {
    sub_7a6132(this, dword_97f2ac);
}



