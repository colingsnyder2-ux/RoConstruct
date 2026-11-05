// from server: 17% by colin
struct Descriptor;
struct ObjectBrowserItem;

struct DeclarationView
{
    char pad0[0x20];
    unsigned int m_hwnd;
    char pad1[0x88];
    ObjectBrowserItem* m_item;
    char pad2[0x20];

    void updateDeclarationView(ObjectBrowserItem* item);
};

struct ObjectBrowserItem
{
    char pad0[0x8];
    char vec1[0x18];
    char pad1[0x30];
    char vec2[0x18];
    char pad2[0x18];
    char vec3[0x18];
};

extern "C" unsigned int __stdcall SendMessageA(unsigned int hWnd, unsigned int Msg, unsigned int wParam, unsigned int lParam);
extern "C" void __cdecl _invalid_parameter_noinfo();

void func_004345f0();
void func_004360a0();
void func_00725750();
void func_00725770();

void DeclarationView::updateDeclarationView(ObjectBrowserItem* item)
{
    SendMessageA(m_hwnd, 0x1101, 0, 0xffff0000);
    m_item = item;

    func_004345f0();
    func_00725750();

    func_004360a0();
    func_004360a0();
    func_004360a0();

    SendMessageA(m_hwnd, 0x1115, 0, 0);

    func_00725770();
}
