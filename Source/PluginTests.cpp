#include <JuceHeader.h>
#include "PluginProcessor.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

TEST_CASE("Plugin processes gain correctly", "[gain]") {
    GainvstAudioProcessor processor;
    juce::AudioBuffer<float> buffer(2, 512);  // Stereo buffer with 512 samples
    juce::MidiBuffer midiMessages;

    // Fill buffer with 1.0f for easy testing
    for (int channel = 0; channel < buffer.getNumChannels(); ++channel) {
        float* channelData = buffer.getWritePointer(channel);
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample) {
            channelData[sample] = 1.0f;
        }
    }

    SECTION("Half gain (0.5x)") {
        auto* gainParam = processor.getGainParameter();
        gainParam->setValueNotifyingHost(gainParam->getNormalisableRange().convertTo0to1(0.5f));
        processor.processBlock(buffer, midiMessages);
        
        // Check first sample of first channel
        REQUIRE(buffer.getSample(0, 0) == Catch::Approx(0.5f).margin(0.01f));
    }

    SECTION("Double gain (2.0x)") {
        auto* gainParam = processor.getGainParameter();
        gainParam->setValueNotifyingHost(gainParam->getNormalisableRange().convertTo0to1(2.0f));
        processor.processBlock(buffer, midiMessages);
        
        // Check first sample of first channel
        REQUIRE(buffer.getSample(0, 0) == Catch::Approx(2.0f).margin(0.01f));
    }

    SECTION("Zero gain (0.0x)") {
        auto* gainParam = processor.getGainParameter();
        gainParam->setValueNotifyingHost(gainParam->getNormalisableRange().convertTo0to1(0.0f));
        processor.processBlock(buffer, midiMessages);
        
        // Check first sample of first channel
        REQUIRE(buffer.getSample(0, 0) == Catch::Approx(0.0f).margin(0.01f));
    }
}

TEST_CASE("Gain parameter initialization", "[parameters]") {
    GainvstAudioProcessor processor;
    auto* gainParam = processor.getGainParameter();
    REQUIRE(gainParam != nullptr);
    REQUIRE(gainParam->get() == Catch::Approx(1.0f));  // Default should be unity gain
    REQUIRE(gainParam->getNormalisableRange().start == Catch::Approx(0.0f));  // Min should be 0
    REQUIRE(gainParam->getNormalisableRange().end == Catch::Approx(2.0f));  // Max should be 2
}

TEST_CASE("Gain processing", "[processing]") {
    GainvstAudioProcessor processor;
    juce::AudioBuffer<float> buffer(2, 512); // 2 channels, 512 samples
    juce::MidiBuffer midiBuffer;

    // Fill buffer with test signal
    for (int channel = 0; channel < buffer.getNumChannels(); ++channel) {
        float* channelData = buffer.getWritePointer(channel);
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample) {
            channelData[sample] = 1.0f; // Fill with 1.0
        }
    }

    SECTION("Unity gain (1.0x)") {
        auto* gainParam = processor.getGainParameter();
        gainParam->setValueNotifyingHost(gainParam->getNormalisableRange().convertTo0to1(1.0f));
        processor.processBlock(buffer, midiBuffer);
        for (int channel = 0; channel < buffer.getNumChannels(); ++channel) {
            const float* channelData = buffer.getReadPointer(channel);
            for (int sample = 0; sample < buffer.getNumSamples(); ++sample) {
                REQUIRE(channelData[sample] == Catch::Approx(1.0f).margin(0.0001f));
            }
        }
    }

    SECTION("Half gain (0.5x)") {
        auto* gainParam = processor.getGainParameter();
        gainParam->setValueNotifyingHost(gainParam->getNormalisableRange().convertTo0to1(0.5f));
        processor.processBlock(buffer, midiBuffer);
        for (int channel = 0; channel < buffer.getNumChannels(); ++channel) {
            const float* channelData = buffer.getReadPointer(channel);
            for (int sample = 0; sample < buffer.getNumSamples(); ++sample) {
                REQUIRE(channelData[sample] == Catch::Approx(0.5f).margin(0.0001f));
            }
        }
    }

    SECTION("Double gain (2.0x)") {
        auto* gainParam = processor.getGainParameter();
        gainParam->setValueNotifyingHost(gainParam->getNormalisableRange().convertTo0to1(2.0f));
        processor.processBlock(buffer, midiBuffer);
        for (int channel = 0; channel < buffer.getNumChannels(); ++channel) {
            const float* channelData = buffer.getReadPointer(channel);
            for (int sample = 0; sample < buffer.getNumSamples(); ++sample) {
                REQUIRE(channelData[sample] == Catch::Approx(2.0f).margin(0.0001f));
            }
        }
    }

    SECTION("Zero gain (0.0x)") {
        auto* gainParam = processor.getGainParameter();
        gainParam->setValueNotifyingHost(gainParam->getNormalisableRange().convertTo0to1(0.0f));
        processor.processBlock(buffer, midiBuffer);
        for (int channel = 0; channel < buffer.getNumChannels(); ++channel) {
            const float* channelData = buffer.getReadPointer(channel);
            for (int sample = 0; sample < buffer.getNumSamples(); ++sample) {
                REQUIRE(channelData[sample] == Catch::Approx(0.0f).margin(0.0001f));
            }
        }
    }
} 