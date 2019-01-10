/**************************************************************************************
 *                                                                                    *
 * This application contains code from OpenDivX and is released as a "Larger Work"    *
 * under that license. Consistant with that license, this application is released     *
 * under the GNU General Public License.                                              *
 *                                                                                    *
 * The OpenDivX license can be found at: http://www.projectmayo.com/opendivx/docs.php *
 * The GPL can be found at: http://www.gnu.org/copyleft/gpl.html                      *
 *                                                                                    *
 * Authors: Damien Chavarria <roy204 at projectmayo.com>                              *
 *                                                                                    *
 **************************************************************************************/

/**
 *
 * ring.h
 *
 * Audio Queue.
 */

#ifndef _RING_H
#define _RING_H

/*********************************************************************
 *                             INCLUDES                              *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*********************************************************************
 *                            FUNCTIONS                              *
 *********************************************************************/

void ring_init();
void ring_write(char *data, int size);
void ring_read(char *data, int size);
int  ring_full(int size);


#endif


