// from server: 32% by atomic.potato
extern "C" {
    void __stdcall sub_738808(int, int, int);
    void __fastcall sub_70cbf0(void*);
    void __fastcall sub_70d1e0(void*);
    void __fastcall sub_6305da(void*);
    void* __stdcall sub_738718();
}

struct CXTColorLum {
    char pad[0x7a4];
    void construct(int);
};

void CXTColorLum::construct(int arg)
{
    sub_738808(0x30, 0, 0x2461);
    *(int*)((char*)this + 0) = 0x7ddeb4;
    sub_70cbf0((char*)this + 0x88);
    sub_70d1e0((char*)this + 0x110);
    sub_6305da((char*)this + 0x1a0);
    *(int*)((char*)this + 0x1a0) = 0x7cc674;
    sub_6305da((char*)this + 0x1f4);
    *(int*)((char*)this + 0x1f4) = 0x7cc674;
    sub_6305da((char*)this + 0x248);
    *(int*)((char*)this + 0x248) = 0x7cc674;
    sub_6305da((char*)this + 0x29c);
    *(int*)((char*)this + 0x29c) = 0x7cc674;
    sub_6305da((char*)this + 0x2f0);
    *(int*)((char*)this + 0x2f0) = 0x7cc674;
    sub_6305da((char*)this + 0x344);
    *(int*)((char*)this + 0x344) = 0x7cc674;
    sub_6305da((char*)this + 0x398);
    *(int*)((char*)this + 0x398) = 0x7dd964;
    sub_6305da((char*)this + 0x3ec);
    *(int*)((char*)this + 0x3ec) = 0x7dd964;
    sub_6305da((char*)this + 0x440);
    *(int*)((char*)this + 0x440) = 0x7dd964;
    sub_6305da((char*)this + 0x494);
    *(int*)((char*)this + 0x494) = 0x7dd964;
    sub_6305da((char*)this + 0x4e8);
    *(int*)((char*)this + 0x4e8) = 0x7dd964;
    sub_6305da((char*)this + 0x53c);
    *(int*)((char*)this + 0x53c) = 0x7dd964;
    sub_6305da((char*)this + 0x590);
    *(int*)((char*)this + 0x590) = 0x7c5c1c;
    sub_6305da((char*)this + 0x5e4);
    *(int*)((char*)this + 0x5e4) = 0x7c5c1c;
    sub_6305da((char*)this + 0x638);
    *(int*)((char*)this + 0x638) = 0x7c5c1c;
    sub_6305da((char*)this + 0x68c);
    *(int*)((char*)this + 0x68c) = 0x7c5c1c;
    sub_6305da((char*)this + 0x6e0);
    *(int*)((char*)this + 0x6e0) = 0x7c5c1c;
    sub_6305da((char*)this + 0x734);
    *(int*)((char*)this + 0x734) = 0x7c5c1c;
    *(int*)((char*)sub_738718() + 4) &= 0xffffffdf;
    *(int*)((char*)this + 0x7a0) = arg;
    *(int*)((char*)this + 0x788) = 0;
    *(int*)((char*)this + 0x78c) = 0;
    *(int*)((char*)this + 0x790) = 0;
    *(int*)((char*)this + 0x794) = 0;
    *(int*)((char*)this + 0x798) = 0;
    *(int*)((char*)this + 0x79c) = 0;
}
