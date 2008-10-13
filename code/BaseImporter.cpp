/*
---------------------------------------------------------------------------
Open Asset Import Library (ASSIMP)
---------------------------------------------------------------------------

Copyright (c) 2006-2008, ASSIMP Development Team

All rights reserved.

Redistribution and use of this software in source and binary forms, 
with or without modification, are permitted provided that the following 
conditions are met:

* Redistributions of source code must retain the above
  copyright notice, this list of conditions and the
  following disclaimer.

* Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the
  following disclaimer in the documentation and/or other
  materials provided with the distribution.

* Neither the name of the ASSIMP team, nor the names of its
  contributors may be used to endorse or promote products
  derived from this software without specific prior
  written permission of the ASSIMP Development Team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
---------------------------------------------------------------------------
*/

/** @file Implementation of BaseImporter */

#include "AssimpPCH.h"
#include "BaseImporter.h"


using namespace Assimp;


// ------------------------------------------------------------------------------------------------
// Constructor to be privately used by Importer
BaseImporter::BaseImporter()
{
	// nothing to do here
}

// ------------------------------------------------------------------------------------------------
// Destructor, private as well
BaseImporter::~BaseImporter()
{
	// nothing to do here
}

// ------------------------------------------------------------------------------------------------
// Imports the given file and returns the imported data.
aiScene* BaseImporter::ReadFile( const std::string& pFile, IOSystem* pIOHandler)
{
	// create a scene object to hold the data
	aiScene* scene = new aiScene();

	// dispatch importing
	try
	{
		InternReadFile( pFile, scene, pIOHandler);
	} catch( ImportErrorException* exception)
	{
		// extract error description
		mErrorText = exception->GetErrorText();

		DefaultLogger::get()->error(mErrorText);

		delete exception;

		// and kill the partially imported data
		delete scene;
		scene = NULL;
	}

	// return what we gathered from the import. 
	return scene;
}

// ------------------------------------------------------------------------------------------------
void BaseImporter::SetupProperties(const Importer* pImp)
{
	// the default implementation does nothing
}



