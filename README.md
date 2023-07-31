## Verify if coreml can be used as a backend in onnxruntime.



```
OrtSessionOptionsAppendExecutionProvider_CoreML, _In_ OrtSessionOptions* options, uint32_t coreml_flagsh
```

The above functions appear to be implemented in onnxruntime.

So I added in onnxruntime_coreml/include/onnxruntime_c_api.h, the following.

```
ORT_API_STATUS(OrtSessionOptionsAppendExecutionProvider_CoreML, _In_ OrtSessionOptions* options, uint32_t coreml_flags);
```

The method is called in the main function.

There is no error.

However, the following warnings are output and seem to be executed on the CPU.

Perhaps if coreml and onnx are not fully compatible, they will use the CPU instead of the GPU.

```
2023-07-31 18:43:53.157 onnxruntime_test[49769:728989] 2023-07-31 18:43:53.156281 [W:onnxruntime:, coreml_execution_provider.cc:76 GetCapability] CoreMLExecutionProvider::GetCapability, number of partitions supported by CoreML: 4 number of nodes in the graph: 9 number of nodes supported by CoreML: 4
2023-07-31 18:43:53.217 onnxruntime_test[49769:728989] 2023-07-31 18:43:53.217781 [W:onnxruntime:, session_state.cc:1162 VerifyEachNodeIsAssignedToAnEp] Some nodes were not assigned to the preferred execution providers which may or may not have a negative impact on performance. e.g. ORT explicitly assigns shape related ops to CPU to improve perf.
2023-07-31 18:43:53.217 onnxruntime_test[49769:728989] 2023-07-31 18:43:53.217857 [W:onnxruntime:, session_state.cc:1164 VerifyEachNodeIsAssignedToAnEp] Rerunning with verbose output on a minimal build will show node assignments.
```

### How to check

Need to run on macos.

Generate an onnx model.
```
cd python; python main.py
```

Build and run C++
```
./exec.sh
```

Addendum

The version of onnxruntime I tried is 1.16.0

The directory "onnxruntime_coreml" is a shared library of onnxruntime v1.16.

It is not necessary to run the build process, but just for the sake of note, I will describe how to build it.

To link and build Coreml,

```
./build.sh --config RelWithDebInfo --cmake_extra_defines CMAKE_INSTALL_PREFIX=`pwd`/install --build_shared_lib --use_coreml --parallel
```