// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct CSettingsDialog {
    char storage[0x3D4];
    CSettingsDialog(int);
};

CSettingsDialog* createSettingsDialog()
{
    return new CSettingsDialog(0);
}
