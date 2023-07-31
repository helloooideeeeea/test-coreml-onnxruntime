#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "onnxruntime_gpu::onnxruntime_gpu" for configuration "RelWithDebInfo"
set_property(TARGET onnxruntime::onnxruntime APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(onnxruntime::onnxruntime PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libonnxruntime.1.16.0.dylib"
  IMPORTED_SONAME_RELWITHDEBINFO "@rpath/libonnxruntime.1.16.0.dylib"
  )

list(APPEND _cmake_import_check_targets onnxruntime::onnxruntime )
list(APPEND _cmake_import_check_files_for_onnxruntime::onnxruntime "${_IMPORT_PREFIX}/lib/libonnxruntime.1.16.0.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
