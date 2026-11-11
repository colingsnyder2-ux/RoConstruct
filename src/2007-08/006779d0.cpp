// from server: 99% by EspClaude
// from server: 93% by colin
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-11.2.2 roc_claude_454b1413e6f9cc7f.cpp

// Candidate translation unit (score above; library headers required).
#define _AFXDLL
#define _XTP_STATICLINK
#define _DLL
// ---- copy of mfc-9.0 afx.h (string chain inlined)
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef __AFX_H__
#define __AFX_H__

#ifndef __cplusplus
	#error MFC requires C++ compilation (use a .cpp suffix)
#endif

#pragma once

/////////////////////////////////////////////////////////////////////////////

#ifdef _DLL
#ifndef _AFXDLL
#error Building MFC application with /MD[d] (CRT dll version) requires MFC shared dll version. Please #define _AFXDLL or do not use /MD[d]
#endif
#endif

// Since MFC itself is built with wchar_t as a native type, it will not have
// the correct type info for types built with wchar_t typedef'd to unsigned
// short.  Make sure that the user's app builds this type info in this case.
#ifndef _NATIVE_WCHAR_T_DEFINED
#define _AFX_FULLTYPEINFO
#endif

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, off)
#endif 
 
#ifdef __ATLDBGMEM_H__
#error <atldbgmem.h> cannot be used in MFC projects. See AfxEnableMemoryTracking
#endif

#if defined(_MFC_DLL_BLD) && defined(_DEBUG)
#ifndef _CRTDBG_MAP_ALLOC
#define _CRTDBG_MAP_ALLOC
#endif
#endif

#ifndef _INC_NEW
	#include <new.h>
#endif

#include <afxver_.h>        // Target version control

#ifdef _WIN64
#ifndef _AFX_NO_DAO_SUPPORT
#define _AFX_NO_DAO_SUPPORT
#endif
#endif

#ifndef _AFX_NOFORCE_LIBS

/////////////////////////////////////////////////////////////////////////////
// Win32 libraries

#ifndef _AFXDLL
	#ifndef _UNICODE
		#ifdef _DEBUG
			#pragma comment(lib, "nafxcwd.lib")
		#else
			#pragma comment(lib, "nafxcw.lib")
		#endif
	#else
		#ifdef _DEBUG
			#pragma comment(lib, "uafxcwd.lib")
		#else
			#pragma comment(lib, "uafxcw.lib")
		#endif
	#endif
#else
	#ifndef _UNICODE
		#ifdef _DEBUG
			#pragma comment(lib, "mfc" _MFC_FILENAME_VER "d.lib")
			#pragma comment(lib, "mfcs" _MFC_FILENAME_VER "d.lib")
		#else
			#pragma comment(lib, "mfc" _MFC_FILENAME_VER ".lib")
			#pragma comment(lib, "mfcs" _MFC_FILENAME_VER ".lib")
		#endif
	#else
		#ifdef _DEBUG
			#pragma comment(lib, "mfc" _MFC_FILENAME_VER "ud.lib")
			#pragma comment(lib, "mfcs" _MFC_FILENAME_VER "ud.lib")
		#else
			#pragma comment(lib, "mfc" _MFC_FILENAME_VER "u.lib")
			#pragma comment(lib, "mfcs" _MFC_FILENAME_VER "u.lib")
		#endif
	#endif
#endif

#ifdef _DLL
	#if !defined(_AFX_NO_DEBUG_CRT) && defined(_DEBUG)
		#pragma comment(lib, "msvcrtd.lib")
	#else
		#pragma comment(lib, "msvcrt.lib")
	#endif
#else
#ifdef _MT
	#if !defined(_AFX_NO_DEBUG_CRT) && defined(_DEBUG)
		#pragma comment(lib, "libcmtd.lib")
	#else
		#pragma comment(lib, "libcmt.lib")
	#endif
#else
	#if !defined(_AFX_NO_DEBUG_CRT) && defined(_DEBUG)
		#pragma comment(lib, "libcd.lib")
	#else
		#pragma comment(lib, "libc.lib")
	#endif
#endif
#endif

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "msimg32.lib")
#pragma comment(lib, "comdlg32.lib")
#pragma comment(lib, "winspool.lib")
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "shlwapi.lib")

// force inclusion of NOLIB.OBJ for /disallowlib directives
#pragma comment(linker, "/include:__afxForceEXCLUDE")

// force inclusion of DLLMODUL.OBJ for _USRDLL
#ifdef _USRDLL
#pragma comment(linker, "/include:__afxForceUSRDLL")
#endif

// force inclusion of STDAFX.OBJ for precompiled types
#ifdef _AFXDLL
#pragma comment(linker, "/include:__afxForceSTDAFX")
#endif

#endif //!_AFX_NOFORCE_LIBS

#if !defined( _AFX_NOFORCE_MANIFEST ) && !defined(_VC_NODEFAULTLIB) && defined( _AFXDLL )

#define __MFC_MAKE_STR_HELPER(x) #x
#define __MFC_MAKE_STR(x) __MFC_MAKE_STR_HELPER(x)

#include <mfcassem.h>

#if defined( _AFXDLL )
	#if _BIND_TO_CURRENT_MFC_VERSION
		#if defined(_M_IX86)
			#pragma comment(linker, "/include:__forceMFCManifestCUR")
		#else
			#pragma comment(linker, "/include:_forceMFCManifestCUR")
		#endif
	#endif
#endif

#endif	// !_AFX_NOFORCE_MANIFEST && !_VC_NODEFAULTLIB && _AFXDLL

#ifdef _MANAGED

#ifndef AFX_NO_CLR_COINIT_STA
#pragma comment(linker, "/CLRTHREADATTRIBUTE:STA")
#endif 

#endif //_MANAGED
/////////////////////////////////////////////////////////////////////////////
// Classes declared in this file
//   in addition to standard primitive data types and various helper macros

struct CRuntimeClass;          // object type information

class CObject;                        // the root of all objects classes

	class CException;                 // the root of all exceptions
		class CArchiveException;      // archive exception
		class CFileException;         // file exception
		class CSimpleException;
			class CMemoryException;       // out-of-memory exception
			class CNotSupportedException; // feature not supported exception
			class CInvalidArgException;	  // one of the parameters to the function is invalid

	class CFile;                      // raw binary file
		class CStdioFile;             // buffered stdio text/binary file
		class CMemFile;               // memory based file

// Non CObject classes
struct CFileStatus;                   // file status information
struct CMemoryState;                  // diagnostic memory support

class CArchive;                       // object persistence tool
class CDumpContext;                   // object diagnostic dumping

/////////////////////////////////////////////////////////////////////////////
// Other includes from standard "C" runtimes

#ifndef _INC_STRING
	#include <string.h>
#endif
#ifndef _INC_STDIO
	#include <stdio.h>
#endif
#ifndef _INC_STDLIB
	#include <stdlib.h>
#endif
#ifndef _INC_TIME
	#include <time.h>
#endif
#ifndef _INC_LIMITS
	#include <limits.h>
#endif
#ifndef _INC_STDDEF
	#include <stddef.h>
#endif
#ifndef _INC_STDARG
	#include <stdarg.h>
#endif
#ifndef _INC_ERRNO 
#include <errno.h>
#endif

#include <malloc.h>

#ifndef _AFX_NO_DEBUG_CRT
#ifndef _INC_CRTDBG
	#include <crtdbg.h>
#endif
#endif // _AFX_NO_DEBUG_CRT

#ifdef _AFX_OLD_EXCEPTIONS
#error MFC no longer supports setjmp/longjmp exception handling.
#endif

#ifdef _AFX_PACKING
#pragma pack(push, _AFX_PACKING)
#endif

/////////////////////////////////////////////////////////////////////////////
// Basic types
// abstract iteration position
struct __POSITION {};
typedef __POSITION* POSITION;

// Standard constants
#undef FALSE
#undef TRUE
#undef NULL

#define FALSE   0
#define TRUE    1
#define NULL    0

/////////////////////////////////////////////////////////////////////////////
// _AFX_FUNCNAME definition
#ifdef UNICODE
#define _AFX_FUNCNAME(_Name) _Name##W
#else
#define _AFX_FUNCNAME(_Name) _Name##A
#endif

/////////////////////////////////////////////////////////////////////////////
// Turn off warnings for /W4
// To resume any of these warning: #pragma warning(default: 4xxx)
// which should be placed after the AFX include files

#pragma warning(disable: 4505)  // unreferenced local function has been removed
#pragma warning(disable: 4511)  // private copy constructors are good to have
#pragma warning(disable: 4512)  // private operator= are good to have
#pragma warning(disable: 4514)  // unreferenced inlines are common
#pragma warning(disable: 4710)  // function not inlined
#pragma warning(disable: 4127)  // constant expression used in macros do while(0);

// warnings specific to _AFXDLL version
#ifdef _AFXDLL
#pragma warning(disable: 4275)  // deriving exported class from non-exported
#pragma warning(disable: 4251)  // using non-exported as public in exported
#endif

#ifdef _AFX_ALL_WARNINGS
#pragma warning( push )
#endif

// warnings generated with common MFC/Windows code
#pragma warning(disable: 4201)  // nameless unions are part of C++
#pragma warning(disable: 4191)  // pointer-to-function casting
// warnings caused by normal optimizations
#ifndef _DEBUG
#pragma warning(disable: 4701)  // local variable *may* be used without init
#pragma warning(disable: 4702)  // unreachable code caused by optimizations
#pragma warning(disable: 4189)  // initialized but unused variable
#pragma warning(disable: 4390)  // empty controlled statement
#endif
// warnings specific to _AFXDLL version
#ifdef _AFXDLL
#pragma warning(disable: 4204)  // non-constant aggregate initializer
#endif
#pragma warning(disable: 4263 4264)  // base class method is hidden

/////////////////////////////////////////////////////////////////////////////
// Diagnostic support

#ifdef _DEBUG

BOOL AFXAPI AfxAssertFailedLine(LPCSTR lpszFileName, int nLine);

void AFX_CDECL AfxTrace(LPCTSTR lpszFormat, ...);
// Note: file names are still ANSI strings (filenames rarely need UNICODE)
void AFXAPI AfxAssertValidObject(const CObject* pOb,
				LPCSTR lpszFileName, int nLine);
void AFXAPI AfxDump(const CObject* pOb); // Dump an object from CodeView

#include <atltrace.h>

// extern ATL::CTrace TRACE;
#define TRACE ATLTRACE

#define THIS_FILE          __FILE__
#define VERIFY(f)          ASSERT(f)
#define DEBUG_ONLY(f)      (f)

// The following trace macros are provided for backward compatiblity
//  (they also take a fixed number of parameters which provides
//   some amount of extra error checking)
#define TRACE0(sz)              TRACE(_T("%s"), _T(sz))
#define TRACE1(sz, p1)          TRACE(_T(sz), p1)
#define TRACE2(sz, p1, p2)      TRACE(_T(sz), p1, p2)
#define TRACE3(sz, p1, p2, p3)  TRACE(_T(sz), p1, p2, p3)

// These AFX_DUMP macros also provided for backward compatibility
#define AFX_DUMP0(dc, sz)   dc << _T(sz)
#define AFX_DUMP1(dc, sz, p1) dc << _T(sz) << p1

#else   // _DEBUG

#define VERIFY(f)          ((void)(f))
#define DEBUG_ONLY(f)      ((void)0)
#pragma warning(push)
#pragma warning(disable : 4793)
inline void AFX_CDECL AfxTrace(...) { }
#pragma warning(pop)
#define TRACE              __noop
#define TRACE0(sz)
#define TRACE1(sz, p1)
#define TRACE2(sz, p1, p2)
#define TRACE3(sz, p1, p2, p3)

#endif // !_DEBUG

#define ASSERT(f)          DEBUG_ONLY((void) ((f) || !::AfxAssertFailedLine(THIS_FILE, __LINE__) || (AfxDebugBreak(), 0)))
/* see ATL headers for commentary on this */
/* We use the name AFXASSUME to avoid name clashes */

#if defined(_PREFAST_) || defined (_DEBUG)
#define AFXASSUME(cond)			do { bool __afx_condVal=!!(cond); ASSERT(__afx_condVal); __analysis_assume(__afx_condVal); } while(0) 
#else
#define AFXASSUME(cond)			((void)0)
#endif

#define ASSERT_VALID(pOb)  DEBUG_ONLY((::AfxAssertValidObject(pOb, THIS_FILE, __LINE__)))

// Debug ASSERTs then throws. Retail throws if condition not met
#define ENSURE_THROW(cond, exception)	\
	do { int __afx_condVal=!!(cond); ASSERT(__afx_condVal); if (!(__afx_condVal)){exception;} } while (false)
#define ENSURE(cond)		ENSURE_THROW(cond, ::AfxThrowInvalidArgException() )
#define ENSURE_ARG(cond)	ENSURE_THROW(cond, ::AfxThrowInvalidArgException() )

// Debug ASSERT_VALIDs then throws. Retail throws if pOb is NULL
#define ENSURE_VALID_THROW(pOb, exception)	\
	do { ASSERT_VALID(pOb); if (!(pOb)){exception;} } while (false)
#define ENSURE_VALID(pOb)	ENSURE_VALID_THROW(pOb, ::AfxThrowInvalidArgException() )

#define ASSERT_POINTER(p, type) \
	ASSERT(((p) != NULL) && AfxIsValidAddress((p), sizeof(type), FALSE))

#define ASSERT_NULL_OR_POINTER(p, type) \
	ASSERT(((p) == NULL) || AfxIsValidAddress((p), sizeof(type), FALSE))

#ifdef _DEBUG
#define UNUSED(x)
#else
#define UNUSED(x) x
#endif
#define UNUSED_ALWAYS(x) x

#ifdef _DEBUG
#define REPORT_EXCEPTION(pException, szMsg) \
	do { \
		TCHAR szErrorMessage[512]; \
		if (pException->GetErrorMessage(szErrorMessage, sizeof(szErrorMessage)/sizeof(*szErrorMessage), 0)) \
			TRACE(traceAppMsg, 0, _T("%s (%s:%d)\n%s\n"), szMsg, _T(__FILE__), __LINE__, szErrorMessage); \
		else \
			TRACE(traceAppMsg, 0, _T("%s (%s:%d)\n"), szMsg, _T(__FILE__), __LINE__); \
		ASSERT(FALSE); \
	} while (0)
#else
#define REPORT_EXCEPTION(pException, szMsg) \
	do { \
		CString strMsg; \
		TCHAR  szErrorMessage[512]; \
		if (pException->GetErrorMessage(szErrorMessage, sizeof(szErrorMessage)/sizeof(*szErrorMessage), 0)) \
			strMsg.Format(_T("%s (%s:%d)\n%s"), szMsg, _T(__FILE__), __LINE__, szErrorMessage); \
		else \
			strMsg.Format(_T("%s (%s:%d)"), szMsg, _T(__FILE__), __LINE__); \
		AfxMessageBox(strMsg); \
	} while (0)
#endif

#define EXCEPTION_IN_DTOR(pException) \
	do { \
		REPORT_EXCEPTION((pException), _T("Exception thrown in destructor")); \
		delete pException; \
	} while (0)
	
#define AFX_BEGIN_DESTRUCTOR try {
#define AFX_END_DESTRUCTOR   } catch (CException *pException) { EXCEPTION_IN_DTOR(pException); }

/////////////////////////////////////////////////////////////////////////////
// Other implementation helpers

#define BEFORE_START_POSITION ((POSITION)-1L)

/////////////////////////////////////////////////////////////////////////////
// explicit initialization for general purpose classes

BOOL AFXAPI AfxInitialize(BOOL bDLL = FALSE, DWORD dwVersion = _MFC_VER);

#undef AFX_DATA
#define AFX_DATA AFX_CORE_DATA

/////////////////////////////////////////////////////////////////////////////
// Basic object model

// generate static object constructor for class registration
void AFXAPI AfxClassInit(CRuntimeClass* pNewClass);
struct AFX_CLASSINIT
	{ AFX_CLASSINIT(CRuntimeClass* pNewClass) { AfxClassInit(pNewClass); } };

struct CRuntimeClass
{
// Attributes
	LPCSTR m_lpszClassName;
	int m_nObjectSize;
	UINT m_wSchema; // schema number of the loaded class
	CObject* (PASCAL* m_pfnCreateObject)(); // NULL => abstract class
#ifdef _AFXDLL
	CRuntimeClass* (PASCAL* m_pfnGetBaseClass)();
#else
	CRuntimeClass* m_pBaseClass;
#endif

// Operations
	CObject* CreateObject();
	BOOL IsDerivedFrom(const CRuntimeClass* pBaseClass) const;

	// dynamic name lookup and creation
	static CRuntimeClass* PASCAL FromName(LPCSTR lpszClassName);
	static CRuntimeClass* PASCAL FromName(LPCWSTR lpszClassName);
	static CObject* PASCAL CreateObject(LPCSTR lpszClassName);
	static CObject* PASCAL CreateObject(LPCWSTR lpszClassName);

// Implementation
	void Store(CArchive& ar) const;
	static CRuntimeClass* PASCAL Load(CArchive& ar, UINT* pwSchemaNum);

	// CRuntimeClass objects linked together in simple list
	CRuntimeClass* m_pNextClass;       // linked list of registered classes
	const AFX_CLASSINIT* m_pClassInit;
};

/////////////////////////////////////////////////////////////////////////////
// Standard exception throws

void __declspec(noreturn) AFXAPI AfxThrowMemoryException();
void __declspec(noreturn) AFXAPI AfxThrowNotSupportedException();
void __declspec(noreturn) AFXAPI AfxThrowInvalidArgException();
void __declspec(noreturn) AFXAPI AfxThrowArchiveException(int cause,
	LPCTSTR lpszArchiveName = NULL);
void __declspec(noreturn) AFXAPI AfxThrowFileException(int cause, LONG lOsError = -1,
	LPCTSTR lpszFileName = NULL);
void __declspec(noreturn) AFXAPI AfxThrowOleException(LONG sc);

/////////////////////////////////////////////////////////////////////////////
// CRT functions

inline errno_t AfxCrtErrorCheck(errno_t error)
{
	switch(error)
	{
	case ENOMEM:
		AfxThrowMemoryException();
		break;
	case EINVAL:
	case ERANGE:
		AfxThrowInvalidArgException();
		break;
	case STRUNCATE:
	case 0:
		break;
	default:
		AfxThrowInvalidArgException();
		break;
	}
	return error;
}

#define AFX_CRT_ERRORCHECK(expr) \
	AfxCrtErrorCheck(expr)

inline void __cdecl Afx_clearerr_s(FILE *stream)
{
	AFX_CRT_ERRORCHECK(::clearerr_s(stream));
}

/////////////////////////////////////////////////////////////////////////////
// Strings

#ifndef _OLEAUTO_H_
	typedef LPWSTR BSTR;// must (semantically) match typedef in oleauto.h
#endif

/////////////////////////////////////////////////////////////////////////////
// class CObject is the root of all compliant objects

class AFX_NOVTABLE CObject
{
public:

// Object model (types, destruction, allocation)
	virtual CRuntimeClass* GetRuntimeClass() const;
	virtual ~CObject() = 0;  // virtual destructors are necessary

	// Diagnostic allocations
	void* PASCAL operator new(size_t nSize);
	void* PASCAL operator new(size_t, void* p);
	void PASCAL operator delete(void* p);
#if _MSC_VER >= 1200
	void PASCAL operator delete(void* p, void* pPlace);
#endif

#if defined(_DEBUG) && !defined(_AFX_NO_DEBUG_CRT)
	// for file name/line number tracking using DEBUG_NEW
	void* PASCAL operator new(size_t nSize, LPCSTR lpszFileName, int nLine);
#if _MSC_VER >= 1200
	void PASCAL operator delete(void *p, LPCSTR lpszFileName, int nLine);
#endif
#endif

	// Disable the copy constructor and assignment by default so you will get
	//   compiler errors instead of unexpected behaviour if you pass objects
	//   by value or assign objects.
protected:
	CObject();
private:
	CObject(const CObject& objectSrc);              // no implementation
	void operator=(const CObject& objectSrc);       // no implementation

// Attributes
public:
	BOOL IsSerializable() const;
	BOOL IsKindOf(const CRuntimeClass* pClass) const;

// Overridables
	virtual void Serialize(CArchive& ar);

#if defined(_DEBUG) || defined(_AFXDLL)
	// Diagnostic Support
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Implementation
public:
	static const CRuntimeClass classCObject;
#ifdef _AFXDLL
	static CRuntimeClass* PASCAL _GetBaseClass();
	static CRuntimeClass* PASCAL GetThisClass();
#endif
};

// Helper macros
#define _RUNTIME_CLASS(class_name) ((CRuntimeClass*)(&class_name::class##class_name))
#ifdef _AFXDLL
#define RUNTIME_CLASS(class_name) (class_name::GetThisClass())
#else
#define RUNTIME_CLASS(class_name) _RUNTIME_CLASS(class_name)
#endif
#define ASSERT_KINDOF(class_name, object) \
	ASSERT((object)->IsKindOf(RUNTIME_CLASS(class_name)))

// RTTI helper macros/functions
const CObject* AFX_CDECL AfxDynamicDownCast(CRuntimeClass* pClass, const CObject* pObject);
CObject* AFX_CDECL AfxDynamicDownCast(CRuntimeClass* pClass, CObject* pObject);
#define DYNAMIC_DOWNCAST(class_name, object) \
	(class_name*)AfxDynamicDownCast(RUNTIME_CLASS(class_name), object)

#ifdef _DEBUG
const CObject* AFX_CDECL AfxStaticDownCast(CRuntimeClass* pClass, const CObject* pObject);
CObject* AFX_CDECL AfxStaticDownCast(CRuntimeClass* pClass, CObject* pObject);
#define STATIC_DOWNCAST(class_name, object) \
	(static_cast<class_name*>(AfxStaticDownCast(RUNTIME_CLASS(class_name), object)))
#else
#define STATIC_DOWNCAST(class_name, object) (static_cast<class_name*>(object))
#endif

//////////////////////////////////////////////////////////////////////////////
// Helper macros for declaring CRuntimeClass compatible classes

#ifdef _AFXDLL
#define DECLARE_DYNAMIC(class_name) \
protected: \
	static CRuntimeClass* PASCAL _GetBaseClass(); \
public: \
	static const CRuntimeClass class##class_name; \
	static CRuntimeClass* PASCAL GetThisClass(); \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#define _DECLARE_DYNAMIC(class_name) \
protected: \
	static CRuntimeClass* PASCAL _GetBaseClass(); \
public: \
	static CRuntimeClass class##class_name; \
	static CRuntimeClass* PASCAL GetThisClass(); \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#else
#define DECLARE_DYNAMIC(class_name) \
public: \
	static const CRuntimeClass class##class_name; \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#define _DECLARE_DYNAMIC(class_name) \
public: \
	static CRuntimeClass class##class_name; \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#endif

// not serializable, but dynamically constructable
#define DECLARE_DYNCREATE(class_name) \
	DECLARE_DYNAMIC(class_name) \
	static CObject* PASCAL CreateObject();

#define _DECLARE_DYNCREATE(class_name) \
	_DECLARE_DYNAMIC(class_name) \
	static CObject* PASCAL CreateObject();

#define DECLARE_SERIAL(class_name) \
	_DECLARE_DYNCREATE(class_name) \
	AFX_API friend CArchive& AFXAPI operator>>(CArchive& ar, class_name* &pOb);

#ifdef _AFXDLL
#define IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew, class_init) \
	CRuntimeClass* PASCAL class_name::_GetBaseClass() \
		{ return RUNTIME_CLASS(base_class_name); } \
	AFX_COMDAT const CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			&class_name::_GetBaseClass, NULL, class_init }; \
	CRuntimeClass* PASCAL class_name::GetThisClass() \
		{ return _RUNTIME_CLASS(class_name); } \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return _RUNTIME_CLASS(class_name); }

#define _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew, class_init) \
	CRuntimeClass* PASCAL class_name::_GetBaseClass() \
		{ return RUNTIME_CLASS(base_class_name); } \
	AFX_COMDAT CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			&class_name::_GetBaseClass, NULL, class_init }; \
	CRuntimeClass* PASCAL class_name::GetThisClass() \
		{ return _RUNTIME_CLASS(class_name); } \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return _RUNTIME_CLASS(class_name); }

#else
#define IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew, class_init) \
	AFX_COMDAT const CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			RUNTIME_CLASS(base_class_name), NULL, class_init }; \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return RUNTIME_CLASS(class_name); }

#define _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew, class_init) \
	AFX_COMDAT CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			RUNTIME_CLASS(base_class_name), NULL, class_init }; \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return RUNTIME_CLASS(class_name); }

#endif

#define IMPLEMENT_DYNAMIC(class_name, base_class_name) \
	IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, NULL, NULL)

#define IMPLEMENT_DYNCREATE(class_name, base_class_name) \
	CObject* PASCAL class_name::CreateObject() \
		{ return new class_name; } \
	IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, \
		class_name::CreateObject, NULL)

#define IMPLEMENT_SERIAL(class_name, base_class_name, wSchema) \
	CObject* PASCAL class_name::CreateObject() \
		{ return new class_name; } \
	extern AFX_CLASSINIT _init_##class_name; \
	_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, \
		class_name::CreateObject, &_init_##class_name) \
	AFX_CLASSINIT _init_##class_name(RUNTIME_CLASS(class_name)); \
	CArchive& AFXAPI operator>>(CArchive& ar, class_name* &pOb) \
		{ pOb = (class_name*) ar.ReadObject(RUNTIME_CLASS(class_name)); \
			return ar; }

// optional bit for schema number that enables object versioning
#define VERSIONABLE_SCHEMA  (0x80000000)

/////////////////////////////////////////////////////////////////////////////
// other helpers

// zero fill everything after the vtbl pointer
#define AFX_ZERO_INIT_OBJECT(base_class) \
	memset(((base_class*)this)+1, 0, sizeof(*this) - sizeof(class base_class));


/////////////////////////////////////////////////////////////////////////////
// Exceptions

class AFX_NOVTABLE CException : public CObject
{
	// abstract class for dynamic type checking
	DECLARE_DYNAMIC(CException)

public:
// Constructors
	CException();   // sets m_bAutoDelete = TRUE
	explicit CException(BOOL bAutoDelete);   // sets m_bAutoDelete = bAutoDelete

// Operations
	void Delete();  // use to delete exception in 'catch' block

	virtual BOOL GetErrorMessage(_Out_z_cap_(nMaxError) LPTSTR lpszError, _In_ UINT nMaxError,
		_Out_opt_ PUINT pnHelpContext = NULL) const ;
	virtual BOOL GetErrorMessage(_Out_z_cap_(nMaxError) LPTSTR lpszError, _In_ UINT nMaxError,
		_Out_opt_ PUINT pnHelpContext = NULL);
	virtual int ReportError(UINT nType = MB_OK, UINT nMessageID = 0);

// Implementation (setting m_bAutoDelete to FALSE is advanced)
public:
	virtual ~CException() = 0;
	BOOL m_bAutoDelete;
#ifdef _DEBUG
	void PASCAL operator delete(void* pbData);
#if _MSC_VER >= 1200
	void PASCAL operator delete(void* pbData, LPCSTR lpszFileName, int nLine);
#endif
protected:
	BOOL m_bReadyForDelete;
#endif
};

// ---- copy of afxstr.h
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/////////////////////////////////////////////////////////////////////////////
// AFXSTR.H - Framework-independent, templateable string class

#ifndef __AFXSTR_H__
#define __AFXSTR_H__

#pragma once

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, off)
#endif

#ifndef _AFX
#error afxstr.h can only be used in MFC projects.  Use atlstr.h
#endif

#include <mbstring.h>

HINSTANCE AFXAPI AfxGetResourceHandle();
HINSTANCE AFXAPI AfxFindStringResourceHandle(UINT nID);

UINT_PTR AFXAPI AfxReadStringLength(CArchive& ar, int& nCharSize);
void AFXAPI AfxWriteStringLength(CArchive& ar, UINT_PTR nLength, BOOL bUnicode);

#include <atlcore.h>
// ---- copy of atlsimpstr.h
// This is a part of the Active Template Library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __ATLSIMPSTR_H__
#define __ATLSIMPSTR_H__

#pragma once

#include <atldef.h>
#include <atlcore.h>
#include <atlexcept.h>
#include <atlmem.h>

extern "C"
{
	LONG __cdecl _InterlockedIncrement( LONG volatile * pn );
	LONG __cdecl _InterlockedDecrement( LONG volatile * pn );
};

#pragma intrinsic( _InterlockedIncrement )
#pragma intrinsic( _InterlockedDecrement )

#pragma pack(push,_ATL_PACKING)
namespace ATL
{

struct CStringData;

__interface IAtlStringMgr
{
public:
	// Allocate a new CStringData
	CStringData* Allocate( int nAllocLength, int nCharSize ) throw();
	// Free an existing CStringData
	void Free( CStringData* pData ) throw();
	// Change the size of an existing CStringData
	CStringData* Reallocate( CStringData* pData, int nAllocLength, int nCharSize ) throw();
	// Get the CStringData for a Nil string
	CStringData* GetNilString() throw();
	IAtlStringMgr* Clone() throw();
};

#ifdef _M_IX86
#ifndef _M_CEE
#define _AtlInterlockedIncrement _InterlockedIncrement
#define _AtlInterlockedDecrement _InterlockedDecrement
#else
#define _AtlInterlockedIncrement InterlockedIncrement
#define _AtlInterlockedDecrement InterlockedDecrement
/* managed code must use the non-intrinsics */
#ifdef InterlockedIncrement
#undef InterlockedIncrement
#endif
#ifdef InterlockedDecrement
#undef InterlockedDecrement
#endif
#endif  // !_M_CEE
#else
#define _AtlInterlockedIncrement InterlockedIncrement
#define _AtlInterlockedDecrement InterlockedDecrement
#endif  // _M_IX86_

struct CStringData
{
	IAtlStringMgr* pStringMgr;  // String manager for this CStringData
	int nDataLength;  // Length of currently used data in XCHARs (not including terminating null)
	int nAllocLength;  // Length of allocated data in XCHARs (not including terminating null)
	long nRefs;     // Reference count: negative == locked
	// XCHAR data[nAllocLength+1]  // A CStringData is always followed in memory by the actual array of character data

	void* data() throw()
	{
		return (this+1);
	}

	void AddRef() throw()
	{
		ATLASSERT(nRefs > 0);
		_AtlInterlockedIncrement(&nRefs);
	}
	bool IsLocked() const throw()
	{
		return nRefs < 0;
	}
	bool IsShared() const throw()
	{
		return( nRefs > 1 ); 
	}
	void Lock() throw()
	{
		ATLASSERT( nRefs <= 1 );
		nRefs--;  // Locked buffers can't be shared, so no interlocked operation necessary
		if( nRefs == 0 )
		{
			nRefs = -1;
		}
	}
	void Release() throw()
	{
		ATLASSERT( nRefs != 0 );

		if( _AtlInterlockedDecrement( &nRefs ) <= 0 )
		{
			pStringMgr->Free( this );
		}
	}
	void Unlock() throw()
	{
		ATLASSERT( IsLocked() );

		if(IsLocked())
		{
			nRefs++;  // Locked buffers can't be shared, so no interlocked operation necessary
			if( nRefs == 0 )
			{
				nRefs = 1;
			}
		}
	}
};

class CNilStringData :
	public CStringData
{
public:
	CNilStringData() throw()
	{
		pStringMgr = NULL;
		nRefs = 2;  // Never gets freed by IAtlStringMgr
		nDataLength = 0;
		nAllocLength = 0;
		achNil[0] = 0;
		achNil[1] = 0;
	}

	void SetManager( _In_ IAtlStringMgr* pMgr ) throw()
	{
		ATLASSERT( pStringMgr == NULL );
		pStringMgr = pMgr;
	}

public:
	wchar_t achNil[2];
};

template< typename BaseType, const int t_nSize >
class CStaticString
{
public:
	CStaticString( _In_ const BaseType* psz ) :
		m_psz( psz )
	{
	}

	operator const BaseType*() const
	{
		return m_psz;
	}

	static int __cdecl GetLength() 
	{
		return (t_nSize/sizeof( BaseType ))-1;
	}

private:
	const BaseType* m_psz;

private:
	CStaticString( const CStaticString& str ) throw();
	CStaticString& operator=( const CStaticString& str ) throw();
};

#define _ST( psz ) ATL::CStaticString< TCHAR, sizeof( _T( psz ) ) >( _T( psz ) )
#define _SA( psz ) ATL::CStaticString< char, sizeof( psz ) >( psz )
#define _SW( psz ) ATL::CStaticString< wchar_t, sizeof( L##psz ) >( L##psz )
#define _SO( psz ) _SW( psz )

template< typename BaseType = char >
class ChTraitsBase
{
public:
	typedef char XCHAR;
	typedef LPSTR PXSTR;
	typedef LPCSTR PCXSTR;
	typedef wchar_t YCHAR;
	typedef LPWSTR PYSTR;
	typedef LPCWSTR PCYSTR;
};

template<>
class ChTraitsBase< wchar_t >
{
public:
	typedef wchar_t XCHAR;
	typedef LPWSTR PXSTR;
	typedef LPCWSTR PCXSTR;
	typedef char YCHAR;
	typedef LPSTR PYSTR;
	typedef LPCSTR PCYSTR;
};

template< typename TCharType, bool t_bMFCDLL = false >
class CStrBufT;

template< typename BaseType , bool t_bMFCDLL = false>
class CSimpleStringT
{
public:
	typedef typename ChTraitsBase< BaseType >::XCHAR XCHAR;
	typedef typename ChTraitsBase< BaseType >::PXSTR PXSTR;
	typedef typename ChTraitsBase< BaseType >::PCXSTR PCXSTR;
	typedef typename ChTraitsBase< BaseType >::YCHAR YCHAR;
	typedef typename ChTraitsBase< BaseType >::PYSTR PYSTR;
	typedef typename ChTraitsBase< BaseType >::PCYSTR PCYSTR;

public:
	explicit CSimpleStringT( _In_ IAtlStringMgr* pStringMgr )
	{
		ATLENSURE( pStringMgr != NULL );
		CStringData* pData = pStringMgr->GetNilString();
		Attach( pData );
	}
	
	CSimpleStringT( _In_ const CSimpleStringT& strSrc )
	{
		CStringData* pSrcData = strSrc.GetData();
		CStringData* pNewData = CloneData( pSrcData );
		Attach( pNewData );
	}
	
	CSimpleStringT( _In_ const CSimpleStringT<BaseType, !t_bMFCDLL>& strSrc )
	{
		CStringData* pSrcData = strSrc.GetData();
		CStringData* pNewData = CloneData( pSrcData );
		Attach( pNewData );
	}
	
	CSimpleStringT( _In_ PCXSTR pszSrc, _In_ IAtlStringMgr* pStringMgr )
	{
		ATLENSURE( pStringMgr != NULL );

		int nLength = StringLength( pszSrc );
		CStringData* pData = pStringMgr->Allocate( nLength, sizeof( XCHAR ) );
		if( pData == NULL )
		{
			ThrowMemoryException();
		}
		Attach( pData );
		SetLength( nLength );
		CopyChars( m_pszData, nLength, pszSrc, nLength );
	}
	CSimpleStringT( _In_ const XCHAR* pchSrc, _In_ int nLength, _In_ IAtlStringMgr* pStringMgr )
	{
		ATLENSURE( pStringMgr != NULL );
		
		if(pchSrc == NULL && nLength != 0)
			AtlThrow(E_INVALIDARG);

		CStringData* pData = pStringMgr->Allocate( nLength, sizeof( XCHAR ) );
		if( pData == NULL )
		{
			ThrowMemoryException();
		}
		Attach( pData );
		SetLength( nLength );
		CopyChars( m_pszData, nLength, pchSrc, nLength );
	}
	~CSimpleStringT() throw()
	{
		CStringData* pData = GetData();
		pData->Release();
	}
	
	operator CSimpleStringT<BaseType, !t_bMFCDLL>&()
	{
		return *(CSimpleStringT<BaseType, !t_bMFCDLL>*)this;
	}

	CSimpleStringT& operator=( _In_ const CSimpleStringT& strSrc )
	{
		CStringData* pSrcData = strSrc.GetData();
		CStringData* pOldData = GetData();
		if( pSrcData != pOldData)
		{
			if( pOldData->IsLocked() || pSrcData->pStringMgr != pOldData->pStringMgr )
			{
				SetString( strSrc.GetString(), strSrc.GetLength() );
			}
			else
			{
				CStringData* pNewData = CloneData( pSrcData );
				pOldData->Release();
				Attach( pNewData );
			}
		}

		return( *this );
	}
	
	CSimpleStringT& operator=( _In_ const CSimpleStringT<BaseType, !t_bMFCDLL>& strSrc )
	{
		CStringData* pSrcData = strSrc.GetData();
		CStringData* pOldData = GetData();
		if( pSrcData != pOldData)
		{
			if( pOldData->IsLocked() || pSrcData->pStringMgr != pOldData->pStringMgr )
			{
				SetString( strSrc.GetString(), strSrc.GetLength() );
			}
			else
			{
				CStringData* pNewData = CloneData( pSrcData );
				pOldData->Release();
				Attach( pNewData );
			}
		}

		return( *this );
	}
	
	CSimpleStringT& operator=( _In_opt_ PCXSTR pszSrc )
	{
		SetString( pszSrc );

		return( *this );
	}

	CSimpleStringT& operator+=( _In_ const CSimpleStringT& strSrc )
	{
		Append( strSrc );

		return( *this );
	}
	template <bool bMFCDLL>
	CSimpleStringT& operator+=( _In_ const CSimpleStringT<BaseType, bMFCDLL>& strSrc )
	{
		Append( strSrc );

		return( *this );
	}
	
	CSimpleStringT& operator+=( _In_opt_z_ PCXSTR pszSrc )
	{
		Append( pszSrc );

		return( *this );
	}
	template< int t_nSize >
	CSimpleStringT& operator+=( _In_ const CStaticString< XCHAR, t_nSize >& strSrc )
	{
		Append( static_cast<const XCHAR *>(strSrc), strSrc.GetLength() );

		return( *this );
	}
	CSimpleStringT& operator+=( _In_ char ch )
	{
		AppendChar( XCHAR( ch ) );

		return( *this );
	}
	CSimpleStringT& operator+=( _In_ unsigned char ch )
	{
		AppendChar( XCHAR( ch ) );

		return( *this );
	}
	CSimpleStringT& operator+=( _In_ wchar_t ch )
	{
		AppendChar( XCHAR( ch ) );

		return( *this );
	}

	XCHAR operator[]( _In_ int iChar ) const
	{
		ATLASSERT( (iChar >= 0) && (iChar <= GetLength()) );  // Indexing the '\0' is OK
		
		if( (iChar < 0) || (iChar > GetLength()) )
			AtlThrow(E_INVALIDARG);
			
		return( m_pszData[iChar] );
	}

	// 2007-08 calls CSimpleStringT::operator PCXSTR through the MFC import table
	__declspec(noinline) operator PCXSTR() const throw()
	{
		return( m_pszData );
	}

	void Append( _In_opt_z_ PCXSTR pszSrc )
	{
		Append( pszSrc, StringLength( pszSrc ) );
	}
	void Append( _In_opt_z_count_(nLength) PCXSTR pszSrc, _In_ int nLength )
	{
		// See comment in SetString() about why we do this
		UINT_PTR nOffset = pszSrc-GetString();

		UINT nOldLength = GetLength();
		if (nOldLength < 0)
		{
			// protects from underflow
			nOldLength = 0;
		}
		
		//Make sure the nLength is greater than zero
		ATLENSURE_THROW(nLength >=0, E_INVALIDARG);

		//Make sure we don't read pass end of the terminating NULL
		nLength = StringLengthN(pszSrc, nLength);

		//Make sure after the string doesn't exceed INT_MAX after appending
		ATLENSURE_THROW(INT_MAX - nLength >= static_cast<int>(nOldLength), E_INVALIDARG);

		int nNewLength = nOldLength+nLength;
		PXSTR pszBuffer = GetBuffer( nNewLength );
		if( nOffset <= nOldLength )
		{
			pszSrc = pszBuffer+nOffset;
			// No need to call CopyCharsOverlapped, since the destination is
			// beyond the end of the original buffer
		}
		CopyChars( pszBuffer+nOldLength, nLength, pszSrc, nLength );
		ReleaseBufferSetLength( nNewLength );
	}
	void AppendChar( _In_ XCHAR ch )
	{
		UINT nOldLength = GetLength();
		int nNewLength = nOldLength+1;
		PXSTR pszBuffer = GetBuffer( nNewLength );
		pszBuffer[nOldLength] = ch;
		ReleaseBufferSetLength( nNewLength );
	}
	void Append( _In_ const CSimpleStringT& strSrc )
	{
		Append( strSrc.GetString(), strSrc.GetLength() );
	}
	template <bool bMFCDLL>
	void Append( _In_ const CSimpleStringT<BaseType, bMFCDLL>& strSrc )
	{
		Append( strSrc.GetString(), strSrc.GetLength() );
	}	
	void Empty() throw()
	{
		CStringData* pOldData = GetData();
		IAtlStringMgr* pStringMgr = pOldData->pStringMgr;
		if( pOldData->nDataLength == 0 )
		{
			return;
		}

		if( pOldData->IsLocked() )
		{
			// Don't reallocate a locked buffer that's shrinking
			SetLength( 0 );
		}
		else
		{
			pOldData->Release();
			CStringData* pNewData = pStringMgr->GetNilString();
			Attach( pNewData );
		}
	}
	void FreeExtra()
	{
		CStringData* pOldData = GetData();
		int nLength = pOldData->nDataLength;
		IAtlStringMgr* pStringMgr = pOldData->pStringMgr;
		if( pOldData->nAllocLength == nLength )
		{
			return;
		}

		if( !pOldData->IsLocked() )  // Don't reallocate a locked buffer that's shrinking
		{
			CStringData* pNewData = pStringMgr->Allocate( nLength, sizeof( XCHAR ) );
			if( pNewData == NULL )
			{
				SetLength( nLength );
				return;
			}
			
			CopyChars( PXSTR( pNewData->data() ), nLength, 
				PCXSTR( pOldData->data() ), nLength );

			pOldData->Release();
			Attach( pNewData );
			SetLength( nLength );
		}
	}

	int GetAllocLength() const throw()
	{
		return( GetData()->nAllocLength );
	}
	XCHAR GetAt( _In_ int iChar ) const
	{
		ATLASSERT( (iChar >= 0) && (iChar <= GetLength()) );  // Indexing the '\0' is OK
		if( (iChar < 0) || (iChar > GetLength()) )
			AtlThrow(E_INVALIDARG);		
			
		return( m_pszData[iChar] );
	}
	PXSTR GetBuffer()
	{
		CStringData* pData = GetData();
		if( pData->IsShared() )
		{
			Fork( pData->nDataLength );
		}

		return( m_pszData );
	}
	_Ret_cap_(nMinBufferLength + 1) PXSTR GetBuffer( _In_ int nMinBufferLength )
	{
		return( PrepareWrite( nMinBufferLength ) );
	}
	_Ret_cap_(nLength + 1) PXSTR GetBufferSetLength( _In_ int nLength )
	{
		PXSTR pszBuffer = GetBuffer( nLength );
		SetLength( nLength );

		return( pszBuffer );
	}
	int GetLength() const throw()
	{
		return( GetData()->nDataLength );
	}
	IAtlStringMgr* GetManager() const throw()
	{
		IAtlStringMgr* pStringMgr = GetData()->pStringMgr;
		return pStringMgr ? pStringMgr->Clone() : NULL;
	}

	_Ret_count_x_(m_nLength) PCXSTR GetString() const throw()
	{
		return( m_pszData );
	}
	bool IsEmpty() const throw()
	{
		return( GetLength() == 0 );
	}
	PXSTR LockBuffer()
	{
		CStringData* pData = GetData();
		if( pData->IsShared() )
		{
			Fork( pData->nDataLength );
			pData = GetData();  // Do it again, because the fork might have changed it
		}
		pData->Lock();

		return( m_pszData );
	}
	void UnlockBuffer() throw()
	{
		CStringData* pData = GetData();
		pData->Unlock();
	}
	void Preallocate( _In_ int nLength )
	{
		PrepareWrite( nLength );
	}
	void ReleaseBuffer( _In_ int nNewLength = -1 )
	{
		if( nNewLength == -1 )
		{
			int nAlloc = GetData()->nAllocLength;
			nNewLength = StringLengthN( m_pszData, nAlloc);
		}
		SetLength( nNewLength );
	}
	void ReleaseBufferSetLength( _In_ int nNewLength )
	{
		ATLASSERT( nNewLength >= 0 );
		SetLength( nNewLength );
	}
	void Truncate( _In_ int nNewLength )
	{
		ATLASSERT( nNewLength <= GetLength() );
		GetBuffer( nNewLength );
		ReleaseBufferSetLength( nNewLength );
	}
	void SetAt( _In_ int iChar, _In_ XCHAR ch )
	{
		ATLASSERT( (iChar >= 0) && (iChar < GetLength()) );

		if( (iChar < 0) || (iChar >= GetLength()) )
			AtlThrow(E_INVALIDARG);		
			
		int nLength = GetLength();
		PXSTR pszBuffer = GetBuffer();
		pszBuffer[iChar] = ch;
		ReleaseBufferSetLength( nLength );
			
	}
	void SetManager( _In_ IAtlStringMgr* pStringMgr )
	{
		ATLASSERT( IsEmpty() );

		CStringData* pData = GetData();
		pData->Release();
		pData = pStringMgr->GetNilString();
		Attach( pData );
	}
	void SetString( _In_opt_ PCXSTR pszSrc )
	{
		SetString( pszSrc, StringLength( pszSrc ) );
	}
	void SetString( _In_opt_count_(nLength) PCXSTR pszSrc, _In_ int nLength )
	{
		if( nLength == 0 )
		{
			Empty();
		}
		else
		{
			// It is possible that pszSrc points to a location inside of our 
			// buffer.  GetBuffer() might change m_pszData if (1) the buffer 
			// is shared or (2) the buffer is too small to hold the new 
			// string.  We detect this aliasing, and modify pszSrc to point
			// into the newly allocated buffer instead.
			
			if(pszSrc == NULL)
				AtlThrow(E_INVALIDARG);			
				
			UINT nOldLength = GetLength();
			UINT_PTR nOffset = pszSrc-GetString();
			// If 0 <= nOffset <= nOldLength, then pszSrc points into our 
			// buffer

			PXSTR pszBuffer = GetBuffer( nLength );
			if( nOffset <= nOldLength )
			{
				CopyCharsOverlapped( pszBuffer, GetAllocLength(), 
					pszBuffer+nOffset, nLength );
			}
			else
			{
				CopyChars( pszBuffer, GetAllocLength(), pszSrc, nLength );
			}
			ReleaseBufferSetLength( nLength );
		}
	}

public:
	friend CSimpleStringT operator+(
		_In_ const CSimpleStringT& str1,
		_In_ const CSimpleStringT& str2 )
	{
		CSimpleStringT s( str1.GetManager() );

		Concatenate( s, str1, str1.GetLength(), str2, str2.GetLength() );

		return( s );
	}

	friend CSimpleStringT operator+(
		_In_ const CSimpleStringT& str1,
		_In_ PCXSTR psz2 )
	{
		CSimpleStringT s( str1.GetManager() );

		Concatenate( s, str1, str1.GetLength(), psz2, StringLength( psz2 ) );

		return( s );
	}

	friend CSimpleStringT operator+(
		_In_ PCXSTR psz1,
		_In_ const CSimpleStringT& str2 )
	{
		CSimpleStringT s( str2.GetManager() );

		Concatenate( s, psz1, StringLength( psz1 ), str2, str2.GetLength() );

		return( s );
	}

	_ATL_INSECURE_DEPRECATE("CSimpleStringT::CopyChars must be passed a buffer size")
	static void __cdecl CopyChars
		( _Out_cap_(nChars) XCHAR* pchDest, _In_opt_count_(nChars) const XCHAR* pchSrc, _In_ int nChars ) throw()
	{
		#pragma warning (push)
		#pragma warning(disable : 4996)
		memcpy( pchDest, pchSrc, nChars*sizeof( XCHAR ) );
		#pragma warning (pop)
	}
	static void __cdecl CopyChars
		( _Out_cap_post_count_(nDestLen,nChars) XCHAR* pchDest, _In_ size_t nDestLen, _In_opt_count_(nChars) const XCHAR* pchSrc, _In_ int nChars ) throw()
	{
		memcpy_s( pchDest, nDestLen*sizeof( XCHAR ), 
			pchSrc, nChars*sizeof( XCHAR ) );
	}

	_ATL_INSECURE_DEPRECATE("CSimpleStringT::CopyCharsOverlapped must be passed a buffer size")
	static void __cdecl CopyCharsOverlapped
		( _Out_cap_(nChars) XCHAR* pchDest, _In_count_(nChars) const XCHAR* pchSrc, _In_ int nChars ) throw()
	{
		#pragma warning (push)
		#pragma warning(disable : 4996)
		memmove( pchDest, pchSrc, nChars*sizeof( XCHAR ) );
		#pragma warning (pop)
	}
	static void __cdecl CopyCharsOverlapped
		( _Out_cap_post_count_(nDestLen, nDestLen) XCHAR* pchDest, _In_ size_t nDestLen, _In_count_(nChars) const XCHAR* pchSrc, _In_ int nChars ) throw()
	{
		memmove_s( pchDest, nDestLen*sizeof( XCHAR ), 
			pchSrc, nChars*sizeof( XCHAR ) );
	}
	static int __cdecl StringLength( _In_opt_z_ const char* psz ) throw()
	{
		if( psz == NULL )
		{
			return( 0 );
		}
		return( int( strlen( psz ) ) );
	}
	static int __cdecl StringLength( _In_opt_z_ const wchar_t* psz ) throw()
	{
		if( psz == NULL )
		{
			return( 0 );
		}
		return( int( wcslen( psz ) ) );
	}
	static int __cdecl StringLengthN( _In_opt_z_ const char* psz, _In_ size_t sizeInXChar ) throw()
	{
		if( psz == NULL )
		{
			return( 0 );
		}
		return( int( strnlen( psz, sizeInXChar ) ) );
	}
	static int __cdecl StringLengthN( _In_opt_z_ const wchar_t* psz, _In_ size_t sizeInXChar ) throw()
	{
		if( psz == NULL )
		{
			return( 0 );
		}
		return( int( wcsnlen( psz, sizeInXChar ) ) );
	}

protected:
	static void __cdecl Concatenate( _Out_ CSimpleStringT& strResult, _In_count_(nLength1) PCXSTR psz1, _In_ int nLength1, _In_count_(nLength2) PCXSTR psz2, _In_ int nLength2 )
	{
		int nNewLength = nLength1+nLength2;
		PXSTR pszBuffer = strResult.GetBuffer( nNewLength );
		CopyChars( pszBuffer, nLength1, psz1, nLength1 );
		CopyChars( pszBuffer+nLength1, nLength2, psz2, nLength2 );
		strResult.ReleaseBufferSetLength( nNewLength );
	}
	ATL_NOINLINE __declspec( noreturn ) static void __cdecl ThrowMemoryException()
	{
		AtlThrow( E_OUTOFMEMORY );
	}

// Implementation
private:
	void Attach( _In_ CStringData* pData ) throw()
	{
		m_pszData = static_cast< PXSTR >( pData->data() );
	}
	ATL_NOINLINE void Fork( _In_ int nLength )
	{
		CStringData* pOldData = GetData();
		int nOldLength = pOldData->nDataLength;
		CStringData* pNewData = pOldData->pStringMgr->Clone()->Allocate( nLength, sizeof( XCHAR ) );
		if( pNewData == NULL )
		{
			ThrowMemoryException();
		}
		int nCharsToCopy = ((nOldLength < nLength) ? nOldLength : nLength)+1;  // Copy '\0'
		CopyChars( PXSTR( pNewData->data() ), nCharsToCopy, 
			PCXSTR( pOldData->data() ), nCharsToCopy );
		pNewData->nDataLength = nOldLength;
		pOldData->Release();
		Attach( pNewData );
	}
	CStringData* GetData() const throw()
	{
		return( reinterpret_cast< CStringData* >( m_pszData )-1 );
	}
	PXSTR PrepareWrite( _In_ int nLength )
	{
		CStringData* pOldData = GetData();
		int nShared = 1-pOldData->nRefs;  // nShared < 0 means true, >= 0 means false
		int nTooShort = pOldData->nAllocLength-nLength;  // nTooShort < 0 means true, >= 0 means false
		if( (nShared|nTooShort) < 0 )  // If either sign bit is set (i.e. either is less than zero), we need to copy data
		{
			PrepareWrite2( nLength );
		}

		return( m_pszData );
	}
	ATL_NOINLINE void PrepareWrite2( _In_ int nLength )
	{
		CStringData* pOldData = GetData();
		if( pOldData->nDataLength > nLength )
		{
			nLength = pOldData->nDataLength;
		}
		if( pOldData->IsShared() )
		{
			Fork( nLength );
		}
		else if( pOldData->nAllocLength < nLength )
		{
			// Grow exponentially, until we hit 1K.
			int nNewLength = pOldData->nAllocLength;
			if( nNewLength > 1024 )
			{
				nNewLength += 1024;
			}
			else
			{
				nNewLength *= 2;
			}
			if( nNewLength < nLength )
			{
				nNewLength = nLength;
			}
			Reallocate( nNewLength );
		}
	}
	ATL_NOINLINE void Reallocate( _In_ int nLength )
	{
		CStringData* pOldData = GetData();
		ATLASSERT( pOldData->nAllocLength < nLength );
		IAtlStringMgr* pStringMgr = pOldData->pStringMgr;
		if ( pOldData->nAllocLength >= nLength || nLength <= 0)
		{
			ThrowMemoryException();
			return;
		}
		CStringData* pNewData = pStringMgr->Reallocate( pOldData, nLength, sizeof( XCHAR ) );
		if( pNewData == NULL )
		{
			ThrowMemoryException();
		}
		Attach( pNewData );
	}

	void SetLength( _In_ int nLength )
	{
		ATLASSERT( nLength >= 0 );
		ATLASSERT( nLength <= GetData()->nAllocLength );

		if( nLength < 0 || nLength > GetData()->nAllocLength)
			AtlThrow(E_INVALIDARG);
			
		GetData()->nDataLength = nLength;
		m_pszData[nLength] = 0;
	}

	static CStringData* __cdecl CloneData( _In_ CStringData* pData )
	{
		CStringData* pNewData = NULL;

		IAtlStringMgr* pNewStringMgr = pData->pStringMgr->Clone();
		if( !pData->IsLocked() && (pNewStringMgr == pData->pStringMgr) )
		{
			pNewData = pData;
			pNewData->AddRef();
		}
		else
		{
			pNewData = pNewStringMgr->Allocate( pData->nDataLength, sizeof( XCHAR ) );
			if( pNewData == NULL )
			{
				ThrowMemoryException();
			}
			pNewData->nDataLength = pData->nDataLength;
			CopyChars( PXSTR( pNewData->data() ), pData->nDataLength+1,
				PCXSTR( pData->data() ), pData->nDataLength+1 );  // Copy '\0'
		}

		return( pNewData );
	}

public :
	typedef CStrBufT<BaseType, t_bMFCDLL> CStrBuf;
private:
	PXSTR m_pszData;
	
	friend class CSimpleStringT<BaseType, !t_bMFCDLL>;
};

template< typename TCharType, bool t_bMFCDLL >
class CStrBufT
{
public:
	typedef CSimpleStringT< TCharType, t_bMFCDLL> StringType;
	typedef typename StringType::XCHAR XCHAR;
	typedef typename StringType::PXSTR PXSTR;
	typedef typename StringType::PCXSTR PCXSTR;

	static const DWORD AUTO_LENGTH = 0x01;  // Automatically determine the new length of the string at release.  The string must be null-terminated.
	static const DWORD SET_LENGTH = 0x02;  // Set the length of the string object at GetBuffer time

public:
	explicit CStrBufT( _In_ StringType& str ) throw( ... ) :
		m_str( str ),
		m_pszBuffer( NULL ),
#ifdef _DEBUG
		m_nBufferLength( str.GetLength() ),
#endif
		m_nLength( str.GetLength() )
	{
		m_pszBuffer = m_str.GetBuffer();
	}
	
	CStrBufT( _In_ StringType& str, _In_ int nMinLength, _In_ DWORD dwFlags = AUTO_LENGTH ) throw( ... ) :
		m_str( str ),
		m_pszBuffer( NULL ),
#ifdef _DEBUG
		m_nBufferLength( nMinLength ),
#endif
		m_nLength( (dwFlags&AUTO_LENGTH) ? -1 : nMinLength )
	{
		if( dwFlags&SET_LENGTH )
		{
			m_pszBuffer = m_str.GetBufferSetLength( nMinLength );
		}
		else
		{
			m_pszBuffer = m_str.GetBuffer( nMinLength );
		}
	}

	~CStrBufT()
	{
		m_str.ReleaseBuffer( m_nLength );
	}

	operator PXSTR() throw()
	{
		return( m_pszBuffer );
	}
	operator PCXSTR() const throw()
	{
		return( m_pszBuffer );
	}

	void SetLength( _In_ int nLength )
	{
		ATLASSERT( nLength >= 0 );		
		ATLASSERT( nLength <= m_nBufferLength );

		if( nLength < 0 )
			AtlThrow(E_INVALIDARG);
		
		m_nLength = nLength;
	}

// Implementation
private:
	StringType& m_str;
	PXSTR m_pszBuffer;
	int m_nLength;
#ifdef _DEBUG
	int m_nBufferLength;
#endif

// Private copy constructor and copy assignment operator to prevent accidental use
private:
	CStrBufT( const CStrBufT& ) throw();
	CStrBufT& operator=( const CStrBufT& ) throw();
};

typedef CSimpleStringT< TCHAR > CSimpleString;
typedef CSimpleStringT< char > CSimpleStringA;
typedef CSimpleStringT< wchar_t > CSimpleStringW;
typedef CStrBufT< TCHAR > CStrBuf;
typedef CStrBufT< char > CStrBufA;
typedef CStrBufT< wchar_t > CStrBufW;

};  // namespace ATL
#pragma pack(pop)

#endif  // __ATLSIMPSTR_H__

// ---- end atlsimpstr.h
#include <cstringt.h>

ATL::IAtlStringMgr* AFXAPI AfxGetStringManager();

template< typename _CharType = char, class StringIterator = ATL::ChTraitsCRT< _CharType > >
class StrTraitMFC : 
	public StringIterator
{
public:
	static HINSTANCE FindStringResourceInstance( UINT nID ) throw()
	{
		return( AfxFindStringResourceHandle( nID ) );
	}

	static ATL::IAtlStringMgr* GetDefaultManager() throw()
	{
		return( AfxGetStringManager() );
	}
};

template< typename _CharType, class StringIterator>
class StrTraitMFC_DLL : public StringIterator
{
public:
	static HINSTANCE FindStringResourceInstance( UINT nID ) throw()
	{
		return( AfxFindStringResourceHandle( nID ) );
	}

	static ATL::IAtlStringMgr* GetDefaultManager() throw()
	{
		return( AfxGetStringManager() );
	}
};

// MFC-enabled compilation. Use MFC memory management and exceptions;
// also, use MFC module state.

// Don't import when MFC dll is being built
#if defined(_AFXDLL)

#if defined(_MFC_DLL_BLD)

template class ATL::CSimpleStringT< char, true >;
template class ATL::CStringT< char, StrTraitMFC_DLL< char > >;
template class ATL::CSimpleStringT< wchar_t, true >;
template class ATL::CStringT< wchar_t, StrTraitMFC_DLL< wchar_t > >;

#else

template class __declspec(dllimport) ATL::CSimpleStringT< char, true >;
template class __declspec(dllimport) ATL::CStringT< char, StrTraitMFC_DLL< char > >;
template class __declspec(dllimport) ATL::CSimpleStringT< wchar_t, true >;
template class __declspec(dllimport) ATL::CStringT< wchar_t, StrTraitMFC_DLL< wchar_t > >;
#if defined(_NATIVE_WCHAR_T)
template class __declspec(dllimport) ATL::CSimpleStringT< unsigned short, true >;
template class __declspec(dllimport) ATL::CStringT< unsigned short, StrTraitMFC_DLL< unsigned short > >;
#endif	// _NATIVE_WCHAR_T

#endif	// _MFC_DLL_BLD

typedef ATL::CStringT< wchar_t, StrTraitMFC_DLL< wchar_t > > CStringW;
typedef ATL::CStringT< char, StrTraitMFC_DLL< char > > CStringA;
typedef ATL::CStringT< TCHAR, StrTraitMFC_DLL< TCHAR > > CString;

#else

typedef ATL::CStringT< wchar_t, StrTraitMFC< wchar_t > > CStringW;
typedef ATL::CStringT< char, StrTraitMFC< char > > CStringA;
typedef ATL::CStringT< TCHAR, StrTraitMFC< TCHAR > > CString;

#endif	// !_WIN64 && _AFXDLL

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, on)
#endif

#endif	// __AFXSTR_H__ (whole file)

// ---- end afxstr.h

// ATL Classes

class CSimpleException : public CException
{
	DECLARE_DYNAMIC(CSimpleException)
	
	// base class for resource-critical MFC exceptions
	// handles ownership and initialization of an error message

public:
// Constructors
	CSimpleException();
	explicit CSimpleException(BOOL bAutoDelete);

// Operations
	virtual BOOL GetErrorMessage(_Out_z_cap_(nMaxError) LPTSTR lpszError, _In_ UINT nMaxError,
		_Out_opt_ PUINT pnHelpContext = NULL) const;

// Implementation (setting m_bAutoDelete to FALSE is advanced)
public:
	virtual ~CSimpleException() = 0;
	BOOL m_bAutoDelete;

	void InitString();      // used during MFC initialization

protected:
	BOOL m_bInitialized;
	BOOL m_bLoaded;
	TCHAR m_szMessage[128];
	UINT m_nResourceID;

#ifdef _DEBUG
	BOOL m_bReadyForDelete;
#endif
};

// helper routines for non-C++ EH implementations
	// for THROW_LAST auto-delete backward compatiblity
	void AFXAPI AfxThrowLastCleanup();

// other out-of-line helper functions
void AFXAPI AfxTryCleanup();

#ifndef _AFX_JUMPBUF
// Use portable 'jmp_buf' defined by ANSI by default.
#define _AFX_JUMPBUF jmp_buf
#endif

// Placed on frame for EXCEPTION linkage, or CException cleanup
struct AFX_EXCEPTION_LINK
{
	AFX_EXCEPTION_LINK* m_pLinkPrev;    // previous top, next in handler chain
	CException* m_pException;   // current exception (NULL in TRY block)

	AFX_EXCEPTION_LINK();       // for initialization and linking
	~AFX_EXCEPTION_LINK()       // for cleanup and unlinking
		{ AfxTryCleanup(); };
};

// Exception global state - never access directly
struct AFX_EXCEPTION_CONTEXT
{
	AFX_EXCEPTION_LINK* m_pLinkTop;

	// Note: most of the exception context is now in the AFX_EXCEPTION_LINK
};

#ifndef _PNH_DEFINED
typedef int (__cdecl * _PNH)( size_t );
#define _PNH_DEFINED
#endif

_PNH AFXAPI AfxGetNewHandler();
_PNH AFXAPI AfxSetNewHandler(_PNH pfnNewHandler);
int AFX_CDECL AfxNewHandler(size_t nSize);

void AFXAPI AfxAbort();


/////////////////////////////////////////////////////////////////////////////
// Exception macros using try, catch and throw
//  (for backward compatibility to previous versions of MFC)

#define TRY { AFX_EXCEPTION_LINK _afxExceptionLink; try {

#define CATCH(class, e) } catch (class* e) \
	{ ASSERT(e->IsKindOf(RUNTIME_CLASS(class))); \
		_afxExceptionLink.m_pException = e;

#define AND_CATCH(class, e) } catch (class* e) \
	{ ASSERT(e->IsKindOf(RUNTIME_CLASS(class))); \
		_afxExceptionLink.m_pException = e;

#define END_CATCH } }

#define THROW(e) throw e
#define THROW_LAST() (AfxThrowLastCleanup(), throw)

// Advanced macros for smaller code
#define CATCH_ALL(e) } catch (CException* e) \
	{ { ASSERT(e->IsKindOf(RUNTIME_CLASS(CException))); \
		_afxExceptionLink.m_pException = e;

#define AND_CATCH_ALL(e) } catch (CException* e) \
	{ { ASSERT(e->IsKindOf(RUNTIME_CLASS(CException))); \
		_afxExceptionLink.m_pException = e;

#define END_CATCH_ALL } } }

#define END_TRY } catch (CException* e) \
	{ ASSERT(e->IsKindOf(RUNTIME_CLASS(CException))); \
		_afxExceptionLink.m_pException = e; } }


/////////////////////////////////////////////////////////////////////////////
// Standard Exception classes

class CMemoryException : public CSimpleException
{
	DECLARE_DYNAMIC(CMemoryException)
public:
	CMemoryException();

// Implementation
public:
	explicit CMemoryException(BOOL bAutoDelete);
	CMemoryException(BOOL bAutoDelete, UINT nResourceID);
	virtual ~CMemoryException();
};

class CNotSupportedException : public CSimpleException
{
	DECLARE_DYNAMIC(CNotSupportedException)
public:
	CNotSupportedException();

// Implementation
public:
	explicit CNotSupportedException(BOOL bAutoDelete);
	CNotSupportedException(BOOL bAutoDelete, UINT nResourceID);
	virtual ~CNotSupportedException();
};
class CInvalidArgException : public CSimpleException
{
	DECLARE_DYNAMIC(CInvalidArgException)
public:
	CInvalidArgException();

// Implementation
public:
	CInvalidArgException(BOOL bAutoDelete);
	CInvalidArgException(BOOL bAutoDelete, UINT nResourceID);
	virtual ~CInvalidArgException();
};

class CArchiveException : public CException
{
	DECLARE_DYNAMIC(CArchiveException)
public:
	enum {
		none,
		genericException,
		readOnly,
		endOfFile,
		writeOnly,
		badIndex,
		badClass,
		badSchema
	};

#pragma warning(push)
#pragma warning(disable:4996)
	AFX_DEPRECATED("CArchiveException::generic clashes with future language keyword generic and should not be used. Use CArchiveException::genericException instead.") static const int __identifier(generic) = genericException;
#pragma warning(pop)

// Constructor
	/* explicit */ CArchiveException(int cause = CArchiveException::none,
		LPCTSTR lpszArchiveName = NULL);

// Attributes
	int m_cause;
	CString m_strFileName;

// Implementation
public:
	virtual ~CArchiveException();
#ifdef _DEBUG
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual BOOL GetErrorMessage(_Out_z_cap_(nMaxError) LPTSTR lpszError, _In_ UINT nMaxError,
		_Out_opt_ PUINT pnHelpContext = NULL) const;
};

class CFileException : public CException
{
	DECLARE_DYNAMIC(CFileException)

public:
	enum {
		none,
		genericException,
		fileNotFound,
		badPath,
		tooManyOpenFiles,
		accessDenied,
		invalidFile,
		removeCurrentDir,
		directoryFull,
		badSeek,
		hardIO,
		sharingViolation,
		lockViolation,
		diskFull,
		endOfFile
	};

#pragma warning(push)
#pragma warning(disable:4996)
	AFX_DEPRECATED("CFileException::generic clashes with future language keyword generic and should not be used. Use CFileException::genericException instead.") static const int __identifier(generic) = genericException;
#pragma warning(pop)

// Constructor
	/* explicit */ CFileException(int cause = CFileException::none, LONG lOsError = -1,
		LPCTSTR lpszArchiveName = NULL);

// Attributes
	int     m_cause;
	LONG    m_lOsError;
	CString m_strFileName;

// Operations
	// convert a OS dependent error code to a Cause
	static int PASCAL OsErrorToException(LONG lOsError);
	static int PASCAL ErrnoToException(int nErrno);

	// helper functions to throw exception after converting to a Cause
	static void PASCAL ThrowOsError(LONG lOsError, LPCTSTR lpszFileName = NULL);
	static void PASCAL ThrowErrno(int nErrno, LPCTSTR lpszFileName = NULL);

// Implementation
public:
	virtual ~CFileException();
#ifdef _DEBUG
	virtual void Dump(CDumpContext&) const;
#endif
	virtual BOOL GetErrorMessage(_Out_z_cap_(nMaxError) LPTSTR lpszError, _In_ UINT nMaxError,
		_Out_opt_ PUINT pnHelpContext = NULL) const;
};

/////////////////////////////////////////////////////////////////////////////
// File - raw unbuffered disk file I/O

class CFile : public CObject
{
	DECLARE_DYNAMIC(CFile)

public:
// Flag values
	enum OpenFlags {
		modeRead =         (int) 0x00000,
		modeWrite =        (int) 0x00001,
		modeReadWrite =    (int) 0x00002,
		shareCompat =      (int) 0x00000,
		shareExclusive =   (int) 0x00010,
		shareDenyWrite =   (int) 0x00020,
		shareDenyRead =    (int) 0x00030,
		shareDenyNone =    (int) 0x00040,
		modeNoInherit =    (int) 0x00080,
		modeCreate =       (int) 0x01000,
		modeNoTruncate =   (int) 0x02000,
		typeText =         (int) 0x04000, // typeText and typeBinary are
		typeBinary =       (int) 0x08000, // used in derived classes only
		osNoBuffer =       (int) 0x10000,
		osWriteThrough =   (int) 0x20000,
		osRandomAccess =   (int) 0x40000,
		osSequentialScan = (int) 0x80000,
		};

	enum Attribute {
		normal =    0x00,
		readOnly =  0x01,
		hidden =    0x02,
		system =    0x04,
		volume =    0x08,
		directory = 0x10,
		archive =   0x20
		};

	enum SeekPosition { begin = 0x0, current = 0x1, end = 0x2 };

	static AFX_DATA const HANDLE hFileNull;

// Constructors
	CFile();
	CFile(HANDLE hFile);
	CFile(LPCTSTR lpszFileName, UINT nOpenFlags);

// Attributes
	HANDLE m_hFile;
	operator HANDLE() const;

	virtual ULONGLONG GetPosition() const;
	BOOL GetStatus(CFileStatus& rStatus) const;
	virtual CString GetFileName() const;
	virtual CString GetFileTitle() const;
	virtual CString GetFilePath() const;
	virtual void SetFilePath(LPCTSTR lpszNewName);

// Operations
	virtual BOOL Open(LPCTSTR lpszFileName, UINT nOpenFlags,
		CFileException* pError = NULL);

	static void PASCAL Rename(LPCTSTR lpszOldName,
				LPCTSTR lpszNewName);
	static void PASCAL Remove(LPCTSTR lpszFileName);
	static BOOL PASCAL GetStatus(LPCTSTR lpszFileName,
				CFileStatus& rStatus);
	static void PASCAL SetStatus(LPCTSTR lpszFileName,
				const CFileStatus& status);

	ULONGLONG SeekToEnd();
	void SeekToBegin();

// Overridables
	virtual CFile* Duplicate() const;

	virtual ULONGLONG Seek(LONGLONG lOff, UINT nFrom);
	virtual void SetLength(ULONGLONG dwNewLen);
	virtual ULONGLONG GetLength() const;

	virtual UINT Read(void* lpBuf, UINT nCount);
	virtual void Write(const void* lpBuf, UINT nCount);

	virtual void LockRange(ULONGLONG dwPos, ULONGLONG dwCount);
	virtual void UnlockRange(ULONGLONG dwPos, ULONGLONG dwCount);

	virtual void Abort();
	virtual void Flush();
	virtual void Close();

// Implementation
public:
	virtual ~CFile();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	enum BufferCommand { bufferRead, bufferWrite, bufferCommit, bufferCheck };
	enum BufferFlags 
	{ 
		bufferDirect = 0x01,
		bufferBlocking = 0x02
	};
	virtual UINT GetBufferPtr(UINT nCommand, UINT nCount = 0,
		void** ppBufStart = NULL, void** ppBufMax = NULL);

protected:
	BOOL m_bCloseOnDelete;
	CString m_strFileName;
};

/////////////////////////////////////////////////////////////////////////////
// STDIO file implementation

class CStdioFile : public CFile
{
	DECLARE_DYNAMIC(CStdioFile)

public:
// Constructors
	CStdioFile();
	CStdioFile(FILE* pOpenStream);
	CStdioFile(LPCTSTR lpszFileName, UINT nOpenFlags);

// Attributes
	FILE* m_pStream;    // stdio FILE
						// m_hFile from base class is _fileno(m_pStream)

// Operations
	// reading and writing strings
	virtual void WriteString(LPCTSTR lpsz);
	virtual LPTSTR ReadString(_Out_z_cap_(nMax) LPTSTR lpsz, _In_ UINT nMax);
	virtual BOOL ReadString(CString& rString);

// Implementation
public:
	virtual ~CStdioFile();
#ifdef _DEBUG
	void Dump(CDumpContext& dc) const;
#endif
	virtual ULONGLONG GetPosition() const;
   virtual ULONGLONG GetLength() const;
	virtual BOOL Open(LPCTSTR lpszFileName, UINT nOpenFlags,
		CFileException* pError = NULL);
	virtual UINT Read(void* lpBuf, UINT nCount);
	virtual void Write(const void* lpBuf, UINT nCount);
	virtual ULONGLONG Seek(LONGLONG lOff, UINT nFrom);
	virtual void Abort();
	virtual void Flush();
	virtual void Close();

	// Unsupported APIs
	virtual CFile* Duplicate() const;
	virtual void LockRange(ULONGLONG dwPos, ULONGLONG dwCount);
	virtual void UnlockRange(ULONGLONG dwPos, ULONGLONG dwCount);
};

////////////////////////////////////////////////////////////////////////////
// Memory based file implementation

class CMemFile : public CFile
{
	DECLARE_DYNAMIC(CMemFile)

public:
// Constructors
	/* explicit */ CMemFile(UINT nGrowBytes = 1024);
	CMemFile(BYTE* lpBuffer, UINT nBufferSize, UINT nGrowBytes = 0);

// Operations
	void Attach(BYTE* lpBuffer, UINT nBufferSize, UINT nGrowBytes = 0);
	BYTE* Detach();

// Advanced Overridables
protected:
	virtual BYTE* Alloc(SIZE_T nBytes);
	virtual BYTE* Realloc(BYTE* lpMem, SIZE_T nBytes);
	virtual BYTE* Memcpy(BYTE* lpMemTarget, const BYTE* lpMemSource, SIZE_T nBytes);
	virtual void Free(BYTE* lpMem);
	virtual void GrowFile(SIZE_T dwNewLen);

// Implementation
protected:
	SIZE_T m_nGrowBytes;
	SIZE_T m_nPosition;
	SIZE_T m_nBufferSize;
	SIZE_T m_nFileSize;
	BYTE* m_lpBuffer;
	BOOL m_bAutoDelete;

public:
	virtual ~CMemFile();
#ifdef _DEBUG
	virtual void Dump(CDumpContext& dc) const;
	virtual void AssertValid() const;
#endif
	virtual ULONGLONG GetPosition() const;
	BOOL GetStatus(CFileStatus& rStatus) const;
	virtual ULONGLONG Seek(LONGLONG lOff, UINT nFrom);
	virtual void SetLength(ULONGLONG dwNewLen);
	virtual UINT Read(void* lpBuf, UINT nCount);
	virtual void Write(const void* lpBuf, UINT nCount);
	virtual void Abort();
	virtual void Flush();
	virtual void Close();
	virtual UINT GetBufferPtr(UINT nCommand, UINT nCount = 0,
		void** ppBufStart = NULL, void** ppBufMax = NULL);
	virtual ULONGLONG GetLength() const;

	// Unsupported APIs
	virtual CFile* Duplicate() const;
	virtual void LockRange(ULONGLONG dwPos, ULONGLONG dwCount);
	virtual void UnlockRange(ULONGLONG dwPos, ULONGLONG dwCount);
};

////////////////////////////////////////////////////////////////////////////
// Local file searches

#include <atltime.h>
using ATL::CTime;
using ATL::CTimeSpan;

class CFileFind : public CObject
{
public:
	CFileFind();
	virtual ~CFileFind();

// Attributes
public:
	ULONGLONG GetLength() const;
	virtual CString GetFileName() const;
	virtual CString GetFilePath() const;
	virtual CString GetFileTitle() const;
	virtual CString GetFileURL() const;
	virtual CString GetRoot() const;

	virtual BOOL GetLastWriteTime(FILETIME* pTimeStamp) const;
	virtual BOOL GetLastAccessTime(FILETIME* pTimeStamp) const;
	virtual BOOL GetCreationTime(FILETIME* pTimeStamp) const;
	virtual BOOL GetLastWriteTime(CTime& refTime) const;
	virtual BOOL GetLastAccessTime(CTime& refTime) const;
	virtual BOOL GetCreationTime(CTime& refTime) const;

	virtual BOOL MatchesMask(DWORD dwMask) const;

	virtual BOOL IsDots() const;
	// these aren't virtual because they all use MatchesMask(), which is
	BOOL IsReadOnly() const;
	BOOL IsDirectory() const;
	BOOL IsCompressed() const;
	BOOL IsSystem() const;
	BOOL IsHidden() const;
	BOOL IsTemporary() const;
	BOOL IsNormal() const;
	BOOL IsArchived() const;

// Operations
	void Close();
	virtual BOOL FindFile(LPCTSTR pstrName = NULL, DWORD dwUnused = 0);
	virtual BOOL FindNextFile();

protected:
	virtual void CloseContext();

// Implementation
protected:
	void* m_pFoundInfo;
	void* m_pNextInfo;
	HANDLE m_hContext;
	CString m_strRoot;
	TCHAR m_chDirSeparator;     // not '\\' for Internet classes

#ifdef _DEBUG
	void Dump(CDumpContext& dc) const;
	void AssertValid() const;
#endif

	DECLARE_DYNAMIC(CFileFind)
};

// CTimeSpan diagnostics and serialization
#ifdef _DEBUG
CDumpContext& AFXAPI operator<<(CDumpContext& dc,CTimeSpan dateSpanSrc);
#endif
CArchive& AFXAPI operator<<(CArchive& ar, CTimeSpan dateSpanSrc);
CArchive& AFXAPI operator>>(CArchive& ar, CTimeSpan& dateSpanSrc);

// CTime diagnostics and serialization
#ifdef _DEBUG
CDumpContext& AFXAPI operator<<(CDumpContext& dc, CTime dateSrc);
#endif
CArchive& AFXAPI operator<<(CArchive& ar, CTime dateSrc);
CArchive& AFXAPI operator>>(CArchive& ar, CTime& dateSrc);

/////////////////////////////////////////////////////////////////////////////
// File status

struct CFileStatus
{
	CTime m_ctime;          // creation date/time of file
	CTime m_mtime;          // last modification date/time of file
	CTime m_atime;          // last access date/time of file
	ULONGLONG m_size;            // logical size of file in bytes
	BYTE m_attribute;       // logical OR of CFile::Attribute enum values
	BYTE _m_padding;        // pad the structure to a WORD
	TCHAR m_szFullName[_MAX_PATH]; // absolute path name

#ifdef _DEBUG
	void Dump(CDumpContext& dc) const;
#endif
};

/////////////////////////////////////////////////////////////////////////////
// Diagnostic memory management routines

// Low level sanity checks for memory blocks
BOOL AFXAPI AfxIsValidAddress(const void* lp,
			UINT_PTR nBytes, BOOL bReadWrite = TRUE);
BOOL AFXAPI AfxIsValidString(LPCWSTR lpsz, int nLength = -1);
BOOL AFXAPI AfxIsValidString(LPCSTR lpsz, int nLength = -1);

// Sanity checks for ATOMs
BOOL AfxIsValidAtom(ATOM nAtom);
BOOL AfxIsValidAtom(LPCTSTR psz);

#if defined(_DEBUG) && !defined(_AFX_NO_DEBUG_CRT)

// Memory tracking allocation
void* AFX_CDECL operator new(size_t nSize, LPCSTR lpszFileName, int nLine);
#define DEBUG_NEW new(THIS_FILE, __LINE__)
#if _MSC_VER >= 1200
void AFX_CDECL operator delete(void* p, LPCSTR lpszFileName, int nLine);
#endif

void * __cdecl operator new[](size_t);
#if _MSC_VER >= 1210
void* __cdecl operator new[](size_t nSize, LPCSTR lpszFileName, int nLine);
void __cdecl operator delete[](void* p, LPCSTR lpszFileName, int nLine);
void __cdecl operator delete[](void *);
#endif

void* AFXAPI AfxAllocMemoryDebug(size_t nSize, BOOL bIsObject,
	LPCSTR lpszFileName, int nLine);
void AFXAPI AfxFreeMemoryDebug(void* pbData, BOOL bIsObject);

// Dump any memory leaks since program started
BOOL AFXAPI AfxDumpMemoryLeaks();

// Return TRUE if valid memory block of nBytes
BOOL AFXAPI AfxIsMemoryBlock(const void* p, UINT nBytes,
	LONG* plRequestNumber = NULL);

// Return TRUE if memory is sane or print out what is wrong
BOOL AFXAPI AfxCheckMemory();

#define afxMemDF _crtDbgFlag

enum AfxMemDF // memory debug/diagnostic flags
{
	allocMemDF          = _CRTDBG_ALLOC_MEM_DF,         // turn on debugging allocator
	delayFreeMemDF      = _CRTDBG_DELAY_FREE_MEM_DF,         // delay freeing memory
	checkAlwaysMemDF    = _CRTDBG_CHECK_ALWAYS_DF,          // AfxCheckMemory on every alloc/free
	checkEvery16MemDF	= _CRTDBG_CHECK_EVERY_16_DF,
	checkEvery128MemDF	= _CRTDBG_CHECK_EVERY_128_DF,
	checkEvery1024MemDF	= _CRTDBG_CHECK_EVERY_1024_DF,
	checkDefaultMemDF	= _CRTDBG_CHECK_DEFAULT_DF
};

#define AfxOutputDebugString TRACE

// turn on/off tracking for a short while
BOOL AFXAPI AfxEnableMemoryTracking(BOOL bTrack);

// Turn on/off the global flag _afxMemoryLeakOverride. if bEnable is TRUE
// then further calls to AfxEnableMemoryTracking() wont change the current
// memory tracking state, until AfxEnableMemoryLeakOverride(BOOL bEnable)
// is called again with bEnable == FALSE.
BOOL AFXAPI AfxEnableMemoryLeakOverride(BOOL bEnable);

// Advanced initialization: for overriding default diagnostics
BOOL AFXAPI AfxDiagnosticInit(void);

// A failure hook returns whether to permit allocation
typedef BOOL (AFXAPI* AFX_ALLOC_HOOK)(size_t nSize, BOOL bObject, LONG lRequestNumber);

// Set new hook, return old (never NULL)
AFX_ALLOC_HOOK AFXAPI AfxSetAllocHook(AFX_ALLOC_HOOK pfnAllocHook);

// Debugger hook on specified allocation request - Obsolete
void AFXAPI AfxSetAllocStop(LONG lRequestNumber);

// Memory state for snapshots/leak detection
struct CMemoryState
{
// Attributes
	enum blockUsage
	{
		freeBlock,    // memory not used
		objectBlock,  // contains a CObject derived class object
		bitBlock,     // contains ::operator new data
		crtBlock,
		ignoredBlock,
		nBlockUseMax  // total number of usages
	};

	_CrtMemState m_memState;
	LONG_PTR m_lCounts[nBlockUseMax];
	LONG_PTR m_lSizes[nBlockUseMax];
	LONG_PTR m_lHighWaterCount;
	LONG_PTR m_lTotalCount;

	CMemoryState();

// Operations
	void Checkpoint();  // fill with current state
	BOOL Difference(const CMemoryState& oldState,
					const CMemoryState& newState);  // fill with difference
	void UpdateData();

	// Output to afxDump
	void DumpStatistics() const;
	void DumpAllObjectsSince() const;
};

// Enumerate allocated objects or runtime classes
void AFXAPI AfxDoForAllObjects(void (AFX_CDECL *pfn)(CObject* pObject, void* pContext),
	void* pContext);
void AFXAPI AfxDoForAllClasses(void (AFX_CDECL *pfn)(const CRuntimeClass* pClass,
	void* pContext), void* pContext);

#else

// non-_DEBUG_ALLOC version that assume everything is OK
#define DEBUG_NEW new
#define AfxCheckMemory() TRUE
#define AfxIsMemoryBlock(p, nBytes) TRUE
#define AfxEnableMemoryTracking(bTrack) FALSE
#define AfxEnableMemoryLeakOverride(bEnable) TRUE
#define AfxOutputDebugString(lpsz) ::OutputDebugString(lpsz)

// diagnostic initialization
#ifndef _DEBUG
#define AfxDiagnosticInit() TRUE
#else
BOOL AFXAPI AfxDiagnosticInit(void);
#endif

#endif // _DEBUG

/////////////////////////////////////////////////////////////////////////////
// Archives for serializing CObject data

// needed for implementation
template<class TYPE, class ARG_TYPE>
class CArray;
class CPtrArray;
class CMapPtrToPtr;
class CDocument;

class CArchive
{
protected:
	enum SchemaMapReservedRefs { objTypeArrayRef = 1 };
	enum LoadArrayObjType{ typeUndefined = 0, typeCRuntimeClass = 1, typeCObject = 2 };	
public:
// Flag values
	enum Mode { store = 0, load = 1, bNoFlushOnDelete = 2, bNoByteSwap = 4 };

	CArchive(CFile* pFile, UINT nMode, int nBufSize = 4096, void* lpBuf = NULL);
	~CArchive();

// Attributes
	BOOL IsLoading() const;
	BOOL IsStoring() const;
	BOOL IsByteSwapping() const;
	BOOL IsBufferEmpty() const;

	CFile* GetFile() const;
	UINT GetObjectSchema(); // only valid when reading a CObject*
	void SetObjectSchema(UINT nSchema);

	// pointer to document being serialized -- must set to serialize
	//  COleClientItems in a document!
	CDocument* m_pDocument;

// Operations
	UINT Read(void* lpBuf, UINT nMax);
	void EnsureRead(void *lpBuf, UINT nCount);
	void Write(const void* lpBuf, UINT nMax);
	void Flush();
	void Close();
	void Abort();   // close and shutdown without exceptions

	// reading and writing strings
	void WriteString(LPCTSTR lpsz);
	LPTSTR ReadString(_Out_z_cap_(nMax+1) LPTSTR lpsz, _In_ UINT nMax);
	BOOL ReadString(CString& rString);

public:
	// Object I/O is pointer based to avoid added construction overhead.
	// Use the Serialize member function directly for embedded objects.
	friend CArchive& AFXAPI operator<<(CArchive& ar, const CObject* pOb);

	friend CArchive& AFXAPI operator>>(CArchive& ar, CObject*& pOb);
	friend CArchive& AFXAPI operator>>(CArchive& ar, const CObject*& pOb);

	// insertion operations
	CArchive& operator<<(BYTE by);
	CArchive& operator<<(WORD w);
	CArchive& operator<<(LONG l);
	CArchive& operator<<(DWORD dw);
	CArchive& operator<<(float f);
	CArchive& operator<<(double d);
	CArchive& operator<<(LONGLONG dwdw);
	CArchive& operator<<(ULONGLONG dwdw);

	CArchive& operator<<(int i);
	CArchive& operator<<(short w);
	CArchive& operator<<(char ch);
#ifdef _NATIVE_WCHAR_T_DEFINED
	CArchive& operator<<(wchar_t ch);
#endif
	CArchive& operator<<(unsigned u);

	template < typename BaseType , bool t_bMFCDLL>
	CArchive& operator<<(const ATL::CSimpleStringT<BaseType, t_bMFCDLL>& str);

	template< typename BaseType, class StringTraits >	
	CArchive& operator<<(const ATL::CStringT<BaseType, StringTraits>& str);
	
	template < typename BaseType , bool t_bMFCDLL>
	CArchive& operator>>(ATL::CSimpleStringT<BaseType, t_bMFCDLL>& str);

	template< typename BaseType, class StringTraits >
	CArchive& operator>>(ATL::CStringT<BaseType, StringTraits>& str);

	CArchive& operator<<(bool b);

	// extraction operations
	CArchive& operator>>(BYTE& by);
	CArchive& operator>>(WORD& w);
	CArchive& operator>>(DWORD& dw);
	CArchive& operator>>(LONG& l);
	CArchive& operator>>(float& f);
	CArchive& operator>>(double& d);
	CArchive& operator>>(LONGLONG& dwdw);
	CArchive& operator>>(ULONGLONG& dwdw);

	CArchive& operator>>(int& i);
	CArchive& operator>>(short& w);
	CArchive& operator>>(char& ch);
#ifdef _NATIVE_WCHAR_T_DEFINED
	CArchive& operator>>(wchar_t& ch);
#endif
	CArchive& operator>>(unsigned& u);
	CArchive& operator>>(bool& b);

	// object read/write
	CObject* ReadObject(const CRuntimeClass* pClass);
	void WriteObject(const CObject* pOb);
	// advanced object mapping (used for forced references)
	void MapObject(const CObject* pOb);

	// advanced versioning support
	void WriteClass(const CRuntimeClass* pClassRef);
	CRuntimeClass* ReadClass(const CRuntimeClass* pClassRefRequested = NULL,
		UINT* pSchema = NULL, DWORD* pObTag = NULL);
	void SerializeClass(const CRuntimeClass* pClassRef);

	// advanced operations (used when storing/loading many objects)
	void SetStoreParams(UINT nHashSize = 2053, UINT nBlockSize = 128);
	void SetLoadParams(UINT nGrowBy = 1024);

	void EnsureSchemaMapExists(CArray<LoadArrayObjType, const LoadArrayObjType&>** ppObjTypeArray = NULL);
// Implementation
public:
	BOOL m_bForceFlat;  // for COleClientItem implementation (default TRUE)
	BOOL m_bDirectBuffer;   // TRUE if m_pFile supports direct buffering
	BOOL m_bBlocking;  // TRUE if m_pFile can block for unbounded periods of time
	void FillBuffer(UINT nBytesNeeded);
	void CheckCount();  // throw exception if m_nMapCount is too large

	// special functions for reading and writing (16-bit compatible) counts
	DWORD_PTR ReadCount();
	void WriteCount(DWORD_PTR dwCount);

	// public for advanced use
	UINT m_nObjectSchema;
	CString m_strFileName;

protected:
	// archive objects cannot be copied or assigned
	CArchive(const CArchive& arSrc);
	void operator=(const CArchive& arSrc);

	BOOL m_nMode;
	BOOL m_bUserBuf;
	int m_nBufSize;
	CFile* m_pFile;
	BYTE* m_lpBufCur;
	BYTE* m_lpBufMax;
	BYTE* m_lpBufStart;

	// array/map for CObject* and CRuntimeClass* load/store
	UINT m_nMapCount;
	union
	{
		CPtrArray* m_pLoadArray;
		CMapPtrToPtr* m_pStoreMap;
	};
	// map to keep track of mismatched schemas
	CMapPtrToPtr* m_pSchemaMap;

	// advanced parameters (controls performance with large archives)
	UINT m_nGrowSize;
	UINT m_nHashSize;
};

/////////////////////////////////////////////////////////////////////////////
// Diagnostic dumping

// Note: AfxDumpStack is available in release builds, although it is always
//      statically linked so as to not negatively affect the size of MFCXX.DLL.

#define AFX_STACK_DUMP_TARGET_TRACE                     0x0001
#define AFX_STACK_DUMP_TARGET_CLIPBOARD 0x0002
#define AFX_STACK_DUMP_TARGET_BOTH                      0x0003
#define AFX_STACK_DUMP_TARGET_ODS                       0x0004
#ifdef _DEBUG
#define AFX_STACK_DUMP_TARGET_DEFAULT           AFX_STACK_DUMP_TARGET_TRACE
#else
#define AFX_STACK_DUMP_TARGET_DEFAULT           AFX_STACK_DUMP_TARGET_CLIPBOARD
#endif

void AFXAPI AfxDumpStack(DWORD dwFlags = AFX_STACK_DUMP_TARGET_DEFAULT);

class CDumpContext
{
public:
	CDumpContext(CFile* pFile = NULL);

// Attributes
	int GetDepth() const;      // 0 => this object, 1 => children objects
	void SetDepth(int nNewDepth);

// Operations
	CDumpContext& operator<<(LPCTSTR lpsz);
#ifdef _UNICODE
	CDumpContext& operator<<(LPCSTR lpsz);  // automatically widened
#else
	CDumpContext& operator<<(LPCWSTR lpsz); // automatically thinned
#endif
	template< typename BaseType, class StringTraits >
	CDumpContext& operator<<(const ATL::CStringT<BaseType, 
		StringTraits>& str)
	{
		*this << static_cast< const BaseType* >( str );
		return *this;
	}
	CDumpContext& operator<<(const void* lp);
	CDumpContext& operator<<(const CObject* pOb);
	CDumpContext& operator<<(const CObject& ob);
	CDumpContext& operator<<(BYTE by);
	CDumpContext& operator<<(WORD w);
	CDumpContext& DumpAsHex(BYTE b);
	CDumpContext& DumpAsHex(WORD w);
#ifdef _WIN64
	CDumpContext& operator<<(LONG l);
	CDumpContext& operator<<(DWORD dw);
	CDumpContext& operator<<(int n);
	CDumpContext& operator<<(UINT u);
	CDumpContext& DumpAsHex(LONG l);
	CDumpContext& DumpAsHex(DWORD dw);
	CDumpContext& DumpAsHex(int n);
	CDumpContext& DumpAsHex(UINT u);
#else
	CDumpContext& operator<<(LONG_PTR l);
	CDumpContext& operator<<(DWORD_PTR dw);
	CDumpContext& operator<<(INT_PTR n);
	CDumpContext& operator<<(UINT_PTR u);
	CDumpContext& DumpAsHex(LONG_PTR l);
	CDumpContext& DumpAsHex(DWORD_PTR dw);
	CDumpContext& DumpAsHex(INT_PTR n);
	CDumpContext& DumpAsHex(UINT_PTR u);
#endif
	CDumpContext& operator<<(float f);
	CDumpContext& operator<<(double d);
	CDumpContext& operator<<(LONGLONG n);
	CDumpContext& operator<<(ULONGLONG n);
	CDumpContext& DumpAsHex(LONGLONG n);
	CDumpContext& DumpAsHex(ULONGLONG n);
	CDumpContext& operator<<(HWND h);
	CDumpContext& operator<<(HDC h);
	CDumpContext& operator<<(HMENU h);
	CDumpContext& operator<<(HACCEL h);
	CDumpContext& operator<<(HFONT h);
	void HexDump(LPCTSTR lpszLine, BYTE* pby, int nBytes, int nWidth);
	void Flush();

// Implementation
protected:
	// dump context objects cannot be copied or assigned
	CDumpContext(const CDumpContext& dcSrc);
	void operator=(const CDumpContext& dcSrc);
	void OutputString(LPCTSTR lpsz);

	int m_nDepth;

public:
	CFile* m_pFile;
};

/////////////////////////////////////////////////////////////////////////////
int __cdecl _AfxInitManaged();

#ifdef _DEBUG
extern AFX_DATA CDumpContext afxDump;
extern AFX_DATA BOOL afxTraceEnabled;
#endif

#ifdef _DEBUG
#define AFXDUMP( exp ) (void)(afxDump<<exp)
#else
#define AFXDUMP( exp )
#endif

/////////////////////////////////////////////////////////////////////////////

#ifdef _AFX_PACKING
#pragma pack(pop)
#endif

#ifndef __AFXCOLL_H__
	#include <afxcoll.h>
	#ifndef __AFXSTATE_H__
		#include <afxstat_.h> // for _AFX_APP_STATE and _AFX_THREAD_STATE
	#endif
#endif

/////////////////////////////////////////////////////////////////////////////
// Inline function declarations

#ifdef _AFX_ENABLE_INLINES
#define _AFX_INLINE AFX_INLINE

#if !defined(_AFX_CORE_IMPL) || !defined(_AFXDLL) || defined(_DEBUG)
#define _AFX_PUBLIC_INLINE AFX_INLINE
#else
#define _AFX_PUBLIC_INLINE
#endif

#endif

#include <afx.inl>


#undef AFX_DATA
#define AFX_DATA

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, on)
#endif

#ifdef _AFX_ALL_WARNINGS
#pragma warning( pop )
#endif

#endif // __AFX_H__

/////////////////////////////////////////////////////////////////////////////

// ---- end afx.h
// XTPPopupBar.cpp : implementation of the CXTPPopupBar class.
//
// This file is a part of the XTREME COMMANDBARS MFC class library.
// (c)1998-2007 Codejock Software, All Rights Reserved.
//
// THIS SOURCE FILE IS THE PROPERTY OF CODEJOCK SOFTWARE AND IS NOT TO BE
// RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED WRITTEN
// CONSENT OF CODEJOCK SOFTWARE.
//
// THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS OUTLINED
// IN THE XTREME TOOLKIT PRO LICENSE AGREEMENT. CODEJOCK SOFTWARE GRANTS TO
// YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE THIS SOFTWARE ON A
// SINGLE COMPUTER.
//
// CONTACT INFORMATION:
// support@codejock.com
// http://www.codejock.com
//
/////////////////////////////////////////////////////////////////////////////

// ---- inlined Source/StdAfx.h
// ---- inlined Source/XTToolkitPro.h
// XTToolkitPro.h
//
// This file is a part of the XTREME TOOLKIT PRO MFC class library.
// (c)1998-2007 Codejock Software, All Rights Reserved.
//
// THIS SOURCE FILE IS THE PROPERTY OF CODEJOCK SOFTWARE AND IS NOT TO BE
// RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED WRITTEN
// CONSENT OF CODEJOCK SOFTWARE.
//
// THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS OUTLINED
// IN THE XTREME TOOLKIT PRO LICENSE AGREEMENT. CODEJOCK SOFTWARE GRANTS TO
// YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE THIS SOFTWARE ON A
// SINGLE COMPUTER.
//
// CONTACT INFORMATION:
// support@codejock.com
// http://www.codejock.com
//
/////////////////////////////////////////////////////////////////////////////

#pragma warning(disable : 4786) // Identifier was truncated to '255' characters in the debug information

#if (_MSC_VER > 1100)
#pragma warning(push)
#pragma pack(push, 8)
#endif

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>
#endif // _AFX_NO_OLE_SUPPORT

#ifdef _MFC_OVERRIDES_NEW
#define _INC_MALLOC
#endif

#include <afxpriv.h>    // MFC support for docking windows
#include <afxtempl.h>   // MFC template classes
#include <afxcview.h>   // MFC ListView / TreeView support
#include <shlobj.h>     // MFC support for shell extensions


#ifndef AFX_STATIC
#define AFX_STATIC static
#endif

//------------------------------------------------------------------------
// NOTE: If using the Xtreme Toolkit Pro as a static library linked to an
// application that is dynamically linked with MFC, you will need to do the
// following:
//
// Open the XTPToolkit_Lib project workspace and select one of the
// Win32 Dynamic build settings and build the library. Add the following
// lines of code to your stdafx.h file:
//
// #define _XTP_STATICLINK
// #include <XTToolkitPro.h>
//
// Add the following line of code to your *.rc2 file after the comment:
// "Add manually edited resources here...":
//
// #include "XTToolkitPro.rc"
//------------------------------------------------------------------------

#undef _XTP_EXT_CLASS

#if !defined(_AFXDLL) || defined(_XTP_STATICLINK)
#define _XTP_EXT_CLASS
#else
#define _XTP_EXT_CLASS  __declspec(dllimport)
#endif // !defined(_AFXDLL) || defined(_XTP_STATICLINK)

#if defined(_XTP_INCLUDE_DEPRECATED)
#include "Source/Common/XTPDeprecated.h"
#endif

#if !defined(_XTP_EXCLUDE_COMMON)
// ---- inlined Source/Common/Includes.h
// Includes.h : header file
//
// This file is a part of the XTREME TOOLKIT PRO MFC class library.
// (c)1998-2007 Codejock Software, All Rights Reserved.
//
// THIS SOURCE FILE IS THE PROPERTY OF CODEJOCK SOFTWARE AND IS NOT TO BE
// RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED WRITTEN
// CONSENT OF CODEJOCK SOFTWARE.
//
// THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS OUTLINED
// IN THE XTREME TOOLKIT PRO LICENSE AGREEMENT. CODEJOCK SOFTWARE GRANTS TO
// YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE THIS SOFTWARE ON A
// SINGLE COMPUTER.
//
// CONTACT INFORMATION:
// support@codejock.com
// http://www.codejock.com
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(__XTPCOMMONINCLUDES_H__)
#define __XTPCOMMONINCLUDES_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Source/Common/Resource.h"
#include "Source/Common/Tmschema.h"
#include "Source/Common/Uxtheme.h"

#include "Source/Common/XTPVersion.h"
#include "Source/Common/XTPMacros.h"
#include "Source/Common/XTPVC80Helpers.h"
#include "Source/Common/XTPVC50Helpers.h"
#include "Source/Common/XTPSystemHelpers.h"
#include "Source/Common/XTPResourceManager.h"
#include "Source/Common/XTPColorManager.h"
#include "Source/Common/XTPWinThemeWrapper.h"
#include "Source/Common/XTPDrawHelpers.h"
// ---- inlined Source/Common/XTPImageManager.h
// XTPImageManager.h : interface for the CXTPImageManager class.
//
// This file is a part of the XTREME TOOLKIT PRO MFC class library.
// (c)1998-2007 Codejock Software, All Rights Reserved.
//
// THIS SOURCE FILE IS THE PROPERTY OF CODEJOCK SOFTWARE AND IS NOT TO BE
// RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED WRITTEN
// CONSENT OF CODEJOCK SOFTWARE.
//
// THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS OUTLINED
// IN THE XTREME TOOLKIT PRO LICENSE AGREEMENT. CODEJOCK SOFTWARE GRANTS TO
// YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE THIS SOFTWARE ON A
// SINGLE COMPUTER.
//
// CONTACT INFORMATION:
// support@codejock.com
// http://www.codejock.com
//
/////////////////////////////////////////////////////////////////////////////

//{{AFX_CODEJOCK_PRIVATE
#if !defined(__XTPIMAGEMANAGER_H__)
#define __XTPIMAGEMANAGER_H__
//}}AFX_CODEJOCK_PRIVATE

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

//-----------------------------------------------------------------------
// Summary:
//     Image state enumerators.
// Example:
// <code>
// // Set Icons
// pCommandBars->GetImageManager()->SetIcons(IDR_MAINFRAME, xtpImageNormal);
// pCommandBars->GetImageManager()->SetIcons(IDR_MAINFRAME, IDR_MAINFRAME_HOT, xtpImageHot);
// </code>
// See Also: CXTPImageManager::SetIcon, CXTPImageManager::SetIcons
//
// <KEYWORDS xtpImageNormal, xtpImageDisabled, xtpImageHot, xtpImageChecked>
//-----------------------------------------------------------------------
enum XTPImageState
{
	xtpImageNormal,     // Normal image.
	xtpImageDisabled,   // Disabled image.
	xtpImageHot,        // Hot image.
	xtpImageChecked,    // Checked(selected) image.
	xtpImagePressed     // Pressed image.
};


class CXTPImageManager;
class CXTPImageManagerIconSet;
class CXTPImageManagerImageList;
class CXTPImageManagerIconHandle;
class CXTPImageManagerResource;
class CXTPPropExchange;

struct XTP_IMAGERESOURCE_INFO
{
	BOOL bAlpha;
	CRect rc;
	CXTPImageManagerResource* pResource;
};

class CXTPImageManagerResource
{
protected:
	class CBitmapDC : public CDC
	{
	public:
		CBitmapDC()
		{
			m_hOldBitmap = 0;
		}
		~CBitmapDC()
		{
			if (m_hOldBitmap)
			{
				::SelectObject(GetSafeHdc(), m_hOldBitmap);
			}
		}
		void SetBitmap(HBITMAP hBitmap)
		{
			if (hBitmap)
			{
				m_hOldBitmap = (HBITMAP)::SelectObject(GetSafeHdc(), hBitmap);
			}
			else if (m_hOldBitmap)
			{
				::SelectObject(GetSafeHdc(), m_hOldBitmap);
				m_hOldBitmap = NULL;
			}

		}
		HBITMAP m_hOldBitmap;
	};

public:
	CXTPImageManagerResource(CXTPImageManager* pImageManager, CSize szIcon);
	~CXTPImageManagerResource();

	XTP_IMAGERESOURCE_INFO* Add(CXTPImageManagerIconHandle& hHandle);
	void Clear(XTP_IMAGERESOURCE_INFO* pRInfo);

	void Draw(CDC* pDC, XTP_IMAGERESOURCE_INFO* pRInfo, CPoint pt, CSize szIcon, BOOL bDrawComposited);

	void CreateIcon(CXTPImageManagerIconHandle& hHandle, XTP_IMAGERESOURCE_INFO* pRInfo);

	CSize GetExtent() const;

private:
	XTP_IMAGERESOURCE_INFO* AllocBitmap();
	void RemoveAll();
	void DrawIconComposited(CDC* pDC, XTP_IMAGERESOURCE_INFO* pRInfo, CPoint pt, CSize szIcon);

protected:
	HBITMAP m_hbmpImage;
	HBITMAP m_hbmpMask;
	CBitmapDC m_dc;

	BYTE* m_pBits;
	CXTPImageManager* m_pImageManager;
	CSize m_szIcon;
	int m_nAllocWidth;
	CArray<XTP_IMAGERESOURCE_INFO*, XTP_IMAGERESOURCE_INFO*> m_arrIcons;
	CArray<XTP_IMAGERESOURCE_INFO*, XTP_IMAGERESOURCE_INFO*> m_arrAlloc;
	CRITICAL_SECTION m_cs;

	friend class CXTPImageManager;
};

//===========================================================================
// Summary:
//     CXTPImageManagerIconHandle is HICON wrapper class.
//===========================================================================
class _XTP_EXT_CLASS CXTPImageManagerIconHandle
{
public:

	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPImageManagerIconHandle object
	// Parameters:
	//     hIcon - Icon handle
	//     hBitmap - Bitmap handle
	//     hHandle - CXTPImageManagerIconHandle reference
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle();
	CXTPImageManagerIconHandle(HICON hIcon, BOOL bUseResources = TRUE); // <combine CXTPImageManagerIconHandle::CXTPImageManagerIconHandle>
	CXTPImageManagerIconHandle(HBITMAP hBitmap); // <combine CXTPImageManagerIconHandle::CXTPImageManagerIconHandle>
	CXTPImageManagerIconHandle(const CXTPImageManagerIconHandle& hHandle); // <combine CXTPImageManagerIconHandle::CXTPImageManagerIconHandle>

	//-------------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPImageManagerIconHandle object, handles cleanup and deallocation
	//-------------------------------------------------------------------------
	~CXTPImageManagerIconHandle();

	//-----------------------------------------------------------------------
	// Summary:
	//     This operator returns a HICON object whose value is copied from this CXTPImageManagerIconHandle object.
	// Returns:
	//     HICON handle.
	//-----------------------------------------------------------------------
	operator HICON() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Copies data from an HBITMAP or CXTPImageManagerIconHandle object
	// Parameters:
	//     handle - CXTPImageManagerIconHandle object
	//     hBitmap - Alpha bitmap handler
	//-----------------------------------------------------------------------
	void CopyHandle(HBITMAP hBitmap);
	void CopyHandle(CXTPImageManagerIconHandle& handle); // <combine CXTPImageManagerIconHandle::CopyHandle@HBITMAP>

	void BeforeModify();
	void AfterModify();

public:

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if the image has alpha channel.
	// Returns:
	//     TRUE if the image has alpha channel; otherwise returns FALSE
	//-----------------------------------------------------------------------
	BOOL IsAlpha() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns TRUE if class has no icon.
	// Returns:
	//     TRUE if m_hIcon member is NULL.
	//-----------------------------------------------------------------------
	BOOL IsEmpty() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves bitmap handle
	// Returns:
	//     32bit alpha bitmap
	//-----------------------------------------------------------------------
	HBITMAP GetBitmap() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the icon handle.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	HICON GetIcon() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the size of the icon.
	// Returns:
	//     Size of the icon.
	//-----------------------------------------------------------------------
	CSize GetExtent() const;

	void Draw(CDC* pDC, CPoint pt, CSize szIcon, BOOL bDrawComposited = FALSE);

public:

	//-------------------------------------------------------------------------
	// Summary:
	//     Release bitmap and icon handlers
	//-------------------------------------------------------------------------
	void Clear();

	//-------------------------------------------------------------------------
	// Summary:
	//     Creates an icon from resource bits describing the icon.
	// Parameters:
	//     hInst - Application instance handler
	//     lpszResourceName - Resource name identifier
	//     szIcon - Specifies the desired width and height, in pixels, of the icon.
	//     bGroupResource - TRUE to check if RT_GROUP_ICON resource exists.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE.
	//-------------------------------------------------------------------------
	BOOL CreateIconFromResource(LPCTSTR lpszResourceName, CSize szIcon, BOOL bGroupResource = TRUE);
	BOOL CreateIconFromResource(HINSTANCE hInst, LPCTSTR lpszResourceName, CSize szIcon, BOOL bGroupResource); // <combine CXTPImageManagerIconHandle::CreateIconFromResource@LPCTSTR@CSize@BOOL>

public:

	//-----------------------------------------------------------------------
	// Summary:
	//     This operator assigns the icon handler to a CXTPImageManagerIconHandle object.
	// Parameters:
	//     hIcon - source icon handler
	//-----------------------------------------------------------------------
	const CXTPImageManagerIconHandle& operator=(const HICON hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     This operator assigns the alpha bitmap handler to a CXTPImageManagerIconHandle object.
	// Parameters:
	//     hBitmap - Alpha bitmap handler
	const CXTPImageManagerIconHandle& operator=(const HBITMAP hBitmap);

	//-----------------------------------------------------------------------
	// Summary:
	//     Create alpha bitmap with valid alpha layer.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE.
	//-----------------------------------------------------------------------
	LPBYTE PreMultiply();

protected:
	void Init();

private:
	const CXTPImageManagerIconHandle& operator=(const CXTPImageManagerIconHandle&);
	CSize _GetExtent() const;


protected:
	HICON   m_hIcon;          // The underlying HICON handler for this CXTPImageManagerIconHandle object.
	HBITMAP m_hBitmap;        // The underlying Alpha bitmap handler for this CXTPImageManagerIconHandle object.
	LPBYTE m_pBits;           // Alpha bitmap bits;
	BOOL    m_bClearHandles;  // TRUE if object must destroy handlers.
	CXTPImageManager* m_pImageManager;
	XTP_IMAGERESOURCE_INFO* m_pRInfo;
	CSize m_szIcon;
	BOOL m_bUseResources;

private:
	friend class CXTPImageManagerIcon;
	friend class CXTPImageManagerResource;
};

//===========================================================================
// Summary:
//     Icons holder class.
//===========================================================================
class _XTP_EXT_CLASS CXTPImageManagerIcon : public CXTPCmdTarget
{
private:
	struct ICONDIRENTRY;
	struct ICONDIRHEADER;
	struct ICONIMAGE;
	struct GRPICONDIRENTRY;
	struct GRPICONDIR;

public:

	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPImageManagerIcon object.
	// Parameters:
	//     nID - Icon identifier.
	//     nWidth - Initial width for the icon.
	//     nHeight - Initial height for the icon.
	//     pIconSet - Parent icon set icon will belong.
	//     pImageList - Parent icon set icon will belong.
	//-----------------------------------------------------------------------
	CXTPImageManagerIcon(UINT nID, int nWidth, int nHeight, CXTPImageManagerIconSet* pIconSet = NULL);
	CXTPImageManagerIcon(UINT nID, int nWidth, int nHeight, CXTPImageManagerImageList* pImageList); //<combine CXTPImageManagerIcon::CXTPImageManagerIcon@UINT@int@int@CXTPImageManagerIconSet*>

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPImageManagerIcon object, handles cleanup and deallocation.
	//-----------------------------------------------------------------------
	~CXTPImageManagerIcon();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the image identifier.
	// Returns:
	//     Identifier of the image
	//-----------------------------------------------------------------------
	UINT GetID() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if the image has alpha channel.
	// Returns:
	//     TRUE if the image has alpha channel; otherwise returns FALSE
	//-----------------------------------------------------------------------
	BOOL IsAlpha() const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Checks if icons was scaled from another CXTPImageManagerIcon object.
	//-------------------------------------------------------------------------
	BOOL IsScaled() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the icon handle.
	// Parameters:
	//     imageState - Image state for icon to retrieve
	// Returns:
	//     Icon handle.
	// See Also: XTPImageState
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetIcon();
	CXTPImageManagerIconHandle& GetIcon(XTPImageState imageState); // <combine CXTPImageManagerIcon::GetIcon>

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the faded icon.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetFadedIcon();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the shadow for the icon.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetShadowIcon();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the shadow for the icon.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetCheckedIcon();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the pressed icon.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetPressedIcon();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves hot icon.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetHotIcon();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the disabled icon.
	// Parameters:
	//     bCreateIfNotExists - Create if image not exists.
	// Returns:
	//     Icon handle.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconHandle& GetDisabledIcon(BOOL bCreateIfNotExists = TRUE);

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines if disabled icon exists
	// Returns:
	//     TRUE if disabled icon exists
	//-----------------------------------------------------------------------
	BOOL HasDisabledIcon() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Creates a disabled icon.
	// Parameters:
	//     clrDisabledLight - The lightest color of icon to generate
	//     clrDisabledDark -  The darkest color of icon to generate
	//-----------------------------------------------------------------------
	void CreateDisabledIcon(COLORREF clrDisabledLight = (COLORREF)-1, COLORREF clrDisabledDark = (COLORREF)-1);

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the icon.
	// Parameters:
	//     hIcon - Icon handle to set.
	//     nIDResourceIcon - Icon resource identifier.
	//     nWidth - Width of icon.
	//     nHeight - Height of icon.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	//-----------------------------------------------------------------------
	BOOL SetIcon(CXTPImageManagerIconHandle hIcon);
	BOOL SetIcon(CXTPImageManagerIconHandle hIcon, XTPImageState imageState); // <combine CXTPImageManagerIcon::SetIcon@CXTPImageManagerIconHandle>
	BOOL SetIcon(UINT nIDResourceIcon, int nWidth, int nHeight); // <combine CXTPImageManagerIcon::SetIcon@CXTPImageManagerIconHandle>

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the disabled icon.
	// Parameters:
	//     hIcon - Icon handle to set.
	//-----------------------------------------------------------------------
	void SetDisabledIcon(CXTPImageManagerIconHandle hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the hot icon.
	// Parameters:
	//     hIcon - Icon handle to set.
	//-----------------------------------------------------------------------
	void SetHotIcon(CXTPImageManagerIconHandle hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the checked icon.
	// Parameters:
	//     hIcon - Icon handle to set.
	//-----------------------------------------------------------------------
	void SetCheckedIcon(CXTPImageManagerIconHandle hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the icon.
	// Parameters:
	//     hIcon - Icon handle to set.
	//-----------------------------------------------------------------------
	void SetNormalIcon(CXTPImageManagerIconHandle hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the pressed icon.
	// Parameters:
	//     hIcon - Icon handle to set.
	//-----------------------------------------------------------------------
	void SetPressedIcon(CXTPImageManagerIconHandle hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the size of the icon.
	// Parameters:
	//     hIcon - Icon handle.
	// Returns:
	//     Size of the icon.
	//-----------------------------------------------------------------------
	CSize GetExtent() const;
	static CSize AFX_CDECL GetExtent(HICON hIcon); // <COMBINE CXTPImageManagerIcon::GetExtent@const>

	//-----------------------------------------------------------------------
	// Summary:
	//     This method tests if file is alpha bitmap.
	// Parameters:
	//     pszFileName - File path.
	// Returns:
	//     TRUE if file is alpha bitmap
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsAlphaBitmapFile(LPCTSTR pszFileName);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method tests if file is png image.
	// Parameters:
	//     pszFileName - File path.
	// Returns:
	//     TRUE if file is png image
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsPngBitmapFile(LPCTSTR pszFileName);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method loads alpha bitmap from icon file.
	// Parameters:
	//     pszFileName - File path.
	//     nWidth - Icon width to load.
	// Returns:
	//     Alpha bitmap if icon with specified width was found; otherwise returns NULL.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL LoadAlphaIcon(LPCTSTR pszFileName, int nWidth);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method loads Alpha bitmap from resource file
	// Parameters:
	//     nIDResource - Resource identifier
	//     hModule - Handle to the instance of the module whose executable file contains the bitmap to be loaded.
	//     lpszResource - Long pointer to a null-terminated string that contains the name of the bitmap resource to be loaded
	// Remarks:
	//     Don't use LoadImage to load alpha bitmap, it loose alpha channel in some Windows.
	// Returns:
	//     Alpha bitmap handler.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL LoadAlphaBitmap(UINT nIDResource);
	static HBITMAP AFX_CDECL LoadAlphaBitmap(HMODULE hModule, LPCTSTR lpszResource); // <combine CXTPImageManagerIcon::LoadAlphaBitmap@UINT>

	//-----------------------------------------------------------------------
	// Summary:
	//     This method loads bitmap from file on disk
	// Parameters:
	//     lpszFileName - File name of bitmap or png file
	//     lbAlphaBitmap - Determines if bitmap contained alpha layer
	// Remarks:
	//     This method loads png or bitmap from file
	// Returns:
	//     Bitmap handler.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL LoadBitmapFromFile(LPCTSTR lpszFileName, BOOL* lbAlphaBitmap = NULL);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method loads Alpha bitmap from resource file
	// Parameters:
	//     hModule - Handle to the instance of the module whose executable file contains the bitmap to be loaded.
	//     lpszResource - Long pointer to a null-terminated string that contains the name of the bitmap resource to be loaded
	//     lbAlphaBitmap - Determines if bitmap contained alpha layer
	// Remarks:
	//     This method loads png or bitmap resource from file
	// Returns:
	//     Alpha bitmap handler.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL LoadBitmapFromResource(LPCTSTR lpszResource, BOOL* lbAlphaBitmap);
	static HBITMAP AFX_CDECL LoadBitmapFromResource(HMODULE hModule, LPCTSTR lpszResource, BOOL* lbAlphaBitmap); // <combine CXTPImageManagerIcon::LoadBitmapFromResource@LPCTSTR@BOOL*>

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if bitmap with specified resource has alpha channel.
	// Parameters:
	//     hModule - Module of the bitmap to check.
	//     lpBitmapName - Resource name of the bitmap to check.
	// Returns:
	//     TRUE if bitmap has alpha channel; otherwise returns FALSE.
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsAlphaBitmapResource(HMODULE hModule, LPCTSTR lpBitmapName);

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if bitmap with specified resource is png resource.
	// Parameters:
	//     hModule - Module of the bitmap to check.
	//     lpBitmapName - Resource name of the bitmap to check.
	// Returns:
	//     TRUE if bitmap is png resource; otherwise returns FALSE.
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsPngBitmapResource(HMODULE hModule, LPCTSTR lpBitmapName);

	//-----------------------------------------------------------------------
	// Summary:
	//     The DrawAlphaBitmap function displays bitmaps that have transparent or semitransparent pixels.
	// Parameters:
	//     pDC     - Pointer to destination device context
	//     ptDest      - upper-left corner of the  destination rectangle
	//     ptSrc      - upper-left corner of the source rectangle
	//     hBitmap - Alpha bitmap handler
	//     szDest  - Destination size
	//     szSrc   - Source size
	//-----------------------------------------------------------------------
	static void AFX_CDECL DrawAlphaBitmap(CDC* pDC, HBITMAP hBitmap, CPoint ptDest, CSize szDest, CPoint ptSrc = 0, CSize szSrc = 0);

	//-----------------------------------------------------------------------
	// Summary:
	//     Creates valid alpha bits to use in AlphaBlend.
	// Parameters:
	//     hBitmap - Alpha bitmap handler
	// Returns:
	//     Valid alpha bits
	// See Also: BLENDFUNCTION, AlphaBlend
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL PreMultiplyAlphaBitmap(HBITMAP hBitmap, BOOL* pbAlpha = NULL, LPBYTE* lpBits = NULL);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to create mirror copy of bitmap
	// Parameters:
	//     hBitmap - Bitmap handle to make copy
	// Returns: new mirror bitmap
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL InvertAlphaBitmap(HBITMAP hBitmap);

	//-----------------------------------------------------------------------
	// Summary:
	//     This helper method retrieves information about alpha bitmap and its alpha bits.
	// Parameters:
	//     dcSrc   - Reference to CDC
	//     hBitmap - Alpha bitmap
	//     pbmi    - Bitmap information
	//     pBits   - Bitmap bits
	//     nSize   - Size of bits array
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL GetBitmapBits(CDC& dcSrc, HBITMAP hBitmap, PBITMAPINFO& pbmi, LPVOID& pBits, UINT& nSize);

	//-----------------------------------------------------------------------
	// Summary:
	//     Copies alpha bitmap.
	// Parameters:
	//     hBitmap - Bitmap handler to be copied.
	// Returns:
	//     new alpha bitmap handler.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL CopyAlphaBitmap(HBITMAP hBitmap, LPBYTE* lpBits = NULL);

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the icon height.
	// Returns:
	//     Height of the icon.
	//-----------------------------------------------------------------------
	int GetHeight() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the icon width.
	// Returns:
	//     Width of the icon.
	//-----------------------------------------------------------------------
	int GetWidth() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Reads or writes this object from or to an archive.
	// Parameters:
	//     ar - A CArchive object to serialize to or from.
	//-----------------------------------------------------------------------
	void Serialize(CArchive& ar);

	//-----------------------------------------------------------------------
	// Summary:
	//     Reads or writes this object from or to an archive.
	// Parameters:
	//     hIcon - Icon to be serialized
	//     ar - A CArchive object to serialize to or from.
	//-----------------------------------------------------------------------
	void SerializeIcon(CXTPImageManagerIconHandle& hIcon, CArchive& ar, long nSchema);

	//-----------------------------------------------------------------------
	// Summary:
	//     Draws the image in specified location.
	// Parameters:
	//     pDC    - Destination device context.
	//     pt     - Specifies the location of the image
	//     hIcon  - A handle to an icon.
	//     szIcon - Specifies the size of the image.
	//-----------------------------------------------------------------------
	void Draw(CDC* pDC, CPoint pt);
	void Draw(CDC* pDC, CPoint pt, CSize szIcon); // <combine CXTPImageManagerIcon::Draw@CDC*@CPoint>
	void Draw(CDC* pDC, CPoint pt, CXTPImageManagerIconHandle& hIcon, CSize szIcon = 0); // <combine CXTPImageManagerIcon::Draw@CDC*@CPoint>

	//-----------------------------------------------------------------------
	// Summary:
	//     Draws the image using the brush specified by the clrBrush parameter.
	// Parameters:
	//     pDC      - Destination device context.
	//     pt       - Specifies the location of the image.
	//     hIcon    - A handle to an icon.
	//     clrBrush - color of the brush used to draw the image.
	//-----------------------------------------------------------------------
	void DrawMono(CDC* pDC, CPoint pt, CXTPImageManagerIconHandle& hIcon, CSize szIcon, COLORREF clrBrush);

	//-------------------------------------------------------------------------
	// Summary:
	//     Redraw Fade and Shadow icons.
	//-------------------------------------------------------------------------
	void Refresh();


public:

	//-----------------------------------------------------------------------
	// Summary:
	//     Use this method to scale icon.
	// Parameters:
	//     hIcon - Icon to be scaled.
	//     szExtent - Source icon size.
	//     nWidth - With of result icon.
	//-----------------------------------------------------------------------
	static HICON AFX_CDECL ScaleToFit(HICON hIcon, CSize szExtent, int nWidth);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to draw non-alpha icon in composited Vista Glass rectangle
	// Parameters:
	//     pDC - Pointer to device context
	//     pt - Pointer to draw icon
	//     szIcon - Size of the icon
	//     hIcon - Icon handle to draw
	//-----------------------------------------------------------------------
	static void AFX_CDECL DrawIconComposited(CDC* pDC, CPoint pt, CSize szIcon, HICON hIcon);

private:
	void InitBimaps(CImageList& imageList, int nIndex);
	void CreateFadedIcon();
	void CreateShadowIcon();

	void Clear(BOOL bIcon = FALSE);
	COLORREF LightenColor(COLORREF clr, double factor);

	BOOL GetDIBBitmap(HBITMAP hBitmap, PBYTE& pBits, UINT& nBitsSize, PBITMAPINFO& pBitmapInfo, UINT& nBitmapInfoSize);
	HBITMAP ReadDIBBitmap(CArchive& ar, LPBYTE* pBits1);
	void WriteDIBBitmap(CArchive& ar, HBITMAP hBitmap);

	CXTPImageManager* GetImageManager() const;

private:
	CXTPImageManagerIcon(const CXTPImageManagerIcon&): m_nID(0) {};
	const CXTPImageManagerIcon& operator=(const CXTPImageManagerIcon&) {return *this;};

public:
	BOOL m_bDrawComposited; // Draw on Vista composited rects.

private:
	const UINT m_nID;
	UINT m_nWidth;
	UINT m_nHeight;
	CXTPImageManagerIconHandle m_hIcon;
	CXTPImageManagerIconHandle m_hFaded;
	CXTPImageManagerIconHandle m_hShadow;
	CXTPImageManagerIconHandle m_hHot;
	CXTPImageManagerIconHandle m_hChecked;
	CXTPImageManagerIconHandle m_hPressed;
	CXTPImageManagerIconHandle m_hDisabled;
	CXTPImageManagerIconHandle m_hDisabledAuto;
	CXTPImageManagerIconSet* m_pIconSet;
	CXTPImageManagerImageList* m_pImageList;

private:
	friend class CXTPImageManager;
	friend class CXTPImageManagerIconSet;
	friend class CXTPImageManagerIconHandle;

};


//===========================================================================
// Summary:
//     CXTPImageManagerIconSet represents the collection of icons for specified identifier.
//===========================================================================
class _XTP_EXT_CLASS CXTPImageManagerIconSet : public CXTPCmdTarget
{
public:
	typedef CMap<UINT, UINT, CXTPImageManagerIcon*, CXTPImageManagerIcon*> CIconSetMap; // Icons collection.

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPImageManagerIconSet object.
	// Parameters:
	//     nID - Icon set identifier.
	//     pImageManager - Parent image manager CXTPImageManagerIconSet belongs.
	//-----------------------------------------------------------------------
	CXTPImageManagerIconSet(UINT nID, CXTPImageManager* pImageManager);

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPImageManagerIconSet object, handles cleanup and deallocation.
	//-----------------------------------------------------------------------
	~CXTPImageManagerIconSet();

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the icon with the specified width
	// Parameters:
	//     nWidth - Width of the icon to retrieve.
	//     bScaled - TRUE to scale icon.
	// Returns:
	//     A pointer to a CXTPImageManagerIcon object
	//-----------------------------------------------------------------------
	CXTPImageManagerIcon* GetIcon(UINT nWidth, BOOL bScaled = TRUE);

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the collection of icons
	// Returns:
	//     A pointer to a CIconSetMap object
	//-----------------------------------------------------------------------
	CIconSetMap* GetIcons();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the identifier of the collection set.
	// Returns:
	//     Identifier of icons.
	//-----------------------------------------------------------------------
	UINT GetID() const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Removes all icons
	//-------------------------------------------------------------------------
	void RemoveAll();

	//-------------------------------------------------------------------------
	// Summary:
	//     Redraws all icons.
	//-------------------------------------------------------------------------
	void RefreshAll();

private:
	CXTPImageManagerIcon* CreateIcon(UINT nWidth);
	void SetIcon(CXTPImageManagerIconHandle hIcon, UINT nWidth);
	void SetDisabledIcon(CXTPImageManagerIconHandle hIcon, UINT nWidth);
	void SetHotIcon(CXTPImageManagerIconHandle hIcon, UINT nWidth);
	void SetCheckedIcon(CXTPImageManagerIconHandle hIcon, UINT nWidth);
	void SetPressedIcon(CXTPImageManagerIconHandle hIcon, UINT nWidth);

private:
	CXTPImageManagerIconSet(const CXTPImageManagerIconSet&): m_nID(0) {};
	const CXTPImageManagerIconSet& operator=(const CXTPImageManagerIconSet&) {return *this;};

private:
	CIconSetMap m_mapIcons;
	const UINT m_nID;
	CXTPImageManager* m_pImageManager;

private:
	friend class CXTPImageManager;
	friend class CXTPImageManagerIcon;
};

//{{AFX_CODEJOCK_PRIVATE

class _XTP_EXT_CLASS CXTPImageManagerImageList
{
public:
	CXTPImageManagerImageList();
	~CXTPImageManagerImageList();

public:
	BOOL Lookup(UINT nCommand);
	CXTPImageManagerIcon* GetIcon(UINT nCommand);
	void Draw(CDC* pDC, CPoint pt, CXTPImageManagerIcon* pIcon, CSize szIcon);
	void RemoveAll();

	CSize GetIconSize() const;

private:
	HIMAGELIST m_hImageList;
	BOOL m_bDestroyImageList;
	UINT m_nBaseCommand;
	CXTPImageManager* m_pImageManager;
	CMap<UINT, UINT, CXTPImageManagerIcon*, CXTPImageManagerIcon*> m_mapIcons;

	friend class CXTPImageManager;
};

//}}AFX_CODEJOCK_PRIVATE

//===========================================================================
// Summary:
//     CXTPImageManager is a stand alone class. It is used to manipulate icons.
//===========================================================================
class _XTP_EXT_CLASS CXTPImageManager : public CXTPCmdTarget
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPImageManager object.
	//-----------------------------------------------------------------------
	CXTPImageManager();

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPImageManager object, handles cleanup and deallocation.
	//-----------------------------------------------------------------------
	~CXTPImageManager();
public:

	//-----------------------------------------------------------------------
	// Summary:
	//     Adds the icons.
	// Parameters:
	//     nIDResourceBitmap  - Bitmap resource identifier
	//     lpszResourceBitmap - Bitmap resource identifier
	//     nIDResourceToolBar - Toolbar resource identifier
	//     bmpIcons           - Bitmap containing icons to be added.
	//     imlIcons           - Image list containing the icons to be added.
	//     pCommands          - Pointer to an array of IDs.
	//     nCount             - Number of elements in the array pointed to by lpIDArray.
	//     szIcon             - Size of the icons.
	//     imageState         - Images state.
	//     bAlpha             - TRUE if bitmap has alpha channel.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	// Example:
	// <code>
	//
	// static UINT buttons[] =
	// {
	//     ID_BACK,
	//     ID_FORWARD,
	//     ID_STOP,
	//     ID_REFRESH,
	//     ID_HOME
	// }
	//
	// XTPImageManager()->SetMaskColor(RGB(0, 0xFF, 0));
	//
	// XTPImageManager()->SetIcons(IDR_TOOLBAR_NORMAL_SMALL, buttons, _countof(buttons), CSize(16, 16), xtpImageNormal);
	// XTPImageManager()->SetIcons(IDR_TOOLBAR_HOT_SMALL, buttons, _countof(buttons), CSize(16, 16), xtpImageHot);
	//
	// XTPImageManager()->SetIcons(IDR_TOOLBAR_NORMAL_LARGE, buttons, _countof(buttons), CSize(24, 24), xtpImageNormal);
	// XTPImageManager()->SetIcons(IDR_TOOLBAR_HOT_LARGE, buttons, _countof(buttons), CSize(24, 24), xtpImageHot);
	// </code>
	// See Also: XTPImageState, SetIcon
	//-----------------------------------------------------------------------
	BOOL SetIcons(UINT nIDResourceToolBar, XTPImageState imageState = xtpImageNormal);
	BOOL SetIcons(UINT nIDResourceToolBar, UINT nIDResourceBitmap, XTPImageState imageState = xtpImageNormal); // <COMBINE CXTPImageManager::SetIcons@UINT@XTPImageState>
	BOOL SetIcons(CBitmap& bmpIcons, UINT* pCommands, int nCount, CSize szIcon, XTPImageState imageState = xtpImageNormal, BOOL bAlpha = FALSE); // <COMBINE CXTPImageManager::SetIcons@UINT@XTPImageState>
	BOOL SetIcons(UINT nIDResourceToolBar, CBitmap& bmpIcons, XTPImageState imageState = xtpImageNormal); // <COMBINE CXTPImageManager::SetIcons@UINT@XTPImageState>
	BOOL SetIcons(UINT nIDResourceBitmap, UINT* pCommands, int nCount, CSize szIcon, XTPImageState imageState = xtpImageNormal); // <COMBINE CXTPImageManager::SetIcons@UINT@XTPImageState>
	BOOL SetIcons(LPCTSTR lpszResourceBitmap, UINT* pCommands, int nCount, CSize szIcon, XTPImageState imageState = xtpImageNormal); // <COMBINE CXTPImageManager::SetIcons@UINT@XTPImageState>
	BOOL SetIcons(CImageList& imlIcons, UINT* pCommands, int nCount, CSize szIcon, XTPImageState imageState = xtpImageNormal); // <COMBINE CXTPImageManager::SetIcons@UINT@XTPImageState>
	BOOL SetIcons(UINT nIDResourceToolBar, CImageList& imlIcons, XTPImageState imageState = xtpImageNormal); // <COMBINE CXTPImageManager::SetIcons@UINT@XTPImageState>

	//-----------------------------------------------------------------------
	// Summary:
	//     This method loads icon from ico file
	// Parameters:
	//     lpszFileName - Path to ico file
	//     nIDCommand   - Icon command
	//     szIcon       - Size of the icons.
	//     imageState   - Images state.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	//-----------------------------------------------------------------------
	BOOL SetIconFromIcoFile(LPCTSTR lpszFileName, UINT nIDCommand, CSize szIcon, XTPImageState imageState);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this to attach images from a HIMAGELIST control to the image manager
	// Parameters:
	//     hImageList - Pointer to an imagelist that holds icons
	//     nBaseCommand - ID to start numbering icons from the imagelist
	//     bDestoryImageList - Destroy imagelist control after the icons are copied to the imagemanager
	//-----------------------------------------------------------------------
	BOOL SetImageList(HIMAGELIST hImageList, int nBaseCommand, BOOL bDestoryImageList = FALSE);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this to create system HIMAGELIST from bitmap and add it to image manager
	// Parameters:
	//     nIDResourceBitmap - Bitmap resource identifier
	//     cx - Width of the icons
	//     nBaseCommand - ID to start numbering icons from the imagelist
	//     clrMask - Mask color for bitmap
	// Remarks:
	//     SetIcons method loads bitmaps and creates HICON for each icon in bitmap, SetImageList creates only
	//     one HIMAGELIST. use SetImageList to create only one GDI object for all icons.
	// See Also: SetIcons
	//-----------------------------------------------------------------------
	BOOL SetImageList(UINT nIDResourceBitmap, int cx, int nBaseCommand = 0, COLORREF clrMask = (COLORREF)-1);

	//-----------------------------------------------------------------------
	// Summary:
	//     Adds the icons from another image manager.
	// Parameters:
	//     pImageManager - A pointer to another image manager. The icons in pImageManager will be added to this image manager.
	//-----------------------------------------------------------------------
	void AddIcons(CXTPImageManager* pImageManager);

	//-----------------------------------------------------------------------
	// Summary:
	//     Adds the icon.
	// Parameters:
	//     hIcon           - Icon handle to add
	//     nIDResourceIcon - Icon resource identifier
	//     nIDCommand      - Icon identifier.
	//     szIcon          - Size of the icons.
	//     imageState      - Images state.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	// See Also: XTPImageState, SetIcons
	//-----------------------------------------------------------------------
	BOOL SetIcon(CXTPImageManagerIconHandle hIcon, UINT nIDCommand, CSize szIcon = 0, XTPImageState imageState = xtpImageNormal);
	BOOL SetIcon(UINT nIDResourceIcon, UINT nIDCommand, CSize szIcon = 0, XTPImageState imageState = xtpImageNormal); // <combine CXTPImageManager::SetIcon@CXTPImageManagerIconHandle@UINT@CSize@XTPImageState>

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to set the color mask of the bitmaps that will be added.
	// Parameters:
	//     clrMask - Mask color to be set.
	// Returns:
	//     Previous color mask.
	//-----------------------------------------------------------------------
	COLORREF SetMaskColor(COLORREF clrMask);

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves color mask.
	// Returns:
	//     Current color mask.
	//-----------------------------------------------------------------------
	COLORREF GetMaskColor() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Mirrors images around the y-axis, useful in RTL (Right-To-Left) Languages.
	// Parameters:
	//     bDrawReverted - If TRUE, images are "flipped" or Mirrored.
	//                     This should be used when displaying images in an
	//                     application that uses RTL (Right-To-Left) Languages.
	//-----------------------------------------------------------------------
	void DrawReverted(BOOL bDrawReverted);

	//-----------------------------------------------------------------------
	// Summary:
	//     Removes all icons.
	//-----------------------------------------------------------------------
	void RemoveAll();

	//-----------------------------------------------------------------------
	// Summary:
	//     Removes the specified icon.
	// Parameters:
	//     nIDCommand - Id of icon to be removed
	//-----------------------------------------------------------------------
	void RemoveIcon(UINT nIDCommand);

	//-----------------------------------------------------------------------
	// Summary:
	//     Redraws all icons.
	//-----------------------------------------------------------------------
	void RefreshAll();

	//-----------------------------------------------------------------------
	// Summary:
	//     This method used by CommandBars to add custom icons
	// Parameters:
	//     hIcon - Icon Handler to be added
	// Returns:
	//     Identifier of new added icon.
	//-----------------------------------------------------------------------
	UINT AddCustomIcon(CXTPImageManagerIconHandle hIcon);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the icons with the specified Id and width.
	// Parameters:
	//     nCommand - ID of the icon to be retrieved
	//     nWidth - Width of the icon to be retrieved
	// Returns:
	//     A pointer to a CXTPImageManagerIcon
	//-----------------------------------------------------------------------
	CXTPImageManagerIcon* GetImage(UINT nCommand, int nWidth = 16) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to determine if non scaled image exists in image manager
	// Parameters:
	//     nCommand - Image identifier to check
	//     nWidth - Image width to check
	// Returns:
	//     TRUE if image non scaled image exists.
	// See Also: GetImage
	//-----------------------------------------------------------------------
	BOOL IsPrimaryImageExists(UINT nCommand, int nWidth) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the icons set with the specified Id.
	// Parameters:
	//     nCommand - ID of the icon set to be retrieved
	// Returns:
	//     A pointer to a CXTPImageManagerIconSet object
	//-----------------------------------------------------------------------
	CXTPImageManagerIconSet* GetIconSet(UINT nCommand) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the icons set with the specified Id from an image list.
	// Parameters:
	//     nCommand - ID of the icon set to be retrieved
	// Returns:
	//     A pointer to a CXTPImageManagerImageList object
	//-----------------------------------------------------------------------
	CXTPImageManagerImageList* GetImageList(UINT nCommand) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves a collection of images.
	// Returns:
	//     A CMap object
	//-----------------------------------------------------------------------
	CMap<UINT, UINT, CXTPImageManagerIconSet*, CXTPImageManagerIconSet*>* GetImages();

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if icons set exists with the specified ID.
	// Parameters:
	//     nCommand - Identifier needed to check.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	//-----------------------------------------------------------------------
	BOOL Lookup(UINT nCommand) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if the icons are drawn mirrored\reverted.
	// Returns:
	//     TRUE if icons are drawn reverted; FALSE if drawn normal.
	//-----------------------------------------------------------------------
	BOOL IsDrawReverted() const;
	BOOL IsDrawReverted(CDC* pDC) const;

	CXTPImageManagerResource* GetResource(CSize szIcon);
public:

	//-----------------------------------------------------------------------
	// Summary:
	//     Reads or writes icons from or to an archive.
	// Parameters:
	//     nCommand - Specified command to serialize.
	//     ar - A CArchive object to serialize to or from.
	//     pPX - A CXTPPropExchange object to serialize to or from.
	//-----------------------------------------------------------------------
	void Serialize(CArchive& ar);
	void Serialize(UINT nCommand, CArchive& ar); //<COMBINE CXTPImageManager::Serialize@CArchive&>

	//-----------------------------------------------------------------------
	// Summary:
	//     Reads or writes icons from or to an archive.
	// Parameters:
	//     nCommand - Specified command to serialize.
	//     ar - A CArchive object to serialize to or from.
	//     pPX - A CXTPPropExchange object to serialize to or from.
	//-----------------------------------------------------------------------
	void DoPropExchange(CXTPPropExchange* pPX);
	void DoPropExchange(UINT nCommand, CXTPPropExchange* pPX); //<COMBINE CXTPImageManager::DoPropExchange@CXTPPropExchange*>

public:

	//-----------------------------------------------------------------------
	// Summary:
	//     Checks if bitmap with specified resource has alpha channel.
	// Parameters:
	//     nIDResourceBitmap - Resource identifier of the bitmap to check.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE.
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsAlphaBitmapResource(UINT nIDResourceBitmap);
	static BOOL AFX_CDECL IsPngBitmapResource(UINT nIDResourceBitmap);

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines if the OS supports alpha icons.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE.
	// See Also: IsAlphaIconsImageListSupported
	//-----------------------------------------------------------------------
	BOOL IsAlphaIconsSupported() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines if the OS supports alpha image list.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	// See Also: IsAlphaIconsSupported
	//-----------------------------------------------------------------------
	static BOOL AFX_CDECL IsAlphaIconsImageListSupported();

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves color of top-left pixel.
	// Parameters:
	//     bmp       - CBitmap reference.
	//     nIDBitmap - Bitmap identifier.
	//     pt        - location of pixel to retrieve.
	// Returns:
	//     COLORREF that will be used as transparent color.
	//-----------------------------------------------------------------------
	static COLORREF AFX_CDECL GetBitmapMaskColor(CBitmap& bmp, CPoint pt = 0);
	static COLORREF AFX_CDECL GetBitmapMaskColor(UINT nIDBitmap, CPoint pt = 0); // <COMBINE CXTPImageManager::GetBitmapMaskColor@CBitmap&@CPoint>

	//-----------------------------------------------------------------------
	// Summary:
	//     This method creates 24bit bitmap from 32bit alpha bitmaps to draw it in old OSes
	// Parameters:
	//     bmpAlpha - Resource bitmap identifier.
	//     clrMask  - Mask color to be used
	//     nIDBitmap - Resource bitmap identifier.
	// Returns:
	//     Reduced bitmap handler.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL ResampleAlphaLayer(HBITMAP bmpAlpha, COLORREF clrMask);
	static HBITMAP AFX_CDECL ResampleAlphaLayer(UINT nIDBitmap, COLORREF clrMask); // <COMBINE CXTPImageManager::ResampleAlphaLayer@HBITMAP@COLORREF>

	//-----------------------------------------------------------------------
	// Summary:
	//     The TransparentBlt function performs a bit-block transfer of the color data corresponding to
	//     a rectangle of pixels from the specified source device context into a destination device context.
	// Parameters:
	//     hdcDest - handle to destination DC
	//     rcDest - destination rectangle
	//     hdcSrc - handle to source DC
	//     rcSrc - source rectangle
	//     crTransparent - color to make transparent
	// Returns:
	//     If the function succeeds, the return value is TRUE.
	// See Also: AlphaBlend
	//-----------------------------------------------------------------------
	BOOL TransparentBlt(HDC hdcDest, const CRect& rcDest,HDC hdcSrc, const CRect& rcSrc, UINT crTransparent) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     The AlphaBlend function displays bitmaps that have transparent or semitransparent pixels.
	// Parameters:
	//     hdcDest - handle to destination DC
	//     rcDest - destination rectangle
	//     hdcSrc - handle to source DC
	//     rcSrc - source rectangle
	// Returns:
	//     If the function succeeds, the return value is TRUE.
	// See Also: TransparentBlt
	//-----------------------------------------------------------------------
	BOOL AlphaBlend(HDC hdcDest, const CRect& rcDest,HDC hdcSrc, const CRect& rcSrc) const;

	//{{AFX_CODEJOCK_PRIVATE
	BOOL AlphaBlend2(HDC hdcDest, const CRect& rcDest,HDC hdcSrc, const CRect& rcSrc, BYTE Transparency) const;
	//}}AFX_CODEJOCK_PRIVATE

	//-----------------------------------------------------------------------
	// Summary:
	//     This function make a rectangle on device context as disabled.
	// Parameters:
	//     hDC              - A handle to DC
	//     rcRect           - A rectangle to be disabled
	//     clrDisabledLight - The lightest color of icon to generate
	//     clrDisabledDark  - The darkest color of icon to generate
	// Returns:
	//     If the function succeeds, the return value is TRUE.
	// See Also: BlackWhiteBitmap
	//-----------------------------------------------------------------------
	BOOL DisableBitmap(HDC hDC, const CRect& rcRect, COLORREF clrDisabledLight = (COLORREF)-1, COLORREF clrDisabledDark = (COLORREF)-1);

	//-----------------------------------------------------------------------
	// Summary:
	//     This function make a rectangle on device context as gray scale.
	// Parameters:
	//     hDC                    - A handle to DC
	//     rcRect                 - A rectangle to be disabled
	//     nBlackAndWhiteContrast - Black-white contrast as integer from 0 to 255
	// Returns:
	//     If the function succeeds, the return value is TRUE.
	// See Also: DisableBitmap
	//-----------------------------------------------------------------------
	BOOL BlackWhiteBitmap(HDC hDC, const CRect& rcRect, int nBlackAndWhiteContrast = 0);

	//-----------------------------------------------------------------------
	// Summary:
	//     This function used to get a bitmap pixel color (including alpha layer).
	// Parameters:
	//     hBmp      - [in] A handle to bitmap
	//     pt        - [in] Coordinates of bitmap pixel.
	//     rclrPixel - [out] A reference to receive pixel color.
	// Returns:
	//     If the function succeeds, the return value is TRUE.
	//-----------------------------------------------------------------------
	BOOL GetBitmapPixel(HBITMAP hBmp, const CPoint& pt, COLORREF& rclrPixel);

	//-----------------------------------------------------------------------
	// Summary:
	//     This helper method creates 32bit bitmap
	// Parameters:
	//     hDC - Pointer to valid context (can be NULL)
	//     iWidth - Width of bitmap
	//     iHeight - Height of bitmap
	//     lpBits - Pointer to bits to return
	// Returns:
	//     Bitmap handle was created.
	//-----------------------------------------------------------------------
	static HBITMAP AFX_CDECL Create32BPPDIBSection(HDC hDC, int iWidth, int iHeight, LPBYTE* lpBits = NULL);
private:
	BOOL LoadToolbar(UINT nIDResourceToolBar, UINT*& pItems, int& nCount, CSize& szIcon) const;

	UINT PasteCustomImage(COleDataObject& data);
	void CopyImage(UINT nCommand);
	BOOL SplitBitmap(HBITMAP hbmSource, int nCount, HBITMAP* pDest) const;
	BOOL IsWindow2000() const;
	BOOL BitmapsCompatible(LPBITMAP lpbm1, LPBITMAP lpbm2) const;
	BOOL McTransparentBlt(HDC hdcDest, int nXOriginDest, int nYOriginDest,
		int nWidthDest, int nHeightDest, HDC hdcSrc,
		int nXOriginSrc, int nYOriginSrc, int nWidthSrc,
		int nHeightSrc, UINT crTransparent) const;
	BOOL BlendImages(HBITMAP hbmSrc1, BOOL bRTL1, HBITMAP hbmSrc2, BOOL bRTL2, HBITMAP hbmDst) const;
	BOOL DoAlphaBlend(HDC hdcDest, int nXOriginDest, int nYOriginDest,
		int nWidthDest, int nHeightDest, HDC hdcSrc, int nXOriginSrc,
		int nYOriginSrc, int nWidthSrc, int nHeightSrc) const;
	BOOL DoDisableBitmap(HBITMAP hBmp, COLORREF clrDisabledLight = (COLORREF)-1, COLORREF clrDisabledDark = (COLORREF)-1,
						 int nBlackAndWhiteContrast = -1);

public:
	static double m_dDisabledBrightnessFactor;  // Brightness factor of disabled icons.
	static double m_dDisabledAlphaFactor;       // Alpha factor of disabled icons.
	static BOOL   m_bAutoResample;              // TRUE to automatically re-sample alpha bitmaps if msimg32 not found.
	static CLIPFORMAT m_nImageClipFormat;       // Clipboard format of icons.
	static CLIPFORMAT m_nAlphaClipFormat;       // Clipboard format of icons.
	// 2007-08 layout (ctor 0x64c6e0): no m_bUseResources / m_mapResources;
	// +0x20 m_clrMask=-1, +0x24 m_mapImages, +0x40 m_arrImageList, +0x54 m_nCustomID=0x10aaa,
	// +0x58..+0x60 set from LoadLibrary/GetProcAddress, +0x64 m_bDrawReverted=2

private:
	COLORREF m_clrMask;
	CMap<UINT, UINT, CXTPImageManagerIconSet*, CXTPImageManagerIconSet*> m_mapImages;
	CArray<CXTPImageManagerImageList*, CXTPImageManagerImageList*> m_arrImageList;

	UINT m_nCustomID;
	DWORD m_dwPad58[3];     // +0x58..+0x63 (module handle and two proc pointers in the 2007-08 ctor)
	BOOL m_bDrawReverted;

private:
	friend _XTP_EXT_CLASS CXTPImageManager* AFX_CDECL XTPImageManager();
	friend class CXTPCustomizeSheet;
	friend class CXTPImageManagerIcon;
	friend class CXTPImageManagerIconHandle;

};

//===========================================================================
// Summary:
//    CXTPTempColorMask class can be used to temporarily set the color mask
//    used by XTPImageManager when using images with different color masks.
//    When the destructor is called the default mask is reset for
//    XTPImageManager.
// Example:
//    The following example demonstrates using CXTPTempColorMask.
// <code>
//    // temporarily change the mask color.
//    CXTPTempColorMask mask(RGB(0,255,0));
//    XTPImageManager()->SetIcons(IDB_FAVORITES,
//        icons, _countof(icons) CSize(16,16));
//
//    // set another mask color, CXTPTempColorMask will handle resetting
//    // the default color mask when it is destroyed.
//    XTPImageManager()->SetMaskColor(RGB(255,0,255));
//    XTPImageManager()->SetIcons(IDR_TOOLBAR_MASKED,
//        buttons, _countof(buttons), CSize(16,16), xtpImageNormal);
// </code>
// See Also:
//    CXTPImageManager::GetMaskColor, CXTPImageManager::SetMaskColor,
//    CXTPPaintManagerColor::GetStandardColor
//========================================================================
class _XTP_EXT_CLASS CXTPTempColorMask
{
public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPTempColorMask object and initializes the
	//     application defined mask color and saves the default mask color
	//     used by XTPImageManager.
	// Parameters:
	//     crNewMask - An RGB value that represents the new color mask value used
	//                 by XTPImageManager.
	//-----------------------------------------------------------------------
	CXTPTempColorMask(COLORREF crNewMask);

	//-----------------------------------------------------------------------
	// Summary:
	//     Destructor for CXTPTempColorMask. Resets the default mask color
	//     used by XTPImageManager back to its original color value.
	//-----------------------------------------------------------------------
	virtual ~CXTPTempColorMask();

private:
	COLORREF m_crMask;
};

//////////////////////////////////////////////////////////////////////////

AFX_INLINE CXTPImageManagerIconHandle::operator HICON() const {
	return m_hIcon;
}

AFX_INLINE UINT CXTPImageManagerIconSet::GetID() const {
	return m_nID;
}
AFX_INLINE BOOL CXTPImageManagerIcon::IsScaled() const {
	return FALSE;
}

_XTP_EXT_CLASS CXTPImageManager* AFX_CDECL XTPImageManager();


AFX_INLINE CXTPImageManagerIconSet::CIconSetMap* CXTPImageManagerIconSet::GetIcons() {
	return &m_mapIcons;
}
AFX_INLINE CMap<UINT, UINT, CXTPImageManagerIconSet*, CXTPImageManagerIconSet*>* CXTPImageManager::GetImages() {
	return  &m_mapImages;
}

AFX_INLINE void CXTPImageManager::DrawReverted(BOOL bDrawReverted) {
	m_bDrawReverted = bDrawReverted;
}
AFX_INLINE BOOL CXTPImageManager::IsDrawReverted() const {
	return m_bDrawReverted;
}

AFX_INLINE CXTPTempColorMask::CXTPTempColorMask(COLORREF crNewMask) {
	m_crMask = XTPImageManager()->SetMaskColor(crNewMask);
}
AFX_INLINE CXTPTempColorMask::~CXTPTempColorMask() {
	XTPImageManager()->SetMaskColor(m_crMask);
}

#endif //#if !defined(__XTPIMAGEMANAGER_H__)

// ---- end Source/Common/XTPImageManager.h
#include "Source/Common/XTMaskEditT.h"
#include "Source/Common/XTPPropExchange.h"
#include "Source/Common/XTPToolTipContext.h"
#include "Source/Common/XTPOffice2007Image.h"
#include "Source/Common/XTPNotifyConnection.h"
#include "Source/Common/XTPSmartPtrInternalT.h"

#endif // !defined(__XTPCOMMONINCLUDES_H__)

// ---- end Source/Common/Includes.h          // _XTP_INCLUDE_COMMON
#endif

#if !defined(_XTP_EXCLUDE_TABMANAGER)
#include "Source/TabManager/Includes.h"      // _XTP_INCLUDE_TABMANAGER
#endif

#if !defined(_XTP_EXCLUDE_GRAPHICLIBRARY)
#include "Source/GraphicLibrary/Includes.h"  // _XTP_INCLUDE_GRAPHICLIBRARY
#endif

#if !defined(_XTP_EXCLUDE_CONTROLS)
#include "Source/Controls/Includes.h"        // _XTP_INCLUDE_CONTROLS
#endif

#if !defined(_XTP_EXCLUDE_COMMANDBARS)
// ---- inlined Source/CommandBars/Includes.h
// Includes.h
//
// This file is a part of the XTREME COMMANDBARS MFC class library.
// (c)1998-2007 Codejock Software, All Rights Reserved.
//
// THIS SOURCE FILE IS THE PROPERTY OF CODEJOCK SOFTWARE AND IS NOT TO BE
// RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED WRITTEN
// CONSENT OF CODEJOCK SOFTWARE.
//
// THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS OUTLINED
// IN THE XTREME TOOLKIT PRO LICENSE AGREEMENT. CODEJOCK SOFTWARE GRANTS TO
// YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE THIS SOFTWARE ON A
// SINGLE COMPUTER.
//
// CONTACT INFORMATION:
// support@codejock.com
// http://www.codejock.com
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(__XTPCOMMANDBARINCLUDES_H__)
#define __XTPCOMMANDBARINCLUDES_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Source/CommandBars/Resource.h"

// ---- inlined Source/CommandBars/XTPCommandBar.h
// XTPCommandBar.h : interface for the CXTPCommandBar class.
//
// This file is a part of the XTREME COMMANDBARS MFC class library.
// (c)1998-2007 Codejock Software, All Rights Reserved.
//
// THIS SOURCE FILE IS THE PROPERTY OF CODEJOCK SOFTWARE AND IS NOT TO BE
// RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED WRITTEN
// CONSENT OF CODEJOCK SOFTWARE.
//
// THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS OUTLINED
// IN THE XTREME TOOLKIT PRO LICENSE AGREEMENT. CODEJOCK SOFTWARE GRANTS TO
// YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE THIS SOFTWARE ON A
// SINGLE COMPUTER.
//
// CONTACT INFORMATION:
// support@codejock.com
// http://www.codejock.com
//
/////////////////////////////////////////////////////////////////////////////

//{{AFX_CODEJOCK_PRIVATE
#if !defined(__XTPCOMMANDBAR_H__)
#define __XTPCOMMANDBAR_H__
//}}AFX_CODEJOCK_PRIVATE

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Source/Common/XTPSystemHelpers.h"
#include "Source/CommandBars/XTPCommandBarsDefines.h"
#include "Source/CommandBars/XTPHookManager.h"

class CXTPDockBar;
class CXTPControls;
class CXTPControl;
class CXTPControlPopup;
class CXTPCommandBars;
class CXTPCommandBar;
class CXTPCommandBarAnimation;
class CXTPPaintManager;
class CXTPImageManager;
class CXTPPropExchange;
struct XTP_COMMANDBARS_PROPEXCHANGE_PARAM;
class CXTPToolTipContext;
class CXTPCommandBarAnimation;
class CXTPCommandBarKeyboardTip;

//{{AFX_CODEJOCK_PRIVATE
#define XTP_TID_HOVER    112223
#define XTP_TID_EXPANDED_POPUP 112224
#define XTP_BOOL_DEFAULT 2
#define XTP_TID_SHOWKEYBOARDTIPS 0xCCCA
//}}AFX_CODEJOCK_PRIVATE

//===========================================================================
// Summary:
//     CXTPCommandBarList is a CList derived class. It is used as a collection
//     of CXTPCommandBar classes.
//===========================================================================
class _XTP_EXT_CLASS CXTPCommandBarList : public CXTPCmdTarget
{
public:

	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPCommandBarList object
	// Parameters:
	//     pCommandBars - Parent CXTPCommandBars pointer
	//-----------------------------------------------------------------------
	CXTPCommandBarList(CXTPCommandBars* pCommandBars)
	{
		m_pCommandBars = pCommandBars;
	}

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPCommandBarList object, handles cleanup and
	//     deallocation
	//-----------------------------------------------------------------------
	virtual ~CXTPCommandBarList();

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to find the CommandBar with the specified
	//     identifier.
	// Parameters:
	//     nBarID - Identifier CommandBar to find.
	// Returns:
	//     A pointer to a CXTPCommandBar object.
	//-----------------------------------------------------------------------
	CXTPCommandBar* FindCommandBar(UINT nBarID) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns Commandbars object attached to list
	// Returns:
	//     Pointer to CXTPCommandBars parent object
	// See Also:
	//     CXTPCommandBars, CXTPCommandBar
	//-----------------------------------------------------------------------
	CXTPCommandBars* GetCommandBars() const { return m_pCommandBars; }

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns CommandBar in list by its index
	// Parameters:
	//     nIndex - Index of the commandbar to return
	// Returns:
	//     CommandBar in list by its index
	// See Also: GetCount
	//-----------------------------------------------------------------------
	CXTPCommandBar* GetAt(int nIndex) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Return count of commanbars in list
	// Returns:
	//     Commanbars count
	// See Also: GetAt
	//-----------------------------------------------------------------------
	int GetCount() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to add new commandbar to the list
	// Parameters:
	//      pCommandBar - CommandBar to be added
	// Returns:
	//      Pointer to just added CommandBar
	// See Also: GetAt, GetCount
	//-----------------------------------------------------------------------
	virtual CXTPCommandBar* Add(CXTPCommandBar* pCommandBar);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to check if CommandBar exists in the list
	// Parameters:
	//      pCommandBar - CommandBar to test
	// Returns:
	//      TRUE if CommandBar exists in the list
	//-----------------------------------------------------------------------
	BOOL Lookup(CXTPCommandBar* pCommandBar) const;

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this method to clean the list
	// See Also: Remove
	//-------------------------------------------------------------------------
	void RemoveAll();

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to remove CommandBar from the list
	// Parameters:
	//     pCommandBar - CommandBar to be removed
	// See Also: RemoveAll
	//-----------------------------------------------------------------------
	void Remove(CXTPCommandBar* pCommandBar);

protected:
	CXTPCommandBars* m_pCommandBars;            // Parent CXTPCommandBars object
	CArray<CXTPCommandBar*, CXTPCommandBar*> m_arrBars;         // Array of CommandBars
};

//===========================================================================
// Summary:
//     CXTPCommandBar is a CWnd derived class. It represents the parent
//     class for command bars.
//===========================================================================
class _XTP_EXT_CLASS CXTPCommandBar : public CWnd, public CXTPHookManagerHookAble, public CXTPAccessible
{
protected:
	//-----------------------------------------------------------------------
	// Summary:
	//     Constructs a CXTPCommandBar object
	//-----------------------------------------------------------------------
	CXTPCommandBar();

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTPCommandBar object, handles cleanup and deallocation
	//-----------------------------------------------------------------------
	virtual ~CXTPCommandBar();

public:

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the tracking state.
	// Returns:
	//     TRUE if the command bar is in the tracking mode.
	//-----------------------------------------------------------------------
	int IsTrackingMode() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the controls collection.
	// Returns:
	//     A CXTPControls pointer.
	//-----------------------------------------------------------------------
	CXTPControls* GetControls() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This method called to set controls collection to commandbar
	// Parameters:
	//     pControls - New controls to be set
	// See Also: GetControls
	//-----------------------------------------------------------------------
	void SetControls(CXTPControls* pControls);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the type of the command bar.
	// Returns:
	//     The type of the command bar. It can be one of the following:
	//     * <b>xtpBarTypeMenuBar</b> Indicates the command bar is menu bar (CXTPMenuBar)
	//     * <b>xtpBarTypeNormal</b> Indicates the command bar is simple toolbar (CXTPToolBar)
	//     * <b>xtpBarTypePopup</b> Indicates the command bar is popupbar (CXTPPopupBar)
	// See Also: XTPBarType, GetPosition
	//-----------------------------------------------------------------------
	XTPBarType GetType() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the position of the command bar.
	// Returns:
	//     The position of the command bar.
	// See Also: XTPBarPosition, GetType
	//-----------------------------------------------------------------------
	XTPBarPosition GetPosition() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to recalculate the layout.
	//-----------------------------------------------------------------------
	void DelayLayout();

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to redraw the command bar.
	//-----------------------------------------------------------------------
	virtual void DelayRedraw();

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to change the tracking state.
	// Parameters:
	//     bMode        - TRUE to set the tracking mode; otherwise FALSE.
	//     bSelectFirst - TRUE to select the first item.
	//     bKeyboard    - TRUE if the item is popped by the keyboard.
	// Returns:
	//     TRUE if the method was successful.
	// See Also: IsTrackingMode.
	//-----------------------------------------------------------------------
	virtual BOOL SetTrackingMode(int bMode, BOOL bSelectFirst = TRUE, BOOL bKeyboard = FALSE);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to convert menu items to command bar controls.
	// Parameters:
	//     pMenu           - Menu to be converted.
	//     bRemoveControls - TRUE to remove all controls first.
	// Returns:
	//     TRUE if the method was successful; otherwise FALSE.
	//-----------------------------------------------------------------------
	virtual BOOL LoadMenu(CMenu* pMenu, BOOL bRemoveControls = TRUE);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to return the control at the specified index.
	// Parameters:
	//     nIndex - An integer index.
	// Returns:
	//     The CXTPControl pointer currently at this index.
	// See also: GetControls, CXTPControls::GetAt
	//-----------------------------------------------------------------------
	CXTPControl* GetControl(int nIndex) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the count of the controls
	// Returns:
	//     The count of the controls.
	//-----------------------------------------------------------------------
	int GetControlCount() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to select the specified control.
	// Parameters:
	//     nSelected - An integer index of the item to be selected.
	//     bKeyboard - TRUE if the item was selected using the keyboard.
	// Returns:
	//     TRUE if the method was successful; otherwise FALSE.
	//-----------------------------------------------------------------------
	virtual BOOL SetSelected(int nSelected, BOOL bKeyboard = FALSE);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to popup the specified control.
	// Parameters:
	//     nPopuped  - An integer index of the item to be popped.
	//     bKeyboard - TRUE if the item is popped by the keyboard.
	// Returns:
	//     TRUE if the method was successful; otherwise FALSE.
	//-----------------------------------------------------------------------
	BOOL SetPopuped(int nPopuped, BOOL bKeyboard = FALSE);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to set a title for this command bar.
	// Parameters:
	//     lpszTitle - Title to be set.
	//-----------------------------------------------------------------------
	void SetTitle(LPCTSTR lpszTitle);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get a title for this command bar.
	// Returns:
	//     The title of the command bar.
	//-----------------------------------------------------------------------
	CString GetTitle() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the command bar's object.
	// Returns:
	//     A CXTPCommandBars pointer (can be NULL).
	//-----------------------------------------------------------------------
	CXTPCommandBars* GetCommandBars() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to set the command bar's object.
	// Parameters:
	//     pCommandBars - CXTPCommandBars to be set.
	//-----------------------------------------------------------------------
	void SetCommandBars(CXTPCommandBars* pCommandBars);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the command bar's site.
	// Returns:
	//     Command bar's site (cannot be NULL).
	//-----------------------------------------------------------------------
	CWnd* GetSite() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the command bar's site as CFrameWnd.
	// Returns:
	//     The command bar's site (can be NULL).
	//-----------------------------------------------------------------------
	CFrameWnd* GetFrameSite() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to set the command bar's flags.
	// Parameters:
	//     dwFlagsAdd    - Flags to be added.
	//     dwFlagsRemove - Flags to be removed.
	// Remarks:
	//     dwFlagsAdd and dwFlagsRemove can be combination of XTPToolBarFlags and XTPMenuBarFlags<p/>
	//     Use the bitwise-OR (|) operator to combine the flags.<p/>
	//     * <b>xtpFlagAlignTop</b> -  Allows docking at the top of the client area.
	//     * <b>xtpFlagAlignBottom</b> -  Allows docking at the bottom of the client area.
	//     * <b>xtpFlagAlignLeft</b> -  Allows docking on the left side of the client area.
	//     * <b>xtpFlagAlignRight</b> -  Allows docking on the left side of the client area.
	//     * <b>xtpFlagAlignAny</b> -  Allows docking on any side of the client area.
	//     * <b>xtpFlagFloating</b> -  Allows floating.
	//     * <b>xtpFlagHideWrap</b> -  Allow to hide wrapped controls.
	//     * <b>xtpFlagStretched</b> -  Bar is stretched.
	//     * <b>xtpFlagStretchedShared</b> -  Bar is stretched, but not fill whole row
	//     * <b>xtpFlagSmartLayout</b> -  Smart layout is enabled
	//
	//     * <b>xtpFlagHideMinimizeBox</b> - To hide minimize box.
	//     * <b>xtpFlagHideMaximizeBox</b> - To hide maximize box.
	//     * <b>xtpFlagIgnoreSetMenuMessage</b> - To ignore MDI menus.
	//     * <b>xtpFlagHideClose</b> - To hide close button.
	//     * <b>xtpFlagHideMDIButtons</b> - Specifies to hide all MDI buttons displayed on the Command Bar.
	//     * <b>xtpFlagAddMDISysPopup</b> - To add system MDI popup bar.  Specifies to add system MDI popup menu to the Menu Bar.  This will appears as an icon to the far left of the Menu Bar and will display the MDI menu bar options when clicked.
	//
	// See Also: XTPMenuBarFlags, XTPToolBarFlags
	//-----------------------------------------------------------------------
	void SetFlags(DWORD dwFlagsAdd, DWORD dwFlagsRemove = 0);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to set the controls from the button array.
	// Parameters:
	//     pButtons - Pointer to an array of command Ids. It cannot be NULL.
	//     nCount   - Number of elements in the array pointed to by pButtons.
	// Returns:
	//     Nonzero if successful; otherwise 0.
	// See Also: LoadToolBar, LoadMenu.
	//-----------------------------------------------------------------------
	BOOL SetButtons(UINT* pButtons, int nCount);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member function to load the toolbar specified by nIDResource.
	// Parameters:
	//     nIDResource - Resource ID of the toolbar to be loaded.
	//     bLoadIcons  - TRUE if the toolbar icons are to be used by CXTPImageManager.
	// Returns:
	//     Nonzero if successful; otherwise 0.
	// See Also: LoadMenu, SetButtons.
	//-----------------------------------------------------------------------
	virtual BOOL LoadToolBar(UINT nIDResource, BOOL bLoadIcons = TRUE);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this function to set the size of the actual bitmapped
	//     images to be added to a toolbar.
	// Parameters:
	//     size - Width and height, in pixels, of the toolbar's icons.
	//-----------------------------------------------------------------------
	void SetIconSize(CSize size);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member function to get the size of a toolbar icon.
	// See Also:
	//     GetLargeIconSize
	//-----------------------------------------------------------------------
	virtual CSize GetIconSize() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to get Large icon size of toolbar
	// Parameters:
	//     bAutoSize - TRUE to adjust size using current DPI mode.
	// Returns:
	//     CSize value contained size of large toolbar icons.
	// See Also: GetIconSize
	//-----------------------------------------------------------------------
	CSize GetLargeIconSize(BOOL bAutoSize) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Sets the size of the buttons in the command bar.
	// Parameters:
	//     size - Width and height, in pixels, of the buttons.
	// Remarks:
	//     The button size must always be at least as large as the bitmap
	//     size it encloses. This function must be called only before adding
	//     any bitmaps to the command bar. If the application does not explicitly
	//     set the button size, it is set to the default size.
	//-----------------------------------------------------------------------
	void SetButtonSize(CSize size);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this function to get the size of the command bar button.
	// Returns:
	//     The width and height values of the command bar button.
	//-----------------------------------------------------------------------
	virtual CSize GetButtonSize() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to show the caption below control's icon.
	// Parameters:
	//     bTextBelow - TRUE to show the caption below the icon.
	//-----------------------------------------------------------------------
	void ShowTextBelowIcons(BOOL bTextBelow = TRUE);

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns a Boolean value that indicates whether the caption is
	//     below the control's icon.
	// Returns:
	//     TRUE if successful, otherwise returns FALSE
	//-----------------------------------------------------------------------
	BOOL IsTextBelowIcons() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to popup the command bar.
	// Parameters:
	//     pControlPopup - Points to a CXTPControlPopup object.
	//     bSelectFirst  - TRUE to select the first item.
	// Returns:
	//     TRUE if successful, otherwise returns FALSE.
	//-----------------------------------------------------------------------
	virtual BOOL Popup(CXTPControlPopup* pControlPopup, BOOL bSelectFirst = FALSE);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to retrieve the current focused control.
	// Returns:
	//     Window handle of the focused control.
	//-----------------------------------------------------------------------
	HWND GetTrackFocus() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to set focus to the window.
	// Parameters:
	//     hwnd - Window handle of the focused control
	//-----------------------------------------------------------------------
	void SetTrackFocus(HWND hwnd);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to set the visibility state of the control.
	// Parameters:
	//     bVisible - TRUE to set control visible.
	//-----------------------------------------------------------------------
	virtual void SetVisible(BOOL bVisible);

	//-----------------------------------------------------------------------
	// Summary:
	//     Returns a Boolean value that indicates whether the command bar
	//     is visible or hidden
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	//-----------------------------------------------------------------------
	virtual BOOL IsVisible() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member function to set the position of the command bar
	// Parameters:
	//     barPosition - Position of the command bar
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	//-----------------------------------------------------------------------
	virtual BOOL SetPosition(XTPBarPosition barPosition);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to get the index of control with specified
	//     accelerator character.
	// Parameters:
	//     chAccel - Character to find.
	// Returns:
	//     Index of the control contained  character as accelerator.
	//-----------------------------------------------------------------------
	int FindAccel(TCHAR chAccel) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to get the index of the control with specified
	//     accelerator character.
	// Parameters:
	//     chAccel     - Character to find
	//     bSelectOnly - TRUE to select only.
	// Returns:
	//     Index of the control contained character as accelerator.
	//-----------------------------------------------------------------------
	int FindAccelEx(UINT chAccel, BOOL& bSelectOnly) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to retrieve the customize mode of the command
	//     bars.
	// Returns:
	//     TRUE if command bars are in customized mode; otherwise returns
	//     FALSE
	//-----------------------------------------------------------------------
	BOOL IsCustomizeMode() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This member is called when a control is entered into the
	//     command bar.
	// Parameters:
	//     pDataObject - Points to a CXTPControl object
	//     point       - Point to test.
	// Returns:
	//     DROPEFFECT enumerator.
	//-----------------------------------------------------------------------
	virtual DROPEFFECT OnCustomizeDragEnter(CXTPControl* pDataObject, CPoint point);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called when a control leaves the command bar.
	//-----------------------------------------------------------------------
	virtual void OnCustomizeDragLeave();

	//-----------------------------------------------------------------------
	// Summary:
	//     This member is called when control is over the command bar.
	// Parameters:
	//     pDataObject - Points to a CXTPControl object
	//     point       - Point to test
	// Returns:
	//     DROPEFFECT enumerator.
	//-----------------------------------------------------------------------
	virtual DROPEFFECT OnCustomizeDragOver(CXTPControl* pDataObject, CPoint point);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called when control is dropped to the command bar.
	// Parameters:
	//     pDataObject - Points to a CXTPControl object
	//     dropEffect  - DROPEFFECT enumerator.
	//     ptDrop      - Point where user drops the control.
	//     ptDrag      - Point where user starts drag the control.
	//-----------------------------------------------------------------------
	virtual void OnCustomizeDrop(CXTPControl* pDataObject, DROPEFFECT& dropEffect, CPoint ptDrop, CPoint ptDrag);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to retrieve the customizable property of the
	//     command bar.
	// Returns:
	//     TRUE if the command bar is customizable; otherwise returns FALSE
	//-----------------------------------------------------------------------
	virtual BOOL IsCustomizable() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to enable/disable customization of the command bar.
	// Parameters:
	//     bEnable - TRUE to enable customization.
	//-----------------------------------------------------------------------
	void EnableCustomization(BOOL bEnable = TRUE);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to recalculate command bar layout.
	//-----------------------------------------------------------------------
	virtual void OnRecalcLayout();

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to remove the tracking state of the command bar.
	//-----------------------------------------------------------------------
	virtual void OnTrackLost();

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to track the command bar.
	//-----------------------------------------------------------------------
	virtual void OnTrackEnter();

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to retrieve the owner window of the command bar.
	// Returns:
	//     A pointer to a CWnd object
	//-----------------------------------------------------------------------
	CWnd* GetOwnerSite() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to redraw all parent command bars.
	//-----------------------------------------------------------------------
	void InvalidateParents();

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to retrieve the current behavior modification
	//     flags of the command bar.
	// Returns:
	//     Flags of the command bar that are currently in effect.
	//-----------------------------------------------------------------------
	DWORD GetFlags() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to retrieve the identifier of the command bar.
	// Returns:
	//     Identifier of the command bar.
	//-----------------------------------------------------------------------
	UINT GetBarID() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to set the identifier.
	// Parameters:
	//     nID - Identifier to set.
	//-----------------------------------------------------------------------
	void SetBarID(UINT nID);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called when a child control becomes selected.
	// Parameters:
	//     bSelected - TRUE when control becomes selected.
	//     pControl  - Points to a CXTPControl object
	//-----------------------------------------------------------------------
	virtual void OnControlSelected(BOOL bSelected, CXTPControl* pControl);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to set the description context.
	// Parameters:
	//     strDescription - Description string.
	// Returns:
	//     TRUE if successful; otherwise returns FALSE
	//-----------------------------------------------------------------------
	BOOL SetStatusText(const CString& strDescription);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method sets the 32-bit value associated with the command bar.
	// Parameters:
	//     dwData - Contains the new value to associate with the command bar.
	// See Also: GetCommandBarData
	//-----------------------------------------------------------------------
	void SetCommandBarData(DWORD_PTR dwData);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method retrieves the application-supplied 32-bit value
	//     associated with the command bar.
	// Returns:
	//     The 32-bit value associated with the command bar.
	// See Also: SetCommandBarData
	//-----------------------------------------------------------------------
	DWORD_PTR GetCommandBarData() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This method retrieves the parent command bar.
	// Returns:
	//     A pointer to a CXTPCommandBar object
	//-----------------------------------------------------------------------
	virtual CXTPCommandBar* GetParentCommandBar() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to retrieve the top-level parent command bar.
	// Returns:
	//     A pointer to the top-level CXTPCommandBar object
	//-----------------------------------------------------------------------
	CXTPCommandBar* GetRootParent() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to retrieve the paint manager.
	// Returns:
	//     A pointer to a CXTPPaintManager object
	//-----------------------------------------------------------------------
	CXTPPaintManager* GetPaintManager() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to retrieve the image manager
	// Returns:
	//     A pointer to a CXTPImageManager object
	//-----------------------------------------------------------------------
	CXTPImageManager* GetImageManager() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to set the width of the floated or popup toolbar.
	// Parameters:
	//     nWidth - Width of the floated or popuped toolbar.
	//-----------------------------------------------------------------------
	void SetWidth(int nWidth);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to get the width of the floated or popup toolbar.
	// Returns:
	//     The width, in pixels, of the floated or popup toolbar.
	//-----------------------------------------------------------------------
	int GetWidth() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to set the specified paint manager
	// Parameters:
	//     pPaintManager - Points to a CXTPPaintManager object  to be set
	//-----------------------------------------------------------------------
	void SetPaintManager(CXTPPaintManager* pPaintManager);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member to set the specified image manager
	// Parameters:
	//     pImageManager - Points to a CXTPImageManager object to be set
	//-----------------------------------------------------------------------
	void SetImageManager(CXTPImageManager* pImageManager);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member function to determine if the CommandBar layout
	//     is Right-to-Left (RTL).
	// Returns:
	//     Returns TRUE if the Commandbar layout is RTL, otherwise FALSE.
	//-----------------------------------------------------------------------
	BOOL IsLayoutRTL() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member function to determine if the CommandBar is a
	//     CXTPDialogBar.
	// Returns:
	//     Returns TRUE if the CommandBar is a CXTPDialogBar, otherwise FALSE
	// See Also: CXTPToolBar, CXTPDialogBar
	//-----------------------------------------------------------------------
	virtual BOOL IsDialogBar() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member function to determine if the CommandBar is a
	//     CXTPRibbonBar.
	// Returns:
	//     Returns TRUE if the CommandBar is a CXTPRibbonBar, otherwise FALSE
	// See Also: CXTPCommandBar, CXTPRibbonBar
	//-----------------------------------------------------------------------
	virtual BOOL IsRibbonBar() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member function to determine if the CommandBar is a
	//     CXTPPopupBar.
	// Returns:
	//     Returns TRUE if the CommandBar is a CXTPPopupBar, otherwise FALSE
	// See Also: CXTPCommandBar, CXTPPopupBar
	//-----------------------------------------------------------------------
	virtual BOOL IsPopupBar() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Reads or writes this object from or to an archive.
	// Parameters:
	//     pPX - A CXTPPropExchange object to serialize to or from.
	//----------------------------------------------------------------------
	virtual void DoPropExchange(CXTPPropExchange* pPX);

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines if underlines is visible in command bar control.
	// Return:
	//     Returns TRUE if underlines is visible; otherwise FALSE;
	//-----------------------------------------------------------------------
	virtual BOOL IsKeyboardCuesVisible() const;


	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called internally to prevent command bar to grab edit focus.
	// Parameters:
	//     bGrabFocus - FALSE to prevent grab focus.
	//-----------------------------------------------------------------------
	void SetGrabFocus(BOOL bGrabFocus);

	//-------------------------------------------------------------------------
	// Summary:
	//     The framework calls this member function to redraw the CommandBars.
	// Parameters:
	//     lpRect - The rectangular area of the bar that is invalid.
	//     bAnimate - TRUE to animate changes in bounding rectangle.
	//-------------------------------------------------------------------------
	virtual void Redraw(LPCRECT lpRect = 0, BOOL bAnimate = TRUE);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw the command bar in the given context.
	// Parameters:
	//     pDC - Pointer to a valid device context
	//     rcClipBox - The rectangular area of the control that is invalid
	//-----------------------------------------------------------------------
	virtual void DrawCommandBar(CDC* pDC, CRect rcClipBox);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to enable animation for CommandBar
	// Parameters:
	//     bEnable - TRUE to enable animation; FALSE to disable
	//-----------------------------------------------------------------------
	void EnableAnimation(BOOL bEnable = TRUE);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to enable double buffer for toolbar drawing
	// Parameters:
	//     bEnable - True to enable double buffer for drawing.
	// See Also: EnableAnimation
	//-----------------------------------------------------------------------
	void EnableDoubleBuffer(BOOL bEnable = TRUE);

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines if animation is enabled for specified command bar
	// Returns:
	//     TRUE if animation is enabled
	// See Also: EnableAnimation
	//-----------------------------------------------------------------------
	BOOL IsAnimationEnabled() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function is called by WindowProc, or is called during
	//     message reflection.
	// Parameters:
	//     hWnd     - Window handle message belongs to.
	//     nMessage - Specifies the message to be sent.
	//     wParam   - Specifies additional message-dependent information.
	//     lParam   - Specifies additional message-dependent information.
	//     lResult  - The return value of WindowProc. Depends on the message;
	//                may be NULL.
	//-----------------------------------------------------------------------
	virtual int OnHookMessage(HWND hWnd, UINT nMessage, WPARAM& wParam, LPARAM& lParam, LRESULT& lResult);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to be sure control is visible on toolbar
	// Parameters:
	//     pControl - CXTPControl child that need to check
	//-----------------------------------------------------------------------
	virtual void EnsureVisible(CXTPControl* pControl);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to retrieve default style of buttons of the commanbar
	// Returns:
	//     XTPButtonStyle represents default style of buttons
	// See Also: SetDefaultButtonStyle
	//-----------------------------------------------------------------------
	XTPButtonStyle GetDefaultButtonStyle() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to set default style for commanbar buttons.
	// Parameters:
	//     buttonStyle - Button style to set
	// See Also: GetDefaultButtonStyle
	//-----------------------------------------------------------------------
	void SetDefaultButtonStyle(XTPButtonStyle buttonStyle);

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this method to freeze redrawing until UnlockRedraw call
	// See Also: UnlockRedraw
	//-------------------------------------------------------------------------
	void LockRedraw();

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this method to unfreeze redrawing.
	// See Also: LockRedraw
	//-------------------------------------------------------------------------
	void UnlockRedraw();

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to show gripper for the commandbar
	// Parameters:
	//     bShow - TRUE to show; FALSE to hide
	// See Also: GetShowGripper
	//-----------------------------------------------------------------------
	void SetShowGripper(BOOL bShow);

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines if gripper is visible for the commandbar
	// Returns:
	//     TRUE if gripper is visible
	// See Also: SetShowGripper
	//-----------------------------------------------------------------------
	BOOL GetShowGripper() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to get borders margins of commandbar
	// Returns:
	//     Rectangle contains border margins
	//-----------------------------------------------------------------------
	virtual CRect GetBorders();

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to draw background of command bar
	// Parameters:
	//     pDC - POinter to device context to draw
	// See Also: DrawCommandBar
	//-----------------------------------------------------------------------
	virtual void FillCommandBarEntry(CDC* pDC);

	virtual BOOL IsResizable() const;

public:
	//-----------------------------------------------------------------------
	// Summary:
	//     Call this method to check if keyboard tips are visible for the commandbar
	// Returns:
	//     TRUE if keyboard tips are visible
	// See Also: CreateKeyboardTips
	//-----------------------------------------------------------------------
	BOOL IsKeyboardTipsVisible() const;

	//-------------------------------------------------------------------------
	// Summary:
	//     This method is called to create keyboard tips collection for commandbar
	// See Also: IsKeyboardTipsVisible
	//-------------------------------------------------------------------------
	virtual void CreateKeyboardTips();

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called when user press key while keyboard tips are visible
	// Parameters:
	//     chAccel - Virtual key
	// See Also: OnKeyboardTip
	//-----------------------------------------------------------------------
	void OnKeyboardTipChar(UINT chAccel);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called when keyboard tip was found for the commandbar
	// Parameters:
	//     pTip - Keyboard tip was found for commandbar
	// See Also: OnKeyboardTipChar
	//-----------------------------------------------------------------------
	virtual void OnKeyboardTip(CXTPCommandBarKeyboardTip* pTip);

	//-------------------------------------------------------------------------
	// Summary:
	//     Call this method to hide
	// See Also: IsKeyboardTipsVisible
	//-------------------------------------------------------------------------
	void HideKeyboardTips();

protected:
	//-----------------------------------------------------------------------
	// Summary:
	//     The framework calls this member function when a non-system key
	//     is pressed.
	// Parameters:
	//     nChar - Specifies the virtual key code of the given key.
	//     lParam   - Specifies additional message-dependent information.
	// Returns:
	//     TRUE if key handled, otherwise returns FALSE
	//-----------------------------------------------------------------------
	virtual BOOL OnHookKeyDown(UINT nChar, LPARAM lParam);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to get the size of the command bar.
	// Parameters:
	//      nLength - The requested dimension of the control bar, either horizontal or vertical, depending on dwMode.
	//      dwMode - see CControlBar::CalcDynamicLayout for list of supported flags.
	// Returns:
	//     Size of the command bar.
	//-----------------------------------------------------------------------
	virtual CSize CalcDynamicLayout(int nLength, DWORD dwMode);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to process special keys.
	// Parameters:
	//     key - Special keys enumerator. Can be any of the values listed in the Remarks section.
	// Remarks:
	//     CXTPCommandBar maps key passed as parameter of OnKeyDown to XTPSpecialKey enumerator and call ProcessSpecialKey.<p/>
	//     key parameter can be one of the following:
	//         * <b>xtpKeyNext</b> Indicates the RIGHT or DOWN key was pressed  Next control must be selected
	//         * <b>xtpKeyPrev</b> Indicates the LEFT or UP key was pressed. Previous control must be selected.
	//         * <b>xtpKeyBack</b> Indicates the LEFT key was pressed for popup bar. Current submenu must be closed
	//         * <b>xtpKeyPopup</b> Indicates the RIGHT key was pressed for popup bar. Submenu must be opened.
	//         * <b>xtpKeyEscape</b> Indicates the ESCAPE key was pressed.
	//         * <b>xtpKeyReturn</b> Indicates the RETURN key was pressed
	//         * <b>xtpKeyHome</b> Indicates the HOME key was pressed. First control must be selected.
	//         * <b>xtpKeyEnd</b> Indicates the END key was pressed. Last control must be selected.
	// Returns:
	//     TRUE if key handled, otherwise returns FALSE
	//-----------------------------------------------------------------------
	virtual BOOL ProcessSpecialKey(XTPSpecialKey key);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called when the controls array is changed.
	//-----------------------------------------------------------------------
	virtual void OnControlsChanged();

	//-----------------------------------------------------------------------
	// Summary:
	//     This method makes a copy of the command bar.
	// Parameters:
	//     pCommandBar - Command bar needed to be copied.
	//     bRecursive - TRUE to copy recursively.
	//-----------------------------------------------------------------------
	virtual void Copy(CXTPCommandBar* pCommandBar, BOOL bRecursive = FALSE);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to determine mouse hit code
	// Parameters:
	//     pt - Position to test
	// Returns:
	//     HTCLIENT if pointer belongs client area; HTNOWHERE otherwise.
	//-----------------------------------------------------------------------
	virtual int OnMouseHitTest(CPoint pt);

	//-----------------------------------------------------------------------
	// Summary:
	//     Updates the control's shortcuts.
	//-----------------------------------------------------------------------
	virtual void UpdateShortcuts();

protected:

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves active MDI document template
	// Remarks:
	//     This method call CXTPCommandBars::GetActiveDocTemplate.
	// Returns:
	//     Active document template identifier.
	// See Also: CXTPCommandBars::GetActiveDocTemplate
	//-----------------------------------------------------------------------
	UINT GetActiveDocTemplate() const;

protected:

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called to assign self identifiers for serialization process.
	// Parameters:
	//     nID             - Identifier to assign
	//     pCommandBarList - List of CommandBars.
	//     pParam          - Address of a XTP_COMMANDBARS_PROPEXCHANGE_PARAM structure.
	//-----------------------------------------------------------------------
	virtual void GenerateCommandBarList(DWORD& nID, CXTPCommandBarList* pCommandBarList, XTP_COMMANDBARS_PROPEXCHANGE_PARAM* pParam);

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called in serialization process.to restore popups from list of command bars.
	// Parameters:
	//     pCommandBarList - List of CommandBars.
	//-----------------------------------------------------------------------
	virtual void RestoreCommandBarList(CXTPCommandBarList* pCommandBarList);

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines if parent frame in help mode
	//-----------------------------------------------------------------------
	BOOL IsHelpMode() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This method is called then toolbar removed from commandbars collection
	//-----------------------------------------------------------------------
	virtual void OnRemoved();

protected:
//{{AFX_CODEJOCK_PRIVATE
	void CustomizeFindDropIndex(CXTPControl* pDataObject, const CPoint& point, CRect& rcMarker, int& nDropIndex, BOOL& bDropAfter);
	void CustomizeDrawMarker(CDC* pDC);
	void UpdateDocTemplateControls();
	BOOL IsMouseLocked() const;
	CSize GetAutoIconSize(BOOL bLarge) const;
//}}AFX_CODEJOCK_PRIVATE

protected:
//{{AFX_CODEJOCK_PRIVATE
	// System accessibility support.
	virtual HRESULT GetAccessibleParent(IDispatch** ppdispParent);
	virtual HRESULT GetAccessibleChildCount(long* pcountChildren);
	virtual HRESULT GetAccessibleChild(VARIANT varChild, IDispatch** ppdispChild);
	virtual HRESULT GetAccessibleName(VARIANT varChild, BSTR* pszName);
	virtual HRESULT GetAccessibleRole(VARIANT varChild, VARIANT* pvarRole);
	virtual HRESULT AccessibleLocation(long *pxLeft, long *pyTop, long *pcxWidth, long* pcyHeight, VARIANT varChild);
	virtual HRESULT AccessibleHitTest(long xLeft, long yTop, VARIANT* pvarChild);
	virtual HRESULT GetAccessibleState(VARIANT varChild, VARIANT* pvarState);
	virtual CCmdTarget* GetAccessible();
//}}AFX_CODEJOCK_PRIVATE

protected:
//{{AFX_CODEJOCK_PRIVATE

	//{{AFX_VIRTUAL(CXTPCommandBar)
	public:
	virtual void OnFinalRelease();
	virtual INT_PTR OnToolHitTest(CPoint point, TOOLINFO* pTI) const;
	BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	virtual LRESULT OnIdleUpdateCmdUI(WPARAM wParam, LPARAM);
	void FilterToolTipMessage(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL PreviewAccel(UINT chAccel);
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CXTPCommandBar)
	afx_msg void OnUpdateCmdUI();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnInitialUpdate();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	virtual void OnPopupRButtonUp(CXTPCommandBar* pCommandBar, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseLeave();
	afx_msg void OnPaint();
	afx_msg LRESULT OnPrintClient(WPARAM wParam, LPARAM);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg LRESULT OnHelpHitTest(WPARAM, LPARAM lParam);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	afx_msg LRESULT OnGetObject(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG
//}}AFX_CODEJOCK_PRIVATE

public:
	int              m_nStateFlags;         // State of the command bars.
	static int       s_nHoverDelay;         // Hover delay time
	static int       s_nExpandDelay;        // Expand delay time
	static int       s_nExpandHoverDelay;   // Expand hover delay
	BOOL             m_bComboBar;           // TRUE if it is combo box list
	// 2007-08 ctor 0x643f30: m_bTrackOnHover (=TRUE) sits at +0x160, after m_nLockRedraw

protected:
	BOOL             m_bGrabFocus;          // TRUE to grab current focus.
	int              m_nMRUWidth;           // Recent width.
	int              m_nSelected;           // Selected control index.
	int              m_nPopuped;            // Popuped control index.
	HWND             m_hwndFocus;           // The handle of the window that currently has focus.
	UINT             m_nBarID;              // Command bar's identifier.
	BOOL             m_bVisible;            // TRUE if the command bar is visible.
	BOOL             m_bTracking;           // TRUE if the command bar is in tracking mode.
	CWnd*            m_pSite;               // Command bar's site.
	DWORD            m_nIdleFlags;          // Idle flags.
	DWORD            m_dwFlags;             // Command bar's flags.
	DWORD            m_dwStyle;             // Command bar's styles.
	CString          m_strTitle;            // Command bar's caption.
	XTPBarType       m_barType;             // Type of the command bar.
	CXTPControls*    m_pControls;           // A pointer to controls collection.
	XTPBarPosition   m_barPosition;         // Position of the command bar.
	CXTPCommandBars* m_pCommandBars;        // parent command bars class.
	CWnd*            m_pOwner;              // Owner window.
	CSize            m_szIcons;             // Size of the command bar's icons.
	CSize            m_szButtons;           // Size of the command bar's icons.
	BOOL             m_bTextBelow;          // TRUE if text is shown below the CommandBar buttons.
	BOOL             m_bExecOnRButton;      // TRUE if the control button is executed on a right-click
	BOOL             m_bIgnoreUpdateHandler;// TRUE to skip update handler for all child controls
	BOOL             m_bRecursePopup;       // TRUE if popup bar was opened recursively. See TPM_RECURSE flag description.
	int              m_nLockRecurse;        // TRUE if another popup bar is opened recursively.
	BOOL             m_bKeyboardSelect;     // TRUE if last item was selected by keyboard.
	BOOL             m_bCloseable;          // TRUE if the CommandBar can be closed and\or Hidden
	BOOL             m_bCustomizable;       // TRUE if command bar is customizable.
	CRect            m_rcMarker;            // Marker position.
	BOOL             m_bVerticalMarker;     // TRUE to draw marker vertically.
	DWORD_PTR        m_dwData;              // The 32-bit value associated with the command bar.
	UINT*            m_pReturnCmd;          // Return command holder.
	BOOL             m_bCustomizeDialogPresent; // TRUE if the command bar is present in Customize dialog.
	BOOL             m_bAnimatePopup;       // TRUE to animate popup bar.
	BOOL             m_nLockRedraw;         // TRUE if all drawing routines skipped
public:
	BOOL             m_bTrackOnHover;       // TRUE to select item if mouse stay over control
protected:
	CXTPPaintManager* m_pPaintManager;      // Selected paint manager for command bar
	CXTPImageManager* m_pImageManager;      // Selected image manager for command bar
	BOOL             m_bMultiLine;          // True if multi line commandbar
	XTPButtonStyle   m_buttonStyle;         // Default button Style

	CXTPToolTipContext* m_pToolTipContext;  // Tool tip Context.
	CXTPCommandBarAnimation* m_pAnimation;  // Animation context
private:
	int m_nClickedControl;

//{{AFX_CODEJOCK_PRIVATE
	DECLARE_MESSAGE_MAP()
	DECLARE_XTP_COMMANDBAR(CXTPCommandBar)

	class CCommandBarCmdUI;

	DECLARE_INTERFACE_MAP()


	friend class CXTPCommandBars;
	friend class CXTPDockBar;
	friend class CCommandBarCmdUI;
	friend class CXTPControl;
	friend class CXTPControls;
	friend class CXTPControlPopup;
	friend class CXTPToolBar;
	friend class CXTPMouseManager;
	friend class CXTPPopupBar;
	friend class CXTPCustomizeSheet;
	friend class CXTPPaintManager;

//}}AFX_CODEJOCK_PRIVATE
};

//////////////////////////////////////////////////////////////////////////


AFX_INLINE int CXTPCommandBar::IsTrackingMode() const{
	return m_bTracking;
}
AFX_INLINE CXTPControls* CXTPCommandBar::GetControls() const {
	return m_pControls;
}
AFX_INLINE XTPBarType CXTPCommandBar::GetType() const {
	return m_barType;
}
AFX_INLINE XTPBarPosition CXTPCommandBar::GetPosition() const {
	return m_barPosition;
}
AFX_INLINE void CXTPCommandBar::DelayLayout() {
	m_nIdleFlags |= xtpIdleLayout;
}

AFX_INLINE void CXTPCommandBar::DelayRedraw() {
	m_nIdleFlags |= xtpIdleRedraw;
}


AFX_INLINE void CXTPCommandBar::SetTitle(LPCTSTR lpszTitle) {
	m_strTitle = lpszTitle;
	Redraw();
}
AFX_INLINE CString CXTPCommandBar::GetTitle() const {
	return m_strTitle;
}
AFX_INLINE void CXTPCommandBar::SetCommandBars(CXTPCommandBars* pCommandBars){
	m_pCommandBars = pCommandBars;
}
AFX_INLINE HWND CXTPCommandBar::GetTrackFocus() const {
	return m_hwndFocus;
}
AFX_INLINE void CXTPCommandBar::SetTrackFocus(HWND hwnd) {
	m_hwndFocus = hwnd;
}
AFX_INLINE void CXTPCommandBar::SetVisible(BOOL /*bVisible*/) {
}
AFX_INLINE BOOL CXTPCommandBar::IsVisible() const {
	return FALSE;
}
AFX_INLINE BOOL CXTPCommandBar::SetPosition(XTPBarPosition /*barPosition*/) {
	return FALSE;
}
AFX_INLINE CSize CXTPCommandBar::CalcDynamicLayout(int, DWORD /*nMode*/) {
	return CSize(0, 0);
}
AFX_INLINE CXTPCommandBar* CXTPCommandBar::GetParentCommandBar() const {
	return NULL;
}
AFX_INLINE void CXTPCommandBar::OnRecalcLayout() {

}
AFX_INLINE BOOL CXTPCommandBar::IsCustomizable() const{
	return m_bCustomizable;
}
AFX_INLINE BOOL CXTPCommandBar::IsDialogBar() const {
	return FALSE;
}
AFX_INLINE void CXTPCommandBar::EnableCustomization(BOOL bEnable) {
	if (!IsDialogBar()) m_bCustomizable = bEnable;
}

AFX_INLINE void CXTPCommandBar::SetIconSize(CSize size) {
	m_szIcons = size;
}
AFX_INLINE void CXTPCommandBar::SetButtonSize(CSize size) {
	m_szButtons = size;
}

AFX_INLINE DWORD CXTPCommandBar::GetFlags() const {
	return m_dwFlags;
}

AFX_INLINE UINT CXTPCommandBar::GetBarID() const {
	return m_nBarID;
}
AFX_INLINE void CXTPCommandBar::SetCommandBarData(DWORD_PTR dwData) {
	m_dwData = dwData;
}
AFX_INLINE DWORD_PTR CXTPCommandBar::GetCommandBarData() const {
	return m_dwData;
}
AFX_INLINE void CXTPCommandBar::LockRedraw() {
	m_nLockRedraw ++;
}
AFX_INLINE void CXTPCommandBar::UnlockRedraw() {
	m_nLockRedraw --;
	if (m_nLockRedraw == 0 && (m_nIdleFlags & xtpIdleRedraw))
		Redraw();
}
AFX_INLINE void CXTPCommandBar::SetGrabFocus(BOOL bGrabFocus) {
	m_bGrabFocus = bGrabFocus;
}
AFX_INLINE BOOL CXTPCommandBar::PreviewAccel(UINT) {
	return FALSE;
}
AFX_INLINE BOOL CXTPCommandBar::IsRibbonBar() const {
	return FALSE;
}
AFX_INLINE BOOL CXTPCommandBar::IsPopupBar() const {
	return FALSE;
}
AFX_INLINE void CXTPCommandBar::SetBarID(UINT nID) {
	m_nBarID = nID;
}
AFX_INLINE XTPButtonStyle CXTPCommandBar::GetDefaultButtonStyle() const {
	return m_buttonStyle;
}

AFX_INLINE void CXTPCommandBar::SetDefaultButtonStyle(XTPButtonStyle buttonStyle) {
	m_buttonStyle = buttonStyle;
}
AFX_INLINE BOOL CXTPCommandBar::IsResizable() const {
	return FALSE;
}
AFX_INLINE void CXTPCommandBar::OnPopupRButtonUp(CXTPCommandBar* /*pCommandBar*/, CPoint /*point*/) {

}


#endif //#if !defined(__XTPCOMMANDBAR_H__)

// ---- end Source/CommandBars/XTPCommandBar.h
#include "Source/CommandBars/XTPToolBar.h"
#include "Source/CommandBars/XTPReBar.h"
#include "Source/CommandBars/XTPMenuBar.h"
#include "Source/CommandBars/XTPStatusBar.h"
#include "Source/CommandBars/XTPFrameWnd.h"
#include "Source/CommandBars/XTPDockBar.h"
#include "Source/CommandBars/XTPCommandBars.h"
#include "Source/CommandBars/XTPDialogBar.h"
#include "Source/CommandBars/XTPTabToolBar.h"

#include "Source/CommandBars/XTPControls.h"
#include "Source/CommandBars/XTPControlButton.h"
#include "Source/CommandBars/XTPControlPopup.h"
#include "Source/CommandBars/XTPControlComboBox.h"
#include "Source/CommandBars/XTPControlEdit.h"
#include "Source/CommandBars/XTPControlPopupColor.h"
#include "Source/CommandBars/XTPControlComboBoxExt.h"
#include "Source/CommandBars/XTPControlCustom.h"
#include "Source/CommandBars/XTPControlListBox.h"
#include "Source/CommandBars/XTPControlExt.h"
#include "Source/CommandBars/XTPControlGallery.h"
#include "Source/CommandBars/XTPControlSlider.h"
#include "Source/CommandBars/XTPControlScrollBar.h"

#include "Source/CommandBars/XTPPaintManager.h"
#include "Source/CommandBars/XTPShortcutManager.h"
#include "Source/CommandBars/XTPHookManager.h"
#include "Source/CommandBars/XTPMouseManager.h"
#include "Source/CommandBars/XTPShadowsManager.h"
#include "Source/CommandBars/XTPSoundManager.h"

#include "Source/CommandBars/XTPTabClientWnd.h"
#include "Source/CommandBars/XTPImageEditor.h"

#include "Source/CommandBars/XTPCustomizeSheet.h"
#include "Source/CommandBars/XTPCustomizeCommandsPage.h"
#include "Source/CommandBars/XTPCustomizeOptionsPage.h"
#include "Source/CommandBars/XTPCustomizeKeyboardPage.h"
#include "Source/CommandBars/XTPCustomizeMenusPage.h"
#include "Source/CommandBars/XTPCustomizeTools.h"

#include "Source/CommandBars/XTPDialogBase.h"

#include "Source/CommandBars/XTPOffice2007Theme.h"
#include "Source/CommandBars/XTPOffice2007FrameHook.h"


#endif //#if !defined(__XTPCOMMANDBARINCLUDES_H__)

// ---- end Source/CommandBars/Includes.h     // _XTP_INCLUDE_COMMANDBARS
#endif

#if !defined(_XTP_EXCLUDE_DOCKINGPANE)
#include "Source/DockingPane/Includes.h"     // _XTP_INCLUDE_DOCKINGPANE
#endif

#if !defined(_XTP_EXCLUDE_PROPERTYGRID)
#include "Source/PropertyGrid/Includes.h"    // _XTP_INCLUDE_PROPERTYGRID
#endif

#if !defined(_XTP_EXCLUDE_REPORTCONTROL)
#include "Source/ReportControl/Includes.h"   // _XTP_INCLUDE_REPORTCONTROL
#endif

#if !defined(_XTP_EXCLUDE_CALENDAR)
#include "Source/Calendar/Includes.h"        // _XTP_INCLUDE_CALENDAR
#endif

#if !defined(_XTP_EXCLUDE_TASKPANEL)
#include "Source/TaskPanel/Includes.h"       // _XTP_INCLUDE_TASKPANEL
#endif

#if !defined(_XTP_EXCLUDE_SHORTCUTBAR)
#include "Source/ShortcutBar/Includes.h"     // _XTP_INCLUDE_SHORTCUTBAR
#endif

#if !defined(_XTP_EXCLUDE_SKINFRAMEWORK)
#include "Source/SkinFramework/Includes.h"   // _XTP_INCLUDE_SKINFRAMEWORK
#endif

#if !defined(_XTP_EXCLUDE_RIBBON)
#include "Source/Ribbon/Includes.h"          // _XTP_INCLUDE_RIBBON
#endif

#if !defined(_XTP_EXCLUDE_SYNTAXEDIT)
#include "Source/SyntaxEdit/Includes.h"      // _XTP_INCLUDE_SYNTAXEDIT
#endif

#define _XTPLIB_FILE_VERSION_STRING_(x) #x
#define _XTPLIB_FILE_VERSION_STRING(x) _XTPLIB_FILE_VERSION_STRING_(x)

#if !defined(_XTP_DEMOMODE) && !defined(_XTP_RETAIL)
#define _XTPLIB_VISUALSTUIDO_VERSION ""
#else
#if _MSC_VER < 1200
#define _XTPLIB_VISUALSTUIDO_VERSION "vc50"
#endif
#if _MSC_VER == 1200
#define _XTPLIB_VISUALSTUIDO_VERSION "vc60"
#endif
#if _MSC_VER == 1300
#define _XTPLIB_VISUALSTUIDO_VERSION "vc70"
#endif
#if _MSC_VER == 1310
#define _XTPLIB_VISUALSTUIDO_VERSION "vc71"
#endif
#if _MSC_VER == 1400
#define _XTPLIB_VISUALSTUIDO_VERSION "vc80"
#endif
#if _MSC_VER == 1500
#define _XTPLIB_VISUALSTUIDO_VERSION "vc90"
#endif


#ifndef _XTPLIB_VISUALSTUIDO_VERSION
#error "Unknown Visual Studio version"
#endif
#endif

#define _XTPLIB_FILE_VERSION _XTPLIB_FILE_VERSION_STRING(_XTPLIB_VERSION_PREFIX)


//------------------------------------------------------
// Xtreme link to the appropriate dll or static library:
//------------------------------------------------------
#if defined(_AFXDLL) && defined(_XTP_STATICLINK)
	#if defined(_DEBUG)
		#if defined(_UNICODE)
			#define _XTPLIB_PROJECT_CONFIGURATION "DSUD"
		#else
			#define _XTPLIB_PROJECT_CONFIGURATION "DSD"
		#endif // _UNICODE
	#else
		#if defined(_UNICODE)
			#define _XTPLIB_PROJECT_CONFIGURATION "DSU"
		#else
			#define _XTPLIB_PROJECT_CONFIGURATION "DS"
		#endif // _UNICODE
	#endif // _DEBUG
	#define _XTPLIB_LINK_TYPE   "lib"
	#define _XTPLIB_LINK_IS_DLL 0
#elif !defined(_AFXDLL)
	#if defined(_DEBUG)
		#if defined(_UNICODE)
			#define _XTPLIB_PROJECT_CONFIGURATION "SUD"
		#else
			#define _XTPLIB_PROJECT_CONFIGURATION "SD"
		#endif // _UNICODE
	#else
		#if defined(_UNICODE)
			#define _XTPLIB_PROJECT_CONFIGURATION "SU"
		#else
			#define _XTPLIB_PROJECT_CONFIGURATION "S"
		#endif // _UNICODE
	#endif // _DEBUG
	#define _XTPLIB_LINK_TYPE   "lib"
	#define _XTPLIB_LINK_IS_DLL 0
#else
	#if defined(_DEBUG)
		#if defined(_UNICODE)
			#define _XTPLIB_PROJECT_CONFIGURATION "UD"
		#else
			#define _XTPLIB_PROJECT_CONFIGURATION "D"
		#endif // _UNICODE
	#else
		#if defined(_UNICODE)
			#define _XTPLIB_PROJECT_CONFIGURATION "U"
		#else
			#define _XTPLIB_PROJECT_CONFIGURATION ""
		#endif // _UNICODE
	#endif // _DEBUG
	#define _XTPLIB_LINK_TYPE   "dll"
	#define _XTPLIB_LINK_IS_DLL 1
#endif // !defined(_AFXDLL) || defined(_XTP_STATICLINK)

#if (_XTPLIB_LINK_IS_DLL == 0) && defined(_XTP_DEMOMODE)
	#pragma message(" ")
	#pragma message("----------------------------------------------------------------------------------------------")
	#pragma message(" The evaluation version of the toolkit only supports DLL configurations.")
	#pragma message(" To purchase the full version (with static link support) please visit http://www.codejock.com")
	#pragma message("----------------------------------------------------------------------------------------------")
	#pragma message(" ")
	#error This build configuration is not supported by the evaluation library
#endif

#if !(defined(_DEBUG)) && defined(_XTP_DEMOMODE)
	#pragma message(" ")
	#pragma message("----------------------------------------------------------------------------------------------")
	#pragma message(" The evaluation version of the toolkit only supports DEBUG configurations.")
	#pragma message(" To purchase the full version (with static link support) please visit http://www.codejock.com")
	#pragma message("----------------------------------------------------------------------------------------------")
	#pragma message(" ")
	#error This build configuration is not supported by the evaluation library
#endif


#if defined(_XTP_DEMOMODE)
	#define _XTPLIB_PROJECT_EVAL "Eval"
#else
	#define _XTPLIB_PROJECT_EVAL ""
#endif

#if defined(_WIN64)
	#define _XTPLIB_PLATFORM "x64"
#else
	#define _XTPLIB_PLATFORM ""
#endif

#ifndef _XTPLIB_NOAUTOLINK
	#pragma comment(lib, "ToolkitPro" _XTPLIB_PROJECT_EVAL _XTPLIB_FILE_VERSION _XTPLIB_VISUALSTUIDO_VERSION _XTPLIB_PLATFORM _XTPLIB_PROJECT_CONFIGURATION ".lib")
	#pragma message("Automatically linking with ToolkitPro" _XTPLIB_PROJECT_EVAL _XTPLIB_FILE_VERSION _XTPLIB_VISUALSTUIDO_VERSION _XTPLIB_PLATFORM _XTPLIB_PROJECT_CONFIGURATION "." _XTPLIB_LINK_TYPE)
#endif //_XTPLIB_NOAUTOLINK

#if !defined(_AFXDLL) && !defined(_XTPLIB_NOAUTOLIBIGNORE)
#ifdef _DEBUG
	#pragma comment(linker, "/NODEFAULTLIB:libcd.lib")
#else
	#pragma comment(linker, "/NODEFAULTLIB:libc.lib")
#endif
#endif

#undef _XTPLIB_FILE_VERSION
#undef _XTPLIB_PROJECT_CONFIGURATION
#undef _XTPLIB_PROJECT_EVAL
#undef _XTPLIB_LINK_TYPE
#undef _XTPLIB_LINK_IS_DLL

#if (_MSC_VER > 1100)
#pragma pack(pop)
#pragma warning(pop)
#endif

/////////////////////////////////////////////////////////////////////////////

// ---- end Source/XTToolkitPro.h

// ---- end Source/StdAfx.h
#include "Source/CommandBars/Resource.h"

#include "Source/Common/XTPVC80Helpers.h"
#include "Source/Common/XTPDrawHelpers.h"
#include "Source/Common/XTPColorManager.h"
#include "Source/Common/XTPImageManager.h"
#include "Source/Common/XTPToolTipContext.h"

#include "Source/CommandBars/XTPPopupBar.h"
#include "Source/CommandBars/XTPPaintManager.h"
#include "Source/CommandBars/XTPControls.h"
#include "Source/CommandBars/XTPControl.h"
#include "Source/CommandBars/XTPControlButton.h"
#include "Source/CommandBars/XTPShortcutManager.h"
#include "Source/CommandBars/XTPControlPopup.h"
#include "Source/CommandBars/XTPShadowsManager.h"
#include "Source/CommandBars/XTPToolBar.h"
#include "Source/CommandBars/XTPCommandBars.h"
#include "Source/CommandBars/XTPMouseManager.h"
#include "Source/CommandBars/XTPSoundManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

double CXTPPopupBar::m_dMaxWidthDivisor = 1.0/3.0;

#ifndef EVENT_SYSTEM_MENUPOPUPSTART
#define EVENT_SYSTEM_MENUPOPUPSTART     0x0006
#define EVENT_SYSTEM_MENUPOPUPEND       0x0007
#define OBJID_MENU 0xFFFFFFFD
#endif

#define TID_HOVERUP 5001
#define TID_HOVERDOWN 5002
#define TID_TEAROFFSELECTED 5003
#define TID_EXPANDHOVER 5004


class CXTPPopupBar::CControlExpandButton: public CXTPControlButton
{
public:
	CControlExpandButton()
	{
		m_controlType = xtpControlButton;
		m_dwFlags = xtpFlagManualUpdate | xtpFlagNoMovable | xtpFlagSkipFocus | xtpFlagShowPopupBarTip;
	}
	void Draw(CDC* pDC);
	virtual void OnExecute();
};

void CXTPPopupBar::CControlExpandButton::Draw(CDC* pDC)
{
	GetPaintManager()->DrawSpecialControl(pDC, xtpButtonExpandMenu, this, m_pParent, TRUE, NULL);
}

void CXTPPopupBar::CControlExpandButton::OnExecute()
{
	((CXTPPopupBar*)m_pParent)->ExpandBar();
}


IMPLEMENT_XTP_COMMANDBAR(CXTPPopupBar, CXTPCommandBar)

CXTPPopupBar::CXTPPopupBar()
{
	m_scrollInfo.Init(this, TID_HOVERUP, TID_HOVERDOWN);

	m_barType = xtpBarTypePopup;
	m_barPosition = xtpBarPopup;

	m_pControlPopup = 0;
	m_ptPopup = 0;
	m_rcExclude.SetRectEmpty();
	m_rcTearOffGripper.SetRectEmpty();
	m_rcResizeGripper.SetRectEmpty();
	m_bResizable = FALSE;
	m_popupFlags = xtpPopupRight;
	m_bDynamicLayout = FALSE;

	m_bTearOffPopup = FALSE;
	m_bTearOffTracking = FALSE;
	m_nTearOffID = 0;
	m_nTearOffWidth = 0;

	m_bShowShadow = TRUE;
	m_rcBorders = CRect(2, 4, 2, 4);
	m_bExpanding = FALSE;

	m_nMRUWidth = 0;
	m_bDoubleGripper = FALSE;

	m_pTearOffBar = NULL;
	m_szTearOffBar = CSize(0, 0);
	m_nTearOffTimer = 0;

	m_bContextMenu = FALSE;

}

CXTPPopupBar* CXTPPopupBar::CreatePopupBar(CXTPCommandBars* pCommandBars)
{
	CXTPPopupBar* pPopupBar = (CXTPPopupBar*)CXTPCommandBars::m_pPopupBarClass->CreateObject();
	pPopupBar->SetCommandBars(pCommandBars);
	return pPopupBar;
}

CXTPPopupBar::~CXTPPopupBar()
{
}

void CXTPPopupBar::SetTearOffPopup(LPCTSTR strCaption, UINT nID, int nWidth)
{
	if (nID == 0)
	{
		m_bTearOffPopup = FALSE;
	}
	else
	{
		m_bTearOffPopup = TRUE;
		m_strTearOffCaption = strCaption;
		m_nTearOffID = nID;
		m_nTearOffWidth = nWidth;
	}
}
BOOL CXTPPopupBar::IsTearOffPopup(CString& strCaption, UINT& nID, int& nWidth)
{
	strCaption = m_strTearOffCaption;
	nID = m_nTearOffID;
	nWidth = m_nTearOffWidth;

	return m_bTearOffPopup;
}

BOOL CXTPPopupBar::IsVisible() const
{
	return (m_hWnd != 0) && IsWindowVisible();
}

void CXTPPopupBar::ExpandBar()
{
	if (m_bExpanded == FALSE && m_bCollapsed == TRUE)
	{
		SAFE_CALLPTR(m_pToolTipContext, CancelToolTips());

		m_bExpanding = TRUE;
		m_bExpanded = TRUE;
		SetPopuped(-1);
		SetSelected(-1);
		OnRecalcLayout();
		XTPMouseManager()->SetForceExpanded(TRUE);
		XTPMouseManager()->IgnoreLButtonUp();
	}
}

BOOL CXTPPopupBar::Create()
{
	if (m_hWnd)
		return TRUE;

	CXTPCommandBars* pCommandBars = GetCommandBars();
	UINT nClassStyle = !pCommandBars || pCommandBars->GetCommandBarsOptions()->bUseSystemSaveBitsStyle ? CS_SAVEBITS | CS_DBLCLKS : CS_DBLCLKS;

	CXTPDrawHelpers::RegisterWndClass(0, _T("XTPPopupBar"), nClassStyle);

	int nLayoutRTL = pCommandBars && pCommandBars->IsLayoutRTL() ? WS_EX_LAYOUTRTL : 0;
	if (!pCommandBars && GetImageManager()->IsDrawReverted() == 1) nLayoutRTL = WS_EX_LAYOUTRTL;

	if (!CreateEx(WS_EX_TOOLWINDOW | nLayoutRTL, _T("XTPPopupBar"), 0, MFS_SYNCACTIVE | WS_POPUP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, CRect(0, 0, 0, 0), GetSite(), 0))
		return FALSE;

	SetWindowText(m_strTitle);

	return TRUE;
}

#ifndef SPI_GETMENUANIMATION
#define SPI_GETMENUANIMATION                0x1002
#endif

#ifndef SPI_GETMENUFADE
#define SPI_GETMENUFADE                     0x1012
#endif


XTPAnimationType CXTPPopupBar::GetAnimationType() const
{
	CXTPCommandBars* pCommandBars = GetCommandBars();
	if (pCommandBars)
	{
		if (GetWindow(GW_CHILD))
			return xtpAnimateNone;

		XTPAnimationType animationType = pCommandBars->GetCommandBarsOptions()->animationType;

		switch (animationType)
		{
			case xtpAnimateWindowsDefault:
			{
				BOOL bEnabled = FALSE;
				if (!SystemParametersInfo(SPI_GETMENUANIMATION, 0, &bEnabled, 0))
					return xtpAnimateNone;

				if (!bEnabled)
					return xtpAnimateNone;

				BOOL bFadeAnimation = FALSE;

				if (!SystemParametersInfo(SPI_GETMENUFADE, 0, &bFadeAnimation, 0))
					return xtpAnimateSlide;

				animationType = bFadeAnimation ? xtpAnimateFade : xtpAnimateSlide;
			}
			break;

			// choose any animation based on a random number
			case xtpAnimateRandom:
			{
				switch (RAND_S() % 3)
				{
					case 0:
						animationType = xtpAnimateFade;
						break;

					case 1:
						animationType = xtpAnimateSlide;
						break;

					default:
						animationType = xtpAnimateUnfold;
						break;
				}
			}
			break;
		}

		return animationType;
	}
	return xtpAnimateNone;

}

void CXTPPopupBar::OnControlsChanged()
{
	m_nSelected = -1;
	m_nPopuped = -1;

	OnRecalcLayout();
}

void CXTPPopupBar::RecalcSizeLayout()
{
	if (!m_bDynamicLayout && GetSafeHwnd() && IsTrackingMode())
	{
		CRect rc = CalculatePopupRect(CalcDynamicLayout(0, 0));
		CXTPWindowRect rcWindow(this);

		if (rc == rcWindow)
		{
			Redraw();
			return;
		}

		CXTPCommandBars* pCommandBars = GetCommandBars();
		BOOL bShowKeyboardTips = IsKeyboardTipsVisible();
		if (bShowKeyboardTips && pCommandBars) pCommandBars->HideKeyboardTips();

		SetWindowRgn(NULL, FALSE);

		SetWindowPos(0, rc.left, rc.top, rc.Width(), rc.Height(), SWP_NOMOVE | SWP_SHOWWINDOW | SWP_NOACTIVATE | SWP_NOOWNERZORDER | SWP_NOZORDER);
		GetPaintManager()->SetCommandBarRegion(this);

		XTPShadowsManager()->OffsetShadow(this, rc.Size() - rcWindow.Size());

		Redraw();
	}
}

void CXTPPopupBar::OnRecalcLayout()
{
	if (!m_bDynamicLayout && GetSafeHwnd() && IsTrackingMode())
	{

		UpdateShortcuts();
		UpdateFlags();

		CRect rc = CalculatePopupRect(CalcDynamicLayout(0, 0));
		CXTPWindowRect rcWindow(this);

		if (!m_bExpanding && rc == rcWindow)
		{
			Redraw();
			return;
		}

		CXTPCommandBars* pCommandBars = GetCommandBars();
		BOOL bShowKeyboardTips = IsKeyboardTipsVisible();
		if (bShowKeyboardTips && pCommandBars) pCommandBars->HideKeyboardTips();

		XTPShadowsManager()->RemoveShadow(this);

		BOOL bChanged = FALSE;

		if (m_bExpanding)
		{
			BOOL bExpandDown = rcWindow.bottom < rc.bottom;

			XTPAnimationType animationType = GetAnimationType();
			if (IsAnimateType(animationType))
			{
				CDC* pDC = GetDesktopWindow()->GetDC();

				CBitmap bmp;
				bmp.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
				CXTPCompatibleDC dcWindow(pDC, &bmp);

				dcWindow.BitBlt(0, 0, rc.Width(), rc.Height(), pDC, rc.left, rc.top, SRCCOPY);
				GetDesktopWindow()->ReleaseDC(pDC);

				ShowWindow(SW_HIDE);
				GetSite()->UpdateWindow();

				SetWindowPos(0, rc.left, rc.top, rc.Width(), rc.Height(), SWP_SHOWWINDOW | SWP_NOACTIVATE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_NOREDRAW);
				GetPaintManager()->SetCommandBarRegion(this);
				bChanged = TRUE;

				CWindowDC paintDC(this);
				CXTPClientRect rcClientPost(this);

				BOOL dwLayout = CXTPDrawHelpers::IsContextRTL(&paintDC);
				CXTPDrawHelpers::SetContextRTL(&paintDC, FALSE);
				paintDC.BitBlt(0, 0, rc.Width(), rc.Height(), &dcWindow, 0, 0, SRCCOPY);
				CXTPDrawHelpers::SetContextRTL(&paintDC, dwLayout);


				CXTPBufferDC animationDC(paintDC, rcClientPost);
				DrawCommandBar(&animationDC, rcClientPost);

				// Animation
				GetPaintManager()->AnimateExpanding(this, &paintDC, &animationDC, bExpandDown);
			}
			XTPSoundManager()->PlaySystemSound(xtpSoundMenuPopup);
		}

		if (!bChanged)
		{
			SetWindowPos(0, rc.left, rc.top, rc.Width(), rc.Height(), SWP_SHOWWINDOW | SWP_NOACTIVATE | SWP_NOOWNERZORDER | SWP_NOZORDER);
			GetPaintManager()->SetCommandBarRegion(this);
		}

		if (m_barPosition == xtpBarPopup && m_bShowShadow)
			XTPShadowsManager()->SetShadow(this, m_rcExclude);

		if (m_pControlPopup)
			m_pControlPopup->UpdateShadow();

		Redraw();

		if (bShowKeyboardTips)
		{
			PostMessage(WM_TIMER, XTP_TID_SHOWKEYBOARDTIPS);
		}

		m_bExpanding = FALSE;
	}
}

void CXTPPopupBar::_MakeSameWidth(int nStart, int nLast, int nWidth)
{
	for (int i = nStart; i < nLast; i++)
	{
		CXTPControl* pControl = GetControl(i);
		if (!pControl || pControl->GetParent() != this || !pControl->IsVisible())
			continue;

		CRect rc = pControl->GetRect();
		pControl->SetRect(CRect(rc.left, rc.top, rc.left + nWidth, rc.bottom));
	}
}

CRect CXTPPopupBar::GetBorders()
{
	if (m_barType == xtpBarTypeNormal)
		return m_rcBorders;

	return GetPaintManager()->GetCommandBarBorders(this);
}

CSize CXTPPopupBar::CalcDynamicLayout(int nLength, DWORD /*nMode*/)
{
	m_bDynamicLayout = TRUE;

	CClientDC dc(this);
	CXTPFontDC font(&dc, GetPaintManager()->GetCommandBarFont(this));

	RECT rcWork;
	SystemParametersInfo(SPI_GETWORKAREA, NULL, &rcWork, 0);

	CRect rcBorders = GetBorders();
	CSize szTearOffGripper(0);
	if (m_bTearOffPopup)
	{
		szTearOffGripper = GetPaintManager()->DrawTearOffGripper(&dc, 0, FALSE, FALSE);
		rcBorders.top += szTearOffGripper.cy;
	}

	if (m_barType == xtpBarTypeNormal)
	{
		UpdateShortcuts();

		CSize sz = m_pControls->CalcDynamicSize(&dc, GetWidth(), LM_COMMIT | LM_HORZ | LM_POPUP, rcBorders);

		m_rcTearOffGripper.SetRect(rcBorders.left, rcBorders.top - szTearOffGripper.cy, sz.cx - rcBorders.right, rcBorders.top);
		m_rcResizeGripper.SetRectEmpty();

		m_bDynamicLayout = FALSE;

		return sz;
	}

	CXTPControl* pControlGallery = GetControls()->FindControl(xtpControlGallery, -1, TRUE, FALSE);

	m_bResizable = pControlGallery ? pControlGallery->IsCustomizeResizeAllow() : 0;
	CSize szResizeGripper(0);
	if (m_bResizable)
	{
		szResizeGripper.cy = m_bResizable != 2 ? 11 : 8;
		rcBorders.bottom += szResizeGripper.cy;
	}

	if (nLength == 0)
	{
		for (int i = 0; i < GetControlCount(); i++)
		{
			CXTPControl* pControl = GetControl(i);
			if (!pControl || pControl->GetParent() != this)
				continue;

			pControl->OnCalcDynamicSize(0);
		}

		UpdateExpandingState();
		UpdateShortcuts();
	}


	CXTPControl* pButtonExpand = m_pControls->FindControl(XTP_ID_POPUPBAR_EXPAND);
	CSize szButtonExpand(0);
	if (m_bCollapsed)
	{
		szButtonExpand = GetPaintManager()->DrawSpecialControl(&dc, xtpButtonExpandMenu, NULL, this, FALSE, NULL);
		rcBorders.bottom += szButtonExpand.cy;

		if (!pButtonExpand)
			pButtonExpand = m_pControls->Add(new CControlExpandButton(), XTP_ID_POPUPBAR_EXPAND, _T(""), -1, TRUE);
		pButtonExpand->SetHideFlags(xtpHideGeneric);
	}
	else if (pButtonExpand) pButtonExpand->SetHideFlags(xtpHideGeneric);

	CSize sz = m_pControls->CalcPopupSize(&dc, nLength, rcBorders);

	if (m_bCollapsed)
	{
		pButtonExpand->SetHideFlags(xtpNoHide);
		pButtonExpand->SetRect(CRect(rcBorders.left, sz.cy - rcBorders.bottom, sz.cx - rcBorders.right, sz.cy - rcBorders.bottom + szButtonExpand.cy));
	}

	m_rcTearOffGripper.SetRect(rcBorders.left, rcBorders.top - szTearOffGripper.cy, sz.cx - rcBorders.right, rcBorders.top);
	m_rcResizeGripper.SetRect(rcBorders.left, sz.cy - rcBorders.bottom, sz.cx - rcBorders.right, sz.cy - rcBorders.bottom + szResizeGripper.cy);

	m_bDynamicLayout = FALSE;

	return sz;
}

CRect CXTPPopupBar::CalculatePopupRect(CSize sz)
{
	RECT rcWork = m_rcExclude.IsRectEmpty() ? XTPMultiMonitor()->GetWorkArea(m_ptPopup) : XTPMultiMonitor()->GetWorkArea(m_rcExclude);
	RECT rcScreen = m_rcExclude.IsRectEmpty() ? XTPMultiMonitor()->GetScreenArea(m_ptPopup) : XTPMultiMonitor()->GetScreenArea(m_rcExclude);

	// If point is on the screen, but not in the work area, then the point
	// must be inside an AppBar.
	if (m_rcExclude.IsRectEmpty() && PtInRect(&rcScreen, m_ptPopup) && !PtInRect(&rcWork, m_ptPopup))
	{
		rcWork = rcScreen;
	}

	rcWork.bottom -= 5;  // for shadow

	CPoint ptCenterRect = m_rcExclude.CenterPoint();
	BOOL bScroll = FALSE, bWrap = FALSE;
	CXTPCommandBars* pCommandars = GetCommandBars();
	BOOL bNoScroll = (pCommandars ? pCommandars->GetCommandBarsOptions()->bWrapLargePopups : FALSE) || m_bMultiLine;


	if (m_rcExclude.Height() == 0 && m_ptPopup.y > rcWork.bottom)
	{
		m_ptPopup.y = m_ptPopup.y - sz.cy;
	}
	else if (m_ptPopup.y + sz.cy > rcWork.bottom)
	{
		if (m_rcExclude.Height() == 0)
		{
			m_ptPopup.y = (m_ptPopup.y < (rcWork.bottom - rcWork.top)/2 ? rcWork.bottom : m_ptPopup.y)- sz.cy;
		}
		else
		{
			if (m_popupFlags & xtpPopupDown)
			{
				m_ptPopup.y = m_rcExclude.top - sz.cy;

				if (m_ptPopup.y < rcWork.top)
				{
					if (bNoScroll)
					{
						m_popupFlags &= ~xtpPopupDown;
						if (m_pControlPopup && (m_pControlPopup->GetType() != xtpControlComboBox || GetParentCommandBar()->GetType() == xtpBarTypePopup))
						{
							m_rcExclude = m_pControlPopup->GetRect();

							AdjustExcludeRect(m_rcExclude, TRUE);
							GetParentCommandBar()->ClientToScreen(m_rcExclude);
						}

						if (m_popupFlags & xtpPopupLeft)
						{
							m_ptPopup.y = rcWork.bottom - sz.cy;
						}
						else
						{
							m_ptPopup.x = m_rcExclude.right;
							m_ptPopup.y = rcWork.bottom - sz.cy;
						}
					}
					else
					{
						bScroll = TRUE;
						if (ptCenterRect.y > (rcWork.bottom - rcWork.top)/2)
						{
							m_ptPopup.y = rcWork.top;
							sz.cy = m_rcExclude.top - rcWork.top;
						}
						else
						{
							m_ptPopup.y = m_rcExclude.bottom;
							sz.cy = rcWork.bottom - m_ptPopup.y;
						}
					}
				}
			}
			else
			{
				m_ptPopup.y = rcWork.bottom - sz.cy;
			}
		}

		if (m_ptPopup.y < rcWork.top) m_ptPopup.y = rcWork.top;

		if (m_ptPopup.y + sz.cy > rcWork.bottom)
		{
			ASSERT(m_ptPopup.y == rcWork.top);

			if (bNoScroll)
			{
				bWrap = TRUE;
			}
			else
			{
				sz.cy = rcWork.bottom - m_ptPopup.y;
				bScroll = TRUE;
			}
		}
	}

	if (bWrap && !m_bMultiLine && (GetType() == xtpBarTypePopup))
	{
		sz = CalcDynamicLayout(rcWork.bottom - rcWork.top, 0);
	}

	if (m_popupFlags == (xtpPopupLeft | xtpPopupDown) && m_rcExclude.Width() != 0)
		m_ptPopup.x = m_rcExclude.right - sz.cx;
	else if (m_popupFlags & xtpPopupLeft && m_rcExclude.Width() != 0)
		m_ptPopup.x = m_rcExclude.left - sz.cx;
	else if ((m_popupFlags & xtpPopupLeft) && m_rcExclude.Width() == 0)
		m_ptPopup.x -= sz.cx;

	if (m_ptPopup.x + sz.cx > rcWork.right)
	{
		if (m_rcExclude.Width() == 0 && m_ptPopup.x > rcWork.right)
			m_ptPopup.x = m_ptPopup.x - sz.cx;
		else if (m_rcExclude.Width() == 0)
			m_ptPopup.x = rcWork.right - sz.cx;
		else
		{
			m_ptPopup.x = (m_popupFlags & xtpPopupDown ? rcWork.right : m_rcExclude.left) - sz.cx ;
			m_popupFlags |= xtpPopupLeft;
		}
		if (m_ptPopup.x < rcWork.left)
			m_ptPopup.x = rcWork.left;
	}
	else if (m_ptPopup.x < rcWork.left)
	{
		if (m_rcExclude.Width() != 0)
		{
			m_ptPopup.x = m_popupFlags & xtpPopupDown ? rcWork.left : m_rcExclude.right;
			m_popupFlags &= ~xtpPopupLeft;
		}
		else if (m_popupFlags & xtpPopupLeft)
		{
			m_ptPopup.x = rcWork.left;
			m_popupFlags &= ~xtpPopupLeft;
		}
	}

	m_scrollInfo.bScroll = bScroll && (GetType() == xtpBarTypePopup && GetPosition() == xtpBarPopup);
	if (m_scrollInfo.bScroll)
	{
		m_scrollInfo.nScrollFirst = 0;
		AdjustScrolling(&sz);
	}

	return CRect(m_ptPopup, sz);
}

void CXTPPopupBar::UpdateLocation(CSize sz)
{
	CRect rc = CalculatePopupRect(sz);
	SetWindowPos(&CWnd::wndTopMost, rc.left, rc.top, rc.Width(), rc.Height(), SWP_NOACTIVATE | SWP_NOOWNERZORDER | SWP_SHOWWINDOW | (IsWindowVisible() ? SWP_NOZORDER : 0));
}

void CXTPPopupBar::AdjustScrolling(LPSIZE lpSize, BOOL bDown, BOOL bInvalidate)
{
	CSize sz = lpSize ? *lpSize : CXTPWindowRect(this).Size();

	m_scrollInfo.btnDown.m_rc.SetRectEmpty();
	m_scrollInfo.btnUp.m_rc.SetRectEmpty();
	int nCount = GetControlCount();
	CRect rcBorders = GetBorders();

	int nSeparator = GetPaintManager()->DrawCommandBarSeparator(NULL, this, NULL, FALSE).cy;

	CSize szTearOffGripper(0);
	if (m_bTearOffPopup)
	{
		szTearOffGripper = GetPaintManager()->DrawTearOffGripper(NULL, 0, FALSE, FALSE);
		rcBorders.top += szTearOffGripper.cy;
	}
	if (m_bResizable)
	{
		rcBorders.bottom += m_rcResizeGripper.Height();
	}

	CXTPControl* pButtonExpand = m_pControls->FindControl(XTP_ID_POPUPBAR_EXPAND);
	CSize szButtonExpand(0);

	if (m_bCollapsed)
	{
		szButtonExpand = GetPaintManager()->DrawSpecialControl(NULL, xtpButtonExpandMenu, NULL, this, FALSE, NULL);
		rcBorders.bottom += szButtonExpand.cy;

		if (!pButtonExpand)
			pButtonExpand = m_pControls->Add(new CControlExpandButton(), XTP_ID_POPUPBAR_EXPAND, _T(""), -1, TRUE);
		pButtonExpand->SetHideFlags(xtpHideGeneric);
	}
	else if (pButtonExpand) pButtonExpand->SetHideFlags(xtpHideGeneric);


	int nScrollHeight = 16;
	int i;

	if (!bDown)
	{
		if (m_scrollInfo.nScrollFirst == 1)
			m_scrollInfo.nScrollFirst = 0;

		int nPos = rcBorders.top;
		if (m_scrollInfo.nScrollFirst != 0)
		{
			nPos += nScrollHeight;
			m_scrollInfo.btnDown.m_rc.SetRect(rcBorders.left, rcBorders.top, sz.cx - rcBorders.right, nPos);
		}

		ASSERT(m_scrollInfo.nScrollFirst < nCount && m_scrollInfo.nScrollFirst >= 0);

		BOOL bFirst = TRUE;
		for (i = m_scrollInfo.nScrollFirst; i < nCount ; i++)
		{
			CXTPControl* pControl = GetControl(i);
			pControl->SetHideFlag(xtpHideScroll, FALSE);

			if (!pControl->IsVisible())
				continue;

			int nItemHeight = pControl->GetRect().Height();
			if (pControl->GetBeginGroup()) nPos += nSeparator;

			if (sz.cy - (nPos + nItemHeight) < nScrollHeight + rcBorders.bottom)
			{
				if (!bFirst)
					break;
				else
					nItemHeight = sz.cy - rcBorders.bottom - rcBorders.top;
			}

			bFirst = FALSE;
			pControl->SetRect(CRect(rcBorders.left, nPos, sz.cx - rcBorders.right, nPos + nItemHeight));

			nPos += nItemHeight;
		}
		for (int j = i; j < nCount; j++)
		{
			GetControl(j)->SetHideFlag(xtpHideScroll, TRUE);
		}

		m_scrollInfo.nScrollLast = i;

		if (i != nCount)
		{
			m_scrollInfo.btnUp.m_rc.SetRect(rcBorders.left, sz.cy - rcBorders.bottom - nScrollHeight, sz.cx - rcBorders.right, sz.cy - rcBorders.bottom);
		}
	}
	else
	{
		if (m_scrollInfo.nScrollLast == nCount - 1)
			m_scrollInfo.nScrollLast = nCount;

		int nPos = sz.cy - rcBorders.bottom;
		if (m_scrollInfo.nScrollLast != nCount)
		{
			nPos -= nScrollHeight;
			m_scrollInfo.btnUp.m_rc.SetRect(rcBorders.left, sz.cy - rcBorders.bottom - nScrollHeight, sz.cx - rcBorders.right, sz.cy - rcBorders.bottom);
		}

		ASSERT(m_scrollInfo.nScrollLast <= nCount && m_scrollInfo.nScrollLast > 0);

		for (i = m_scrollInfo.nScrollLast - 1 ; i >= 0 ; i--)
		{
			CXTPControl* pControl = GetControl(i);
			pControl->SetHideFlag(xtpHideScroll, FALSE);

			if (!pControl->IsVisible())
				continue;

			int nItemHeight = pControl->GetRect().Height();

			if (nPos - nItemHeight < nScrollHeight)
			{
				break;
			}
			pControl->SetRect(CRect(rcBorders.left, nPos - nItemHeight, sz.cx - rcBorders.right, nPos));

			nPos -= nItemHeight;
			if (pControl->GetBeginGroup()) nPos -= nSeparator;
		}

		for (int j = i; j >= 0; j--)
		{
			GetControl(j)->SetHideFlag(xtpHideScroll, TRUE);
		}

		m_scrollInfo.nScrollFirst = i + 1;

		if (i != -1)
		{
			m_scrollInfo.btnDown.m_rc.SetRect(rcBorders.left, rcBorders.top, sz.cx - rcBorders.right, rcBorders.top + nScrollHeight);
		}
	}
	if (m_bCollapsed)
	{
		pButtonExpand->SetHideFlags(xtpNoHide);
		pButtonExpand->SetRect(CRect(rcBorders.left, sz.cy - rcBorders.bottom, sz.cx - rcBorders.right, sz.cy - rcBorders.bottom +  szButtonExpand.cy));
	}
	m_rcTearOffGripper.SetRect(rcBorders.left, rcBorders.top - szTearOffGripper.cy, sz.cx - rcBorders.right, rcBorders.top);
	if (m_bResizable) m_rcResizeGripper.SetRect(rcBorders.left, sz.cy - rcBorders.bottom, sz.cx - rcBorders.right, sz.cy - rcBorders.bottom + m_rcResizeGripper.Height());

	if (bInvalidate) Redraw();
}

void CXTPCommandBar::UpdateShortcuts()
{
	CXTPCommandBars* pCommandBars = GetCommandBars();
	if (!pCommandBars)
		return;

	if (!pCommandBars->GetCommandBarsOptions()->bAutoUpdateShortcuts)
		return;

	for (int i = 0; i < GetControlCount(); i++)
	{
		CXTPControl* pControl = GetControl(i);
		if (!pControl || pControl->GetParent() != this || !pControl->IsVisible())
			continue;

		CString strShortcut;
		if (pControl->GetID() != 0)
		{
			pCommandBars->GetShortcutManager()->FindDefaultAccelerator(pControl->GetID(), strShortcut);
			pControl->m_strShortcutTextAuto = strShortcut;
		}
	}
}

void CXTPPopupBar::AdjustExcludeRect(CRect& rc, BOOL bVertical)
{
	m_pControlPopup->AdjustExcludeRect(rc, bVertical);
}

AFX_INLINE BOOL IsVerticalPosition(CXTPCommandBar* pCommandBar)
{
	return IsVerticalPosition(pCommandBar->GetPosition()) ||
		(pCommandBar->GetType() == xtpBarTypePopup && pCommandBar->GetPosition() == xtpBarFloating);
}

void CXTPPopupBar::UpdateFlags()
{
	if (m_pControlPopup)
	{
		BOOL bLayoutRTL = IsLayoutRTL();


		CXTPCommandBar* pParent = GetParentCommandBar();
		ASSERT(pParent);
		if (!pParent)
			return;

		m_popupFlags = xtpPopupRight;

		if (m_pControlPopup->m_dwFlags & xtpFlagLeftPopup || bLayoutRTL) m_popupFlags |= xtpPopupLeft;

		if (pParent->GetFlags() & xtpFlagSmartLayout && pParent->GetPosition() == xtpBarPopup)
		{
			m_popupFlags |= xtpPopupDown;
		}
		else if (!IsVerticalPosition(pParent))
		{
			m_popupFlags |= xtpPopupDown;
		}
		else
		{
			if (pParent->GetPosition() == xtpBarRight || (pParent->GetType() == xtpBarTypePopup &&
				pParent->IsPopupBar() && ((CXTPPopupBar*)pParent)->m_popupFlags & xtpPopupLeft))
				m_popupFlags = xtpPopupLeft;
		}

		m_rcExclude = m_pControlPopup->GetRect();

		if (m_pControlPopup->GetType() == xtpControlComboBox && pParent->GetType() != xtpBarTypePopup)
		{
			m_popupFlags |= xtpPopupDown;
		}
		else AdjustExcludeRect(m_rcExclude, IsVerticalPosition(pParent));

		pParent->ClientToScreen(m_rcExclude);

		m_ptPopup.x = (m_popupFlags & xtpPopupDown) ? m_rcExclude.left : m_rcExclude.right;
		m_ptPopup.y = (m_popupFlags & xtpPopupDown) ? m_rcExclude.bottom : m_rcExclude.top;
	}
}


void CXTPPopupBar::UpdateExpandingState()
{
	CXTPCommandBars* pCommandBars = GetCommandBars();
	if (!pCommandBars)
		return;

	int i;

	if (pCommandBars->GetCommandBarsOptions()->bAlwaysShowFullMenus)
	{
		for (i = 0; i < GetControlCount(); i++)
		{
			CXTPControl* pControl = GetControl(i);
			if (!pControl || pControl->GetParent() != this)
				continue;

			pControl->SetExpanded(FALSE);
		}
		m_bExpanded = TRUE;
		return;
	}

	m_bCollapsed = FALSE;

	BOOL bCollapsedExists = FALSE;
	for (i = 0; i < GetControlCount(); i++)
	{
		CXTPControl* pControl = GetControl(i);
		if (!pControl || pControl->GetParent() != this)
			continue;

		BOOL bVisible = pControl->IsVisible(xtpHideExpand | xtpHideScroll);

		if (pCommandBars->IsControlHidden(pControl))
		{
			pControl->SetExpanded(bVisible);
		}
		else
		{
			pControl->SetExpanded(FALSE);

			if (pControl->GetID() != XTP_ID_POPUPBAR_EXPAND && bVisible)
				bCollapsedExists = TRUE;
		}
	}

	for (i = 0; i < GetControlCount(); i++)
	{
		CXTPControl* pControl = GetControl(i);
		if (!pControl || pControl->GetParent() != this)
			continue;

		pControl->SetHideFlag(xtpHideExpand, FALSE);

		if (pControl->GetExpanded())
		{
			if (!m_bExpanded && bCollapsedExists)
			{
				pControl->SetHideFlag(xtpHideExpand, TRUE);
				m_bCollapsed = TRUE;
			}
		}
	}
}

void CXTPPopupBar::Animate()
{
	CXTPCommandBar* pParentCommandBar = GetParentCommandBar();

	BOOL bAnimate = pParentCommandBar ? pParentCommandBar->m_bAnimatePopup : TRUE;

	if (bAnimate)
	{
		if (IsCustomizeMode() || GetWindow(GW_CHILD))
			bAnimate = FALSE;
	}

	BOOL bRegionChanged = FALSE;


	if (bAnimate)
	{
		XTPAnimationType animationType = GetAnimationType();
		if (IsAnimateType(animationType))
		{

			if (m_pControlPopup)
			{
				m_pControlPopup->RedrawParent();
				m_pControlPopup->GetParent()->UpdateWindow();
			}

			GetSite()->UpdateWindow();

			CClientDC paintDC(this);
			CXTPClientRect rcClient(this);
			CXTPWindowRect rcWindow(this);

			CXTPBufferDC animationDC(paintDC, rcClient);
			DrawCommandBar(&animationDC, rcClient);

			CDC* pDC = GetDesktopWindow()->GetDC();

			BOOL dwLayout = CXTPDrawHelpers::IsContextRTL(&paintDC);
			CXTPDrawHelpers::SetContextRTL(&paintDC, FALSE);
			paintDC.BitBlt(0, 0, rcClient.Width(), rcClient.Height(), pDC, rcWindow.left, rcWindow.top, SRCCOPY);
			GetDesktopWindow()->ReleaseDC(pDC);
			CXTPDrawHelpers::SetContextRTL(&paintDC, dwLayout);

			GetPaintManager()->SetCommandBarRegion(this);
			bRegionChanged = TRUE;
			// Animation
			GetPaintManager()->Animate(&paintDC, &animationDC, rcClient, animationType);
		}
	}

	if (pParentCommandBar) pParentCommandBar->m_bAnimatePopup = FALSE;
	if (!bRegionChanged) GetPaintManager()->SetCommandBarRegion(this);

}



BOOL CXTPPopupBar::Popup(CXTPControlPopup* pControlPopup, BOOL bSelectFirst)
{
	m_pControlPopup = pControlPopup;

	if (!Create())
		return FALSE;

	if (m_pToolTipContext)
	{
		m_pToolTipContext->CancelToolTips();
	}

	LockRedraw();

	CWnd* pWndOwner = GetOwnerSite();
	if (pWndOwner) pWndOwner->SendMessage(WM_XTP_INITCOMMANDSPOPUP, 0, (LPARAM)this);

	m_bTearOffSelected = FALSE;

	m_bCollapsed = FALSE;
	m_bExpanded = IsCustomizeMode() || XTPMouseManager()->IsForceExpanded();

	UpdateFlags();

	UpdateLocation(CalcDynamicLayout(0, 0));

	if (!m_hWnd)
	{
		UnlockRedraw();
		return FALSE;
	}

	if (m_pControlPopup && m_pControlPopup->m_pParent->GetSafeHwnd() == NULL)
	{
		UnlockRedraw();
		DestroyWindow();
		return FALSE;
	}

	SetTrackingMode(TRUE, bSelectFirst, bSelectFirst);

	m_nIdleFlags &= ~xtpIdleLayout;
	OnIdleUpdateCmdUI(TRUE, 0L);

	if (!m_hWnd)
	{
		UnlockRedraw();
		return FALSE;
	}

	Animate();
	XTPSoundManager()->PlaySystemSound(xtpSoundMenuPopup);

	if (m_barPosition == xtpBarPopup && m_bShowShadow)
	{
		XTPShadowsManager()->RemoveShadow(this);
		XTPShadowsManager()->SetShadow(this, m_rcExclude);
	}

	m_nIdleFlags |= xtpIdleLayout;
	UnlockRedraw();

	return TRUE;
}

BOOL CXTPPopupBar::Popup(int x, int y, LPCRECT rcExclude)
{
	m_ptPopup = CPoint(x, y);
	if (rcExclude) m_rcExclude = *rcExclude;
	return Popup(NULL);
}

BEGIN_MESSAGE_MAP(CXTPPopupBar, CXTPCommandBar)
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEACTIVATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_SETCURSOR()
	ON_WM_TIMER()
	ON_WM_NCACTIVATE()
	ON_WM_NCCREATE()
	ON_MESSAGE(WM_FLOATSTATUS, OnFloatStatus)
END_MESSAGE_MAP()

void CXTPPopupBar::SwitchTearOffTracking(BOOL bShow, CPoint point)
{
	CXTPCommandBars* pCommandBars = GetCommandBars();
	ASSERT(pCommandBars);
	if (!pCommandBars)
		return;

	ShowWindow(bShow ? SW_SHOWNA : SW_HIDE);

	if (!bShow)
	{
		if (m_pTearOffBar == NULL)
		{
			m_pTearOffBar = pCommandBars->GetToolBar(m_nTearOffID);
			if (m_pTearOffBar != NULL)
			{
				m_pTearOffBar->SetPosition(xtpBarFloating);
				m_pTearOffBar->SetVisible(TRUE);
				pCommandBars->RecalcFrameLayout();
			}
		}
		if (m_pTearOffBar == NULL)
		{

			m_pTearOffBar = pCommandBars->AddCustomBar(m_strTearOffCaption, m_nTearOffID, TRUE);
			m_pTearOffBar->m_nMRUWidth = m_nTearOffWidth;

			for (int i = 0; i < GetControlCount(); i++)
			{
				CXTPControl* pControl = GetControl(i);
				if (!pControl || pControl->GetParent() != this)
					continue;

				if (pControl->GetID() != XTP_ID_POPUPBAR_EXPAND)
				{
					CXTPControl* pControlClone = m_pTearOffBar->GetControls()->AddClone(pControl);
					pControlClone->SetHideFlags(pControlClone->GetHideFlags() & ~(xtpHideScroll | xtpHideExpand));
				}
			}

		}
		ASSERT(m_pTearOffBar);

		pCommandBars->GetSite()->SendMessage(WM_XTP_TEAROFFDONE, (WPARAM)m_pTearOffBar, (LPARAM)this);

		m_szTearOffBar = m_pTearOffBar->CalcDynamicLayout(-1, LM_MRUWIDTH | LM_HORZ | LM_COMMIT);
		CPoint pt(point.x - m_szTearOffBar.cx / 2, point.y - 10);
		m_pTearOffBar->MoveWindow(pt.x, pt.y, m_szTearOffBar.cx, m_szTearOffBar.cy);
		m_pTearOffBar->OnInitialUpdate();
		m_pTearOffBar->Redraw();


	}
	else
	{
		if (m_pTearOffBar)
		{
			m_pTearOffBar->SetVisible(FALSE);
			m_pTearOffBar = 0;
		}

	}
}

void CXTPPopupBar::TrackResize()
{
	// don't handle if capture already set
	if (::GetCapture() != NULL)
		return;

	CXTPControl* pControl = GetControls()->FindControl(xtpControlGallery, -1, TRUE, FALSE);
	if (!pControl)
		return;
	CSize szControl(pControl->GetWidth(), pControl->GetRect().Height());
	CSize szControlInit = szControl;
	CSize szControlMin(pControl->GetCustomizeMinWidth(), pControl->GetCustomizeMinHeight());

	SetPopuped(-1);
	SetSelected(-1);

	BOOL bResizeWidth = m_bResizable & 1;
	BOOL bResizeHeight = m_bResizable & 2;

	// set capture to the window which received this message
	SetCapture();
	ASSERT(m_hWnd == ::GetCapture());

	CPoint pt(0, 0);
	GetCursorPos(&pt);

	// get messages until capture lost or cancelled/accepted
	while (::GetCapture() == m_hWnd)
	{
		MSG msg;

		while (::PeekMessage(&msg, NULL, WM_PAINT, WM_PAINT, PM_NOREMOVE))
		{
			if (!GetMessage(&msg, NULL, WM_PAINT, WM_PAINT))
				break;
			DispatchMessage(&msg);
		}

		if (!::GetMessage(&msg, NULL, 0, 0))
		{
			AfxPostQuitMessage((int)msg.wParam);
			break;
		}

		if (msg.message == WM_LBUTTONUP)
			break;
		else if (msg.message == WM_MOUSEMOVE && pt != msg.pt)
		{
			szControl += CPoint(msg.pt) - pt;

			if (bResizeWidth) pControl->SetWidth(max(szControl.cx, szControlMin.cx));
			if (bResizeHeight) pControl->SetHeight(max(szControl.cy, szControlMin.cy));
			RecalcSizeLayout();

			pt = msg.pt;
		}
		else if (msg.message == WM_KEYDOWN)
		{
			if (msg.wParam == VK_ESCAPE)
			{
				if (bResizeWidth) pControl->SetWidth(szControlInit.cx);
				if (bResizeHeight) pControl->SetHeight(szControlInit.cy);
				RecalcSizeLayout();
				break;
			}
		}
		else
			DispatchMessage(&msg);

	}

	ReleaseCapture();
}

void CXTPPopupBar::TrackTearOff()
{
	m_pTearOffBar = NULL;
	CRect rcGripper = m_rcTearOffGripper;
	ClientToScreen(&rcGripper);

	BOOL bShow = TRUE;
	// don't handle if capture already set
	if (::GetCapture() != NULL)
		return;

	// set capture to the window which received this message
	SetCapture();
	ASSERT(this == CWnd::GetCapture());

	CPoint pt(0, 0);
	// get messages until capture lost or cancelled/accepted
	while (CWnd::GetCapture() == this)
	{
		MSG msg;

		while (::PeekMessage(&msg, NULL, WM_PAINT, WM_PAINT, PM_NOREMOVE))
		{
			if (!GetMessage(&msg, NULL, WM_PAINT, WM_PAINT))
				break;
			DispatchMessage(&msg);
		}

		if (!::GetMessage(&msg, NULL, 0, 0))
		{
			AfxPostQuitMessage((int)msg.wParam);
			break;
		}

		if (msg.message == WM_LBUTTONUP)
			break;
		else if (msg.message == WM_MOUSEMOVE && pt != msg.pt)
		{
			pt = msg.pt;
			BOOL bState = !(pt.x > rcGripper.right + 10 || pt.x < rcGripper.left - 10 ||
				pt.y > rcGripper.bottom + 10 || pt.y < rcGripper.top - 10);
			if (bState != bShow)
			{
				bShow = bState;
				SwitchTearOffTracking(bState, pt);
			}

			if (m_pTearOffBar != NULL)
			{
				CPoint point(pt.x - m_szTearOffBar.cx / 2, pt.y - 10);
				m_pTearOffBar->MoveWindow(point.x, point.y, m_szTearOffBar.cx, m_szTearOffBar.cy);

			}

		}
		else if (msg.message == WM_KEYDOWN)
		{
			if (msg.wParam == VK_ESCAPE)
			{
				break;
			}
		}
		else
			DispatchMessage(&msg);

	}

	ReleaseCapture();
	if (m_pTearOffBar)
	{
		GetCommandBars()->ClosePopups();
	}
}

BOOL CXTPPopupBar::_MouseInResizeGripper(const POINT& pt)
{
	if (m_rcResizeGripper.PtInRect(pt))
	{
		if (m_bResizable == 2)
		{
			return TRUE;
		}

		CRect rcResizeGripper(m_rcResizeGripper);
		rcResizeGripper.left = rcResizeGripper.right - rcResizeGripper.Height();
		if (rcResizeGripper.PtInRect(pt))
		{
			return TRUE;
		}
	}
	return FALSE;
}

BOOL CXTPPopupBar::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	if (m_bResizable)
	{
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(&pt);

		if (_MouseInResizeGripper(pt))
		{
			SetCursor(AfxGetApp()->LoadStandardCursor(m_bResizable == 2 ? IDC_SIZENS : IDC_SIZENWSE));
			return TRUE;
		}
	}

	return CXTPCommandBar::OnSetCursor(pWnd, nHitTest, message);
}

void CXTPPopupBar::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (m_bTearOffPopup && m_rcTearOffGripper.PtInRect(point) && !IsCustomizeMode())
	{
		SetCursor(AfxGetApp()->LoadStandardCursor(IDC_SIZEALL));

		CXTPMouseManager* pMouseManager = XTPMouseManager();

		pMouseManager->LockMouseMove();
		m_bTearOffTracking = TRUE;
		TrackTearOff();
		m_bTearOffTracking = FALSE;
		pMouseManager->UnlockMouseMove();

		pMouseManager->RefreshCursor();
		return;
	}

	if (m_bResizable && _MouseInResizeGripper(point))
	{
		CXTPMouseManager* pMouseManager = XTPMouseManager();

		pMouseManager->LockMouseMove();
		TrackResize();
		pMouseManager->UnlockMouseMove();

		pMouseManager->RefreshCursor();
		return;
	}

	CXTPCommandBar::OnLButtonDown(nFlags, point);
}

BOOL CXTPPopupBar::DestroyWindow()
{
	if (!GetSafeHwnd())
		return CXTPCommandBar::DestroyWindow();

	CWnd* pWnd = GetWindow(GW_CHILD);
	if (!pWnd)
		return CXTPCommandBar::DestroyWindow();

	CWnd* pWndParent = GetSite();

	while (pWnd)
	{
		CWnd* pWndNext = pWnd->GetWindow(GW_HWNDNEXT);

		pWnd->ShowWindow(SW_HIDE);
		pWnd->SetParent(pWndParent);

		pWnd = pWndNext;
	}
	return CXTPCommandBar::DestroyWindow();
}

BOOL CXTPPopupBar::SetTrackingMode(int bMode, BOOL bSelectFirst, BOOL bKeyboard)
{
	if (!CXTPCommandBar::SetTrackingMode(bMode, bSelectFirst, bKeyboard))
		return FALSE;

	CWnd* pWnd = GetSite();

	if (!bMode)
	{
		AccessibleNotifyWinEvent(EVENT_SYSTEM_MENUPOPUPEND, m_hWnd, OBJID_MENU, 0);

		DestroyWindow();

		CXTPCommandBar* pParentCommandBar = GetParentCommandBar();
		if (pParentCommandBar)
			pParentCommandBar->SetPopuped(-1);

		if (pWnd && ::IsWindow(pWnd->m_hWnd)) pWnd->SendMessage(WM_XTP_UNINITCOMMANDSPOPUP, 0, (LPARAM)this);

		Sleep(1);

		m_pControlPopup = 0;

	}
	else
	{
		AccessibleNotifyWinEvent(EVENT_SYSTEM_MENUPOPUPSTART, m_hWnd, OBJID_MENU, 0);
	}
	if (pWnd && ::IsWindow(pWnd->m_hWnd)) pWnd->UpdateWindow();

	return TRUE;
}


void CXTPPopupBar::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_nLockRecurse > 0)
		return;

	if (GetParentCommandBar() != NULL && CXTPClientRect(this).PtInRect(point))
	{
		// restore selection
		GetParentCommandBar()->SetSelected(m_pControlPopup->GetIndex());
	}

	if (m_scrollInfo.bScroll)
	{
		if (m_scrollInfo.btnUp.OnMouseMove(point) ||
			m_scrollInfo.btnDown.OnMouseMove(point))
		{
			SetPopuped(-1);
		}
	}

	if (m_bTearOffPopup && !IsCustomizeMode() && m_rcTearOffGripper.PtInRect(point) && !m_bTearOffSelected)
	{
		SetSelected(-1);
		SetPopuped(-1);
		m_nTearOffTimer = SetTimer(TID_TEAROFFSELECTED, 80, NULL);
	}

	CXTPCommandBar::OnMouseMove(nFlags, point);
}

CXTPCommandBar* CXTPPopupBar::GetParentCommandBar() const
{
	return m_pControlPopup ? m_pControlPopup->GetParent() : NULL;
}

int CXTPPopupBar::OnMouseActivate(CWnd* /*pDesktopWnd*/, UINT /*nHitTest*/, UINT /*message*/)
{
	return MA_NOACTIVATE;
}

BOOL CXTPPopupBar::OnNcActivate(BOOL bActive)
{
	return bActive ? FALSE : CWnd::OnNcActivate(bActive);
}

BOOL CXTPPopupBar::OnNcCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (!CXTPCommandBar::OnNcCreate(lpCreateStruct))
		return FALSE;

	if (GetStyle() & MFS_SYNCACTIVE)
	{
		// syncronize activation state with top level parent
		CWnd* pParentWnd = GetTopLevelParent();
		ASSERT(pParentWnd != NULL);
		if (!pParentWnd)
			return FALSE;

		CWnd* pActiveWnd = GetForegroundWindow();
		BOOL bActive = (pParentWnd == pActiveWnd) ||
			(pParentWnd->GetLastActivePopup() == pActiveWnd &&
			pActiveWnd->SendMessage(WM_FLOATSTATUS, FS_SYNCACTIVE) != 0);

		// the WM_FLOATSTATUS does the actual work
		SendMessage(WM_FLOATSTATUS, bActive ? FS_ACTIVATE : FS_DEACTIVATE);
	}


	return TRUE;
}


LRESULT CXTPPopupBar::OnFloatStatus(WPARAM wParam, LPARAM)
{
	// FS_SYNCACTIVE is used to detect MFS_SYNCACTIVE windows
	LRESULT lResult = ((GetStyle() & MFS_SYNCACTIVE) && (wParam & FS_SYNCACTIVE));
	return lResult;
}



void CXTPPopupBar::DrawCommandBar(CDC* pDC, CRect rcClipBox)
{
	CXTPCommandBar::DrawCommandBar(pDC, rcClipBox);

	if (m_scrollInfo.bScroll)
	{
		if (!m_scrollInfo.btnUp.m_rc.IsRectEmpty())
		{
			CPoint pt = m_scrollInfo.btnUp.m_rc.CenterPoint();
			GetPaintManager()->Triangle(pDC, CPoint(pt.x - 3, pt.y), CPoint(pt.x + 3, pt.y), CPoint(pt.x, pt.y + 3), GetXtremeColor(COLOR_BTNTEXT));
		}
		if (!m_scrollInfo.btnDown.m_rc.IsRectEmpty())
		{
			CPoint pt = m_scrollInfo.btnDown.m_rc.CenterPoint();
			GetPaintManager()->Triangle(pDC, CPoint(pt.x - 3, pt.y), CPoint(pt.x + 3, pt.y), CPoint(pt.x, pt.y - 3), GetXtremeColor(COLOR_BTNTEXT));
		}
	}

	if (m_bTearOffPopup && GetControlCount() > 0)
	{
		GetPaintManager()->DrawTearOffGripper(pDC, m_rcTearOffGripper, m_bTearOffSelected, TRUE);
	}

	if (!m_rcResizeGripper.IsRectEmpty() && m_bResizable)
	{
		GetPaintManager()->DrawPopupResizeGripper(pDC, m_rcResizeGripper, m_bResizable);
	}
}


BOOL CXTPPopupBar::SetSelected(int nSelected, BOOL bKeyboard)
{
	if (!CXTPCommandBar::SetSelected(nSelected, bKeyboard))
		return FALSE;

	if (m_nSelected != -1 && !bKeyboard && (GetControl(m_nSelected)->GetID() == XTP_ID_POPUPBAR_EXPAND))
	{
		CXTPCommandBars* pCommandBars = GetCommandBars();
		ASSERT(pCommandBars);

		if (pCommandBars->GetCommandBarsOptions()->bShowFullAfterDelay)
		{
			SetTimer(TID_EXPANDHOVER, s_nExpandHoverDelay, NULL);
		}
	}
	else
	{
		KillTimer(TID_EXPANDHOVER);

	}

	if (m_scrollInfo.bScroll && m_nSelected != -1)
	{
		if (GetControl(m_nSelected)->GetHideFlags() & xtpHideScroll)
		{
			if (m_nSelected >= m_scrollInfo.nScrollLast)
			{
				m_scrollInfo.nScrollLast = m_nSelected + 1;
				AdjustScrolling(NULL, TRUE, TRUE);
			}
			else
			{
				m_scrollInfo.nScrollFirst = m_nSelected;
				AdjustScrolling(NULL, FALSE, TRUE);
			}
		}
	}

	return TRUE;
}

void CXTPPopupBar::OnTimer(UINT_PTR nIDEvent)
{
	int nCount = GetControlCount();

	switch (nIDEvent)
	{
		case TID_HOVERUP:
			if (m_scrollInfo.nScrollLast == nCount)
			{
				m_scrollInfo.btnUp.KillTimer();
				return;
			}
			m_scrollInfo.nScrollLast++;
			AdjustScrolling(NULL, TRUE, TRUE);

			break;

		case TID_HOVERDOWN:
			if (m_scrollInfo.nScrollFirst == 0)
			{
				m_scrollInfo.btnDown.KillTimer() ;
				return;
			}
			m_scrollInfo.nScrollFirst--;
			AdjustScrolling(NULL, FALSE, TRUE);
			break;

		case TID_TEAROFFSELECTED:
			{
				CPoint pt;
				GetCursorPos(&pt);
				ScreenToClient(&pt);
				if (!m_bTearOffSelected && m_rcTearOffGripper.PtInRect(pt))
				{
					m_bTearOffSelected = TRUE;
					Redraw();
				}
				if (m_bTearOffSelected && !m_rcTearOffGripper.PtInRect(pt) && !m_bTearOffTracking)
				{
					m_bTearOffSelected = FALSE;
					Redraw();
					KillTimer(m_nTearOffTimer);
				}
			}
			break;

		case TID_EXPANDHOVER:
			if (m_nSelected != -1 && GetControl(m_nSelected)->GetID() == XTP_ID_POPUPBAR_EXPAND)
			{
				GetControl(m_nSelected)->OnExecute();
			}

			KillTimer(TID_EXPANDHOVER);
			break;
	}

	CXTPCommandBar::OnTimer(nIDEvent);
}

BOOL CXTPPopupBar::OnHookKeyDown(UINT nChar, LPARAM lParam)
{
	if (m_bCollapsed)
	{
		if (nChar == VK_DOWN)
		{
			if (GetKeyState(VK_CONTROL) < 0 || m_pControls->GetNext(m_nSelected, +1) <= m_nSelected)
			{
				ExpandBar();
			}
		}
	}
	return CXTPCommandBar::OnHookKeyDown(nChar, lParam);
}

void CXTPPopupBar::SetDefaultItem(UINT uItem, BOOL fByPos)
{
	CXTPControl* pControl = fByPos ? m_pControls->GetAt(uItem) : m_pControls->FindControl(xtpControlError, uItem, TRUE, FALSE);
	if (pControl)
	{
		pControl->SetItemDefault(TRUE);
	}
}

UINT CXTPPopupBar::GetDefaultItem(UINT /*gmdiFlags*/, BOOL fByPos)
{
	for (int i = 0; i < GetControlCount(); i++)
	{
		CXTPControl* pControl = GetControl(i);
		if (!pControl || pControl->GetParent() != this || !pControl->IsVisible())
			continue;

		if (pControl->IsItemDefault())
		{
			return fByPos ? pControl->GetIndex() : pControl->GetID();
		}
	}
	return (UINT)-1;
}

void CXTPPopupBar::Copy(CXTPCommandBar* pCommandBar, BOOL bRecursive)
{
	ASSERT_KINDOF(CXTPPopupBar, pCommandBar);

	CXTPCommandBar::Copy(pCommandBar, bRecursive);

	m_bTearOffPopup = ((CXTPPopupBar*)pCommandBar)->m_bTearOffPopup;
	m_strTearOffCaption = ((CXTPPopupBar*)pCommandBar)->m_strTearOffCaption;
	m_nTearOffID = ((CXTPPopupBar*)pCommandBar)->m_nTearOffID;
	m_nTearOffWidth = ((CXTPPopupBar*)pCommandBar)->m_nTearOffWidth;

	m_bShowShadow = ((CXTPPopupBar*)pCommandBar)->m_bShowShadow;
	m_rcBorders = ((CXTPPopupBar*)pCommandBar)->m_rcBorders;
	m_bContextMenu = ((CXTPPopupBar*)pCommandBar)->m_bContextMenu;
}

void CXTPPopupBar::SetPopupToolBar(BOOL bToolBarType)
{
	m_barType = bToolBarType ? xtpBarTypeNormal : xtpBarTypePopup;
}

////////////////////////////////////////////////////////////////////////////
//

IMPLEMENT_XTP_COMMANDBAR(CXTPPopupToolBar, CXTPPopupBar)

CXTPPopupToolBar::CXTPPopupToolBar()
{
	m_barType = xtpBarTypeNormal;
}

CSize CXTPPopupToolBar::CalcDynamicLayout(int, DWORD /*nMode*/)
{
	return CXTPPopupBar::CalcDynamicLayout(0, 0);
}

CXTPPopupToolBar* CXTPPopupToolBar::CreatePopupToolBar(CXTPCommandBars* pCommandBars)
{
	CXTPPopupToolBar* pPopupBar = (CXTPPopupToolBar*)CXTPCommandBars::m_pPopupToolBarClass->CreateObject();
	pPopupBar->SetCommandBars(pCommandBars);
	return pPopupBar;
}


