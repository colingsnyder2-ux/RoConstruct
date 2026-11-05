// from server: 70% by Intel




struct BallBallContact {
    void* vfptr;
    void* next;
    void* pool;

    void* __stdcall Create(void* a1, void* a2, void* a3);
};

extern "C" void* __stdcall AllocateFromPool(void* pool);

void* __stdcall BallBallContact::Create(void* a1, void* a2, void* a3) {
    BallBallContact* thisPtr = this;
    void* eax = thisPtr->vfptr;
    if (eax) {
        void* edx = *reinterpret_cast<void**>(eax);
        thisPtr->vfptr = edx;
    } else {
        eax = AllocateFromPool(thisPtr->pool);
    }
    if (!eax) {
        return 0;
    }
    void* ecx = *reinterpret_cast<void**>(a2);
    unsigned short dx = *reinterpret_cast<unsigned short*>(a1);
    *reinterpret_cast<void**>(reinterpret_cast<char*>(eax) + 4) = ecx;
    void* edx = *reinterpret_cast<void**>(a3);
    *reinterpret_cast<unsigned short*>(eax) = dx;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(eax) + 8) = edx;
    edx = *reinterpret_cast<void**>(reinterpret_cast<char*>(a3) + 4);
    *reinterpret_cast<void**>(reinterpret_cast<char*>(eax) + 12) = edx;
    ecx = *reinterpret_cast<void**>(reinterpret_cast<char*>(a3) + 8);
    *reinterpret_cast<void**>(reinterpret_cast<char*>(eax) + 16) = ecx;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(eax) + 20) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(eax) + 24) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(eax) + 28) = 0;
    return eax;
}
