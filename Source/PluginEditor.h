/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class GainvstAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                    public juce::Slider::Listener
{
public:
    GainvstAudioProcessorEditor (GainvstAudioProcessor&);
    ~GainvstAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider* slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    GainvstAudioProcessor& audioProcessor;
    juce::Slider gainSlider;
    juce::Label gainLabel;
    juce::Label versionLabel;  // Label to display build version

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainvstAudioProcessorEditor)
};
