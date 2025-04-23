# CMake generated Testfile for 
# Source directory: /Users/jason/Documents/dev/gain-vst
# Build directory: /Users/jason/Documents/dev/gain-vst/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(gain-vst-tests "/Users/jason/Documents/dev/gain-vst/build/gain-vst-tests_artefacts/gain-vst-tests")
set_tests_properties(gain-vst-tests PROPERTIES  _BACKTRACE_TRIPLES "/Users/jason/Documents/dev/gain-vst/CMakeLists.txt;106;add_test;/Users/jason/Documents/dev/gain-vst/CMakeLists.txt;0;")
subdirs("_deps/catch2-build")
subdirs("JUCE")
