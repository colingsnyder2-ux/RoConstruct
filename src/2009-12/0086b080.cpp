// from server: 85% by atomic.potato
struct CXTPPropertyGridItemEnum {
    void SetValue(int);
};

extern "C" void __stdcall sub_98d538(void*, void*);

void CXTPPropertyGridItemEnum::SetValue(int value)
{
    (*(void (__thiscall **)(CXTPPropertyGridItemEnum*, int))(*(int*)this + 0xe8))(this, value);
    *(int*)((char*)this + 0x8c) = 5;
    *(int*)((char*)this + 0x7c) = 1;
    sub_98d538((char*)this + 0xa8, (char*)this + 0xa4);
}
