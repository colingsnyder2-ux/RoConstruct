// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0826fec[];
extern "C" char g_0826e94[];
extern "C" void __fastcall fn_004f0840(void* self);

void operator delete(void*) throw();
struct HideGuard {
    void* s;
    __forceinline HideGuard(void* p):s(p){*(void**)p=g_0826fec;}
    __forceinline ~HideGuard(){*(void**)s=g_0826e94;}
};
extern "C" void* __fastcall fn_004f0b60(void* self, int unusedEdx, unsigned int flags){
    { HideGuard g(self); fn_004f0840(self); }
    if (flags&1) ::operator delete(self);
    return self;
}
