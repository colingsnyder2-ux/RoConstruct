// from server: 29% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" unsigned int __stdcall SetTimer(void*, unsigned int, unsigned int, void*);
extern "C" int __stdcall KillTimer(void*, unsigned int);

struct RefCounted {
    void AddRef();
    void Release();
};

struct Controller {
    char pad[0x20];
    void* hwnd;
    char pad2[0x2cc - 0x24];
    char field2cc[0x1c];
    char field2e8[0x1c];
    unsigned int field304;
    void* field308;
    void* field30c;
    void* field310;
    void* field314;
    void onServiceProvider(void* oldProvider, void* newProvider);
};

void Controller::onServiceProvider(void* oldProvider, void* newProvider)
{
    if (this->field308 == oldProvider) {
        if (newProvider) {
            RefCounted* p = (RefCounted*)newProvider;
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
                p->Release();
            }
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
                p->Release();
            }
        }
        return;
    }

    if (this->field308) {
        void* local308 = this->field308;
        void* local30c = this->field30c;
        if (local30c) {
            _InterlockedExchangeAdd((volatile long*)((char*)local30c + 4), 1);
        }
        if (this->field308) {
        }
        if (this->field310) {
        }
        if (this->field310) {
        }
    }

    this->field310 = 0;
    void* old314 = this->field314;
    this->field314 = 0;
    if (old314) {
        RefCounted* p = (RefCounted*)old314;
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
            p->Release();
        }
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
            p->Release();
        }
    }

    this->field308 = oldProvider;

    if (this->field308) {
        void* local = newProvider;
        if (local) {
            _InterlockedExchangeAdd((volatile long*)((char*)local + 4), 1);
        }
        this->field304 = SetTimer(this->hwnd, 0x14d, 1, 0);
        if (this->field310) {
        }
        if (this->field310) {
        }
        if (this->field308) {
        }
    } else {
        if (this->hwnd) {
            KillTimer(this->hwnd, this->field304);
        }
    }

    if (newProvider) {
        RefCounted* p = (RefCounted*)newProvider;
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
            p->Release();
        }
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
            p->Release();
        }
    }
}
