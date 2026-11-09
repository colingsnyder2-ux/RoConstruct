// from server: 48% by colin
struct CScriptEditor {
    char pad0[0x20];
    void* m_field20;
    char pad24[0x128 - 0x24];
    void* m_field128;
    char pad12c[0x134 - 0x12c];
    void* m_field134;
    char pad138[0x144 - 0x138];
    unsigned char m_field144;
    unsigned char m_field145;
    unsigned char m_field146;
    void func_45d230();
    void func_45cc90(int, void*);
    void func_45cad0(int, int);
    void method();
};

extern "C" {
    void __stdcall sub_725750();
    void __stdcall sub_725770();
    int __stdcall sub_77e64c(void*);
    void* __stdcall sub_77e6a8(void*);
    void __stdcall sub_77e69c(void*, void*);
    void __stdcall sub_77e67c(void*, int, int);
    void __stdcall sub_77e680(void*, void*);
    void __stdcall sub_77e684(void*);
    void __stdcall sub_77e6ac(void*);
    void* __stdcall sub_408740();
    void __stdcall sub_548e90(void*, void*);
    void __stdcall sub_44f310(void*, void*, int);
}

void CScriptEditor::method()
{
    if (m_field20 == 0)
        return;

    m_field144 = 1;

    if (m_field134 == 0)
        return;

    void* ebx = m_field128;
    sub_725750();

    int eax = sub_77e64c((char*)m_field134 + 0xf0);
    m_field146 = (eax == 0);

    if (m_field146) {
        void* edi = sub_77e6a8(*(void**)((char*)m_field134 + 0xe8));
        func_45d230();
        func_45cc90(1, edi);
    } else {
        char buf[0x20];
        sub_77e69c(buf, (char*)m_field134 + 0xf0);
        *(int*)(buf + 0x1c) = *(int*)((char*)m_field134 + 0xf0 + 0x1c);

        void* p = sub_408740();
        void* str;
        sub_548e90(p, &str);

        void* edi = *(void**)str;
        *(void**)str = 0;

        if (str) {
            void* vtable = *(void**)str;
            void* fn = *(void**)((char*)vtable + 4);
            void* obj = (char*)str + (int)fn;
            void* v2 = *(void**)obj;
            void* fn2 = *(void**)v2;
            ((void (__stdcall*)(int))fn2)(1);
        }

        char oss[0x88];
        sub_77e67c(oss, 2, 1);
        sub_44f310(oss, edi, 0x1000);

        char str2[0x20];
        sub_77e680(oss, str2);
        void* ebx2 = sub_77e6a8(str2);
        func_45d230();
        func_45cc90(1, ebx2);

        sub_77e6ac(str2);
        sub_77e684(oss);

        if (edi) {
            void* vtable = *(void**)edi;
            void* fn = *(void**)((char*)vtable + 4);
            void* obj = (char*)edi + (int)fn;
            void* v2 = *(void**)obj;
            void* fn2 = *(void**)v2;
            ((void (__stdcall*)(int))fn2)(1);
        }
    }

    int edi;
    if (m_field145 == 0 && m_field146 != 0)
        edi = 0;
    else
        edi = 1;

    func_45d230();
    func_45cad0(1, edi);

    sub_725770();
}
