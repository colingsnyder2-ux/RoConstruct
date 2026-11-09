// from server: 31% by atomic.potato
extern "C" void* __stdcall sub_7E1E30(void*);
extern "C" void __stdcall sub_7E1E80(void*);
extern "C" void* __stdcall sub_7F3860(unsigned int);
extern "C" void __stdcall sub_7F385A(void*);
extern "C" void __stdcall sub_6C8AC0(void*);
extern "C" void __stdcall sub_540AE0(void*);

struct Player {
    void* field0;
    void ensure();
};

void Player::ensure()
{
    if (field0 != 0)
        return;

    char local[8];
    sub_7E1E30(&local[0]);

    if (field0 == 0)
    {
        void* p = sub_7F3860(0x34);
        if (p != 0)
            sub_6C8AC0(p);

        void* old = field0;
        field0 = p;
        if (old != 0)
        {
            sub_540AE0(old);
            sub_7F385A(old);
        }
    }

    sub_7E1E80(&local[0]);
}
