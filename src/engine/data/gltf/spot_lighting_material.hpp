#pragma once

#include "dependencies.hpp"

namespace gltf {

inline
auto spot_lighting_material() {
    auto m = eng::Material();
    load(m.program, {
        {
            agl::ShaderType::vertex,
            file(tlw::root + "src/shader/gltf/deferred/lighting/spot_lighting.vs")
        },
        {
            agl::ShaderType::fragment,
            file(tlw::root + "src/shader/gltf/deferred/lighting/spot_lighting.fs")
        }});
    m.program.capabilities.emplace_back(
        agl::Capability::blend, []() {
            glBlendEquation(GL_FUNC_ADD);
            glBlendFunc(GL_ONE, GL_ONE); });
    return m;
}

}