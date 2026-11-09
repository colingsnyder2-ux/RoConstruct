#include "ObjModel.h"

void ObjModel_load::loadModel(ObjModel& ref, const string& file, bool useMtl, ObjRender mode)
{
	refmode = mode;
	if( fileExists(file) )
	{
		Array<ObjMtl> mtlSets;
		TextInput::Options options;
		options.cppComments=false;
		options.signedNumbers=true;
		TextInput in(file, options);
		while( in.hasMore() )
		{
			try{
				Token tok = in.read();
				string tmp = tok.string();
				if( tmp == "v" )
				{
					if( !ReadObjVerticies(ref, in, tok) )
						return;
				}
				else if( tmp == "vt" )
				{
					if( !ReadObjUVs(ref, in, tok) )
						return;
				}
				else if( tmp == "f" )
				{
					if( !ReadObjFaces(ref, in, tok) )
						return;
				}
				else if( tmp == "mtllib" )
				{
					string mtlfile;
					int line = tok.line();
					tok = in.read();
					if( line == tok.line() )
						mtlfile = tok.string();
					if( (tok = in.read()).line() == line)
						mtlfile += tok.string();
					if( (tok = in.read()).line() == line)
					{
						mtlfile += tok.string();
						ReadMtl(mtlfile, mtlSets);
						for(int i=0; i<mtlSets.size(); ++i)
						{
							if(mtlSets[i].texture.length() > 0)
							{
								ref.textures.append(ref.textureManager.loadTexture(mtlSets[i].texture));
								mtlSets[i].textureIndex = ref.textures.length()-1;
							}
							else
								mtlSets[i].textureIndex = -1;
						}
					}
					else
						in.push(tok);
				}
				else if( tmp == "usemtl" )
				{
					int line = tok.line();
					tok = in.read();
					ObjModel::ObjModelFace omf;
					if( line == tok.line() )
					{
						if( mtlSets.size() > 0 )
						{
							omf.index = ref.vertexIndices.size();
							omf.texture = -1;
							const int idx = mtlSets.size();
							for(int i=0; i<idx; ++i)
							{
								if( mtlSets[i].name == tok.string() )
								{
									omf.texture = mtlSets[i].textureIndex;
									memcpy(omf.ambient, mtlSets[i].ambient, 3*sizeof(float));
									memcpy(omf.diffuse, mtlSets[i].diffuse, 3*sizeof(float));
									memcpy(omf.emission, mtlSets[i].emission, 3*sizeof(float));
									memcpy(&omf.shininess, &mtlSets[i].shininess, sizeof(float));
									memcpy(omf.specular, mtlSets[i].specular, 3*sizeof(float));
									ref.objects.append(omf);
									break;
								}
							}
						}
					}
				}

			}catch(TextInput::WrongTokenType e){
				//exit
				return;
			}
		}
		ref.modelExists=true;

		MeshAlg::computeAdjacency(ref.geometry.vertexArray, ref.vertexIndices, ref.faces, ref.edges, ref.vertexArray);
	    MeshAlg::computeNormals(ref.geometry.vertexArray, ref.faces, ref.vertexArray, ref.geometry.normalArray, ref.faceNormals);
		MeshAlg::computeBounds(ref.geometry.vertexArray, ref.boundingBox, ref.boundingSphere);
		ref.numBoundaryEdges = MeshAlg::countBoundaryEdges(ref.edges);
		ref.numWeldedBoundaryEdges = 0;

		mtlSets.clear();
	}
}

bool ObjModel_load::ReadObjVerticies(ObjModel& ref, TextInput& in, Token& type)
{
	//Signed number is set to true default
	//Expand first row read
	try{
		in.push(type);
		double x,y,z;
		while( ((type=in.read()).type() == Token::SYMBOL) && (type.string() == "v") )
		{
			x = in.readNumber();
			y = in.readNumber();
			z = in.readNumber();
			ref.geometry.vertexArray.append(Vector3(x,y,z));			
		}
		in.push(type);
	}catch(TextInput::WrongTokenType e){
		return false;
	}
	return true;
}

bool ObjModel_load::ReadObjUVs(ObjModel& ref, TextInput& in, Token& type)
{
	//Signed number is set to true default
	//Expand first row read
	try{
		in.push(type);
		double u,v;
		while( ((type=in.read()).type() == Token::SYMBOL) && (type.string() == "vt") )
		{
			u = in.readNumber();
			v = in.readNumber();
			ref.textureCoordinates.append(Vector2(u,v));
		}
		in.push(type);
	}catch(TextInput::WrongTokenType e){
		return false;
	}

	return true;
}

bool ObjModel_load::ReadObjFaces(ObjModel& ref, TextInput& in, Token& type)
{
	//Signed number is set to true default
	//Expand first row read
	try{
		in.push(type);
		Token tok;
		int line=0;
		int idx1, idx2, idx3, idx4;
		int tex1, tex2, tex3, tex4;
		int norm1, norm2, norm3, norm4;
		while( ((type=in.read()).type() == Token::SYMBOL) && (type.string() == "f") )
		{
			line=type.line();
			tok = in.read();
			if( (tok.line() != line) || (tok.type()!=Token::NUMBER) )
				return false;
			idx1 = (int)tok.number()-1;
			tok = in.read();
			if( (tok.line() != line) || (tok.type()!=Token::SYMBOL) || !(tok.string()=="/") )
				return false;
			tok = in.read();
			if( (tok.line() != line) || (tok.type()!=Token::NUMBER) )
				return false;
			tex1 = (int)tok.number()-1;
/*	This code goes with commented out parameters
			if( useNormals )
			{
				tok = in.read();
				if( (tok.line() != line) || (tok.type()!=Token::SYMBOL) || !(tok.string()=="/") )
					return false;
				tok = in.read();
				if( (tok.line() != line) || (tok.type()!=Token::NUMBER) )
					return false;
				norm1 = (int)tok.number()-1;
			}
*/

			tok = in.read();
			if( (tok.line() != line) || (tok.type()!=Token::NUMBER) )
				return false;
			idx2 = (int)tok.number()-1;
			tok = in.read();
			if( (tok.line() != line) || (tok.type()!=Token::SYMBOL) || !(tok.string()=="/") )
				return false;
			tok = in.read();
			if( (tok.line() != line) || (tok.type()!=Token::NUMBER) )
				return false;
			tex2 = (int)tok.number()-1;
/*	This code goes with commented out parameters
			if( useNormals )
			{
				tok = in.read();
				if( (tok.line() != line) || (tok.type()!=Token::SYMBOL) || !(tok.string()=="/") )
					return false;
				tok = in.read();
				if( (tok.line() != line) || (tok.type()!=Token::NUMBER) )
					return false;
				norm2 = (int)tok.number()-1;
			}
*/
			tok = in.read();
			if( (tok.line() != line) || (tok.type()!=Token::NUMBER) )
				return false;
			idx3 = (int)tok.number()-1;
			tok = in.read();
			if( (tok.line() != line) || (tok.type()!=Token::SYMBOL) || !(tok.string()=="/") )
				return false;
			tok = in.read();
			if( (tok.line() != line) || (tok.type()!=Token::NUMBER) )
				return false;
			tex3 = (int)tok.number()-1;
/*	This code goes with commented out parameters
			if( useNormals )
			{
				tok = in.read();
				if( (tok.line() != line) || (tok.type()!=Token::SYMBOL) || !(tok.string()=="/") )
					return false;
				tok = in.read();
				if( (tok.line() != line) || (tok.type()!=Token::NUMBER) )
					return false;
				norm3 = (int)tok.number()-1;
			}

			if( useQuads)
			{
				tok = in.read();
				if( (tok.line() != line) || (tok.type()!=Token::NUMBER) )
					return false;
				idx4 = (int)tok.number()-1;
				tok = in.read();
				if( (tok.line() != line) || (tok.type()!=Token::SYMBOL) || !(tok.string()=="/") )
					return false;
				tok = in.read();
				if( (tok.line() != line) || (tok.type()!=Token::NUMBER) )
					return false;
				tex4 = (int)tok.number()-1;
				if( useNormals )
				{
					tok = in.read();
					if( (tok.line() != line) || (tok.type()!=Token::SYMBOL) || !(tok.string()=="/") )
						return false;
					tok = in.read();
					if( (tok.line() != line) || (tok.type()!=Token::NUMBER) )
						return false;
					norm4 = (int)tok.number()-1;
				}
			}
*/			
			if(idx1 < 0 || idx1 > (ref.geometry.vertexArray.size()-1))
				ref.vertexIndices.append(0);
			else
				ref.vertexIndices.append(idx1);
			if(idx2 < 0 || idx2 > (ref.geometry.vertexArray.size()-1))
				ref.vertexIndices.append(0);
			else
				ref.vertexIndices.append(idx2);
			if(idx3 < 0 || idx3 > (ref.geometry.vertexArray.size()-1))
				ref.vertexIndices.append(0);
			else
				ref.vertexIndices.append(idx3);
/*	This code goes with commented out parameters
			if( useQuads )
			{
				if(idx4 < 0 || idx4 > (vertices.size()-1))
					vertexIndices.append(0);
				else
					vertexIndices.append(idx4);
			}
*/
			if(tex1 < 0 || tex1 > (ref.textureCoordinates.size()-1))
				ref.textureIndices.append(0);
			else
				ref.textureIndices.append(tex1);
			if(tex2 < 0 || tex2 > (ref.textureCoordinates.size()-1))
				ref.textureIndices.append(0);
			else
				ref.textureIndices.append(tex2);
			if(tex3 < 0 || tex3 > (ref.textureCoordinates.size()-1))
				ref.textureIndices.append(0);
			else
				ref.textureIndices.append(tex3);
/*	This code goes with commented out parameters
			if( useQuads )
			{
				if(tex4 < 0 || tex4 > (textureCoordinates.size()-1))
					textureIndices.append(0);
				else
					textureIndices.append(tex4);
			}
*/
//			Token stok = in.peek();
//			if(stok.string() == "s")
//			{
//				stok=in.read();
//				stok=in.read();
//			}
		}
		in.push(type);
	}catch(TextInput::WrongTokenType e){
		return false;
	}
	return true;
}


bool ObjModel_load::ReadMtl(const string& file, Array<ObjMtl>& mtls)
{
	if( fileExists(file) )
	{
		TextInput in(file);
		Token tok;
		try{
			while( in.hasMore() )
			{
				tok = in.read();
				if( tok.string() == "newmtl" )
				{
					ObjMtl tmp;
					//always use defaults?
					tmp.ambient[0]=0.2; tmp.ambient[1]=0.2; tmp.ambient[2]=0.2;
					tmp.diffuse[0]=0.8; tmp.diffuse[1]=0.8; tmp.diffuse[2]=0.8;
					//I think this is Ni but won't use until I know.
					tmp.emission[0]=1.0; tmp.emission[1]=1.0; tmp.emission[2]=1.0;
					tmp.shininess=0.0;
					tmp.specular[0]=1.0; tmp.specular[1]=1.0; tmp.specular[2]=1.0;

					int line = tok.line();
					tok = in.read();
					if( (line == tok.line()) && (tok.type() == Token::SYMBOL) )
					{
						tmp.name = tok.string();
						while( ((tok = in.read()).type() != Token::END) && (tok.string() != "newmtl" ) )
						{
							//perhaps will figure out what illum settings demand these
							if(tok.string() == "Ka")
							{
								tmp.ambient[0] = in.readNumber();
								tmp.ambient[1] = in.readNumber();
								tmp.ambient[2] = in.readNumber();
							}
							else if(tok.string() == "Kd")
							{
								tmp.diffuse[0] = in.readNumber();
								tmp.diffuse[1] = in.readNumber();
								tmp.diffuse[2] = in.readNumber();
							}
							else if(tok.string() == "Ni")
							{
								tmp.shininess = in.readNumber();
							}
							else if(tok.string() == "Ks")
							{
								tmp.specular[0] = in.readNumber();
								tmp.specular[1] = in.readNumber();
								tmp.specular[2] = in.readNumber();
							}
							else if(tok.string() == "map_Kd")
							{
								string texname;
								int line = tok.line();
								tok = in.read();
								if( line = tok.line() )
									texname = tok.string();
								if( (tok = in.read()).line() == line )
									texname += tok.string();
								if( (tok = in.read()).line() == line )
								{
									texname += tok.string();

									tmp.texture = texname;
								}
							}
						}
						mtls.append(tmp);
						if(tok.string() == "newmtl")
							in.push(tok);
					}
				}
			}
		}catch(TextInput::WrongTokenType e){
			return false;
		}
	}
	if( mtls.size() == 0 )
		return false;
	else
		return true;
}
