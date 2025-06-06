# Install script for directory: /Users/jason/Documents/dev/gain-vst/JUCE

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/jason/Documents/dev/gain-vst/cmake-build-debug/JUCE/modules/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/jason/Documents/dev/gain-vst/cmake-build-debug/JUCE/extras/Build/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/JUCE-8.0.7" TYPE FILE FILES
    "/Users/jason/Documents/dev/gain-vst/cmake-build-debug/JUCE/JUCEConfigVersion.cmake"
    "/Users/jason/Documents/dev/gain-vst/cmake-build-debug/JUCE/JUCEConfig.cmake"
    "/Users/jason/Documents/dev/gain-vst/JUCE/extras/Build/CMake/JUCECheckAtomic.cmake"
    "/Users/jason/Documents/dev/gain-vst/JUCE/extras/Build/CMake/JUCEHelperTargets.cmake"
    "/Users/jason/Documents/dev/gain-vst/JUCE/extras/Build/CMake/JUCEModuleSupport.cmake"
    "/Users/jason/Documents/dev/gain-vst/JUCE/extras/Build/CMake/JUCEUtils.cmake"
    "/Users/jason/Documents/dev/gain-vst/JUCE/extras/Build/CMake/JuceLV2Defines.h.in"
    "/Users/jason/Documents/dev/gain-vst/JUCE/extras/Build/CMake/LaunchScreen.storyboard"
    "/Users/jason/Documents/dev/gain-vst/JUCE/extras/Build/CMake/PIPAudioProcessor.cpp.in"
    "/Users/jason/Documents/dev/gain-vst/JUCE/extras/Build/CMake/PIPAudioProcessorWithARA.cpp.in"
    "/Users/jason/Documents/dev/gain-vst/JUCE/extras/Build/CMake/PIPComponent.cpp.in"
    "/Users/jason/Documents/dev/gain-vst/JUCE/extras/Build/CMake/PIPConsole.cpp.in"
    "/Users/jason/Documents/dev/gain-vst/JUCE/extras/Build/CMake/RecentFilesMenuTemplate.nib"
    "/Users/jason/Documents/dev/gain-vst/JUCE/extras/Build/CMake/UnityPluginGUIScript.cs.in"
    "/Users/jason/Documents/dev/gain-vst/JUCE/extras/Build/CMake/checkBundleSigning.cmake"
    "/Users/jason/Documents/dev/gain-vst/JUCE/extras/Build/CMake/copyDir.cmake"
    "/Users/jason/Documents/dev/gain-vst/JUCE/extras/Build/CMake/juce_runtime_arch_detection.cpp"
    "/Users/jason/Documents/dev/gain-vst/JUCE/extras/Build/CMake/juce_LinuxSubprocessHelper.cpp"
    )
endif()

