#include "Sine.h"

#include <cmath>
#include <cstring>
#include <iostream>

Sine::Sine()
{}

inline static float modulo(float a, float b) {
    return a - std::floor(a / b) * b;
}

int Sine::rtaudio_callback(void* outbuf, void* inbuf, unsigned int nFrames, double streamtime,
                           RtAudioStreamStatus status, void* userdata)
{
    (void)inbuf;
    float* buf = (float*)outbuf;
    unsigned int remainFrames;
    CallbackData* data = (CallbackData*)userdata;

    // std::cout << "streamtime: " << streamtime << " ; cur: " << data->cur << '\n';

    // remainFrames = nFrames;
    // while (remainFrames > 0) {
    //     unsigned int sz = data->nFrame - data->cur;
    //     if (sz > remainFrames) sz = remainFrames;
    //     std::memcpy(buf, data->wftable + (data->cur * data->nChannel),
    //                 sz * data->nChannel * sizeof(float));
    //     data->cur = (data->cur + sz) % data->nFrame;
    //     buf += sz * data->nChannel;
    //     remainFrames -= sz;
    // }
    // float val;
    // for(size_t i = 0; i<512; i++) {
    //     val = std::sin(i * M_PI * 2 * data->freq / data->nRate + data->lastVal) * 0.1;
    //     *buf++ = val;
    //     *buf++ = val;
    // }

    // data->lastVal += 511 * M_PI * 2 * data->freq / data->nRate;
    // std::cout << nFrames << '\n';

    for (size_t i = 0; i < nFrames/2; i++) {
        float val = std::sin(data->position);
        // std::cout << val << '\n';
        buf[i] = val;
        buf[i+nFrames/2] = val;
        data->position += 2.f * M_PI * INV_SAMPLE_RATE * data->freq;
    }


    data->position = std::fmod(data->position, 2.f * M_PI);


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

    mRtAudio.openStream(&streamParams, NULL, RTAUDIO_FLOAT32, SAMPLE_RATE, &mBufsize, rtaudio_callback,
                        &mCallbackData, &options);

    
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