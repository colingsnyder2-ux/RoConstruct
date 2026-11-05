
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CHEMCPP_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CHEMCPP_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CHEMCPP_EXPORTS
#define CHEMCPP_API __declspec(dllexport)
#else
#define CHEMCPP_API __declspec(dllimport)
#endif

// This class is exported from the ChemCPP.dll
class CHEMCPP_API CChemCPP {
public:
	CChemCPP(void);
	// TODO: add your methods here.
};

extern CHEMCPP_API int nChemCPP;

CHEMCPP_API int fnChemCPP(void);
