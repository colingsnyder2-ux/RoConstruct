// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef long HRESULT; typedef int BOOL; typedef unsigned int UINT;
#define WINAPI __stdcall
#define NULL 0
#define S_OK ((HRESULT)0L)
struct CRITICAL_SECTION { void* a; long b, c; void* d; void* e; unsigned long f; };
extern "C" __declspec(dllimport) void WINAPI EnterCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void WINAPI LeaveCriticalSection(CRITICAL_SECTION*);
struct IDirect3D9;
extern "C" BOOL WINAPI D3DXCheckVersion(UINT D3DSdkVersion, UINT D3DXSdkVersion);
IDirect3D9* WINAPI DXUT_Dynamic_Direct3DCreate9(UINT SDKVersion);
#define DXUTERR_NODIRECT3D              ((HRESULT)0x80040901L)
#define DXUTERR_INCORRECTVERSION        ((HRESULT)0x80040909L)

extern CRITICAL_SECTION g_cs;
extern bool g_bThreadSafe;

class DXUTLock
{
public:
    inline DXUTLock()  { if( g_bThreadSafe ) EnterCriticalSection( &g_cs ); }
    inline ~DXUTLock() { if( g_bThreadSafe ) LeaveCriticalSection( &g_cs ); }
};

#define SET_ACCESSOR( x, y )       inline void Set##y( x t )   { DXUTLock l; m_state.m_##y = t; };
#define GET_ACCESSOR( x, y )       inline x Get##y()           { DXUTLock l; return m_state.m_##y; };
#define GET_SET_ACCESSOR( x, y )   SET_ACCESSOR( x, y ) GET_ACCESSOR( x, y )

class DXUTState
{
protected:
    struct STATE
    {
        IDirect3D9* m_D3D;
        char pad0[0x1fd - 4];
        bool m_ShowMsgBoxOnError;
        char pad1[0x210 - 0x1fe];
        bool m_DXUTInited;
        char pad2[2];
        bool m_DXUTInitCalled;
        char pad3[0xb98 - 0x214];
    };
    STATE m_state;
public:
    DXUTState() throw();
    ~DXUTState();
    GET_SET_ACCESSOR( IDirect3D9*, D3D );
    GET_SET_ACCESSOR( bool, ShowMsgBoxOnError );
    GET_SET_ACCESSOR( bool, DXUTInited );
    GET_SET_ACCESSOR( bool, DXUTInitCalled );
};

DXUTState& GetDXUTState()
{
    static DXUTState state;
    return state;
}

IDirect3D9* DXUTGetD3DObject();
void DXUTDisplayErrorMessage( HRESULT hr );

HRESULT DXUTInit( bool bShowMsgBoxOnError )
{
    GetDXUTState().SetDXUTInitCalled( true );
    GetDXUTState().SetShowMsgBoxOnError( bShowMsgBoxOnError );

    if( !D3DXCheckVersion( 0x20, 0x16 ) )
    {
        DXUTDisplayErrorMessage( DXUTERR_INCORRECTVERSION );
        return DXUTERR_INCORRECTVERSION;
    }

    IDirect3D9* pD3D = DXUTGetD3DObject();
    if( pD3D == NULL )
    {
        pD3D = DXUT_Dynamic_Direct3DCreate9( 0x20 );
        GetDXUTState().SetD3D( pD3D );
    }

    if( pD3D == NULL )
    {
        DXUTDisplayErrorMessage( DXUTERR_NODIRECT3D );
        return DXUTERR_NODIRECT3D;
    }

    GetDXUTState().SetDXUTInited( true );
    return S_OK;
}
