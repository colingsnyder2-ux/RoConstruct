// from server: 10% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct String {
    char pad[0x1c];
};

struct ContentProvider {
    char pad0[0x138];
    char lock[8];
    char pad1[0x140 - 0x138 - 8];
    void ProcessFile(const String& name, const String& path);
};

extern "C" {
    void* __stdcall sub_7f3860(unsigned int);
    void __stdcall sub_7f4878(const void*, const void*);
    void __stdcall sub_854a90(void*, void*, void*);
    void* __stdcall sub_98b6e8();
    void __stdcall sub_98b6f0(void*, void*);
    void __stdcall sub_98b6c8(void*, void*, int, int, int);
    void __stdcall sub_98b6d4(void*, int, int);
    void __stdcall sub_98b424(void*, void*);
    void* __stdcall sub_98b6d8(void*, void*);
    void __stdcall sub_98b69c(void*, void*);
    void __stdcall sub_98b6e4(void*);
    void __stdcall sub_98b6dc(void*);
    void __stdcall sub_98b6cc(void*);
    void __stdcall sub_98b5a4(void*, const char*, void*);
    void __stdcall sub_98b680(void*, void*, const char*);
    void __stdcall sub_98b228();
}

int __stdcall sub_6bdfd0(void*, void*);
int __stdcall sub_6bee30(void*, void*);
void __stdcall sub_6c12b0(void*, void*);
void __stdcall sub_6c13f0(void*, void*);
void __stdcall sub_6c0580(void*);
void __stdcall sub_6c2380(void*, void*, void*);
int __stdcall sub_4b7370(void*);
int __stdcall sub_4b73e0(void*);
void __stdcall sub_409390(void*, void*);
void __stdcall sub_408db0(void*);
void __stdcall sub_412c80(void*);
void __stdcall sub_418460(void*, void*);
void __stdcall sub_514af0(void*);
void __stdcall sub_6384e0(void*);
void __stdcall sub_63f270(void*, void*);
void __stdcall sub_4109e0();

void ContentProvider::ProcessFile(const String& name, const String& path)
{
    void* evt = sub_7f3860(0x1c);
    void* evtObj = 0;
    if (evt) {
        evtObj = sub_98b6e8();
    }
    void* local38 = evtObj;
    void* local3c;
    sub_6bdfd0(&local3c, evtObj);
    sub_854a90(&local3c, evtObj, evtObj);

    void* local30 = 0;
    void* local34 = 0;

    if (sub_4b7370((void*)&name)) {
        void* obj = sub_7f3860(0x1c);
        if (obj) {
            char buf[0x20];
            sub_98b6f0(buf, (void*)&name);
            *(void**)(buf + 0x1c) = *(void**)((char*)&name + 0x1c);
            sub_6c12b0(obj, buf);
        }
        sub_6bee30(&local30, obj);
        void* p = local30;
        if (*(int*)((char*)p + 0x14) == 0) {
            char tmp[0x40];
            sub_98b5a4(tmp, "File not found '", (void*)&name);
            char tmp2[0x40];
            sub_98b680(tmp2, tmp, "'");
            char tmp3[0x40];
            sub_409390(tmp3, tmp2);
            sub_7f4878(tmp3, (void*)0xa904f0);
        }
    }

    if (!sub_4b73e0((void*)&name)) {
        void* obj = sub_7f3860(0x1c);
        if (obj) {
            char buf[0x20];
            sub_98b6f0(buf, (void*)&name);
            *(void**)(buf + 0x1c) = *(void**)((char*)&name + 0x1c);
            sub_6c13f0(obj, buf);
        }
        sub_6bee30(&local30, obj);
        void* p = local30;
        if (p && *(int*)((char*)p + 0x14) != 0) {
            char* str;
            if (*(unsigned int*)((char*)p + 0x18) >= 0x10)
                str = *(char**)((char*)p + 4);
            else
                str = (char*)p + 4;
            char fbuf[0x1f8];
            sub_98b6c8(fbuf, str, 0x21, 0x40, 1);
            char sbuf[0x140];
            sub_98b6d4(sbuf, 2, 1);
            char tmp[0x1f0];
            sub_98b424(sbuf, tmp);
            void* r = sub_98b6d8(sbuf, &local3c);
            sub_98b69c(local38, r);
            sub_98b6e4(&local3c);
            sub_98b6dc(sbuf);
            sub_98b6cc(fbuf);
        }
    } else {
        if (sub_4b73e0((void*)&name)) {
            sub_98b6f0(&local3c, (void*)&name);
            sub_6c0580(&local3c);
            char tmp[0x118];
            sub_418460(tmp, &local3c);
            sub_63f270(tmp, local38);
            sub_408db0(tmp);
            sub_98b6e4(&local3c);
        }
    }

    void* lockPtr = (char*)this + 0x138;
    void* local44 = lockPtr;
    char local48 = 0;
    sub_412c80(&local44);

    void* a = local30;
    void* b = local34;
    if (b) {
        _InterlockedExchangeAdd((volatile long*)((char*)b + 4), 1);
    }
    void* c = local3c;
    void* d = local38;
    if (c) {
        _InterlockedExchangeAdd((volatile long*)((char*)c + 4), 1);
    }

    char tmp2[0x40];
    sub_6384e0(tmp2);
    sub_6c2380((char*)this + 0x140, (void*)&name, tmp2);
    sub_514af0(tmp2);

    if (local48) {
        void* p = local44;
        long old = _InterlockedExchangeAdd((volatile long*)p, (long)0x80000000);
        if ((old & 0x40000000) == 0 && old > (long)0x80000000) {
            long prev = _InterlockedExchangeAdd((volatile long*)p, 0);
            if ((prev & 0x40000000) == 0) {
                sub_4109e0();
                sub_98b228();
            }
        }
    }
}
