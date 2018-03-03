#include "GLSLANG/ShaderLang.h"

extern "C"
int GLSLangInitialize() {
    if ( sh::Initialize() )
        return 1;
    return 0;
}

extern "C"
int GLSLangFinalize() {
    if ( sh::Finalize() )
        return 1;
    return 0;
}

extern "C"
void GLSLangInitBuiltInResources(ShBuiltInResources *resources) {
    sh::InitBuiltInResources(resources);
}

extern "C"
const char* GLSLangGetBuiltInResourcesString(const ShHandle handle) {
    return sh::GetBuiltInResourcesString(handle).c_str();
}

extern "C"
ShHandle GLSLangConstructCompiler(unsigned int type,
                                  int spec,
                                  int output,
                                  const ShBuiltInResources *resources) {
    return sh::ConstructCompiler(static_cast<sh::GLenum>(type),
                                 static_cast<ShShaderSpec>(spec),
                                 static_cast<ShShaderOutput>(output),
                                 resources);
}

extern "C"
void GLSLangDestructCompiler(ShHandle handle) {
    sh::Destruct(handle);
}

extern "C"
int GLSLangCompile(const ShHandle handle,
               const char* const shaderStrings[],
               size_t numStrings,
               ShCompileOptions compileOptions) {
    if ( sh::Compile(handle, shaderStrings, numStrings, compileOptions) )
        return 1;

    return 0;
}

extern "C"
void GLSLangClearResults(const ShHandle handle) {
    sh::ClearResults(handle);
}

extern "C"
int GLSLangGetShaderVersion(const ShHandle handle) {
    return sh::GetShaderVersion(handle);
}

extern "C"
int GLSLangGetShaderOutputType(const ShHandle handle) {
    return sh::GetShaderOutputType(handle);
}

extern "C"
const char* GLSLangGetInfoLog(const ShHandle handle) {
    return sh::GetInfoLog(handle).c_str();
}

// Returns null-terminated object code for a compiled shader.
// Parameters:
// handle: Specifies the compiler
extern "C"
const char* GLSLangGetObjectCode(const ShHandle handle) {
    return sh::GetObjectCode(handle).c_str();
}
