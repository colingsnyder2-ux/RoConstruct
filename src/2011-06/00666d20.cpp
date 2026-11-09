// from server: 52% by atomic.potato


extern "C" void* __stdcall sub_00A404C4(void*, const char*);

struct ButtonBindingWidget {
    void* m_str;
    ButtonBindingWidget* __cdecl ctor(int type, const char* name);
};

ButtonBindingWidget* ButtonBindingWidget::ctor(int type, const char* name)
{
    m_str = 0;
    if (type == 0x1b)
        sub_00A404C4(this, (const char*)0x00a9c0dc);
    else
        sub_00A404C4(this, (const char*)0x00a5beca);
    return this;
}
