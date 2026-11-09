// from server: 5% by colin
struct RBXName {
    void* p;
};

struct CreatorBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

struct VCamera {
    char pad0[0x20];
    void* field20;
    char pad24[0x44];
    void* field68;
    char pad6c[0x0e];
    char field7a;
    char field7b;
    char pad7c[0x0c];
    void* field88;
    char pad8c[0x08];
    void* field94;
    void* field98;
    void* field9c;
};

struct Rect {
    long left;
    long top;
    long right;
    long bottom;
};

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

extern "C" {
    int __stdcall IsRectEmpty(const tagRECT*);
    int __stdcall GetClientRect(void*, tagRECT*);
    int __stdcall DrawTextA(void*, const char*, int, tagRECT*, unsigned int);
}

extern void* g_8b5188;
extern void* g_8bbd30;
extern char g_8bfac1;

void __stdcall sub_630490(void*);
void __stdcall sub_63048a(void*);
void __stdcall sub_630a1e();

void __stdcall sub_457da0(void*);
void __stdcall sub_457f30(void*, void*, int);
void __stdcall sub_457f90(void*);
void __stdcall sub_458c00(void*);
void __stdcall sub_45a740(void*, int);
void __stdcall sub_4797e0(void*);
void __stdcall sub_479820(void*);
void __stdcall sub_4f5660();
void* __stdcall sub_40f060();

struct VCamera2 {
    char pad0[0x20];
    void* field20;
    char pad24[0x44];
    void* field68;
    char pad6c[0x0e];
    char field7a;
    char field7b;
    char pad7c[0x0c];
    void* field88;
    char pad8c[0x08];
    void* field94;
    void* field98;
    void* field9c;

    bool method();
};

bool VCamera2::method()
{
    char local_13 = 0;
    char local_f = 0;
    void* local_50 = 0;
    tagRECT local_68;
    tagRECT local_10;
    void* local_20;
    void* local_4c;
    int local_ac = 0;

    sub_630490(&local_4c);

    if (this->field94 == 0)
        goto cleanup;
    if (local_50 == 0)
        goto cleanup;
    if (this->field68 == 0)
        goto cleanup;

    if (IsRectEmpty(&local_68) != 0)
        goto cleanup;

    sub_457da0(this->field94);

    if (this->field9c == 0) {
        GetClientRect(this->field20, &local_10);
        DrawTextA(local_50, "Roblox can't run with your graphics driver", -1, &local_10, 0x8000);
        goto cleanup;
    }

    sub_457f30(&local_20, this->field88, 1);
    local_ac = 1;

    sub_458c00(this);
    sub_4797e0(this->field9c);
    sub_45a740(this, 1);
    sub_479820(this->field9c);
    local_f = 1;

    this->field7a = 1;
    if (this->field7b == 0) {
        void* p = sub_40f060();
        if (p != 0)
            p = (char*)p + 4;
        else
            p = 0;
        void* vt = *(void**)g_8bbd30;
        void* fn = *(void**)((char*)vt + 4);
        typedef void (__stdcall *Fn)(void*);
        ((Fn)fn)(p);
        if (local_f == 0) {
            sub_458c00(this);
            this->field7b = 0;
        }
    } else {
        sub_458c00(this);
        this->field7b = 0;
    }

    if (this->field7a != 0) {
        this->field7a = 0;
        sub_4f5660();
        g_8bfac1 = 1;
    }

    local_ac = 0;
    sub_457f90(&local_20);

cleanup:
    local_ac = -1;
    sub_63048a(&local_4c);
    return local_f != 0;
}
