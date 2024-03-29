#ifndef BAPHOMET_OGGDECODER_H
#define BAPHOMET_OGGDECODER_H

/*
	Ogg.h
	Created: xxxx-xx-xx
	Description:
		Ogg.h decodes ogg/vorbis files into nice pcm 
		packets which are then fed into an
		audio callback courtesy of portaudio
		(also just wraps libogg & libvorbis)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // pow() is used
#include <ogg/ogg.h>
#include <vorbis/codec.h>

#define MAX_OGG_SAMPLE_FRAMES 1024

typedef struct {
	long frames;
	int16_t* buffer;
} PcmRemainder;

typedef struct {
	FILE* 				filepointer;
	ogg_stream_state 	stream_state;
	ogg_sync_state 		sync_state;
	ogg_packet 			packet;
	ogg_page 			page;
	vorbis_block 		block;
	vorbis_comment 		comments;
	vorbis_info 		info;
	vorbis_dsp_state 	state;
	PcmRemainder		remainder;
	int 				eos;
} OggDecoder;

OggDecoder* ogg_decoder_open(char* filepath);
int ogg_decoder_is_vorbis(char* filepath);
void ogg_decoder_close(OggDecoder* decoder);
void ogg_decoder_rewind(OggDecoder* decoder);
int ogg_decoder_get_pcm_i16(OggDecoder* decoder, int16_t** buffer, int frames);
int ogg_decoder_get_channels(OggDecoder* decoder);
int ogg_decoder_get_rate(OggDecoder* decoder);
int ogg_decoder_get_eos(OggDecoder* decoder);

#endif