#pragma once

#include "RtAudio.h"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
#include "SFML/Config.hpp"

constexpr unsigned SAMPLES = 4410;
constexpr unsigned SAMPLE_RATE = 44100;
constexpr float INV_SAMPLE_RATE = 1.f / SAMPLE_RATE;
constexpr unsigned AMPLITUDE = 30000;
constexpr float MY_PI = 3.1415926535;

typedef struct {
    // unsigned int nRate; /* Sampling Rate (sample/sec) */
    // unsigned int nChannel; /* Channel Number */
    // unsigned int nFrame; /* Frame Number of Wave Table */
    // float* wftable; /* Wave Form Table(interleaved) */
    // unsigned int cur; /* current index of WaveFormTable(in Frame) */
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
    unsigned int mBufsize = 128;
    unsigned int mFreq = 440;

};