/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WackyDistAudioProcessorEditor::WackyDistAudioProcessorEditor (WackyDistAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // --- CHAOS KNOB ---
    chaosKnob.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    chaosKnob.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    chaosKnob.setRange(0.0, 1.0); // 0 to 100% Chaos
    addAndMakeVisible(chaosKnob);
    
    // The "Action": Update the processor variable when the knob moves
    chaosKnob.onValueChange = [this] { audioProcessor.chaosAmount = (float)chaosKnob.getValue(); };

    chaosLabel.setText("GARBAGE", juce::dontSendNotification);
    chaosLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(chaosLabel);

    // --- VOLUME KNOB ---
    volumeKnob.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    volumeKnob.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    volumeKnob.setRange(0.0, 1.0);
    volumeKnob.setValue(0.5); // Default to 50%
    addAndMakeVisible(volumeKnob);
    
    volumeKnob.onValueChange = [this] { audioProcessor.masterVolume = (float)volumeKnob.getValue(); };

    volumeLabel.setText("SAFETY", juce::dontSendNotification);
    volumeLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(volumeLabel);

    setSize (400, 300);
}

WackyDistAudioProcessorEditor::~WackyDistAudioProcessorEditor()
{
}

//==============================================================================
void WackyDistAudioProcessorEditor::paint (juce::Graphics& g)
{
    // A dark, slightly "trashy" charcoal instead of standard grey
    g.fillAll (juce::Colour (0xff1a1a1a));

    // Optional: Draw a border or some text at the top
    g.setColour (juce::Colours::red);
    g.setFont (juce::FontOptions (20.0f).withStyle ("Bold"));
    g.drawText ("WACKY DIST", getLocalBounds().removeFromTop(40), juce::Justification::centred);
}

void WackyDistAudioProcessorEditor::resized()
{
    // Divide the area into two columns
    auto area = getLocalBounds().reduced(20);
    auto leftSide = area.removeFromLeft(area.getWidth() / 2);
    
    // Position Knobs
    chaosKnob.setBounds(leftSide.removeFromTop(area.getHeight() * 0.8));
    volumeKnob.setBounds(area.removeFromTop(area.getHeight() * 0.8));
    
    // Position Labels under them
    chaosLabel.setBounds(chaosKnob.getX(), chaosKnob.getBottom() - 20, chaosKnob.getWidth(), 30);
    volumeLabel.setBounds(volumeKnob.getX(), volumeKnob.getBottom() - 20, volumeKnob.getWidth(), 30);
}
