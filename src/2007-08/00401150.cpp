// from server: 100% by colin
extern "C" __declspec(dllimport) void __cdecl free(void*);

struct CSettingsDialog {
    void* m_field0;
    void clear();
};

void CSettingsDialog::clear()
{
    while (m_field0 != 0) {
        void* p = m_field0;
        m_field0 = *(void**)p;
        free(p);
    }
}
