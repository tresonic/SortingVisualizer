#pragma once

#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
#include "SFML/Config.hpp"

constexpr unsigned SAMPLES = 4410;
constexpr unsigned SAMPLE_RATE = 44100;
constexpr unsigned AMPLITUDE = 30000;

class Sine {
public:
    Sine();
    void play();
    void setFreq(int freq);
    void stop();

private:
    sf::Int16 mSamples[SAMPLES];
    sf::SoundBuffer mBuffer;
    sf::Sound mSound;
};