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

#ifndef DECAPS_H
#define DECAPS_H

/*
 * Base Classes
 */

#include "MediaClasses.h"
#include "DecapsAVI.h"

/*
 * Decaps:
 * -------
 *
 * - Decaps Wrapper
 *
 */

class MediaDecaps : public MediaItemDecaps {

private:

	MediaDecapsAVI  *decapsAVI;
	MediaItemDecaps *decaps;

public:

	MediaDecaps();
	~MediaDecaps();
	
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
	 * Decaps functions
	 */

	unsigned int  GetNumberOfVideoStreams();
	unsigned int  GetNumberOfAudioStreams();

	unsigned int  GetVideoWidth(unsigned int StreamId);
	unsigned int  GetVideoHeight(unsigned int StreamId);
	double        GetVideoFrameRate(unsigned int StreamId);
	char         *GetVideoCompression(unsigned int StreamId);
	BITMAPINFOHEADER *GetVideoHeader(unsigned int StramId);

	unsigned long GetCurrentVideoFrame(unsigned int StreamId);
	unsigned long GetTotalVideoFrames(unsigned int StreamId);
	unsigned long GetTotalVideoTime(unsigned int StreamId);
	WAVEFORMATEX *GetAudioFormat(unsigned int StreamId);
	
	unsigned int  GetAudioBits(unsigned int StreamId);
	unsigned int  GetAudioChannels(unsigned int StreamId);
	unsigned int  GetAudioFrequency(unsigned int StreamId);

	unsigned int  GetNextVideoFrameSize(unsigned int StreamId);
	unsigned int  ReadVideoFrame(unsigned int StreamId, MediaBuffer *mb);

	unsigned int  ReadAudioData(unsigned int StreamId, char *buffer, unsigned int bytes);
	MP_RESULT     UpdateForSize();

	MP_RESULT     SeekAudio(unsigned int StreamId, long bytes);
	MP_RESULT     SeekVideo(unsigned int StreamId, long frame);
	MP_RESULT     ReSeekAudio(unsigned int StreamId);

	MP_RESULT     Seek(unsigned int videoStreamId, unsigned int audioStreamId, int percent);
	MP_RESULT     Rewind(unsigned int videoStreamId, unsigned int audioStreamId);

	MP_RESULT     SeekNextKeyFrame(unsigned int StreamId);
	MP_RESULT     SeekPreviousKeyFrame(unsigned int StreamId);
};

#endif // DECAPS_H
