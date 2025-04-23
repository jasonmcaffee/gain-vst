cmake_minimum_required(VERSION 3.15)
project(gain-vst VERSION 1.0.0)

# Include FetchContent for downloading Catch2
include(FetchContent)

# Fetch Catch2
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

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

# Add test target
juce_add_console_app(gain-vst-tests
    PRODUCT_NAME "Gain VST Tests")

# Add test source files
target_sources(gain-vst-tests
    PRIVATE
        Source/PluginTests.cpp)

# Set C++ standard for tests
target_compile_features(gain-vst-tests PRIVATE cxx_std_17)

# Link test dependencies
target_link_libraries(gain-vst-tests
    PRIVATE
        gain-vst
        Catch2::Catch2WithMain
        juce::juce_audio_utils
        juce::juce_audio_processors
        juce::juce_core
        juce::juce_data_structures
        juce::juce_events
        juce::juce_graphics
        juce::juce_gui_basics
        juce::juce_gui_extra)

# Set include directories for tests
target_include_directories(gain-vst-tests PRIVATE 
    ${CMAKE_SOURCE_DIR}/Source
    ${CMAKE_SOURCE_DIR}/JuceLibraryCode
    ${CMAKE_SOURCE_DIR}/JUCE/modules
    ${Catch2_SOURCE_DIR}/include
)

# Generate JUCE header for tests
juce_generate_juce_header(gain-vst-tests)

# Enable testing
enable_testing()
add_test(NAME gain-vst-tests COMMAND gain-vst-tests) 