// =============================================================================
// Decal.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/Decal.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "reflection/reflection.h"
#include "v8datamodel/FaceInstance.h"
#include "util/TextureId.h"

namespace RBX
{
	extern char sDecal[];

	class Decal : public DescribedCreatable<Decal, FaceInstance, sDecal>
	{
	private:
		TextureId texture;
		float specular;
		float shiny;
	public:
		static const Reflection::PropDescriptor<Decal, TextureId> prop_Texture;
		static const Reflection::PropDescriptor<Decal, float> prop_Specular;
		static const Reflection::PropDescriptor<Decal, float> prop_Shiny;

		Decal();

		TextureId getTexture() const
		{
			return texture;
		}

		void setTexture(TextureId);

		float getSpecular() const
		{
			return specular;
		}

		void setSpecular(float value);

		float getShiny() const
		{
			return shiny;
		}

		void setShiny(float value);
	};

	extern char sTexture[];

	class Texture : public DescribedCreatable<Texture, Decal, sTexture>
	{
	private:
		G3D::Vector2 studsPerTile;
	public:
		static const Reflection::PropDescriptor<Texture, float> prop_StudsPerTileU;
		static const Reflection::PropDescriptor<Texture, float> prop_StudsPerTileV;

	public:
		Texture();
		const G3D::Vector2& getStudsPerTile();

		float getStudsPerTileU() const
		{
			return studsPerTile.x;
		}

		void setStudsPerTileU(float value);

		float getStudsPerTileV() const
		{
			return studsPerTile.y;
		}

		void setStudsPerTileV(float value);
	};
};
