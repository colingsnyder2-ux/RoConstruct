// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_scorehuddatanative1028f80a4d638c9e.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <string>
struct Data {std::vector<std::vector<std::string> > data;std::vector<std::string> fields;void resize(int,int);};
void Data::resize(int dataSize,int fieldSize){data.resize(dataSize);for(int i=0;i<dataSize;i++)data[i].resize(fieldSize);fields.resize(fieldSize);}
