// from server: 100% by atomic.potato
extern "C" int (__cdecl *_ismbcprint)(int);

struct CXTMaskEditT {
    int OnChar(unsigned int nChar);
};

int CXTMaskEditT::OnChar(unsigned int nChar) {
    if (_ismbcprint((signed char)nChar) == 0) {
        if (((int (__thiscall *)(CXTMaskEditT *, unsigned int))*(void **)(*(int *)this + 0x154))(this, nChar) == 0) {
            return 0;
        }
    }
    return 1;
}
