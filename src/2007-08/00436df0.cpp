// from server: 100% by colin
struct Descriptor;

struct DeclarationView {
    char pad[0xa8];
    void* m_a8;
    void* m_ac;
    void updateDeclarationView(void* item, int* out);
};

extern "C" void* __cdecl sub_630d36(void* a, void* b, void* c, void* d, void* e);

struct Helper1 {
    void sub_436bd0(void* arg);
    void sub_436330(void* arg);
    void sub_436790(void* arg);
};

void DeclarationView::updateDeclarationView(void* item, int* out)
{
    void* esi = *(void**)((char*)item + 0x5c);
    if (m_a8 != 0) {
        void* r = sub_630d36(esi, 0, (void*)0x882b74, (void*)0x887144, 0);
        if (r != 0) {
            ((Helper1*)m_a8)->sub_436bd0(r);
        } else {
            void* r2 = sub_630d36(esi, 0, (void*)0x882b74, (void*)0x8871a4, 0);
            if (r2 != 0) {
                ((Helper1*)m_a8)->sub_436330(r2);
            }
        }
    }
    if (m_ac != 0) {
        ((Helper1*)m_ac)->sub_436790(esi);
    }
    *out = 0;
}
