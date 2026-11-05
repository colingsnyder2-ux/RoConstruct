#pragma once
// Inactive native 2008-06 recovery: the application's ATL module object (CRobloxApp.cpp's translation unit).
#include <afxwin.h>
#include <atlbase.h>

// CRobloxModule (RTTI of vtable 00816a28: CRobloxModule : CAtlMfcModule : CAtlModuleT<CAtlMfcModule> : CAtlModule :
// _ATL_MODULE70 at +4). sizeof 0x2c == sizeof(CAtlMfcModule): the one instance is the global at 0096dbb4 and the
// next global (theApp) starts at 0096dbe0. Its dynamic initializer 007ef7d0 is the inline CAtlModule constructor
// (_pAtlModule = this, m_csStaticDataInitAndTypeInfo.Init() at +0x10, cbSize = 0x24 or m_bInitFailed) followed by
// the vptr store 00816a28 and atexit(007fae10), so CRobloxModule declares no constructor or members of its own.
// Vtable slots: 0 ??_G 0044be40 (inline ~CAtlModule -> Term), 1-3 CAtlMfcModule Lock/Unlock/GetLockCount
// (0044b950/0044b960/0044b970), 4 CAtlModule::GetGITPtr 0044b900, 5 CAtlModuleT::AddCommonRGSReplacements
// 0044b980 (L"APPID" with the default GetAppId() L""): no override, so no DECLARE_REGISTRY_APPID_RESOURCEID.
class CRobloxModule : public ATL::CAtlMfcModule
{
};

// 0096dbb4. The variable name is the ATL wizard convention, provisional.
extern CRobloxModule _AtlModule;
