#include <cmath>
#include <iostream>

#include "Sine.h"

Sine::Sine()
{
    mSound.setBuffer(mBuffer);
    mSound.setLoop(true);
}

void Sine::play()
{
    const double TWO_PI = 6.28318;
    const double increment = 50.f / 44100;
    double x = 0;
    for (unsigned i = 0; i < SAMPLES; i++) {
        mSamples[i] = AMPLITUDE * std::sin(x * TWO_PI);
        x += increment;
    }

    if (!mBuffer.loadFromSamples(mSamples, SAMPLES, 1, SAMPLE_RATE)) {
        std::cerr << "Loading failed!" << std::endl;
    }

    mSound.play();
}

void Sine::setFreq(int freq) {
    float factor = float(freq) / 50.f;
    mSound.setPitch(factor);
}

void Sine::stop()
{
    mSound.pause();
}