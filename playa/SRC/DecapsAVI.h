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

#ifndef DECAPS_AVI_H
#define DECAPS_AVI_H

/*
 * Base Classes
 */

#include "MediaClasses.h"
#include "mmreg.h"
#include <stdio.h>

#define AVI_MAX_LEN 2000000000
#define HEADERBYTES 2048
#define PAD_EVEN(x) ( ((x)+1) & ~1 )
#define AVIIF_KEYFRAME	0x00000010L

/*
 * INDEX TYPES
 */

typedef struct
{
  long pos;
  long len;
  long flags;

} video_index_entry;

typedef struct
{
   long pos;
   long len;
   long tot;

} audio_index_entry;

/*
 * Avi Decaps:
 * -----------
 *
 * - Decaps AVI files
 *
 */

class MediaDecapsAVI : public MediaItemDecaps {

public:

	BITMAPINFOHEADER   bitmapinfoheader;
	MPEGLAYER3WAVEFORMAT waveformatex;
    long               width;             
    long               height;            
    double             fps;               
    char               compressor[8];     
    long               video_strn;        
    long               video_frames;      
    char               video_tag[4];      
    long               video_pos;         
    long               a_fmt;             
    long               a_chans;           
    long               a_rate;            
    long               a_bits;            
    long               audio_strn;        
    long               audio_bytes;       
    long               audio_chunks;      
    char               audio_tag[4];      
    long               audio_posc;        
    long               audio_posb;        
    long               pos;               
    long               n_idx;             
    long               max_idx;           
    char               (*idx)[16]; 
    video_index_entry *video_index;
    audio_index_entry *audio_index;
    long               last_pos;          
    long               last_len;          
    int                must_use_index;    
    long               movi_start;

	HANDLE             hIOMutex;
	MediaItemInput    *input;

	int  IsAVI();
	int  FillHeader(int getIndex);
	int  ReFillIndex();
	int  AddIndexEntry(char *tag, 
		 	           long flags, 
	 		           long pos, 
	 		           long len);
	BOOL isKeyframe(long frame);
	int  SampleSize();

public:

	MediaDecapsAVI();
	~MediaDecapsAVI();
	
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
	char		 *GetVideoCompression(unsigned int StreamId);
	BITMAPINFOHEADER *GetVideoHeader(unsigned int StreamId);

	unsigned long GetCurrentVideoFrame(unsigned int StreamId);
	unsigned long GetTotalVideoFrames(unsigned int StreamId);
	unsigned long GetTotalVideoTime(unsigned int StreamId);
	
	unsigned int  GetAudioBits(unsigned int StreamId);
	unsigned int  GetAudioChannels(unsigned int StreamId);
	unsigned int  GetAudioFrequency(unsigned int StreamId);
	WAVEFORMATEX *GetAudioFormat(unsigned int StreamId);

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

#endif // DECAPS_AVI_H
