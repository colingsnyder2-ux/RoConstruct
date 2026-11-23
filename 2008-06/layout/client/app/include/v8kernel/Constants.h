// =============================================================================
// Constants.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8kernel/Constants.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <G3D/Vector3.h>

/*
  private: static const int32_t JOINT_FORCE_DATA;
  private: static const float MAX_LEGO_JOINT_FORCES_THEORY[7];
  private: static const float MAX_LEGO_JOINT_FORCES_MEASURED[7];

  private: void Constants();

  private: static const float LEGO_GRID_MASS();
  private: static const float LEGO_JOINT_K();
  private: static const float LEGO_DEFAULT_ELASTIC_K();
  private: static const float unitJointK();
  private: static const float getJointKMultiplier(const G3D::Vector3&, bool);
  public: static const int32_t uiStepsPerSec();
  public: static const int32_t worldStepsPerUiStep();
  public: static const int32_t kernelStepsPerWorldStep();
  public: static const int32_t worldStepsPerSec();
  public: static const int32_t kernelStepsPerSec();
  public: static const int32_t kernelStepsPerUiStep();
  public: static const float uiDt();
  public: static const float worldDt();
  public: static const float kernelDt();
  public: static const G3D::Vector3& getKmsGravity();
  public: static const float getKmsMaxJointForce(float, float);
  public: static const float getElasticMultiplier(float);
  public: static const float getJointK(const G3D::Vector3&, bool);
};
*/

namespace RBX
{
	class Constants {
		private:
		  static const int JOINT_FORCE_DATA;
		  static const float MAX_LEGO_JOINT_FORCES_THEORY[7];
		  static const float MAX_LEGO_JOINT_FORCES_MEASURED[7];
		  Constants(); //optimized out
		  static const float LEGO_GRID_MASS(); //optimized out
		  static const float LEGO_JOINT_K(); //optimized out
		  static const float LEGO_DEFAULT_ELASTIC_K(); //optimized out
		  static const float unitJointK(); //optimized out
		  static const float getJointKMultiplier(const G3D::Vector3& clippedSortedSize, bool ball);
		public:
		  static const int uiStepsPerSec(); //optimized out
		  static const int worldStepsPerUiStep(); //optimized out
		  static const int kernelStepsPerWorldStep();
		  static const int worldStepsPerSec();
		  static const int kernelStepsPerSec();
		  static const int kernelStepsPerUiStep();
		  static const float uiDt();
		  static const float worldDt();
		  static const float kernelDt();
		  static const G3D::Vector3& getKmsGravity()
		  {
			  static G3D::Vector3 result = G3D::Vector3(0.0f, -9.8100004f, 0.0f);
			  return result;
		  }
		  static const float getKmsMaxJointForce(float grid1, float grid2);
		  static const float getElasticMultiplier(float);
		  static const float getJointK(const G3D::Vector3&, bool);
	};
}
