/**************************************************************************************
 *                                                                                    *
 * This application contains code from OpenDivX and is released as a "Larger Work"    *
 * under that license. Consistant with that license, this application is released     *
 * under the GNU General Public License.                                              *
 *                                                                                    *
 * The OpenDivX license can be found at: http://www.projectmayo.com/opendivx/docs.php *
 * The GPL can be found at: http://www.gnu.org/copyleft/gpl.html                      *
 *                                                                                    *
 * Copyright (c) 2001 - Project Mayo                                                  *
 *                                                                                    *
 * Authors: Damien Chavarria                                                          *
 *          DivX Advanced Research Center <darc at projectmayo.com>                   *
 *                                                                                    *
 **************************************************************************************/

#ifndef INPUT_FILE_H
#define INPUT_FILE_H

/*
 * Base Classes
 */

#include "MediaClasses.h"

/*
 * Standard includes
 * for file handling
 */

#include <fcntl.h>
#include <stdio.h>
#include <io.h>
#include <crtdbg.h>

/*
 * File Input Class
 */

class MediaInputFile : public MediaItemInput {

private:

	FILE *file;
	DWORD size;

public:

	MediaInputFile();
	~MediaInputFile();

	/*
	 * Media Item functions
	 */

	media_type_t  GetType();
	char         *GetName();

	MP_RESULT     Connect(MediaItem *item);
	MP_RESULT     ReleaseConnections();

	DWORD         GetCaps();
	MP_RESULT     Configure(HINSTANCE hInstance, HWND hwnd);

	/*
	 * Input Item functions
	 */

	MP_RESULT          Open(char *url, media_input_mode_t mode);

	long               GetSize();
	long			   GetBufferSize();
	long			   GetBufferPosition();
	long			   GetBufferingSize();

	unsigned int       Read(MediaBuffer *mb, unsigned int size);
	unsigned int       Seek(int size, media_input_seek_t method);

	unsigned int       GetLine(MediaBuffer *mb);
	BOOL               EndOfFile();

	MP_RESULT Close();
};


#endif // INPUT_FILE_H