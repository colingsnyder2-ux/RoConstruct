// from server: 100% by EspClaude
// from server: 97% by king_originala_sol_resume_native
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /Ob1
// roc-lib: xtp-11.2.2-lib-imports roc_espclaude_569602479ecc41f0.cpp

// Candidate translation unit (score above; library headers required).
#define WINVER 0x0501
#define _WIN32_WINNT 0x0501
#include <intrin.h>
#include <atlbase.h>
#include <shlwapi.h>
#include <typeinfo>

// Exact Boost 1.34.1 smart-pointer ABI subset used by this translation unit.
// Source: boost/detail/sp_counted_base_w32.hpp, shared_count.hpp, shared_ptr.hpp.
namespace boost
{
    namespace detail
    {
        class sp_counted_base
        {
        private:
            sp_counted_base(sp_counted_base const&);
            sp_counted_base& operator=(sp_counted_base const&);

            long use_count_;
            long weak_count_;

        public:
            sp_counted_base() : use_count_(1), weak_count_(1) {}
            virtual ~sp_counted_base() {}
            virtual void dispose() = 0;
            virtual void destroy() { delete this; }
            virtual void* get_deleter(std::type_info const& ti) = 0;

            void weak_release()
            {
                if (_InterlockedDecrement(&weak_count_) == 0)
                    destroy();
            }

            void release()
            {
                if (_InterlockedDecrement(&use_count_) == 0)
                {
                    dispose();
                    weak_release();
                }
            }
        };

        class shared_count
        {
        private:
            sp_counted_base* pi_;

        public:
            ~shared_count()
            {
                if (pi_ != 0)
                    pi_->release();
            }
        };
    }

    template<class T>
    class shared_ptr
    {
    public:
        T* operator->() const { return px; }

    private:
        T* px;
        detail::shared_count pn;
    };
}

extern CString gBaseUrl;
extern bool gSilentCrashReport;

namespace RBX
{
    namespace ContentProvider
    {
        void setAssetFolder(const char* path);
    }
}

class GlobalSettings
{
public:
    void loadState();
};

boost::shared_ptr<GlobalSettings> getGlobalSettings();
void initializeTaskScheduler();
void initializeNetworkSettings();
void initializeSecurity();
void initializeApplicationSettings();
void reportGlobalSettings();

class CRobloxModuleProbe : public CWinApp
{
public:
    void loadAppSettings();
};

void CRobloxModuleProbe::loadAppSettings()
{
    SetRegistryKey("ROBLOX Corporation");
    LoadStdProfileSettings(6);

    CXTPPropExchangeXMLNode settings(TRUE, 0, "Settings");
    settings.SetCompactMode(FALSE);

    CString moduleFilename;
    AfxGetModuleShortFileName(
        AfxGetApp()->m_hInstance,
        moduleFilename);

    CString moduleFolder((LPCSTR)moduleFilename);
    PathRemoveFileSpecA(moduleFolder.GetBuffer(moduleFolder.GetLength()));
    moduleFolder.ReleaseBuffer();
    settings.LoadFromFile(moduleFolder + "\\AppSettings.xml");

    {
    BOOL silentCrashReport = TRUE;
    if (!PX_Bool(&settings, "SilentCrashReport", silentCrashReport) ||
        silentCrashReport)
    {
        silentCrashReport = FALSE;
        ATL::CRegKey key;
        if (key.Open(
                HKEY_CURRENT_USER,
                "Software\\ROBLOX Corporation\\Roblox",
                KEY_READ) == ERROR_SUCCESS)
        {
            DWORD registryValue = FALSE;
            key.QueryDWORDValue("SilentCrashReport", registryValue);
            silentCrashReport = registryValue;
            gBaseUrl.ReleaseBuffer();
        }
    }
    gSilentCrashReport = silentCrashReport != FALSE;
    }

    PX_String(&settings, "BaseUrl", gBaseUrl);
    if (gBaseUrl.IsEmpty())
    {
        ATL::CRegKey key;
        if (key.Open(HKEY_LOCAL_MACHINE, "Software\\Roblox", KEY_READ) ==
            ERROR_SUCCESS)
        {
            ULONG length = 1024;
            key.QueryStringValue(
                "BaseUrl",
                gBaseUrl.GetBuffer(1024),
                &length);
            gBaseUrl.ReleaseBuffer();
        }
    }

    CString contentFolder;
    PX_String(&settings, "ContentFolder", contentFolder);
    if (!contentFolder.IsEmpty())
    {
        CString assetFolder;
        LPCSTR folder = moduleFolder;
        LPCSTR content = contentFolder;
        LPSTR buffer = assetFolder.GetBuffer(MAX_PATH);
        PathCombineA(buffer, folder, content);
        assetFolder.ReleaseBuffer();
        RBX::ContentProvider::setAssetFolder(assetFolder);
    }

    initializeTaskScheduler();
    initializeNetworkSettings();
    initializeSecurity();
    initializeApplicationSettings();
    getGlobalSettings()->loadState();
    reportGlobalSettings();
}


