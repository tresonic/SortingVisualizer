#include "Sine.h"

#include <cmath>
#include <iostream>

Sine::Sine()
{}

int Sine::rtaudio_callback(void* outbuf, void* inbuf, unsigned int nFrames, double streamtime,
                           RtAudioStreamStatus status, void* userdata)
{
    (void)inbuf;
    float* buf = (float*)outbuf;
    unsigned int remainFrames;
    CallbackData* data = (CallbackData*)userdata;

    for (size_t i = 0; i < nFrames; i++) {
        float val = std::sin(data->position);
        buf[i] = val;
        buf[i + nFrames] = val;
        data->position += 2.f * MY_PI * INV_SAMPLE_RATE * data->freq;
    }

    data->position = std::fmod(data->position, 2.f * MY_PI);

    return 0;
}

void Sine::play()
{
    /* probe audio devices */
    unsigned int devId = mRtAudio.getDefaultOutputDevice();

    RtAudio::StreamParameters streamParams;
    streamParams.deviceId = devId;
    streamParams.nChannels = 2;

    RtAudio::StreamOptions options;
    options.numberOfBuffers = 8;
    options.flags = RTAUDIO_NONINTERLEAVED;

    mRtAudio.openStream(&streamParams, NULL, RTAUDIO_FLOAT32, SAMPLE_RATE, &mBufsize,
                        rtaudio_callback, &mCallbackData, &options);

    mRtAudio.startStream();
}

void Sine::setFreq(int freq)
{
    mFreq = freq;
    mCallbackData.freq = freq;
}

void Sine::stop()
{
    mRtAudio.stopStream();
    mRtAudio.closeStream();
}