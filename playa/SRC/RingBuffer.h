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

#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdlib.h>
#include <string.h>

#define RING_SIZE 128000

/*
 * Ring Buffer Class
 *
 */

class MediaRingBuffer {

private:

	char        *ring;
	unsigned int read_pos;
	unsigned int write_pos;

public:

	MediaRingBuffer();
	~MediaRingBuffer();

	void Init();

	/*
	 * Read Write Funcs
	 */

	void Read(char *outData, unsigned int size);
	void Write(char *inData, unsigned int size);

	int  IsFullFor(unsigned int size);
};

#endif