// from server: 100% by tester
struct CXTPControlLabel {
    void* method(int);
};

extern "C" void* __fastcall sub_0067ee70(void*);

void* CXTPControlLabel::method(int arg)
{
    void* p = sub_0067ee70(this);
    void** vt = *(void***)p;
    void (__thiscall* fn)(void*, void*, int) = (void (__thiscall*)(void*, void*, int))vt[0x38];
    fn(p, this, arg);
    return p;
}
