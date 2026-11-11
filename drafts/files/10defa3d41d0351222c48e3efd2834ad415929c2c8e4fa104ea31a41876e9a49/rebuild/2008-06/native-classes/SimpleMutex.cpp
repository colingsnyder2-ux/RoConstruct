// native-flags: /O2 /GS- /EHsc /MD /GS- /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Network\raknet30\Source
// >>> native-status (generated) -- do not edit >>>
// SimpleMutex | 2008-06 | 2 byte-exact, inactive (not link-selected)
// 2/2 mapped addresses byte-exact | 0 unproved | no mapped strings | by auto
// <<< native-status | src 13ca235f | roc native-status --write
#include "../../../tools/rbxgs/Client/Network/raknet30/Source/SimpleMutex.h"

void SimpleMutex::Lock(void)
{
#ifdef _WIN32
	/*
	DWORD d = WaitForSingleObject(hMutex, INFINITE);
	#ifdef _DEBUG
	if (d==WAIT_FAILED)
	{
	LPVOID messageBuffer;
	FormatMessage( 
	FORMAT_MESSAGE_ALLOCATE_BUFFER | 
	FORMAT_MESSAGE_FROM_SYSTEM | 
	FORMAT_MESSAGE_IGNORE_INSERTS,
	NULL,
	GetLastError(),
	MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
	(LPTSTR) &messageBuffer,
	0,
	NULL 
	);
	// Process any inserts in messageBuffer.
	// ...
	// Display the string.
	//MessageBox( NULL, (LPCTSTR)messageBuffer, "Error", MB_OK | MB_ICONINFORMATION );
	printf("SimpleMutex error: %s", messageBuffer);
	// Free the buffer.
	LocalFree( messageBuffer );

	}

	assert(d==WAIT_OBJECT_0);
	*/
	EnterCriticalSection(&criticalSection);

#else
	int error = pthread_mutex_lock(&hMutex);
	assert(error==0);
#endif
}

void SimpleMutex::Unlock(void)
{
#ifdef _WIN32
	//	ReleaseMutex(hMutex);
	LeaveCriticalSection(&criticalSection);
#else
	int error = pthread_mutex_unlock(&hMutex);
	assert(error==0);
#endif
}
