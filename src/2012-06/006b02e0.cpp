// from server: 57% by atomic.potato
struct Item {
    char pad0[0x48];
    char str48[0x14];
    char pad5c[0x54];
    void* field_b0;
    void disassociateState(void*);
};

extern "C" {
    extern unsigned char byte_E31AC5;
    int __cdecl sub_5C9FFA(int, const char*, char*);
    void __cdecl sub_6A47C0(void*);
    void __cdecl sub_709EC0(void*);
    int __cdecl sub_6AC790(void*, void*);
    int __cdecl sub_4571F0(void*, void*, void*);
    int __cdecl sub_6AE1E0(void*, void*);
}

void Item::disassociateState(void* arg)
{
    if (field_b0 == 0)
        return;

    if (byte_E31AC5 != 0) {
        char* p;
        if (*(unsigned int*)((char*)this + 0x5c) < 0x10)
            p = (char*)this + 0x48;
        else
            p = *(char**)((char*)this + 0x48);
        sub_5C9FFA((int)byte_E31AC5, "ScriptContext::disassociateState -- %s", p);
    }

    void* v = (*(void*(__thiscall**)(void*))(*(int*)this + 0x68))(this);
    if (*(int*)((char*)v + 0x14) != 0) {
        char* base = (char*)this + 0x26c;
        int r = sub_6AC790(base, v);
        int* begin = *(int**)(r + 0x20);
        int* end = *(int**)(r + 0x24);
        while (begin != end) {
            if (*begin == (int)this) {
                char tmp[8];
                sub_4571F0((char*)r + 0x1c, tmp, begin);
                int diff = *(int*)((char*)r + 0x24) - *(int*)((char*)r + 0x20);
                if ((diff & 0xfffffff8) == 0)
                    sub_6AE1E0(base, v);
                break;
            }
            begin += 2;
        }
    }

    sub_709EC0(field_b0);
    void* old = field_b0;
    field_b0 = 0;
    if (old != 0)
        sub_6A47C0(old);
}
