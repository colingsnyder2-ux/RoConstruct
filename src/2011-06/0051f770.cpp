// from server: 75% by colin
struct ProfiledRakPeer {
    char pad[0x2a8];
    int field_2a8;
    int field_0c;
    void RunUpdateCycle(unsigned int timeNS, unsigned int timeMS);
};

extern "C" void __stdcall sub_52d8d0(int*);
extern "C" void __stdcall sub_4ec940(int*);
extern "C" void __stdcall sub_4ed100(int*, void*, unsigned int);
extern "C" void __stdcall sub_4159a0(int*);

void ProfiledRakPeer::RunUpdateCycle(unsigned int timeNS, unsigned int timeMS)
{
    sub_52d8d0(&this->field_2a8);
    sub_4ec940(&this->field_0c);
    if (timeNS != 0 && timeMS > 0)
        sub_4ed100(&this->field_0c, (void*)timeNS, timeMS);
    sub_4159a0(&this->field_2a8);
}
