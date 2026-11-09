// from server: 0% by colin
// from server: 44% by colin
struct Stats_Item {
    void setValue(int, const char*);
};

struct SoundServiceStatsItem : Stats_Item {
    void update();
};

extern "C" int __cdecl sub_62fbea(int*, char*);
extern "C" int __cdecl sub_62fc44(int*, int);
extern "C" void __cdecl sub_588330(int);

void SoundServiceStatsItem::update()
{
    char buf;
    if ((*(unsigned char*)((char*)this + 0x11d) & 4) == 0) {
        if ((*(unsigned char*)((char*)this + 0x11d) & 2) != 0) {
            int* p = *(int**)((char*)this + 0xf4);
            if (p != 0) {
                if (sub_62fbea(p, &buf) != 0x24 && buf != 0) {
                    sub_588330(sub_62fc44(*(int**)((char*)this + 0xf4), 0));
                }
            }
        }
    }
}
