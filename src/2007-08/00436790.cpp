// from server: 32% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct ObjectBrowserItem {
    int unknown0;
    int unknown4;
    int unknown8;
    int unknownC;
};

struct std_string {
    void ctor();
    void dtor();
    std_string& operator=(const std_string&);
    std_string& operator=(const char*);
    std_string& operator+=(const std_string&);
    std_string& operator+=(const char*);
    const char* c_str() const;
};

struct RefCountedBase {
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    volatile long refCount4;
    volatile long refCount8;
};

struct CDeclarationView {
    void method_436790(ObjectBrowserItem* item);
};

extern "C" void __stdcall sub_435070(int, int, int);
extern "C" void __cdecl sub_436490(int, int, int, int, int, int);
extern "C" void __cdecl sub_4364e0();
extern "C" void __cdecl sub_442c60();
extern "C" void __cdecl sub_443340();
extern "C" void __cdecl sub_443390();
extern "C" void __cdecl sub_4433e0();
extern "C" void* __cdecl sub_444b70();
extern "C" void __cdecl sub_492360();
extern "C" void __cdecl sub_5017c0();
extern "C" void __cdecl sub_630a1e();
extern "C" void* __cdecl sub_630d36(int, const char*, const char*, int, ObjectBrowserItem*);

extern "C" void __stdcall imp_77e62c();
extern "C" void __stdcall imp_77e660();
extern "C" void __stdcall imp_77e664();
extern "C" void __stdcall imp_77e690();
extern "C" void __stdcall imp_77e6a4();
extern "C" void __stdcall imp_77e6a8();
extern "C" void __stdcall imp_77e6ac();

extern const char str_787034[];
extern const char str_78cc48[];
extern const char str_78cc4c[];
extern const char str_78cc50[];
extern const char str_78cc58[];
extern const char str_882b74[];
extern const char str_8836a4[];
extern const char str_887144[];
extern const char str_887174[];
extern const char str_8871d0[];

void CDeclarationView::method_436790(ObjectBrowserItem* item) {
    if (item == 0) {
        sub_435070(0, 0, 0);
        return;
    }

    std_string decl;
    decl.ctor();

    ObjectBrowserItem* found = 0;
    found = (ObjectBrowserItem*)sub_630d36(0, str_882b74, str_8836a4, 0, item);
    if (found != 0) {
        std_string owner;
        owner.ctor();
        owner.operator=(str_787034);
        owner.operator+=(str_78cc4c);
        owner.operator+=(str_78cc48);

        std_string summary;
        summary.ctor();
        sub_436490(0, 0, 0, 0, 0, 0);
        summary.operator+=(str_78cc48);

        RefCountedBase* rc = (RefCountedBase*)found->unknownC;
        void* s = sub_444b70();
        rc = (RefCountedBase*)(*(int*)s);
        sub_443390();
        if (rc != 0) {
            if (_InterlockedExchangeAdd(&rc->refCount4, -1) == 1) {
                rc->unknown1();
                if (_InterlockedExchangeAdd(&rc->refCount8, -1) == 1) {
                    rc->unknown2();
                }
            }
        }
        summary.dtor();
        owner.dtor();
    } else {
        found = (ObjectBrowserItem*)sub_630d36(0, str_882b74, str_887174, 0, item);
        if (found != 0) {
            std_string owner;
            owner.ctor();
            owner.operator=(str_787034);
            owner.operator+=(str_78cc4c);
            owner.operator+=(str_78cc48);

            std_string summary;
            summary.ctor();
            sub_436490(0, 0, 0, 0, 0, 0);
            summary.operator+=(str_78cc48);

            RefCountedBase* rc = (RefCountedBase*)found->unknownC;
            void* s = sub_444b70();
            rc = (RefCountedBase*)(*(int*)s);
            sub_443340();
            summary.dtor();
            owner.dtor();
        } else {
            found = (ObjectBrowserItem*)sub_630d36(0, str_882b74, str_8836a4, 0, item);
            if (found != 0) {
                std_string owner;
                owner.ctor();
                owner.operator=(str_78cc58);
                owner.operator+=(str_78cc4c);
                owner.operator+=(str_78cc48);

                std_string summary;
                summary.ctor();
                sub_436490(0, 0, 0, 0, 0, 0);
                summary.operator+=(str_78cc48);

                RefCountedBase* rc = (RefCountedBase*)found->unknownC;
                void* s = sub_444b70();
                rc = (RefCountedBase*)(*(int*)s);
                sub_4433e0();
                summary.dtor();
                owner.dtor();
            } else {
                found = (ObjectBrowserItem*)sub_630d36(0, str_882b74, str_8871d0, 0, item);
                if (found != 0) {
                    std_string owner;
                    owner.ctor();
                    owner.operator=(str_78cc50);
                    owner.operator+=(str_78cc4c);
                    owner.operator+=(str_78cc48);

                    std_string summary;
                    summary.ctor();
                    sub_436490(0, 0, 0, 0, 0, 0);
                    summary.operator+=(str_78cc48);

                    RefCountedBase* rc = (RefCountedBase*)found->unknownC;
                    void* s = sub_444b70();
                    rc = (RefCountedBase*)(*(int*)s);
                    sub_442c60();
                    summary.dtor();
                    owner.dtor();
                } else {
                    found = (ObjectBrowserItem*)sub_630d36(0, str_882b74, str_887144, 0, item);
                    if (found != 0) {
                        std_string owner;
                        owner.ctor();
                        owner.operator=(str_787034);
                        owner.operator+=(str_78cc4c);
                        owner.operator+=(str_78cc48);

                        std_string summary;
                        summary.ctor();
                        sub_436490(0, 0, 0, 0, 0, 0);
                        summary.operator+=(str_78cc48);

                        RefCountedBase* rc = (RefCountedBase*)found->unknownC;
                        void* s = sub_444b70();
                        rc = (RefCountedBase*)(*(int*)s);
                        sub_442c60();
                        summary.dtor();
                        owner.dtor();
                    } else {
                        std_string owner;
                        owner.ctor();
                        owner.operator=(str_787034);
                        owner.operator+=(str_78cc4c);
                        owner.operator+=(str_78cc48);

                        std_string summary;
                        summary.ctor();
                        sub_436490(0, 0, 0, 0, 0, 0);
                        summary.operator+=(str_78cc48);

                        RefCountedBase* rc = (RefCountedBase*)found->unknownC;
                        void* s = sub_444b70();
                        rc = (RefCountedBase*)(*(int*)s);
                        sub_442c60();
                        summary.dtor();
                        owner.dtor();
                    }
                }
            }
        }
    }

    decl.dtor();
}
