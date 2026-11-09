// from server: 61% by colin
struct TypedStatsItem {
    char pad0[0xec];
    void* m_ec;
    char pad1[0x294 - 0xec - 4];
    void* m_294;
    void* m_298;

    void construct(void* arg);
};

void TypedStatsItem::construct(void* arg) {
    void* p298 = m_298;
    m_294 = (void*)0x7a4cac;
    void* edx = *(void**)((char*)p298 + 4);
    *(void**)((char*)edx + (int)this + 0x298) = (void*)0x7a4ca4;

    void* saved = arg;
    int one = 1;
    void* eax = saved;
    void* ecx = this;
    ((void (__thiscall*)(void*, void*))0x57e490)(ecx, eax);

    void* pec = m_ec;
    *(void**)((char*)this + 0) = (void*)0x7abc84;
    *(void**)((char*)this + 4) = (void*)0x7abc7c;
    *(void**)((char*)this + 0x10) = (void*)0x7abc74;
    *(void**)((char*)this + 0x14) = (void*)0x7abc64;
    *(void**)((char*)this + 0x2c) = (void*)0x7abc54;
    *(void**)((char*)this + 0x44) = (void*)0x7abc44;
    *(void**)((char*)this + 0x5c) = (void*)0x7abc34;
    *(void**)((char*)this + 0x74) = (void*)0x7abc24;
    *(void**)((char*)this + 0x8c) = (void*)0x7abc14;
    *(void**)((char*)this + 0xe8) = (void*)0x7abc08;
    *(void**)((char*)this + 0x158) = (void*)0x7abbf0;
    *(void**)((char*)this + 0x228) = (void*)0x7abbd8;

    void* ecx2 = *(void**)((char*)pec + 4);
    *(void**)((char*)ecx2 + (int)this + 0xec) = (void*)0x7abbcc;

    void* edx2 = m_ec;
    void* eax2 = *(void**)((char*)edx2 + 8);
    *(void**)((char*)eax2 + (int)this + 0xec) = (void*)0x7abbc4;

    void* ecx3 = m_ec;
    void* edx3 = *(void**)((char*)ecx3 + 0xc);
    *(void**)((char*)edx3 + (int)this + 0xec) = (void*)0x7abba8;

    void* eax3 = m_ec;
    void* eax4 = *(void**)((char*)eax3 + 4);
    void* ecx4 = (void*)((char*)eax4 - 0x198);
    *(void**)((char*)eax4 + (int)this + 0xe8) = ecx4;

    void* edx4 = m_ec;
    void* eax5 = *(void**)((char*)edx4 + 8);
    void* ecx5 = (void*)((char*)eax5 - 0x1a0);
    *(void**)((char*)eax5 + (int)this + 0xe8) = ecx5;

    void* edx5 = m_ec;
    void* eax6 = *(void**)((char*)edx5 + 0xc);
    void* ecx6 = (void*)((char*)eax6 - 0x1a8);
    *(void**)((char*)eax6 + (int)this + 0xe8) = ecx6;
}
