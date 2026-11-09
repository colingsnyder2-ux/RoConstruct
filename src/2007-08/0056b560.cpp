// from server: 28% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct XmlNameValuePair;
struct DescribedBase;
struct IIDREF;

struct RefCounted {
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    volatile long refCount;
    volatile long weakRefCount;
};

struct StringValue {
    char buf[16];
    unsigned int size;
    unsigned int capacity;
};

struct XmlNameValuePair {
    char pad[0xc];
    int type;
};

struct ArchiveBinder {
    int field0;
    int field4;
    int field8;
    int fieldC;

    bool processID(XmlNameValuePair* valueID, DescribedBase* source);
    bool processIDREF(XmlNameValuePair* valueIDREF, DescribedBase* propertyOwner, const IIDREF* idref);
    bool resolveIDREF(XmlNameValuePair* valueIDREF, DescribedBase* propertyOwner, const IIDREF* idref);
};

struct IDREFBinding {
    XmlNameValuePair* valueIDREF;
    DescribedBase* propertyOwner;
    const IIDREF* idref;
};

extern int g_8c22d8;
extern int g_8c22c0;
extern int g_8c22bc;
extern int g_8c22dc;

extern "C" {
    void __stdcall sub_41d060(void* dst, void* src);
    void __stdcall sub_424410(void* dst, void* src);
    void __stdcall sub_492360(void* p);
    void __stdcall sub_501f30(void* p);
    void __stdcall sub_501840(void* p);
    void __stdcall sub_5421b0(void* a, void* b);
    void* __stdcall sub_55d330(void* p, int id);
    void* __stdcall sub_55d350(void* p, void* node);
    void* __stdcall sub_55d3b0(void* p, int id);
    bool __stdcall sub_55d460(void* p, void* out);
    bool __stdcall sub_55d5f0(void* p, void* out);
    void __stdcall sub_56a770(void* p);
    void __stdcall sub_56ab00(void* p);
    void __stdcall sub_56b4b0(void* p);
    void __stdcall sub_56c0a0(void* p, int a, const char* b, const char* c);
    void* __stdcall sub_56c3b0(void* p);
    void* __stdcall sub_77e698(const char* s);
    void __stdcall sub_77e6ac(void* p);
}

bool ArchiveBinder::resolveIDREF(XmlNameValuePair* valueIDREF, DescribedBase* propertyOwner, const IIDREF* idref)
{
    if (valueIDREF->type != g_8c22d8)
        goto fail;

    {
        void* found = sub_55d3b0(valueIDREF, g_8c22c0);
        if (found == 0)
            goto fail;
        if (!sub_55d5f0((char*)found + 4, this))
            goto fail;
    }

    if (this->field0 < 4)
        goto fail;

    {
        char local[0x40];
        sub_56ab00(local);

        void* iter = sub_55d330(valueIDREF, g_8c22bc);
        if (iter == 0)
            goto cleanup;

        while (iter != 0) {
            void* node = sub_55d3b0(iter, g_8c22dc);
            if (node == 0)
                goto next;

            {
                void* strOut;
                if (!sub_55d460((char*)node + 4, &strOut))
                    goto next;

                void* strVal;
                sub_41d060(&strVal, strOut);

                if (strVal != 0) {
                    sub_5421b0(iter, local);
                    sub_424410((void*)propertyOwner, &strVal);
                } else {
                    char* s;
                    if (strVal != 0) {
                        if (*(unsigned int*)((char*)strVal + 0x1c) >= 0x10)
                            s = *(char**)((char*)strVal + 8);
                        else
                            s = (char*)strVal + 8;
                    } else {
                        s = (char*)0x785954;
                    }
                    void* tmp = sub_56c3b0(local);
                    sub_56c0a0(*(void**)tmp, 2, (const char*)0x7a9c04, s);
                    sub_492360(local);
                }

                if (strVal != 0) {
                    if (_InterlockedExchangeAdd((volatile long*)((char*)strVal + 4), -1) == 1) {
                        void** vt = *(void***)strVal;
                        ((void(__thiscall*)(void*))vt[1])(strVal);
                        if (_InterlockedExchangeAdd((volatile long*)((char*)strVal + 8), -1) == 1) {
                            void** vt2 = *(void***)strVal;
                            ((void(__thiscall*)(void*))vt2[2])(strVal);
                        }
                    }
                }
            }

        next:
            iter = sub_55d350(valueIDREF, iter);
        }

    cleanup:
        sub_56a770(local);
        sub_56b4b0(local);
    }

    return true;

fail:
    {
        void* strObj = sub_77e698((const char*)0x7a9bb0);
        sub_501f30(&strObj);
        sub_501840(&strObj);
        sub_77e6ac(&strObj);
    }
    return false;
}
