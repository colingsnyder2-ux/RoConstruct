// from server: 49% by Intel
struct HumanoidState {
    char pad0[8];
    int m_field8;
    void func(int arg);
};

extern "C" int __stdcall sub_798870(int);
extern "C" int __stdcall sub_798880(int);
extern "C" int __stdcall sub_798890(int);
extern "C" int __stdcall sub_79b2b0(int);
extern "C" int __stdcall sub_79b2c0(int);
extern "C" int __stdcall sub_79b2d0(int);
extern "C" void __stdcall sub_7b95c0(int, int);

void HumanoidState::func(int arg)
{
    if (!m_field8)
        return;

    int v = sub_798870(m_field8);
    if (v)
        sub_7b95c0(*(int*)(v + 0x198), arg);

    v = sub_79b2b0(m_field8);
    if (v)
        sub_7b95c0(*(int*)(v + 0x198), arg);

    v = sub_798880(m_field8);
    if (v)
        sub_7b95c0(*(int*)(v + 0x198), arg);

    v = sub_798890(m_field8);
    if (v)
        sub_7b95c0(*(int*)(v + 0x198), arg);

    v = sub_79b2d0(m_field8);
    if (v)
        sub_7b95c0(*(int*)(v + 0x198), arg);

    v = sub_79b2c0(m_field8);
    if (v)
        sub_7b95c0(*(int*)(v + 0x198), arg);
}
