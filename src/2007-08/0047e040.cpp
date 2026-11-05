// from server: 14% by colin
// roc 2007-08 0047e040  unit: G3D::Win32Window  size: 1800 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0047e040

typedef unsigned int DWORD;
typedef unsigned char BYTE;
typedef void* HDC;
typedef void* HGLRC;
typedef int BOOL;

struct PIXELFORMATDESCRIPTOR {
    unsigned short nSize;
    unsigned short nVersion;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE cColorBits;
    BYTE cRedBits;
    BYTE cRedShift;
    BYTE cGreenBits;
    BYTE cGreenShift;
    BYTE cBlueBits;
    BYTE cBlueShift;
    BYTE cAlphaBits;
    BYTE cAlphaShift;
    BYTE cAccumBits;
    BYTE cAccumRedBits;
    BYTE cAccumGreenBits;
    BYTE cAccumBlueBits;
    BYTE cAccumAlphaBits;
    BYTE cDepthBits;
    BYTE cStencilBits;
    BYTE cAuxBuffers;
    BYTE iLayerType;
    BYTE bReserved;
    DWORD dwLayerMask;
    DWORD dwVisibleMask;
    DWORD dwDamageMask;
};

extern "C" {
    HDC __stdcall GetDC(void* hWnd);
    int __stdcall ChoosePixelFormat(HDC hdc, const PIXELFORMATDESCRIPTOR* ppfd);
    BOOL __stdcall SetPixelFormat(HDC hdc, int format, const PIXELFORMATDESCRIPTOR* ppfd);
    int __stdcall DescribePixelFormat(HDC hdc, int format, unsigned int nBytes, PIXELFORMATDESCRIPTOR* ppfd);
    HGLRC __stdcall wglCreateContext(HDC hdc);
    BOOL __stdcall wglShareLists(HGLRC hrc1, HGLRC hrc2);
    void __cdecl exit(int code);
}

struct G3DString {
    void* rep;
    G3DString(const char* s);
    ~G3DString();
};

struct G3DArray {
    void* data;
    int size;
    int capacity;
};

struct G3DTable {
    int count;
    void* data;
};

struct G3DVector3 {
    float x, y, z;
};

struct G3DVector4 {
    float x, y, z, w;
};

struct G3DColor4 {
    float r, g, b, a;
};

struct G3DColor4uint8 {
    unsigned char r, g, b, a;
};

struct G3DCoordinateFrame {
    float data[12];
};

struct G3DMatrix4 {
    float data[16];
};

struct G3DBox {
    float data[24];
};

struct G3DPlane {
    float normal[3];
    float d;
};

struct G3DLine {
    float data[6];
};

struct G3DLineSegment {
    float data[6];
};

struct G3DMatrix3 {
    float data[9];
};

struct G3DAABox {
    float data[6];
};

struct G3DVector2 {
    float x, y;
};

struct G3DVector3int16 {
    short x, y, z;
};

struct G3DVector2int16 {
    short x, y;
};

struct G3DColor3 {
    float r, g, b;
};

struct G3DColor3uint8 {
    unsigned char r, g, b;
};

struct G3DColor4float {
    float r, g, b, a;
};

struct G3DCoordinateFrame2 {
    float data[12];
};

struct G3DDebug {
    static void* debug;
};

struct G3DTextureArgs {
    int a, b, c;
    G3DTextureArgs(const G3DTextureArgs& other);
};

struct G3DTextureManager {
    void* data;
};

struct G3DWin32Window {
    void* vtable;
    char pad0[0x24];
    G3DTextureArgs texArgs;
    char pad1[0x04];
    int field_3c;
    int field_40;
    int field_44;
    int field_48;
    int field_4c;
    char field_50;
    char pad2[0x02];
    char field_53;
    char pad3[0x5c];
    char field_b0;
    char field_b1;
    char field_b2;
    char field_b3;
    char pad4[0x34];
    HDC hdc;
    HGLRC hglrc;
    char pad5[0x13c];
    int field_1e8;

    void method_47e040(bool param1, int param2);
};

void G3DWin32Window::method_47e040(bool param1, int param2)
{
    if (!param1) {
        G3DTextureArgs localArgs(this->texArgs);
        G3DTextureArgs* pArgs = &localArgs;
        (void)pArgs;
        extern void func_47f970();
        func_47f970();
    }

    this->field_1e8 = param2;
    this->field_b2 = 0;
    this->field_b1 = 0;
    this->field_b0 = 0;

    extern void* __cdecl memset(void*, int, unsigned int);
    memset(&this->field_b3, 0, 0xff);

    this->hdc = GetDC((void*)this->field_1e8);

    if (*(int*)0x8bd670 != 0) {
        PIXELFORMATDESCRIPTOR pfd;
        pfd.nSize = 0x28;
        pfd.nVersion = 1;
        pfd.dwFlags = 0x25;
        pfd.iPixelType = 0;
        pfd.cColorBits = 0x20;
        pfd.cRedBits = 0;
        pfd.cRedShift = 0;
        pfd.cGreenBits = 0;
        pfd.cGreenShift = 0;
        pfd.cBlueBits = 0;
        pfd.cBlueShift = 0;
        pfd.cAlphaBits = 0;
        pfd.cAlphaShift = 0;
        pfd.cAccumBits = 0;
        pfd.cAccumRedBits = 0;
        pfd.cAccumGreenBits = 0;
        pfd.cAccumBlueBits = 0;
        pfd.cAccumAlphaBits = 0;
        pfd.cDepthBits = 0x10;
        pfd.cStencilBits = 0;
        pfd.cAuxBuffers = 0;
        pfd.iLayerType = 0;
        pfd.bReserved = 0;
        pfd.dwLayerMask = 0;
        pfd.dwVisibleMask = 0;
        pfd.dwDamageMask = 0;

        int format = ChoosePixelFormat(this->hdc, &pfd);
        if (format != 0) {
            SetPixelFormat(this->hdc, format, &pfd);
        }
    }

    this->hglrc = wglCreateContext(this->hdc);

    if (*(int*)0x8bd674 != 0) {
        wglShareLists(this->hglrc, *(HGLRC*)((char*)*(void**)0x8bd674 + 0xa8));
    }

    if (*(void**)0x8bd0d8 != this) {
        void** vt = *(void***)this;
        void (*fn)(void*) = (void (*)(void*))vt[0x98/4];
        fn(this);
        *(void**)0x8bd0d8 = this;
    }

    if (!param1) {
        extern void func_46f510();
        func_46f510();
    }
}
