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

#ifndef MEDIA_BUFFER_H
#define MEDIA_BUFFER_H

#include "Error.h"

/*
 * malloc/calloc files
 */

#include <stdlib.h>

/*
 * Media Buffer Class
 *
 */

class MediaBuffer {

private:

	unsigned int size;
	void        *data;

public:

	MediaBuffer();
	~MediaBuffer();

	/*
	 * Info functions
	 */

	void        *GetData();
	unsigned int GetSize();

	/*
	 * Alloc and Realloc
	 * Functions
	 */

	MP_RESULT Alloc(int size);
	MP_RESULT ReAlloc(int size);

	/*
	 * Free functions
	 */

	MP_RESULT Free();
};

#endif // MEDIA_BUFFER_H