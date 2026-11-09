/// MolecularModel.h
/// Describes data struct to match Viewer.MolecularModel, which defines a MolecularModel
/// in C#. 
/// 
/// author sab
/// date 6.18.05

typedef struct 
{
   float x;
   float y;
   float z;
   int elementNumber;
   int id;
} TestDataStruct;

/// Create the AtomStruct data struct type, to match
/// the C# AtomStruct
typedef struct 
{
	int elementNumber;
	int ID;
	float x;
	float y;
	float z;
} AtomStruct;

/// Create the BondStruct type, to match
/// the C# BondStruct
typedef struct 
{
	int atomIndex1;
	int atomIndex2;
	int order;
} BondStruct; 



extern "C" __declspec(dllexport) int TestAtomStruct(AtomStruct atom);



