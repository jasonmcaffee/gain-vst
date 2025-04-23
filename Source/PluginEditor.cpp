/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainvstAudioProcessorEditor::GainvstAudioProcessorEditor (GainvstAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    gainSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 90, 30);
    gainSlider.setRange(0.0, 2.0, 0.01);
    gainSlider.setValue(1.0);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
    
    gainLabel.setText("Gain", juce::dontSendNotification);
    gainLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(gainLabel);

    // Initialize version label with build date and time
    versionLabel.setText("Build: " + juce::String(__DATE__) + " " + juce::String(__TIME__), juce::dontSendNotification);
    versionLabel.setJustificationType(juce::Justification::centredRight);
    versionLabel.setFont(juce::Font(12.0f));
    addAndMakeVisible(versionLabel);
}

GainvstAudioProcessorEditor::~GainvstAudioProcessorEditor()
{
}

//==============================================================================
void GainvstAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void GainvstAudioProcessorEditor::resized()
{
    auto area = getLocalBounds();
    
    // Position version label at bottom right
    versionLabel.setBounds(area.removeFromBottom(20).reduced(5));
    
    // Layout other components
    gainLabel.setBounds(area.removeFromTop(20));
    gainSlider.setBounds(area.reduced(50));
}

void GainvstAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &gainSlider)
    {
        audioProcessor.getGainParameter()->setValueNotifyingHost(static_cast<float>(slider->getValue()));
    }
}
