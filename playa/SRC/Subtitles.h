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


#ifndef SUBTITLES_H
#define SUBTITLES_H

#include "SubtitlesMicroDVD.h"
#include "MediaClasses.h"

/*
 * The subtitles
 * reader wrapper Class...
 *
 */

class MediaSubtitler : public MediaItemSubtitler {

private:

	MediaSubtitlerMicroDVD *microDVDSubtitler;
	MediaItemSubtitler      *subtitler;

public:

	MediaSubtitler();
	~MediaSubtitler();

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
	 * Subtitler
	 */

	MP_RESULT     Open(char *lpFilename);
	subtitles_t  *GetSubtitles(DWORD frameNumber);
	MP_RESULT     Close();
};

#endif