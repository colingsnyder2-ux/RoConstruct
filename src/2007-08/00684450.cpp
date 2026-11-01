// from server: 100% by colin
struct SoundChannel {
    char pad[0x20];
    int field_20;
    char pad2[0x130 - 0x24];
    int field_130;
    int field_134;
    char pad3[0x148 - 0x138];
    int field_148;

    void func();
};

extern "C" int (__stdcall *InvalidateRect)(void*, const void*, int);

SoundChannel* __fastcall SoundChannel_helper_682a20(SoundChannel*);
void __fastcall SoundChannel_helper_683be0(SoundChannel*);

void SoundChannel::func()
{
    int v = (*(int*)(field_130 + 0x28)) != 0;
    if (field_134 != v) {
        SoundChannel* p = SoundChannel_helper_682a20(this);
        if (p->field_148 == 0) {
            SoundChannel_helper_683be0(this);
            return;
        }
    }
    if (field_20 != 0) {
        SoundChannel* p = SoundChannel_helper_682a20(this);
        if (p->field_148 == 0) {
            InvalidateRect((void*)field_20, 0, 0);
        }
    }
}
