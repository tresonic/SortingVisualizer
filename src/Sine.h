#pragma once

#include "RtAudio.h"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
#include "SFML/Config.hpp"

constexpr unsigned SAMPLE_RATE = 44100;
constexpr float INV_SAMPLE_RATE = 1.f / SAMPLE_RATE;
constexpr float MY_PI = 3.1415926535;
constexpr unsigned AUDIO_BUFSIZE = 128;

typedef struct {
    float freq;
    float position;
} CallbackData;

class Sine {
public:
    Sine();
    void play();
    void setFreq(int freq);
    void stop();

private:
    static int rtaudio_callback(void* outbuf, void* inbuf, unsigned int nFrames, double streamtime,
                                RtAudioStreamStatus status, void* userdata);

    CallbackData mCallbackData;
    RtAudio mRtAudio;
    unsigned int mBufsize = AUDIO_BUFSIZE;
    unsigned int mFreq = 440;
};