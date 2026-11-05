// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_dialogselection_0ffe3ef3f6c36f7f.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
// from server: 81% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);

struct String;
typedef void (__thiscall *StringAssign)(String*, const String&);
typedef void (__thiscall *StringDestroy)(String*);
extern StringAssign assignString;
extern StringDestroy destroyString;

struct String {
    void* data;
    ~String() { destroyString(this); }
    void assign(const String& other) { assignString(this, other); }
};

typedef boost::shared_ptr<void> Product;

struct List {
    char storage[32];
    String text(int, int);
    const char* data(int);
    void imageList(int, unsigned int, int);
};

struct Exchange {
    int saving;
};

struct ImageList {
    void* unused;
    void* handle;
    void* getHandle() {
        void* result=this;
        if(result) result=handle;
        return result;
    }
};

extern void __stdcall exchangeList(Exchange*, int, List*);
extern Product __cdecl makeProduct(const char*);
extern void __stdcall finishList(long);
extern void* __cdecl getDescriptor();
extern int __stdcall compareItems(long, long, long);

struct Dialog {
    char padding[148];
    String selectedText;
    Product selected;
    ImageList images;
    List list;
    void* window;

    void update(void*);
    void exchange(Exchange*);
};

void Dialog::exchange(Exchange* exchangeData)
{
    exchangeList(exchangeData, 1000, &list);
    if (exchangeData->saving) {
        int position = SendMessageA(window, 0x100c, -1, 2) + 1;
        if (position != 0) {
            int index=position-1;
            SendMessageA(window, 0x100c, index, 2);
            selectedText.assign(list.text(index, 0));
            selected = makeProduct(list.data(index));
        }
    } else {
        if (SendMessageA(window, 0x1004, 0, 0) == 0) {
            SendMessageA(window, 0x108e, 3, 0);
            list.imageList(0, 0x800, 0);
            finishList(SendMessageA(window, 0x1003, 1,
                                  (long)images.getHandle()));
            update(getDescriptor());
            SendMessageA(window, 0x1030, 0, (long)compareItems);
        }
    }
}
