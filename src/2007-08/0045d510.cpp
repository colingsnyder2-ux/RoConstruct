// from server: 100% by EspClaude
// from server: 58% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: scintilla-mfc-1.20 roc_claude_18fcf4ed39f53b9d.cpp

// Candidate translation unit (score above; library headers required).
#define _AFXDLL
#define _DLL
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
	__declspec(noinline) bool IsEmpty() const throw()
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

#include <afxstr.h>

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

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef __AFXWIN_H__
#ifndef RC_INVOKED
#define __AFXWIN_H__

/////////////////////////////////////////////////////////////////////////////
// Make sure 'afx.h' is included first

#ifndef __AFX_H__
	#include <afx.h>
#endif

// Note: WINDOWS.H already included from AFXV_W32.H
#ifndef NTDDI_LONGHORN
#define NTDDI_LONGHORN 0x06000000
#if (WINVER >= 0x0600) || (_WIN32_WINNT >= 0x0600)
#error Your version of the Windows SDK is earlier than 6.0. Try setting the 'WINVER' and '_WIN32_WINNT' definitions in your project to less than 0x0600.
#endif
#endif

#ifndef _INC_SHELLAPI
	#include <shellapi.h>
#endif

#ifndef __AFXRES_H__
	#include <afxres.h>     // standard resource IDs
#endif

#ifndef __AFXCOLL_H__
	#include <afxcoll.h>    // standard collections
#endif

#ifndef _OBJBASE_H_
	#include <objbase.h> //needed for commdlg.h (STDMETHOD)
#endif

#ifndef _INC_COMMDLG
	#include <commdlg.h>    // common dialog APIs
#endif

// Avoid mapping GetFileTitle to GetFileTitle[A/W]
#ifdef GetFileTitle
#undef GetFileTitle
AFX_INLINE short APIENTRY GetFileTitle(LPCTSTR lpszFile, LPTSTR lpszTitle, WORD cbBuf)
#ifdef UNICODE
	{ return ::GetFileTitleW(lpszFile, lpszTitle, cbBuf); }
#else
	{ return ::GetFileTitleA(lpszFile, lpszTitle, cbBuf); }
#endif
#endif

#ifndef _AFX_NO_AFXCMN_SUPPORT
#ifdef _AFX_PACKING
#pragma pack(push, _AFX_PACKING)
#endif
#include <afxcomctl32.h>
#ifdef _AFX_PACKING
#pragma pack(pop)
#endif
#endif

#if (_WIN32_WINNT >= 0x501)
#include <uxtheme.h>

#if ((NTDDI_VERSION >= NTDDI_LONGHORN || defined(__VSSYM32_H__)) && !defined(SCHEMA_VERIFY_VSSYM32))
#include <vssym32.h>
#else
#include <tmschema.h>
#endif
#endif	// (_WIN32_WINNT >= 0x501)

#if (_WIN32_WINNT >= 0x600)
#ifndef _WINSOCK2API_
#ifdef _WINSOCKAPI_
	#error MFC requires use of Winsock2.h
#endif
	#include <winsock2.h>
#endif

#ifndef _WS2IPDEF_
	#include <ws2ipdef.h>
#endif

#ifndef _WINDNS_INCLUDED_
	#include <windns.h>
#endif

#ifndef __IPHLPAPI_H__
	#include <iphlpapi.h>
#endif
#endif	// (_WIN32_WINNT >= 0x600)

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, off)
#endif

#ifndef _AFX_NOFORCE_LIBS
#pragma comment(lib, "uuid.lib")
#endif

#ifdef _INC_WINDOWSX
// The following names from WINDOWSX.H collide with names in this header
#undef SubclassWindow
#undef CopyRgn
#endif

#include <htmlhelp.h>

#ifdef _AFX_PACKING
#pragma pack(push, _AFX_PACKING)
#endif

#pragma warning( push )
#pragma warning( disable: 4121 )


/////////////////////////////////////////////////////////////////////////////
// Classes declared in this file

//CObject
	//CException
		//CSimpleException
			class CResourceException;// Win resource failure exception
			class CUserException;    // Message Box alert and stop operation

	class CGdiObject;            // CDC drawing tool
		class CPen;              // a pen / HPEN wrapper
		class CBrush;            // a brush / HBRUSH wrapper
		class CFont;             // a font / HFONT wrapper
		class CBitmap;           // a bitmap / HBITMAP wrapper
		class CPalette;          // a palette / HPALLETE wrapper
		class CRgn;              // a region / HRGN wrapper

	class CDC;                   // a Display Context / HDC wrapper
		class CClientDC;         // CDC for client of window
		class CWindowDC;         // CDC for entire window
		class CPaintDC;          // embeddable BeginPaint struct helper

	class CImageList;            // an image list / HIMAGELIST wrapper

	class CMenu;                 // a menu / HMENU wrapper

	class CCmdTarget;            // a target for user commands
		class CWnd;                 // a window / HWND wrapper
			class CDialog;          // a dialog

			// standard windows controls
			class CStatic;          // Static control
			class CButton;          // Button control
			class CListBox;         // ListBox control
				class CCheckListBox;// special listbox with checks
			class CComboBox;        // ComboBox control
			class CEdit;            // Edit control
			class CScrollBar;       // ScrollBar control

			// frame windows
			class CFrameWnd;        // standard SDI frame
				class CMDIFrameWnd; // standard MDI frame
				class CMDIChildWnd; // standard MDI child
				class CMiniFrameWnd;// half-height caption frame wnd

			// views on a document
			class CView;            // a view on a document
				class CScrollView;  // a scrolling view

		class CWinThread;           // thread base class
			class CWinApp;          // application base class

		class CDocTemplate;         // template for document creation
			class CSingleDocTemplate;// SDI support
			class CMultiDocTemplate; // MDI support

		class CDocument;            // main document abstraction


// Helper classes
class CCmdUI;           // Menu/button enabling
class CDataExchange;    // Data exchange and validation context
class CCommandLineInfo; // CommandLine parsing helper
class CDocManager;      // CDocTemplate manager object

struct COleControlSiteOrWnd; // ActiveX dialog control helper


class CControlCreationInfo; //Used in CWnd::CreateControl overloads.

class CVariantBoolConverter;

/////////////////////////////////////////////////////////////////////////////

enum AFX_HELP_TYPE
{
	afxWinHelp = 0,
	afxHTMLHelp = 1
};

// Type modifier for message handlers
#ifndef afx_msg
#define afx_msg         // intentional placeholder
#endif

#undef AFX_DATA
#define AFX_DATA AFX_CORE_DATA


#ifndef __ATLTYPES_H__
#include <atltypes.h>
#endif

#ifdef _DEBUG
// Diagnostic Output
CDumpContext& AFXAPI operator<<(CDumpContext& dc, SIZE size);
CDumpContext& AFXAPI operator<<(CDumpContext& dc, POINT point);
CDumpContext& AFXAPI operator<<(CDumpContext& dc, const RECT& rect);
#endif //_DEBUG

// Serialization
CArchive& AFXAPI operator<<(CArchive& ar, SIZE size);
CArchive& AFXAPI operator<<(CArchive& ar, POINT point);
CArchive& AFXAPI operator<<(CArchive& ar, const RECT& rect);
CArchive& AFXAPI operator>>(CArchive& ar, SIZE& size);
CArchive& AFXAPI operator>>(CArchive& ar, POINT& point);
CArchive& AFXAPI operator>>(CArchive& ar, RECT& rect);

/////////////////////////////////////////////////////////////////////////////
// Standard exceptions

class CResourceException : public CSimpleException    // resource failure
{
	DECLARE_DYNAMIC(CResourceException)
public:
	CResourceException();

// Implementation
public:
	explicit CResourceException(BOOL bAutoDelete);
	CResourceException(BOOL bAutoDelete, UINT nResourceID);
	virtual ~CResourceException();
};

class CUserException : public CSimpleException   // general user visible alert
{
	DECLARE_DYNAMIC(CUserException)
public:
	CUserException();

// Implementation
public:
	explicit CUserException(BOOL bAutoDelete);
	CUserException(BOOL bAutoDelete, UINT nResourceID);
	virtual ~CUserException();
};

void AFXAPI AfxThrowResourceException();
void AFXAPI AfxThrowUserException();

void AFXAPI AfxGetGrayBitmap(const CBitmap &rSrc, CBitmap *pDest, COLORREF crBackground);
void AFXAPI AfxDrawGrayBitmap(CDC *pDC, int x, int y, const CBitmap &rSrc, COLORREF crBackground);
void AFXAPI AfxGetDitheredBitmap(const CBitmap &rSrc, CBitmap *pDest, COLORREF cr1, COLORREF cr2);
void AFXAPI AfxDrawDitheredBitmap(CDC *pDC, int x, int y, const CBitmap &rSrc, COLORREF cr1, COLORREF cr2);

/////////////////////////////////////////////////////////////////////////////
// CGdiObject abstract class for CDC SelectObject

class CGdiObject : public CObject
{
	DECLARE_DYNCREATE(CGdiObject)
public:

// Attributes
	HGDIOBJ m_hObject;                  // must be first data member
	operator HGDIOBJ() const;
	HGDIOBJ GetSafeHandle() const;

	static CGdiObject* PASCAL FromHandle(HGDIOBJ hObject);
	static void PASCAL DeleteTempMap();
	BOOL Attach(HGDIOBJ hObject);
	HGDIOBJ Detach();

// Constructors
	CGdiObject(); // must Create a derived class object
	BOOL DeleteObject();

// Operations
#pragma push_macro("GetObject")
#undef GetObject
	int _AFX_FUNCNAME(GetObject)(int nCount, LPVOID lpObject) const;
	int GetObject(int nCount, LPVOID lpObject) const;
#pragma pop_macro("GetObject")
	UINT GetObjectType() const;
	BOOL CreateStockObject(int nIndex);
	BOOL UnrealizeObject();
	BOOL operator==(const CGdiObject& obj) const;
	BOOL operator!=(const CGdiObject& obj) const;

// Implementation
public:
	virtual ~CGdiObject();
#ifdef _DEBUG
	virtual void Dump(CDumpContext& dc) const;
	virtual void AssertValid() const;
#endif
};

/////////////////////////////////////////////////////////////////////////////
// CGdiObject subclasses (drawing tools)

class CPen : public CGdiObject
{
	DECLARE_DYNAMIC(CPen)

public:
	static CPen* PASCAL FromHandle(HPEN hPen);

// Constructors
	CPen();
	CPen(int nPenStyle, int nWidth, COLORREF crColor);
	CPen(int nPenStyle, int nWidth, const LOGBRUSH* pLogBrush,
		int nStyleCount = 0, const DWORD* lpStyle = NULL);
	BOOL CreatePen(int nPenStyle, int nWidth, COLORREF crColor);
	BOOL CreatePen(int nPenStyle, int nWidth, const LOGBRUSH* pLogBrush,
		int nStyleCount = 0, const DWORD* lpStyle = NULL);
	BOOL CreatePenIndirect(LPLOGPEN lpLogPen);

// Attributes
	operator HPEN() const;
	int GetLogPen(LOGPEN* pLogPen);
	int GetExtLogPen(EXTLOGPEN* pLogPen);

// Implementation
public:
	virtual ~CPen();
#ifdef _DEBUG
	virtual void Dump(CDumpContext& dc) const;
#endif
};

class CBrush : public CGdiObject
{
	DECLARE_DYNAMIC(CBrush)

public:
	static CBrush* PASCAL FromHandle(HBRUSH hBrush);

// Constructors
	CBrush();
	CBrush(COLORREF crColor);             // CreateSolidBrush
	CBrush(int nIndex, COLORREF crColor); // CreateHatchBrush
	explicit CBrush(CBitmap* pBitmap);          // CreatePatternBrush

	BOOL CreateSolidBrush(COLORREF crColor);
	BOOL CreateHatchBrush(int nIndex, COLORREF crColor);
	BOOL CreateBrushIndirect(const LOGBRUSH* lpLogBrush);
	BOOL CreatePatternBrush(CBitmap* pBitmap);
	BOOL CreateDIBPatternBrush(HGLOBAL hPackedDIB, UINT nUsage);
	BOOL CreateDIBPatternBrush(const void* lpPackedDIB, UINT nUsage);
	BOOL CreateSysColorBrush(int nIndex);

// Attributes
	operator HBRUSH() const;
	int GetLogBrush(LOGBRUSH* pLogBrush);

// Implementation
public:
	virtual ~CBrush();
#ifdef _DEBUG
	virtual void Dump(CDumpContext& dc) const;
#endif
};

class CFont : public CGdiObject
{
	DECLARE_DYNAMIC(CFont)

public:
	static CFont* PASCAL FromHandle(HFONT hFont);

// Constructors
	CFont();
	BOOL CreateFontIndirect(const LOGFONT* lpLogFont);
	BOOL CreateFont(int nHeight, int nWidth, int nEscapement,
			int nOrientation, int nWeight, BYTE bItalic, BYTE bUnderline,
			BYTE cStrikeOut, BYTE nCharSet, BYTE nOutPrecision,
			BYTE nClipPrecision, BYTE nQuality, BYTE nPitchAndFamily,
			LPCTSTR lpszFacename);
	BOOL CreatePointFont(int nPointSize, LPCTSTR lpszFaceName, CDC* pDC = NULL);
	BOOL CreatePointFontIndirect(const LOGFONT* lpLogFont, CDC* pDC = NULL);

// Attributes
	operator HFONT() const;
	int GetLogFont(LOGFONT* pLogFont);

// Implementation
public:
	virtual ~CFont();
#ifdef _DEBUG
	virtual void Dump(CDumpContext& dc) const;
#endif
};

class CBitmap : public CGdiObject
{
	DECLARE_DYNAMIC(CBitmap)

public:
	static CBitmap* PASCAL FromHandle(HBITMAP hBitmap);

// Constructors
	CBitmap();

	BOOL LoadBitmap(LPCTSTR lpszResourceName);
	BOOL LoadBitmap(UINT nIDResource);
	BOOL LoadOEMBitmap(UINT nIDBitmap); // for OBM_/OCR_/OIC_
#ifndef _AFX_NO_AFXCMN_SUPPORT
	BOOL LoadMappedBitmap(UINT nIDBitmap, UINT nFlags = 0,
		LPCOLORMAP lpColorMap = NULL, int nMapSize = 0);
#endif
	BOOL CreateBitmap(int nWidth, int nHeight, UINT nPlanes, UINT nBitcount,
			const void* lpBits);
	BOOL CreateBitmapIndirect(LPBITMAP lpBitmap);
	BOOL CreateCompatibleBitmap(CDC* pDC, int nWidth, int nHeight);
	BOOL CreateDiscardableBitmap(CDC* pDC, int nWidth, int nHeight);

// Attributes
	operator HBITMAP() const;
	int GetBitmap(BITMAP* pBitMap);

// Operations
	DWORD SetBitmapBits(DWORD dwCount, const void* lpBits);
	DWORD GetBitmapBits(DWORD dwCount, LPVOID lpBits) const;
	CSize SetBitmapDimension(int nWidth, int nHeight);
	CSize GetBitmapDimension() const;

// Implementation
public:
	virtual ~CBitmap();
#ifdef _DEBUG
	virtual void Dump(CDumpContext& dc) const;
#endif
};

class CPalette : public CGdiObject
{
	DECLARE_DYNAMIC(CPalette)

public:
	static CPalette* PASCAL FromHandle(HPALETTE hPalette);

// Constructors
	CPalette();
	BOOL CreatePalette(LPLOGPALETTE lpLogPalette);
	BOOL CreateHalftonePalette(CDC* pDC);

// Attributes
	operator HPALETTE() const;
	int GetEntryCount();
	UINT GetPaletteEntries(UINT nStartIndex, UINT nNumEntries,
			LPPALETTEENTRY lpPaletteColors) const;
	UINT SetPaletteEntries(UINT nStartIndex, UINT nNumEntries,
			LPPALETTEENTRY lpPaletteColors);

// Operations
	void AnimatePalette(UINT nStartIndex, UINT nNumEntries,
			LPPALETTEENTRY lpPaletteColors);
	UINT GetNearestPaletteIndex(COLORREF crColor) const;
	BOOL ResizePalette(UINT nNumEntries);

// Implementation
	virtual ~CPalette();
};

class CRgn : public CGdiObject
{
	DECLARE_DYNAMIC(CRgn)

public:
	static CRgn* PASCAL FromHandle(HRGN hRgn);
	operator HRGN() const;

// Constructors
	CRgn();
	BOOL CreateRectRgn(int x1, int y1, int x2, int y2);
	BOOL CreateRectRgnIndirect(LPCRECT lpRect);
	BOOL CreateEllipticRgn(int x1, int y1, int x2, int y2);
	BOOL CreateEllipticRgnIndirect(LPCRECT lpRect);
	BOOL CreatePolygonRgn(LPPOINT lpPoints, int nCount, int nMode);
	BOOL CreatePolyPolygonRgn(LPPOINT lpPoints, LPINT lpPolyCounts,
			int nCount, int nPolyFillMode);
	BOOL CreateRoundRectRgn(int x1, int y1, int x2, int y2, int x3, int y3);
	BOOL CreateFromPath(CDC* pDC);
	BOOL CreateFromData(const XFORM* lpXForm, int nCount,
		const RGNDATA* pRgnData);

// Operations
	void SetRectRgn(int x1, int y1, int x2, int y2);
	void SetRectRgn(LPCRECT lpRect);
	int CombineRgn(const CRgn* pRgn1, const CRgn* pRgn2, int nCombineMode);
	int CopyRgn(const CRgn* pRgnSrc);
	BOOL EqualRgn(const CRgn* pRgn) const;
	int OffsetRgn(int x, int y);
	int OffsetRgn(POINT point);
	int GetRgnBox(LPRECT lpRect) const;
	BOOL PtInRegion(int x, int y) const;
	BOOL PtInRegion(POINT point) const;
	BOOL RectInRegion(LPCRECT lpRect) const;
	int GetRegionData(LPRGNDATA lpRgnData, int nCount) const;

// Implementation
	virtual ~CRgn();
};

/////////////////////////////////////////////////////////////////////////////
// The device context

class CDC : public CObject
{
	DECLARE_DYNCREATE(CDC)
public:

// Attributes
	HDC m_hDC;          // The output DC (must be first data member)
	HDC m_hAttribDC;    // The Attribute DC
	operator HDC() const;
	HDC GetSafeHdc() const; // Always returns the Output DC
	CWnd* GetWindow() const;

	static CDC* PASCAL FromHandle(HDC hDC);
	static void PASCAL DeleteTempMap();
	BOOL Attach(HDC hDC);   // Attach/Detach affects only the Output DC
	HDC Detach();

	virtual void SetAttribDC(HDC hDC);  // Set the Attribute DC
	virtual void SetOutputDC(HDC hDC);  // Set the Output DC
	virtual void ReleaseAttribDC();     // Release the Attribute DC
	virtual void ReleaseOutputDC();     // Release the Output DC

	BOOL IsPrinting() const;            // TRUE if being used for printing

	CPen* GetCurrentPen() const;
	CBrush* GetCurrentBrush() const;
	CPalette* GetCurrentPalette() const;
	CFont* GetCurrentFont() const;
	CBitmap* GetCurrentBitmap() const;

	// for bidi and mirrored localization
	DWORD GetLayout() const;
	DWORD SetLayout(DWORD dwLayout);

// Constructors
	CDC();
	BOOL CreateDC(LPCTSTR lpszDriverName, LPCTSTR lpszDeviceName,
		LPCTSTR lpszOutput, const void* lpInitData);
	BOOL CreateIC(LPCTSTR lpszDriverName, LPCTSTR lpszDeviceName,
		LPCTSTR lpszOutput, const void* lpInitData);
	BOOL CreateCompatibleDC(CDC* pDC);

	BOOL DeleteDC();

// Device-Context Functions
	virtual int SaveDC();
	virtual BOOL RestoreDC(int nSavedDC);
	int GetDeviceCaps(int nIndex) const;
	UINT SetBoundsRect(LPCRECT lpRectBounds, UINT flags);
	UINT GetBoundsRect(LPRECT lpRectBounds, UINT flags);
	BOOL ResetDC(const DEVMODE* lpDevMode);

// Drawing-Tool Functions
	CPoint GetBrushOrg() const;
	CPoint SetBrushOrg(int x, int y);
	CPoint SetBrushOrg(POINT point);
	int EnumObjects(int nObjectType,
			int (CALLBACK* lpfn)(LPVOID, LPARAM), LPARAM lpData);

// Type-safe selection helpers
public:
	virtual CGdiObject* SelectStockObject(int nIndex);
	CPen* SelectObject(CPen* pPen);
	CBrush* SelectObject(CBrush* pBrush);
	virtual CFont* SelectObject(CFont* pFont);
	CBitmap* SelectObject(CBitmap* pBitmap);
	int SelectObject(CRgn* pRgn);       // special return for regions
	CGdiObject* SelectObject(CGdiObject* pObject);
		// CGdiObject* provided so compiler doesn't use SelectObject(HGDIOBJ)

// Color and Color Palette Functions
	COLORREF GetNearestColor(COLORREF crColor) const;
	CPalette* SelectPalette(CPalette* pPalette, BOOL bForceBackground);
	UINT RealizePalette();
	void UpdateColors();

// Drawing-Attribute Functions
	COLORREF GetBkColor() const;
	int GetBkMode() const;
	int GetPolyFillMode() const;
	int GetROP2() const;
	int GetStretchBltMode() const;
	COLORREF GetTextColor() const;

	virtual COLORREF SetBkColor(COLORREF crColor);
	int SetBkMode(int nBkMode);
	int SetPolyFillMode(int nPolyFillMode);
	int SetROP2(int nDrawMode);
	int SetStretchBltMode(int nStretchMode);
	virtual COLORREF SetTextColor(COLORREF crColor);

	BOOL GetColorAdjustment(LPCOLORADJUSTMENT lpColorAdjust) const;
	BOOL SetColorAdjustment(const COLORADJUSTMENT* lpColorAdjust);

#if (_WIN32_WINNT >= 0x0500)

	COLORREF GetDCBrushColor() const;
	COLORREF SetDCBrushColor(COLORREF crColor);

	COLORREF GetDCPenColor() const;
	COLORREF SetDCPenColor(COLORREF crColor);

#endif

	// Graphics mode
	int SetGraphicsMode(int iMode);
	int GetGraphicsMode() const;

	// World transform
	BOOL SetWorldTransform(const XFORM* pXform);
	BOOL ModifyWorldTransform(const XFORM* pXform,DWORD iMode);
	BOOL GetWorldTransform(XFORM* pXform) const;

	// Mapping Functions
	int GetMapMode() const;
	CPoint GetViewportOrg() const;
	virtual int SetMapMode(int nMapMode);
	// Viewport Origin
	virtual CPoint SetViewportOrg(int x, int y);
			CPoint SetViewportOrg(POINT point);
	virtual CPoint OffsetViewportOrg(int nWidth, int nHeight);

	// Viewport Extent
	CSize GetViewportExt() const;
	virtual CSize SetViewportExt(int cx, int cy);
			CSize SetViewportExt(SIZE size);
	virtual CSize ScaleViewportExt(int xNum, int xDenom, int yNum, int yDenom);

	// Window Origin
	CPoint GetWindowOrg() const;
	CPoint SetWindowOrg(int x, int y);
	CPoint SetWindowOrg(POINT point);
	CPoint OffsetWindowOrg(int nWidth, int nHeight);

	// Window extent
	CSize GetWindowExt() const;
	virtual CSize SetWindowExt(int cx, int cy);
			CSize SetWindowExt(SIZE size);
	virtual CSize ScaleWindowExt(int xNum, int xDenom, int yNum, int yDenom);

// Coordinate Functions
	void DPtoLP(LPPOINT lpPoints, int nCount = 1) const;
	void DPtoLP(LPRECT lpRect) const;
	void DPtoLP(LPSIZE lpSize) const;
	void LPtoDP(LPPOINT lpPoints, int nCount = 1) const;
	void LPtoDP(LPRECT lpRect) const;
	void LPtoDP(LPSIZE lpSize) const;

// Special Coordinate Functions (useful for dealing with metafiles and OLE)
	void DPtoHIMETRIC(LPSIZE lpSize) const;
	void LPtoHIMETRIC(LPSIZE lpSize) const;
	void HIMETRICtoDP(LPSIZE lpSize) const;
	void HIMETRICtoLP(LPSIZE lpSize) const;

// Region Functions
	BOOL FillRgn(CRgn* pRgn, CBrush* pBrush);
	BOOL FrameRgn(CRgn* pRgn, CBrush* pBrush, int nWidth, int nHeight);
	BOOL InvertRgn(CRgn* pRgn);
	BOOL PaintRgn(CRgn* pRgn);

// Clipping Functions
	virtual int GetClipBox(LPRECT lpRect) const;
	virtual BOOL PtVisible(int x, int y) const;
			BOOL PtVisible(POINT point) const;
	virtual BOOL RectVisible(LPCRECT lpRect) const;
			int SelectClipRgn(CRgn* pRgn);
			int ExcludeClipRect(int x1, int y1, int x2, int y2);
			int ExcludeClipRect(LPCRECT lpRect);
			int ExcludeUpdateRgn(CWnd* pWnd);
			int IntersectClipRect(int x1, int y1, int x2, int y2);
			int IntersectClipRect(LPCRECT lpRect);
			int OffsetClipRgn(int x, int y);
			int OffsetClipRgn(SIZE size);
	int SelectClipRgn(CRgn* pRgn, int nMode);

// Line-Output Functions
	CPoint GetCurrentPosition() const;
	CPoint MoveTo(int x, int y);
	CPoint MoveTo(POINT point);
	BOOL LineTo(int x, int y);
	BOOL LineTo(POINT point);
	BOOL Arc(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	BOOL Arc(LPCRECT lpRect, POINT ptStart, POINT ptEnd);
	BOOL Polyline(const POINT* lpPoints, int nCount);

	BOOL AngleArc(int x, int y, int nRadius, float fStartAngle, float fSweepAngle);
	BOOL ArcTo(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	BOOL ArcTo(LPCRECT lpRect, POINT ptStart, POINT ptEnd);
	int GetArcDirection() const;
	int SetArcDirection(int nArcDirection);

	BOOL PolyDraw(const POINT* lpPoints, const BYTE* lpTypes, int nCount);
	BOOL PolylineTo(const POINT* lpPoints, int nCount);
	BOOL PolyPolyline(const POINT* lpPoints,
		const DWORD* lpPolyPoints, int nCount);

	BOOL PolyBezier(const POINT* lpPoints, int nCount);
	BOOL PolyBezierTo(const POINT* lpPoints, int nCount);

// Simple Drawing Functions
	void FillRect(LPCRECT lpRect, CBrush* pBrush);
	void FrameRect(LPCRECT lpRect, CBrush* pBrush);
	void InvertRect(LPCRECT lpRect);
	BOOL DrawIcon(int x, int y, HICON hIcon);
	BOOL DrawIcon(POINT point, HICON hIcon);
	BOOL DrawState(CPoint pt, CSize size, HBITMAP hBitmap, UINT nFlags,
		HBRUSH hBrush = NULL);
	BOOL DrawState(CPoint pt, CSize size, CBitmap* pBitmap, UINT nFlags,
		CBrush* pBrush = NULL);
	BOOL DrawState(CPoint pt, CSize size, HICON hIcon, UINT nFlags,
		HBRUSH hBrush = NULL);
	BOOL DrawState(CPoint pt, CSize size, HICON hIcon, UINT nFlags,
		CBrush* pBrush = NULL);
	BOOL DrawState(CPoint pt, CSize size, LPCTSTR lpszText, UINT nFlags,
		BOOL bPrefixText = TRUE, int nTextLen = 0, HBRUSH hBrush = NULL);
	BOOL DrawState(CPoint pt, CSize size, LPCTSTR lpszText, UINT nFlags,
		BOOL bPrefixText = TRUE, int nTextLen = 0, CBrush* pBrush = NULL);
	BOOL DrawState(CPoint pt, CSize size, DRAWSTATEPROC lpDrawProc,
		LPARAM lData, UINT nFlags, HBRUSH hBrush = NULL);
	BOOL DrawState(CPoint pt, CSize size, DRAWSTATEPROC lpDrawProc,
		LPARAM lData, UINT nFlags, CBrush* pBrush = NULL);

// Ellipse and Polygon Functions
	BOOL Chord(int x1, int y1, int x2, int y2, int x3, int y3,
		int x4, int y4);
	BOOL Chord(LPCRECT lpRect, POINT ptStart, POINT ptEnd);
	void DrawFocusRect(LPCRECT lpRect);
	BOOL Ellipse(int x1, int y1, int x2, int y2);
	BOOL Ellipse(LPCRECT lpRect);
	BOOL Pie(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	BOOL Pie(LPCRECT lpRect, POINT ptStart, POINT ptEnd);
	BOOL Polygon(const POINT* lpPoints, int nCount);	
	BOOL PolyPolygon(const POINT* lpPoints, const INT* lpPolyCounts, int nCount);
	BOOL Rectangle(int x1, int y1, int x2, int y2);
	BOOL Rectangle(LPCRECT lpRect);
	BOOL RoundRect(int x1, int y1, int x2, int y2, int x3, int y3);
	BOOL RoundRect(LPCRECT lpRect, POINT point);

// Bitmap Functions
	BOOL PatBlt(int x, int y, int nWidth, int nHeight, DWORD dwRop);
	BOOL BitBlt(int x, int y, int nWidth, int nHeight, CDC* pSrcDC,
		int xSrc, int ySrc, DWORD dwRop);
	BOOL StretchBlt(int x, int y, int nWidth, int nHeight, CDC* pSrcDC,
		int xSrc, int ySrc, int nSrcWidth, int nSrcHeight, DWORD dwRop);
	COLORREF GetPixel(int x, int y) const;
	COLORREF GetPixel(POINT point) const;
	COLORREF SetPixel(int x, int y, COLORREF crColor);
	COLORREF SetPixel(POINT point, COLORREF crColor);
	BOOL FloodFill(int x, int y, COLORREF crColor);
	BOOL ExtFloodFill(int x, int y, COLORREF crColor, UINT nFillType);
	BOOL MaskBlt(int x, int y, int nWidth, int nHeight, CDC* pSrcDC,
		int xSrc, int ySrc, CBitmap& maskBitmap, int xMask, int yMask,
		DWORD dwRop);
	BOOL PlgBlt(LPPOINT lpPoint, CDC* pSrcDC, int xSrc, int ySrc,
		int nWidth, int nHeight, CBitmap& maskBitmap, int xMask, int yMask);
	BOOL SetPixelV(int x, int y, COLORREF crColor);
	BOOL SetPixelV(POINT point, COLORREF crColor);
   BOOL GradientFill(TRIVERTEX* pVertices, ULONG nVertices, 
	  void* pMesh, ULONG nMeshElements, DWORD dwMode);
   BOOL TransparentBlt(int xDest, int yDest, int nDestWidth, int nDestHeight,
	  CDC* pSrcDC, int xSrc, int ySrc, int nSrcWidth, int nSrcHeight, 
	  UINT clrTransparent);
   BOOL AlphaBlend(int xDest, int yDest, int nDestWidth, int nDestHeight,
	  CDC* pSrcDC, int xSrc, int ySrc, int nSrcWidth, int nSrcHeight, 
	  BLENDFUNCTION blend);

// Text Functions
	virtual BOOL TextOut(int x, int y, LPCTSTR lpszString, int nCount);
			BOOL TextOut(int x, int y, const CString& str);
	virtual BOOL ExtTextOut(int x, int y, UINT nOptions, LPCRECT lpRect,
				LPCTSTR lpszString, UINT nCount, LPINT lpDxWidths);
			BOOL ExtTextOut(int x, int y, UINT nOptions, LPCRECT lpRect,
				const CString& str, LPINT lpDxWidths);
	virtual CSize TabbedTextOut(int x, int y, LPCTSTR lpszString, int nCount,
				int nTabPositions, LPINT lpnTabStopPositions, int nTabOrigin);
			CSize TabbedTextOut(int x, int y, const CString& str,
				int nTabPositions, LPINT lpnTabStopPositions, int nTabOrigin);

#pragma push_macro("DrawText")
#pragma push_macro("DrawTextEx")
#undef DrawText
#undef DrawTextEx
	virtual int _AFX_FUNCNAME(DrawText)(LPCTSTR lpszString, int nCount, LPRECT lpRect,
				UINT nFormat);
			int _AFX_FUNCNAME(DrawText)(const CString& str, LPRECT lpRect, UINT nFormat);

	virtual int _AFX_FUNCNAME(DrawTextEx)(LPTSTR lpszString, int nCount, LPRECT lpRect,
				UINT nFormat, LPDRAWTEXTPARAMS lpDTParams);
			int _AFX_FUNCNAME(DrawTextEx)(const CString& str, LPRECT lpRect, UINT nFormat, LPDRAWTEXTPARAMS lpDTParams);

			int DrawText(LPCTSTR lpszString, int nCount, LPRECT lpRect,
				UINT nFormat);
			int DrawText(const CString& str, LPRECT lpRect, UINT nFormat);

			int DrawTextEx(LPTSTR lpszString, int nCount, LPRECT lpRect,
				UINT nFormat, LPDRAWTEXTPARAMS lpDTParams);
			int DrawTextEx(const CString& str, LPRECT lpRect, UINT nFormat, LPDRAWTEXTPARAMS lpDTParams);
#pragma pop_macro("DrawText")
#pragma pop_macro("DrawTextEx")

	CSize GetTextExtent(LPCTSTR lpszString, int nCount) const;
	CSize GetTextExtent(const CString& str) const;
	CSize GetOutputTextExtent(LPCTSTR lpszString, int nCount) const;
	CSize GetOutputTextExtent(const CString& str) const;
	CSize GetTabbedTextExtent(LPCTSTR lpszString, int nCount,
		int nTabPositions, LPINT lpnTabStopPositions) const;
	CSize GetTabbedTextExtent(const CString& str,
		int nTabPositions, LPINT lpnTabStopPositions) const;
	CSize GetOutputTabbedTextExtent(LPCTSTR lpszString, int nCount,
		int nTabPositions, LPINT lpnTabStopPositions) const;
	CSize GetOutputTabbedTextExtent(const CString& str,
		int nTabPositions, LPINT lpnTabStopPositions) const;
	virtual BOOL GrayString(CBrush* pBrush,
		BOOL (CALLBACK* lpfnOutput)(HDC, LPARAM, int), LPARAM lpData,
			int nCount, int x, int y, int nWidth, int nHeight);
	UINT GetTextAlign() const;
	UINT SetTextAlign(UINT nFlags);
	int GetTextFace(_In_ int nCount, _Out_z_cap_post_count_(nCount, return) LPTSTR lpszFacename) const;
	int GetTextFace(CString& rString) const;
#pragma push_macro("GetTextMetrics")
#undef GetTextMetrics
	BOOL _AFX_FUNCNAME(GetTextMetrics)(LPTEXTMETRIC lpMetrics) const;
	BOOL GetTextMetrics(LPTEXTMETRIC lpMetrics) const;
#pragma pop_macro("GetTextMetrics")
	BOOL GetOutputTextMetrics(LPTEXTMETRIC lpMetrics) const;
	int SetTextJustification(int nBreakExtra, int nBreakCount);
	int GetTextCharacterExtra() const;
	int SetTextCharacterExtra(int nCharExtra);

	DWORD GetCharacterPlacement(LPCTSTR lpString, int nCount, int nMaxExtent, LPGCP_RESULTS lpResults, DWORD dwFlags) const;
	DWORD GetCharacterPlacement(CString& str, int nMaxExtent, LPGCP_RESULTS lpResults, DWORD dwFlags) const;

#if (_WIN32_WINNT >= 0x0500)

	BOOL GetTextExtentExPointI(LPWORD pgiIn, int cgi, int nMaxExtent, LPINT lpnFit, LPINT alpDx, _Out_opt_ LPSIZE lpSize) const;
	BOOL GetTextExtentPointI(LPWORD pgiIn, int cgi, _Out_opt_ LPSIZE lpSize) const;

#endif



// Advanced Drawing
	BOOL DrawEdge(LPRECT lpRect, UINT nEdge, UINT nFlags);
	BOOL DrawFrameControl(LPRECT lpRect, UINT nType, UINT nState);

// Scrolling Functions
	BOOL ScrollDC(int dx, int dy, LPCRECT lpRectScroll, LPCRECT lpRectClip,
		CRgn* pRgnUpdate, LPRECT lpRectUpdate);

// Font Functions
	BOOL GetCharWidth(UINT nFirstChar, UINT nLastChar, LPINT lpBuffer) const;
	BOOL GetOutputCharWidth(UINT nFirstChar, UINT nLastChar, LPINT lpBuffer) const;
	DWORD SetMapperFlags(DWORD dwFlag);
	CSize GetAspectRatioFilter() const;

	BOOL GetCharABCWidths(UINT nFirstChar, UINT nLastChar, LPABC lpabc) const;
	DWORD GetFontData(DWORD dwTable, DWORD dwOffset, LPVOID lpData, DWORD cbData) const;
	int GetKerningPairs(int nPairs, LPKERNINGPAIR lpkrnpair) const;
	UINT GetOutlineTextMetrics(UINT cbData, LPOUTLINETEXTMETRIC lpotm) const;
	DWORD GetGlyphOutline(UINT nChar, UINT nFormat, LPGLYPHMETRICS lpgm,
		DWORD cbBuffer, LPVOID lpBuffer, const MAT2* lpmat2) const;

	BOOL GetCharABCWidths(UINT nFirstChar, UINT nLastChar,
		LPABCFLOAT lpABCF) const;
	BOOL GetCharWidth(UINT nFirstChar, UINT nLastChar,
		float* lpFloatBuffer) const;

	DWORD GetFontLanguageInfo() const;

#if (_WIN32_WINNT >= 0x0500)

	BOOL GetCharABCWidthsI(UINT giFirst, UINT cgi, LPWORD pgi, LPABC lpabc) const;
	BOOL GetCharWidthI(UINT giFirst, UINT cgi, LPWORD pgi, LPINT lpBuffer) const;

#endif

// Printer/Device Escape Functions
	virtual int Escape(_In_ int nEscape, _In_ int nCount,
		_In_bytecount_(nCount) LPCSTR lpszInData, _In_ LPVOID lpOutData);
	int Escape(_In_ int nEscape, _In_ int nInputSize, _In_bytecount_(nInputSize) LPCSTR lpszInputData,
		_In_ int nOutputSize, _Out_bytecap_(nOutputSize) LPSTR lpszOutputData);
	int DrawEscape(int nEscape, int nInputSize, LPCSTR lpszInputData);

	// Escape helpers
	int StartDoc(LPCTSTR lpszDocName);  // old Win3.0 version
	int StartDoc(LPDOCINFO lpDocInfo);
	int StartPage();
	int EndPage();
	int SetAbortProc(BOOL (CALLBACK* lpfn)(HDC, int));
	int AbortDoc();
	int EndDoc();

// MetaFile Functions
	BOOL PlayMetaFile(HMETAFILE hMF);
	BOOL PlayMetaFile(HENHMETAFILE hEnhMetaFile, LPCRECT lpBounds);
	BOOL AddMetaFileComment(UINT nDataSize, const BYTE* pCommentData);
		// can be used for enhanced metafiles only

// Path Functions
	BOOL AbortPath();
	BOOL BeginPath();
	BOOL CloseFigure();
	BOOL EndPath();
	BOOL FillPath();
	BOOL FlattenPath();
	BOOL StrokeAndFillPath();
	BOOL StrokePath();
	BOOL WidenPath();
	float GetMiterLimit() const;
	BOOL SetMiterLimit(float fMiterLimit);
	int GetPath(LPPOINT lpPoints, LPBYTE lpTypes, int nCount) const;
	BOOL SelectClipPath(int nMode);

// Misc Helper Functions
	static CBrush* PASCAL GetHalftoneBrush();
	void DrawDragRect(LPCRECT lpRect, SIZE size,
		LPCRECT lpRectLast, SIZE sizeLast,
		CBrush* pBrush = NULL, CBrush* pBrushLast = NULL);
	void FillSolidRect(LPCRECT lpRect, COLORREF clr);
	void FillSolidRect(int x, int y, int cx, int cy, COLORREF clr);
	void Draw3dRect(LPCRECT lpRect, COLORREF clrTopLeft, COLORREF clrBottomRight);
	void Draw3dRect(int x, int y, int cx, int cy,
		COLORREF clrTopLeft, COLORREF clrBottomRight);

// Implementation
public:
	virtual ~CDC();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// advanced use and implementation
	BOOL m_bPrinting;
	HGDIOBJ SelectObject(HGDIOBJ);      // do not use for regions

protected:
	// used for implementation of non-virtual SelectObject calls
	static CGdiObject* PASCAL SelectGdiObject(HDC hDC, HGDIOBJ h);
};

/////////////////////////////////////////////////////////////////////////////
// CDC Helpers

class CPaintDC : public CDC
{
	DECLARE_DYNAMIC(CPaintDC)

// Constructors
public:
	explicit CPaintDC(CWnd* pWnd);   // BeginPaint

// Attributes
protected:
	HWND m_hWnd;
public:
	PAINTSTRUCT m_ps;       // actual paint struct!

// Implementation
public:
	virtual ~CPaintDC();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

class CClientDC : public CDC
{
	DECLARE_DYNAMIC(CClientDC)

// Constructors
public:
	explicit CClientDC(CWnd* pWnd);

// Attributes
protected:
	HWND m_hWnd;

// Implementation
public:
	virtual ~CClientDC();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

class CWindowDC : public CDC
{
	DECLARE_DYNAMIC(CWindowDC)

// Constructors
public:
	explicit CWindowDC(CWnd* pWnd);

// Attributes
protected:
	HWND m_hWnd;

// Implementation
public:
	virtual ~CWindowDC();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

/////////////////////////////////////////////////////////////////////////////
// CImageList

class CImageList : public CObject
{
	DECLARE_DYNCREATE(CImageList)

// Constructors
public:
	CImageList();
	BOOL Create(int cx, int cy, UINT nFlags, int nInitial, int nGrow);
	BOOL Create(UINT nBitmapID, int cx, int nGrow, COLORREF crMask);
	BOOL Create(LPCTSTR lpszBitmapID, int cx, int nGrow, COLORREF crMask);
	BOOL Create(CImageList& imagelist1, int nImage1, CImageList& imagelist2,
		int nImage2, int dx, int dy);
	BOOL Create(CImageList* pImageList);

// Attributes
	HIMAGELIST m_hImageList;            // must be first data member
	operator HIMAGELIST() const;
	HIMAGELIST GetSafeHandle() const;

	static CImageList* PASCAL FromHandle(HIMAGELIST hImageList);
	static CImageList* PASCAL FromHandlePermanent(HIMAGELIST hImageList);
	static void PASCAL DeleteTempMap();
	BOOL Attach(HIMAGELIST hImageList);
	HIMAGELIST Detach();

	int GetImageCount() const;
	COLORREF SetBkColor(COLORREF cr);
	COLORREF GetBkColor() const;
	BOOL GetImageInfo(int nImage, IMAGEINFO* pImageInfo) const;

// Operations
	BOOL DeleteImageList();
	BOOL SetImageCount(UINT uNewCount);

	int Add(CBitmap* pbmImage, CBitmap* pbmMask);
	int Add(CBitmap* pbmImage, COLORREF crMask);
	BOOL Remove(int nImage);
	BOOL Replace(int nImage, CBitmap* pbmImage, CBitmap* pbmMask);
	int Add(HICON hIcon);
	int Replace(int nImage, HICON hIcon);
	HICON ExtractIcon(int nImage);
	BOOL Draw(CDC* pDC, int nImage, POINT pt, UINT nStyle);
	BOOL DrawEx(CDC* pDC, int nImage, POINT pt, SIZE sz, COLORREF clrBk, COLORREF clrFg, UINT nStyle);
	BOOL SetOverlayImage(int nImage, int nOverlay);
	BOOL Copy(int iDst, int iSrc, UINT uFlags = ILCF_MOVE);
	BOOL Copy(int iDst, CImageList* pSrc, int iSrc, UINT uFlags = ILCF_MOVE);
	BOOL DrawIndirect(IMAGELISTDRAWPARAMS* pimldp);
	BOOL DrawIndirect(CDC* pDC, int nImage, POINT pt, SIZE sz, POINT ptOrigin,
			UINT fStyle = ILD_NORMAL, DWORD dwRop = SRCCOPY,
			COLORREF rgbBack = CLR_DEFAULT, COLORREF rgbFore = CLR_DEFAULT,
			DWORD fState = ILS_NORMAL, DWORD Frame = 0, COLORREF crEffect = CLR_DEFAULT);

#ifndef _AFX_NO_OLE_SUPPORT
	BOOL Read(CArchive* pArchive);
	BOOL Write(CArchive* pArchive);
#endif

// Drag APIs
	BOOL BeginDrag(int nImage, CPoint ptHotSpot);
	static void PASCAL EndDrag();
	static BOOL PASCAL DragMove(CPoint pt);
	BOOL SetDragCursorImage(int nDrag, CPoint ptHotSpot);
	static BOOL PASCAL DragShowNolock(BOOL bShow);
	static CImageList* PASCAL GetDragImage(LPPOINT lpPoint, LPPOINT lpPointHotSpot);
	static BOOL PASCAL DragEnter(CWnd* pWndLock, CPoint point);
	static BOOL PASCAL DragLeave(CWnd* pWndLock);

// Implementation
public:
	virtual ~CImageList();
#ifdef _DEBUG
	virtual void Dump(CDumpContext& dc) const;
	virtual void AssertValid() const;
#endif
};

/////////////////////////////////////////////////////////////////////////////
// CMenu

class CMenu : public CObject
{
	DECLARE_DYNCREATE(CMenu)
public:

// Constructors
	CMenu();

	BOOL CreateMenu();
	BOOL CreatePopupMenu();
	BOOL LoadMenu(LPCTSTR lpszResourceName);
	BOOL LoadMenu(UINT nIDResource);
	BOOL LoadMenuIndirect(const void* lpMenuTemplate);
	BOOL DestroyMenu();

// Attributes
	HMENU m_hMenu;          // must be first data member
	HMENU GetSafeHmenu() const;
	operator HMENU() const;

	static CMenu* PASCAL FromHandle(HMENU hMenu);
	static void PASCAL DeleteTempMap();
	BOOL Attach(HMENU hMenu);
	HMENU Detach();

// CMenu Operations
	BOOL DeleteMenu(UINT nPosition, UINT nFlags);
	BOOL TrackPopupMenu(UINT nFlags, int x, int y,
						CWnd* pWnd, LPCRECT lpRect = 0);
	BOOL TrackPopupMenuEx(UINT fuFlags, int x, int y, CWnd* pWnd, LPTPMPARAMS lptpm);

#if(WINVER >= 0x0500)

	BOOL SetMenuInfo(LPCMENUINFO lpcmi);
	BOOL GetMenuInfo(LPMENUINFO lpcmi) const;

#endif

	BOOL operator==(const CMenu& menu) const;
	BOOL operator!=(const CMenu& menu) const;

// CMenuItem Operations
	BOOL AppendMenu(UINT nFlags, UINT_PTR nIDNewItem = 0,
					LPCTSTR lpszNewItem = NULL);
	BOOL AppendMenu(UINT nFlags, UINT_PTR nIDNewItem, const CBitmap* pBmp);
	UINT CheckMenuItem(UINT nIDCheckItem, UINT nCheck);
	UINT EnableMenuItem(UINT nIDEnableItem, UINT nEnable);
	UINT GetMenuItemCount() const;
	UINT GetMenuItemID(int nPos) const;
	UINT GetMenuState(UINT nID, UINT nFlags) const;
	int GetMenuString(_In_ UINT nIDItem, _Out_z_cap_(nMaxCount) LPTSTR lpString, _In_ int nMaxCount,
					_In_ UINT nFlags) const;
	int GetMenuString(UINT nIDItem, CString& rString, UINT nFlags) const;
	BOOL GetMenuItemInfo(UINT uItem, LPMENUITEMINFO lpMenuItemInfo,
					BOOL fByPos = FALSE);
	BOOL SetMenuItemInfo(UINT uItem, LPMENUITEMINFO lpMenuItemInfo,
					BOOL fByPos = FALSE);
	CMenu* GetSubMenu(int nPos) const;
	BOOL InsertMenu(UINT nPosition, UINT nFlags, UINT_PTR nIDNewItem = 0,
					LPCTSTR lpszNewItem = NULL);
	BOOL InsertMenu(UINT nPosition, UINT nFlags, UINT_PTR nIDNewItem,
					const CBitmap* pBmp);
	BOOL InsertMenuItem(UINT uItem, LPMENUITEMINFO lpMenuItemInfo,
					BOOL fByPos = FALSE);
	BOOL ModifyMenu(UINT nPosition, UINT nFlags, UINT_PTR nIDNewItem = 0,
					LPCTSTR lpszNewItem = NULL);
	BOOL ModifyMenu(UINT nPosition, UINT nFlags, UINT_PTR nIDNewItem,
					const CBitmap* pBmp);
	BOOL RemoveMenu(UINT nPosition, UINT nFlags);
	BOOL SetMenuItemBitmaps(UINT nPosition, UINT nFlags,
					const CBitmap* pBmpUnchecked, const CBitmap* pBmpChecked);
	BOOL CheckMenuRadioItem(UINT nIDFirst, UINT nIDLast, UINT nIDItem, UINT nFlags);
	BOOL SetDefaultItem(UINT uItem, BOOL fByPos = FALSE);
	UINT GetDefaultItem(UINT gmdiFlags, BOOL fByPos = FALSE);

// Context Help Functions
	BOOL SetMenuContextHelpId(DWORD dwContextHelpId);
	DWORD GetMenuContextHelpId() const;

// Overridables (must override draw and measure for owner-draw menu items)
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);

// Implementation
public:
	virtual ~CMenu();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	static CMenu* PASCAL CMenu::FromHandlePermanent(HMENU hMenu);
};

/////////////////////////////////////////////////////////////////////////////
// Window message map handling

struct AFX_MSGMAP_ENTRY;       // declared below after CWnd

struct AFX_MSGMAP
{
	const AFX_MSGMAP* (PASCAL* pfnGetBaseMap)();
	const AFX_MSGMAP_ENTRY* lpEntries;
};


#define DECLARE_MESSAGE_MAP() \
protected: \
	static const AFX_MSGMAP* PASCAL GetThisMessageMap(); \
	virtual const AFX_MSGMAP* GetMessageMap() const; \

#define BEGIN_TEMPLATE_MESSAGE_MAP(theClass, type_name, baseClass)			\
	PTM_WARNING_DISABLE														\
	template < typename type_name >											\
	const AFX_MSGMAP* theClass< type_name >::GetMessageMap() const			\
		{ return GetThisMessageMap(); }										\
	template < typename type_name >											\
	const AFX_MSGMAP* PASCAL theClass< type_name >::GetThisMessageMap()		\
	{																		\
		typedef theClass< type_name > ThisClass;							\
		typedef baseClass TheBaseClass;										\
		static const AFX_MSGMAP_ENTRY _messageEntries[] =					\
		{

#define BEGIN_MESSAGE_MAP(theClass, baseClass) \
	PTM_WARNING_DISABLE \
	const AFX_MSGMAP* theClass::GetMessageMap() const \
		{ return GetThisMessageMap(); } \
	const AFX_MSGMAP* PASCAL theClass::GetThisMessageMap() \
	{ \
		typedef theClass ThisClass;						   \
		typedef baseClass TheBaseClass;					   \
		static const AFX_MSGMAP_ENTRY _messageEntries[] =  \
		{

#define END_MESSAGE_MAP() \
		{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } \
	}; \
		static const AFX_MSGMAP messageMap = \
		{ &TheBaseClass::GetThisMessageMap, &_messageEntries[0] }; \
		return &messageMap; \
	}								  \
	PTM_WARNING_RESTORE


// Message map signature values and macros in separate header
#include <afxmsg_.h>

/////////////////////////////////////////////////////////////////////////////
// Dialog data exchange (DDX_) and validation (DDV_)

class COleControlSite;

// CDataExchange - for data exchange and validation
class CDataExchange
{
// Attributes
public:
	BOOL m_bSaveAndValidate;   // TRUE => save and validate data
	CWnd* m_pDlgWnd;           // container usually a dialog

// Operations (for implementors of DDX and DDV procs)
	HWND PrepareCtrl(int nIDC);     
	HWND PrepareEditCtrl(int nIDC); 
	void Fail();                    // will throw exception

	CDataExchange(CWnd* pDlgWnd, BOOL bSaveAndValidate);

#ifndef _AFX_NO_OCC_SUPPORT
	COleControlSite* PrepareOleCtrl(int nIDC); // for OLE controls in dialog
#endif

// Implementation
   UINT m_idLastControl;      // last control used (for validation)
	BOOL m_bEditLastControl;   // last control was an edit item
};

#include <afxdd_.h>     // standard DDX_ and DDV_ routines

/////////////////////////////////////////////////////////////////////////////
// OLE types

typedef LONG HRESULT;

struct IUnknown;
typedef IUnknown* LPUNKNOWN;

struct IDispatch;
typedef IDispatch* LPDISPATCH;

struct IConnectionPoint;
typedef IConnectionPoint* LPCONNECTIONPOINT;

struct IEnumOLEVERB;
typedef IEnumOLEVERB* LPENUMOLEVERB;

typedef struct _GUID GUID;
typedef GUID IID;
typedef GUID CLSID;
#ifndef _REFCLSID_DEFINED
#define REFCLSID const CLSID &
#endif

typedef long DISPID;
typedef unsigned short VARTYPE;
typedef long SCODE;

typedef WCHAR OLECHAR;
typedef OLECHAR* BSTR;

struct tagDISPPARAMS;
typedef tagDISPPARAMS DISPPARAMS;

struct tagVARIANT;
typedef tagVARIANT VARIANT;

struct ITypeInfo;
typedef ITypeInfo* LPTYPEINFO;

struct ITypeLib;
typedef ITypeLib* LPTYPELIB;

struct IAccessible;
struct IAccessibleProxy;
struct IAccessibleServer;
struct IEnumVARIANT;

struct tagEXCEPINFO;
typedef tagEXCEPINFO EXCEPINFO;


/////////////////////////////////////////////////////////////////////////////
// CCmdTarget

// private structures
struct AFX_CMDHANDLERINFO;  // info about where the command is handled
struct AFX_EVENT;           // info about an event
class CTypeLibCache;        // cache for OLE type libraries

/////////////////////////////////////////////////////////////////////////////
// OLE interface map handling (more in AFXDISP.H)

#ifndef _AFX_NO_OLE_SUPPORT

struct AFX_INTERFACEMAP_ENTRY
{
	const void* piid;       // the interface id (IID) (NULL for aggregate)
	size_t nOffset;         // offset of the interface vtable from m_unknown
};

struct AFX_INTERFACEMAP
{
#ifdef _AFXDLL
	const AFX_INTERFACEMAP* (PASCAL* pfnGetBaseMap)(); // NULL is root class
#else
	const AFX_INTERFACEMAP* pBaseMap;
#endif
	const AFX_INTERFACEMAP_ENTRY* pEntry; // map for this class
};


#ifdef _AFXDLL
#define DECLARE_INTERFACE_MAP() \
private: \
	static const AFX_INTERFACEMAP_ENTRY _interfaceEntries[]; \
protected: \
	static const AFX_INTERFACEMAP interfaceMap; \
	static const AFX_INTERFACEMAP* PASCAL GetThisInterfaceMap(); \
	virtual const AFX_INTERFACEMAP* GetInterfaceMap() const; \

#else
#define DECLARE_INTERFACE_MAP() \
private: \
	static const AFX_INTERFACEMAP_ENTRY _interfaceEntries[]; \
protected: \
	static const AFX_INTERFACEMAP interfaceMap; \
	virtual const AFX_INTERFACEMAP* GetInterfaceMap() const; \

#endif

/////////////////////////////////////////////////////////////////////////////
// OLE COM (Component Object Model) implementation infrastructure
//      - data driven QueryInterface
//      - standard implementation of aggregate AddRef and Release
// (see CCmdTarget in AFXWIN.H for more information)

#define METHOD_PROLOGUE(theClass, localClass) \
	theClass* pThis = \
		((theClass*)((BYTE*)this - offsetof(theClass, m_x##localClass))); \
	AFX_MANAGE_STATE(pThis->m_pModuleState) \
	pThis; // avoid warning from compiler \

#define METHOD_PROLOGUE_(theClass, localClass) \
	theClass* pThis = \
		((theClass*)((BYTE*)this - offsetof(theClass, m_x##localClass))); \
	pThis; // avoid warning from compiler \

#ifndef _AFX_NO_NESTED_DERIVATION
#define METHOD_PROLOGUE_EX(theClass, localClass) \
	theClass* pThis = ((theClass*)((BYTE*)this - m_nOffset)); \
	AFX_MANAGE_STATE(pThis->m_pModuleState) \
	pThis; // avoid warning from compiler \

#define METHOD_PROLOGUE_EX_(theClass, localClass) \
	theClass* pThis = ((theClass*)((BYTE*)this - m_nOffset)); \
	pThis; // avoid warning from compiler \

#else
#define METHOD_PROLOGUE_EX(theClass, localClass) \
	METHOD_PROLOGUE(theClass, localClass) \

#define METHOD_PROLOGUE_EX_(theClass, localClass) \
	METHOD_PROLOGUE_(theClass, localClass) \

#endif

// Provided only for compatibility with CDK 1.x
#define METHOD_MANAGE_STATE(theClass, localClass) \
	METHOD_PROLOGUE_EX(theClass, localClass) \

#define BEGIN_INTERFACE_PART(localClass, baseClass) \
	class X##localClass : public baseClass \
	{ \
	public: \
		STDMETHOD_(ULONG, AddRef)(); \
		STDMETHOD_(ULONG, Release)(); \
		STDMETHOD(QueryInterface)(REFIID iid, LPVOID* ppvObj); \

#ifndef _AFX_NO_NESTED_DERIVATION
#define BEGIN_INTERFACE_PART_DERIVE(localClass, baseClass) \
	class X##localClass : public baseClass \
	{ \
	public: \

#else
#define BEGIN_INTERFACE_PART_DERIVE(localClass, baseClass) \
	BEGIN_INTERFACE_PART(localClass, baseClass) \

#endif

#ifndef _AFX_NO_NESTED_DERIVATION
#define INIT_INTERFACE_PART(theClass, localClass) \
		size_t m_nOffset; \
		INIT_INTERFACE_PART_DERIVE(theClass, localClass) \

#define INIT_INTERFACE_PART_DERIVE(theClass, localClass) \
		X##localClass() \
			{ m_nOffset = offsetof(theClass, m_x##localClass); } \

#else
#define INIT_INTERFACE_PART(theClass, localClass)
#define INIT_INTERFACE_PART_DERIVE(theClass, localClass)

#endif

// Note: Inserts the rest of OLE functionality between these two macros,
//  depending upon the interface that is being implemented.  It is not
//  necessary to include AddRef, Release, and QueryInterface since those
//  member functions are declared by the macro.

#define END_INTERFACE_PART(localClass) \
	} m_x##localClass; \
	friend class X##localClass; \

struct CInterfacePlaceHolder
{
	DWORD_PTR m_vtbl;   // filled in with USE_INTERFACE_PART
	CInterfacePlaceHolder() { m_vtbl = 0; }
};

#define END_INTERFACE_PART_OPTIONAL(localClass) \
	}; \
	CInterfacePlaceHolder m_x##localClass; \
	friend class X##localClass; \

#ifdef _AFXDLL
#define END_INTERFACE_PART_STATIC END_INTERFACE_PART
#else
#define END_INTERFACE_PART_STATIC END_INTERFACE_PART
#endif

#define USE_INTERFACE_PART(localClass) \
	m_x##localClass.m_vtbl = *(DWORD_PTR*)&X##localClass(); \

// To avoid C4238.
#define USE_INTERFACE_PART_STD(localClass) \
	X##localClass tmp##localClass; \
	m_x##localClass.m_vtbl = *(DWORD_PTR*)&tmp##localClass;

#ifdef _AFXDLL
#define BEGIN_INTERFACE_MAP(theClass, theBase) \
	const AFX_INTERFACEMAP* PASCAL theClass::GetThisInterfaceMap() \
		{ return &theClass::interfaceMap; } \
	const AFX_INTERFACEMAP* theClass::GetInterfaceMap() const \
		{ return &theClass::interfaceMap; } \
	AFX_COMDAT const AFX_INTERFACEMAP theClass::interfaceMap = \
		{ &theBase::GetThisInterfaceMap, &theClass::_interfaceEntries[0], }; \
	AFX_COMDAT const AFX_INTERFACEMAP_ENTRY theClass::_interfaceEntries[] = \
	{ \

#else
#define BEGIN_INTERFACE_MAP(theClass, theBase) \
	const AFX_INTERFACEMAP* theClass::GetInterfaceMap() const \
		{ return &theClass::interfaceMap; } \
	AFX_COMDAT const AFX_INTERFACEMAP theClass::interfaceMap = \
		{ &theBase::interfaceMap, &theClass::_interfaceEntries[0], }; \
	AFX_COMDAT const AFX_INTERFACEMAP_ENTRY theClass::_interfaceEntries[] = \
	{ \

#endif

#define INTERFACE_PART(theClass, iid, localClass) \
		{ &iid, offsetof(theClass, m_x##localClass) }, \

#define INTERFACE_AGGREGATE(theClass, theAggr) \
		{ NULL, offsetof(theClass, theAggr) }, \

#define END_INTERFACE_MAP() \
		{ NULL, (size_t)-1 } \
	}; \


#endif //!_AFX_NO_OLE_SUPPORT

/////////////////////////////////////////////////////////////////////////////
// OLE dispatch map handling (more in AFXDISP.H)

#ifndef _AFX_NO_OLE_SUPPORT

struct AFX_DISPMAP_ENTRY;

struct AFX_DISPMAP
{
#ifdef _AFXDLL
	const AFX_DISPMAP* (PASCAL* pfnGetBaseMap)();
#else
	const AFX_DISPMAP* pBaseMap;
#endif
	const AFX_DISPMAP_ENTRY* lpEntries;
	UINT* lpEntryCount;
	DWORD* lpStockPropMask;
};

#ifdef _AFXDLL
#define DECLARE_DISPATCH_MAP() \
private: \
	static const AFX_DISPMAP_ENTRY _dispatchEntries[]; \
	static UINT _dispatchEntryCount; \
	static DWORD _dwStockPropMask; \
protected: \
	static const AFX_DISPMAP dispatchMap; \
	static const AFX_DISPMAP* PASCAL GetThisDispatchMap(); \
	virtual const AFX_DISPMAP* GetDispatchMap() const; \

#else
#define DECLARE_DISPATCH_MAP() \
private: \
	static const AFX_DISPMAP_ENTRY _dispatchEntries[]; \
	static UINT _dispatchEntryCount; \
	static DWORD _dwStockPropMask; \
protected: \
	static const AFX_DISPMAP dispatchMap; \
	virtual const AFX_DISPMAP* GetDispatchMap() const; \

#endif

#endif //!_AFX_NO_OLE_SUPPORT

/////////////////////////////////////////////////////////////////////////////
// OLE Document Object command target handling

#ifndef _AFX_NO_DOCOBJECT_SUPPORT

struct AFX_OLECMDMAP_ENTRY
{
   const GUID* pguid;   // id of the command group
   ULONG       cmdID;   // OLECMD ID
   UINT        nID;     // corresponding WM_COMMAND message ID
};

struct AFX_OLECMDMAP
{
#ifdef _AFXDLL
	const AFX_OLECMDMAP* (PASCAL* pfnGetBaseMap)();
#else
	const AFX_OLECMDMAP* pBaseMap;
#endif
	const AFX_OLECMDMAP_ENTRY* lpEntries;
};

#ifdef _AFXDLL
#define DECLARE_OLECMD_MAP() \
private: \
	static const AFX_OLECMDMAP_ENTRY _commandEntries[]; \
protected: \
	static const AFX_OLECMDMAP commandMap; \
	static const AFX_OLECMDMAP* PASCAL GetThisCommandMap(); \
	virtual const AFX_OLECMDMAP* GetCommandMap() const; \

#else
#define DECLARE_OLECMD_MAP() \
private: \
	static const AFX_OLECMDMAP_ENTRY _commandEntries[]; \
protected: \
	static const AFX_OLECMDMAP commandMap; \
	virtual const AFX_OLECMDMAP* GetCommandMap() const; \

#endif

#ifdef _AFXDLL
#define BEGIN_OLECMD_MAP(theClass, baseClass) \
	const AFX_OLECMDMAP* PASCAL theClass::GetThisCommandMap() \
		{ return &theClass::commandMap; } \
	const AFX_OLECMDMAP* theClass::GetCommandMap() const \
		{ return &theClass::commandMap; } \
	AFX_COMDAT const AFX_OLECMDMAP theClass::commandMap = \
	{ &baseClass::GetThisCommandMap, &theClass::_commandEntries[0] }; \
	AFX_COMDAT const AFX_OLECMDMAP_ENTRY theClass::_commandEntries[] = \
	{ \

#else
#define BEGIN_OLECMD_MAP(theClass, baseClass) \
	const AFX_OLECMDMAP* theClass::GetCommandMap() const \
		{ return &theClass::commandMap; } \
	AFX_COMDAT const AFX_OLECMDMAP theClass::commandMap = \
	{ &baseClass::commandMap, &theClass::_commandEntries[0] }; \
	AFX_COMDAT const AFX_OLECMDMAP_ENTRY theClass::_commandEntries[] = \
	{ \

#endif

#define END_OLECMD_MAP() \
		{NULL, 0, 0} \
	}; \

class COleCmdUI;

#endif //!_AFX_NO_DOCOBJECT_SUPPORT

/////////////////////////////////////////////////////////////////////////////
// OLE event sink map handling (more in AFXDISP.H)

#ifndef _AFX_NO_OCC_SUPPORT

struct AFX_EVENTSINKMAP_ENTRY;

struct AFX_EVENTSINKMAP
{
#ifdef _AFXDLL
	const AFX_EVENTSINKMAP* (PASCAL* pfnGetBaseMap)();
#else
	const AFX_EVENTSINKMAP* pBaseMap;
#endif
	const AFX_EVENTSINKMAP_ENTRY* lpEntries;
	UINT* lpEntryCount;
};

#ifdef _AFXDLL
#define DECLARE_EVENTSINK_MAP() \
private: \
	static const AFX_EVENTSINKMAP_ENTRY _eventsinkEntries[]; \
	static UINT _eventsinkEntryCount; \
protected: \
	static const AFX_EVENTSINKMAP eventsinkMap; \
	static const AFX_EVENTSINKMAP* PASCAL GetThisEventSinkMap(); \
	virtual const AFX_EVENTSINKMAP* GetEventSinkMap() const; \

#else
#define DECLARE_EVENTSINK_MAP() \
private: \
	static const AFX_EVENTSINKMAP_ENTRY _eventsinkEntries[]; \
	static UINT _eventsinkEntryCount; \
protected: \
	static const AFX_EVENTSINKMAP eventsinkMap; \
	virtual const AFX_EVENTSINKMAP* GetEventSinkMap() const; \

#endif

#endif //!_AFX_NO_OCC_SUPPORT

/////////////////////////////////////////////////////////////////////////////
// OLE connection map handling (more in AFXDISP.H)

#ifndef _AFX_NO_OLE_SUPPORT

struct AFX_CONNECTIONMAP_ENTRY
{
	const void* piid;   // the interface id (IID)
	size_t nOffset;         // offset of the interface vtable from m_unknown
};

struct AFX_CONNECTIONMAP
{
#ifdef _AFXDLL
	const AFX_CONNECTIONMAP* (PASCAL* pfnGetBaseMap)(); // NULL is root class
#else
	const AFX_CONNECTIONMAP* pBaseMap;
#endif
	const AFX_CONNECTIONMAP_ENTRY* pEntry; // map for this class
};

#ifdef _AFXDLL
#define DECLARE_CONNECTION_MAP() \
private: \
	static const AFX_CONNECTIONMAP_ENTRY _connectionEntries[]; \
protected: \
	static const AFX_CONNECTIONMAP connectionMap; \
	static const AFX_CONNECTIONMAP* PASCAL GetThisConnectionMap(); \
	virtual const AFX_CONNECTIONMAP* GetConnectionMap() const; \

#else
#define DECLARE_CONNECTION_MAP() \
private: \
	static const AFX_CONNECTIONMAP_ENTRY _connectionEntries[]; \
protected: \
	static const AFX_CONNECTIONMAP connectionMap; \
	virtual const AFX_CONNECTIONMAP* GetConnectionMap() const; \

#endif

#endif //!_AFX_NO_OLE_SUPPORT

/////////////////////////////////////////////////////////////////////////////
// CCmdTarget proper

#ifndef _AFX_NO_OCC_SUPPORT
class COccManager;      // forward reference (see ..\src\occimpl.h)
#endif

class AFX_NOVTABLE CCmdTarget : public CObject
{
	DECLARE_DYNAMIC(CCmdTarget)
protected:

public:
// Constructors
	CCmdTarget();

// Attributes
	LPDISPATCH GetIDispatch(BOOL bAddRef);
		// retrieve IDispatch part of CCmdTarget
	static CCmdTarget* PASCAL FromIDispatch(LPDISPATCH lpDispatch);
		// map LPDISPATCH back to CCmdTarget* (inverse of GetIDispatch)
	BOOL IsResultExpected();
		// returns TRUE if automation function should return a value

// Operations
	void EnableAutomation();
		// call in constructor to wire up IDispatch
	void EnableConnections();
		// call in constructor to wire up IConnectionPointContainer

	void BeginWaitCursor();
	void EndWaitCursor();
	void RestoreWaitCursor();       // call after messagebox

#ifndef _AFX_NO_OLE_SUPPORT
	// dispatch OLE verbs through the message map
	BOOL EnumOleVerbs(LPENUMOLEVERB* ppenumOleVerb);
	BOOL DoOleVerb(LONG iVerb, LPMSG lpMsg, HWND hWndParent, LPCRECT lpRect);
#endif

// Overridables
	// route and dispatch standard command message types
	//   (more sophisticated than OnCommand)
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra,
		AFX_CMDHANDLERINFO* pHandlerInfo);

#ifndef _AFX_NO_OLE_SUPPORT
	// called when last OLE reference is released
	virtual void OnFinalRelease();
#endif

#ifndef _AFX_NO_OLE_SUPPORT
	// called before dispatching to an automation handler function
	virtual BOOL IsInvokeAllowed(DISPID dispid);
#endif

#ifndef _AFX_NO_OLE_SUPPORT
	// support for OLE type libraries
	void EnableTypeLib();
	HRESULT GetTypeInfoOfGuid(LCID lcid, const GUID& guid,
		LPTYPEINFO* ppTypeInfo);
	virtual BOOL GetDispatchIID(IID* pIID);
	virtual UINT GetTypeInfoCount();
	virtual CTypeLibCache* GetTypeLibCache();
	virtual HRESULT GetTypeLib(LCID lcid, LPTYPELIB* ppTypeLib);
#endif

// Implementation
public:
	virtual ~CCmdTarget() = 0;
#ifdef _DEBUG
	virtual void Dump(CDumpContext& dc) const;
	virtual void AssertValid() const;
#endif
#ifndef _AFX_NO_OLE_SUPPORT
	void GetNotSupported();
	void SetNotSupported();
#endif

protected:
	friend class CView;

	CView* GetRoutingView();
	CFrameWnd* GetRoutingFrame();
	static CView* PASCAL GetRoutingView_();
	static CFrameWnd* PASCAL GetRoutingFrame_();
	DECLARE_MESSAGE_MAP()       // base class - no {{ }} macros

#ifndef _AFX_NO_DOCOBJECT_SUPPORT
	DECLARE_OLECMD_MAP()
	friend class COleCmdUI;
#endif

#ifndef _AFX_NO_OLE_SUPPORT
	DECLARE_DISPATCH_MAP()
	DECLARE_CONNECTION_MAP()
	DECLARE_INTERFACE_MAP()

#ifndef _AFX_NO_OCC_SUPPORT
	DECLARE_EVENTSINK_MAP()
#endif // !_AFX_NO_OCC_SUPPORT

	// OLE interface map implementation
public:
	// data used when CCmdTarget is made OLE aware
	long m_dwRef;
	LPUNKNOWN m_pOuterUnknown;  // external controlling unknown if != NULL
	DWORD_PTR m_xInnerUnknown;  // place-holder for inner controlling unknown

public:
	// advanced operations
	void EnableAggregation();       // call to enable aggregation
	void ExternalDisconnect();      // forcibly disconnect
	LPUNKNOWN GetControllingUnknown();
		// get controlling IUnknown for aggregate creation

	// these versions do not delegate to m_pOuterUnknown
	DWORD InternalQueryInterface(const void*, LPVOID* ppvObj);
	DWORD InternalAddRef();
	DWORD InternalRelease();
	// these versions delegate to m_pOuterUnknown
	DWORD ExternalQueryInterface(const void*, LPVOID* ppvObj);
	DWORD ExternalAddRef();
	DWORD ExternalRelease();

	// implementation helpers
	LPUNKNOWN GetInterface(const void*);
	LPUNKNOWN QueryAggregates(const void*);

	// advanced overrideables for implementation
	virtual BOOL OnCreateAggregates();
	virtual LPUNKNOWN GetInterfaceHook(const void*);

	// OLE automation implementation
protected:
	struct XDispatch
	{
		DWORD_PTR m_vtbl;   // place-holder for IDispatch vtable
#ifndef _AFX_NO_NESTED_DERIVATION
		size_t m_nOffset;
#endif
	} m_xDispatch;
	BOOL m_bResultExpected;

	// member variable-based properties
	void GetStandardProp(const AFX_DISPMAP_ENTRY* pEntry,
		VARIANT* pvarResult, UINT* puArgErr);
	SCODE SetStandardProp(const AFX_DISPMAP_ENTRY* pEntry,
		DISPPARAMS* pDispParams, UINT* puArgErr);

	// DISPID to dispatch map lookup
	static UINT PASCAL GetEntryCount(const AFX_DISPMAP* pDispMap);
	const AFX_DISPMAP_ENTRY* PASCAL GetDispEntry(LONG memid);
	static LONG PASCAL MemberIDFromName(const AFX_DISPMAP* pDispMap, LPCTSTR lpszName);

	// helpers for member function calling implementation
	static UINT PASCAL GetStackSize(const BYTE* pbParams, VARTYPE vtResult);
#ifdef _SHADOW_DOUBLES
	SCODE PushStackArgs(BYTE* pStack, const BYTE* pbParams,
		void* pResult, VARTYPE vtResult, DISPPARAMS* pDispParams,
		UINT* puArgErr, VARIANT* rgTempVars, UINT nSizeArgs,CVariantBoolConverter* pTempStackArgs = NULL);
#else
	SCODE PushStackArgs(BYTE* pStack, const BYTE* pbParams,
		void* pResult, VARTYPE vtResult, DISPPARAMS* pDispParams,
		UINT* puArgErr, VARIANT* rgTempVars,CVariantBoolConverter* pTempStackArgs = NULL);
#endif
	SCODE CallMemberFunc(const AFX_DISPMAP_ENTRY* pEntry, WORD wFlags,
		VARIANT* pvarResult, DISPPARAMS* pDispParams, UINT* puArgErr);

	friend class COleDispatchImpl;

#ifndef _AFX_NO_OCC_SUPPORT
public:
	// OLE event sink implementation
	BOOL OnEvent(UINT idCtrl, AFX_EVENT* pEvent,
		AFX_CMDHANDLERINFO* pHandlerInfo);
protected:
	const AFX_EVENTSINKMAP_ENTRY* PASCAL GetEventSinkEntry(UINT idCtrl,
		AFX_EVENT* pEvent);
#endif // !_AFX_NO_OCC_SUPPORT

	// OLE connection implementation
	struct XConnPtContainer
	{
		DWORD_PTR m_vtbl;   // place-holder for IConnectionPointContainer vtable
#ifndef _AFX_NO_NESTED_DERIVATION
		size_t m_nOffset;
#endif
	} m_xConnPtContainer;

	AFX_MODULE_STATE* m_pModuleState;
	friend class CInnerUnknown;
	friend UINT APIENTRY _AfxThreadEntry(void* pParam);

	virtual BOOL GetExtraConnectionPoints(CPtrArray* pConnPoints);
	virtual LPCONNECTIONPOINT GetConnectionHook(const IID& iid);

	friend class COleConnPtContainer;

#endif //!_AFX_NO_OLE_SUPPORT
};

class CCmdUI        // simple helper class
{
public:
// Attributes
	UINT m_nID;
	UINT m_nIndex;          // menu item or other index

	// if a menu item
	CMenu* m_pMenu;         // NULL if not a menu
	CMenu* m_pSubMenu;      // sub containing menu item
							// if a popup sub menu - ID is for first in popup

	// if from some other window
	CWnd* m_pOther;         // NULL if a menu or not a CWnd

// Operations to do in ON_UPDATE_COMMAND_UI
	virtual void Enable(BOOL bOn = TRUE);
	virtual void SetCheck(int nCheck = 1);   // 0, 1 or 2 (indeterminate)
	virtual void SetRadio(BOOL bOn = TRUE);
	virtual void SetText(LPCTSTR lpszText);

// Advanced operation
	void ContinueRouting();

// Implementation
	CCmdUI();
	BOOL m_bEnableChanged;
	BOOL m_bContinueRouting;
	UINT m_nIndexMax;       // last + 1 for iterating m_nIndex

	CMenu* m_pParentMenu;   // NULL if parent menu not easily determined
							//  (probably a secondary popup menu)

	BOOL DoUpdate(CCmdTarget* pTarget, BOOL bDisableIfNoHndler);
};

// special CCmdUI derived classes are used for other UI paradigms
//  like toolbar buttons and status indicators

// pointer to afx_msg member function
#ifndef AFX_MSG_CALL
#define AFX_MSG_CALL
#endif
typedef void (AFX_MSG_CALL CCmdTarget::*AFX_PMSG)(void);

enum AFX_DISPMAP_FLAGS
{
	afxDispCustom = 0,
	afxDispStock = 1
};

//IA64: AFX_DISPMAP_ENTRY could be ordered more efficiently to reduce size
// bloat from alignment
#pragma warning( disable: 4121 )
struct AFX_DISPMAP_ENTRY
{
	LPCTSTR lpszName;       // member/property name
	long lDispID;           // DISPID (may be DISPID_UNKNOWN)
	LPCSTR lpszParams;      // member parameter description
	WORD vt;                // return value type / or type of property
	AFX_PMSG pfn;           // normal member On<membercall> or, OnGet<property>
	AFX_PMSG pfnSet;        // special member for OnSet<property>
	size_t nPropOffset;     // property offset
	AFX_DISPMAP_FLAGS flags;// flags (e.g. stock/custom)
};
#pragma warning( default: 4121 )

struct AFX_EVENTSINKMAP_ENTRY
{
	AFX_DISPMAP_ENTRY dispEntry;
	UINT nCtrlIDFirst;
	UINT nCtrlIDLast;
};

// DSC Sink state/reason codes passed to MFC user event handlers
enum DSCSTATE
{
	dscNoState = 0,
	dscOKToDo,
	dscCancelled,
	dscSyncBefore,
	dscAboutToDo,
	dscFailedToDo,
	dscSyncAfter,
	dscDidEvent
};

enum DSCREASON
{
	dscNoReason = 0,
	dscClose,
	dscCommit,
	dscDelete,
	dscEdit,
	dscInsert,
	dscModify,
	dscMove
};

/////////////////////////////////////////////////////////////////////////////
// CWnd implementation

// structures (see afxext.h)
struct CCreateContext;      // context for creating things
struct CPrintInfo;          // print preview customization info

struct AFX_MSGMAP_ENTRY
{
	UINT nMessage;   // windows message
	UINT nCode;      // control code or WM_NOTIFY code
	UINT nID;        // control ID (or 0 for windows messages)
	UINT nLastID;    // used for entries specifying a range of control id's
	UINT_PTR nSig;       // signature type (action) or pointer to message #
	AFX_PMSG pfn;    // routine to call (or special value)
};

/////////////////////////////////////////////////////////////////////////////
// CWnd - a Microsoft Windows application window

class COleDropTarget;   // for more information see AFXOLE.H
class COleControlContainer;
class COleControlSite;

// CWnd::m_nFlags (generic to CWnd)
#define WF_TOOLTIPS         0x0001  // window is enabled for tooltips
#define WF_TEMPHIDE         0x0002  // window is temporarily hidden
#define WF_STAYDISABLED     0x0004  // window should stay disabled
#define WF_MODALLOOP        0x0008  // currently in modal loop
#define WF_CONTINUEMODAL    0x0010  // modal loop should continue running
#define WF_OLECTLCONTAINER  0x0100  // some descendant is an OLE control
#define WF_TRACKINGTOOLTIPS 0x0400  // window is enabled for tracking tooltips

// CWnd::m_nFlags (specific to CFrameWnd)
#define WF_STAYACTIVE       0x0020  // look active even though not active
#define WF_NOPOPMSG         0x0040  // ignore WM_POPMESSAGESTRING calls
#define WF_MODALDISABLE     0x0080  // window is disabled
#define WF_KEEPMINIACTIVE   0x0200  // stay activate even though you are deactivated


#define WF_NOWIN32ISDIALOGMSG   0x0800
#define WF_ISWINFORMSVIEWWND    0x1000

// flags for CWnd::RunModalLoop
#define MLF_NOIDLEMSG       0x0001  // don't send WM_ENTERIDLE messages
#define MLF_NOKICKIDLE      0x0002  // don't send WM_KICKIDLE messages
#define MLF_SHOWONIDLE      0x0004  // show window if not visible at idle time

// extra MFC defined TTF_ flags for TOOLINFO::uFlags
#define TTF_NOTBUTTON       0x80000000L // no status help on buttondown
#define TTF_ALWAYSTIP       0x40000000L // always show the tip even if not active

class CWnd : public CCmdTarget
{
	DECLARE_DYNCREATE(CWnd)
protected:
	static const MSG* PASCAL GetCurrentMessage();

// Attributes
public:
	HWND m_hWnd;            // must be first data member
	operator HWND() const;
	BOOL operator==(const CWnd& wnd) const;
	BOOL operator!=(const CWnd& wnd) const;

	HWND GetSafeHwnd() const;
	DWORD GetStyle() const;
	DWORD GetExStyle() const;
	BOOL ModifyStyle(DWORD dwRemove, DWORD dwAdd, UINT nFlags = 0);
	BOOL ModifyStyleEx(DWORD dwRemove, DWORD dwAdd, UINT nFlags = 0);

	CWnd* GetOwner() const;
	void SetOwner(CWnd* pOwnerWnd);


#if(WINVER >= 0x0500)

	BOOL GetWindowInfo(PWINDOWINFO pwi) const;
	BOOL GetTitleBarInfo(PTITLEBARINFO pti) const;

#endif	// WINVER >= 0x0500

// Constructors and other creation
	CWnd();

	static CWnd* PASCAL FromHandle(HWND hWnd);
	static CWnd* PASCAL FromHandlePermanent(HWND hWnd);
	static void PASCAL DeleteTempMap();
	BOOL Attach(HWND hWndNew);
	HWND Detach();

	// subclassing/unsubclassing functions
	virtual void PreSubclassWindow();
	BOOL SubclassWindow(HWND hWnd);
	BOOL SubclassDlgItem(UINT nID, CWnd* pParent);
	HWND UnsubclassWindow();

	// handling of RT_DLGINIT resource (extension to RT_DIALOG)
	BOOL ExecuteDlgInit(LPCTSTR lpszResourceName);
	BOOL ExecuteDlgInit(LPVOID lpResource);

public:
	// for child windows, views, panes etc
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL);

	// advanced creation (allows access to extended styles)
	virtual BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		int x, int y, int nWidth, int nHeight,
		HWND hWndParent, HMENU nIDorHMenu, LPVOID lpParam = NULL);

	virtual BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		LPVOID lpParam = NULL);

#ifndef _AFX_NO_OCC_SUPPORT
	// for wrapping OLE controls
	BOOL CreateControl(REFCLSID clsid, LPCTSTR pszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID, CFile* pPersist=NULL,
		BOOL bStorage=FALSE, BSTR bstrLicKey=NULL);

	BOOL CreateControl(LPCTSTR pszClass, LPCTSTR pszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID, CFile* pPersist=NULL,
		BOOL bStorage=FALSE, BSTR bstrLicKey=NULL);

   // Another overload for creating controls that use default extents.
   BOOL CreateControl( REFCLSID clsid, LPCTSTR pszWindowName, DWORD dwStyle,
	  const POINT* ppt, const SIZE* psize, CWnd* pParentWnd, UINT nID,
	  CFile* pPersist = NULL, BOOL bStorage = FALSE, BSTR bstrLicKey = NULL );


   //Overload for special controls (WinForms), that require more than CLSID.
   BOOL CreateControl(const CControlCreationInfo& creationInfo, DWORD dwStyle,
	const POINT* ppt, const SIZE* psize, CWnd* pParentWnd, UINT nID);

	LPUNKNOWN GetControlUnknown();
	BOOL PaintWindowlessControls(CDC *pDC);
#endif

	virtual BOOL DestroyWindow();

	// special pre-creation and window rect adjustment hooks
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	// Advanced: virtual AdjustWindowRect
	enum AdjustType { adjustBorder = 0, adjustOutside = 1 };
	virtual void CalcWindowRect(LPRECT lpClientRect,
		UINT nAdjustType = adjustBorder);

// Window tree access
	int GetDlgCtrlID() const;
	int SetDlgCtrlID(int nID);
		// get and set window ID, for child windows only
	CWnd* GetDlgItem(int nID) const;
		// get immediate child with given ID
	void GetDlgItem(int nID, HWND* phWnd) const;
		// as above, but returns HWND
	CWnd* GetDescendantWindow(int nID, BOOL bOnlyPerm = FALSE) const;
		// like GetDlgItem but recursive
	void SendMessageToDescendants(UINT message, WPARAM wParam = 0,
		LPARAM lParam = 0, BOOL bDeep = TRUE, BOOL bOnlyPerm = FALSE);
	CFrameWnd* GetParentFrame() const;
	CFrameWnd* EnsureParentFrame() const;
	CWnd* GetTopLevelParent() const;
	CWnd* EnsureTopLevelParent() const;
	CWnd* GetTopLevelOwner() const;
	CWnd* GetParentOwner() const;
	CFrameWnd* GetTopLevelFrame() const;
	static CWnd* PASCAL GetSafeOwner(CWnd* pParent = NULL, HWND* pWndTop = NULL);

#if(WINVER >= 0x0500)

	CWnd* GetAncestor(UINT gaFlags) const;

#endif	// WINVER >= 0x0500

// Message Functions
#pragma push_macro("SendMessage")
#undef SendMessage
	LRESULT _AFX_FUNCNAME(SendMessage)(UINT message, WPARAM wParam = 0, LPARAM lParam = 0) const;
	LRESULT SendMessage(UINT message, WPARAM wParam = 0, LPARAM lParam = 0) const;
#pragma pop_macro("SendMessage")
	BOOL PostMessage(UINT message, WPARAM wParam = 0, LPARAM lParam = 0);

	BOOL SendNotifyMessage(UINT message, WPARAM wParam, LPARAM lParam);
	BOOL SendChildNotifyLastMsg(LRESULT* pResult = NULL);

	BOOL DragDetect(POINT pt) const;


// Message processing for modeless dialog-like windows
	BOOL IsDialogMessage(LPMSG lpMsg);

// Window Text Functions
	void SetWindowText(LPCTSTR lpszString);
	int GetWindowText(_Out_z_cap_post_count_(nMaxCount, return + 1) LPTSTR lpszStringBuf, _In_ int nMaxCount) const;
	void GetWindowText(CString& rString) const;
	int GetWindowTextLength() const;
	void SetFont(CFont* pFont, BOOL bRedraw = TRUE);
	CFont* GetFont() const;

// CMenu Functions - non-Child windows only
	CMenu* GetMenu() const;
	BOOL SetMenu(CMenu* pMenu);
	void DrawMenuBar();
	CMenu* GetSystemMenu(BOOL bRevert) const;
	BOOL HiliteMenuItem(CMenu* pMenu, UINT nIDHiliteItem, UINT nHilite);

// Window Size and Position Functions
	BOOL IsIconic() const;
	BOOL IsZoomed() const;
	void MoveWindow(int x, int y, int nWidth, int nHeight,
				BOOL bRepaint = TRUE);
	void MoveWindow(LPCRECT lpRect, BOOL bRepaint = TRUE);
	int SetWindowRgn(HRGN hRgn, BOOL bRedraw);
	int GetWindowRgn(HRGN hRgn) const;

	static AFX_DATA const CWnd wndTop; // SetWindowPos's pWndInsertAfter
	static AFX_DATA const CWnd wndBottom; // SetWindowPos's pWndInsertAfter
	static AFX_DATA const CWnd wndTopMost; // SetWindowPos pWndInsertAfter
	static AFX_DATA const CWnd wndNoTopMost; // SetWindowPos pWndInsertAfter

	BOOL SetWindowPos(const CWnd* pWndInsertAfter, int x, int y,
				int cx, int cy, UINT nFlags);
	UINT ArrangeIconicWindows();
	void BringWindowToTop();
	void GetWindowRect(LPRECT lpRect) const;
	void GetClientRect(LPRECT lpRect) const;

	BOOL GetWindowPlacement(WINDOWPLACEMENT* lpwndpl) const;
	BOOL SetWindowPlacement(const WINDOWPLACEMENT* lpwndpl);

// Coordinate Mapping Functions
	void ClientToScreen(LPPOINT lpPoint) const;
	void ClientToScreen(LPRECT lpRect) const;
	void ScreenToClient(LPPOINT lpPoint) const;
	void ScreenToClient(LPRECT lpRect) const;
	void MapWindowPoints(CWnd* pwndTo, LPPOINT lpPoint, UINT nCount) const;
	void MapWindowPoints(CWnd* pwndTo, LPRECT lpRect) const;

// Update/Painting Functions
	CDC* BeginPaint(LPPAINTSTRUCT lpPaint);
	void EndPaint(LPPAINTSTRUCT lpPaint);
	CDC* GetDC();
	CDC* GetWindowDC();
	int ReleaseDC(CDC* pDC);
	void Print(CDC* pDC, DWORD dwFlags) const;
	void PrintClient(CDC* pDC, DWORD dwFlags) const;

	void UpdateWindow();
	void SetRedraw(BOOL bRedraw = TRUE);
	BOOL GetUpdateRect(LPRECT lpRect, BOOL bErase = FALSE);
	int GetUpdateRgn(CRgn* pRgn, BOOL bErase = FALSE);
	void Invalidate(BOOL bErase = TRUE);
	void InvalidateRect(LPCRECT lpRect, BOOL bErase = TRUE);
	void InvalidateRgn(CRgn* pRgn, BOOL bErase = TRUE);
	void ValidateRect(LPCRECT lpRect);
	void ValidateRgn(CRgn* pRgn);
	BOOL ShowWindow(int nCmdShow);
	BOOL IsWindowVisible() const;
	void ShowOwnedPopups(BOOL bShow = TRUE);

	CDC* GetDCEx(CRgn* prgnClip, DWORD flags);
	BOOL LockWindowUpdate();
	void UnlockWindowUpdate();
	BOOL RedrawWindow(LPCRECT lpRectUpdate = NULL,
		CRgn* prgnUpdate = NULL,
		UINT flags = RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);
	BOOL EnableScrollBar(int nSBFlags, UINT nArrowFlags = ESB_ENABLE_BOTH);

	BOOL DrawAnimatedRects(int idAni, CONST RECT *lprcFrom, CONST RECT *lprcTo);
	BOOL DrawCaption(CDC* pDC, LPCRECT lprc, UINT uFlags);

#if(WINVER >= 0x0500)

	BOOL AnimateWindow(DWORD dwTime, DWORD dwFlags);

#endif	// WINVER >= 0x0500

#if(_WIN32_WINNT >= 0x0501)

	BOOL PrintWindow(CDC* pDC, UINT nFlags) const;

#endif	// _WIN32_WINNT >= 0x0501

// Layered Window

#if(_WIN32_WINNT >= 0x0500)

	BOOL SetLayeredWindowAttributes(COLORREF crKey, BYTE bAlpha, DWORD dwFlags);
	BOOL UpdateLayeredWindow(CDC* pDCDst, POINT *pptDst, SIZE *psize, 
		CDC* pDCSrc, POINT *pptSrc, COLORREF crKey, BLENDFUNCTION *pblend, DWORD dwFlags);

#endif	// _WIN32_WINNT >= 0x0500

#if(_WIN32_WINNT >= 0x0501)

	BOOL GetLayeredWindowAttributes(COLORREF *pcrKey, BYTE *pbAlpha, DWORD *pdwFlags) const;

#endif	// _WIN32_WINNT >= 0x0501


// Timer Functions
	UINT_PTR SetTimer(UINT_PTR nIDEvent, UINT nElapse,
		void (CALLBACK* lpfnTimer)(HWND, UINT, UINT_PTR, DWORD));
	BOOL KillTimer(UINT_PTR nIDEvent);

// ToolTip Functions
	BOOL EnableToolTips(BOOL bEnable = TRUE);
	BOOL EnableTrackingToolTips(BOOL bEnable = TRUE);
	static void PASCAL CancelToolTips(BOOL bKeys = FALSE);
	void FilterToolTipMessage(MSG* pMsg);

	// for command hit testing (used for automatic tooltips)
	virtual INT_PTR OnToolHitTest(CPoint point, TOOLINFO* pTI) const;

// Window State Functions
	BOOL IsWindowEnabled() const;
	BOOL EnableWindow(BOOL bEnable = TRUE);

	// the active window applies only to top-level (frame windows)
	static CWnd* PASCAL GetActiveWindow();
	CWnd* SetActiveWindow();

	// the foreground window applies only to top-level windows (frame windows)
	BOOL SetForegroundWindow();
	static CWnd* PASCAL GetForegroundWindow();

	// capture and focus apply to all windows
	static CWnd* PASCAL GetCapture();
	CWnd* SetCapture();
	static CWnd* PASCAL GetFocus();
	CWnd* SetFocus();

	static CWnd* PASCAL GetDesktopWindow();

// Obsolete and non-portable APIs - not recommended for new code
	void CloseWindow();
	BOOL OpenIcon();

// Dialog-Box Item Functions
// (NOTE: Dialog-Box Items/Controls are not necessarily in dialog boxes!)
	void CheckDlgButton(int nIDButton, UINT nCheck);
	void CheckRadioButton(int nIDFirstButton, int nIDLastButton,
					int nIDCheckButton);
	int GetCheckedRadioButton(int nIDFirstButton, int nIDLastButton) const;
	int DlgDirList(_Inout_z_ LPTSTR lpPathSpec, _In_ int nIDListBox,
					_In_ int nIDStaticPath, _In_ UINT nFileType);
	int DlgDirListComboBox(_Inout_z_ LPTSTR lpPathSpec, _In_ int nIDComboBox,
					_In_ int nIDStaticPath, _In_ UINT nFileType);
	AFX_DEPRECATED("CWnd::DlgDirSelect(lpszOut, nControlId) is no longer supported. Instead, use CWnd::DlgDirSelect(lpszOut, nSize, nControlId)")
		BOOL DlgDirSelect(_Out_z_cap_c_(_MAX_PATH) LPTSTR lpString, _In_ int nIDListBox);
	BOOL DlgDirSelect(_Out_z_cap_(nSize) LPTSTR lpString, _In_ int nSize, _In_ int nIDListBox);
	AFX_DEPRECATED("CWnd::DlgDirSelectComboBox(lpszOut, nControlId) is no longer supported. Instead, use CWnd::DlgDirSelectComboBox(lpszOut, nSize, nControlId)")
		BOOL DlgDirSelectComboBox(_Out_z_cap_c_(_MAX_PATH) LPTSTR lpString, _In_ int nIDComboBox);
	BOOL DlgDirSelectComboBox(_Out_z_cap_(nSize) LPTSTR lpString, _In_ int nSize, _In_ int nIDComboBox);

	UINT GetDlgItemInt(int nID, BOOL* lpTrans = NULL,
					BOOL bSigned = TRUE) const;
	int GetDlgItemText(_In_ int nID, _Out_z_cap_post_count_(nMaxCount, return + 1) LPTSTR lpStr, _In_ int nMaxCount) const;
	int GetDlgItemText(int nID, CString& rString) const;
	CWnd* GetNextDlgGroupItem(CWnd* pWndCtl, BOOL bPrevious = FALSE) const;
	COleControlSiteOrWnd* GetNextDlgGroupItem(COleControlSiteOrWnd *pCurSiteOrWnd = NULL) const;
	COleControlSiteOrWnd* GetPrevDlgGroupItem(COleControlSiteOrWnd *pCurSiteOrWnd = NULL) const;
	void RemoveRadioCheckFromGroup(const COleControlSiteOrWnd *pSiteOrWnd) const;
	CWnd* GetNextDlgTabItem(CWnd* pWndCtl, BOOL bPrevious = FALSE) const;
	COleControlSiteOrWnd* GetNextDlgTabItem(COleControlSiteOrWnd *pCurSiteOrWnd, BOOL bPrevious) const;
	UINT IsDlgButtonChecked(int nIDButton) const;
	LRESULT SendDlgItemMessage(int nID, UINT message,
					WPARAM wParam = 0, LPARAM lParam = 0);
	void SetDlgItemInt(int nID, UINT nValue, BOOL bSigned = TRUE);
	void SetDlgItemText(int nID, LPCTSTR lpszString);
	POSITION FindSiteOrWnd(const COleControlSiteOrWnd *pSiteOrWnd) const;
	POSITION FindSiteOrWndWithFocus() const;

// Scrolling Functions
	int GetScrollPos(int nBar) const;
	void GetScrollRange(int nBar, LPINT lpMinPos, LPINT lpMaxPos) const;
	void ScrollWindow(int xAmount, int yAmount,
					LPCRECT lpRect = NULL,
					LPCRECT lpClipRect = NULL);
	int SetScrollPos(int nBar, int nPos, BOOL bRedraw = TRUE);
	void SetScrollRange(int nBar, int nMinPos, int nMaxPos,
			BOOL bRedraw = TRUE);
	void ShowScrollBar(UINT nBar, BOOL bShow = TRUE);
	void EnableScrollBarCtrl(int nBar, BOOL bEnable = TRUE);
	virtual CScrollBar* GetScrollBarCtrl(int nBar) const;
			// return sibling scrollbar control (or NULL if none)

	int ScrollWindowEx(int dx, int dy,
				LPCRECT lpRectScroll, LPCRECT lpRectClip,
				CRgn* prgnUpdate, LPRECT lpRectUpdate, UINT flags);
	BOOL SetScrollInfo(int nBar, LPSCROLLINFO lpScrollInfo,
		BOOL bRedraw = TRUE);
	BOOL GetScrollInfo(int nBar, LPSCROLLINFO lpScrollInfo, UINT nMask = SIF_ALL);
	int GetScrollLimit(int nBar);

#if(WINVER >= 0x0500)

	BOOL GetScrollBarInfo(LONG idObject, PSCROLLBARINFO psbi) const;

#endif	// WINVER >= 0x0500

// Window Access Functions
	CWnd* ChildWindowFromPoint(POINT point) const;
	CWnd* ChildWindowFromPoint(POINT point, UINT nFlags) const;
	static CWnd* PASCAL FindWindow(LPCTSTR lpszClassName, LPCTSTR lpszWindowName);
	static CWnd* FindWindowEx(HWND hwndParent, HWND hwndChildAfter, LPCTSTR lpszClass, LPCTSTR lpszWindow);

	CWnd* GetNextWindow(UINT nFlag = GW_HWNDNEXT) const;
	CWnd* GetTopWindow() const;

	CWnd* GetWindow(UINT nCmd) const;
	CWnd* GetLastActivePopup() const;

	BOOL IsChild(const CWnd* pWnd) const;
	CWnd* GetParent() const;
	CWnd* SetParent(CWnd* pWndNewParent);
	static CWnd* PASCAL WindowFromPoint(POINT point);

// Alert Functions
	BOOL FlashWindow(BOOL bInvert);
#pragma push_macro("MessageBox")
#undef MessageBox
	int _AFX_FUNCNAME(MessageBox)(LPCTSTR lpszText, LPCTSTR lpszCaption = NULL,
			UINT nType = MB_OK);
	int MessageBox(LPCTSTR lpszText, LPCTSTR lpszCaption = NULL,
			UINT nType = MB_OK);
#pragma pop_macro("MessageBox")

#if(WINVER >= 0x0500)

	BOOL FlashWindowEx(DWORD dwFlags, UINT  uCount, DWORD dwTimeout);

#endif	// WINVER >= 0x0500

// Clipboard Functions
	BOOL ChangeClipboardChain(HWND hWndNext);
	HWND SetClipboardViewer();
	BOOL OpenClipboard();
	static CWnd* PASCAL GetClipboardOwner();
	static CWnd* PASCAL GetClipboardViewer();
	static CWnd* PASCAL GetOpenClipboardWindow();

// Caret Functions
	void CreateCaret(CBitmap* pBitmap);
	void CreateSolidCaret(int nWidth, int nHeight);
	void CreateGrayCaret(int nWidth, int nHeight);
	static CPoint PASCAL GetCaretPos();
	static void PASCAL SetCaretPos(POINT point);
	void HideCaret();
	void ShowCaret();

// Shell Interaction Functions
	void DragAcceptFiles(BOOL bAccept = TRUE);

// Icon Functions
	HICON SetIcon(HICON hIcon, BOOL bBigIcon);
	HICON GetIcon(BOOL bBigIcon) const;

// Context Help Functions
	BOOL SetWindowContextHelpId(DWORD dwContextHelpId);
	DWORD GetWindowContextHelpId() const;

// Dialog Data support
public:
	BOOL UpdateData(BOOL bSaveAndValidate = TRUE);
			// data wnd must be same type as this

// Help Command Handlers
	afx_msg void OnHelp();          // F1 (uses current context)
	afx_msg void OnHelpIndex();     // ID_HELP_INDEX
	afx_msg void OnHelpFinder();    // ID_HELP_FINDER, ID_DEFAULT_HELP
	afx_msg void OnHelpUsing();     // ID_HELP_USING
	virtual void WinHelp(DWORD_PTR dwData, UINT nCmd = HELP_CONTEXT);
	virtual void HtmlHelp(DWORD_PTR dwData, UINT nCmd = 0x000F);
	virtual void WinHelpInternal(DWORD_PTR dwData, UINT nCmd = HELP_CONTEXT);

// Layout and other functions
public:
	enum RepositionFlags
		{ reposDefault = 0, reposQuery = 1, reposExtra = 2, reposNoPosLeftOver=0x8000 };
	void RepositionBars(UINT nIDFirst, UINT nIDLast, UINT nIDLeftOver,
		UINT nFlag = reposDefault, LPRECT lpRectParam = NULL,
		LPCRECT lpRectClient = NULL, BOOL bStretch = TRUE);

	// dialog support
	void UpdateDialogControls(CCmdTarget* pTarget, BOOL bDisableIfNoHndler);
	void CenterWindow(CWnd* pAlternateOwner = NULL);
	int RunModalLoop(DWORD dwFlags = 0);
	virtual BOOL ContinueModal();
	virtual void EndModalLoop(int nResult);

#ifndef _AFX_NO_OCC_SUPPORT
// OLE control wrapper functions
   COleControlSite* GetOleControlSite(UINT idControl) const;
	void AFX_CDECL InvokeHelper(DISPID dwDispID, WORD wFlags,
		VARTYPE vtRet, void* pvRet, const BYTE* pbParamInfo, ...);
	void AFX_CDECL SetProperty(DISPID dwDispID, VARTYPE vtProp, ...);
	void GetProperty(DISPID dwDispID, VARTYPE vtProp, void* pvProp) const;
	IUnknown* GetDSCCursor();
	void BindDefaultProperty(DISPID dwDispID, VARTYPE vtProp, LPCTSTR szFieldName, CWnd* pDSCWnd);
	void BindProperty(DISPID dwDispId, CWnd* pWndDSC);
#endif

// Accessibility Support
public :
	void EnableActiveAccessibility();
	void NotifyWinEvent(DWORD event, LONG idObjectType, LONG idObject);

protected :
	bool m_bEnableActiveAccessibility;
	IAccessible* m_pStdObject;
	typedef VOID (WINAPI *PFNNOTIFYWINEVENT)(DWORD, HWND, LONG, LONG);
	static PFNNOTIFYWINEVENT m_pfnNotifyWinEvent;
	friend BOOL AFXAPI AfxWinInit(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance,
		_In_z_ LPTSTR lpCmdLine, _In_ int nCmdShow);

protected:
	IAccessibleProxy* m_pProxy;
	afx_msg LRESULT OnGetObject(WPARAM, LPARAM);

#ifndef _AFX_NO_OLE_SUPPORT
	DECLARE_INTERFACE_MAP()
#endif

	class XAccessible //: public IAccessible
	{	
	public:
#ifndef _AFX_NO_NESTED_DERIVATION
		size_t m_nOffset;
		XAccessible()
			{ m_nOffset = offsetof(CWnd, m_xAccessible); }
#endif
		virtual ULONG __stdcall AddRef(); 
		virtual ULONG __stdcall Release(); 
		virtual HRESULT __stdcall QueryInterface(REFIID iid, LPVOID* ppvObj); 
		virtual HRESULT __stdcall Invoke(DISPID, REFIID, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
		virtual HRESULT __stdcall GetIDsOfNames(REFIID, LPOLESTR *, UINT, LCID, DISPID *);
		virtual HRESULT __stdcall GetTypeInfoCount(unsigned int *);
		virtual HRESULT __stdcall GetTypeInfo(unsigned int, LCID, ITypeInfo**);
		virtual HRESULT __stdcall get_accParent(IDispatch **ppdispParent);
		virtual HRESULT __stdcall get_accChildCount(long *pcountChildren);
		virtual HRESULT __stdcall get_accChild(VARIANT varChild, IDispatch **ppdispChild);
		virtual HRESULT __stdcall get_accName(VARIANT varChild, BSTR *pszName);
		virtual HRESULT __stdcall get_accValue(VARIANT varChild, BSTR *pszValue);
		virtual HRESULT __stdcall get_accDescription(VARIANT varChild, BSTR *pszDescription);
		virtual HRESULT __stdcall get_accRole(VARIANT varChild, VARIANT *pvarRole);
		virtual HRESULT __stdcall get_accState(VARIANT varChild, VARIANT *pvarState);
		virtual HRESULT __stdcall get_accHelp(VARIANT varChild, BSTR *pszHelp);
		virtual HRESULT __stdcall get_accHelpTopic(BSTR *pszHelpFile, VARIANT varChild, long *pidTopic);
		virtual HRESULT __stdcall get_accKeyboardShortcut(VARIANT varChild, BSTR *pszKeyboardShortcut);
		virtual HRESULT __stdcall get_accFocus(VARIANT *pvarChild);
		virtual HRESULT __stdcall get_accSelection(VARIANT *pvarChildren);
		virtual HRESULT __stdcall get_accDefaultAction(VARIANT varChild, BSTR *pszDefaultAction);
		virtual HRESULT __stdcall accSelect(long flagsSelect, VARIANT varChild);
		virtual HRESULT __stdcall accLocation(long *pxLeft, long *pyTop, long *pcxWidth, long *pcyHeight, VARIANT varChild);
		virtual HRESULT __stdcall accNavigate(long navDir, VARIANT varStart, VARIANT *pvarEndUpAt);
		virtual HRESULT __stdcall accHitTest(long xLeft, long yTop, VARIANT *pvarChild);
		virtual HRESULT __stdcall accDoDefaultAction(VARIANT varChild);
		virtual HRESULT __stdcall put_accName(VARIANT varChild, BSTR szName);
		virtual HRESULT __stdcall put_accValue(VARIANT varChild, BSTR szValue);
	} m_xAccessible;
	friend class XAccessible; 

	class XAccessibleServer //: public IAccessibleServer
	{	
	public:
#ifndef _AFX_NO_NESTED_DERIVATION
		size_t m_nOffset;
		XAccessibleServer()
			{ m_nOffset = offsetof(CWnd, m_xAccessibleServer); }
#endif		
		virtual ULONG __stdcall AddRef(); 
		virtual ULONG __stdcall Release(); 
		virtual HRESULT __stdcall QueryInterface(REFIID iid, LPVOID* ppvObj); 
		virtual HRESULT __stdcall SetProxy(IAccessibleProxy *pProxy);
		virtual HRESULT __stdcall GetHWND(HWND *phWnd);
		virtual HRESULT __stdcall GetEnumVariant(IEnumVARIANT **ppEnumVariant);
	} m_xAccessibleServer;
	friend class XAccessibleServer;

public :
	virtual HRESULT EnsureStdObj();

	virtual HRESULT get_accParent(IDispatch **ppdispParent);
	virtual HRESULT get_accChildCount(long *pcountChildren);
	virtual HRESULT get_accChild(VARIANT varChild, IDispatch **ppdispChild);
	virtual HRESULT get_accName(VARIANT varChild, BSTR *pszName);
	virtual HRESULT get_accValue(VARIANT varChild, BSTR *pszValue);
	virtual HRESULT get_accDescription(VARIANT varChild, BSTR *pszDescription);
	virtual HRESULT get_accRole(VARIANT varChild, VARIANT *pvarRole);
	virtual HRESULT get_accState(VARIANT varChild, VARIANT *pvarState);
	virtual HRESULT get_accHelp(VARIANT varChild, BSTR *pszHelp);
	virtual HRESULT get_accHelpTopic(BSTR *pszHelpFile, VARIANT varChild, long *pidTopic);
	virtual HRESULT get_accKeyboardShortcut(VARIANT varChild, BSTR *pszKeyboardShortcut);
	virtual HRESULT get_accFocus(VARIANT *pvarChild);
	virtual HRESULT get_accSelection(VARIANT *pvarChildren);
	virtual HRESULT get_accDefaultAction(VARIANT varChild, BSTR *pszDefaultAction);
	virtual HRESULT accSelect(long flagsSelect, VARIANT varChild);
	virtual HRESULT accLocation(long *pxLeft, long *pyTop, long *pcxWidth, long *pcyHeight, VARIANT varChild);
	virtual HRESULT accNavigate(long navDir, VARIANT varStart, VARIANT *pvarEndUpAt);
	virtual HRESULT accHitTest(long xLeft, long yTop, VARIANT *pvarChild);
	virtual HRESULT accDoDefaultAction(VARIANT varChild);
	//Obsolete
	virtual HRESULT put_accName(VARIANT varChild, BSTR szName);
	//Obsolete
	virtual HRESULT put_accValue(VARIANT varChild, BSTR szValue);
	virtual HRESULT SetProxy(IAccessibleProxy *pProxy);
	virtual HRESULT CreateAccessibleProxy(WPARAM wParam, LPARAM lParam, LRESULT *pResult);

	// Helpers for windows that contain windowless controls
	long GetWindowLessChildCount();
	long GetWindowedChildCount();
	long GetAccessibleChildCount();
	HRESULT GetAccessibleChild(VARIANT varChild, IDispatch** ppdispChild);
	HRESULT GetAccessibleName(VARIANT varChild, BSTR* pszName);
	HRESULT GetAccessibilityLocation(VARIANT varChild, long *pxLeft, long *pyTop, long *pcxWidth, long *pcyHeight);
	HRESULT GetAccessibilityHitTest(long xLeft, long yTop, VARIANT *pvarChild);


// Window-Management message handler member functions
protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);

	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnActivateApp(BOOL bActive, DWORD dwThreadID);
	afx_msg LRESULT OnActivateTopLevel(WPARAM, LPARAM);
	afx_msg void OnCancelMode();
	afx_msg void OnChildActivate();
	afx_msg void OnClose();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint pos);
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	afx_msg void OnDestroy();
	afx_msg void OnEnable(BOOL bEnable);
	afx_msg void OnEndSession(BOOL bEnding);
	afx_msg void OnEnterIdle(UINT nWhy, CWnd* pWho);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg BOOL OnHelpInfo(HELPINFO* lpHelpInfo);
	afx_msg void OnIconEraseBkgnd(CDC* pDC);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg LRESULT OnMenuChar(UINT nChar, UINT nFlags, CMenu* pMenu);
	afx_msg void OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu);
	afx_msg void OnMove(int x, int y);
	afx_msg void OnPaint();
	afx_msg void OnSyncPaint();
	afx_msg void OnParentNotify(UINT message, LPARAM lParam);
	afx_msg UINT OnNotifyFormat(CWnd* pWnd, UINT nCommand);
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnQueryEndSession();
	afx_msg BOOL OnQueryNewPalette();
	afx_msg BOOL OnQueryOpen();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTCard(UINT idAction, DWORD dwActionData);
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg void OnSessionChange(UINT nSessionState, UINT nId);

	afx_msg void OnChangeUIState(UINT nAction, UINT nUIElement);
	afx_msg void OnUpdateUIState(UINT nAction, UINT nUIElement);
	afx_msg UINT OnQueryUIState();

// Nonclient-Area message handler member functions
	afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp);
	afx_msg BOOL OnNcCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnNcDestroy();
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnNcLButtonDblClk(UINT nHitTest, CPoint point);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnNcLButtonUp(UINT nHitTest, CPoint point);
	afx_msg void OnNcMButtonDblClk(UINT nHitTest, CPoint point);
	afx_msg void OnNcMButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnNcMButtonUp(UINT nHitTest, CPoint point);
	afx_msg void OnNcMouseHover(UINT nHitTest, CPoint point);
	afx_msg void OnNcMouseLeave();
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
	afx_msg void OnNcPaint();
	afx_msg void OnNcRButtonDblClk(UINT nHitTest, CPoint point);
	afx_msg void OnNcRButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnNcRButtonUp(UINT nHitTest, CPoint point);
	afx_msg void OnNcXButtonDown(short zHitTest, UINT nButton, CPoint point);
	afx_msg void OnNcXButtonUp(short zHitTest, UINT nButton, CPoint point);
	afx_msg void OnNcXButtonDblClk(short zHitTest, UINT nButton, CPoint point);

// System message handler member functions
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnPaletteIsChanging(CWnd* pRealizeWnd);
	afx_msg void OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnSysDeadChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnAppCommand(CWnd* pWnd, UINT nCmd, UINT nDevice, UINT nKey);
#if(_WIN32_WINNT >= 0x0501)
	afx_msg void OnRawInput(UINT nInputCode, HRAWINPUT hRawInput);
#endif
	afx_msg void OnCompacting(UINT nCpuTime);
	afx_msg void OnDevModeChange(_In_z_ LPTSTR lpDeviceName);
	afx_msg void OnFontChange();
	afx_msg void OnPaletteChanged(CWnd* pFocusWnd);
	afx_msg void OnSpoolerStatus(UINT nStatus, UINT nJobs);
	afx_msg void OnSysColorChange();
	afx_msg void OnTimeChange();
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	afx_msg void OnWinIniChange(LPCTSTR lpszSection);
	afx_msg UINT OnPowerBroadcast(UINT nPowerEvent, UINT nEventData);
	afx_msg void OnUserChanged();
	afx_msg void OnInputLangChange(UINT nCharSet, UINT nLocaleId);
	afx_msg void OnInputLangChangeRequest(UINT nFlags, UINT nLocaleId);
	afx_msg void OnInputDeviceChange(unsigned short nFlags);

// Input message handler member functions
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnDeadChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnUniChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnXButtonDblClk(UINT nFlags, UINT nButton, CPoint point);
	afx_msg void OnXButtonDown(UINT nFlags, UINT nButton, CPoint point);
	afx_msg void OnXButtonUp(UINT nFlags, UINT nButton, CPoint point);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseHWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnTimer(UINT_PTR nIDEvent);

// Initialization message handler member functions
	afx_msg void OnInitMenu(CMenu* pMenu);
	afx_msg void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu);
	afx_msg void OnUnInitMenuPopup(CMenu* pPopupMenu, UINT nFlags);

// Clipboard message handler member functions
	afx_msg void OnAskCbFormatName(_In_ UINT nMaxCount, _Out_z_cap_(nMaxCount) LPTSTR lpszString);
	afx_msg void OnChangeCbChain(HWND hWndRemove, HWND hWndAfter);
	afx_msg void OnDestroyClipboard();
	afx_msg void OnDrawClipboard();
	afx_msg void OnHScrollClipboard(CWnd* pClipAppWnd, UINT nSBCode, UINT nPos);
	afx_msg void OnPaintClipboard(CWnd* pClipAppWnd, HGLOBAL hPaintStruct);
	afx_msg void OnRenderAllFormats();
	afx_msg void OnRenderFormat(UINT nFormat);
	afx_msg void OnSizeClipboard(CWnd* pClipAppWnd, HGLOBAL hRect);
	afx_msg void OnVScrollClipboard(CWnd* pClipAppWnd, UINT nSBCode, UINT nPos);
	afx_msg void OnClipboardUpdate();

// Control message handler member functions
	afx_msg int OnCompareItem(int nIDCtl, LPCOMPAREITEMSTRUCT lpCompareItemStruct);
	afx_msg void OnDeleteItem(int nIDCtl, LPDELETEITEMSTRUCT lpDeleteItemStruct);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg UINT OnGetDlgCode();
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg int OnCharToItem(UINT nChar, CListBox* pListBox, UINT nIndex);
	afx_msg int OnVKeyToItem(UINT nKey, CListBox* pListBox, UINT nIndex);

// MDI message handler member functions
	afx_msg void OnMDIActivate(BOOL bActivate,
		CWnd* pActivateWnd, CWnd* pDeactivateWnd);

// Menu loop notification messages
	afx_msg void OnEnterMenuLoop(BOOL bIsTrackPopupMenu);
	afx_msg void OnExitMenuLoop(BOOL bIsTrackPopupMenu);
	afx_msg void OnMenuRButtonUp(UINT nPos, CMenu* pMenu);
	afx_msg UINT OnMenuDrag(UINT nPos, CMenu* pMenu);
#if(WINVER >= 0x0500)
	afx_msg UINT OnMenuGetObject(MENUGETOBJECTINFO* pMenuGetObjectInfo);
#endif
	afx_msg void OnMenuCommand(UINT nPos, CMenu* pMenu);
	afx_msg void OnNextMenu(UINT nKey, LPMDINEXTMENU lpMdiNextMenu);

// Win4 messages
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	afx_msg void OnStyleChanging(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	afx_msg void OnSizing(UINT nSide, LPRECT lpRect);
	afx_msg void OnMoving(UINT nSide, LPRECT lpRect);
	afx_msg void OnEnterSizeMove();
	afx_msg void OnExitSizeMove();
	afx_msg void OnCaptureChanged(CWnd* pWnd);
	afx_msg BOOL OnDeviceChange(UINT nEventType, DWORD_PTR dwData);

// Desktop Windows Manager messages
	afx_msg void OnCompositionChanged();
	afx_msg void OnNcRenderingChanged(BOOL bIsRendering);
	afx_msg void OnColorizationColorChanged(DWORD dwColorizationColor, BOOL bOpacity);
	afx_msg void OnWindowMaximizedChange(BOOL bIsMaximized);

// Overridables and other helpers (for implementation of derived classes)
protected:
	// for deriving from a standard control
	virtual WNDPROC* GetSuperWndProcAddr();

	// for dialog data exchange and validation
	virtual void DoDataExchange(CDataExchange* pDX);

public:
	// for modality
	virtual void BeginModalState();
	virtual void EndModalState();

	// for translating Windows messages in main message pump
	virtual BOOL PreTranslateMessage(MSG* pMsg);

#ifndef _AFX_NO_OCC_SUPPORT
	// for ambient properties exposed to contained OLE controls
	virtual BOOL OnAmbientProperty(COleControlSite* pSite, DISPID dispid,
		VARIANT* pvar);
#endif

protected:
	// for processing Windows messages
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);

	// for handling default processing
	LRESULT Default();
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);

	// for custom cleanup after WM_NCDESTROY
	virtual void PostNcDestroy();

	// for notifications from parent
	virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
		// return TRUE if parent should not process this message
	BOOL ReflectChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	static BOOL PASCAL ReflectLastMsg(HWND hWndChild, LRESULT* pResult = NULL);

// Implementation
public:
	virtual ~CWnd();
	virtual BOOL CheckAutoCenter();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	static BOOL PASCAL GrayCtlColor(HDC hDC, HWND hWnd, UINT nCtlColor,
		HBRUSH hbrGray, COLORREF clrText);

	// helper routines for implementation
	BOOL HandleFloatingSysCommand(UINT nID, LPARAM lParam);
	BOOL IsTopParentActive() const;
	void ActivateTopParent();
	static BOOL PASCAL WalkPreTranslateTree(HWND hWndStop, MSG* pMsg);
	static CWnd* PASCAL GetDescendantWindow(HWND hWnd, int nID,
		BOOL bOnlyPerm);
	static void PASCAL SendMessageToDescendants(HWND hWnd, UINT message,
		WPARAM wParam, LPARAM lParam, BOOL bDeep, BOOL bOnlyPerm);
	virtual BOOL IsFrameWnd() const; // IsKindOf(RUNTIME_CLASS(CFrameWnd)))
	virtual void OnFinalRelease();
	BOOL PreTranslateInput(LPMSG lpMsg);
	static BOOL PASCAL ModifyStyle(HWND hWnd, DWORD dwRemove, DWORD dwAdd,
		UINT nFlags);
	static BOOL PASCAL ModifyStyleEx(HWND hWnd, DWORD dwRemove, DWORD dwAdd,
		UINT nFlags);
	static void PASCAL _FilterToolTipMessage(MSG* pMsg, CWnd* pWnd);
	BOOL _EnableToolTips(BOOL bEnable, UINT nFlag);
	static HWND PASCAL GetSafeOwner_(HWND hWnd, HWND* pWndTop);
	void PrepareForHelp();

	COleControlContainer* GetControlContainer();

public:
	HWND m_hWndOwner;   // implementation of SetOwner and GetOwner
	UINT m_nFlags;      // see WF_ flags above

protected:
	WNDPROC m_pfnSuper; // for subclassing of controls
	static const UINT m_nMsgDragList;
	int m_nModalResult; // for return values from CWnd::RunModalLoop

	COleDropTarget* m_pDropTarget;  // for automatic cleanup of drop target
	friend class COleDropTarget;
	friend class CFrameWnd;

	// for creating dialogs and dialog-like windows
	BOOL CreateDlg(LPCTSTR lpszTemplateName, CWnd* pParentWnd);
	BOOL CreateDlgIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd* pParentWnd,
		HINSTANCE hInst);

#ifndef _AFX_NO_OCC_SUPPORT
	COleControlContainer* m_pCtrlCont;  // for containing OLE controls
	COleControlSite* m_pCtrlSite;       // for wrapping an OLE control
	friend class COccManager;
	friend class COleControlSite;
	friend class COleControlContainer;
	BOOL InitControlContainer(BOOL bCreateFromResource=FALSE);
   virtual BOOL CreateControlContainer(COleControlContainer** ppContainer);
   virtual BOOL CreateControlSite(COleControlContainer* pContainer, 
	  COleControlSite** ppSite, UINT nID, REFCLSID clsid);
	virtual BOOL SetOccDialogInfo(struct _AFX_OCC_DIALOG_INFO* pOccDialogInfo);
	virtual _AFX_OCC_DIALOG_INFO* GetOccDialogInfo();
	void AttachControlSite(CHandleMap* pMap);
public:
	void AttachControlSite(CWnd* pWndParent, UINT nIDC = 0);
	COleControlSite* GetControlSite() const
	{
		return m_pCtrlSite;
	}
#endif

protected:
	// implementation of message dispatch/hooking
	friend LRESULT CALLBACK _AfxSendMsgHook(int, WPARAM, LPARAM);
	friend void AFXAPI _AfxStandardSubclass(HWND);
	friend LRESULT CALLBACK _AfxCbtFilterHook(int, WPARAM, LPARAM);
	friend LRESULT AFXAPI AfxCallWndProc(CWnd*, HWND, UINT, WPARAM, LPARAM);

	// standard message implementation
	afx_msg LRESULT OnNTCtlColor(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDisplayChange(WPARAM, LPARAM);
	afx_msg LRESULT OnDragList(WPARAM, LPARAM);

	// Helper functions for retrieving Text from windows messsage / structure
	// -----------------------------------------------------------------------
	// errCode  - the errCode for the window message, uMsg
	// pszText  - buffer to grow and retrieve the text (do not allocate when calling, the function will allocate)
	// cch      - size of the buffer in TCHAR to be pass to the windows message, uMsg
	// cchBegin - initial size to allocate
	// cchEnd   - maximum size to allocate
	// uMsg     - window message 
	// lParam   - the LPARAM of the message.  This is pass by reference because it could potentially be alias of pszText/cch for some messages.
	// wParam   - the WPARAM of the message.  This is pass by reference because it could potentially be alias of pszText/cch for some messages.
	// strOut   - the CString containing the received text

	template <class TReturnType, class TCchType >
	TReturnType EnlargeBufferGetText(_In_ TReturnType errCode, LPTSTR& pszText, TCchType& cch, TCchType cchBegin, TCchType cchEnd, UINT uMsg, WPARAM& wParam, LPARAM& lParam, CString& strOut) const throw(...)
	{
		ENSURE(::IsWindow(m_hWnd));
		ENSURE(cchBegin < cchEnd);
		ENSURE(cchEnd <= INT_MAX); // CString only support up to INT_MAX
		TReturnType retCode = errCode;
		strOut = CString("");
		cch = cchBegin;
		do 
		{
			pszText = strOut.GetBufferSetLength(cch);
			retCode = static_cast<TReturnType>(this->SendMessage(uMsg, wParam, lParam));
			strOut.ReleaseBuffer();
			pszText = NULL;

			if (retCode == errCode)
			{
				// error clear the string and return error
				strOut = CString("");
				cch=0;
				break;
			}
			if (static_cast<TCchType>(strOut.GetLength()) < cch-1)
			{
				cch = strOut.GetLength();
				break;
			}
		}
		while( (::ATL::AtlMultiply(&cch, cch, 2) == S_OK) && (cch < cchEnd));
		return retCode;
	}


	template <class TReturnType>
	inline TReturnType EnlargeBufferGetText(TReturnType errCode, LPTSTR& pszText, int& pcch, UINT uMsg, WPARAM& wParam, LPARAM& lParam, CString& strOut) const throw(...)
	{
		return EnlargeBufferGetText<TReturnType, int>(errCode, pszText, pcch, 256, INT_MAX, uMsg, wParam, lParam, strOut);
	}

	template <class TReturnType>
	inline TReturnType EnlargeBufferGetText(TReturnType errCode, LPTSTR& pszText, UINT& pcch, UINT uMsg, WPARAM& wParam, LPARAM& lParam, CString& strOut) const throw(...)
	{
		// using INT_MAX instead of UINT_MAX here because CString has a INT_MAX limit
		return EnlargeBufferGetText<TReturnType, UINT>(errCode, pszText, pcch, 256, INT_MAX, uMsg, wParam, lParam, strOut);
	}

	//{{AFX_MSG(CWnd)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CWnd(HWND hWnd);    // just for special initialization
};

// helpers for registering your own WNDCLASSes
LPCTSTR AFXAPI AfxRegisterWndClass(UINT nClassStyle,
	HCURSOR hCursor = 0, HBRUSH hbrBackground = 0, HICON hIcon = 0);

BOOL AFXAPI AfxRegisterClass(WNDCLASS* lpWndClass);

// helper to initialize rich edit 1.0 control
BOOL AFXAPI AfxInitRichEdit();
// helper to initialize rich edit 2.0 control
BOOL AFXAPI AfxInitRichEdit2();

// Implementation
LRESULT CALLBACK AfxWndProc(HWND, UINT, WPARAM, LPARAM);

WNDPROC AFXAPI AfxGetAfxWndProc();
#define AfxWndProc (*AfxGetAfxWndProc())

typedef void (AFX_MSG_CALL CWnd::*AFX_PMSGW)(void);
	// like 'AFX_PMSG' but for CWnd derived classes only

typedef void (AFX_MSG_CALL CWinThread::*AFX_PMSGT)(void);
	// like 'AFX_PMSG' but for CWinThread-derived classes only

/////////////////////////////////////////////////////////////////////////////
// CDialog - a modal or modeless dialog
class CDialog : public CWnd
{
	DECLARE_DYNAMIC(CDialog)

	// Modeless construct
public:
	CDialog();

	virtual BOOL Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
	virtual BOOL Create(UINT nIDTemplate, CWnd* pParentWnd = NULL);
	virtual BOOL CreateIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd* pParentWnd = NULL,
		void* lpDialogInit = NULL);
	virtual BOOL CreateIndirect(HGLOBAL hDialogTemplate, CWnd* pParentWnd = NULL);

	// Modal construct
public:
	explicit CDialog(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
	explicit CDialog(UINT nIDTemplate, CWnd* pParentWnd = NULL);
	BOOL InitModalIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd* pParentWnd = NULL,
		void* lpDialogInit = NULL);
	BOOL InitModalIndirect(HGLOBAL hDialogTemplate, CWnd* pParentWnd = NULL);

// Attributes
public:
	void MapDialogRect(LPRECT lpRect) const;
	void SetHelpID(UINT nIDR);

// Operations
public:
	// modal processing
	virtual INT_PTR DoModal();

	// support for passing on tab control - use 'PostMessage' if needed
	void NextDlgCtrl() const;
	void PrevDlgCtrl() const;
	void GotoDlgCtrl(CWnd* pWndCtrl);

	// default button access
	void SetDefID(UINT nID);
	DWORD GetDefID() const;

	// termination
	void EndDialog(int nResult);

// Overridables (special message map entries)
	virtual BOOL OnInitDialog();
	virtual void OnSetFont(CFont* pFont);
protected:
	virtual void OnOK();
	virtual void OnCancel();

// Implementation
public:
	virtual ~CDialog();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra,
		AFX_CMDHANDLERINFO* pHandlerInfo);
	virtual BOOL CheckAutoCenter();

protected:
	UINT m_nIDHelp;                 // Help ID (0 for none, see HID_BASE_RESOURCE)

	// parameters for 'DoModal'
	LPCTSTR m_lpszTemplateName;     // name or MAKEINTRESOURCE
	HGLOBAL m_hDialogTemplate;      // indirect (m_lpDialogTemplate == NULL)
	LPCDLGTEMPLATE m_lpDialogTemplate;  // indirect if (m_lpszTemplateName == NULL)
	void* m_lpDialogInit;           // DLGINIT resource data
	CWnd* m_pParentWnd;             // parent/owner window
	HWND m_hWndTop;                 // top level parent window (may be disabled)

#ifndef _AFX_NO_OCC_SUPPORT
	_AFX_OCC_DIALOG_INFO* m_pOccDialogInfo;
	virtual BOOL SetOccDialogInfo(_AFX_OCC_DIALOG_INFO* pOccDialogInfo);
	virtual _AFX_OCC_DIALOG_INFO* GetOccDialogInfo();
#endif
	virtual void PreInitDialog();

	// implementation helpers
	HWND PreModal();
	void PostModal();

	BOOL CreateIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd* pParentWnd,
		void* lpDialogInit, HINSTANCE hInst);
	BOOL CreateIndirect(HGLOBAL hDialogTemplate, CWnd* pParentWnd,
		HINSTANCE hInst);

protected:
	//{{AFX_MSG(CDialog)
	afx_msg LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnHelpHitTest(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT HandleInitDialog(WPARAM, LPARAM);
	afx_msg LRESULT HandleSetFont(WPARAM, LPARAM);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

// all CModalDialog functionality is now in CDialog
#define CModalDialog    CDialog

/////////////////////////////////////////////////////////////////////////////
// Standard Windows controls

class CStatic : public CWnd
{
	DECLARE_DYNAMIC(CStatic)

// Constructors
public:
	CStatic();
	virtual BOOL Create(LPCTSTR lpszText, DWORD dwStyle,
				const RECT& rect, CWnd* pParentWnd, UINT nID = 0xffff);

// Operations
	HICON SetIcon(HICON hIcon);
	HICON GetIcon() const;

	HENHMETAFILE SetEnhMetaFile(HENHMETAFILE hMetaFile);
	HENHMETAFILE GetEnhMetaFile() const;
	HBITMAP SetBitmap(HBITMAP hBitmap);
	HBITMAP GetBitmap() const;
	HCURSOR SetCursor(HCURSOR hCursor);
	HCURSOR GetCursor();

// Overridables (for owner draw only)
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

// Implementation
public:
	virtual ~CStatic();
protected:
	virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);
};

class CButton : public CWnd
{
	DECLARE_DYNAMIC(CButton)

// Constructors
public:
	CButton();
	virtual BOOL Create(LPCTSTR lpszCaption, DWORD dwStyle,
				const RECT& rect, CWnd* pParentWnd, UINT nID);

// Attributes
	UINT GetState() const;
	void SetState(BOOL bHighlight);
	int GetCheck() const;
	void SetCheck(int nCheck);
	UINT GetButtonStyle() const;
	void SetButtonStyle(UINT nStyle, BOOL bRedraw = TRUE);

	HICON SetIcon(HICON hIcon);
	HICON GetIcon() const;
	HBITMAP SetBitmap(HBITMAP hBitmap);
	HBITMAP GetBitmap() const;
	HCURSOR SetCursor(HCURSOR hCursor);
	HCURSOR GetCursor();

#if (_WIN32_WINNT >= 0x501)
	AFX_ANSI_DEPRECATED BOOL GetIdealSize(_Out_ LPSIZE psize) const;
	AFX_ANSI_DEPRECATED BOOL SetImageList(_In_ PBUTTON_IMAGELIST pbuttonImagelist);
	AFX_ANSI_DEPRECATED BOOL GetImageList(_In_ PBUTTON_IMAGELIST pbuttonImagelist) const;
	AFX_ANSI_DEPRECATED BOOL SetTextMargin(_In_ LPRECT pmargin);
	AFX_ANSI_DEPRECATED BOOL GetTextMargin(_Out_ LPRECT pmargin) const;
#endif  // (_WIN32_WINNT >= 0x501)

#if ( _WIN32_WINNT >= 0x0600 ) && defined(UNICODE)
	CString GetNote() const;
	_Check_return_ BOOL GetNote(_Out_z_cap_(*pcchNote) LPTSTR lpszNote, _Inout_ UINT* pcchNote) const;
	BOOL SetNote(_In_z_ LPCTSTR lpszNote);
	UINT GetNoteLength() const;
	BOOL GetSplitInfo(_Out_ PBUTTON_SPLITINFO pInfo) const;
	BOOL SetSplitInfo(_In_ PBUTTON_SPLITINFO pInfo);
	UINT GetSplitStyle() const;
	BOOL SetSplitStyle(_In_ UINT nStyle);
	BOOL GetSplitSize(_Out_ LPSIZE pSize) const;
	BOOL SetSplitSize(_In_ LPSIZE pSize);
	CImageList* GetSplitImageList() const;
	BOOL SetSplitImageList(_In_ CImageList* pSplitImageList);
	TCHAR GetSplitGlyph() const;
	BOOL SetSplitGlyph(_In_ TCHAR chGlyph);
	BOOL SetDropDownState(_In_ BOOL fDropDown);

	// Sets whether the action associated with the button requires elevated permissions.
	// If elevated permissions are required then the button should display an elevated icon.
	HICON SetShield(_In_ BOOL fElevationRequired);
#endif // ( _WIN32_WINNT >= 0x600 ) && defined(UNICODE)

// Overridables (for owner draw only)
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

// Implementation
public:
	virtual ~CButton();
protected:
	virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);
};

#if (_WIN32_WINNT >= 0x600) && defined(UNICODE)
class CSplitButton : public CButton
{
	DECLARE_DYNAMIC(CSplitButton)

// Constructors
public:
	CSplitButton();
	CSplitButton(UINT nMenuId, UINT nSubMenuId);
	CSplitButton(CMenu* pMenu);

	~CSplitButton();

	virtual BOOL Create(LPCTSTR lpszCaption, DWORD dwStyle,
				const RECT& rect, CWnd* pParentWnd, UINT nID);

	void SetDropDownMenu(UINT nMenuId, UINT nSubMenuId);
	void SetDropDownMenu(CMenu* pMenu);

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnDropDown(NMHDR* /*pNMHDR*/, LRESULT *pResult);

	void Cleanup();

	CMenu * m_pMenu;
	UINT m_nMenuId;
	UINT m_nSubMenuId;
};

#endif // (_WIN32_WINNT >= 0x600) && defined(CSplitButton)

class CListBox : public CWnd
{
	DECLARE_DYNAMIC(CListBox)

// Constructors
public:
	CListBox();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

// Attributes

	// for entire listbox
	int GetCount() const;
	int GetHorizontalExtent() const;
	void SetHorizontalExtent(int cxExtent);
	int GetTopIndex() const;
	int SetTopIndex(int nIndex);
	LCID GetLocale() const;
	LCID SetLocale(LCID nNewLocale);
	int InitStorage(int nItems, UINT nBytes);
	UINT ItemFromPoint(CPoint pt, BOOL& bOutside) const;

#if(WINVER >= 0x0500)
	DWORD GetListBoxInfo() const;
#endif	// WINVER >= 0x0500	

	// for single-selection listboxes
	int GetCurSel() const;
	int SetCurSel(int nSelect);

	// for multiple-selection listboxes
	int GetSel(int nIndex) const;           // also works for single-selection
	int SetSel(int nIndex, BOOL bSelect = TRUE);
	int GetSelCount() const;
	int GetSelItems(int nMaxItems, LPINT rgIndex) const;
	void SetAnchorIndex(int nIndex);
	int GetAnchorIndex() const;

	// for listbox items
	DWORD_PTR GetItemData(int nIndex) const;
	int SetItemData(int nIndex, DWORD_PTR dwItemData);
	void* GetItemDataPtr(int nIndex) const;
	int SetItemDataPtr(int nIndex, void* pData);
	int GetItemRect(int nIndex, LPRECT lpRect) const;
	int GetText(_In_ int nIndex, _Pre_notnull_ _Post_z_ LPTSTR lpszBuffer) const;
	void GetText(int nIndex, CString& rString) const;
	int GetTextLen(int nIndex) const;

	// Settable only attributes
	void SetColumnWidth(int cxWidth);
	BOOL SetTabStops(int nTabStops, LPINT rgTabStops);
	void SetTabStops();
	BOOL SetTabStops(const int& cxEachStop);    // takes an 'int'

	int SetItemHeight(int nIndex, UINT cyItemHeight);
	int GetItemHeight(int nIndex) const;
	int FindStringExact(int nIndexStart, LPCTSTR lpszFind) const;
	int GetCaretIndex() const;
	int SetCaretIndex(int nIndex, BOOL bScroll = TRUE);

// Operations
	// manipulating listbox items
	int AddString(LPCTSTR lpszItem);
	int DeleteString(UINT nIndex);
	int InsertString(int nIndex, LPCTSTR lpszItem);
	void ResetContent();
	int Dir(UINT attr, LPCTSTR lpszWildCard);

	// selection helpers
	int FindString(int nStartAfter, LPCTSTR lpszItem) const;
	int SelectString(int nStartAfter, LPCTSTR lpszItem);
	int SelItemRange(BOOL bSelect, int nFirstItem, int nLastItem);

// Overridables (must override draw, measure and compare for owner draw)
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	virtual int CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
	virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
	virtual int VKeyToItem(UINT nKey, UINT nIndex);
	virtual int CharToItem(UINT nKey, UINT nIndex);

// Implementation
public:
	virtual ~CListBox();
protected:
	virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);
};

class CCheckListBox : public CListBox
{
	DECLARE_DYNAMIC(CCheckListBox)

// Constructors
public:
	CCheckListBox();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

// Attributes
	void SetCheckStyle(UINT nStyle);
	UINT GetCheckStyle();
	void SetCheck(int nIndex, int nCheck);
	int GetCheck(int nIndex);
	void Enable(int nIndex, BOOL bEnabled = TRUE);
	BOOL IsEnabled(int nIndex);

	virtual CRect OnGetCheckPosition(CRect rectItem, CRect rectCheckBox);

// Overridables (must override draw, measure and compare for owner draw)
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);

// Implementation
protected:
	void PreDrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	void PreMeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	int PreCompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
	void PreDeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
	bool PreDrawItemThemed(CDC* pDC, DRAWITEMSTRUCT &drawItem, int nCheck, int cyItem);
	void PreDrawItemNonThemed(CDC* pDC, DRAWITEMSTRUCT &drawItem, int nCheck, int cyItem);
	void PreDrawItemHelper(LPDRAWITEMSTRUCT lpDrawItemStruct);	

	virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);

   void SetSelectionCheck( int nCheck );

// Active Accessibility
	virtual HRESULT get_accRole(VARIANT varChild, VARIANT *pvarRole);
	virtual HRESULT get_accState(VARIANT varChild, VARIANT *pvarState);
	virtual HRESULT get_accDefaultAction(VARIANT varChild, BSTR *pszDefaultAction);
	virtual HRESULT accDoDefaultAction(VARIANT varChild);

#ifdef _DEBUG
	virtual void PreSubclassWindow();
#endif

	int CalcMinimumItemHeight();
	void InvalidateCheck(int nIndex);
	void InvalidateItem(int nIndex);
	int CheckFromPoint(CPoint point, BOOL& bInCheck);

	int m_cyText;
	UINT m_nStyle;

	// Message map functions
protected:
	//{{AFX_MSG(CCheckListBox)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg LRESULT OnSetFont(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBAddString(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBFindString(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBFindStringExact(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBGetItemData(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBGetText(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBInsertString(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBSelectString(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBSetItemData(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLBSetItemHeight(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

class CComboBox : public CWnd
{
	DECLARE_DYNAMIC(CComboBox)

// Constructors
public:
	CComboBox();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

// Attributes
	// for entire combo box
	int GetCount() const;
	int GetCurSel() const;
	int SetCurSel(int nSelect);
	LCID GetLocale() const;
	LCID SetLocale(LCID nNewLocale);
// Win4
	int GetTopIndex() const;
	int SetTopIndex(int nIndex);
	int InitStorage(int nItems, UINT nBytes);
	void SetHorizontalExtent(UINT nExtent);
	UINT GetHorizontalExtent() const;
	int SetDroppedWidth(UINT nWidth);
	int GetDroppedWidth() const;

#if(WINVER >= 0x0500)
	BOOL GetComboBoxInfo(PCOMBOBOXINFO pcbi) const;
#endif	// WINVER >= 0x0500

#if (_WIN32_WINNT >= 0x501) && defined(UNICODE)
	// Sets the minimum number of visible items in the drop-down list of the combo box.
	BOOL SetMinVisibleItems(_In_ int iMinVisible);

	// Retrieves the minimum number of visible items in the drop-down list of the combo box.
	int GetMinVisible() const;

#ifdef CB_SETCUEBANNER
	// REVIEW: Sets the cue banner text displayed in the edit control of the combo box.
	BOOL SetCueBanner(_In_z_ LPCTSTR lpszText);

	// REVIEW: Retrieves the cue banner text displayed in the edit control of the combo box.
	CString GetCueBanner() const;
	BOOL GetCueBanner(_Out_z_cap_(cchText) LPTSTR lpszText, _In_ int cchText) const;
#endif  // CB_SETCUEBANNER
#endif  // (_WIN32_WINNT >= 0x501) && defined(UNICODE)

	// for edit control
	DWORD GetEditSel() const;
	BOOL LimitText(int nMaxChars);
	BOOL SetEditSel(int nStartChar, int nEndChar);

	// for combobox item
	DWORD_PTR GetItemData(int nIndex) const;
	int SetItemData(int nIndex, DWORD_PTR dwItemData);
	void* GetItemDataPtr(int nIndex) const;
	int SetItemDataPtr(int nIndex, void* pData);
	int GetLBText(_In_ int nIndex, _Pre_notnull_ _Post_z_ LPTSTR lpszText) const;
	void GetLBText(int nIndex, CString& rString) const;
	int GetLBTextLen(int nIndex) const;

	int SetItemHeight(int nIndex, UINT cyItemHeight);
	int GetItemHeight(int nIndex) const;
	int FindStringExact(int nIndexStart, LPCTSTR lpszFind) const;
	int SetExtendedUI(BOOL bExtended = TRUE);
	BOOL GetExtendedUI() const;
	void GetDroppedControlRect(LPRECT lprect) const;
	BOOL GetDroppedState() const;

// Operations
	// for drop-down combo boxes
	void ShowDropDown(BOOL bShowIt = TRUE);

	// manipulating listbox items
	int AddString(LPCTSTR lpszString);
	int DeleteString(UINT nIndex);
	int InsertString(int nIndex, LPCTSTR lpszString);
	void ResetContent();
	int Dir(UINT attr, LPCTSTR lpszWildCard);

	// selection helpers
	int FindString(int nStartAfter, LPCTSTR lpszString) const;
	int SelectString(int nStartAfter, LPCTSTR lpszString);

	// Clipboard operations
	void Clear();
	void Copy();
	void Cut();
	void Paste();

// Overridables (must override draw, measure and compare for owner draw)
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	virtual int CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
	virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);

// Implementation
public:
	virtual ~CComboBox();
protected:
	virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);
};

// NOTE: This class must remain a binary-compatible subset
// of CEditView. Do not add data members or virtual functions
// directly to this class.
class CEdit : public CWnd
{
	// DECLARE_DYNAMIC virtual OK - CWnd already has DECLARE_DYNAMIC
	DECLARE_DYNAMIC(CEdit)

// Constructors
public:
	CEdit();
	BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

// Attributes
	BOOL CanUndo() const;
	int GetLineCount() const;
	BOOL GetModify() const;
	void SetModify(BOOL bModified = TRUE);
	void GetRect(LPRECT lpRect) const;
	DWORD GetSel() const;
	void GetSel(int& nStartChar, int& nEndChar) const;
	HLOCAL GetHandle() const;
	void SetHandle(HLOCAL hBuffer);
	void SetMargins(UINT nLeft, UINT nRight);
	DWORD GetMargins() const;
	void SetLimitText(UINT nMax);
	UINT GetLimitText() const;
	CPoint PosFromChar(UINT nChar) const;
	int CharFromPos(CPoint pt) const;

	// NOTE: first word in lpszBuffer must contain the size of the buffer!
	// NOTE: may not return null character
	int GetLine(_In_ int nIndex, _Out_ LPTSTR lpszBuffer) const;
	// NOTE: may not return null character
	int GetLine(_In_ int nIndex, _Out_cap_post_count_(nMaxLength, return) LPTSTR lpszBuffer, _In_ int nMaxLength) const;

#if (_WIN32_WINNT >= 0x501)
	AFX_ANSI_DEPRECATED BOOL SetCueBanner(_In_z_ LPCWSTR lpszText, _In_ BOOL fDrawIfFocused = FALSE);
	AFX_ANSI_DEPRECATED BOOL GetCueBanner(_Out_z_cap_(cchText) LPWSTR lpszText, _In_ int cchText) const;

#if defined(UNICODE)
	CString GetCueBanner() const;

	BOOL ShowBalloonTip(_In_z_ LPCWSTR lpszTitle, _In_z_ LPCWSTR lpszText, _In_ INT ttiIcon = TTI_NONE);
	BOOL ShowBalloonTip(_In_ PEDITBALLOONTIP pEditBalloonTip);
	BOOL HideBalloonTip();
#endif  // (UNICODE)
#endif  // (_WIN32_WINNT >= 0x501)

#if (_WIN32_WINNT >= 0x0600) && defined(UNICODE)
	// REVIEW: Sets the characters in the edit control that are highlighted.
	void SetHighlight(_In_ int ichStart, _In_ int ichEnd);

	// REVIEW: Retrieves the characters in the edit control that are highlighted.
	BOOL GetHighlight(_Out_ int* pichStart, _Out_ int* pichEnd) const;
#endif  // (_WIN32_WINNT >= 0x0600) && defined(UNICODE)

// Operations
	void EmptyUndoBuffer();
	BOOL FmtLines(BOOL bAddEOL);

	void LimitText(int nChars = 0);
	int LineFromChar(int nIndex = -1) const;
	int LineIndex(int nLine = -1) const;
	int LineLength(int nLine = -1) const;
	void LineScroll(int nLines, int nChars = 0);
	void ReplaceSel(LPCTSTR lpszNewText, BOOL bCanUndo = FALSE);
	void SetPasswordChar(TCHAR ch);
	void SetRect(LPCRECT lpRect);
	void SetRectNP(LPCRECT lpRect);
	void SetSel(DWORD dwSelection, BOOL bNoScroll = FALSE);
	void SetSel(int nStartChar, int nEndChar, BOOL bNoScroll = FALSE);
	BOOL SetTabStops(int nTabStops, LPINT rgTabStops);
	void SetTabStops();
	BOOL SetTabStops(const int& cxEachStop);    // takes an 'int'

	// Clipboard operations
	BOOL Undo();
	void Clear();
	void Copy();
	void Cut();
	void Paste();

	BOOL SetReadOnly(BOOL bReadOnly = TRUE);
	int GetFirstVisibleLine() const;
	TCHAR GetPasswordChar() const;

// Implementation
public:
	// virtual OK here - ~CWnd already virtual
	virtual ~CEdit();
};

class CScrollBar : public CWnd
{
	DECLARE_DYNAMIC(CScrollBar)

// Constructors
public:
	CScrollBar();
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

// Attributes
	int GetScrollPos() const;
	int SetScrollPos(int nPos, BOOL bRedraw = TRUE);
	void GetScrollRange(LPINT lpMinPos, LPINT lpMaxPos) const;
	void SetScrollRange(int nMinPos, int nMaxPos, BOOL bRedraw = TRUE);
	void ShowScrollBar(BOOL bShow = TRUE);

	BOOL EnableScrollBar(UINT nArrowFlags = ESB_ENABLE_BOTH);

	BOOL SetScrollInfo(LPSCROLLINFO lpScrollInfo, BOOL bRedraw = TRUE);
	BOOL GetScrollInfo(LPSCROLLINFO lpScrollInfo, UINT nMask = SIF_ALL);
	int GetScrollLimit();

#if(_WIN32_WINNT >= 0x0501)
	BOOL GetScrollBarInfo(PSCROLLBARINFO pScrollInfo) const;
#endif	// _WIN32_WINNT >= 0x0501

// Implementation
public:
	virtual ~CScrollBar();
};

/////////////////////////////////////////////////////////////////////////////
// CFrameWnd - base class for SDI and other frame windows

// Frame window styles
#define FWS_ADDTOTITLE  0x00008000L // modify title based on content
#define FWS_PREFIXTITLE 0x00004000L // show document name before app name
#define FWS_SNAPTOBARS  0x00002000L // snap size to size of contained bars

// Frame window menu bar visibility styles
#define AFX_MBV_KEEPVISIBLE    0x01L // always visible
#define AFX_MBV_DISPLAYONFOCUS 0x02L // toggle state on ALT
#define AFX_MBV_DISPLAYONF10   0x04L // display on F10

// Frame window menu bar visibility states
#define AFX_MBS_VISIBLE 0x01L // visible
#define AFX_MBS_HIDDEN  0x02L // hidden

struct CPrintPreviewState;  // forward reference (see afxext.h)
class CControlBar;          // forward reference (see afxext.h)
class CReBar;               // forward reference (see afxext.h)

class CDockBar;             // forward reference (see afxpriv.h)
class CMiniDockFrameWnd;    // forward reference (see afxpriv.h)
class CDockState;           // forward reference (see afxpriv.h)

class COleFrameHook;        // forward reference (see ..\src\oleimpl2.h)

class CFrameWnd : public CWnd
{
	DECLARE_DYNCREATE(CFrameWnd)

// Constructors
public:
	static AFX_DATA const CRect rectDefault;
	CFrameWnd();

	BOOL LoadAccelTable(LPCTSTR lpszResourceName);
	virtual BOOL Create(LPCTSTR lpszClassName,
				LPCTSTR lpszWindowName,
				DWORD dwStyle = WS_OVERLAPPEDWINDOW,
				const RECT& rect = rectDefault,
				CWnd* pParentWnd = NULL,        // != NULL for popups
				LPCTSTR lpszMenuName = NULL,
				DWORD dwExStyle = 0,
				CCreateContext* pContext = NULL);

	// dynamic creation - load frame and associated resources
	virtual BOOL LoadFrame(UINT nIDResource,
				DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE,
				CWnd* pParentWnd = NULL,
				CCreateContext* pContext = NULL);

	// special helper for view creation
	CWnd* CreateView(CCreateContext* pContext, UINT nID = AFX_IDW_PANE_FIRST);

// Attributes
	virtual CDocument* GetActiveDocument();

	// Active child view maintenance
	CView* GetActiveView() const;           // active view or NULL
	void SetActiveView(CView* pViewNew, BOOL bNotify = TRUE);
		// active view or NULL, bNotify == FALSE if focus should not be set

	// Active frame (for frames within frames -- MDI)
	virtual CFrameWnd* GetActiveFrame();

	// For customizing the default messages on the status bar
	virtual void GetMessageString(UINT nID, CString& rMessage) const;

	BOOL m_bAutoMenuEnable;
		// TRUE => menu items without handlers will be disabled

	BOOL IsTracking() const;

// Operations
	virtual void RecalcLayout(BOOL bNotify = TRUE);
	virtual void ActivateFrame(int nCmdShow = -1);
	void InitialUpdateFrame(CDocument* pDoc, BOOL bMakeVisible);
	void SetTitle(LPCTSTR lpszTitle);
	CString GetTitle() const;
	virtual CMenu* GetMenu() const;
	virtual BOOL SetMenu(CMenu* pMenu);

	// set/get menu bar visibility style
	virtual void SetMenuBarVisibility(DWORD dwStyle);
	virtual DWORD GetMenuBarVisibility() const;

	// set/get menu bar visibility state
	virtual BOOL SetMenuBarState(DWORD dwState);
	virtual DWORD GetMenuBarState() const;

#if WINVER >= 0x0500
	BOOL GetMenuBarInfo(LONG idObject, LONG idItem, PMENUBARINFO pmbi) const;
#endif

	// to set text of standard status bar
	void SetMessageText(LPCTSTR lpszText);
	void SetMessageText(UINT nID);

	// control bar docking
	void EnableDocking(DWORD dwDockStyle);
	void DockControlBar(CControlBar* pBar, UINT nDockBarID = 0,
		LPCRECT lpRect = NULL);
	void FloatControlBar(CControlBar* pBar, CPoint point,
		DWORD dwStyle = CBRS_ALIGN_TOP);
	CControlBar* GetControlBar(UINT nID);

	// frame window based modality
	virtual void BeginModalState();
	virtual void EndModalState();
	BOOL InModalState() const;
	void ShowOwnedWindows(BOOL bShow);

	// saving and loading control bar state
	void LoadBarState(LPCTSTR lpszProfileName);
	void SaveBarState(LPCTSTR lpszProfileName) const;
	void ShowControlBar(CControlBar* pBar, BOOL bShow, BOOL bDelay);
	void SetDockState(const CDockState& state);
	void GetDockState(CDockState& state) const;

// Overridables
	virtual void OnSetPreviewMode(BOOL bPreview, CPrintPreviewState* pState);
	virtual CWnd* GetMessageBar();

	// border space negotiation
	enum BorderCmd
		{ borderGet = 1, borderRequest = 2, borderSet = 3 };
	virtual BOOL NegotiateBorderSpace(UINT nBorderCmd, LPRECT lpRectBorder);

protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);

// Command Handlers
public:
	afx_msg void OnContextHelp();   // for Shift+F1 help
	afx_msg void OnUpdateControlBarMenu(CCmdUI* pCmdUI);
	afx_msg BOOL OnBarCheck(UINT nID);

// Implementation
public:
	virtual ~CFrameWnd();
	int m_nWindow;  // general purpose window number - display as ":n"
					// -1 => unknown, 0 => only window viewing document
					// 1 => first of many windows viewing document, 2=> second

	HMENU m_hMenuDefault;       // default menu resource for this frame
	HACCEL m_hAccelTable;       // accelerator table
	DWORD m_dwPromptContext;    // current help prompt context for message box
	BOOL m_bHelpMode;           // if TRUE, then Shift+F1 help mode is active
	CFrameWnd* m_pNextFrameWnd; // next CFrameWnd in app global list
	CRect m_rectBorder;         // for OLE border space negotiation
	COleFrameHook* m_pNotifyHook;

	CPtrList m_listControlBars; // array of all control bars that have this
								// window as their dock site
	int m_nShowDelay;           // SW_ command for delay show/hide

	CMiniDockFrameWnd* CreateFloatingFrame(DWORD dwStyle);
	DWORD CanDock(CRect rect, DWORD dwDockStyle,
		CDockBar** ppDockBar = NULL); // called by CDockContext
	void AddControlBar(CControlBar *pBar);
	void RemoveControlBar(CControlBar *pBar);
	void DockControlBar(CControlBar* pBar, CDockBar* pDockBar,
		LPCRECT lpRect = NULL);
	void ReDockControlBar(CControlBar* pBar, CDockBar* pDockBar,
		LPCRECT lpRect = NULL);
	void NotifyFloatingWindows(DWORD dwFlags);
	void DestroyDockBars();

protected:
	UINT m_nIDHelp;             // Help ID (0 for none, see HID_BASE_RESOURCE)
	UINT m_nIDTracking;         // tracking command ID or string IDS
	UINT m_nIDLastMessage;      // last displayed message string IDS
	CView* m_pViewActive;       // current active view
	BOOL (CALLBACK* m_lpfnCloseProc)(CFrameWnd* pFrameWnd);
	UINT m_cModalStack;         // BeginModalState depth
	HWND* m_phWndDisable;       // windows disabled because of BeginModalState
	HMENU m_hMenuAlt;           // menu to update to (NULL means default)
	CString m_strTitle;         // default title (original)
	BOOL m_bInRecalcLayout;     // avoid recursion in RecalcLayout
	CRuntimeClass* m_pFloatingFrameClass;
	static const DWORD dwDockBarMap[4][2];
    DWORD m_dwMenuBarVisibility;      // menu bar visibility style
	DWORD m_dwMenuBarState;           // menu bar visibility state
	HMENU m_hMenu;                    // backed menu for restoring from the hidden state
	BOOL  m_bTempShowMenu;            // temporarily show the menu bar to enable menu access keys
	BOOL  m_bMouseHitMenu;            // if TRUE, the mouse is hitting the menu bar

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual BOOL IsFrameWnd() const;
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra,
		AFX_CMDHANDLERINFO* pHandlerInfo);
	virtual void OnUpdateFrameTitle(BOOL bAddToTitle);
	virtual void OnUpdateFrameMenu(HMENU hMenuAlt);
	virtual HACCEL GetDefaultAccelerator();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	// idle update of frame user interface
	enum IdleFlags
		{ idleMenu = 1, idleTitle = 2, idleNotify = 4, idleLayout = 8 };
	UINT m_nIdleFlags;          // set of bit flags for idle processing
	virtual void DelayUpdateFrameMenu(HMENU hMenuAlt);
	void DelayUpdateFrameTitle();
	void DelayRecalcLayout(BOOL bNotify = TRUE);

	// for Shift+F1 help support
	BOOL CanEnterHelpMode();
	virtual void ExitHelpMode();

	// implementation helpers
public:
	void UpdateFrameTitleForDocument(LPCTSTR lpszDocName);
protected:
	LPCTSTR GetIconWndClass(DWORD dwDefaultStyle, UINT nIDResource);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual void PostNcDestroy();   // default to delete this.
	int OnCreateHelper(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	void BringToTop(int nCmdShow);
		// bring window to top for SW_ commands which affect z-order

	// implementation helpers for Shift+F1 help mode
	BOOL ProcessHelpMsg(MSG& msg, DWORD* pContext);
	HWND SetHelpCapture(POINT point, BOOL* pbDescendant);

	// CFrameWnd list management
	void AddFrameWnd();
	void RemoveFrameWnd();

	// called before changing the menu bar visibility state
	virtual void OnShowMenuBar();
	virtual void OnHideMenuBar();

	friend class CWnd;  // for access to m_bModalDisable
	friend class CReBar; // for access to m_bInRecalcLayout

	//{{AFX_MSG(CFrameWnd)
	// Windows messages
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnClose();
	afx_msg void OnInitMenu(CMenu*);
	afx_msg void OnInitMenuPopup(CMenu*, UINT, BOOL);
	afx_msg void OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu);
	afx_msg LRESULT OnMenuChar(UINT nChar, UINT nFlags, CMenu* pMenu);
	afx_msg LRESULT OnPopMessageString(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetMessageString(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnHelpPromptAddr(WPARAM wParam, LPARAM lParam);
	afx_msg void OnIdleUpdateCmdUI();
	afx_msg void OnEnterIdle(UINT nWhy, CWnd* pWho);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg BOOL OnQueryEndSession();
	afx_msg void OnEndSession(BOOL bEnding);
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnHelpHitTest(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnActivateTopLevel(WPARAM wParam, LPARAM lParam);
	afx_msg void OnEnable(BOOL bEnable);
	afx_msg void OnPaletteChanged(CWnd* pFocusWnd);
	afx_msg BOOL OnQueryNewPalette();
	// standard commands
	afx_msg BOOL OnToolTipText(UINT nID, NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnUpdateKeyIndicator(CCmdUI* pCmdUI);
	afx_msg void OnHelp();
	afx_msg void OnUpdateContextHelp(CCmdUI* pCmdUI);
	afx_msg BOOL OnChevronPushed(UINT id, NMHDR *pnm, LRESULT *result);
	//}}AFX_MSG
protected:
	afx_msg LRESULT OnDDEInitiate(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDDEExecute(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDDETerminate(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

	friend class CWinApp;
};

/////////////////////////////////////////////////////////////////////////////
// MDI Support

class CMDIFrameWnd : public CFrameWnd
{
	DECLARE_DYNCREATE(CMDIFrameWnd)

public:
// Constructors
	CMDIFrameWnd();

// Operations
	void MDIActivate(CWnd* pWndActivate);
	CMDIChildWnd* MDIGetActive(BOOL* pbMaximized = NULL) const;
	void MDIIconArrange();
	void MDIMaximize(CWnd* pWnd);
	void MDINext();
	void MDIPrev();
	void MDIRestore(CWnd* pWnd);
	CMenu* MDISetMenu(CMenu* pFrameMenu, CMenu* pWindowMenu);
	void MDITile();
	void MDICascade();
	void MDITile(int nType);
	void MDICascade(int nType);
	CMDIChildWnd* CreateNewChild(CRuntimeClass* pClass, UINT nResource,
		HMENU hMenu = NULL, HACCEL hAccel = NULL);

// Overridables
	// MFC 1.0 backward compatible CreateClient hook (called by OnCreateClient)
	virtual BOOL CreateClient(LPCREATESTRUCT lpCreateStruct, CMenu* pWindowMenu);
	// customize if using an 'Window' menu with non-standard IDs
	virtual HMENU GetWindowMenuPopup(HMENU hMenuBar);

// Implementation
public:
	HWND m_hWndMDIClient;       // MDI Client window handle

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource,
				DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE,
				CWnd* pParentWnd = NULL,
				CCreateContext* pContext = NULL);
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void OnUpdateFrameTitle(BOOL bAddToTitle);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra,
		AFX_CMDHANDLERINFO* pHandlerInfo);
	virtual void OnUpdateFrameMenu(HMENU hMenuAlt);
	virtual void DelayUpdateFrameMenu(HMENU hMenuAlt);
	virtual CFrameWnd* GetActiveFrame();
	virtual void SetMenuBarVisibility(DWORD dwStyle);
	virtual BOOL SetMenuBarState(DWORD dwState);

protected:
	virtual LRESULT DefWindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

	//{{AFX_MSG(CMDIFrameWnd)
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnUpdateMDIWindowCmd(CCmdUI* pCmdUI);
	afx_msg BOOL OnMDIWindowCmd(UINT nID);
	afx_msg void OnWindowNew();
	afx_msg LRESULT OnCommandHelp(WPARAM wParam, LPARAM lParam);
	afx_msg void OnIdleUpdateCmdUI();
	afx_msg LRESULT OnMenuChar(UINT nChar, UINT, CMenu*);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

class CMDIChildWnd : public CFrameWnd
{
	DECLARE_DYNCREATE(CMDIChildWnd)

// Constructors
public:
	CMDIChildWnd();

	virtual BOOL Create(LPCTSTR lpszClassName,
				LPCTSTR lpszWindowName,
				DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW,
				const RECT& rect = rectDefault,
				CMDIFrameWnd* pParentWnd = NULL,
				CCreateContext* pContext = NULL);

// Attributes
	CMDIFrameWnd* GetMDIFrame();

// Operations
	void MDIDestroy();
	void MDIActivate();
	void MDIMaximize();
	void MDIRestore();
	void SetHandles(HMENU hMenu, HACCEL hAccel);

// Implementation
protected:
	HMENU m_hMenuShared;        // menu when we are active

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle,
					CWnd* pParentWnd, CCreateContext* pContext = NULL);
		// 'pParentWnd' parameter is required for MDI Child
	virtual BOOL DestroyWindow();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void ActivateFrame(int nCmdShow = -1);
	virtual void OnUpdateFrameMenu(BOOL bActive, CWnd* pActivateWnd,
		HMENU hMenuAlt);

	BOOL m_bPseudoInactive;     // TRUE if window is MDI active according to
								//  windows, but not according to MFC...

protected:
	virtual CWnd* GetMessageBar();
	virtual void OnUpdateFrameTitle(BOOL bAddToTitle);
	virtual LRESULT DefWindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam);
	BOOL UpdateClientEdge(LPRECT lpRect = NULL);

	//{{AFX_MSG(CMDIChildWnd)
	afx_msg void OnMDIActivate(BOOL bActivate, CWnd*, CWnd*);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnNcCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnWindowPosChanging(LPWINDOWPOS lpWndPos);
	afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg void OnDestroy();
	afx_msg BOOL OnToolTipText(UINT nID, NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CMiniFrameWnd

// MiniFrame window styles
#define MFS_SYNCACTIVE      0x00000100L // syncronize activation w/ parent
#define MFS_4THICKFRAME     0x00000200L // thick frame all around (no tiles)
#define MFS_THICKFRAME      0x00000400L // use instead of WS_THICKFRAME
#define MFS_MOVEFRAME       0x00000800L // no sizing, just moving
#define MFS_BLOCKSYSMENU    0x00001000L // block hit testing on system menu

#pragma warning( push )

#pragma warning( disable: 4263 )
#pragma warning( disable: 4264 )
class CMiniFrameWnd : public CFrameWnd
{
	DECLARE_DYNCREATE(CMiniFrameWnd)

// Constructors
public:
	CMiniFrameWnd();
	virtual BOOL Create(LPCTSTR lpClassName, LPCTSTR lpWindowName,
		DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd = NULL, UINT nID = 0);
	virtual BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpClassName, LPCTSTR lpWindowName,
		DWORD dwStyle, const RECT& rect,
		CWnd* pParentWnd = NULL, UINT nID = 0);

// Implementation
public:
	~CMiniFrameWnd();

	//{{AFX_MSG(CMiniFrameWnd)
	afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* pMMI);
	afx_msg LRESULT OnFloatStatus(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnQueryCenterWnd(WPARAM wParam, LPARAM lParam);
	afx_msg BOOL OnNcCreate(LPCREATESTRUCT lpcs);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	static void PASCAL CalcBorders(LPRECT lpClientRect,
		DWORD dwStyle = WS_THICKFRAME | WS_CAPTION, DWORD dwExStyle = 0);

protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	BOOL m_bSysTracking;
	BOOL m_bInSys;
	BOOL m_bActive;
	CString m_strCaption;
};

#pragma warning( pop )

/////////////////////////////////////////////////////////////////////////////
// class CView is the client area UI for a document

class CPrintDialog;     // forward reference (see afxdlgs.h)
class CPreviewView;     // forward reference (see afxpriv.h)
class CSplitterWnd;     // forward reference (see afxext.h)
class COleServerDoc;    // forward reference (see afxole.h)

typedef DWORD DROPEFFECT;
class COleDataObject;   // forward reference (see afxole.h)

class AFX_NOVTABLE CView : public CWnd
{
	DECLARE_DYNAMIC(CView)

// Constructors
protected:
	CView();

// Attributes
public:
	CDocument* GetDocument() const;

// Operations
public:
	// for standard printing setup (override OnPreparePrinting)
	BOOL DoPreparePrinting(CPrintInfo* pInfo);

// Overridables
public:
	virtual BOOL IsSelected(const CObject* pDocItem) const; // support for OLE

	// OLE scrolling support (used for drag/drop as well)
	virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE);
	virtual BOOL OnScrollBy(CSize sizeScroll, BOOL bDoScroll = TRUE);

	// OLE drag/drop support
	virtual DROPEFFECT OnDragEnter(COleDataObject* pDataObject,
		DWORD dwKeyState, CPoint point);
	virtual DROPEFFECT OnDragOver(COleDataObject* pDataObject,
		DWORD dwKeyState, CPoint point);
	virtual void OnDragLeave();
	virtual BOOL OnDrop(COleDataObject* pDataObject,
		DROPEFFECT dropEffect, CPoint point);
	virtual DROPEFFECT OnDropEx(COleDataObject* pDataObject,
		DROPEFFECT dropDefault, DROPEFFECT dropList, CPoint point);
	virtual DROPEFFECT OnDragScroll(DWORD dwKeyState, CPoint point);

	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);

	virtual void OnInitialUpdate(); // called first time after construct

protected:
	// Activation
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView,
					CView* pDeactiveView);
	virtual void OnActivateFrame(UINT nState, CFrameWnd* pFrameWnd);

	// General drawing/updating
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual void OnDraw(CDC* pDC) = 0;

	// Printing support
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
		// must override to enable printing and print preview

	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// Advanced: end print preview mode, move to point
	virtual void OnEndPrintPreview(CDC* pDC, CPrintInfo* pInfo, POINT point,
		CPreviewView* pView);

// Implementation
public:
	virtual ~CView() = 0;
#ifdef _DEBUG
	virtual void Dump(CDumpContext&) const;
	virtual void AssertValid() const;
#endif //_DEBUG

	// Advanced: for implementing custom print preview
	BOOL DoPrintPreview(UINT nIDResource, CView* pPrintView,
			CRuntimeClass* pPreviewViewClass, CPrintPreviewState* pState);

	virtual void CalcWindowRect(LPRECT lpClientRect,
		UINT nAdjustType = adjustBorder);
	virtual CScrollBar* GetScrollBarCtrl(int nBar) const;
	static CSplitterWnd* PASCAL GetParentSplitter(
		const CWnd* pWnd, BOOL bAnyState);

protected:
	CDocument* m_pDocument;

public:
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra,
		AFX_CMDHANDLERINFO* pHandlerInfo);
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void PostNcDestroy();

	// friend classes that call protected CView overridables
	friend class CDocument;
	friend class CDocTemplate;
	friend class CPreviewView;
	friend class CFrameWnd;
	friend class CMDIFrameWnd;
	friend class CMDIChildWnd;
	friend class CSplitterWnd;
	friend class COleServerDoc;
	friend class CDocObjectServer;

	//{{AFX_MSG(CView)
	afx_msg int OnCreate(LPCREATESTRUCT lpcs);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	// commands
	afx_msg void OnUpdateSplitCmd(CCmdUI* pCmdUI);
	afx_msg BOOL OnSplitCmd(UINT nID);
	afx_msg void OnUpdateNextPaneMenu(CCmdUI* pCmdUI);
	afx_msg BOOL OnNextPaneCmd(UINT nID);

	// not mapped commands - must be mapped in derived class
	afx_msg void OnFilePrint();
	afx_msg void OnFilePrintPreview();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// class CCtrlView allows almost any control to be a view

class AFX_NOVTABLE CCtrlView : public CView
{
	DECLARE_DYNCREATE(CCtrlView)

public:
	CCtrlView(LPCTSTR lpszClass, DWORD dwStyle);

// Attributes
protected:
	CString m_strClass;
	DWORD m_dwDefaultStyle;

// Overrides
	virtual void OnDraw(CDC* pDC);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	~CCtrlView() = 0;
#ifdef _DEBUG
	virtual void Dump(CDumpContext&) const;
	virtual void AssertValid() const;
#endif //_DEBUG

protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// class CScrollView supports simple scrolling and scaling

class _AFX_MOUSEANCHORWND;

class CScrollView : public CView
{
	DECLARE_DYNAMIC(CScrollView)

// Constructors
protected:
	CScrollView();

public:
	static AFX_DATA const SIZE sizeDefault;
		// used to specify default calculated page and line sizes

	// in logical units - call one of the following Set routines
	void SetScaleToFitSize(SIZE sizeTotal);
	void SetScrollSizes(int nMapMode, SIZE sizeTotal,
				const SIZE& sizePage = sizeDefault,
				const SIZE& sizeLine = sizeDefault);

// Attributes
public:
	CPoint GetScrollPosition() const;       // upper corner of scrolling
	CSize GetTotalSize() const;             // logical size

	void CheckScrollBars(BOOL& bHasHorzBar, BOOL& bHasVertBar) const;

	// for device units
	CPoint GetDeviceScrollPosition() const;
	void GetDeviceScrollSizes(int& nMapMode, SIZE& sizeTotal,
			SIZE& sizePage, SIZE& sizeLine) const;

// Operations
public:
	void ScrollToPosition(POINT pt);    // set upper left position
	void FillOutsideRect(CDC* pDC, CBrush* pBrush);
	void ResizeParentToFit(BOOL bShrinkOnly = TRUE);
	BOOL DoMouseWheel(UINT fFlags, short zDelta, CPoint point);

// Implementation
protected:
	_AFX_MOUSEANCHORWND* m_pAnchorWindow; // window for wheel mouse anchor
	friend class _AFX_MOUSEANCHORWND;
	int m_nMapMode;				 // mapping mode for window creation
	CSize m_totalLog;           // total size in logical units (no rounding)
	CSize m_totalDev;           // total size in device units
	CSize m_pageDev;            // per page scroll size in device units
	CSize m_lineDev;            // per line scroll size in device units

	BOOL m_bCenter;             // Center output if larger than total size
	BOOL m_bInsideUpdate;       // internal state for OnSize callback
	void CenterOnPoint(CPoint ptCenter);
	void ScrollToDevicePosition(POINT ptDev); // explicit scrolling no checking

protected:
	virtual void OnDraw(CDC* pDC) = 0;      // pass on pure virtual

	void UpdateBars();          // adjust scrollbars etc
	BOOL GetTrueClientSize(CSize& size, CSize& sizeSb);
		// size with no bars
	void GetScrollBarSizes(CSize& sizeSb);
	void GetScrollBarState(CSize sizeClient, CSize& needSb,
		CSize& sizeRange, CPoint& ptMove, BOOL bInsideClient);

public:
	virtual ~CScrollView();
#ifdef _DEBUG
	virtual void Dump(CDumpContext&) const;
	virtual void AssertValid() const;
#endif //_DEBUG
	virtual void CalcWindowRect(LPRECT lpClientRect,
		UINT nAdjustType = adjustBorder);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);

	virtual CSize GetWheelScrollDistance(CSize sizeDistance,
		BOOL bHorz, BOOL bVert);

	// scrolling implementation support for OLE
	virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE);
	virtual BOOL OnScrollBy(CSize sizeScroll, BOOL bDoScroll = TRUE);

	//{{AFX_MSG(CScrollView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnMouseWheel(UINT fFlags, short zDelta, CPoint point);
//	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	afx_msg LRESULT HandleMButtonDown(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CWinThread

typedef UINT (AFX_CDECL *AFX_THREADPROC)(LPVOID);

class COleMessageFilter;        // forward reference (see afxole.h)

BOOL AFXAPI AfxPumpMessage();
LRESULT AFXAPI AfxProcessWndProcException(CException*, const MSG* pMsg);
BOOL __cdecl AfxPreTranslateMessage(MSG* pMsg);
BOOL __cdecl AfxIsIdleMessage(MSG* pMsg);

class CWinThread : public CCmdTarget
{
	DECLARE_DYNAMIC(CWinThread)

	friend BOOL AfxInternalPreTranslateMessage(MSG* pMsg);

public:
// Constructors
	CWinThread();
	BOOL CreateThread(DWORD dwCreateFlags = 0, UINT nStackSize = 0,
		LPSECURITY_ATTRIBUTES lpSecurityAttrs = NULL);

// Attributes
	CWnd* m_pMainWnd;       // main window (usually same AfxGetApp()->m_pMainWnd)
	CWnd* m_pActiveWnd;     // active main window (may not be m_pMainWnd)
	BOOL m_bAutoDelete;     // enables 'delete this' after thread termination

	// only valid while running
	HANDLE m_hThread;       // this thread's HANDLE
	operator HANDLE() const;
	DWORD m_nThreadID;      // this thread's ID

	int GetThreadPriority();
	BOOL SetThreadPriority(int nPriority);

// Operations
	DWORD SuspendThread();
	DWORD ResumeThread();
	BOOL PostThreadMessage(UINT message, WPARAM wParam, LPARAM lParam);

// Overridables
	// thread initialization
	virtual BOOL InitInstance();

	// running and idle processing
	virtual int Run();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL PumpMessage();     // low level message pump
	virtual BOOL OnIdle(LONG lCount); // return TRUE if more idle processing
	virtual BOOL IsIdleMessage(MSG* pMsg);  // checks for special messages

	// thread termination
	virtual int ExitInstance(); // default will 'delete this'

	// Advanced: exception handling
	virtual LRESULT ProcessWndProcException(CException* e, const MSG* pMsg);

	// Advanced: handling messages sent to message filter hook
	virtual BOOL ProcessMessageFilter(int code, LPMSG lpMsg);

	// Advanced: virtual access to m_pMainWnd
	virtual CWnd* GetMainWnd();

// Implementation
public:
	virtual ~CWinThread();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	void CommonConstruct();
	virtual void Delete();
		// 'delete this' only if m_bAutoDelete == TRUE

public:
	// constructor used by implementation of AfxBeginThread
	CWinThread(AFX_THREADPROC pfnThreadProc, LPVOID pParam);

	// valid after construction
	LPVOID m_pThreadParams; // generic parameters passed to starting function
	AFX_THREADPROC m_pfnThreadProc;

	// set after OLE is initialized
	void (AFXAPI* m_lpfnOleTermOrFreeLib)(BOOL, BOOL);
	COleMessageFilter* m_pMessageFilter;

protected:
	BOOL DispatchThreadMessageEx(MSG* msg);  // helper
	void DispatchThreadMessage(MSG* msg);  // obsolete
};

// global helpers for threads

CWinThread* AFXAPI AfxBeginThread(AFX_THREADPROC pfnThreadProc, LPVOID pParam,
	int nPriority = THREAD_PRIORITY_NORMAL, UINT nStackSize = 0,
	DWORD dwCreateFlags = 0, LPSECURITY_ATTRIBUTES lpSecurityAttrs = NULL);
CWinThread* AFXAPI AfxBeginThread(CRuntimeClass* pThreadClass,
	int nPriority = THREAD_PRIORITY_NORMAL, UINT nStackSize = 0,
	DWORD dwCreateFlags = 0, LPSECURITY_ATTRIBUTES lpSecurityAttrs = NULL);

CWinThread* AFXAPI AfxGetThread();
MSG* AFXAPI AfxGetCurrentMessage();

void AFXAPI AfxEndThread(UINT nExitCode, BOOL bDelete = TRUE);

void AFXAPI AfxInitThread();
void AFXAPI AfxTermThread(HINSTANCE hInstTerm = NULL);

/////////////////////////////////////////////////////////////////////////////
// Global functions for access to the one and only CWinApp

#define afxCurrentWinApp    AfxGetModuleState()->m_pCurrentWinApp
#define afxCurrentInstanceHandle    AfxGetModuleState()->m_hCurrentInstanceHandle
#define afxCurrentResourceHandle    AfxGetModuleState()->m_hCurrentResourceHandle
#define afxCurrentAppName   AfxGetModuleState()->m_lpszCurrentAppName
#define afxContextIsDLL     AfxGetModuleState()->m_bDLL
#define afxRegisteredClasses    AfxGetModuleState()->m_fRegisteredClasses
#define afxAmbientActCtx    AfxGetModuleState()->m_bSetAmbientActCtx

#ifndef _AFX_NO_OCC_SUPPORT
#define afxOccManager   AfxGetModuleState()->m_pOccManager
#endif

//Fusion: Access macros for WinSxS dynamic wrappers.
#ifndef _AFX_NO_AFXCMN_SUPPORT
#define _AFX_COMCTL32_ISOLATION_WRAPPER_INDEX 0
#define afxComCtlWrapper static_cast<CComCtlWrapper*>(AfxGetModuleState()->m_pDllIsolationWrappers[_AFX_COMCTL32_ISOLATION_WRAPPER_INDEX])
#endif

#define _AFX_COMMDLG_ISOLATION_WRAPPER_INDEX 1
#define afxCommDlgWrapper static_cast<CCommDlgWrapper*>(AfxGetModuleState()->m_pDllIsolationWrappers[_AFX_COMMDLG_ISOLATION_WRAPPER_INDEX])

#define _AFX_SHELL_ISOLATION_WRAPPER_INDEX 2
#define afxShellWrapper static_cast<CShellWrapper*>(AfxGetModuleState()->m_pDllIsolationWrappers[_AFX_SHELL_ISOLATION_WRAPPER_INDEX])

#define _AFX_ISOLATION_WRAPPER_ARRAY_SIZE 3

// Advanced initialization: for overriding default WinMain
BOOL AFXAPI AfxWinInit(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance,
	_In_z_ LPTSTR lpCmdLine, _In_ int nCmdShow);
void AFXAPI AfxWinTerm();

// Global Windows state data helper functions (inlines)
#ifdef _AFXDLL
ULONG AFXAPI AfxGetDllVersion();
#endif

CWinApp* AFXAPI AfxGetApp();
CWnd* AFXAPI AfxGetMainWnd();
HINSTANCE AFXAPI AfxGetInstanceHandle();
HINSTANCE AFXAPI AfxGetResourceHandle();
void AFXAPI AfxSetResourceHandle(HINSTANCE hInstResource);
LPCTSTR AFXAPI AfxGetAppName();
AFX_DEPRECATED("AfxLoadLangResourceDLL(LPCTSTR pszFormat) has been deprecated, use AfxLoadLangResourceDLL(LPCTSTR pszFormat, LPCTSTR pszPath) instead")
	HINSTANCE AFXAPI AfxLoadLangResourceDLL(LPCTSTR pszFormat);
HINSTANCE AFXAPI AfxLoadLangResourceDLL(LPCTSTR pszFormat, LPCTSTR pszPath);

// Use instead of PostQuitMessage in OLE server applications
void AFXAPI AfxPostQuitMessage(int nExitCode);

// Use AfxFindResourceHandle to find resource in chain of extension DLLs
#ifndef _AFXDLL
#define AfxFindResourceHandle(lpszResource, lpszType) AfxGetResourceHandle()
#else
HINSTANCE AFXAPI AfxFindResourceHandle(LPCTSTR lpszName, LPCTSTR lpszType);
#endif

LONG AFXAPI AfxDelRegTreeHelper(HKEY hParentKey, const CString& strKeyName);

class CRecentFileList;          // forward reference (see afxadv.h)

// access to message filter in CWinApp
COleMessageFilter* AFXAPI AfxOleGetMessageFilter();

/////////////////////////////////////////////////////////////////////////////
// CCommandLineInfo

class CCommandLineInfo : public CObject
{
public:
	// Sets default values
	CCommandLineInfo();

	// plain char* version on UNICODE for source-code backwards compatibility
	virtual void ParseParam(const TCHAR* pszParam, BOOL bFlag, BOOL bLast);
#ifdef _UNICODE
	virtual void ParseParam(const char* pszParam, BOOL bFlag, BOOL bLast);
#endif

	BOOL m_bShowSplash;
	BOOL m_bRunEmbedded;
	BOOL m_bRunAutomated;
	BOOL m_bRegisterPerUser;
	enum { FileNew, FileOpen, FilePrint, FilePrintTo, FileDDE, AppRegister,
		AppUnregister, FileNothing = -1 } m_nShellCommand;

	// not valid for FileNew
	CString m_strFileName;

	// valid only for FilePrintTo
	CString m_strPrinterName;
	CString m_strDriverName;
	CString m_strPortName;

	~CCommandLineInfo();
// Implementation
protected:
	void ParseParamFlag(const char* pszParam);
	void ParseParamNotFlag(const TCHAR* pszParam);
#ifdef _UNICODE
	void ParseParamNotFlag(const char* pszParam);
#endif
	void ParseLast(BOOL bLast);
};

/////////////////////////////////////////////////////////////////////////////
// CDocManager

class CDocManager : public CObject
{
	DECLARE_DYNAMIC(CDocManager)
public:

// Constructor
	CDocManager();

	//Document functions
	virtual void AddDocTemplate(CDocTemplate* pTemplate);
	virtual POSITION GetFirstDocTemplatePosition() const;
	virtual CDocTemplate* GetNextDocTemplate(POSITION& pos) const;
	virtual void RegisterShellFileTypes(BOOL bCompat);
	void UnregisterShellFileTypes();
	virtual CDocument* OpenDocumentFile(LPCTSTR lpszFileName); // open named file
	virtual BOOL SaveAllModified(); // save before exit
	virtual void CloseAllDocuments(BOOL bEndSession); // close documents before exiting
	virtual int GetOpenDocumentCount();

	// helper for standard commdlg dialogs
	virtual BOOL DoPromptFileName(CString& fileName, UINT nIDSTitle,
			DWORD lFlags, BOOL bOpenFileDialog, CDocTemplate* pTemplate);

//Commands
	// Advanced: process async DDE request
	virtual BOOL OnDDECommand(_In_z_ LPTSTR lpszCommand);
	virtual void OnFileNew();
	virtual void OnFileOpen();

// Implementation
protected:
	CPtrList m_templateList;
	int GetDocumentCount(); // helper to count number of total documents

public:
	static CPtrList* pStaticList;       // for static CDocTemplate objects
	static BOOL bStaticInit;            // TRUE during static initialization
	static CDocManager* pStaticDocManager;  // for static CDocTemplate objects

public:
	virtual ~CDocManager();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

/////////////////////////////////////////////////////////////////////////////
// CWinApp - the root of all Windows applications

#define _AFX_MRU_COUNT   4      // default support for 4 entries in file MRU
#define _AFX_MRU_MAX_COUNT 16   // currently allocated id range supports 16

#define _AFX_SYSPOLICY_NOTINITIALIZED			0
#define _AFX_SYSPOLICY_NORUN					1 
#define _AFX_SYSPOLICY_NODRIVES					2
#define _AFX_SYSPOLICY_RESTRICTRUN				4
#define _AFX_SYSPOLICY_NONETCONNECTDISCONNECTD	8
#define _AFX_SYSPOLICY_NOENTIRENETWORK			16
#define _AFX_SYSPOLICY_NORECENTDOCHISTORY		32
#define _AFX_SYSPOLICY_NOCLOSE					64
#define _AFX_SYSPOLICY_NOPLACESBAR				128
#define _AFX_SYSPOLICY_NOBACKBUTTON				256
#define _AFX_SYSPOLICY_NOFILEMRU				512

struct _AfxSysPolicyData
{
	LPCTSTR szPolicyName;
	DWORD dwID;
};

struct _AfxSysPolicies
{
	LPCTSTR szPolicyKey;
	_AfxSysPolicyData *pData;
};

class CWinApp : public CWinThread
{
	DECLARE_DYNAMIC(CWinApp)
public:

// Constructor
	/* explicit */ CWinApp(LPCTSTR lpszAppName = NULL);     // app name defaults to EXE name

// Attributes
	// Startup args (do not change)

	// This module's hInstance.
	HINSTANCE m_hInstance;

	// Pointer to the command-line.
	LPTSTR m_lpCmdLine;

	// Initial state of the application's window; normally,
	// this is an argument to ShowWindow().
	int m_nCmdShow;

	// Running args (can be changed in InitInstance)

	// Human-redable name of the application. Normally set in
	// constructor or retreived from AFX_IDS_APP_TITLE.
	LPCTSTR m_pszAppName;

	// Name of registry key for this application. See
	// SetRegistryKey() member function.
	LPCTSTR m_pszRegistryKey;

	// Pointer to CDocManager used to manage document templates
	// for this application instance.
	CDocManager* m_pDocManager;

	// Support for Shift+F1 help mode.

	// TRUE if we're in SHIFT+F1 mode.
	BOOL m_bHelpMode;

public:
	// set in constructor to override default

	// Executable name (no spaces).
	LPCTSTR m_pszExeName;

	// Default based on this module's path.
	LPCTSTR m_pszHelpFilePath;

	// Default based on this application's name.
	LPCTSTR m_pszProfileName;

	// Sets and initializes usage of HtmlHelp instead of WinHelp.
	void EnableHtmlHelp();

	// Sets and initializes usage of HtmlHelp instead of WinHelp.
	void SetHelpMode( AFX_HELP_TYPE eHelpType );
	AFX_HELP_TYPE GetHelpMode();

	// help mode used by the app
	AFX_HELP_TYPE m_eHelpType;

// Initialization Operations - should be done in InitInstance
protected:
	// Load MRU file list and last preview state.
	void LoadStdProfileSettings(UINT nMaxMRU = _AFX_MRU_COUNT);

	void EnableShellOpen();

	// SetDialogBkColor is no longer supported.
	// To change dialog background and text color, handle WM_CTLCOLORDLG instead.
	AFX_DEPRECATED("CWinApp::SetDialogBkColor is no longer supported. Instead, handle WM_CTLCOLORDLG in your dialog")
			void SetDialogBkColor(COLORREF clrCtlBk = RGB(192, 192, 192), COLORREF clrCtlText = RGB(0, 0, 0));

	// Set regsitry key name to be used by CWinApp's
	// profile member functions; prevents writing to an INI file.
	void SetRegistryKey(LPCTSTR lpszRegistryKey);
	void SetRegistryKey(UINT nIDRegistryKey);

	// Enable3dControls and Enable3dControlsStatic are no longer necessary.
	AFX_DEPRECATED("CWinApp::Enable3dControls is no longer needed. You should remove this call.")
			BOOL Enable3dControls();
#ifndef _AFXDLL
	AFX_DEPRECATED("CWinApp::Enable3dControlsStatic is no longer needed. You should remove this call.")
			BOOL Enable3dControlsStatic();
#endif

	void RegisterShellFileTypes(BOOL bCompat = FALSE);

	// call after all doc templates are registered
	void UnregisterShellFileTypes();

public:
	// Loads a cursor resource.
	HCURSOR LoadCursor(LPCTSTR lpszResourceName) const;
	HCURSOR LoadCursor(UINT nIDResource) const;

	// Loads a stock cursor resource; for for IDC_* values.
	HCURSOR LoadStandardCursor(LPCTSTR lpszCursorName) const;

	// Loads an OEM cursor; for all OCR_* values.
	HCURSOR LoadOEMCursor(UINT nIDCursor) const;

	// Loads an icon resource.
	HICON LoadIcon(LPCTSTR lpszResourceName) const;
	HICON LoadIcon(UINT nIDResource) const;

	// Loads an icon resource; for stock IDI_ values.
	HICON LoadStandardIcon(LPCTSTR lpszIconName) const;

	// Loads an OEM icon resource; for all OIC_* values.
	HICON LoadOEMIcon(UINT nIDIcon) const;

	// Retrieve an integer value from INI file or registry.
	UINT GetProfileInt(LPCTSTR lpszSection, LPCTSTR lpszEntry, int nDefault);

	// Sets an integer value to INI file or registry.
	BOOL WriteProfileInt(LPCTSTR lpszSection, LPCTSTR lpszEntry, int nValue);

	// Retrieve a string value from INI file or registry.
	CString GetProfileString(LPCTSTR lpszSection, LPCTSTR lpszEntry,
				LPCTSTR lpszDefault = NULL);

	// Sets a string value to INI file or registry.
	BOOL WriteProfileString(LPCTSTR lpszSection, LPCTSTR lpszEntry,
				LPCTSTR lpszValue);

	// Retrieve an arbitrary binary value from INI file or registry.
	BOOL GetProfileBinary(LPCTSTR lpszSection, LPCTSTR lpszEntry,
				LPBYTE* ppData, UINT* pBytes);

	// Sets an arbitrary binary value to INI file or registry.
	BOOL WriteProfileBinary(LPCTSTR lpszSection, LPCTSTR lpszEntry,
				LPBYTE pData, UINT nBytes);

	// Override in derived class.
	virtual void InitLibId();

	// Register
	virtual BOOL Register();

	// Unregisters everything this app was known to register.
	virtual BOOL Unregister();

	// Delete a registry key entry (and all its subkeys, too).
	LONG DelRegTree(HKEY hParentKey, const CString& strKeyName);

// Running Operations - to be done on a running application
	// Dealing with document templates
	void AddDocTemplate(CDocTemplate* pTemplate);
	POSITION GetFirstDocTemplatePosition() const;
	CDocTemplate* GetNextDocTemplate(POSITION& pos) const;

	// Open named file, trying to match a regsitered
	// document template to it.
	virtual CDocument* OpenDocumentFile(LPCTSTR lpszFileName);

	// Add a string to the recent file list. Remove oldest string,
	// if no space left.
	virtual void AddToRecentFileList(LPCTSTR lpszPathName);

	// Printer DC Setup routine, 'struct tagPD' is a PRINTDLG structure.
	void SelectPrinter(HANDLE hDevNames, HANDLE hDevMode,
		BOOL bFreeOld = TRUE);

	// Create a DC for the system default printer.
	BOOL CreatePrinterDC(CDC& dc);


BOOL GetPrinterDeviceDefaults(PRINTDLG* pPrintDlg);

	// Run this app as an embedded object.
	BOOL RunEmbedded();

	// Run this app as an OLE automation server.
	BOOL RunAutomated();

	// Parse the command line for stock options and commands.
	void ParseCommandLine(CCommandLineInfo& rCmdInfo);

	// React to a shell-issued command line directive.
	BOOL ProcessShellCommand(CCommandLineInfo& rCmdInfo);

// Overridables

	// Hooks for your initialization code
	virtual BOOL InitApplication();

	// exiting
	virtual BOOL SaveAllModified(); // save before exit
	void HideApplication();
	void CloseAllDocuments(BOOL bEndSession); // close documents before exiting

	// Advanced: to override message boxes and other hooks
	virtual int DoMessageBox(LPCTSTR lpszPrompt, UINT nType, UINT nIDPrompt);
	virtual void DoWaitCursor(int nCode); // 0 => restore, 1=> begin, -1=> end

	// Advanced: process async DDE request
	virtual BOOL OnDDECommand(_In_z_ LPTSTR lpszCommand);

	// Advanced: Help support
	virtual void WinHelp(DWORD_PTR dwData, UINT nCmd = HELP_CONTEXT);
	virtual void HtmlHelp(DWORD_PTR dwData, UINT nCmd = 0x000F);
	virtual void WinHelpInternal(DWORD_PTR dwData, UINT nCmd = HELP_CONTEXT);

// Command Handlers
protected:
	// map to the following for file new/open
	afx_msg void OnFileNew();
	afx_msg void OnFileOpen();

	// map to the following to enable print setup
	afx_msg void OnFilePrintSetup();

	// map to the following to enable help
	afx_msg void OnContextHelp();   // shift-F1
	afx_msg void OnHelp();          // F1 (uses current context)
	afx_msg void OnHelpIndex();     // ID_HELP_INDEX
	afx_msg void OnHelpFinder();    // ID_HELP_FINDER, ID_DEFAULT_HELP
	afx_msg void OnHelpUsing();     // ID_HELP_USING

// Implementation
protected:
	HGLOBAL m_hDevMode;             // printer Dev Mode
	HGLOBAL m_hDevNames;            // printer Device Names
	DWORD m_dwPromptContext;        // help context override for message box
// LKG	
//	DWORD m_dwPolicies;				// block for storing boolean system policies

	HINSTANCE m_hLangResourceDLL;  // Satellite resource DLL

	int m_nWaitCursorCount;         // for wait cursor (>0 => waiting)
	HCURSOR m_hcurWaitCursorRestore; // old cursor to restore after wait cursor

	CRecentFileList* m_pRecentFileList;

	void UpdatePrinterSelection(BOOL bForceDefaults);
	void SaveStdProfileSettings();  // save options to .INI file

public: // public for implementation access
	CCommandLineInfo* m_pCmdInfo;

	ATOM m_atomApp, m_atomSystemTopic;   // for DDE open
	UINT m_nNumPreviewPages;        // number of default printed pages

	size_t  m_nSafetyPoolSize;      // ideal size

	void (AFXAPI* m_lpfnDaoTerm)();

	void DevModeChange(_In_z_ LPTSTR lpDeviceName);
	void SetCurrentHandles();

	// Finds number of opened CDocument items owned by templates
	// registered with the doc manager.
	int GetOpenDocumentCount();

	// helpers for standard commdlg dialogs
	BOOL DoPromptFileName(CString& fileName, UINT nIDSTitle,
			DWORD lFlags, BOOL bOpenFileDialog, CDocTemplate* pTemplate);
	INT_PTR DoPrintDialog(CPrintDialog* pPD);

	void EnableModeless(BOOL bEnable); // to disable OLE in-place dialogs

	// overrides for implementation
	virtual BOOL InitInstance();
	virtual int ExitInstance(); // return app exit code
	virtual int Run();
	virtual BOOL OnIdle(LONG lCount); // return TRUE if more idle processing
	virtual LRESULT ProcessWndProcException(CException* e, const MSG* pMsg);
	virtual HINSTANCE LoadAppLangResourceDLL();

    // Helper for message boxes; can work when no CWinApp can be found
	static int ShowAppMessageBox(CWinApp *pApp, LPCTSTR lpszPrompt, UINT nType, UINT nIDPrompt);
	static void DoEnableModeless(BOOL bEnable); // to disable OLE in-place dialogs

public:
	virtual ~CWinApp();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// helpers for registration
	HKEY GetSectionKey(LPCTSTR lpszSection);
	HKEY GetAppRegistryKey();

protected:
	//{{AFX_MSG(CWinApp)
	afx_msg void OnAppExit();
	afx_msg void OnUpdateRecentFileMenu(CCmdUI* pCmdUI);
	afx_msg BOOL OnOpenRecentFile(UINT nID);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public :
	// System Policy Settings
	virtual BOOL LoadSysPolicies(); // Override to load policies other than the system policies that MFC loads.
	BOOL GetSysPolicyValue(DWORD dwPolicyID, BOOL *pbValue); // returns the policy's setting in the out parameter
protected :
	BOOL _LoadSysPolicies() throw(); // Implementation helper
	DWORD m_dwPolicies;				// block for storing boolean system policies
};

/////////////////////////////////////////////////////////////////////////////
// class CWaitCursor

class CWaitCursor
{
// Construction/Destruction
public:
	CWaitCursor();
	~CWaitCursor();

// Operations
public:
	void Restore();
};

/////////////////////////////////////////////////////////////////////////////
// class CDocTemplate creates documents

class AFX_NOVTABLE CDocTemplate : public CCmdTarget
{
	DECLARE_DYNAMIC(CDocTemplate)

// Constructors
protected:
	CDocTemplate(UINT nIDResource, CRuntimeClass* pDocClass,
		CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass);

public:
	virtual void LoadTemplate();

// Attributes
public:
	// setup for OLE containers
	void SetContainerInfo(UINT nIDOleInPlaceContainer);

	// setup for OLE servers
	void SetServerInfo(UINT nIDOleEmbedding, UINT nIDOleInPlaceServer = 0,
		CRuntimeClass* pOleFrameClass = NULL, CRuntimeClass* pOleViewClass = NULL);

	// iterating over open documents
	virtual POSITION GetFirstDocPosition() const = 0;
	virtual CDocument* GetNextDoc(POSITION& rPos) const = 0;

// Operations
public:
	virtual void AddDocument(CDocument* pDoc);      // must override
	virtual void RemoveDocument(CDocument* pDoc);   // must override

	enum DocStringIndex
	{
		windowTitle,        // default window title
		docName,            // user visible name for default document
		fileNewName,        // user visible name for FileNew
		// for file based documents:
		filterName,         // user visible name for FileOpen
		filterExt,          // user visible extension for FileOpen
		// for file based documents with Shell open support:
		regFileTypeId,      // REGEDIT visible registered file type identifier
		regFileTypeName,    // Shell visible registered file type name
	};
	virtual BOOL GetDocString(CString& rString,
		enum DocStringIndex index) const; // get one of the info strings
	CFrameWnd* CreateOleFrame(CWnd* pParentWnd, CDocument* pDoc,
		BOOL bCreateView);

// Overridables
public:
	enum Confidence
	{
		noAttempt,
		maybeAttemptForeign,
		maybeAttemptNative,
		yesAttemptForeign,
		yesAttemptNative,
		yesAlreadyOpen
	};
	virtual Confidence MatchDocType(LPCTSTR lpszPathName,
					CDocument*& rpDocMatch);
	virtual CDocument* CreateNewDocument();
	virtual CFrameWnd* CreateNewFrame(CDocument* pDoc, CFrameWnd* pOther);
	virtual void InitialUpdateFrame(CFrameWnd* pFrame, CDocument* pDoc,
		BOOL bMakeVisible = TRUE);
	virtual BOOL SaveAllModified();     // for all documents
	virtual void CloseAllDocuments(BOOL bEndSession);
	virtual CDocument* OpenDocumentFile(
		LPCTSTR lpszPathName, BOOL bMakeVisible = TRUE) = 0;
					// open named file
					// if lpszPathName == NULL => create new file with this type
	virtual void SetDefaultTitle(CDocument* pDocument) = 0;

// Implementation
public:
	BOOL m_bAutoDelete;
	virtual ~CDocTemplate() = 0;

	// back pointer to OLE or other server (NULL if none or disabled)
	CObject* m_pAttachedFactory;

	// menu & accelerator resources for in-place container
	HMENU m_hMenuInPlace;
	HACCEL m_hAccelInPlace;

	// menu & accelerator resource for server editing embedding
	HMENU m_hMenuEmbedding;
	HACCEL m_hAccelEmbedding;

	// menu & accelerator resource for server editing in-place
	HMENU m_hMenuInPlaceServer;
	HACCEL m_hAccelInPlaceServer;

#ifdef _DEBUG
	virtual void Dump(CDumpContext&) const;
	virtual void AssertValid() const;
#endif
	virtual void OnIdle();             // for all documents
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra,
		AFX_CMDHANDLERINFO* pHandlerInfo);

protected:
	UINT m_nIDResource;                 // IDR_ for frame/menu/accel as well
	UINT m_nIDServerResource;           // IDR_ for OLE inplace frame/menu/accel
	UINT m_nIDEmbeddingResource;        // IDR_ for OLE open frame/menu/accel
	UINT m_nIDContainerResource;        // IDR_ for container frame/menu/accel

	CRuntimeClass* m_pDocClass;         // class for creating new documents
	CRuntimeClass* m_pFrameClass;       // class for creating new frames
	CRuntimeClass* m_pViewClass;        // class for creating new views
	CRuntimeClass* m_pOleFrameClass;    // class for creating in-place frame
	CRuntimeClass* m_pOleViewClass;     // class for creating in-place view

	CString m_strDocStrings;    // '\n' separated names
		// The document names sub-strings are represented as _one_ string:
		// windowTitle\ndocName\n ... (see DocStringIndex enum)
};

// SDI support (1 document only)
class CSingleDocTemplate : public CDocTemplate
{
	DECLARE_DYNAMIC(CSingleDocTemplate)

// Constructors
public:
	CSingleDocTemplate(UINT nIDResource, CRuntimeClass* pDocClass,
		CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass);

// Implementation
public:
	virtual ~CSingleDocTemplate();
	virtual void AddDocument(CDocument* pDoc);
	virtual void RemoveDocument(CDocument* pDoc);
	virtual POSITION GetFirstDocPosition() const;
	virtual CDocument* GetNextDoc(POSITION& rPos) const;
	virtual CDocument* OpenDocumentFile(
		LPCTSTR lpszPathName, BOOL bMakeVisible = TRUE);
	virtual void SetDefaultTitle(CDocument* pDocument);

#ifdef _DEBUG
	virtual void Dump(CDumpContext&) const;
	virtual void AssertValid() const;
#endif //_DEBUG

protected:  // standard implementation
	CDocument* m_pOnlyDoc;
};

// MDI support (zero or more documents)
class CMultiDocTemplate : public CDocTemplate
{
	DECLARE_DYNAMIC(CMultiDocTemplate)

// Constructors
public:
	CMultiDocTemplate(UINT nIDResource, CRuntimeClass* pDocClass,
		CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass);

// Implementation
public:
	// Menu and accel table for MDI Child windows of this type
	HMENU m_hMenuShared;
	HACCEL m_hAccelTable;

	virtual ~CMultiDocTemplate();
	virtual void LoadTemplate();
	virtual void AddDocument(CDocument* pDoc);
	virtual void RemoveDocument(CDocument* pDoc);
	virtual POSITION GetFirstDocPosition() const;
	virtual CDocument* GetNextDoc(POSITION& rPos) const;
	virtual CDocument* OpenDocumentFile(
		LPCTSTR lpszPathName, BOOL bMakeVisible = TRUE);
	virtual void SetDefaultTitle(CDocument* pDocument);

#ifdef _DEBUG
	virtual void Dump(CDumpContext&) const;
	virtual void AssertValid() const;
#endif //_DEBUG

protected:  // standard implementation
	CPtrList m_docList;          // open documents of this type
	UINT m_nUntitledCount;   // start at 0, for "Document1" title
};

/////////////////////////////////////////////////////////////////////////////
// class CDocument is the main document data abstraction

class AFX_NOVTABLE CDocument : public CCmdTarget
{
	DECLARE_DYNAMIC(CDocument)

public:
// Constructors
	CDocument();

// Attributes
public:
	const CString& GetTitle() const;
	virtual void SetTitle(LPCTSTR lpszTitle);
	const CString& GetPathName() const;
	virtual void SetPathName(LPCTSTR lpszPathName, BOOL bAddToMRU = TRUE);

	CDocTemplate* GetDocTemplate() const;
	virtual BOOL IsModified();
	virtual void SetModifiedFlag(BOOL bModified = TRUE);

// Operations
	void AddView(CView* pView);
	void RemoveView(CView* pView);
	virtual POSITION GetFirstViewPosition() const;
	virtual CView* GetNextView(POSITION& rPosition) const;

	// Update Views (simple update - DAG only)
	void UpdateAllViews(CView* pSender, LPARAM lHint = 0L,
		CObject* pHint = NULL);

// Overridables
	// Special notifications
	virtual void OnChangedViewList(); // after Add or Remove view
	virtual void DeleteContents(); // delete doc items etc

	// File helpers
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();
	virtual void ReportSaveLoadException(LPCTSTR lpszPathName,
				CException* e, BOOL bSaving, UINT nIDPDefault);
	virtual CFile* GetFile(LPCTSTR lpszFileName, UINT nOpenFlags,
		CFileException* pError);
	virtual void ReleaseFile(CFile* pFile, BOOL bAbort);

	// advanced overridables, closing down frame/doc, etc.
	virtual BOOL CanCloseFrame(CFrameWnd* pFrame);
	virtual BOOL SaveModified(); // return TRUE if ok to continue
	virtual void PreCloseFrame(CFrameWnd* pFrame);

// Implementation
protected:
	// default implementation
	CString m_strTitle;
	CString m_strPathName;
	CDocTemplate* m_pDocTemplate;
	CPtrList m_viewList;                // list of views
	BOOL m_bModified;                   // changed since last saved

public:
	BOOL m_bAutoDelete;     // TRUE => delete document when no more views
	BOOL m_bEmbedded;       // TRUE => document is being created by OLE

#ifdef _DEBUG
	virtual void Dump(CDumpContext&) const;
	virtual void AssertValid() const;
#endif //_DEBUG
	virtual ~CDocument() = 0;

	// implementation helpers
	virtual BOOL DoSave(LPCTSTR lpszPathName, BOOL bReplace = TRUE);
	virtual BOOL DoFileSave();
	virtual void UpdateFrameCounts();
	void DisconnectViews();
	void SendInitialUpdate();

	// overridables for implementation
	virtual HMENU GetDefaultMenu(); // get menu depending on state
	virtual HACCEL GetDefaultAccelerator();
	virtual void OnIdle();
	virtual void OnFinalRelease();

	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra,
		AFX_CMDHANDLERINFO* pHandlerInfo);
	friend class CDocTemplate;

protected:
	// file menu commands
	//{{AFX_MSG(CDocument)
	afx_msg void OnFileClose();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	//}}AFX_MSG
	// mail enabling
	afx_msg void OnFileSendMail();
	afx_msg void OnUpdateFileSendMail(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Extra diagnostic tracing options

#ifdef _DEBUG
extern AFX_DATA UINT afxTraceFlags;
#endif // _DEBUG

#ifdef _DEBUG
#define DECLARE_AFX_TRACE_CATEGORY( name ) extern AFX_DATA ATL::CTraceCategory name;
#else
#define DECLARE_AFX_TRACE_CATEGORY( name ) const DWORD_PTR name = 0;
#endif

DECLARE_AFX_TRACE_CATEGORY( traceAppMsg )        // main message pump trace (includes DDE)
DECLARE_AFX_TRACE_CATEGORY( traceWinMsg )        // Windows message tracing
DECLARE_AFX_TRACE_CATEGORY( traceCmdRouting )    // Windows command routing trace
DECLARE_AFX_TRACE_CATEGORY( traceOle )          // special OLE callback trace
DECLARE_AFX_TRACE_CATEGORY( traceDatabase )     // special database trace
DECLARE_AFX_TRACE_CATEGORY( traceInternet )     // special Internet client trace
DECLARE_AFX_TRACE_CATEGORY( traceDumpContext )	// traces from CDumpContext
DECLARE_AFX_TRACE_CATEGORY( traceMemory )		// generic non-kernel memory traces
DECLARE_AFX_TRACE_CATEGORY( traceHtml )			// Html traces
DECLARE_AFX_TRACE_CATEGORY( traceSocket )		// Socket traces

//////////////////////////////////////////////////////////////////////////////
// MessageBox helpers

void AFXAPI AfxFormatString1(CString& rString, UINT nIDS, LPCTSTR lpsz1);
void AFXAPI AfxFormatString2(CString& rString, UINT nIDS,
				LPCTSTR lpsz1, LPCTSTR lpsz2);
int AFXAPI AfxMessageBox(LPCTSTR lpszText, UINT nType = MB_OK,
				UINT nIDHelp = 0);
int AFXAPI AfxMessageBox(UINT nIDPrompt, UINT nType = MB_OK,
				UINT nIDHelp = (UINT)-1);

// Implementation string helpers
void AFXAPI AfxFormatStrings(CString& rString, UINT nIDS,
				LPCTSTR const* rglpsz, int nString);
void AFXAPI AfxFormatStrings(CString& rString, LPCTSTR lpszFormat,
				LPCTSTR const* rglpsz, int nString);
BOOL AFXAPI AfxExtractSubString(CString& rString, LPCTSTR lpszFullString,
				int iSubString, TCHAR chSep = '\n');

/////////////////////////////////////////////////////////////////////////////
// Special target variant APIs

#ifdef _AFXDLL
	#include <afxdll_.h>
#endif

// Windows Version compatibility (obsolete)
#define AfxEnableWin30Compatibility()
#define AfxEnableWin31Compatibility()
#define AfxEnableWin40Compatibility()

// Temporary map management (locks temp map on current thread)
void AFXAPI AfxLockTempMaps();
BOOL AFXAPI AfxUnlockTempMaps(BOOL bDeleteTemps = TRUE);

/////////////////////////////////////////////////////////////////////////////
// Special OLE related functions (see OLELOCK.CPP)

void AFXAPI AfxOleOnReleaseAllObjects();
BOOL AFXAPI AfxOleCanExitApp();
void AFXAPI AfxOleLockApp();
void AFXAPI AfxOleUnlockApp();

void AFXAPI AfxOleSetUserCtrl(BOOL bUserCtrl);
BOOL AFXAPI AfxOleGetUserCtrl();

#ifndef _AFX_NO_OCC_SUPPORT
BOOL AFXAPI AfxOleLockControl(REFCLSID clsid);
BOOL AFXAPI AfxOleUnlockControl(REFCLSID clsid);
BOOL AFXAPI AfxOleLockControl(LPCTSTR lpszProgID);
BOOL AFXAPI AfxOleUnlockControl(LPCTSTR lpszProgID);
void AFXAPI AfxOleUnlockAllControls();
#endif

/////////////////////////////////////////////////////////////////////////////
// Use version 1.0 of the RichEdit control

#define _RICHEDIT_VER 0x0210

/////////////////////////////////////////////////////////////////////////////
// Inline function declarations

#ifndef GET_X_LPARAM
#define GET_X_LPARAM(lp)                        ((int)(short)LOWORD(lp))
#endif
#ifndef GET_Y_LPARAM
#define GET_Y_LPARAM(lp)                        ((int)(short)HIWORD(lp))
#endif

#ifdef _AFX_PACKING
#pragma pack(pop)
#endif

#include <afxcomctl32.inl>

#ifdef _AFX_ENABLE_INLINES
#define _AFXWIN_INLINE AFX_INLINE
#include <afxwin1.inl>
#include <afxwin2.inl>
#include <afxwin3.inl>
#endif

#include <afxwin4.inl>

#undef AFX_DATA
#define AFX_DATA

#ifdef _AFX_MINREBUILD
#pragma component(minrebuild, on)
#endif

/////////////////////////////////////////////////////////////////////////////

#else //RC_INVOKED
#include <afxres.h>     // standard resource IDs
#endif //RC_INVOKED


#ifdef _M_CEE
    #include <atliface.h>
    #include <afxole.h>
#endif

#pragma warning( pop )

#endif //__AFXWIN_H__

/////////////////////////////////////////////////////////////////////////////



/*
Module : ScintillaDocView.CPP
Purpose: Defines the implementation for MFC CView and CDocument derived wrapper classes for the Scintilla 
         edit control (www.scintilla.org).
Created: PJN / 19-03-2004
History: PJN / 12-08-2004 1. Made all the remaining non virtual functions related to Find and Replace virtual.
                          2. TextNotFound function is now passed the parameters used for the search. Thanks 
                          to Dmitry Naumov for this update.
                          3. Removed the OnTextNotFound function as all the work for it is achieved using the
                          TextNotFound function.
                          4. Creation of the find / replace dialog now takes place in a new virtual function
                          "CreateFindReplaceDialog". Again thanks to Dmitry Naumov for this update. 
         PJN / 04-03-2005 1. Fix in CScintillaView::PrintPage which now sorts out the issue of print preview
                          not working in the MFC doc / view wrappers for scintilla. Thanks to Frank Kiesel
                          for reporting this fix.
         PJN / 10-07-2005 1. Addition of a virtual function namely OnAutoCSelection which handles the
                          SCN_AUTOCSELECTION notification message which was introduced in Scintilla v1.63.
                          Thanks to Dan Petitt for suggesting this update.
                          2. A new boolean variable called "m_bUseROFileAttributeDuringLoading" has been added 
                          to CScintillaView. If this value is set then the code will check the read only file
                          attribute of the file being loaded and if it is set, then the document is marked as 
                          read only by Scintilla. By doing this any attempts to modify the document will cause 
                          the OnModifyAttemptRO virtual function to be called. This allows you to prompt to 
                          make the file read write or to check out the file from a version control system. 
                          Thanks to Dan Petitt for suggesting this update.
                          3. Demo app now demonstrates how to use the SCN_MODIFYATTEMPTRO notification.
                          4. Fixed a number of warnings when the code is compiled using Visual Studio .NET 2003.
                          5. SetSavePoint and SetReadOnly calls are now made in CScintillaDoc::OnSaveDocument
                          instead of CScintillaView::Serialize. This ensures that the control is only reset
                          upon a successful save.
         PJN / 03-01-2006 1. Fixed a bug where the separator line in the header was not being drawn due to 
                          issues in the code which calculates the coordinates. 
                          2. Added two member variables which decide whether printer headers and footers should
                          be printed (CScintillaView::m_bPrintHeader and CScintillaView::m_bPrintFooter). You
                          could of course achieve the same result by deriving a class from CScintillaView and 
                          implementing empty PrintHeader and PrinterFooter methods!!!. Thanks to Jason Elliott
                          for suggesting this update.
                          3. Optimized the construction of member variables in CScintillaView::CScintillaView
                          and in CScintillaFindReplaceDlg::CScintillaFindReplaceDlg
                          4. CScintillaView::OnReplaceAll sets the selection to 0,0 before doing text replacement. 
                          This ensures that all text in a document is replaced. Also this function now does not 
                          bother calling TextNotFound at the end of the function if replacements took place. 
                          Thanks to Jason Elliott for this nice update. 
                          5. A parameter which indicates whether text is being replaced or found is now sent to
                          CScintillaView::TextNotFound.
         PJN / 06-01-2006 1. Removed some unnecessary code from CScintillaView::OnEndPrinting. Thanks to 
                          Greg Smith for spotting this issue.
         PJN / 08-01-2006 1. Find / Replace dialog and associated state is now maintained outside of CScintillaView.
                          This means that if you have multiple CScintillaView's in your app, that they share the
                          one find / replace dialog which is the standard type of UI you would normally expect for 
                          this. Thanks to Greg Smith for reporting this issue.
                          2. Find / replace dialog is now closed when the last CScintillaView is destroyed. Thanks
                          to Greg Smith for reporting this issue.
         PJN / 16-01-2006 1. Removed an unused "rSetup" variable in CScintillaView::PrintPage
                          2. Optimized code in CScintillaView::PrintPage and CScintillaView::OnFilePageSetup which
                          determines if metric or imperial measurements are being used. Now a boolean member variable
                          of CScintillaView called m_bUsingMetric which by default picks up the control panel
                          preference is provided. This allows client code to change this value to customize how
                          measurements are specified. Thanks to Greg Smith for reporting this issue.
                          3. Fixed a small typo in CScintillaView::PrintHeader and PrintFooter. Also explicitly uses
                          the TA_TOP flag in combination with TA_LEFT when setting alignment settings for header
                          and footer text. Again thanks to Greg Smith for reporting this.
                          4. Scintilla find / replace state is now stored in a standard global variable instead of
                          using the CProcessLocal template which it was using previously. This is no longer required
                          since it was used to provide Win32s support for MFC on older versions of MFC. Since Win32s
                          is no longer supported by MFC, there is no need to use this mechanism any more.
         PJN / 02-02-2006 1. Minor update to CScintillaView to allow deletion of text when there is nothing selected. 
                          Thanks to Alexander Kirillov for reporting this bug. 
         PJN / 14-03-2006 1. Updated the internal function CScintillaView::SameAsSelected to support regular 
                          expressions. Thanks to Greg Smith for this update.
         PJN / 22-05-2006 1. Fixed a flicker issue when the view is resized. Thanks to Michael Gunlock for reporting 
                          this issue.
         PJN / 29-06-2005 1. Code now uses new C++ style casts rather than old style C casts where necessary. 
                          2. Code now supports persisting margin settings. Thanks to Krasimir Stoychev for this update
                          3. Updated the code to clean compile in VC 2005
         PJN / 17-09-2006 1. Updated OnReplaceSel and OnReplaceAll implementations to use TargetFromSelection and 
                          ReplaceTargetRE/ReplaceTarget. Thanks to Matt Spear for reporting this issue.
         PJN / 11-06-2007 1. Addition of a SCINTILLADOCVIEW_EXT_CLASS preprocessor macro to allow the classes to be 
                          more easily used in an extension DLL.
         PJN / 19-03-2008 1. Fixed a copy and paste bug in CScintillaView::PrintPage where the incorrect margin value
                          was being used in the calculation of "rfPrint.rc.left". Thanks to Steve Arnold for reporting
                          this bug.

Copyright (c) 2004 - 2008 by PJ Naughter (Web: www.naughter.com, Email: pjna@naughter.com)

All rights reserved.

Copyright / Usage Details:

You are allowed to include the source code in any product (commercial, shareware, freeware or otherwise) 
when your product is released in binary form. You are allowed to modify the source code in any way you want 
except you cannot modify the copyright details at the top of each module. If you want to distribute source 
code with your application, then you are only allowed to distribute versions released by the author. This is 
to maintain a single distribution point for the source code. 

*/


/////////////////////////////////  Includes  //////////////////////////////////

#include "stdafx.h"
#include "stdafx.h"
/*
Module : ScintillaDocView.H
Purpose: Defines the interface for MFC CView and CDocument derived wrapper classes for the Scintilla 
         edit control (www.scintilla.org)
Created: PJN / 19-03-2004

Copyright (c) 2004 - 2008 by PJ Naughter (Web: www.naughter.com, Email: pjna@naughter.com)

All rights reserved.

Copyright / Usage Details:

You are allowed to include the source code in any product (commercial, shareware, freeware or otherwise) 
when your product is released in binary form. You are allowed to modify the source code in any way you want 
except you cannot modify the copyright details at the top of each module. If you want to distribute source 
code with your application, then you are only allowed to distribute versions released by the author. This is 
to maintain a single distribution point for the source code. 

*/


//////////////////// Macros / Defines /////////////////////////////////////////

#pragma once

#ifndef __SCINTILLADOCVIEW_H__
#define __SCINTILLADOCVIEW_H__


#include "ScintillaCtrl.h"

#ifndef __AFXTEMPL_H__
#pragma message("To avoid this message please put afxtempl.h into your pre compiled header (normally stdafx.h)")
#include <afxtempl.h>
#endif //__AFXTEMPL_H__

#ifndef SCINTILLADOCVIEW_EXT_CLASS
#define SCINTILLADOCVIEW_EXT_CLASS
#endif


//////////////////// Classes //////////////////////////////////////////////////

class SCINTILLADOCVIEW_EXT_CLASS CScintillaFindReplaceDlg : public CFindReplaceDialog
{
public:
//Constructors / Destructors
  CScintillaFindReplaceDlg();

//Methods
  BOOL Create(BOOL bFindDialogOnly, LPCTSTR lpszFindWhat, LPCTSTR lpszReplaceWith = NULL, DWORD dwFlags = FR_DOWN, CWnd* pParentWnd = NULL);
  BOOL GetRegularExpression() const { return m_bRegularExpression; };
  void SetRegularExpression(BOOL bRegularExpression) { m_bRegularExpression = bRegularExpression; };
  static CScintillaFindReplaceDlg* GetFindReplaceDlg();

protected:
	virtual BOOL OnInitDialog();

  afx_msg void OnRegularExpression();

//Member variables
  BOOL m_bRegularExpression;

	DECLARE_MESSAGE_MAP()
};

class SCINTILLADOCVIEW_EXT_CLASS CScintillaView : public CView
{
public:
//Constructors / Destructors
  CScintillaView();

//Methods
  CScintillaCtrl& GetCtrl();
	void            SetMargins(const CRect& rMargin) { m_rMargin = rMargin; };
	CRect           GetMargins() const { return m_rMargin; };
  BOOL            GetUseROFileAttributeDuringLoading() const { return m_bUseROFileAttributeDuringLoading; };
  void            SetUseROFileAttributeDuringLoading(BOOL bUseROFileAttributeDuringLoading) { m_bUseROFileAttributeDuringLoading = bUseROFileAttributeDuringLoading; };

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
//Printing support
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo = NULL);
	virtual BOOL PaginateTo(CDC* pDC, CPrintInfo* pInfo);
	virtual long PrintPage(CDC* pDC, CPrintInfo* pInfo, long nIndexStart, long nIndexStop);
  virtual void PrintHeader(CDC* pDC, CPrintInfo* pInfo, RangeToFormat& frPrint);
  virtual void PrintFooter(CDC* pDC, CPrintInfo* pInfo, RangeToFormat& frPrint);

//Search and Replace support
	virtual void OnFindNext(LPCTSTR lpszFind, BOOL bNext, BOOL bCase, BOOL bWord, BOOL bRegularExpression);
	virtual void TextNotFound(LPCTSTR lpszFind, BOOL bNext, BOOL bCase, BOOL bWord, BOOL bRegularExpression, BOOL bReplaced);
  virtual BOOL FindText(LPCTSTR lpszFind, BOOL bNext, BOOL bCase, BOOL bWord, BOOL bRegularExpression);
	virtual void OnEditFindReplace(BOOL bFindOnly);
	virtual BOOL FindTextSimple(LPCTSTR lpszFind, BOOL bNext, BOOL bCase, BOOL bWord, BOOL bRegularExpression);
	virtual void OnReplaceSel(LPCTSTR lpszFind, BOOL bNext, BOOL bCase,	BOOL bWord, BOOL bRegularExpression, LPCTSTR lpszReplace);
	virtual void OnReplaceAll(LPCTSTR lpszFind, LPCTSTR lpszReplace, BOOL bCase, BOOL bWord, BOOL bRegularExpression);
	void GetReplaceAllTarget(long& s, long& e);
	virtual BOOL SameAsSelected(LPCTSTR lpszCompare, BOOL bCase, BOOL bWord, BOOL bRegularExpression);
	virtual long FindAndSelect(DWORD dwFlags, TextToFind& ft);
  virtual void AdjustFindDialogPosition();
  virtual CScintillaFindReplaceDlg* CreateFindReplaceDialog();

//Misc methods
	virtual void OnDraw(CDC*);
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	virtual void DeleteContents();
	virtual void Serialize(CArchive& ar);
  virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
  virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
  static BOOL UserWantsMetric();
  virtual void LoadMarginSettings(const CString& sSection = _T("PageSetup"));
  virtual void SaveMarginSettings(const CString& sSection = _T("PageSetup"));

//Notifications
  virtual void OnStyleNeeded(SCNotification* pSCNotification);
  virtual void OnCharAdded(SCNotification* pSCNotification);
  virtual void OnSavePointReached(SCNotification* pSCNotification);
  virtual void OnSavePointLeft(SCNotification* pSCNotification);
  virtual void OnModifyAttemptRO(SCNotification* pSCNotification);
  virtual void OnDoubleClick(SCNotification* pSCNotification);
  virtual void OnUpdateUI(SCNotification* pSCNotification);
  virtual void OnModified(SCNotification* pSCNotification);
  virtual void OnMacroRecord(SCNotification* pSCNotification);
  virtual void OnMarginClick(SCNotification* pSCNotification);
  virtual void OnNeedShown(SCNotification* pSCNotification);
  virtual void OnPainted(SCNotification* pSCNotification);
  virtual void OnUserListSelection(SCNotification* pSCNotification);
  virtual void OnDwellStart(SCNotification* pSCNotification);
  virtual void OnDwellEnd(SCNotification* pSCNotification);
  virtual void OnZoom(SCNotification* pSCNotification);
  virtual void OnHotSpotClick(SCNotification* pSCNotification);
  virtual void OnHotSpotDoubleClick(SCNotification* pSCNotification);
  virtual void OnCallTipClick(SCNotification* pSCNotification);
  virtual void OnAutoCSelection(SCNotification* pSCNotification);
  virtual void OnChange();
  virtual void OnSetFocus();
  virtual void OnKillFocus();

//Member variables
  CScintillaCtrl   m_Edit;                             //The scintilla control
	CArray<int, int> m_aPageStart;                       //array of starting pages
	CRect            m_rMargin;                          //Margin for printing
	BOOL             m_bFirstSearch;                     //Is this the first search
  BOOL             m_bUseROFileAttributeDuringLoading; //Should we check the RO file attribute to see if the file should be opened in read only mode by scintilla
  BOOL             m_bPrintHeader;                     //Should Headers be printed?
  BOOL             m_bPrintFooter;                     //Should Footers be printed?
  BOOL             m_bUsingMetric;                     //TRUE if the margin is specified in Metric units, else FALSE implies imperial
  BOOL             m_bPersistMarginSettings;           //Should we persist the margin settings for the Page Setup dialog

	afx_msg void OnPaint();
	afx_msg void OnUpdateNeedSel(CCmdUI* pCmdUI);
  afx_msg void OnUpdateNeedPaste(CCmdUI* pCmdUI);
	afx_msg void OnUpdateNeedText(CCmdUI* pCmdUI);
	afx_msg void OnUpdateNeedFind(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditUndo(CCmdUI* pCmdUI);
  afx_msg void OnUpdateEditRedo(CCmdUI* pCmdUI);
  afx_msg void OnUpdateNeedTextAndFollowingText(CCmdUI* pCmdUI);
	afx_msg void OnEditCut();
	afx_msg void OnEditCopy();
	afx_msg void OnEditPaste();
	afx_msg void OnEditClear();
	afx_msg void OnEditUndo();
  afx_msg void OnEditRedo();
	afx_msg void OnEditSelectAll();
	afx_msg void OnEditFind();
	afx_msg void OnEditReplace();
	afx_msg void OnEditRepeat();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnFilePageSetup();
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg LRESULT OnFindReplaceCmd(WPARAM, LPARAM lParam);

	DECLARE_MESSAGE_MAP()

  DECLARE_DYNCREATE(CScintillaView)

  friend class CScintillaDoc;
};

class SCINTILLADOCVIEW_EXT_CLASS CScintillaDoc : public CDocument
{
protected: //create from serialization only
	CScintillaDoc();
	DECLARE_DYNAMIC(CScintillaDoc)

//Attributes
public:
	virtual CScintillaView* GetView() const;

//Implementation
public:
	virtual void DeleteContents();
	virtual BOOL IsModified();
	virtual void SetModifiedFlag(BOOL bModified = TRUE);
	virtual void Serialize(CArchive& ar);
  virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

#endif //__SCINTILLADOCVIEW_H__

#ifndef __AFXDISP_H__
#pragma message("To avoid this message, please put afxdisp.h in your pre compiled header (normally stdafx.h)")
#include <afxdisp.h>
#endif
#include "resource.h"




//////////////////////////////// Statics / Macros /////////////////////////////

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


////////////////////////////////// Implementation /////////////////////////////

class _SCINTILLA_EDIT_STATE
{
public:
//Constructors / Destructors
	_SCINTILLA_EDIT_STATE();

//Member variables
	CScintillaFindReplaceDlg* pFindReplaceDlg;    //find or replace dialog
	BOOL                      bFindOnly;          //Is pFindReplace the find or replace?
	CString                   strFind;            //last find string
	CString                   strReplace;         //last replace string
	BOOL                      bCase;              //TRUE==case sensitive, FALSE==not
	int                       bNext;              //TRUE==search down, FALSE== search up
	BOOL                      bWord;              //TRUE==match whole word, FALSE==not
  BOOL                      bRegularExpression; //TRUE==regular expression search, FALSE==not
};

_SCINTILLA_EDIT_STATE::_SCINTILLA_EDIT_STATE() : bRegularExpression(FALSE),
                                                 pFindReplaceDlg(NULL),
               	                                 bWord(FALSE),
                                                 bFindOnly(TRUE),
	                                               bCase(FALSE),
	                                               bNext(TRUE)
{
}

_SCINTILLA_EDIT_STATE _scintillaEditState;

CScintillaFindReplaceDlg* CScintillaFindReplaceDlg::GetFindReplaceDlg()
{
	return _scintillaEditState.pFindReplaceDlg;
}

BEGIN_MESSAGE_MAP(CScintillaFindReplaceDlg, CFindReplaceDialog)
  ON_BN_CLICKED(IDC_REGULAR_EXPRESSION, OnRegularExpression)
END_MESSAGE_MAP()


CScintillaFindReplaceDlg::CScintillaFindReplaceDlg(): m_bRegularExpression(FALSE)
{
}

BOOL CScintillaFindReplaceDlg::Create(BOOL bFindDialogOnly,	LPCTSTR lpszFindWhat, LPCTSTR lpszReplaceWith, DWORD dwFlags, CWnd* pParentWnd)
{
  //Tell Windows to use our dialog instead of the standard one
  m_fr.hInstance = AfxGetResourceHandle();
  m_fr.Flags |= FR_ENABLETEMPLATE;
  if (bFindDialogOnly)
    m_fr.lpTemplateName = MAKEINTRESOURCE(IDD_SCINTILLA_FINDDLGORD);
  else
    m_fr.lpTemplateName = MAKEINTRESOURCE(IDD_SCINTILLA_REPLACEDLGORD);

  //Let the base class do its thing
  return CFindReplaceDialog::Create(bFindDialogOnly,	lpszFindWhat, lpszReplaceWith, dwFlags, pParentWnd);
}

BOOL CScintillaFindReplaceDlg::OnInitDialog() 
{
  //let the base class do its thing
	BOOL bReturn = CFindReplaceDialog::OnInitDialog();

  //Should we check the regular expression check box
  CButton* pCtrl = static_cast<CButton*>(GetDlgItem(IDC_REGULAR_EXPRESSION));
  AFXASSUME(pCtrl);
  pCtrl->SetCheck(m_bRegularExpression);
	
	return bReturn;
}

void CScintillaFindReplaceDlg::OnRegularExpression() 
{
  //Save the state of the Regular expression checkbox into a member variable
  CButton* pCtrl = static_cast<CButton*>(GetDlgItem(IDC_REGULAR_EXPRESSION));
  AFXASSUME(pCtrl);
	m_bRegularExpression = (pCtrl->GetCheck() == 1);
}


IMPLEMENT_DYNCREATE(CScintillaView, CView)

const UINT _ScintillaMsgFindReplace = ::RegisterWindowMessage(FINDMSGSTRING);

BEGIN_MESSAGE_MAP(CScintillaView, CView)
	ON_WM_PAINT()
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateNeedSel)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateNeedPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_FIND, OnUpdateNeedText)
	ON_UPDATE_COMMAND_UI(ID_EDIT_REPEAT, OnUpdateNeedFind)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, OnUpdateEditUndo)
  ON_UPDATE_COMMAND_UI(ID_EDIT_REDO, OnUpdateEditRedo)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_COMMAND(ID_EDIT_CLEAR, OnEditClear)
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
  ON_COMMAND(ID_EDIT_REDO, OnEditRedo)
	ON_COMMAND(ID_EDIT_SELECT_ALL, OnEditSelectAll)
	ON_COMMAND(ID_EDIT_FIND, OnEditFind)
	ON_COMMAND(ID_EDIT_REPLACE, OnEditReplace)
	ON_COMMAND(ID_EDIT_REPEAT, OnEditRepeat)
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateNeedSel)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR, OnUpdateNeedTextAndFollowingText)
	ON_UPDATE_COMMAND_UI(ID_EDIT_SELECT_ALL, OnUpdateNeedText)
	ON_UPDATE_COMMAND_UI(ID_EDIT_REPLACE, OnUpdateNeedText)
	ON_COMMAND(ID_FILE_PAGE_SETUP, OnFilePageSetup)
	ON_WM_DESTROY()
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
 	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_REGISTERED_MESSAGE(_ScintillaMsgFindReplace, OnFindReplaceCmd)
END_MESSAGE_MAP()

CScintillaView::CScintillaView() : m_rMargin(0, 0, 0, 0), 
                                   m_bFirstSearch(TRUE),
                                   m_bUseROFileAttributeDuringLoading(TRUE),
                                   m_bPrintHeader(TRUE), 
                                   m_bPrintFooter(TRUE),
                                   m_bPersistMarginSettings(TRUE),
                                   m_bUsingMetric(UserWantsMetric())
{
}

CScintillaCtrl& CScintillaView::GetCtrl()
{ 
  CScintillaCtrl& ctrl = m_Edit;

  return ctrl; 
}

void CScintillaView::LoadMarginSettings(const CString& sSection)
{
  //Get the margin values 
  CWinApp* pApp = AfxGetApp();
  AFXASSUME(pApp);
	m_rMargin.left = pApp->GetProfileInt(sSection, _T("LeftMargin"), m_rMargin.left);
	m_rMargin.right = pApp->GetProfileInt(sSection, _T("RightMargin"), m_rMargin.right);
	m_rMargin.top = pApp->GetProfileInt(sSection, _T("TopMargin"), m_rMargin.top);
	m_rMargin.bottom = pApp->GetProfileInt(sSection, _T("BottomMargin"), m_rMargin.bottom);
}

void CScintillaView::SaveMarginSettings(const CString& sSection)
{
  //Write out the margin values 
  CWinApp* pApp = AfxGetApp();
  AFXASSUME(pApp);
	pApp->WriteProfileInt(sSection, _T("LeftMargin"), m_rMargin.left);
	pApp->WriteProfileInt(sSection, _T("RightMargin"), m_rMargin.right);
	pApp->WriteProfileInt(sSection, _T("TopMargin"), m_rMargin.top);
	pApp->WriteProfileInt(sSection, _T("BottomMargin"), m_rMargin.bottom);
}

void CScintillaView::OnDestroy()
{
  //Close Find/Replace dialog if this is the last CScintillaView
	if (_scintillaEditState.pFindReplaceDlg)
	{
		CWinApp* pApp = AfxGetApp();

    //Count up the number of CScintillaView's we have (excluding this one)
    int nScintillaViews = 0;

		//no doc manager - no templates
		if (pApp->m_pDocManager)
		{
			//walk all templates
			CDocTemplate* pTemplate;
			POSITION pos = pApp->m_pDocManager->GetFirstDocTemplatePosition();
			while (pos && (nScintillaViews == 0))
			{
				pTemplate = pApp->m_pDocManager->GetNextDocTemplate(pos);
				AFXASSUME(pTemplate);

				//walk all documents in the template
				POSITION pos2 = pTemplate->GetFirstDocPosition();
				while (pos2 && (nScintillaViews == 0))
				{
					CDocument* pDoc = pTemplate->GetNextDoc(pos2);
					ASSERT(pDoc);

					//walk all views in the document
					POSITION pos3 = pDoc->GetFirstViewPosition();
					while (pos3 && (nScintillaViews == 0))
					{
						CView* pView = pDoc->GetNextView(pos3);
						ASSERT(pView);
						
						//if we find another CScintillaView, skip code that closes find dialog
						if (pView->IsKindOf(RUNTIME_CLASS(CScintillaView)) && (pView != this) && ::IsWindow(pView->GetSafeHwnd()))
							++nScintillaViews;
					}
				}
			}
		}

    //Close down the find/replace dialog if we are the last CScintillaView
		if (nScintillaViews == 0)
    {
      if (::IsWindow(_scintillaEditState.pFindReplaceDlg->m_hWnd))
			  _scintillaEditState.pFindReplaceDlg->SendMessage(WM_CLOSE);
		  _scintillaEditState.pFindReplaceDlg = NULL;
    }
	}

  //Let the base class do its thing
  CView::OnDestroy();
}

void CScintillaView::DeleteContents()
{
	ASSERT_VALID(this);
	ASSERT(m_hWnd != NULL);

  CScintillaCtrl& rCtrl = GetCtrl();
	rCtrl.ClearAll();
  rCtrl.EmptyUndoBuffer();
}

void CScintillaView::OnDraw(CDC*)
{
	ASSERT(FALSE);
}

void CScintillaView::OnPaint()
{
	//this is done to avoid CView::OnPaint
	Default();
}

BOOL CScintillaView::OnPreparePrinting(CPrintInfo* pInfo)
{
  //Determine if we should allow selection printing
  CScintillaCtrl& rCtrl = GetCtrl();

  long nStartChar = rCtrl.GetSelectionStart();
  long nEndChar = rCtrl.GetSelectionEnd();
  if (nStartChar != nEndChar)
  {
    // Enable the Selection button
    pInfo->m_pPD->m_pd.Flags &= ~PD_NOSELECTION;

    // Check the Selection button
    pInfo->m_pPD->m_pd.Flags |= PD_SELECTION;
  }

  //Let the base class do its thing
  return DoPreparePrinting(pInfo);
}

void CScintillaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* pInfo)
{
  //Validate our parameters
	ASSERT_VALID(this);

  CScintillaCtrl& rCtrl = GetCtrl();

	//initialize page start vector
	ASSERT(m_aPageStart.GetSize() == 0);
  if (pInfo->m_pPD->PrintSelection())
    m_aPageStart.Add(rCtrl.GetSelectionStart());
  else
	  m_aPageStart.Add(0);
	ASSERT(m_aPageStart.GetSize() > 0);

	ASSERT_VALID(this);
}

BOOL CScintillaView::PaginateTo(CDC* pDC, CPrintInfo* pInfo)
{
  //Validate our parameters
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

  CRect rectSave = pInfo->m_rectDraw;
	UINT nPageSave = pInfo->m_nCurPage;
	ASSERT(nPageSave > 1);
	ASSERT(nPageSave >= static_cast<UINT>(m_aPageStart.GetSize()));
	VERIFY(pDC->SaveDC() != 0);
	pDC->IntersectClipRect(0, 0, 0, 0);
	pInfo->m_nCurPage = m_aPageStart.GetSize();
	while (pInfo->m_nCurPage < nPageSave)
	{
		ASSERT(pInfo->m_nCurPage == static_cast<UINT>(m_aPageStart.GetSize()));
		OnPrepareDC(pDC, pInfo);
		ASSERT(pInfo->m_bContinuePrinting);
		pInfo->m_rectDraw.SetRect(0, 0,	pDC->GetDeviceCaps(HORZRES), pDC->GetDeviceCaps(VERTRES));
		OnPrint(pDC, pInfo);
		if (pInfo->m_nCurPage == static_cast<UINT>(m_aPageStart.GetSize()))
			break;
		++pInfo->m_nCurPage;
	}
	BOOL bResult = pInfo->m_nCurPage == nPageSave;
	pDC->RestoreDC(-1);
	pInfo->m_nCurPage = nPageSave;
  pInfo->m_rectDraw = rectSave;
	ASSERT_VALID(this);
	return bResult;
}

void CScintillaView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
  //Validate our parameters
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);
	AFXASSUME(pInfo != NULL);

  if (pInfo->m_nCurPage <= pInfo->GetMaxPage())
  {
	  if ((pInfo->m_nCurPage > static_cast<UINT>(m_aPageStart.GetSize())) &&	!PaginateTo(pDC, pInfo))
	  {
		  //can't paginate to that page, thus cannot print it.
		  pInfo->m_bContinuePrinting = FALSE;
	  }
	  ASSERT_VALID(this);
  }
  else
  {
		//Reached the max page to print
		pInfo->m_bContinuePrinting = FALSE;
  }
}

void CScintillaView::PrintHeader(CDC* pDC, CPrintInfo* /*pInfo*/, RangeToFormat& frPrint)
{
  //By Default we print "Document Name - Printed on Date" as well as a line separator below the text
  //Derived classes are of course free to implement their own version of PrintHeader
  CString sHeader;
  AfxFormatString2(sHeader, IDS_SCINTILLA_DEFAULT_PRINT_HEADER, GetDocument()->GetTitle(), COleDateTime::GetCurrentTime().Format());

  //Setup the DC
  pDC->SetTextColor(RGB(0, 0, 0));
  UINT nAlign = pDC->SetTextAlign(TA_LEFT | TA_TOP);

  //Draw the header
  CSize sizeText = pDC->GetTextExtent(sHeader);
  int nHeaderDepth = 2*sizeText.cy;
	CRect rLine(frPrint.rcPage.left, frPrint.rcPage.top, frPrint.rcPage.right, frPrint.rcPage.top + nHeaderDepth);
  pDC->ExtTextOut(frPrint.rcPage.left, frPrint.rcPage.top + nHeaderDepth/3, 0, &rLine, sHeader, NULL);

  //Draw a line underneath the text
  pDC->MoveTo(frPrint.rcPage.left, frPrint.rcPage.top + nHeaderDepth - 5);
  pDC->LineTo(frPrint.rcPage.right, frPrint.rcPage.top + nHeaderDepth - 5);

  //Restore the DC
  pDC->SetTextAlign(nAlign);

  //Adjust the place where scintilla will draw the text
  if (frPrint.rc.top < (frPrint.rcPage.top + nHeaderDepth))
    frPrint.rc.top = frPrint.rcPage.top + nHeaderDepth;
}

void CScintillaView::PrintFooter(CDC* pDC, CPrintInfo* pInfo, RangeToFormat& frPrint)
{
  //By Default we print "Page X" as well as a line separator above the text
  //Derived classes are of course free to implement their own version of PrintFooter
  CString sPage;
  sPage.Format(_T("%d"), pInfo->m_nCurPage);
  CString sFooter;
  AfxFormatString1(sFooter, IDS_SCINTILLA_DEFAULT_PRINT_FOOTER, sPage);

  //Setup the DC
  pDC->SetTextColor(RGB(0, 0, 0));
  UINT nAlign = pDC->SetTextAlign(TA_LEFT | TA_TOP);
  
  //Draw the header
  CSize sizeText = pDC->GetTextExtent(sFooter);
  int nFooterDepth = 2*sizeText.cy;
  CRect rLine(frPrint.rcPage.left, frPrint.rcPage.bottom - nFooterDepth, frPrint.rcPage.right, frPrint.rcPage.bottom);
  pDC->ExtTextOut(frPrint.rcPage.left, frPrint.rcPage.bottom - nFooterDepth*2/3, 0, &rLine, sFooter, NULL);

  //Draw a line above the text
  pDC->MoveTo(frPrint.rcPage.left, frPrint.rcPage.bottom - nFooterDepth + 5);
  pDC->LineTo(frPrint.rcPage.right, frPrint.rcPage.bottom - nFooterDepth + 5);

  //Restore the DC
  pDC->SetTextAlign(nAlign);

  //Adjust the place where scintilla will draw the text
  if (frPrint.rc.bottom > (frPrint.rcPage.bottom - nFooterDepth))
    frPrint.rc.bottom = frPrint.rcPage.bottom - nFooterDepth;
}

BOOL CScintillaView::UserWantsMetric()
{
  TCHAR localeInfo[3];
  localeInfo[0] = _T('\0');
  GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_IMEASURE, localeInfo, 3);
  return (localeInfo[0] == _T('0')) ;
}

long CScintillaView::PrintPage(CDC* pDC, CPrintInfo* pInfo, long nIndexStart, long nIndexStop)
{
  //Validate our parameters
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	RangeToFormat rfPrint;
	rfPrint.hdc = pDC->m_hDC;
	rfPrint.hdcTarget = pDC->m_hAttribDC;

	//Take into account the specified margins
  CRect rMargins;
	if ((m_rMargin.left) != 0 || (m_rMargin.right) != 0 || (m_rMargin.top) != 0 || (m_rMargin.bottom != 0)) 
  {
    //Get printer resolution
    CPoint pDpi;
    pDpi.x = pDC->GetDeviceCaps(LOGPIXELSX);  //DPI in X direction
    pDpi.y = pDC->GetDeviceCaps(LOGPIXELSY);  //DPI in Y direction

		//Convert the hundredths of millimeters or thousandths of inches margin values
		//from the Page Setup dialog to device units.
		int iScale = m_bUsingMetric ? 2540 : 1000;    //scale factor for margin scaling;
		rMargins.left   = MulDiv(m_rMargin.left, pDpi.x, iScale);
		rMargins.top    = MulDiv(m_rMargin.top, pDpi.y, iScale);
		rMargins.right	= MulDiv(m_rMargin.right, pDpi.x, iScale);
		rMargins.bottom	= MulDiv(m_rMargin.bottom, pDpi.y, iScale);
	} 
  else 
		rMargins = m_rMargin;

  //We take the page size from the pInfo member variable (decrement the right and
  //bottom values by 1 to suit Scintilla)
	rfPrint.rcPage.left = pInfo->m_rectDraw.left;
	rfPrint.rcPage.top = pInfo->m_rectDraw.top;
	rfPrint.rcPage.right = pInfo->m_rectDraw.right - 1;
	rfPrint.rcPage.bottom = pInfo->m_rectDraw.bottom - 1;

  //Fill in the area to print
  rfPrint.rc.left = rfPrint.rcPage.left + rMargins.left;
  rfPrint.rc.top = rfPrint.rcPage.top + rMargins.top;
  rfPrint.rc.right = rfPrint.rcPage.right - rMargins.right;
  rfPrint.rc.bottom = rfPrint.rcPage.bottom - rMargins.bottom;

  //Fill in the text to print
	rfPrint.chrg.cpMin = nIndexStart;
	rfPrint.chrg.cpMax = nIndexStop;

  //Print the header (if requested to)
  if (m_bPrintHeader)
    PrintHeader(pDC, pInfo, rfPrint);

  //Print the footer (if requested to)
  if (m_bPrintFooter)
    PrintFooter(pDC, pInfo, rfPrint);

  //Finally ask the control to print the text
  return GetCtrl().FormatRange(TRUE, &rfPrint);
}

void CScintillaView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
  //Validate our parameters
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);
	AFXASSUME(pInfo != NULL);
	ASSERT(pInfo->m_bContinuePrinting);

	UINT nPage = pInfo->m_nCurPage;
	ASSERT(nPage <= (UINT) m_aPageStart.GetSize());
	int nIndex = m_aPageStart[nPage-1];

  //Determine where we should end the printing
  int nEndPrint = 0;
  if (pInfo->m_pPD->PrintSelection())
    nEndPrint = GetCtrl().GetSelectionEnd();
  else
    nEndPrint = GetCtrl().GetTextLength();

	//print as much as possible in the current page.
	nIndex = PrintPage(pDC, pInfo, nIndex, nEndPrint);
	if (nIndex >= nEndPrint)
	{
		TRACE0("End of Document\n");
		pInfo->SetMaxPage(nPage);
	}

	//update pagination information for page just printed
	if (nPage == (UINT) m_aPageStart.GetSize())
	{
		if (nIndex < nEndPrint)
			m_aPageStart.Add(nIndex);
	}
	else
	{
		ASSERT(nPage+1 <= static_cast<UINT>(m_aPageStart.GetSize()));
		ASSERT(nIndex == m_aPageStart[nPage+1-1]);
	}
}

void CScintillaView::OnEndPrinting(CDC*, CPrintInfo*)
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	m_aPageStart.RemoveAll();
}

void CScintillaView::OnUpdateNeedPaste(CCmdUI* pCmdUI)
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	pCmdUI->Enable(GetCtrl().CanPaste());
}

void CScintillaView::OnUpdateNeedText(CCmdUI* pCmdUI)
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	pCmdUI->Enable(GetCtrl().GetTextLength() != 0);
}

void CScintillaView::OnUpdateNeedTextAndFollowingText(CCmdUI* pCmdUI)
{
  //Validate our parameters
	ASSERT_VALID(this);

  CScintillaCtrl& rCtrl = GetCtrl();
  int nLength = rCtrl.GetTextLength();
  long nStartChar = rCtrl.GetSelectionStart();

	pCmdUI->Enable(nLength && (nStartChar != nLength));
}

void CScintillaView::OnUpdateNeedFind(CCmdUI* pCmdUI)
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	pCmdUI->Enable(GetCtrl().GetLength() != 0 && !_scintillaEditState.strFind.IsEmpty());
}

void CScintillaView::OnUpdateEditUndo(CCmdUI* pCmdUI)
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	pCmdUI->Enable(GetCtrl().CanUndo());
}

void CScintillaView::OnUpdateEditRedo(CCmdUI* pCmdUI)
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	pCmdUI->Enable(GetCtrl().CanRedo());
}

void CScintillaView::OnUpdateNeedSel(CCmdUI* pCmdUI)
{
  //Validate our parameters
	ASSERT_VALID(this);
	
  CScintillaCtrl& rCtrl = GetCtrl();
  long nStartChar = rCtrl.GetSelectionStart();
  long nEndChar = rCtrl.GetSelectionEnd();
	pCmdUI->Enable(nStartChar != nEndChar);
}

void CScintillaView::OnEditCut()
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	GetCtrl().Cut();
}

void CScintillaView::OnEditCopy()
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	GetCtrl().Copy();
}

void CScintillaView::OnEditPaste()
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	GetCtrl().Paste();
}

void CScintillaView::OnEditClear()
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	GetCtrl().Clear();
}

void CScintillaView::OnEditUndo()
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	GetCtrl().Undo();
}

void CScintillaView::OnEditRedo()
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	GetCtrl().Redo();
}

void CScintillaView::OnEditSelectAll()
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	GetCtrl().SelectAll();
}

void CScintillaView::OnEditFind()
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	OnEditFindReplace(TRUE);
}

void CScintillaView::OnEditReplace()
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	OnEditFindReplace(FALSE);
}

void CScintillaView::OnEditRepeat()
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	if (!FindText(_scintillaEditState.strFind, _scintillaEditState.bNext, _scintillaEditState.bCase, _scintillaEditState.bWord, _scintillaEditState.bRegularExpression))
		TextNotFound(_scintillaEditState.strFind, _scintillaEditState.bNext, _scintillaEditState.bCase, _scintillaEditState.bWord, _scintillaEditState.bRegularExpression, FALSE);
}

void CScintillaView::AdjustFindDialogPosition()
{
  //Validate our parameters
	AFXASSUME(_scintillaEditState.pFindReplaceDlg);
	
  CScintillaCtrl& rCtrl = GetCtrl();
  int nStart = rCtrl.GetSelectionStart();
	CPoint point;
  point.x = rCtrl.PointXFromPosition(nStart);
  point.y = rCtrl.PointYFromPosition(nStart);
	ClientToScreen(&point);
	CRect rectDlg;
	_scintillaEditState.pFindReplaceDlg->GetWindowRect(&rectDlg);
	if (rectDlg.PtInRect(point))
	{
		if (point.y > rectDlg.Height())
			rectDlg.OffsetRect(0, point.y - rectDlg.bottom - 20);
		else
		{
			int nVertExt = GetSystemMetrics(SM_CYSCREEN);
			if (point.y + rectDlg.Height() < nVertExt)
				rectDlg.OffsetRect(0, 40 + point.y - rectDlg.top);
		}
		_scintillaEditState.pFindReplaceDlg->MoveWindow(&rectDlg);
	}
}

CScintillaFindReplaceDlg* CScintillaView::CreateFindReplaceDialog()
{
  return new CScintillaFindReplaceDlg;
}

void CScintillaView::OnEditFindReplace(BOOL bFindOnly)
{
  //Validate our parameters
	ASSERT_VALID(this);

	m_bFirstSearch = TRUE;
	if (_scintillaEditState.pFindReplaceDlg != NULL)
	{
		if (_scintillaEditState.bFindOnly == bFindOnly)
		{
			_scintillaEditState.pFindReplaceDlg->SetActiveWindow();
			_scintillaEditState.pFindReplaceDlg->ShowWindow(SW_SHOW);
			return;
		}
		else
		{
			ASSERT(_scintillaEditState.bFindOnly != bFindOnly);
			_scintillaEditState.pFindReplaceDlg->SendMessage(WM_CLOSE);
			ASSERT(_scintillaEditState.pFindReplaceDlg == NULL);
			ASSERT_VALID(this);
		}
	}
  CScintillaCtrl& rCtrl = GetCtrl();
	CString strFind(rCtrl.GetSelText());
	//if selection is empty or spans multiple lines use old find text
	if (strFind.IsEmpty() || (strFind.FindOneOf(_T("\n\r")) != -1))
		strFind = _scintillaEditState.strFind;

	CString strReplace(_scintillaEditState.strReplace);
	_scintillaEditState.pFindReplaceDlg = CreateFindReplaceDialog();
	AFXASSUME(_scintillaEditState.pFindReplaceDlg != NULL);
	DWORD dwFlags = NULL;
	if (_scintillaEditState.bNext)
		dwFlags |= FR_DOWN;
	if (_scintillaEditState.bCase)
		dwFlags |= FR_MATCHCASE;
	if (_scintillaEditState.bWord)
		dwFlags |= FR_WHOLEWORD;
  if (_scintillaEditState.bRegularExpression)
    _scintillaEditState.pFindReplaceDlg->SetRegularExpression(TRUE);

	if (!_scintillaEditState.pFindReplaceDlg->Create(bFindOnly, strFind, strReplace, dwFlags, this))
	{
		_scintillaEditState.pFindReplaceDlg = NULL;
		ASSERT_VALID(this);
		return;
	}
	ASSERT(_scintillaEditState.pFindReplaceDlg != NULL);
	_scintillaEditState.bFindOnly = bFindOnly;
	_scintillaEditState.pFindReplaceDlg->SetActiveWindow();
	_scintillaEditState.pFindReplaceDlg->ShowWindow(SW_SHOW);
	ASSERT_VALID(this);
}

void CScintillaView::OnFindNext(LPCTSTR lpszFind, BOOL bNext, BOOL bCase, BOOL bWord, BOOL bRegularExpression)
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	_scintillaEditState.strFind = lpszFind;
	_scintillaEditState.bCase = bCase;
	_scintillaEditState.bWord = bWord;
	_scintillaEditState.bNext = bNext;
  _scintillaEditState.bRegularExpression = bRegularExpression;

	if (!FindText(_scintillaEditState.strFind, bNext, bCase, bWord, bRegularExpression))
		TextNotFound(_scintillaEditState.strFind, bNext, bCase, bWord, bRegularExpression, FALSE);
	else
		AdjustFindDialogPosition();
	ASSERT_VALID(this);
}

void CScintillaView::OnReplaceSel(LPCTSTR lpszFind, BOOL bNext, BOOL bCase,	BOOL bWord, BOOL bRegularExpression, LPCTSTR lpszReplace)
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	_scintillaEditState.strFind = lpszFind;
	_scintillaEditState.strReplace = lpszReplace;
	_scintillaEditState.bCase = bCase;
	_scintillaEditState.bWord = bWord;
	_scintillaEditState.bNext = bNext;
  _scintillaEditState.bRegularExpression = bRegularExpression;

  CScintillaCtrl& rCtrl = GetCtrl();

	if (!SameAsSelected(_scintillaEditState.strFind, bCase, bWord, bRegularExpression))
	{
		if (!FindText(_scintillaEditState.strFind, bNext, bCase, bWord, bRegularExpression))
			TextNotFound(_scintillaEditState.strFind, bNext, bCase, bWord, bRegularExpression, TRUE);
		else
			AdjustFindDialogPosition();
		return;
	}

  if (bRegularExpression)
  {
    rCtrl.TargetFromSelection();
    rCtrl.ReplaceTargetRE(_scintillaEditState.strReplace.GetLength(), _scintillaEditState.strReplace);    
  }
  else
  	GetCtrl().ReplaceSel(_scintillaEditState.strReplace);
	if (!FindText(_scintillaEditState.strFind, bNext, bCase, bWord, bRegularExpression))
		TextNotFound(_scintillaEditState.strFind, bNext, bCase, bWord, bRegularExpression, TRUE);
	else
		AdjustFindDialogPosition();
	ASSERT_VALID(this);
}

void CScintillaView::OnReplaceAll(LPCTSTR lpszFind, LPCTSTR lpszReplace, BOOL bCase, BOOL bWord, BOOL bRegularExpression)
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	_scintillaEditState.strFind = lpszFind;
	_scintillaEditState.strReplace = lpszReplace;
	_scintillaEditState.bCase = bCase;
	_scintillaEditState.bWord = bWord;
	_scintillaEditState.bNext = TRUE;
  _scintillaEditState.bRegularExpression = bRegularExpression;

	CWaitCursor wait;

  //Set the selection to the begining of the document to ensure all text is replaced in the document
  long start_pos, end_pos;
  GetReplaceAllTarget(start_pos,end_pos);

  CScintillaCtrl& c = GetCtrl();
  bool has_selection = c.GetSelectionStart() != c.GetSelectionEnd();

  int flags = 0;

  if (bCase)
	  flags |= SCFIND_MATCHCASE;

  if (bRegularExpression)
	  flags |= SCFIND_REGEXP;

  if (bWord)
	  flags |= SCFIND_WHOLEWORD;

  c.SetSearchFlags(flags);
  c.BeginUndoAction();

  c.SetTargetStart(start_pos);
  c.SetTargetEnd(end_pos);

  long find_pos;
  bool bFoundSomething = false;

  while ((find_pos = c.SearchInTarget(_scintillaEditState.strFind.GetLength(),_scintillaEditState.strFind)) != -1)
  {
	  c.ReplaceTarget(_scintillaEditState.strReplace.GetLength(),_scintillaEditState.strReplace);
	  c.SetTargetStart(c.GetTargetEnd() + 1);
	  c.SetTargetEnd(end_pos); // Still end position

	  if (!bFoundSomething)
		  bFoundSomething = true;
  }

  c.EndUndoAction();

  if (has_selection) // Was the text previously selected?
	  c.SetSel(start_pos,c.GetTargetEnd());

  //Inform the user if we could not find anything
  if (!bFoundSomething)
    TextNotFound(_scintillaEditState.strFind, _scintillaEditState.bNext, bCase, bWord, bRegularExpression, TRUE);

	ASSERT_VALID(this);
}

LRESULT CScintillaView::OnFindReplaceCmd(WPARAM /*wParam*/, LPARAM lParam)
{
  //Validate our parameters
	ASSERT_VALID(this);

	CScintillaFindReplaceDlg* pDialog = static_cast<CScintillaFindReplaceDlg*>(CFindReplaceDialog::GetNotifier(lParam));
	AFXASSUME(pDialog != NULL);
	ASSERT(pDialog == _scintillaEditState.pFindReplaceDlg);

	if (pDialog->IsTerminating())
		_scintillaEditState.pFindReplaceDlg = NULL;
	else if (pDialog->FindNext())
		OnFindNext(pDialog->GetFindString(), pDialog->SearchDown(), pDialog->MatchCase(), pDialog->MatchWholeWord(), pDialog->GetRegularExpression());
	else if (pDialog->ReplaceCurrent())
	{
		ASSERT(!_scintillaEditState.bFindOnly);
		OnReplaceSel(pDialog->GetFindString(), pDialog->SearchDown(), pDialog->MatchCase(), pDialog->MatchWholeWord(), pDialog->GetRegularExpression(), pDialog->GetReplaceString());
	}
	else if (pDialog->ReplaceAll())
	{
		ASSERT(!_scintillaEditState.bFindOnly);
		OnReplaceAll(pDialog->GetFindString(), pDialog->GetReplaceString(), pDialog->MatchCase(), pDialog->MatchWholeWord(), pDialog->GetRegularExpression());
	}
	ASSERT_VALID(this);

	return 0;
}

BOOL CScintillaView::SameAsSelected(LPCTSTR lpszCompare, BOOL bCase, BOOL bWord, BOOL bRegularExpression)
{
  CScintillaCtrl& rCtrl = GetCtrl();

  //check length first
	int nStartChar = rCtrl.GetSelectionStart();                           //get the selection size    
  int nEndChar = rCtrl.GetSelectionEnd();
  size_t nLen = lstrlen(lpszCompare);                                   //get the #chars to search for
  if (!bRegularExpression && (nLen != (size_t)(nEndChar - nStartChar))) //if not a regular expression...
    return FALSE;                                                       //...sizes must match,

  //Now use the advanced search functionality of scintilla to determine the result
  int iFlags = bCase ? SCFIND_MATCHCASE : 0;
  iFlags |= bWord ? SCFIND_WHOLEWORD : 0;
  iFlags |= bRegularExpression ? SCFIND_REGEXP : 0;
  rCtrl.SetSearchFlags(iFlags);
  rCtrl.TargetFromSelection();                     //set target
  if (rCtrl.SearchInTarget(static_cast<int>(nLen), lpszCompare) < 0) //see what we got
    return FALSE;                                  //no match

  //If we got a match, the target is set to the found text
  return (rCtrl.GetTargetStart() == nStartChar) && (rCtrl.GetTargetEnd() == nEndChar);
}

BOOL CScintillaView::FindText(LPCTSTR lpszFind, BOOL bNext, BOOL bCase, BOOL bWord, BOOL bRegularExpression)
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	CWaitCursor wait;
	return FindTextSimple(lpszFind, bNext, bCase, bWord, bRegularExpression);
}

BOOL CScintillaView::FindTextSimple(LPCTSTR lpszFind, BOOL bNext, BOOL bCase, BOOL bWord, BOOL bRegularExpression)
{
  //Validate our parameters
	ASSERT(lpszFind != NULL);

  CScintillaCtrl& rCtrl = GetCtrl();

	TextToFind ft;
  ft.chrg.cpMin = rCtrl.GetSelectionStart();
  ft.chrg.cpMax = rCtrl.GetSelectionEnd();
	if (m_bFirstSearch)
		m_bFirstSearch = FALSE;

#ifdef _UNICODE
	CScintillaCtrl::W2UTF8(lpszFind, -1, ft.lpstrText);
#else
	ft.lpstrText = T2A(const_cast<LPTSTR>(lpszFind));
#endif
	if (ft.chrg.cpMin != ft.chrg.cpMax) // i.e. there is a selection
	{
#ifndef _UNICODE
		// If byte at beginning of selection is a DBCS lead byte,
		// increment by one extra byte.
		TEXTRANGE textRange;
		TCHAR ch[2];
		textRange.chrg.cpMin = ft.chrg.cpMin;
		textRange.chrg.cpMax = ft.chrg.cpMin + 1;
		textRange.lpstrText = ch;
		rCtrl.SendMessage(EM_GETTEXTRANGE, 0, (LPARAM)&textRange);
		if (_istlead(ch[0]))
		{
			ASSERT(ft.chrg.cpMax - ft.chrg.cpMin >= 2);

      if (bNext)
  			ft.chrg.cpMin++;
      else
        ft.chrg.cpMax = ft.chrg.cpMin - 1;
		}
#endif

    if (bNext)  
		  ft.chrg.cpMin++;
    else
      ft.chrg.cpMax = ft.chrg.cpMin - 1;
	}

  int nLength = rCtrl.GetLength();
  if (bNext)
    ft.chrg.cpMax = nLength;
	else
 	  ft.chrg.cpMin = 0;

	DWORD dwFlags = bCase ? SCFIND_MATCHCASE : 0;
	dwFlags |= bWord ? SCFIND_WHOLEWORD : 0;
  dwFlags |= bRegularExpression ? SCFIND_REGEXP : 0;

  if (!bNext)
  {
    //Swap the start and end positions which Scintilla uses to flag backward searches
    int ncpMinTemp = ft.chrg.cpMin;
    ft.chrg.cpMin = ft.chrg.cpMax;
    ft.chrg.cpMax = ncpMinTemp;
  }

	//if we find the text return TRUE
	BOOL bFound = (FindAndSelect(dwFlags, ft) != -1);

#ifdef _UNICODE
  //Tidy up the heap memory before we return
  delete [] ft.lpstrText;
#endif

  return bFound;
}

long CScintillaView::FindAndSelect(DWORD dwFlags, TextToFind& ft)
{
  CScintillaCtrl& rCtrl = GetCtrl();
	long index = rCtrl.FindText(dwFlags, &ft);
	if (index != -1) // i.e. we found something
    rCtrl.SetSel(ft.chrgText.cpMin, ft.chrgText.cpMax);
	return index;
}

void CScintillaView::TextNotFound(LPCTSTR /*lpszFind*/, BOOL /*bNext*/, BOOL /*bCase*/, BOOL /*bWord*/, BOOL /*bRegularExpression*/, BOOL /*bReplaced*/)
{
  //Validate our parameters
	ASSERT_VALID(this);
	
	m_bFirstSearch = TRUE;
  MessageBeep(MB_ICONHAND);
}

void CScintillaView::OnSetFocus(CWnd* /*pOldWnd*/) 
{
  //Give the focus to the child control
	m_Edit.SetFocus();
}

void CScintillaView::OnSize(UINT nType, int cx, int cy) 
{
  //Let the base class do its thing
	CView::OnSize(nType, cx, cy);

  //Resize the edit control to be the size of the client area
  CRect r;
  GetClientRect(&r);
  m_Edit.MoveWindow(&r);	
}

BOOL CScintillaView::OnEraseBkgnd(CDC* /*pDC*/) 
{
  //We do nothing here, because the scintilla control takes up the entire 
  //client area of our view;
	return TRUE;
}

void CScintillaView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
	//need to set owner of Find/Replace dialog
	if (_scintillaEditState.pFindReplaceDlg && pActivateView == this)
		_scintillaEditState.pFindReplaceDlg->m_fr.hwndOwner = m_hWnd;

  //let the base class do its thing
	CView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}

int CScintillaView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
  //let the base class do its thing
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
  //Create the scintilla edit control  
  CRect r;
  if (!m_Edit.Create(WS_CHILD|WS_VISIBLE|WS_TABSTOP, r, this, 0))
    return -1;
	
	return 0;
}

#ifdef _DEBUG
void CScintillaView::AssertValid() const
{
  //Let the base class do its thing
	CView::AssertValid();

  //Validate our parameters
	ASSERT_VALID(&m_aPageStart);

	if (_scintillaEditState.pFindReplaceDlg != NULL)
		ASSERT_VALID(_scintillaEditState.pFindReplaceDlg);
}

void CScintillaView::Dump(CDumpContext& dc) const
{
  //Let the base class do its thing
	CView::Dump(dc);

	dc << _T("\nm_aPageStart ") << &m_aPageStart;
  dc << _T("\nbUseROFileAttributeDuringLoading = ") << m_bUseROFileAttributeDuringLoading;

	dc << _T("\n Static Member Data:");
	if (_scintillaEditState.pFindReplaceDlg != NULL)
	{
		dc << _T("\npFindReplaceDlg = ") <<	static_cast<void*>(_scintillaEditState.pFindReplaceDlg);
		dc << _T("\nbFindOnly = ") << _scintillaEditState.bFindOnly;
	}
	dc << _T("\nstrFind = ") << _scintillaEditState.strFind;
	dc << _T("\nstrReplace = ") << _scintillaEditState.strReplace;
	dc << _T("\nbCase = ") << _scintillaEditState.bCase;
	dc << _T("\nbWord = ") << _scintillaEditState.bWord;
	dc << _T("\nbNext = ") << _scintillaEditState.bNext;
  dc << _T("\nbRegularExpression = ") << _scintillaEditState.bRegularExpression;
}
#endif //_DEBUG

void CScintillaView::Serialize(CArchive& ar)
{
  //Validate our parameters
	ASSERT_VALID(this);
	
  CScintillaCtrl& rCtrl = GetCtrl();

  if (ar.IsLoading())
  {
    //Tell the control not to maintain any undo info while we stream the data 
    rCtrl.Cancel();
    rCtrl.SetUndoCollection(FALSE);

    //Read the data in from the file in blocks
    CFile* pFile = ar.GetFile();
    char Buffer[4096];
    int nBytesRead = 0;
    do
    {
      nBytesRead = pFile->Read(Buffer, 4096);
      if (nBytesRead)
        rCtrl.AddText(nBytesRead, Buffer);
    }
    while (nBytesRead);

    //Set the read only state if required
    if (m_bUseROFileAttributeDuringLoading && ((GetFileAttributes(pFile->GetFilePath()) & FILE_ATTRIBUTE_READONLY) == FILE_ATTRIBUTE_READONLY))
      rCtrl.SetReadOnly(TRUE);
    else
      rCtrl.SetReadOnly(FALSE);

    //Reinitialize the control settings
    rCtrl.SetUndoCollection(TRUE);
    rCtrl.EmptyUndoBuffer();
    rCtrl.SetSavePoint();
    rCtrl.GotoPos(0);
  }
  else
  {
    //Get the length of the document
    int nDocLength = rCtrl.GetLength();

    //Write the data in blocks to disk
    CFile* pFile = ar.GetFile();
    for (int i=0; i<nDocLength; i += 4095) //4095 because data will be returned NULL terminated
    {
      int nGrabSize = nDocLength - i;
      if (nGrabSize > 4095)
        nGrabSize = 4095;

      //Get the data from the control
	    TextRange tr;
	    tr.chrg.cpMin = i;
	    tr.chrg.cpMax = i + nGrabSize;
      char Buffer[4096];
	    tr.lpstrText = Buffer;
	    rCtrl.GetTextRange(&tr);

      //Write it to disk
      pFile->Write(Buffer, nGrabSize);
    }
  }
}

void CScintillaView::OnFilePageSetup() 
{
  //Display a standard page setup dialog
	CPageSetupDialog dlg;

  //Allow the margin settings to be tweaked
  dlg.m_psd.Flags |= PSD_MARGINS;

  //Are we using the metric or imperial system	
  if (m_bUsingMetric)
    dlg.m_psd.Flags |= PSD_INHUNDREDTHSOFMILLIMETERS;
  else
    dlg.m_psd.Flags |= PSD_INTHOUSANDTHSOFINCHES;

  if (m_bPersistMarginSettings)
    LoadMarginSettings();

  //Set the current margin settings to the current value from m_rectMargin 
  dlg.m_psd.rtMargin = m_rMargin;

	//get the current device from the app
	PRINTDLG pd;
	pd.hDevNames = NULL;
	pd.hDevMode = NULL;
  CWinApp* pApp = AfxGetApp();
	pApp->GetPrinterDeviceDefaults(&pd);
	dlg.m_psd.hDevNames = pd.hDevNames;
	dlg.m_psd.hDevMode = pd.hDevMode;

	if (dlg.DoModal() == IDOK)
	{
    //Save the new margin value in to the member variable
    m_rMargin = dlg.m_psd.rtMargin;

    if (m_bPersistMarginSettings)
      SaveMarginSettings();

    //Update the printer settings
		pApp->SelectPrinter(dlg.m_psd.hDevNames, dlg.m_psd.hDevMode);
	}
}

void CScintillaView::OnStyleNeeded(SCNotification* /*pSCNotification*/)
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnCharAdded(SCNotification* /*pSCNotification*/)
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnSavePointReached(SCNotification* /*pSCNotification*/)
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnSavePointLeft(SCNotification* /*pSCNotification*/)
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnModifyAttemptRO(SCNotification* /*pSCNotification*/)
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnDoubleClick(SCNotification* /*pSCNotification*/)
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnUpdateUI(SCNotification* /*pSCNotification*/)
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnModified(SCNotification* /*pSCNotification*/)
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnMacroRecord(SCNotification* /*pSCNotification*/)
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnMarginClick(SCNotification* pSCNotification)
{
  //By default get the line where the click occured and toggle its fold state
  CScintillaCtrl& rCtrl = GetCtrl();
  int nLine = rCtrl.LineFromPosition(pSCNotification->position);
  rCtrl.ToggleFold(nLine);
}

void CScintillaView::OnNeedShown(SCNotification* /*pSCNotification*/)
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnPainted(SCNotification* /*pSCNotification*/)
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnUserListSelection(SCNotification* /*pSCNotification*/)
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnDwellStart(SCNotification* /*pSCNotification*/)
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnDwellEnd(SCNotification* /*pSCNotification*/)
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnZoom(SCNotification* /*pSCNotification*/)
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnHotSpotClick(SCNotification* /*pSCNotification*/)
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnHotSpotDoubleClick(SCNotification* /*pSCNotification*/)
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnCallTipClick(SCNotification* /*pSCNotification*/)
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnAutoCSelection(SCNotification* /*pSCNotification*/)
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnChange()
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnSetFocus()
{
  //By default do nothing, derived classes may want to do something
}

void CScintillaView::OnKillFocus()
{
  //By default do nothing, derived classes may want to do something
}

BOOL CScintillaView::OnCommand(WPARAM wParam, LPARAM lParam)
{
  HWND hWndControl = reinterpret_cast<HWND>(lParam);
  
  if (hWndControl == GetCtrl().GetSafeHwnd())
  {
    WORD wNotification = HIWORD(wParam);
    switch (wNotification)
    {
      case SCEN_CHANGE:
      {
        OnChange();
        break;
      }
      case SCEN_SETFOCUS:
      {
        OnSetFocus();
        break;
      }
      case SCEN_KILLFOCUS:
      {
        OnKillFocus();
        break;
      }
      default:
      {
        break;
      }
    }

    return TRUE;
  }

  //let the base class do its thing
  return CView::OnCommand(wParam, lParam);
}

BOOL CScintillaView::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
  NMHDR* pNMHdr = reinterpret_cast<NMHDR*>(lParam);
  AFXASSUME(pNMHdr);

  //Is it a notification from the embedded control
  CScintillaCtrl& rCtrl = GetCtrl();
  if (pNMHdr->hwndFrom == rCtrl.GetSafeHwnd())
  {
    SCNotification* pSCNotification = reinterpret_cast<SCNotification*>(lParam);
    switch (pNMHdr->code)
    {
      case SCN_STYLENEEDED:
      {
        OnStyleNeeded(pSCNotification);
        break;
      }
      case SCN_CHARADDED:
      {
        OnCharAdded(pSCNotification);
        break;
      }
      case SCN_SAVEPOINTREACHED:
      {
        OnSavePointReached(pSCNotification);
        break;
      }
      case SCN_SAVEPOINTLEFT:
      {
        OnSavePointLeft(pSCNotification);
        break;
      }
      case SCN_MODIFYATTEMPTRO:
      {
        OnModifyAttemptRO(pSCNotification);
        break;
      }
      case SCN_DOUBLECLICK:
      {
        OnDoubleClick(pSCNotification);
        break;
      }
      case SCN_UPDATEUI:
      {
        OnUpdateUI(pSCNotification);
        break;
      }
      case SCN_MODIFIED:
      {
        OnModified(pSCNotification);
        break;
      }
      case SCN_MACRORECORD:
      {
        OnMacroRecord(pSCNotification);
        break;
      }
      case SCN_MARGINCLICK:
      {
        OnMarginClick(pSCNotification);
        break;
      }
      case SCN_NEEDSHOWN:
      {
        OnNeedShown(pSCNotification);
        break;
      }
      case SCN_PAINTED:
      {
        OnPainted(pSCNotification);
        break;
      }
      case SCN_USERLISTSELECTION:
      {
        OnUserListSelection(pSCNotification);
        break;
      }
      case SCN_DWELLSTART:
      {
        OnDwellStart(pSCNotification);
        break;
      }
      case SCN_DWELLEND:
      {
        OnDwellEnd(pSCNotification);
        break;
      }
      case SCN_ZOOM:
      {
        OnZoom(pSCNotification);
        break;
      }
      case SCN_HOTSPOTCLICK:
      {
        OnHotSpotClick(pSCNotification);
        break;
      }
      case SCN_HOTSPOTDOUBLECLICK:
      {
        OnHotSpotDoubleClick(pSCNotification);
        break;
      }
      case SCN_CALLTIPCLICK:
      {
        OnCallTipClick(pSCNotification);
        break;
      }
      case SCN_AUTOCSELECTION:
      {
        OnAutoCSelection(pSCNotification);
        break;
      }
      default:
      {
        break;
      }
    }
    return TRUE; // we processed the message
  }
  else
  {
    //let the base class do its thing
    return CView::OnNotify(wParam, lParam, pResult);
  }
}

void CScintillaView::GetReplaceAllTarget( long& s, long& e )
{
	s = 0; e = GetCtrl().GetLength();
}

IMPLEMENT_DYNAMIC(CScintillaDoc, CDocument)

CScintillaDoc::CScintillaDoc()
{
	ASSERT_VALID(this);
}

CScintillaView* CScintillaDoc::GetView() const
{
	//find the first view - if there are no views
	//we must return NULL
	POSITION pos = GetFirstViewPosition();
	if (pos == NULL)
		return NULL;

	//find the first view that is a CScintillaView
	CView* pView;
	while (pos != NULL)
	{
		pView = GetNextView(pos);
		if (pView->IsKindOf(RUNTIME_CLASS(CScintillaView)))
			return static_cast<CScintillaView*>(pView);
	}

	//can't find one--return NULL
	return NULL;
}

void CScintillaDoc::SetModifiedFlag(BOOL bModified)
{
  CScintillaView* pView = GetView();
  AFXASSUME(pView);

  if (bModified == FALSE)
    pView->GetCtrl().SetSavePoint();

  m_bModified = bModified;
}

BOOL CScintillaDoc::IsModified()
{
  CScintillaView* pView = GetView();
  AFXASSUME(pView);

	return m_bModified || pView->GetCtrl().GetModify();
}

void CScintillaDoc::DeleteContents()
{
  //let the base class do its thing
	CDocument::DeleteContents();

  //Ask our accompanying view to delete its contents
	CWaitCursor wait;
	CScintillaView* pView = GetView();
  if (pView)
    pView->DeleteContents();
}

void CScintillaDoc::Serialize(CArchive& ar)
{
	CScintillaView* pView = GetView();
	AFXASSUME(pView);
	
	pView->Serialize(ar);
}

BOOL CScintillaDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
  //Let the base class do its thing
	BOOL bSuccess = CDocument::OnSaveDocument(lpszPathName);
  if (bSuccess)
  {
		CScintillaView* pView = GetView();
		AFXASSUME(pView);
		
		CScintillaCtrl& rCtrl = pView->GetCtrl();

		//Tell the control that the document has now been saved
		rCtrl.SetSavePoint();
		rCtrl.SetReadOnly(FALSE);
	}

	return bSuccess;
} 

#ifdef _DEBUG
void CScintillaDoc::AssertValid() const
{
  //Let the base class do its thing
	CDocument::AssertValid();
}

void CScintillaDoc::Dump(CDumpContext& dc) const
{
  //let the base class do its thing
	CDocument::Dump(dc);
}
#endif //_DEBUG

