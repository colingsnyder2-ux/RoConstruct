// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) int __cdecl _strnicmp(const char*, const char*, unsigned int);
extern "C" __declspec(dllimport) int __cdecl atoi(const char*);
extern "C" __declspec(dllimport) unsigned long __stdcall inet_addr(const char*);
class SocketLayer {
public:
    static SocketLayer* Instance() { return &I; }
    const char* DomainNameToIP(const char* domainName);
    static SocketLayer I;
};
struct SystemAddress {
    unsigned int binaryAddress;
    unsigned short port;
    void SetBinaryAddress(const char* str);
};
void SystemAddress::SetBinaryAddress(const char *str)
{
	if (str[0] < '0' || str[0] > '9')
	{
		const char *ip = SocketLayer::Instance()->DomainNameToIP(str);
		if (ip)
			binaryAddress = inet_addr(ip);
	}
	else
	{
		int index, portIndex;
		char IPPart[22];
		char portPart[10];
		for (index=0; str[index] && str[index]!=':' && index<22; index++)
		{
			IPPart[index]=str[index];
		}
		IPPart[index]=0;
		portPart[0]=0;
		if (str[index] && str[index+1])
		{
			index++;
			for (portIndex=0; portIndex<10 && str[index] && index < 22+10; index++, portIndex++)
				portPart[portIndex]=str[index];
			portPart[portIndex]=0;
		}
		if (_strnicmp(str,"localhost", 9)==0)
			binaryAddress=inet_addr("127.0.0.1");
		else if (IPPart[0])
			binaryAddress=inet_addr(IPPart);
		if (portPart[0])
			port=(unsigned short) atoi(portPart);
	}
}
