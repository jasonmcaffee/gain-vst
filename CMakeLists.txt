cmake_minimum_required(VERSION 3.15)
project(gain-vst VERSION 1.0.0)

# Add JUCE as a subdirectory
add_subdirectory(JUCE)

# Initialize JUCE
juce_add_plugin(gain-vst
    VERSION 1.0.0
    COMPANY_NAME "YourCompany"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE YcCp
    PLUGIN_CODE Gvst
    FORMATS VST3 Standalone
    PRODUCT_NAME "Gain VST")

# Add source files
target_sources(gain-vst
    PRIVATE
        Source/PluginProcessor.cpp
        Source/PluginEditor.cpp)

# Set C++ standard
target_compile_features(gain-vst PRIVATE cxx_std_17)

# Link JUCE modules
target_link_libraries(gain-vst
    PRIVATE
        juce::juce_audio_utils
        juce::juce_audio_processors
        juce::juce_core
        juce::juce_data_structures
        juce::juce_events
        juce::juce_graphics
        juce::juce_gui_basics
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)

# Set include directories
target_include_directories(gain-vst PRIVATE 
    ${CMAKE_SOURCE_DIR}/Source
    ${CMAKE_SOURCE_DIR}/JuceLibraryCode
    ${CMAKE_SOURCE_DIR}/JUCE/modules
)

# Enable JUCE modules
juce_generate_juce_header(gain-vst) 