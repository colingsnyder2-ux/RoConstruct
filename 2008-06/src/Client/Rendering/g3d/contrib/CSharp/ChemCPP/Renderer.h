


#pragma once

#ifndef CHEMCPP_RENDERER_HEADER
#define CHEMCPP_RENDERER_HEADER


#include "stdafx.h"
#include "ChemCPP.h"
#include "MolecularModel.h"




// forward declare classes
namespace G3D {
	class GWindow;
	class RenderDevice;
	class Vector3;
	class GCamera;
}



class Renderer
{
public:
	Renderer(bool createDebugMolecule = false);
	~Renderer(void);
	void initHWND(HWND hwnd, int width, int height);
	void renderScene();

	/// Model management -- add atoms and bonds. 
	void clearModel();
	void addAtom(AtomStruct atom);
	void addBond(BondStruct bond);

	/// Draw stuff
	void drawAtoms();
	void drawBonds();
	void drawArrows();
	void drawLabels();
	void drawOverlay();
	

	/// Control the view
	void spinY(float radians); 

private:
	G3D::GWindow* _gWindow; 
	G3D::RenderDevice * _rd; 
	G3D::GCamera* _camera;

	/// How much is the molecule rotated around the y-axis? 
	float _yRotation;

	// I'd like to store a list of atoms and bonds on the renderer, but we get 
	// weird multiply-defined symbols if we try to instantiate an instance of
	// vector<> in the header file. I'm using global static variables, declared in Renderer.cpp,
	// instead. So sorry. -sab
	//std::vector<AtomStruct> _atoms; 
	//std::vector<BondStruct> _bonds;

	G3D::Vector3 findAtomPosition(int atomID);
	void resetScene();
	float getCameraZPos();
	
};

extern "C" CHEMCPP_API void TestStructExtreme(TestDataStruct foo);

extern "C" CHEMCPP_API Renderer* CreateCppInternals();
extern "C" CHEMCPP_API void DeleteCppInternals(Renderer * instance);
extern "C" CHEMCPP_API void InitHWND(Renderer * instance, HWND hwnd, int width, int height); 
extern "C" CHEMCPP_API void RenderScene(Renderer * instance); 
extern "C" CHEMCPP_API void ClearModel(Renderer * instance); 
extern "C" CHEMCPP_API void AddAnAtom(Renderer * instance, AtomStruct atom); 
extern "C" CHEMCPP_API void AddBond(Renderer * instance, BondStruct bond); 
extern "C" CHEMCPP_API void SpinY(Renderer * instance, float radians); 

#endif