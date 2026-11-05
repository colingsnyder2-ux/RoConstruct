// from server: 27% by colin
struct MVCXTPPropertyGridItemXItem
{
    bool convertToValue(void* value) const;
};

extern "C" void __stdcall sub_439850(void*);
extern "C" void __stdcall sub_5595A0(void*);

bool MVCXTPPropertyGridItemXItem::convertToValue(void* value) const
{
    char buf[8];
    sub_439850(buf);
    void* p = value;
    if (p != 0)
        p = (char*)p + 4;
    void* result = (*(void*(__thiscall**)(void*, void*))((*(char**)((*(char**)((char*)this + 0x118)) + 0x18)) + 4))(*(void**)((*(char**)((char*)this + 0x118)) + 0x18), p);
    sub_5595A0(buf);
    return result != 0;
}
