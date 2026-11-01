// from server: 71% by colin
struct CSettingsExplorer {
    int field_0;
    void* field_4;
    bool field_8;
    char pad_9[3];
    char field_c;
    void* get();
};

void* CSettingsExplorer::get()
{
    if (field_4 == 0) {
        void* h = ((void* (__stdcall*)(void*))0x77d57c)(&field_c);
        field_4 = ((void* (__stdcall*)(void*))0x77d2c8)(h);
        if (field_4 == 0) {
            void* h2 = ((void* (__stdcall*)(void*))0x77d57c)(&field_c);
            field_4 = ((void* (__stdcall*)(void*))0x77d27c)(h2);
            field_8 = (field_4 != 0);
        }
    }
    return field_4;
}
